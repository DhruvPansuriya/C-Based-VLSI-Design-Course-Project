"""Prove i-j-k == k-i-j, compile as C++, then measure both with real HLS."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
if __package__ in (None, ""):
    sys.path.insert(0, str(ROOT))

SOURCE = ROOT / "benchmarks/matmul_loop_order"
OUT = ROOT / "results/matmul_loop_order"
NAMES = {"original": "matmul_ijk", "optimized": "matmul_kij"}


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save(path, value):
    path.write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")


def prepare():
    from hlscheck import verify_equivalence
    from hlscheck.evidence import verify_evidence
    from scripts.validate_native import hls_testbench

    OUT.mkdir(parents=True, exist_ok=True)
    a, b = (SOURCE / (NAMES[v] + ".cpp") for v in ("original", "optimized"))
    print("1. PROVE: 4x4 uint32 matrix multiplication, i-j-k versus k-i-j", flush=True)
    result = verify_equivalence(a.read_text(), b.read_text(), "kernel",
                                output_dir=OUT / "proof", timeout_ms=60000)
    for obligation in result["obligations"]:
        print("  ", obligation["id"], "->", obligation["status"], flush=True)
    print("  Final:", result["status"], "in", result["elapsed_seconds"], "seconds", flush=True)
    if result["status"] != "equivalent":
        raise RuntimeError("HLS blocked: the source pair has not been proved equivalent")
    evidence = verify_evidence(OUT / "proof", timeout_ms=60000)
    assert evidence["passed"]
    save(OUT / "evidence_replay.json", evidence)
    assert result["source_sha256"] == {"original": digest(a), "candidate": digest(b)}

    print("2. COMPILE C++17: 264 directed/random comparisons", flush=True)
    sample = r'''
uint32_t sample_a[16], sample_b[16], sample_out[16];
for (int p=0; p<16; p++) {sample_a[p]=p+1; sample_b[p]=p+1;}
kernel(sample_a, sample_b, sample_out);
printf("A = B = rows [1..4], [5..8], [9..12], [13..16]; A*B:\n");
for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) printf("%4u ", sample_out[i*4+j]);
    printf("\n");
}
return 0;}
'''
    native_source = OUT / "native_cpp_test.cpp"
    test = hls_testbench(a.read_text(), count=264).replace("return 0;}", sample)
    native_source.write_text("#include <stdio.h>\n" + b.read_text() + "\n" + test,
                             encoding="utf-8")
    compiler = shutil.which("clang++") or shutil.which("clang")
    if not compiler:
        raise RuntimeError("A C++ compiler is required for the native demonstration")
    executable = OUT / "matmul_cpp_check.exe"
    command = [compiler, "-std=c++17", "-O2", str(native_source), "-o", str(executable)]
    built = subprocess.run(command, capture_output=True, text=True, timeout=60)
    (OUT / "native_compile.log").write_text(built.stdout + built.stderr, encoding="utf-8")
    if built.returncode:
        raise RuntimeError(built.stderr)
    run = subprocess.run([str(executable)], capture_output=True, text=True, timeout=15)
    (OUT / "native_run.log").write_text(run.stdout + run.stderr, encoding="utf-8")
    if run.returncode:
        raise RuntimeError("Compiled C++ comparison failed: " + run.stderr)
    print("  C++ comparisons: PASS\n" + run.stdout, flush=True)
    native = {"passed": True, "comparisons": 264, "cpp_standard": "c++17",
              "command": command, "harness_sha256": digest(native_source),
              "sample_stdout": run.stdout}
    save(OUT / "native.json", native)

    inputs = OUT / "hls_inputs"
    inputs.mkdir(exist_ok=True)
    for source in (a, b):
        copied = inputs / (source.stem + ".c")
        copied.write_bytes(source.read_bytes())
        assert digest(copied) == digest(source)
    (inputs / "tb.c").write_text(hls_testbench(a.read_text(), count=16), encoding="utf-8")
    gate = {"verification": {"status": "equivalent"},
            "original_sha256": digest(a), "candidate_sha256": digest(b),
            "integrated_proof_sha256": digest(OUT / "proof/result.json"),
            "proof_evidence_replayed": True, "native_cpp_passed": True,
            "scope": "C-compatible C++ source; HLS receives byte-identical C11 input"}
    save(OUT / "hls_gate.json", gate)
    return result


def measure_linux():
    # Importing this module configures the already installed Linux HLS tools.
    from tools.run_hls_linux import run_one

    gate_path = OUT / "hls_gate.json"
    gate = json.loads(gate_path.read_text())
    assert gate["verification"]["status"] == "equivalent"
    assert gate["proof_evidence_replayed"] and gate["native_cpp_passed"]
    assert gate["integrated_proof_sha256"] == digest(OUT / "proof/result.json")
    proof = json.loads((OUT / "proof/result.json").read_text())
    assert proof["status"] == "equivalent"
    rows = {}
    print("3. FRESH HLS + RTL SIMULATION + MAPPING + TIMING", flush=True)
    for variant, name in NAMES.items():
        key = "original_sha256" if variant == "original" else "candidate_sha256"
        cpp = SOURCE / (name + ".cpp")
        c = OUT / "hls_inputs" / (name + ".c")
        assert digest(cpp) == digest(c) == gate[key]
        assert proof["source_sha256"]["original" if variant == "original" else "candidate"] == gate[key]
        row = run_one({"name": "matmul_k_outer_demo"}, variant, force=True,
                      source_override=c, testbench_override=OUT / "hls_inputs/tb.c",
                      proof_override=gate_path, output_root=OUT / "hls")
        if row["status"] != "complete":
            raise RuntimeError(row.get("error", "HLS experiment failed"))
        rows[variant] = row
    summary = {"matrix_dimension": 4, "loop_orders": ["i-j-k", "k-i-j"],
               "proof_status": proof["status"], "proof_elapsed_seconds": proof["elapsed_seconds"],
               "source_cpp_sha256": {k: digest(SOURCE / (v + ".cpp")) for k, v in NAMES.items()},
               "fresh_hls_run": True, "native_cpp_comparisons": 264,
               "hls_input_mode": "C11, byte-identical to C-compatible .cpp sources",
               "not_added_to_main_50_pair_cohort": True,
               "measurements": rows,
               "scope": "Mapped pre-layout Nangate45 ASIC estimates at a common 10 ns clock; no FPGA or routed-timing claim"}
    save(OUT / "summary.json", summary)
    report(summary)


def report(summary):
    original, candidate = (summary["measurements"][v] for v in ("original", "optimized"))
    columns = [("Cell area (um^2)", "area_um2"), ("Latency (cycles)", "cycles"),
               ("Latency at 10 ns clock (ns)", "latency_at_target_ns"),
               ("Mapped critical-path delay (ns)", "delay_ns"),
               ("Area x latency (um^2 ns)", "area_latency_product_um2_ns")]
    lines = ["# Matrix multiplication: i-j-k versus k-i-j", "",
             "The candidate moves k to the outermost loop. No other source optimization or pragma is added.", "",
             "- Source: [i-j-k](../../benchmarks/matmul_loop_order/matmul_ijk.cpp), "
             "[k-i-j](../../benchmarks/matmul_loop_order/matmul_kij.cpp).",
             "- Integrated equivalence proof: **equivalent**; all 32-bit unsigned inputs, with valid nonoverlapping arrays.",
             "- Native C++17: 264 directed/random comparisons passed.",
             "- Fresh Bambu runs: 16 passing RTL transactions per implementation.",
             "- Target: Nangate45 typical, 10 ns clock; pre-layout mapped ASIC estimates.", "",
             "| Metric | Original i-j-k | Candidate k-i-j | Change |",
             "| --- | ---: | ---: | ---: |"]
    print("\n4. MEASURED COMPARISON (negative change means lower)", flush=True)
    for label, key in columns:
        a, b = original[key], candidate[key]
        change = 100 * (b / a - 1)
        lines.append(f"| {label} | {a:.6g} | {b:.6g} | {change:+.2f}% |")
        print(f"  {label:34s} {a:12.6g} -> {b:12.6g} ({change:+.2f}%)", flush=True)
    cost_change = 100 * (candidate["area_latency_product_um2_ns"] /
                         original["area_latency_product_um2_ns"] - 1)
    outcome = "improves" if cost_change < -0.1 else ("regresses" if cost_change > 0.1 else "leaves essentially unchanged")
    lines += ["", f"Under this configuration, moving k outermost **{outcome}** area x latency ({cost_change:+.2f}%).", "",
              "A functional proof establishes equal results, not better hardware. Loop order changes memory traffic, "
              "reuse opportunities, scheduling and accumulation dependencies; the HLS compiler determines the resulting hardware.", "",
              "The .cpp sources use the C-compatible subset. Our checker models C semantics; Bambu compiles byte-identical "
              "C11 copies. The native test separately compiles as C++17. This does not establish support for general C++.", "",
              "Critical-path delay is distinct from total execution latency. These results are a new isolated demonstration "
              "and do not modify the main 50-pair experiment counts.", "",
              "Reproduce: `python scripts/run_matmul_demo.py` from the project root. "
              "Formal obligations are under `proof/`; all synthesis, simulation, mapping and timing logs are under `hls/`.", ""]
    (OUT / "REPORT.md").write_text("\n".join(lines), encoding="utf-8")
    print("  Outcome:", outcome, "area x latency.", flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--verify-only", action="store_true", help="Prove equivalence and run C++ tests, without HLS")
    parser.add_argument("--hls-linux", action="store_true", help=argparse.SUPPRESS)
    args = parser.parse_args()
    if args.hls_linux:
        measure_linux()
        return 0
    prepare()
    if args.verify_only:
        return 0
    if sys.platform == "win32":
        path = Path(__file__).resolve().as_posix()
        linux_path = "/mnt/" + path[0].lower() + path[2:]
        command = ["wsl.exe", "-d", "Ubuntu", "--", "python3", linux_path, "--hls-linux"]
        with (OUT / "hls_runner.log").open("w", encoding="utf-8") as log:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                       text=True, encoding="utf-8", errors="replace")
            for line in process.stdout:
                print(line, end="", flush=True)
                log.write(line)
                log.flush()
            if process.wait():
                raise RuntimeError("HLS run failed; inspect results/matmul_loop_order/hls_runner.log")
    else:
        measure_linux()
    print("\nSaved results/matmul_loop_order/REPORT.md", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
