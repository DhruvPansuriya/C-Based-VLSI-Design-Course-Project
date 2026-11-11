#!/usr/bin/env python3
"""Run T17 baselines and append results/eval/baselines/<name>.jsonl (one line per task x candidate)."""
from __future__ import annotations

import argparse
from dataclasses import asdict
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.config import load_config  # noqa: E402
from vwe.eval.baselines import B2_STATUS, NAMES, pipeline_baseline, regression_only, tests_only  # noqa: E402
from vwe.interpret import load_generated  # noqa: E402
from vwe.pipeline import verify  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("name", choices=(*NAMES, "llm_judge"))
    ap.add_argument("task_dir", type=Path, nargs="+")
    ap.add_argument("--candidate", action="append")
    ap.add_argument("--generated", type=Path, help="generated_set.json (B3/B4); per-task path if one task")
    ap.add_argument("--config", type=Path, default=Path("config/benchmark.toml"))
    ap.add_argument("--out-dir", type=Path, default=Path("results/eval/baselines"))
    ap.add_argument("--runs-root", type=Path, default=Path("runs/baselines"))
    args = ap.parse_args()
    if args.name == "llm_judge":
        print(f"llm_judge: {B2_STATUS}", file=sys.stderr)
        return 2
    cfg = load_config(args.config)
    args.out_dir.mkdir(parents=True, exist_ok=True)
    out = args.out_dir / f"{args.name}.jsonl"
    for task_dir in args.task_dir:
        manifest = json.loads((task_dir / "task.json").read_text())
        generated = load_generated(args.generated) if args.generated else None
        for cid in args.candidate or sorted(manifest["candidates"]):
            if args.name == "tests_only":
                result = tests_only(task_dir, cid)
            elif args.name == "regression_only":
                result = regression_only(task_dir, cid, generated, cfg,
                                         args.runs_root / manifest["task_id"] / cid)
            else:
                result = pipeline_baseline(args.name, task_dir, cid, generated, lambda t, c, g: verify(
                    t, c, cfg, "auto", runs_root=args.runs_root, generated=g).data)
            with out.open("a") as stream:
                stream.write(json.dumps(asdict(result)) + "\n")
            print(f"{result.task_id} {cid} {result.decision} {result.reason[:80]}", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
