#!/usr/bin/env python3
"""Label every candidate of each benchmark task (formal identity check + native differential).

Writes <task>/eval/labels.json (never read by the pipeline) and an aggregate
summary with class balance, unknown counts and flagged tasks.
"""
from __future__ import annotations

import argparse
from collections import Counter
import json
from pathlib import Path
import sys
from time import monotonic

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.config import load_config  # noqa: E402
from vwe.eval.labels import as_json, formal_identity, label_pool  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--task", action="append", default=[])
    ap.add_argument("--tasks", type=Path, default=Path("evaluation/benchmarks/tasks"))
    ap.add_argument("--config", type=Path, default=Path("config/benchmark.toml"))
    ap.add_argument("--samples", type=int, default=10000)
    ap.add_argument("--summary", type=Path, default=Path("evaluation/benchmarks/labels_summary.json"))
    ap.add_argument("--runs-root", type=Path, default=Path("runs/labels"))
    args = ap.parse_args()
    cfg = load_config(args.config)
    roots = sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file()) if args.all \
        else [args.tasks / t for t in args.task]

    def formal(task_dir: Path, cid: str) -> tuple[str, str]:
        return formal_identity(task_dir, cid, cfg, args.runs_root / task_dir.name / cid)

    summary = json.loads(args.summary.read_text()) if args.summary.is_file() else {"tasks": {}}
    for root in roots:
        start = monotonic()
        manifest = json.loads((root / "task.json").read_text())
        pool = {c: (root / f).read_text() for c, f in manifest["candidates"].items()}
        labels = label_pool(root, pool, formal, samples=args.samples)
        (root / "eval/labels.json").write_text(json.dumps(as_json(labels), indent=2) + "\n")
        counts = Counter(l.label for l in labels)
        flags = [f"{l.candidate}: {l.flag}" for l in labels if l.flag]
        if not counts["correct"] or not counts["incorrect"]:
            flags.append("task lacks a correct or an incorrect labelled candidate")
        summary["tasks"][root.name] = {"counts": dict(counts), "flags": flags,
                                       "labels": {l.candidate: l.label for l in labels},
                                       "seconds": round(monotonic() - start, 1)}
        args.summary.write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
        print(root.name, dict(counts), flags, flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
