"""Frozen 12-input Qwen1.5B/Codex comparison with typed C and HLS evidence."""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, as_completed
from copy import deepcopy
import hashlib
import json
import math
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
if __package__ in (None, ""):
    sys.path.insert(0, str(ROOT))
OUT = ROOT / "results/two_model_study"
PLAN = ROOT / "experiments/two_model_study/plan.json"
MODELS = ("qwen15", "gpt61sol")
SYSTEM = "You optimize C11 kernels for high-level synthesis. Preserve exact behavior. Return only complete C source code, with no explanation."
INSTRUCTION = """Quickly optimize this kernel for HLS, prioritizing lower mapped cell area times execution latency at a fixed 10 ns clock.
Preserve the exact function name, return type, parameter types, array dimensions, every return value and every final parameter-array element for all admitted inputs.
The target is ILP32: char8, short16, int32, long32, long-long64; plain char is signed. Preserve integer promotions, signedness and unsigned modular arithmetic at each type's width. Arrays are valid and pairwise nonoverlapping. Do not add input restrictions.
Return complete C11 source containing exactly one function named kernel. Preserve required typedefs and macros and include stdint.h if needed. Do not add helper functions, function/library calls, compiler builtins, dynamic memory, globals or vendor pragmas. Do not use undefined behavior. Return code only, without explanation.

Original source:
```c
{source}```
"""


def write(path, text):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(text.encode("utf-8"))


def save(path, value):
    write(path, json.dumps(value, indent=2) + "\n")


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def message_hash(messages):
    return hashlib.sha256(json.dumps(messages, sort_keys=True).encode()).hexdigest()


def prepare():
    manifest_path = ROOT / "experiments/two_model_study/manifest.json"
    manifest = json.loads(manifest_path.read_text())
    assert manifest["preflight_status"] == "passed"
    cases = []
    for case in manifest["cases"]:
        source = ROOT / case["source"]
        assert sha(source) == case["original_sha256"]
        text = source.read_text()
        assert text.encode() == source.read_bytes(), "Original must use LF bytes"
        messages = [{"role": "system", "content": SYSTEM},
                    {"role": "user", "content": INSTRUCTION.format(source=text)}]
        item = {**case, "messages": messages, "messages_sha256": message_hash(messages)}
        cases.append(item)
        save(OUT / "prompts" / case["id"] / "messages.json", messages)
        write(OUT / "prompts" / case["id"] / "prompt.txt", SYSTEM + "\n\n" + messages[1]["content"])
    plan = {"manifest_sha256": sha(manifest_path), "cases": cases, "models": list(MODELS),
            "local_settings": {"seed": 5291, "temperature": 0.2, "top_p": 0.95,
                               "max_tokens": 1536, "context_size": 4096},
            "qwen": json.loads((ROOT / "tools/local_llm/PROVENANCE.json").read_text()),
            "codex": {"requested_model": "gpt-6.1-sol", "fork_turns": "none",
                      "sampling_controls": "Not exposed; distinct Codex reference, not identical local sampling",
                      "prompt_transport": "Identical system/user instruction text concatenated with a blank line"},
            "attempts_per_case_per_model": 1, "no_feedback_or_repairs": True,
            "resource_policy": "60000 ms per SMT/ESBMC obligation; complete unwinding required",
            "hls_policy": "Only equivalent source pairs with verified proof dependencies and passing compiled-C checks",
            "scope": manifest["scope"], "api_charge_usd": 0}
    if PLAN.exists():
        assert json.loads(PLAN.read_text()) == plan, "Frozen plan changed; do not overwrite"
    else:
        save(PLAN, plan)
    print("Prepared", len(cases), "frozen sources/prompts for two models", flush=True)


def select(args):
    plan = json.loads(PLAN.read_text())
    assert sha(ROOT / "experiments/two_model_study/manifest.json") == plan["manifest_sha256"]
    cases = [c for c in plan["cases"] if not args.cases or c["id"] in args.cases]
    for case in cases:
        assert sha(ROOT / case["source"]) == case["original_sha256"]
        assert message_hash(case["messages"]) == case["messages_sha256"]
    return plan, cases


def generation_folder(model, case):
    return OUT / "generations" / model / case["id"]


def generate_qwen(plan, cases):
    from scripts.generate_local_candidates import extract_code
    binary = ROOT / "tools/local_llm/runtime/llama-server.exe"
    weights = ROOT / "tools/local_llm" / plan["qwen"]["model_file"]
    assert sha(weights) == plan["qwen"]["model_sha256"]
    endpoint = "http://127.0.0.1:8095"
    command = [str(binary), "-m", str(weights), "--device", "Vulkan1", "--n-gpu-layers", "all",
               "--ctx-size", str(plan["local_settings"]["context_size"]), "--parallel", "1",
               "--threads", "8", "--reasoning", "off", "--host", "127.0.0.1", "--port", "8095"]
    save(OUT / "qwen_runtime.json", {"command": command, "model": plan["qwen"]})
    with (OUT / "qwen_server.log").open("w", encoding="utf-8") as log:
        process = subprocess.Popen(command, cwd=binary.parent, stdout=log, stderr=subprocess.STDOUT,
                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
        try:
            started = time.monotonic()
            while time.monotonic() - started < 120:
                if process.poll() is not None:
                    raise RuntimeError("Qwen server exited; see qwen_server.log")
                try:
                    with urllib.request.urlopen(endpoint + "/health", timeout=2) as r:
                        if r.status == 200:
                            break
                except Exception:
                    time.sleep(0.5)
            else:
                raise RuntimeError("Qwen startup timeout")
            with urllib.request.urlopen(endpoint + "/v1/models", timeout=10) as r:
                model_id = json.load(r)["data"][0]["id"]
            for case in cases:
                folder = generation_folder("qwen15", case)
                request = {"model": model_id, "messages": case["messages"], "stream": False,
                           **{k: v for k, v in plan["local_settings"].items() if k != "context_size"}}
                request_hash = hashlib.sha256(json.dumps(request, sort_keys=True).encode()).hexdigest()
                if (folder / "generation.json").exists():
                    old = json.loads((folder / "generation.json").read_text())
                    assert old["request_sha256"] == request_hash
                    assert old["candidate_sha256"] == sha(folder / "candidate.c")
                    assert old["raw_response_sha256"] == sha(folder / "response.json")
                    print("Qwen", case["id"], "saved first response", flush=True)
                    continue
                if (folder / "response.json").exists():
                    raise RuntimeError("Unfinalized response exists; inspect rather than resample")
                folder.mkdir(parents=True, exist_ok=True)
                save(folder / "request.json", request)
                start = time.perf_counter()
                query = urllib.request.Request(endpoint + "/v1/chat/completions", data=json.dumps(request).encode(),
                                               headers={"Content-Type": "application/json"})
                with urllib.request.urlopen(query, timeout=240) as r:
                    raw = r.read()
                (folder / "response.json").write_bytes(raw)
                data = json.loads(raw)
                choice = data["choices"][0]
                content = choice["message"].get("content") or ""
                write(folder / "response.txt", content)
                code, extraction = extract_code(content)
                write(folder / "candidate.c", code)
                record = {"model": "qwen15", "case": case["id"], "messages_sha256": case["messages_sha256"],
                          "original_sha256": case["original_sha256"], "request_sha256": request_hash,
                          "raw_response_sha256": sha(folder / "response.json"),
                          "candidate_sha256": sha(folder / "candidate.c"), "extraction": extraction,
                          "elapsed_seconds": round(time.perf_counter() - start, 3),
                          "finish_reason": choice.get("finish_reason"), "usage": data.get("usage"),
                          "timings": data.get("timings"), "model_provenance": plan["qwen"],
                          "manual_semantic_edits": False, "api_charge_usd": 0}
                save(folder / "generation.json", record)
                print("Qwen", case["id"], record["finish_reason"], record["elapsed_seconds"], "s", flush=True)
        finally:
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=15)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()


def import_codex(plan, cases):
    """Record actual fresh-task response files; never fabricate missing candidates."""
    from scripts.generate_local_candidates import extract_code
    for case in cases:
        folder = generation_folder("gpt61sol", case)
        raw = folder / "response.txt"
        invocation = folder / "invocation.json"
        if not raw.exists() or not invocation.exists():
            print("Codex response pending:", case["id"], flush=True)
            continue
        record_path = folder / "generation.json"
        if record_path.exists():
            record = json.loads(record_path.read_text())
            assert record["raw_response_sha256"] == sha(raw) and record["candidate_sha256"] == sha(folder / "candidate.c")
            assert record["messages_sha256"] == case["messages_sha256"]
            continue
        job = json.loads(invocation.read_text())
        assert job["model"] == "gpt-6.1-sol" and job["fork_turns"] == "none"
        assert job["task_text"] == case["messages"][0]["content"] + "\n\n" + case["messages"][1]["content"]
        code, extraction = extract_code(raw.read_text(encoding="utf-8"))
        write(folder / "candidate.c", code)
        save(folder / "request.json", {"messages": case["messages"], "codex": job})
        save(record_path, {"model": "gpt61sol", "case": case["id"], "messages_sha256": case["messages_sha256"],
                          "original_sha256": case["original_sha256"], "raw_response_sha256": sha(raw),
                          "candidate_sha256": sha(folder / "candidate.c"), "extraction": extraction,
                          "finish_reason": "complete", "invocation": job,
                          "sampling_controls": "Not exposed by Codex", "manual_semantic_edits": False,
                          "api_charge_usd": 0})


def abi_portable_function(unit, name):
    """Canonical target-long32 semantics in a golden function on a Linux host64 TB."""
    from pycparser import c_ast, c_generator
    node = deepcopy(unit.function)
    node.decl.name = node.decl.type.type.declname = name
    class LowerLong(c_ast.NodeVisitor):
        def visit_IdentifierType(self, n):
            if n.names.count("long") == 1:
                n.names = ["unsigned", "int"] if "unsigned" in n.names else ["int"]
    LowerLong().visit(node)
    return c_generator.CGenerator().visit(node)


def sample_value(spec, number):
    bits, signed = spec["bits"], spec["signed"]
    edges = [0, 1, (1 << bits) - 1, 1 << (bits - 1), (1 << (bits - 1)) - 1,
             2, (1 << bits) - 2, 0x5555555555555555 & ((1 << bits) - 1),
             0xAAAAAAAAAAAAAAAA & ((1 << bits) - 1), 0x7FF0000000000000 & ((1 << bits) - 1),
             0x7FF0000000000001 & ((1 << bits) - 1), 0xFFF0000000000000 & ((1 << bits) - 1),
             0x000FFFFFFFFFFFFF & ((1 << bits) - 1), 0xFFFFFFFF00000000 & ((1 << bits) - 1),
             0x8000000000000001 & ((1 << bits) - 1), 3]
    v = edges[number] if number < len(edges) else int.from_bytes(hashlib.sha256(str(number).encode()).digest()[:8], "little") & ((1 << bits) - 1)
    return v - (1 << bits) if signed and v >= (1 << (bits - 1)) else v


def testbench(original, candidate=None, *, trials=264, hls=False):
    from hlscheck.frontend import compile_pair, ABI_ASSERTIONS
    from hlscheck.miter import function_source, literal
    left, right, contract = compile_pair(original, candidate if candidate is not None else original, "kernel")
    if hls:
        top = left.canonical.split("\n{", 1)[0] + ";"
        lines = ["#include <stdint.h>", "#include <assert.h>", top,
                 '_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");',
                 abi_portable_function(left, "reference")]
    else:
        lines = ["#include <stdint.h>", "#include <stdio.h>", ABI_ASSERTIONS,
                 function_source(left, "reference"), function_source(right, "candidate")]
    lines.append("int main(void) {")
    for t in range(trials):
        lines.append("{")
        a_args, b_args, comparisons = [], [], []
        for p in left.parameters:
            a, b = f'a_{p["position"]}', f'b_{p["position"]}'
            a_args.append(a)
            b_args.append(b)
            if p["length"] is None:
                value = literal(sample_value(p, t), p)
                lines += [f'{p["c_type"]} {a}={value};', f'{p["c_type"]} {b}={a};']
            else:
                values = [literal(sample_value(p, t if t < 16 else t * 1000 + p["position"] * 100 + j), p) for j in range(p["length"])]
                lines += [f'{p["c_type"]} {a}[{p["length"]}]={{{",".join(values)}}};',
                          f'{p["c_type"]} {b}[{p["length"]}]={{{",".join(values)}}};']
                comparisons += [f'{a}[{j}]=={b}[{j}]' for j in range(p["length"])]
        call_a = 'reference(' + ','.join(a_args) + ');'
        call_b = ('kernel' if hls else 'candidate') + '(' + ','.join(b_args) + ');'
        ret = left.return_type.c_type
        if ret != "void":
            lines += [ret + ' ar=' + call_a, ret + ' br=' + call_b]
            comparisons.append("ar==br")
        else:
            lines += [call_a, call_b]
        condition = ' && '.join('(' + c + ')' for c in comparisons) or '1'
        lines += [f'assert({condition});' if hls else f'if(!({condition})){{printf("mismatch at test {t}\\n");return 1;}}', "}"]
    if not hls:
        lines.append(f'printf("PASS {trials} typed comparisons\\n");')
    lines += ["return 0;", "}"]
    return '\n'.join(lines) + '\n'


def evaluate(case, model):
    from hlscheck import verify_equivalence
    from hlscheck.frontend import compile_pair
    from hlscheck.evidence import verify_evidence, replay_native_witness
    gen = generation_folder(model, case)
    if not (gen / "generation.json").exists():
        print(model, case["id"], "response pending", flush=True)
        return
    record = json.loads((gen / "generation.json").read_text())
    assert record["candidate_sha256"] == sha(gen / "candidate.c")
    assert record["messages_sha256"] == case["messages_sha256"]
    folder = OUT / "evaluations" / model / case["id"]
    folder.mkdir(parents=True, exist_ok=True)
    original, candidate = (ROOT / case["source"]).read_text(), (gen / "candidate.c").read_text()
    fingerprints = {"original": sha(ROOT / case["source"]), "candidate": sha(gen / "candidate.c"),
                    "runner": sha(Path(__file__)), "checker": {p.name: sha(p) for p in (ROOT / "hlscheck").glob("*.py")}}
    cached = folder / "evaluation.json"
    if cached.exists():
        old = json.loads(cached.read_text())
        if old.get("fingerprints") == fingerprints:
            print(model, case["id"], old["status"], "saved exact-source result", flush=True)
            return
    command = [shutil.which("clang"), "--target=i686-w64-windows-gnu", "-std=c11", "-Werror=return-type",
               "-fsyntax-only", str(gen / "candidate.c")]
    syntax = subprocess.run(command, capture_output=True, text=True, timeout=30)
    write(folder / "syntax.log", syntax.stdout + syntax.stderr)
    row = {"case": case["id"], "model": model, "fingerprints": fingerprints,
           "messages_sha256": case["messages_sha256"], "syntax_compiles": syntax.returncode == 0,
           "finish_reason": record["finish_reason"], "api_charge_usd": 0}
    if syntax.returncode:
        row["status"] = "compile_failure"
    else:
        result = verify_equivalence(original, candidate, "kernel", output_dir=folder / "proof", timeout_ms=60000)
        row.update(status=result["status"], reason=result.get("reason"), verification_seconds=result["elapsed_seconds"])
        try:
            a, b, _ = compile_pair(original, candidate, "kernel")
            row["ast_unchanged"] = a.canonical == b.canonical
        except Exception:
            row["ast_unchanged"] = None
        if row["status"] in ("equivalent", "not_equivalent"):
            evidence = verify_evidence(folder / "proof", timeout_ms=60000)
            assert evidence["passed"]
            save(folder / "replay.json", evidence)
            row["smt_dependencies_replayed"] = True
        if row["status"] == "not_equivalent":
            native = replay_native_witness(folder / "proof", folder / "native_witness")
            row["native_witness"] = native
            assert native.get("passed"), native
        if row["status"] == "equivalent":
            source = folder / "native.c"
            write(source, testbench(original, candidate))
            executable = folder / "typed_check.exe"
            built = subprocess.run([shutil.which("clang"), "-std=c11", "-O1", str(source), "-o", str(executable)],
                                   capture_output=True, text=True, timeout=60)
            write(folder / "native_compile.log", built.stdout + built.stderr)
            assert built.returncode == 0, built.stderr[-2000:]
            run = subprocess.run([str(executable.resolve())], capture_output=True, text=True, timeout=20)
            write(folder / "native_run.log", run.stdout + run.stderr)
            assert run.returncode == 0, run.stdout + run.stderr
            row["native"] = {"passed": True, "trials": 264, "harness_sha256": sha(source),
                             "scope": "Compiled exact-width full-range typed edge/random inputs, supplementary to the formal proof"}
            gate = {"verification": {"status": "equivalent"}, "original_sha256": fingerprints["original"],
                    "candidate_sha256": fingerprints["candidate"], "proof_sha256": sha(folder / "proof/result.json"),
                    "native_harness_sha256": sha(source), "native_passed": True}
            assert result["source_sha256"] == {"original": gate["original_sha256"], "candidate": gate["candidate_sha256"]}
            save(folder / "hls_gate.json", gate)
            write(OUT / "hls_inputs" / case["id"] / "tb.c", testbench(original, trials=16, hls=True))
    save(cached, row)
    print(model, case["id"], row["status"], "changed:", row.get("ast_unchanged") is False, flush=True)


def hls_linux(cases, models, jobs=2):
    from tools.run_hls_linux import run_one
    tasks = []
    for case in cases:
        accepted = []
        for model in models:
            folder = OUT / "evaluations" / model / case["id"]
            if not (folder / "evaluation.json").exists():
                continue
            row = json.loads((folder / "evaluation.json").read_text())
            if row["status"] != "equivalent":
                continue
            gate = json.loads((folder / "hls_gate.json").read_text())
            assert gate["native_passed"] and gate["proof_sha256"] == sha(folder / "proof/result.json")
            proof = json.loads((folder / "proof/result.json").read_text())
            assert proof["status"] == "equivalent" and proof["source_sha256"] == {
                "original": sha(ROOT / case["source"]), "candidate": sha(generation_folder(model, case) / "candidate.c")}
            assert gate["original_sha256"] == proof["source_sha256"]["original"]
            assert gate["candidate_sha256"] == proof["source_sha256"]["candidate"]
            assert gate["native_harness_sha256"] == sha(folder / "native.c")
            accepted.append((model, folder))
        if not accepted:
            continue
        tb = OUT / "hls_inputs" / case["id"] / "tb.c"
        tasks.append((case, "baseline", "original", ROOT / case["source"], accepted[0][1] / "hls_gate.json", tb))
        for model, folder in accepted:
            tasks.append((case, model, "optimized", generation_folder(model, case) / "candidate.c", folder / "hls_gate.json", tb))
    def task(item):
        case, model, variant, source, gate, tb = item
        row = run_one({"name": "tm_" + case["id"] + "_" + model}, variant,
                      source_override=source, proof_override=gate, testbench_override=tb, output_root=OUT / "hls")
        save(OUT / "hardware" / case["id"] / (model + ".json"), row)
        return row["status"]
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for future in as_completed([pool.submit(task, item) for item in tasks]):
            future.result()
    print("HLS finished", len(tasks), "implementations; failures remain explicit", flush=True)


def report(plan):
    rows = []
    for case in plan["cases"]:
        for model in MODELS:
            p = OUT / "evaluations" / model / case["id"] / "evaluation.json"
            if not p.exists():
                rows.append({"case": case["id"], "model": model, "status": "pending"})
                continue
            row = json.loads(p.read_text())
            for key, filename in [("hardware", model), ("baseline_hardware", "baseline")]:
                hp = OUT / "hardware" / case["id"] / (filename + ".json")
                if hp.exists():
                    row[key] = json.loads(hp.read_text())
            if row.get("hardware", {}).get("status") == row.get("baseline_hardware", {}).get("status") == "complete":
                a, b = row["baseline_hardware"], row["hardware"]
                assert a["configuration_sha256"] == b["configuration_sha256"]
                row["latency_speedup"] = a["cycles"] / b["cycles"]
                row["area_ratio"] = b["area_um2"] / a["area_um2"]
                row["area_latency_ratio"] = b["area_latency_product_um2_ns"] / a["area_latency_product_um2_ns"]
                row["qor_improves"] = row.get("ast_unchanged") is False and row["area_latency_ratio"] < 0.999 and b["meets_10ns"]
            rows.append(row)
    aggregates = {}
    for model in MODELS:
        selected = [r for r in rows if r["model"] == model]
        measured = [r for r in selected if "latency_speedup" in r]
        aggregates[model] = {"attempts_planned": len(selected), "status_counts": dict(Counter(r["status"] for r in selected)),
            "verified_equivalence_rate": sum(r["status"] == "equivalent" for r in selected) / len(selected),
            "ast_unchanged": sum(r.get("ast_unchanged") is True for r in selected),
            "measured_candidates": len(measured), "useful_improvements": sum(r.get("qor_improves", False) for r in selected),
            "area_latency_regressions": sum(r.get("area_latency_ratio", 1) > 1.001 for r in measured),
            "area_latency_unchanged": sum(abs(r["area_latency_ratio"] - 1) <= 0.001 for r in measured),
            "latency_improvements": sum(r["latency_speedup"] > 1.001 for r in measured),
            "geomean_latency_speedup_conditional": math.exp(sum(math.log(r["latency_speedup"]) for r in measured) / len(measured)) if measured else None,
            "geomean_area_latency_ratio_conditional": math.exp(sum(math.log(r["area_latency_ratio"]) for r in measured) / len(measured)) if measured else None}
    common = [c["id"] for c in plan["cases"] if all(any(r["case"] == c["id"] and r["model"] == m and
              "latency_speedup" in r for r in rows) for m in MODELS)]
    paired = {}
    for model in MODELS:
        measured = [r for r in rows if r["model"] == model and r["case"] in common]
        paired[model] = {"count": len(measured),
            "geomean_latency_speedup": math.exp(sum(math.log(r["latency_speedup"]) for r in measured)/len(measured)) if measured else None,
            "geomean_area_latency_ratio": math.exp(sum(math.log(r["area_latency_ratio"]) for r in measured)/len(measured)) if measured else None}
    summary = {"models": aggregates, "cases": rows, "api_charge_usd": 0,
               "common_measured_case_ids": common, "paired_common_case_comparison": paired,
               "scope": plan["scope"], "protocol": "One attempt per model per case, same prompt text, no feedback or repairs. Codex sampling controls not exposed.",
               "main_50_pair_cohort_unchanged": True}
    save(OUT / "summary.json", summary)
    lines = ["# Two-model dataset study", "", plan["scope"], "",
             "Qwen2.5-Coder-1.5B Q4_K_M runs locally; GPT-6.1-Sol runs in fresh Codex tasks. "
             "Both receive identical system/user instruction text for each frozen original. "
             "One first response per case, no feedback or repair. Codex sampling controls are not exposed; "
             "this is not a controlled parameter-size comparison or an intra-model seed study.", "",
             "| Model | Planned | Equivalent | Mismatch | Other outcomes | Measured | Useful QoR gains |",
             "| --- | ---: | ---: | ---: | --- | ---: | ---: |"]
    for model, a in aggregates.items():
        counts = a["status_counts"]
        others = ', '.join(f'{k}: {v}' for k, v in counts.items() if k not in ('equivalent', 'not_equivalent')) or '-'
        lines.append(f'| {model} | {a["attempts_planned"]} | {counts.get("equivalent",0)} | {counts.get("not_equivalent",0)} | {others} | {a["measured_candidates"]} | {a["useful_improvements"]} |')
    lines += ["", "| Benchmark | Model | Verdict | Changed AST | Original cycles | Candidate cycles | Latency speedup | Area change | Area x latency change |",
              "| --- | --- | --- | --- | ---: | ---: | ---: | ---: | ---: |"]
    for r in rows:
        changed = 'yes' if r.get('ast_unchanged') is False else ('no' if r.get('ast_unchanged') is True else '-')
        measured = '— | — | — | — | —'
        if 'latency_speedup' in r:
            measured = f'{r["baseline_hardware"]["cycles"]:g} | {r["hardware"]["cycles"]:g} | {r["latency_speedup"]:.3f}x | {(r["area_ratio"]-1)*100:+.2f}% | {(r["area_latency_ratio"]-1)*100:+.2f}%'
        lines.append(f'| {r["case"]} | {r["model"]} | {r["status"]} | {changed} | {measured} |')
    lines += ["", "The area-latency product is cell area × execution latency at a common 10 ns clock. Negative changes are improvements. "
              "Useful gains require a changed, proved-equivalent candidate, successful RTL simulation/mapping/timing, "
              "at least 0.1% lower area-latency product, and meeting the clock constraint. Unchanged programs count as equivalent but not useful optimizations. "
              "Unsupported/inconclusive outcomes are not confirmed semantic errors.", "",
              "Hardware uses Bambu, Verilator, Yosys and OpenSTA with Nangate45 typical. These are mapped pre-layout ASIC "
              "estimates, not routed timing or FPGA LUT counts. Critical-path delay and area are retained in summary.json. "
              "Six compute adaptations define new reduced unsigned-integer domains; six leaves preserve their original "
              "types and full input domains. They are not twelve full unmodified benchmark applications.", "",
              "Prompts, local model version/weights, first raw responses, unmodified candidates, formal obligations, "
              "native checks, hardware sources/testbenches/logs and per-case dossiers are retained. "
              "The main 50-pair study and earlier pilot remain separate. Geometric means in summary.json apply only "
              "to the explicitly counted measured candidates; unresolved cases have no fabricated hardware values.", ""]
    if common:
        lines += [f"## Paired comparison on the same {len(common)} measured cases", "",
                  "These aggregates use exactly the same cases for both models. Unresolved Codex cases are excluded "
                  "from both models' hardware averages, while the full-attempt outcome counts above retain them.", "",
                  "| Model | Cases | Geometric mean latency speedup | Geometric mean area-latency ratio |",
                  "| --- | ---: | ---: | ---: | ---: |"]
        for model, a in paired.items():
            lines.append(f'| {model} | {a["count"]} | {a["geomean_latency_speedup"]:.3f}x | {a["geomean_area_latency_ratio"]:.3f} |')
        lines += ["", "A latency speedup above1 is faster. An area-latency ratio below1 is better. "
                  "These are descriptive results from twelve related small cases, not a statistically established model ranking.", ""]
    lines += ["## What the outputs show", "",
              "Qwen preserves all twelve examples, but nine are unchanged after canonical parsing. Its other edits "
              "include compound-assignment spelling, integer-mask/type spelling, and replacing a GEMM local accumulator "
              "with output-array accumulation. A changed AST is not necessarily a useful optimization.", "",
              "GPT-6.1-Sol makes more extensive loop/unrolling and algebraic edits. ATAX and BiCG remain inconclusive "
              "at the frozen60-second per-obligation budget: const-qualified locals are outside the specialized "
              "symbolic engine, and the remaining ESBMC problems time out. They are not called incorrect and are not synthesized. "
              "The checker, source candidates and verification budget were not changed to turn these cases into wins.", "",
              "The SYRK candidate factors alpha outside the dot product and writes each lower-triangle result once. "
              "GEMM, stencil and MVT show why lower latency need not give a lower area-latency cost: exposing "
              "more arithmetic can increase mapped area. GSM absolute value trades more area for a shorter critical path.", "",
              "See [the full CSV](measurements.csv), [figures](figures/comparison.png), "
              "[per-case source/proof dossiers](dossiers/), and [integrity/harness validation](validation.json). "
              "The frozen experiment plan is experiments/two_model_study/plan.json.", ""]
    write(OUT / "REPORT.md", '\n'.join(lines))
    print(json.dumps(aggregates, indent=2), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--prepare", action="store_true")
    parser.add_argument("--generate-qwen", action="store_true")
    parser.add_argument("--import-codex", action="store_true")
    parser.add_argument("--evaluate", action="store_true")
    parser.add_argument("--hls", action="store_true")
    parser.add_argument("--hls-linux", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--report", action="store_true")
    parser.add_argument("--cases", nargs="*")
    parser.add_argument("--models", nargs="*", choices=MODELS, default=list(MODELS))
    parser.add_argument("--jobs", type=int, default=2)
    args = parser.parse_args()
    if args.prepare:
        prepare()
    plan, cases = select(args)
    if args.generate_qwen:
        generate_qwen(plan, cases)
    if args.import_codex:
        import_codex(plan, cases)
    if args.evaluate:
        # Z3 default contexts must not be used concurrently in Python threads.
        for model in args.models:
            for case in cases:
                evaluate(case, model)
    if args.hls_linux:
        hls_linux(cases, args.models, jobs=args.jobs)
    elif args.hls:
        posix = Path(__file__).resolve().as_posix()
        linux = '/mnt/' + posix[0].lower() + posix[2:]
        command = ['wsl.exe', '-d', 'Ubuntu', '--', 'python3', linux, '--hls-linux', '--jobs', str(args.jobs), '--models', *args.models]
        if args.cases:
            command += ['--cases', *args.cases]
        with (OUT / 'hls_runner.log').open('w', encoding='utf-8') as log:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, encoding='utf-8', errors='replace')
            for line in process.stdout:
                print(line, end='', flush=True)
                log.write(line)
                log.flush()
            if process.wait():
                raise RuntimeError('HLS runner failed; inspect hls_runner.log')
    if args.report:
        report(plan)


if __name__ == '__main__':
    main()
