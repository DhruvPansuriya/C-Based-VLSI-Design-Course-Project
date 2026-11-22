#!/usr/bin/env python3
"""Compare handwritten and generated-interpretation verdicts (T13).

With --fixtures the "generator" is the authored mock fixture set, so agreement
shows only that the plumbing preserves verdicts. It says nothing about live models.
"""
from __future__ import annotations

import argparse
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from vwe.config import load_config  # noqa: E402
from vwe.interpret import generate_interpretations  # noqa: E402
from vwe.llm import LLMClient, MockProvider  # noqa: E402
from vwe.pipeline import verify  # noqa: E402
from vwe.tasks import load_pipeline_view  # noqa: E402

TASKS = ("ex1_saturate", "ex2_argmax", "ex4_sum")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--fixtures", type=Path, default=Path("tests/fixtures/llm/auto"))
    ap.add_argument("--out", type=Path, default=Path("results/auto_vs_handwritten.md"))
    ap.add_argument("--runs-root", type=Path, default=Path("runs/auto-compare"))
    args = ap.parse_args()
    cfg = load_config()
    rows, differences = [], 0
    for name in TASKS:
        task_dir = Path("examples/tasks") / name
        task = load_pipeline_view(task_dir)
        client = LLMClient(MockProvider(fixture_dir=args.fixtures / name, family="mock_fixture"),
                           "authored-fixture", cache_dir=args.runs_root / "cache" / name)
        generated = generate_interpretations(task, [client], out_dir=args.runs_root / name / "interpret")
        for cid in sorted(task.candidates):
            hand = verify(task_dir, cid, cfg, "handwritten", runs_root=args.runs_root / "runs")
            auto = verify(task_dir, cid, cfg, "auto", runs_root=args.runs_root / "runs", generated=generated)
            h = (hand.data["decision"], hand.data["evidence_class"])
            a = (auto.data["decision"], auto.data["evidence_class"])
            differences += h != a
            rows.append((name, cid, " ".join(h), " ".join(a), "same" if h == a else "DIFFERENT"))
            print(rows[-1], flush=True)
    lines = ["# Auto versus handwritten interpretations (examples 1, 2, 4)", "",
             "**Generator:** authored mock fixtures (`tests/fixtures/llm/auto`), *not* a live model. "
             "The fixtures are derived from the handwritten readings, so agreement here only shows "
             "that generation, freezing and verification preserve verdicts. It is not evidence about "
             "model quality. No live provider was configured.", "",
             "| task | candidate | handwritten | auto (mock fixtures) | |", "|---|---|---|---|---|"]
    lines += [f"| {r[0]} | {r[1]} | {r[2]} | {r[3]} | {r[4]} |" for r in rows]
    lines += ["", f"Differences: {differences} of {len(rows)}."]
    if differences:
        lines.append("Each difference must be explained from the run reports before this file is cited.")
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("\n".join(lines) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
