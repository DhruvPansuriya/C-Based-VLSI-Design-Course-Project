"""Cross-check our initial examples with the real ESBMC implementation and Z3."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import json

from hlscheck.esbmc_backend import run_esbmc


def main():
    root = Path(__file__).resolve().parents[1]
    inputs = root / "benchmarks/demo"
    output = root / "results/esbmc"
    results = []
    for family in ("scale", "unswitch"):
        for variant, expected in (("optimized", "equivalent"), ("buggy", "not_equivalent")):
            name = f"{family}_{variant}"
            result = run_esbmc((inputs / f"{family}_original.c").read_text(),
                               (inputs / f"{family}_{variant}.c").read_text(),
                               output_dir=output / name, function="kernel")
            result.update(case=name, expected=expected)
            results.append(result)
            print(f"{name:24} {result['status']:20} {result['elapsed_seconds']:.3f}s", flush=True)
    summary = {"passed": all(r["status"] == r["expected"] for r in results), "cases": results}
    (output / "summary.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    return 0 if summary["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
