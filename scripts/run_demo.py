"""Reproduce the first equivalence-checker milestone without an HLS tool."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import hashlib
import json

from hlscheck import check_equivalence


def main():
    root = Path(__file__).resolve().parents[1]
    directory = root / "benchmarks" / "demo"
    output = root / "results" / "demo"
    output.mkdir(parents=True, exist_ok=True)
    rows = []
    for family in ("scale", "unswitch"):
        for variant, expected in (("optimized", "equivalent"), ("buggy", "not_equivalent")):
            original = directory / f"{family}_original.c"
            candidate = directory / f"{family}_{variant}.c"
            case = f"{family}_{variant}"
            result = check_equivalence(original.read_text(), candidate.read_text(), "kernel",
                                       smt_path=output / f"{case}.smt2")
            result.update(case=case, expected=expected,
                          original=str(original.relative_to(root)), candidate=str(candidate.relative_to(root)),
                          original_sha256=hashlib.sha256(original.read_bytes()).hexdigest(),
                          candidate_sha256=hashlib.sha256(candidate.read_bytes()).hexdigest(),
                          provenance="Initial Codex-session demonstration; buggy variants are deliberately seeded controls",
                          hls_qor="not measured")
            (output / f"{case}.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
            rows.append(result)
            print(f"{case:24} {result['status']:20} {result['elapsed_seconds']:.4f}s")
    passed = all(r["status"] == r["expected"] for r in rows)
    summary = {"passed": passed, "cases": rows, "hls_qor": "not measured"}
    (output / "summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print(f"\nDemo {'PASS' if passed else 'FAIL'}; evidence saved in results/demo/")
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
