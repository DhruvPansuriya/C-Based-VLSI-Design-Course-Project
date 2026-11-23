"""Validate actual two-model evidence, test native harnesses, and export results."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import csv
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
if __package__ in (None, ""):
    sys.path.insert(0, str(ROOT))
from scripts import run_two_model_study as runner
from scripts.generate_local_candidates import extract_code

OUT = runner.OUT


def compile_run(source, destination, expected_code):
    destination.mkdir(parents=True, exist_ok=True)
    path = destination / "check.c"
    runner.write(path, source)
    binary = destination / "check.exe"
    built = subprocess.run([shutil.which("clang"), "-std=c11", "-O1", str(path), "-o", str(binary)],
                           capture_output=True, text=True, timeout=60)
    runner.write(destination / "compile.log", built.stdout + built.stderr)
    assert built.returncode == 0, built.stderr[-1500:]
    run = subprocess.run([str(binary.resolve())], capture_output=True, text=True, timeout=20)
    runner.write(destination / "run.log", run.stdout + run.stderr)
    assert run.returncode == expected_code, (str(path), run.stdout, run.stderr)
    return {"passed": True, "harness_sha256": runner.sha(path), "exit_code": run.returncode,
            "stdout": run.stdout.strip(), "evidence": str(destination.relative_to(ROOT))}


def validate(plan, summary):
    from hlscheck.evidence import verify_evidence
    initial = ROOT / "experiments/script_versions/two_model_study_initial/run_two_model_study.py"
    driver_hashes = {runner.sha(initial), runner.sha(Path(runner.__file__))}
    manifest = ROOT / "experiments/two_model_study/manifest.json"
    assert runner.sha(manifest) == plan["manifest_sha256"]
    queries = native_pairs = 0
    config_hashes = set()
    accepted = []
    for case in plan["cases"]:
        assert runner.sha(ROOT / case["source"]) == case["original_sha256"]
        snapshot = (ROOT / case["source"]).parent / "upstream_source.txt"
        assert runner.sha(snapshot) == case["upstream_sha256"]
        upstream = ROOT / case["upstream_source"]
        if upstream.exists():
            assert runner.sha(upstream) == case["upstream_sha256"]
        assert runner.message_hash(case["messages"]) == case["messages_sha256"]
        for model in runner.MODELS:
            generation = runner.generation_folder(model, case)
            g = json.loads((generation / "generation.json").read_text())
            assert g["messages_sha256"] == case["messages_sha256"]
            assert g["original_sha256"] == case["original_sha256"]
            assert g["candidate_sha256"] == runner.sha(generation / "candidate.c")
            assert g["manual_semantic_edits"] is False
            request = json.loads((generation / "request.json").read_text())
            assert request["messages"] == case["messages"]
            if model == "qwen15":
                assert g["raw_response_sha256"] == runner.sha(generation / "response.json")
                raw = json.loads((generation / "response.json").read_bytes())
                text = raw["choices"][0]["message"].get("content") or ""
                for key in ("seed", "temperature", "top_p", "max_tokens"):
                    assert request[key] == plan["local_settings"][key]
            else:
                assert g["raw_response_sha256"] == runner.sha(generation / "response.txt")
                invocation = json.loads((generation / "invocation.json").read_text())
                assert invocation["model"] == "gpt-6.1-sol" and invocation["fork_turns"] == "none"
                assert invocation["task_text"] == case["messages"][0]["content"] + "\n\n" + case["messages"][1]["content"]
                text = (generation / "response.txt").read_text()
            extracted, _ = extract_code(text)
            assert extracted.encode() == (generation / "candidate.c").read_bytes()
            folder = OUT / "evaluations" / model / case["id"]
            r = json.loads((folder / "evaluation.json").read_text())
            assert r["fingerprints"]["runner"] in driver_hashes
            assert r["fingerprints"]["original"] == case["original_sha256"]
            assert r["fingerprints"]["candidate"] == g["candidate_sha256"]
            for name, value in r["fingerprints"]["checker"].items():
                assert runner.sha(ROOT / "hlscheck" / name) == value
            if r["status"] in ("equivalent", "not_equivalent"):
                evidence = verify_evidence(folder / "proof", timeout_ms=60000)
                assert evidence["passed"]
                queries += len(evidence["queries"])
                proof = json.loads((folder / "proof/result.json").read_text())
                assert proof["complete_unwinding_required"]
            if r["status"] == "equivalent":
                assert r["native"]["passed"] and runner.sha(folder / "native.c") == r["native"]["harness_sha256"]
                native_pairs += r["native"]["trials"]
                accepted.append((case, model))
            else:
                assert not (OUT / "hardware" / case["id"] / (model + ".json")).exists()
    hardware_files = sorted((OUT / "hardware").glob("*/*.json"))
    transactions = 0
    for path in hardware_files:
        h = json.loads(path.read_text())
        assert h["status"] == "complete", path
        assert h["source_sha256"] == runner.sha(ROOT / h["source"])
        config_hashes.add(h["configuration_sha256"])
        folder = OUT / "hls" / (h["case"] + "_" + h["variant"])
        assert h["testbench_sha256"] == runner.sha(folder / "tb.c")
        assert h["timing_coverage"]["unexplained_unconstrained_endpoints"] == []
        assert h["hls"]["exit_code"] == h["synthesis"]["exit_code"] == h["timing"]["exit_code"] == 0
        assert h["rtl_simulation_passed"] and h["rtl_simulation_calls"] == 16
        transactions += h["rtl_simulation_calls"]
    assert len(config_hashes) == 1
    assert len(hardware_files) == len(plan["cases"]) + len(accepted) == 34
    # Supplement primary tests with independently varied scalar arguments.
    # Keep the original run and its retained driver fingerprints unchanged.
    old_sample = runner.sample_value
    def independent_sample(spec, number):
        if spec["length"] is None and number >= 16:
            number = number * 1000 + spec["position"] * 100 + 67
        return old_sample(spec, number)
    runner.sample_value = independent_sample
    def supplement(item):
        case, model = item
        original = (ROOT / case["source"]).read_text()
        candidate = (runner.generation_folder(model, case) / "candidate.c").read_text()
        code = runner.testbench(original, candidate, trials=264)
        record = compile_run(code, OUT / "native_supplement" / model / case["id"], 0)
        record.update(case=case["id"], model=model, trials=264)
        return record
    with ThreadPoolExecutor(max_workers=2) as pool:
        supplemental = list(pool.map(supplement, accepted))
    runner.sample_value = old_sample
    by_id = {c["id"]: c for c in plan["cases"]}
    get = lambda name: (ROOT / by_id[name]["source"]).read_text()
    absolute = get("chstone_gsm_abs")
    fraction = get("hlseval_extractFloat64Frac")
    stencil = get("machsuite_stencil5")
    atax = get("polybench_atax4")
    controls = [
        ("equal_control", fraction, fraction, 0),
        ("u64_narrowing_fault", fraction, fraction.replace("return a & 0x000FFFFFFFFFFFFFLL;", "return (unsigned int)(a & 0x000FFFFFFFFFFFFFLL);"), 1),
        ("signed16_saturation_fault", absolute, absolute.replace("return a < 0 ? (a == MIN_WORD ? MAX_WORD : -a) : a;", "return a < 0 ? -a : a;"), 1),
        ("unwritten_array_boundary_fault", stencil, stencil.rsplit("}", 1)[0] + "sol[24] = 0u;\n}\n", 1),
        ("observable_temporary_fault", atax, atax.rsplit("}", 1)[0] + "tmp[0] = 0u;\n}\n", 1),
    ]
    control_rows = []
    for name, original, candidate, expected in controls:
        if expected:
            assert original != candidate
        r = compile_run(runner.testbench(original, candidate, trials=32), OUT / "harness_validation" / name, expected)
        r.update(id=name, expected="mismatch detected" if expected else "no mismatch", provenance="Deliberate harness control, not an LLM output")
        control_rows.append(r)
    result = {"passed": True, "frozen_originals_checked": 12, "raw_model_responses_and_candidates_checked": 24,
              "identical_prompt_pairs_checked": 12, "primary_smt_queries_replayed": queries,
              "verified_candidates": len(accepted), "primary_compiled_c_pair_trials": native_pairs,
              "supplementary_compiled_c_pair_trials": len(supplemental) * 264,
              "actual_hls_implementations": len(hardware_files), "rtl_transactions": transactions,
              "single_hls_configuration": True, "native_supplement": supplemental,
              "native_harness_controls": control_rows,
              "scope": "Exact raw-response extraction, current checker/retained driver hashes, source provenance, accepted SMT replay, independent-scalar compiled-C supplement, seeded harness controls and HLS source/testbench/configuration/RTL checks. No new model outputs or repairs."}
    runner.save(OUT / "validation.json", result)
    print("Validated24 raw outputs,22 proofs/native pairs,34 hardware implementations and544 RTL transactions.", flush=True)


def export(plan, summary):
    fields = ["benchmark", "model", "verdict", "ast_unchanged", "original_cycles", "candidate_cycles", "latency_speedup",
              "original_area_um2", "candidate_area_um2", "original_delay_ns", "candidate_delay_ns", "area_latency_ratio", "useful_improvement"]
    with (OUT / "measurements.csv").open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        for row in summary["cases"]:
            original, candidate = row.get("baseline_hardware", {}), row.get("hardware", {})
            writer.writerow(dict(zip(fields, [row["case"], row["model"], row["status"], row.get("ast_unchanged"),
                original.get("cycles"), candidate.get("cycles"), row.get("latency_speedup"), original.get("area_um2"),
                candidate.get("area_um2"), original.get("delay_ns"), candidate.get("delay_ns"),
                row.get("area_latency_ratio"), row.get("qor_improves")])) )
    notes = {
        "machsuite_gemm4": ("Move accumulation into output array instead of a local scalar.", "Unroll the four-product dot product, cache each input row and use grouped additions."),
        "machsuite_stencil5": ("Canonical source unchanged.", "Three partial accumulators with unrolled filter columns."),
        "polybench_mvt4": ("Compound assignment spelling only.", "Fuse the two output loops and unroll four-product sums."),
        "polybench_atax4": ("Canonical source unchanged.", "Cache x/row elements, unroll the dot product and use four output accumulators; proof inconclusive."),
        "polybench_bicg4": ("Canonical source unchanged.", "Cache p/row elements and use four scalar s accumulators; proof inconclusive."),
        "polybench_syrk4": ("Canonical source unchanged.", "Factor alpha outside the dot product and update each lower-triangle c element once."),
        "machsuite_rj_xtime": ("Canonical source unchanged.", "Replace conditional reduction with branchless top-bit-controlled XOR."),
        "chstone_gsm_abs": ("Canonical source unchanged.", "Unsigned bitwise magnitude and explicit saturation adjustment."),
        "chstone_gsm_add": ("Canonical source unchanged.", "Biased unsigned range test and one saturation branch."),
        "hlseval_extractFloat64Sign": ("Canonical source unchanged.", "Explicit return cast; the sign extraction remains the same."),
        "hlseval_extractFloat64Frac": ("Equivalent typedef/mask spelling.", "Explicit unsigned mask suffix; no algorithmic change."),
        "hlseval_float64_is_nan": ("Canonical source unchanged.", "Exponent/fraction predicates replace the shifted-pattern comparison."),
    }
    runner.save(OUT / "optimization_notes.json", {k:dict(zip(runner.MODELS,v)) for k,v in notes.items()})
    dossier = OUT / "dossiers"
    dossier.mkdir(exist_ok=True)
    for case in plan["cases"]:
        def link(path):
            return os.path.relpath(path, dossier).replace('\\','/')
        lines = ["# " + case["id"], "", "Origin: " + case["suite"], "", case["preparation"], "",
                 "## Frozen original", "", "```c", (ROOT / case["source"]).read_text().rstrip(), "```", ""]
        for model in runner.MODELS:
            row = next(r for r in summary["cases"] if r["case"] == case["id"] and r["model"] == model)
            generation = runner.generation_folder(model, case)
            proof = OUT / "evaluations" / model / case["id"] / "proof/result.json"
            lines += ["## " + model, "", "Verdict: **" + row["status"] + "**. " + notes[case["id"]][runner.MODELS.index(model)], "",
                      f'[Raw response]({link(generation / "response.txt")}) | [Exact prompt]({link(OUT / "prompts" / case["id"] / "prompt.txt")}) | [Proof]({link(proof)})', "",
                      "```c", (generation / "candidate.c").read_text().rstrip(), "```", ""]
            if "latency_speedup" in row:
                a,b = row["baseline_hardware"],row["hardware"]
                lines += [f'Area: {a["area_um2"]:.3f} -> {b["area_um2"]:.3f} um^2. Cycles: {a["cycles"]:g} -> {b["cycles"]:g}. '
                          f'Critical-path delay: {a["delay_ns"]:.6f} -> {b["delay_ns"]:.6f} ns. '
                          f'Area-latency ratio: {row["area_latency_ratio"]:.6f}.', ""]
        runner.write(dossier / (case["id"] + ".md"), '\n'.join(lines))


def figures(plan, summary):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    import numpy as np
    plt.rcParams.update({"font.size":10,"axes.spines.top":False,"axes.spines.right":False})
    fig,axs = plt.subplots(2,2,figsize=(14,9),layout="constrained")
    colors = ["#2563eb","#0f766e"]
    labels = ["Qwen Coder 1.5B","GPT-6.1-Sol"]
    counts = [summary["models"][m]["status_counts"] for m in runner.MODELS]
    for i,c in enumerate(counts):
        axs[0,0].barh(i,c.get("equivalent",0),color=colors[i])
        axs[0,0].barh(i,c.get("inconclusive",0),left=c.get("equivalent",0),color="#f59e0b",hatch="//")
        axs[0,0].text(.2,i,f'{c.get("equivalent",0)} equivalent',va="center",color="white",weight="bold")
        if c.get("inconclusive",0):axs[0,0].text(11,i,"2 inconclusive",ha="center",va="center",fontsize=8)
    axs[0,0].set(yticks=[0,1],yticklabels=labels,xlim=(0,12.5),xlabel="Candidates (12 per model)",title="Formal outcomes; inconclusive is not incorrect")
    compute = [c["id"] for c in plan["cases"] if c["category"] == "adapted_kernel"]
    short = ["GEMM","Stencil","MVT","ATAX","BiCG","SYRK"]
    x = np.arange(len(compute))
    for ax,key,title,ylabel in [(axs[0,1],"latency_speedup","Compute-kernel latency (higher is better)","Original cycles / candidate cycles"),
                                (axs[1,0],"area_latency_ratio","Compute-kernel area x latency (lower is better)","Candidate cost / original cost")]:
        for i,model in enumerate(runner.MODELS):
            vals=[]
            for cid in compute:
                row=next(r for r in summary["cases"] if r["case"]==cid and r["model"]==model)
                vals.append(row.get(key,float("nan")))
            xx=x+(i-.5)*.34
            ax.bar(xx,vals,width=.32,label=labels[i],color=colors[i])
            for xpos,value in zip(xx,vals):
                if np.isnan(value):ax.text(xpos,.08,"?",ha="center",color="#b45309",weight="bold")
        ax.axhline(1,color="#475569",ls="--",lw=1)
        ax.set(xticks=x,xticklabels=short,title=title,ylabel=ylabel,ylim=(0,None))
        ax.legend(fontsize=8)
    categories=["Lower cost","Unchanged cost","Higher cost","Unresolved"]
    for i,model in enumerate(runner.MODELS):
        a=summary["models"][model]
        vals=[a["useful_improvements"],a["area_latency_unchanged"],a["area_latency_regressions"],a["attempts_planned"]-a["measured_candidates"]]
        axs[1,1].bar(np.arange(4)+(i-.5)*.34,vals,width=.32,color=colors[i],label=labels[i])
    axs[1,1].set(xticks=np.arange(4),xticklabels=categories,title="Hardware outcomes across all 12 cases",ylabel="Candidates")
    axs[1,1].legend(fontsize=8)
    fig.suptitle("Same-prompt HLS optimization: 12 dataset-derived kernels",fontsize=16,weight="bold")
    destination=OUT/"figures";destination.mkdir(exist_ok=True)
    fig.savefig(destination/"comparison.png",dpi=180)
    fig.savefig(destination/"comparison.svg")
    plt.close(fig)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--figures-only",action="store_true",help="Use the reporting Python without rerunning validation")
    args=parser.parse_args()
    plan=json.loads(runner.PLAN.read_text())
    if args.figures_only:
        figures(plan,json.loads((OUT/"summary.json").read_text()))
        print("Saved comparison figures using",sys.executable,flush=True)
        return
    runner.report(plan)
    summary=json.loads((OUT/"summary.json").read_text())
    validate(plan,summary)
    export(plan,summary)
    try:
        figures(plan,summary)
    except ModuleNotFoundError as error:
        if error.name not in ("matplotlib","numpy"):
            raise
        reporting_python=Path(sys.base_prefix)/("python.exe" if os.name=="nt" else "bin/python3")
        if reporting_python.resolve()==Path(sys.executable).resolve():
            raise
        subprocess.run([str(reporting_python),str(Path(__file__).resolve()),"--figures-only"],check=True,timeout=90)
    print("Saved verified report, complete CSV, twelve source dossiers and figures.",flush=True)


if __name__=="__main__":
    main()
