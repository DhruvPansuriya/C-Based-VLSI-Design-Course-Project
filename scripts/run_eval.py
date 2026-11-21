#!/usr/bin/env python3
"""T18: run the method and baselines on every labelled benchmark candidate, then summarise.

Method readings come from benchmarks/generated/<task>/generated_set.json (produced
by `vwe interpret ... --family openai`). Without one, the method is not run and is
recorded as UNDECIDED "no generated readings" - an honest abstention, not a guess.
Labels are read here, after all verdicts are computed, and never by the pipeline.

Outputs: results/eval/raw.jsonl, summary.md, errors.md.
"""
from __future__ import annotations

import argparse
from dataclasses import asdict
import json
from pathlib import Path
import sys
from concurrent.futures import ProcessPoolExecutor, as_completed
from time import monotonic

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from vwe.config import load_config  # noqa: E402
from vwe.eval import metrics as M  # noqa: E402
from vwe.eval.baselines import pipeline_baseline, regression_only, tests_only  # noqa: E402
from vwe.interpret import load_generated  # noqa: E402
from vwe.pipeline import verify  # noqa: E402

SYSTEMS = ("vwe", "tests_only", "single_contract", "regression_only")


def run_one(system: str, task_dir: Path, cid: str, generated, cfg, runs: Path) -> dict:
    start = monotonic()
    if system == "vwe":
        if generated is None:
            out = {"decision": "UNDECIDED", "evidence_class": "-", "claim_target": "none",
                   "reason": "no generated readings for this task"}
        else:
            data = verify(task_dir, cid, cfg, "auto", runs_root=runs / "vwe", generated=generated).data
            out = {k: data[k] for k in ("decision", "evidence_class", "claim_target", "reason")}
    elif system == "tests_only":
        v = tests_only(task_dir, cid)
        out = {"decision": v.decision, "evidence_class": "-",
               "claim_target": "repair_correctness" if v.decision != "UNDECIDED" else "none", "reason": v.reason}
    elif system == "regression_only":
        v = regression_only(task_dir, cid, generated, cfg, runs / "b4" / task_dir.name / cid)
        out = {"decision": v.decision, "evidence_class": "-",
               "claim_target": "repair_correctness" if v.decision != "UNDECIDED" else "none", "reason": v.reason}
    else:
        v = pipeline_baseline(system, task_dir, cid, generated, lambda t, c, g: verify(
            t, c, cfg, "auto", runs_root=runs / "b3", generated=g).data)
        out = {"decision": v.decision, "evidence_class": "-",
               "claim_target": "repair_correctness" if v.decision != "UNDECIDED" else "none", "reason": v.reason}
    out["seconds"] = round(monotonic() - start, 2)
    return out


def _unit(unit, config: str, runs_root: str) -> dict:
    """One (system, task, candidate) verdict; runs in a worker process."""
    system, task_dir, cid, gpath = unit
    generated = load_generated(gpath) if gpath is not None else None
    out = run_one(system, task_dir, cid, generated, load_config(config), Path(runs_root))
    return {"system": system, "task": task_dir.name, "candidate": cid, **out}


def fmt(x, digits=2):
    if x is None:
        return "-"
    if isinstance(x, tuple):
        return f"[{x[0]:.{digits}f}, {x[1]:.{digits}f}]"
    return f"{x:.{digits}f}" if isinstance(x, float) else str(x)


def write_reports(rows: list[M.Row], reasons: dict, bug_type: dict, out: Path, notes: list[str]) -> None:
    systems = sorted({r.system for r in rows}, key=lambda s: SYSTEMS.index(s) if s in SYSTEMS else 99)
    lines = ["# Evaluation summary", "", *notes, "",
             "| system | labelled | decided | coverage | ACCEPT prec. (Wilson) | REJECT prec. (Wilson) | wrong | unknown labels |",
             "|---|---|---|---|---|---|---|---|"]
    for s in systems:
        sub = [r for r in rows if r.system == s]
        m = M.summary(sub)
        lines.append(f"| {s} | {m['labelled']} | {m['decided']} | {fmt(m['coverage'])} | "
                     f"{fmt(m['accept_precision'])} {fmt(m['accept_wilson'])} n={m['accept']} | "
                     f"{fmt(m['reject_precision'])} {fmt(m['reject_wilson'])} n={m['reject']} | "
                     f"{m['wrong']} | {m['unknown_labels']} |")
    lines += ["", "Wilson intervals treat candidates as independent and are shown for reference only. "
              "Task-clustered bootstrap intervals (resampling tasks):", ""]
    for s in systems:
        sub = [r for r in rows if r.system == s]
        lines.append(f"- {s}: coverage {fmt(M.cluster_bootstrap(sub, 'coverage'))}, REJECT precision "
                     f"{fmt(M.cluster_bootstrap(sub, 'reject_precision'))}, ACCEPT precision "
                     f"{fmt(M.cluster_bootstrap(sub, 'accept_precision'))}")
    vwe_rows = [r for r in rows if r.system == "vwe"]
    lines += ["", "## Predeclared selection policies (method)", "",
              "Evidence classes are not calibrated probabilities; each policy keeps only decisions of the "
              "listed classes.", "", "| policy | decided | coverage | ACCEPT prec. | REJECT prec. | wrong |",
              "|---|---|---|---|---|---|"]
    for name, classes in M.POLICIES.items():
        m = M.summary(vwe_rows, policy=classes)
        lines.append(f"| {name} | {m['decided']} | {fmt(m['coverage'])} | {fmt(m['accept_precision'])} | "
                     f"{fmt(m['reject_precision'])} | {m['wrong']} |")
    lines += ["", "## Paired task-level comparison (method vs baseline)", "",
              "| baseline | tasks | method better | baseline better | ties | net right decisions | sign-test p |",
              "|---|---|---|---|---|---|---|"]
    for s in systems:
        if s == "vwe":
            continue
        p = M.paired_by_task(vwe_rows, [r for r in rows if r.system == s])
        lines.append(f"| {s} | {p['tasks_compared']} | {p['wins']} | {p['losses']} | {p['ties']} | "
                     f"{p['net_right_decisions']} | {fmt(p['sign_test_p'], 3)} |")
    lines += ["", "## Breakdown by bug type (method)", "", "| bug type | labelled | decided | wrong |", "|---|---|---|---|"]
    for k, m in M.breakdown(vwe_rows, bug_type).items():
        lines.append(f"| {k} | {m['labelled']} | {m['decided']} | {m['wrong']} |")
    lines += ["", "## Abstention reasons (method)", ""]
    counts: dict[str, int] = {}
    for r in vwe_rows:
        if r.decision == "UNDECIDED":
            key = reasons[(r.system, r.task, r.candidate)][:80]
            counts[key] = counts.get(key, 0) + 1
    lines += [f"- {n} x {k}" for k, n in sorted(counts.items(), key=lambda x: -x[1])]
    (out / "summary.md").write_text("\n".join(lines) + "\n")
    errs = ["# Wrong decisions (audit)", "",
            "Every ACCEPT of an incorrect candidate or REJECT of a correct one, per system. Each must be "
            "explained (bad label, reading miss, or tool/implementation bug). Wrong E0/E1 verdicts of the "
            "method are claimed impossible and fail the run.", ""]
    for r in rows:
        if M.is_wrong(r):
            errs.append(f"- **{r.system}** {r.task}/{r.candidate}: {r.decision} {r.evidence} vs label "
                        f"{r.label} - {reasons[(r.system, r.task, r.candidate)][:160]}")
    if len(errs) == 5:
        errs.append("None.")
    (out / "errors.md").write_text("\n".join(errs) + "\n")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tasks", type=Path, default=ROOT / "benchmarks/tasks")
    ap.add_argument("--generated", type=Path, default=ROOT / "benchmarks/generated")
    ap.add_argument("--systems", nargs="+", default=list(SYSTEMS), choices=SYSTEMS)
    ap.add_argument("--config", type=Path, default=ROOT / "config/benchmark.toml")
    ap.add_argument("--out", type=Path, default=ROOT / "results/eval")
    ap.add_argument("--runs-root", type=Path, default=ROOT / "runs/eval")
    ap.add_argument("--jobs", type=int, default=1, help="parallel (system, candidate) units")
    ap.add_argument("--resume", action="store_true", help="reuse verdict rows already in verdicts.jsonl")
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    log = json.loads((ROOT / "benchmarks/adaptation_log.json").read_text())
    bug_type = {r["task_id"]: r["type"] for r in log["selected"]}
    raw_rows, reasons, rows = [], {}, []
    task_dirs = sorted(p for p in args.tasks.iterdir() if (p / "eval/labels.json").is_file())
    units, with_readings = [], 0
    for task_dir in task_dirs:
        gpath = args.generated / task_dir.name / "generated_set.json"
        with_readings += gpath.is_file()
        manifest = json.loads((task_dir / "task.json").read_text())
        units += [(system, task_dir, cid, gpath if gpath.is_file() else None)
                  for cid in sorted(manifest["candidates"]) for system in args.systems]
    verdict_log = args.out / "verdicts.jsonl"  # verdicts only, written before any label is read
    done = {}
    if args.resume and verdict_log.is_file():
        for line in verdict_log.read_text().splitlines():
            r = json.loads(line)
            done[(r["system"], r["task"], r["candidate"])] = r
    elif verdict_log.exists():
        verdict_log.unlink()
    todo = [u for u in units if (u[0], u[1].name, u[2]) not in done]
    with ProcessPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        futures = {pool.submit(_unit, u, str(args.config), str(args.runs_root)): u for u in todo}
        for future in as_completed(futures):
            row = future.result()
            done[(row["system"], row["task"], row["candidate"])] = row
            with verdict_log.open("a") as stream:
                stream.write(json.dumps(row) + "\n")
            print(row["system"], row["task"], row["candidate"], row["decision"], row["reason"][:60], flush=True)
    raw_rows = [done[(u[0], u[1].name, u[2])] for u in units]
    # Labels are joined only after every verdict above has been computed.
    labels = {t.name: {l["candidate"]: l["label"] for l in json.loads((t / "eval/labels.json").read_text())}
              for t in task_dirs}
    with (args.out / "raw.jsonl").open("w") as stream:
        for r in raw_rows:
            label = labels[r["task"]].get(r["candidate"], "unknown")
            stream.write(json.dumps({**r, "label": label}) + "\n")
            rows.append(M.Row(r["system"], r["task"], r["candidate"], r["decision"], r["evidence_class"],
                              r["claim_target"], label, r["seconds"]))
            reasons[(r["system"], r["task"], r["candidate"])] = r["reason"]
    notes = [f"{len(task_dirs)} labelled tasks; {with_readings} have generated readings for the method.",
             "Labels: `vwe/eval/labels.py` (formal identity vs P_ref + native differential testing).",
             "Benchmark requests are fixed templates, not human-authored; see docs/T15_BENCHMARKS.md."]
    if not with_readings:
        notes.append("**No task has generated readings (no live LLM output), so the method abstains on "
                     "every candidate. This table measures that abstention, not the method's precision.**")
    write_reports(rows, reasons, bug_type, args.out, notes)
    core = M.unsound_core([r for r in rows if r.system == "vwe"])
    print((args.out / "summary.md").read_text())
    if core:
        print(f"UNSOUND E0/E1 DECISIONS: {[(r.task, r.candidate) for r in core]}")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
