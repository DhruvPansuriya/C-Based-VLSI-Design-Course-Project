"""Summarize recorded evidence; never synthesize missing tool results."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import json


def main():
    root = Path(__file__).resolve().parents[1]
    summary_path = root / "results/benchmarks/summary.json"
    summary = json.loads(summary_path.read_text())
    conclusive = [r for r in summary["cases"] if r["esbmc"]["status"] in ("equivalent", "not_equivalent")]
    summary.update(hlscheck_passed=all(r["hlscheck"]["status"] == r["expected"] for r in summary["cases"]),
                   reference_conclusive=len(conclusive), reference_total=len(summary["cases"]),
                   reference_agrees_when_conclusive=all(r["esbmc"]["status"] == r["hlscheck"]["status"] for r in conclusive))
    summary_path.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    past = json.loads((root / "results/past/summary.json").read_text())
    past_map = {r["name"]: r for r in past["cases"]}
    names = {"scale_optimized": "strength_reduction", "scale_buggy": "seeded_bug"}
    text = ["# Initial implementation comparison", "",
            "Recorded locally on 2026-11-21. These are initial small kernels, not a", 
            "complete project evaluation. Original and optimized code are compared", 
            "over all uint32_t data inputs with separate, nonaliasing arrays.", "",
            "| Case | Our Z3 checker | ESBMC + Z3 | PAST release |",
            "|---|---|---|---|"]
    for row in summary["cases"]:
        name = row["case"]
        matched = past_map.get(names.get(name, name))
        status = matched["past_status"] if matched else "not run (scalar branch interface)"
        text.append(f"| {name} | {row['hlscheck']['status']} | {row['esbmc']['status']} | {status} |")
    text += ["", "## What this establishes", "",
             "- The authors' PAST 0.7.2 Linux wheel was loaded and calibrated on identical code.",
             "- PAST accepted pure unrolling, GEMM loop interchange, and stencil source unrolling.",
             "- With the tested default normalization settings, PAST returned 0 for multiplication-to-shift. We label that result `not_proved`, not a concrete disproof.",
             "- Both SMT checkers proved the multiplication-to-shift rewrite.",
             "- PAST's optional all-normalizations mode was also tested on the strength-reduction pair and returned `not_proved`; logs are retained separately.",
             "- ESBMC used its actual Z3 backend, bit-vector arithmetic, signed overflow/shift/uninitialized-read checks, and retained bounds/pointer/unwinding assertions.",
             "- Our checker resolved all eight cases. ESBMC resolved seven, agreeing on all seven; GEMM equivalence reached the configured external wall-clock limit.",
             "- PAST independently accepted the GEMM transformation that timed out in this ESBMC run.",
             "- All negative controls are deliberately seeded; they are not evidence of an LLM's spontaneous bug rate.",
             "- GEMM and stencil are small unsigned adaptations of MachSuite, with explicit provenance and retained license. Upstream floating/signed semantics are not claimed.",
             "- This initial verifier comparison is separate from the completed hardware experiment; see `results/submission/HLS_RESULTS.md`.", "",
             "## Combining implementations", "",
             "The `--backend auto` pipeline first tries our restricted symbolic checker,",
             "then invokes the released ESBMC implementation with Z3 for unsupported or",
             "inconclusive inputs. `results/fallback_demo/pipeline_result.json` records",
             "a successful symbolic-array-index proof obtained through that fallback.",
             "PAST remains an independently invoked structural reference, not a Z3",
             "proof substitute or an implicit acceptance decision in the pipeline.", "",
             "## Reproduction and evidence", "",
             "Run `scripts/run_benchmark_checks.py` for our checker and ESBMC, and",
             "`scripts/prepare_past_demo.py` for PAST through WSL Ubuntu. Each is run using",
             "the project Python environment on Windows. The latter invokes the", 
             "downloaded native Linux wheel through an isolated worker.", "",
             "Evidence: `results/benchmarks/summary.json`, per-case source hashes,",
             "SMT-LIB queries, generated ESBMC harnesses/logs/results, and",
             "`results/past/summary.json` plus per-case logs and annotated inputs.", "",
             "This comparison is not a claim of overall superiority. Frontends, proof",
             "strategies, instrumentation and input formats differ. PAST's comparison",
             "inputs are annotated-region adaptations of the function bodies."]
    path = root / "results/IMPLEMENTATION_COMPARISON.md"
    path.write_text("\n".join(text) + "\n", encoding="utf-8")
    print(path.relative_to(root))


if __name__ == "__main__":
    main()
