"""Render the recorded public-dataset audit and results without rerunning tools."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


import json


def main():
    root = Path(__file__).resolve().parents[1]
    output = root / "results/eqbench"
    audit = json.loads((output / "audit.json").read_text())
    summary = json.loads((output / "summary.json").read_text())
    complete = sum((root / p["candidate"]).exists() for p in audit["pairs"])
    audit["complete_source_pairs"] = complete
    audit["indexed_old_version_files"] = audit["total_pairs"]
    (output / "audit.json").write_text(json.dumps(audit, indent=2) + "\n", encoding="utf-8")
    lines = ["# EqBench public C dataset: initial evaluation", "",
             f"Repository snapshot: `{audit['snapshot']}`.", "",
             "The upstream README advertises 147 equivalent and 125 non-equivalent",
             "cases across C and Java. We report what is actually present in this",
             "pinned C snapshot, rather than treating advertised counts as measured.", "",
             f"- Indexed old-version C files: {audit['total_pairs']}.",
             f"- Complete old/new C file pairs: {complete}.",
             f"- Labels among indexed records: {audit['labels']}.",
             f"- Compatible with the current generated-harness adapter: {audit['eligible_for_current_adapter']}.",
             f"- Evaluated: {summary['evaluated']} (all currently eligible cases).",
             f"- Status counts: {summary['statuses']}.",
             f"- Conclusive verdicts: {summary['conclusive']}; agreements with upstream labels: {summary['agreements']}.", "",
             "## Interpretation", "",
             "The two conclusive checks match their labels. This is **not 100%",
             "accuracy on EqBench**: the other evaluated pairs are inconclusive,",
             "and most indexed pairs are excluded by current frontend restrictions.",
             "All evaluated pairs have signed-int interfaces, so our uint32-only",
             "interpreter rejects them and the pipeline uses ESBMC/Z3. Thus these",
             "results evaluate the composite tool's fallback, not signed-integer",
             "capabilities of our own interpreter.", "",
             "The experiment uses unmodified source semantics, full scalar type",
             "domains, no added range preconditions, unwind bound 32, a requested",
             "3000 ms solver wall-clock budget, and an external process grace period",
             "of 10 seconds. Unwinding assertions remain enabled. `incomplete_unwind`",
             "does not imply a program mismatch. An `unknown` result is not an",
             "incorrect classification. These limitations expose genuine next steps",
             "in support for general loops and richer C interfaces.", "",
             "## Every evaluated case", "",
             "| Pair | Published label | Composite result |",
             "|---|---|---|"]
    for row in summary["rows"]:
        lines.append(f"| {row['pair']} | {row['published_label']} | {row['result']['status']} |")
    lines += ["", "## Exclusions and labels", "",
              "See `audit.json` for every included/excluded record, its original",
              "metadata, source hashes and exclusion reason. Common exclusions are",
              "includes, helper functions, unsupported types and missing metadata.",
              "`cases/` preserves the symbolic-stage result, generated ESBMC C",
              "harness, command line, constraints, output and final verdict.", "",
              "[Upstream issue #15](https://github.com/shrBadihi/EqBench/issues/15)",
              "reports disputed labels related to logic, signed overflow and NaN",
              "semantics. This is an external report, not our own discovery. No",
              "labels have been changed, and the present run does not evaluate",
              "those reported cases.", "",
              "Reproduce with `python scripts/run_eqbench.py --limit 14 --timeout-ms 3000",
              "--max-unroll 32`, then `python scripts/write_eqbench_report.py` using the",
              "project virtual environment."]
    (output / "REPORT.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("Wrote results/eqbench/REPORT.md")


if __name__ == "__main__":
    main()
