#!/usr/bin/env python3
"""EVAL-P3: run VWE on the adapted Project 3 tasks and compare with their labels and checker.

VWE runs in handwritten mode with the single computed T5 preservation reading. Labels
(eval/project3.json) are joined only after every verdict is computed.
Writes results/eval_project3/{raw.jsonl, summary.md}.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import sys
from concurrent.futures import ProcessPoolExecutor, as_completed
from time import monotonic

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
from vwe.config import load_config  # noqa: E402
from vwe.eval.metrics import wilson  # noqa: E402
from vwe.pipeline import verify  # noqa: E402

EXPECT = {"equivalent": "ACCEPT", "not_equivalent": "REJECT", "candidate_undefined": "REJECT"}


def outcome_class(decision: str, label: str) -> str:
    if decision == "UNDECIDED":
        return "abstained"
    return "agree" if EXPECT[label] == decision else "DISAGREE"


def fmt(x):
    return "-" if x is None else (f"[{x[0]:.2f}, {x[1]:.2f}]" if isinstance(x, tuple) else f"{x:.2f}")


def summarise(rows: list[dict], out: Path, config: str) -> None:
    lines = ["# EVAL-P3: VWE on the Project 3 team benchmarks", "",
             "Separate evaluation with a different approach: their tool checks C-to-C equivalence of "
             "LLM-optimised HLS kernels; VWE treats each as a T5 request (\"optimise without changing "
             "behaviour\") with one computed preservation reading and no LLM. Labels and their checker "
             "outcomes come from their handoff (`eval/project3.json`), joined after all verdicts.", "",
             f"Profile `{config}` (K=32, max_unwind=40, 120 s solver timeouts); local CBMC/Z3 on this laptop. "
             "`#include <stdint.h>` was replaced by explicit typedefs (recorded per task).", ""]
    by = defaultdict(list)
    for r in rows:
        by[(r["cohort"], r["label"])].append(r)
    lines += ["| cohort | their label | n | VWE ACCEPT | VWE REJECT | VWE UNDECIDED | agree | disagree | their checker agrees with label |",
              "|---|---|---|---|---|---|---|---|---|"]
    for (cohort, label), rs in sorted(by.items()):
        d = Counter(r["decision"] for r in rs)
        c = Counter(r["class"] for r in rs)
        theirs = sum(r["their_outcome"] == r["label"] for r in rs)
        lines.append(f"| {cohort} | {label} | {len(rs)} | {d['ACCEPT']} | {d['REJECT']} | {d['UNDECIDED']} | "
                     f"{c['agree']} | {c['DISAGREE']} | {theirs}/{len(rs)} |")
    decided = [r for r in rows if r["decision"] != "UNDECIDED"]
    agree = sum(r["class"] == "agree" for r in decided)
    lines += ["", f"**Overall:** {len(rows)} candidates, {len(decided)} decided "
              f"(coverage {len(decided) / len(rows):.2f}), {agree} agree with the label, "
              f"{len(decided) - agree} disagree. Agreement among decided: "
              f"{agree / len(decided) if decided else 0:.3f} (Wilson {fmt(wilson(agree, len(decided)))}; "
              "candidates within a kernel family are not independent, so treat the interval as indicative).",
              "", "Evidence classes of VWE decisions: " +
              ", ".join(f"{k}={v}" for k, v in sorted(Counter(r["evidence_class"] for r in decided).items())),
              "", f"Mean seconds per verdict: {sum(r['seconds'] for r in rows) / len(rows):.1f}", "",
              "## Disagreements (each must be explained)", ""]
    bad = [r for r in rows if r["class"] == "DISAGREE"]
    lines += [f"- {r['task']}/{r['candidate']}: VWE {r['decision']} {r['evidence_class']} vs label {r['label']} "
              f"(their checker: {r['their_outcome']}) - {r['reason'][:140]}" for r in bad] or ["None."]
    lines += ["", "## Abstentions (VWE UNDECIDED)", ""]
    reasons = Counter(r["reason"][:90] for r in rows if r["decision"] == "UNDECIDED")
    lines += [f"- {n} x {k}" for k, n in reasons.most_common()] or ["None."]
    (out / "summary.md").write_text("\n".join(lines) + "\n")


def _one(task_dir: Path, cid: str, config: str, runs_root: str) -> dict:
    start = monotonic()
    data = verify(task_dir, cid, load_config(config), "handwritten", runs_root=Path(runs_root)).data
    return {"task": task_dir.name, "candidate": cid, "decision": data["decision"],
            "evidence_class": data["evidence_class"], "reason": data["reason"],
            "seconds": round(monotonic() - start, 1)}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tasks", type=Path, default=ROOT / "benchmarks/project3/tasks")
    ap.add_argument("--config", type=Path, default=ROOT / "config/project3.toml")
    ap.add_argument("--out", type=Path, default=ROOT / "results/eval_project3")
    ap.add_argument("--runs-root", type=Path, default=ROOT / "runs/eval_project3")
    ap.add_argument("--resume", action="store_true", help="reuse rows already in raw.jsonl")
    ap.add_argument("--jobs", type=int, default=1)
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    raw_path = args.out / "raw.jsonl"
    done = {}
    if args.resume and raw_path.is_file():
        for line in raw_path.read_text().splitlines():
            r = json.loads(line)
            done[(r["task"], r["candidate"])] = r
    units = [(task_dir, cid) for task_dir in sorted(p for p in args.tasks.iterdir() if (p / "task.json").is_file())
             for cid in sorted(json.loads((task_dir / "task.json").read_text())["candidates"])]
    todo = [u for u in units if (u[0].name, u[1]) not in done]
    with ProcessPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        futures = [pool.submit(_one, task_dir, cid, str(args.config), str(args.runs_root)) for task_dir, cid in todo]
        for future in as_completed(futures):
            v = future.result()
            done[(v["task"], v["candidate"])] = v
            with raw_path.open("a") as stream:  # verdict only; labels are joined below
                stream.write(json.dumps(v) + "\n")
            print(v["task"], v["candidate"], v["decision"], v["evidence_class"], v["seconds"], flush=True)
    verdicts = [done[(t.name, c)] for t, c in units]
    rows = []
    for v in verdicts:
        ev = json.loads((args.tasks / v["task"] / "eval/project3.json").read_text())
        label = ev["labels"][v["candidate"]]
        rows.append({**v, "cohort": ev["cohort"], "label": label,
                     "their_outcome": ev["their_outcome"][v["candidate"]],
                     "class": outcome_class(v["decision"], label)})
    (args.out / "joined.jsonl").write_text("".join(json.dumps(r) + "\n" for r in rows))
    summarise(rows, args.out, args.config.name)
    print((args.out / "summary.md").read_text())
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
