#!/usr/bin/env python3
"""Generate interpretation sets for benchmark tasks with a configured LLM family.

Inputs per task: P0 signature, request text and caller profile only (RequestContext).
Budget: stops after --max-tasks tasks or as soon as a family reports unavailable
(e.g. no API credit), so a misconfiguration costs at most one failed call.
Writes benchmarks/generated/<task>/{generated_set.json, interpretations.md, llm_log.jsonl}.
"""
from __future__ import annotations

import argparse
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
from vwe.interpret import generate_interpretations  # noqa: E402
from vwe.llm import ContextError, build_client, load_llm_settings  # noqa: E402
from vwe.tasks import load_pipeline_view  # noqa: E402


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--family", action="append", required=True)
    ap.add_argument("--tasks", type=Path, default=ROOT / "benchmarks/tasks")
    ap.add_argument("--out", type=Path, default=ROOT / "benchmarks/generated")
    ap.add_argument("--max-tasks", type=int, default=100)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--cache-dir", type=Path, default=Path("~/.cache/vwe/llm").expanduser())
    args = ap.parse_args()
    settings = load_llm_settings()
    roots = sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file())[: args.max_tasks]
    for root in roots:
        out = args.out / root.name
        if (out / "generated_set.json").is_file():
            print(f"{root.name}: already generated", flush=True)
            continue
        clients = [build_client(settings, f, cache_dir=args.cache_dir, seed=args.seed,
                                log_path=out / "llm_log.jsonl") for f in args.family]
        try:
            result = generate_interpretations(load_pipeline_view(root), clients, out_dir=out)
        except ContextError as exc:  # recorded and skipped; the method will abstain on this task
            out.mkdir(parents=True, exist_ok=True)
            (out / "skipped.txt").write_text(f"no context: {exc}\n")
            print(f"{root.name}: skipped ({exc})", flush=True)
            continue
        statuses = [r["status"] for r in result.records]
        print(f"{root.name}: {len(result.members)} readings; live={result.generation['live_families']}; "
              f"{statuses}", flush=True)
        if "unavailable" in statuses or any("insufficient_quota" in r.get("detail", "") for r in result.records):
            print("stopping: provider unavailable or out of credit", file=sys.stderr)
            return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
