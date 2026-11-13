"""One fixed prefix-sum prompt, three local model families and a Codex reference."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
if __package__ in (None, ""):
    sys.path.insert(0, str(ROOT))
OUT = ROOT / "results/model_pilot_quick"
WEIGHTS = ROOT / "tools/local_llm"
ENDPOINT = "http://127.0.0.1:8094"
MODELS = [
    dict(id="qwen15", label="Qwen2.5-Coder-1.5B", organization="Qwen / Alibaba",
         repo="Qwen/Qwen2.5-Coder-1.5B-Instruct-GGUF", revision="f86cb2c1fa58255f8052cc32aeede1b7482d4361",
         file="qwen2.5-coder-1.5b-instruct-q4_k_m.gguf", bytes=1117320768,
         sha256="cc324af070c2ecbfd324a30884d2f951a7ff756aba85cb811a6ec436933bb046"),
    dict(id="smol360", label="SmolLM2-360M-Instruct", organization="Hugging Face",
         repo="bartowski/SmolLM2-360M-Instruct-GGUF", revision="7be6f65f1db715fe5dc5a4634c0d459b4eed42ec",
         file="SmolLM2-360M-Instruct-Q4_K_M.gguf", bytes=270590880,
         sha256="2fa3f013dcdd7b99f9b237717fa0b12d75bbb89984cc1274be1471a465bac9c2",
         upstream="HuggingFaceTB/SmolLM2-360M-Instruct", conversion="Community GGUF conversion by bartowski"),
    dict(id="granite2", label="Granite-3.3-2B-Instruct", organization="IBM",
         repo="ibm-granite/granite-3.3-2b-instruct-GGUF", revision="7cdf86ccd1f1bb3491c9b7017b033f2e51367397",
         file="granite-3.3-2b-instruct-Q4_K_M.gguf", bytes=1545303328,
         sha256="ac71e9e32c0bea919b409c5918f69ca74339854b0319c5065e4e9fb6d95c4852"),
]


def write(path, text):
    path.write_bytes(text.encode("utf-8"))


def save(path, value):
    write(path, json.dumps(value, indent=2) + "\n")


def sha(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def fetch_model(model):
    target = WEIGHTS / model["file"]
    if target.exists():
        assert target.stat().st_size == model["bytes"] and sha(target) == model["sha256"]
        print(model["id"], "installed weights verified", flush=True)
        return target
    print(model["id"], f'download: {model["bytes"]/1e6:.1f} MB', flush=True)
    url = f'https://huggingface.co/{model["repo"]}/resolve/{model["revision"]}/{model["file"]}?download=true&pilot={int(time.time())}'
    part = target.with_suffix(".gguf.part")
    start = time.perf_counter()
    request = urllib.request.Request(url, headers={"User-Agent": "CS5291-local-model-pilot"})
    count = 0
    last = start
    with urllib.request.urlopen(request, timeout=60) as response, part.open("wb") as stream:
        while chunk := response.read(4 * 1024 * 1024):
            stream.write(chunk)
            count += len(chunk)
            now = time.perf_counter()
            if now - last > 15:
                print(model["id"], f'{count/1e6:.0f}/{model["bytes"]/1e6:.0f} MB; {count/1e6/(now-start):.1f} MB/s', flush=True)
                last = now
    assert count == model["bytes"] and sha(part) == model["sha256"], "Download integrity failure"
    assert not target.exists()
    part.rename(target)
    print(model["id"], "download SHA256 verified", flush=True)
    return target


def get_json(path):
    with urllib.request.urlopen(ENDPOINT + path, timeout=3) as response:
        return json.load(response)


def generate(model, weights, protocol):
    from scripts.generate_local_candidates import extract_code
    folder = OUT / model["id"]
    folder.mkdir(exist_ok=True)
    record_path = folder / "generation.json"
    if record_path.exists():
        old = json.loads(record_path.read_text())
        assert old["messages_sha256"] == protocol["messages_sha256"]
        assert old["candidate_sha256"] == sha(folder / "candidate.c")
        print(model["id"], "reusing saved first response; no resampling", flush=True)
        return
    binary = WEIGHTS / "runtime/llama-server.exe"
    command = [str(binary), "-m", str(weights), "--device", "Vulkan1", "--n-gpu-layers", "all",
               "--ctx-size", "2048", "--parallel", "1", "--threads", "8", "--reasoning", "off",
               "--host", "127.0.0.1", "--port", "8094"]
    save(folder / "runtime.json", {"command": command, "model": model, "quantization": "Q4_K_M"})
    with (folder / "server.log").open("w", encoding="utf-8") as log:
        process = subprocess.Popen(command, cwd=binary.parent, stdout=log, stderr=subprocess.STDOUT,
                                   creationflags=subprocess.CREATE_NO_WINDOW if os.name == "nt" else 0)
        try:
            deadline = time.monotonic() + 120
            while time.monotonic() < deadline:
                if process.poll() is not None:
                    raise RuntimeError(model["id"] + ": server exited; inspect server.log")
                try:
                    get_json("/health")
                    break
                except Exception:
                    time.sleep(0.5)
            else:
                raise RuntimeError("Model server startup timeout")
            model_id = get_json("/v1/models")["data"][0]["id"]
            settings = protocol["local_generation"]
            request = {"model": model_id, "messages": protocol["messages"], "stream": False,
                       **{k: settings[k] for k in ("seed", "temperature", "top_p", "max_tokens")}}
            save(folder / "request.json", request)
            start = time.perf_counter()
            query = urllib.request.Request(ENDPOINT + "/v1/chat/completions",
                      data=json.dumps(request).encode(), headers={"Content-Type": "application/json"})
            with urllib.request.urlopen(query, timeout=180) as response:
                raw = response.read()
            (folder / "response.json").write_bytes(raw)
            data = json.loads(raw)
            choice = data["choices"][0]
            content = choice["message"].get("content") or ""
            write(folder / "response.txt", content)
            code, extraction = extract_code(content)
            write(folder / "candidate.c", code)
            record = {"id": model["id"], "label": model["label"], "organization": model["organization"],
                      "model": model, "messages_sha256": protocol["messages_sha256"],
                      "candidate_sha256": sha(folder / "candidate.c"), "raw_response_sha256": sha(folder / "response.json"),
                      "elapsed_seconds": round(time.perf_counter() - start, 3),
                      "finish_reason": choice.get("finish_reason"), "usage": data.get("usage"),
                      "timings": data.get("timings"), "extraction": extraction,
                      "manual_semantic_edits": False, "api_charge_usd": 0,
                      "sampling": request | {"messages": "See request.json"}}
            save(record_path, record)
            print(model["id"], "generated", record["finish_reason"], "in", record["elapsed_seconds"], "s", flush=True)
        finally:
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=15)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()


def evaluate(identifier, index):
    from hlscheck import verify_equivalence
    from hlscheck.evidence import verify_evidence, replay_native_witness
    from scripts.evaluate_local_candidates import canonical, native_check
    folder = OUT / identifier
    generation = json.loads((folder / "generation.json").read_text())
    assert generation["candidate_sha256"] == sha(folder / "candidate.c")
    original, candidate = (OUT / "original.c").read_text(), (folder / "candidate.c").read_text()
    compiler = shutil.which("clang")
    built = subprocess.run([compiler, "-std=c11", "-fsyntax-only", str(folder / "candidate.c")],
                           capture_output=True, text=True, timeout=20)
    write(folder / "syntax.log", built.stdout + built.stderr)
    row = {"id": identifier, "label": generation["label"], "organization": generation["organization"],
           "candidate_sha256": generation["candidate_sha256"], "messages_sha256": generation["messages_sha256"],
           "generation_seconds": generation.get("elapsed_seconds"), "finish_reason": generation.get("finish_reason"),
           "syntax_compiles": built.returncode == 0}
    if built.returncode:
        row["status"] = "compile_failure"
    else:
        result = verify_equivalence(original, candidate, "kernel", output_dir=folder / "proof", timeout_ms=60000)
        row["status"] = result["status"]
        row["verification_seconds"] = result["elapsed_seconds"]
        row["reason"] = result.get("reason")
        try:
            row["ast_unchanged"] = canonical(original) == canonical(candidate)
        except Exception:
            row["ast_unchanged"] = None
        if result["status"] in ("equivalent", "not_equivalent"):
            evidence = verify_evidence(folder / "proof", timeout_ms=60000)
            assert evidence["passed"]
            row["evidence_replay_passed"] = True
            save(folder / "evidence_replay.json", evidence)
        if result["status"] == "equivalent":
            native = native_check(original, candidate, result, folder, index, trials=264)
            assert native["passed"]
            row["native"] = native
            gate = {"verification": {"status": "equivalent"}, "original_sha256": sha(OUT / "original.c"),
                    "candidate_sha256": sha(folder / "candidate.c"), "integrated_proof_sha256": sha(folder / "proof/result.json")}
            assert result["source_sha256"] == {"original": gate["original_sha256"], "candidate": gate["candidate_sha256"]}
            save(folder / "hls_gate.json", gate)
        elif result["status"] == "not_equivalent":
            row["native_witness"] = replay_native_witness(folder / "proof", folder / "native_witness")
            assert row["native_witness"].get("passed")
    save(folder / "evaluation.json", row)
    print(identifier, "CHECK:", row["status"], "unchanged:", row.get("ast_unchanged"), flush=True)
    return row


def hls_linux():
    from tools.run_hls_linux import run_one
    summary = json.loads((OUT / "summary.json").read_text())
    accepted = [r for r in summary["cases"] if r["status"] == "equivalent"]
    assert accepted
    for row in accepted:
        folder = OUT / row["id"]
        gate = json.loads((folder / "hls_gate.json").read_text())
        assert gate["integrated_proof_sha256"] == sha(folder / "proof/result.json")
        assert json.loads((folder / "proof/result.json").read_text())["status"] == "equivalent"
        assert gate["candidate_sha256"] == sha(folder / "candidate.c") == row["candidate_sha256"]
        assert gate["original_sha256"] == sha(OUT / "original.c")
    tb = OUT / "hls_tb.c"
    baseline = run_one({"name": "pilot_prefix_baseline"}, "original", force=True,
               source_override=OUT / "original.c", testbench_override=tb,
               proof_override=OUT / accepted[0]["id"] / "hls_gate.json", output_root=OUT / "hls")
    assert baseline["status"] == "complete", baseline.get("error")
    summary["baseline_hls"] = baseline
    for row in accepted:
        folder = OUT / row["id"]
        measured = run_one({"name": "pilot_prefix_" + row["id"]}, "optimized", force=True,
                   source_override=folder / "candidate.c", testbench_override=tb,
                   proof_override=folder / "hls_gate.json", output_root=OUT / "hls")
        row["hls"] = measured
        if measured["status"] == "complete":
            row["latency_speedup"] = baseline["cycles"] / measured["cycles"]
            row["area_change_percent"] = 100 * (measured["area_um2"] / baseline["area_um2"] - 1)
            row["area_latency_change_percent"] = 100 * (measured["area_latency_product_um2_ns"] / baseline["area_latency_product_um2_ns"] - 1)
        save(OUT / "summary.json", summary)
    report(summary)


def report(summary):
    audit_path = OUT / "independent_audit/summary.json"
    audit = json.loads(audit_path.read_text()) if audit_path.exists() else None
    lines = ["# Quick multi-model HLS optimization pilot", "",
             "One educational eight-element prefix-sum kernel, one saved attempt per model. "
             "The three local models receive byte-identical system/user messages and the same generation settings. "
             "GPT-6.1-Sol is a fresh-context Codex reference using the same instruction text; its sampling controls are not exposed.", "",
             "All candidates are preserved without repair. Inconclusive/unsupported results are not classified as semantic errors. "
             "This pilot demonstrates the pipeline, not model accuracy or a reliable model ranking.", "",
             "| Model | Equivalence outcome | Changed AST | Area (um^2) | Cycles | Delay (ns) | Latency speedup | Area x latency change |",
             "| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |"]
    base = summary.get("baseline_hls", {})
    if base:
        lines.append(f'| Original | reference | - | {base["area_um2"]:.2f} | {base["cycles"]:g} | {base["delay_ns"]:.3f} | 1.00x | 0% |')
    for row in summary["cases"]:
        h = row.get("hls", {})
        change = "yes" if row.get("ast_unchanged") is False else ("no" if row.get("ast_unchanged") else "unknown")
        if h.get("status") == "complete":
            values = f'{h["area_um2"]:.2f} | {h["cycles"]:g} | {h["delay_ns"]:.3f} | {row["latency_speedup"]:.2f}x | {row["area_latency_change_percent"]:+.2f}%'
        else:
            values = "- | - | - | - | -"
        lines.append(f'| {row["label"]} | {row["status"]} | {change} | {values} |')
    lines += ["", "Hardware: fresh Bambu + Verilator + Yosys + OpenSTA, Nangate45 typical, common 10 ns clock. "
              "Mapped pre-layout ASIC estimates. Each successful implementation has sixteen passing RTL calls. "
              "Correct candidates also pass 264 compiled-C comparisons; accepted SMT queries are replayed.", "",
              "Protocol and exact prompt: `protocol.json`, `prompt.txt`. Each model directory retains requests, raw responses, "
              "unmodified candidate C, model/runtime provenance, verification records and native checks. "
              "SmolLM2 GGUF is a bartowski community conversion of the Hugging Face model. "
              "Qwen and IBM weights are from their official GGUF repositories. No paid inference API was called.", "",
              "Reproduce the local pilot with `python scripts/run_model_pilot.py`. Saved first responses are reused rather than resampled. "
              "The Codex response is retained separately and is not silently regenerated by that command.", ""]
    if audit:
        witness = audit["qwen_native_witness"]
        lines += ["## Separate Qwen native diagnostic", "",
                  "The formal result remains **unsupported**, because the candidate calls a compiler builtin without "
                  "a model in our frontend. This is not a formal HLSCheck refutation. An independently compiled "
                  "execution of the exact unmodified source nevertheless confirms a semantic mismatch:", "",
                  f'- Input a: `{witness["input_a"]}`.',
                  f'- Original out: `{witness["observed_original_out"]}`.',
                  f'- Qwen out: `{witness["observed_candidate_out"]}`.', "",
                  "Evidence: [audit summary](independent_audit/summary.json), "
                  "[native witness harness](independent_audit/qwen_native_witness.c). "
                  "The builtin stores the addition result and returns an overflow flag; assigning that flag "
                  "to out overwrites the sum with zero for a[i]+0. No candidate was repaired.", ""]
    write(OUT / "REPORT.md", "\n".join(lines))
    table_start = next(i for i, line in enumerate(lines) if line.startswith("| Model"))
    table_end = table_start + 2 + int(bool(base)) + len(summary["cases"])
    print("\n" + "\n".join(lines[table_start:table_end]), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hls-linux", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--no-hls", action="store_true")
    args = parser.parse_args()
    if args.hls_linux:
        hls_linux()
        return
    from scripts.validate_native import hls_testbench
    protocol = json.loads((OUT / "protocol.json").read_text())
    # Store the verification/HLS input with LF bytes on both operating systems.
    source = (ROOT / protocol["source"]).read_text()
    assert hashlib.sha256(source.encode()).hexdigest() == protocol["source_sha256"]
    write(OUT / "original.c", source)
    save(OUT / "model_manifest.json", MODELS)
    with ThreadPoolExecutor(max_workers=2) as pool:
        futures = {m["id"]: pool.submit(fetch_model, m) for m in MODELS[1:]}
        for model in MODELS:
            weights = fetch_model(model) if model["id"] == "qwen15" else futures[model["id"]].result()
            generate(model, weights, protocol)
    identifiers = [m["id"] for m in MODELS] + ["gpt61sol"]
    rows = [evaluate(identifier, i) for i, identifier in enumerate(identifiers)]
    assert len({r["messages_sha256"] for r in rows}) == 1
    summary = {"benchmark": protocol["benchmark"], "api_charge_usd": 0, "cases": rows,
               "same_prompt_hash_all_four": True, "source_sha256": sha(OUT / "original.c"),
               "scope": protocol["scope"], "models": MODELS}
    save(OUT / "summary.json", summary)
    write(OUT / "hls_tb.c", hls_testbench(source, count=16))
    report(summary)
    if not args.no_hls and any(r["status"] == "equivalent" for r in rows):
        posix = Path(__file__).resolve().as_posix()
        path = "/mnt/" + posix[0].lower() + posix[2:]
        command = ["wsl.exe", "-d", "Ubuntu", "--", "python3", path, "--hls-linux"]
        with (OUT / "hls_runner.log").open("w", encoding="utf-8") as log:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                       text=True, encoding="utf-8", errors="replace")
            for line in process.stdout:
                print(line, end="", flush=True)
                log.write(line)
                log.flush()
            if process.wait():
                raise RuntimeError("HLS stage failed; inspect hls_runner.log")
    print("Saved results/model_pilot_quick/REPORT.md", flush=True)


if __name__ == "__main__":
    main()
