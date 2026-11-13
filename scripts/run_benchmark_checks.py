"""Compare our checker and the ESBMC/Z3 implementation on recorded C pairs."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import hashlib
import json

from hlscheck import check_equivalence
from hlscheck.esbmc_backend import run_esbmc


def main():
    root = Path(__file__).resolve().parents[1]
    output = root / "results/benchmarks"
    output.mkdir(parents=True, exist_ok=True)
    rows = []
    for family, folder in (("scale", "demo"), ("unswitch", "demo"),
                           ("gemm", "machsuite_u32"), ("stencil", "machsuite_u32")):
        directory = root / "benchmarks" / folder
        original_path = directory / f"{family}_original.c"
        original = original_path.read_text()
        for variant, expected in (("optimized", "equivalent"), ("buggy", "not_equivalent")):
            candidate_path = directory / f"{family}_{variant}.c"
            candidate = candidate_path.read_text()
            name = f"{family}_{variant}"
            our = check_equivalence(original, candidate, "kernel", smt_path=output / (name + ".smt2"))
            external = run_esbmc(original, candidate, function="kernel", output_dir=output / name, timeout_seconds=30)
            row = {"case": name, "expected": expected, "hlscheck": our, "esbmc": external,
                   "original": str(original_path.relative_to(root)), "candidate": str(candidate_path.relative_to(root)),
                   "original_sha256": hashlib.sha256(original_path.read_bytes()).hexdigest(),
                   "candidate_sha256": hashlib.sha256(candidate_path.read_bytes()).hexdigest(),
                   "provenance": "Codex-authored optimization" if variant == "optimized" else "Deliberately seeded negative control",
                   "hls_qor": "not measured"}
            rows.append(row)
            (output / f"{name}.json").write_text(json.dumps(row, indent=2) + "\n", encoding="utf-8")
            print(f"{name:24} ours={our['status']:18} ESBMC={external['status']:18}", flush=True)
    passed = all(r["hlscheck"]["status"] == r["esbmc"]["status"] == r["expected"] for r in rows)
    conclusive = [r for r in rows if r["esbmc"]["status"] in ("equivalent", "not_equivalent")]
    summary = {"passed": passed,
               "hlscheck_passed": all(r["hlscheck"]["status"] == r["expected"] for r in rows),
               "reference_conclusive": len(conclusive), "reference_total": len(rows),
               "reference_agrees_when_conclusive": all(r["esbmc"]["status"] == r["hlscheck"]["status"] for r in conclusive),
               "cases": rows}
    (output / "summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print("Comparison", "PASS" if passed else "contains unresolved cases", flush=True)
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
