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
    ap.add_argument("--family", action="append", help="live families from config/llm.toml (default: mock fixtures)")
    ap.add_argument("--seed", type=int, default=0)
    args = ap.parse_args()
    live = bool(args.family)
    if live and args.out == Path("results/auto_vs_handwritten.md"):
        args.out = Path("results/auto_vs_handwritten_live.md")
    cfg = load_config()
    rows, differences, sets = [], 0, {}
    for name in TASKS:
        task_dir = Path("examples/tasks") / name
        task = load_pipeline_view(task_dir)
        if live:
            from vwe.llm import build_client, load_llm_settings
            settings = load_llm_settings()
            clients = [build_client(settings, f, seed=args.seed, cache_dir=args.runs_root / "cache",
                                    log_path=args.runs_root / name / "llm_log.jsonl") for f in args.family]
        else:
            clients = [LLMClient(MockProvider(fixture_dir=args.fixtures / name, family="mock_fixture"),
                                 "authored-fixture", cache_dir=args.runs_root / "cache" / name)]
        generated = generate_interpretations(task, clients, out_dir=args.runs_root / name / "interpret")
        sets[name] = generated
        for cid in sorted(task.candidates):
            hand = verify(task_dir, cid, cfg, "handwritten", runs_root=args.runs_root / "runs")
            auto = verify(task_dir, cid, cfg, "auto", runs_root=args.runs_root / "runs", generated=generated)
            h = (hand.data["decision"], hand.data["evidence_class"])
            a = (auto.data["decision"], auto.data["evidence_class"])
            differences += h != a
            rows.append((name, cid, " ".join(h), " ".join(a), "same" if h == a else "DIFFERENT"))
            print(rows[-1], flush=True)
    if live:
        header = (f"**Generator:** live models via Groq: {', '.join(args.family)} (seed {args.seed}, "
                  f"prompts v{sets[TASKS[0]].generation['prompts']['strict']['version']}). Live families "
                  f"answering: {sorted({x for s in sets.values() for x in s.generation['live_families']})}. "
                  "Each difference below is explained from the generated readings.")
    else:
        header = ("**Generator:** authored mock fixtures (`tests/fixtures/llm/auto`), *not* a live model. "
                  "The fixtures are derived from the handwritten readings, so agreement here only shows "
                  "that generation, freezing and verification preserve verdicts. It is not evidence about "
                  "model quality.")
    lines = ["# Auto versus handwritten interpretations (examples 1, 2, 4)", "", header, "",
             "| task | candidate | handwritten | auto (mock fixtures) | |", "|---|---|---|---|---|"]
    lines += [f"| {r[0]} | {r[1]} | {r[2]} | {r[3]} | {r[4]} |" for r in rows]
    lines += ["", f"Differences: {differences} of {len(rows)}."]
    if differences:
        lines.append("Each difference must be explained from the run reports before this file is cited.")
    lines += ["", "## Generated readings", ""]
    for name, g in sets.items():
        lines.append(f"### {name} (set `{g.sha256[:12]}`)")
        for m in g.members:
            clauses = "; ".join(f"`{c['zone']}` -> `{c['behaviour']}`" for c in m["clauses"])
            lines.append(f"- {m['id']}: {clauses}; ext `{m['ext']}`; reach `{m['reach']}`")
        lines += [f"- {r['family']}/{r['prompt']}: {r['status']} {r.get('detail', '')[:80]}"
                  for r in g.records if r["status"] != "ok"]
        lines.append("")
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("\n".join(lines) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
