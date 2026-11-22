#!/usr/bin/env python3
"""Write evaluation/results/eval/pool_stats.md from evaluation/benchmarks/labels_summary.json."""
from __future__ import annotations

from collections import Counter
import json
from pathlib import Path


def main() -> int:
    summary = json.loads(Path("evaluation/benchmarks/labels_summary.json").read_text())["tasks"]
    total = Counter()
    lines = ["# Candidate pools and labels", "",
             "Labels: formal identity check against P_ref (VWE pipeline) combined with native",
             "sanitizer differential testing; see `vwe/eval/labels.py` for the rule and its limits.",
             "Pools contain P_ref, unchanged P0 and deterministic P_ref mutants. **No LLM-generated",
             "candidates**: no live provider was configured.", "",
             "| task | candidates | correct | incorrect | unknown | flags |", "|---|---|---|---|---|---|"]
    for task, row in sorted(summary.items()):
        c = Counter(row["counts"])
        total.update(c)
        lines.append(f"| {task} | {sum(c.values())} | {c['correct']} | {c['incorrect']} | {c['unknown']} | "
                     f"{'; '.join(row['flags']) or ''} |")
    lines += ["", f"Totals over {len(summary)} tasks: {sum(total.values())} candidates, "
              f"{total['correct']} correct, {total['incorrect']} incorrect, {total['unknown']} unknown "
              "(unknown labels are excluded from metrics and reported)."]
    out = Path("evaluation/results/eval/pool_stats.md")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text("\n".join(lines) + "\n")
    print(out.read_text())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
