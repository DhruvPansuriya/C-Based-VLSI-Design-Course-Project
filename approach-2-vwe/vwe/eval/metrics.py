"""Evaluation metrics (T18) as pure functions.

Corrections from docs/engineering/IMPORT_REVIEW.md: candidates of one task are not
independent, so intervals for headline rates are task-clustered bootstraps and
baseline comparisons are paired at task level (no per-candidate McNemar). Evidence
classes are not calibrated confidences: they define predeclared selection
policies, not a probability-ordered risk-coverage curve. Admission-policy
refusals are counted apart from semantic errors. Unknown labels are excluded
from rates and reported.
"""
from __future__ import annotations

from collections import defaultdict
from dataclasses import dataclass
from math import comb, sqrt
import random
from typing import Iterable, Mapping, Sequence

POLICIES = {"E0 only": {"E0"}, "E0+E1": {"E0", "E1"}, "all classes": {"E0", "E1", "E2"}}


@dataclass(frozen=True)
class Row:
    system: str
    task: str
    candidate: str
    decision: str            # ACCEPT | REJECT | UNDECIDED
    evidence: str            # E0 | E1 | E2 | - (baselines: "-")
    claim: str               # repair_correctness | admission_policy | build_view_consistency | none
    label: str               # correct | incorrect | unknown
    seconds: float = 0.0


def wilson(successes: int, n: int, z: float = 1.959963984540054) -> tuple[float, float] | None:
    if n == 0:
        return None
    p = successes / n
    centre = p + z * z / (2 * n)
    half = z * sqrt(p * (1 - p) / n + z * z / (4 * n * n))
    return ((centre - half) / (1 + z * z / n), (centre + half) / (1 + z * z / n))


def sign_test(wins: int, losses: int) -> float | None:
    """Exact two-sided binomial sign test over tasks (ties excluded)."""
    n = wins + losses
    if n == 0:
        return None
    k = min(wins, losses)
    tail = sum(comb(n, i) for i in range(k + 1)) / 2 ** n
    return min(1.0, 2 * tail)


def is_wrong(r: Row) -> bool:
    return r.claim == "repair_correctness" and (
        (r.decision == "ACCEPT" and r.label == "incorrect") or (r.decision == "REJECT" and r.label == "correct"))


def is_right(r: Row) -> bool:
    return r.claim == "repair_correctness" and (
        (r.decision == "ACCEPT" and r.label == "correct") or (r.decision == "REJECT" and r.label == "incorrect"))


def _labelled(rows: Iterable[Row]) -> list[Row]:
    return [r for r in rows if r.label in ("correct", "incorrect")]


def summary(rows: Sequence[Row], *, policy: set[str] | None = None) -> dict:
    """Counts and rates over labelled candidates. Policy filters semantic decisions by class."""
    lab = _labelled(rows)
    semantic = [r for r in lab if r.claim == "repair_correctness" and r.decision != "UNDECIDED"
                and (policy is None or r.evidence in policy or r.evidence == "-")]
    accepts = [r for r in semantic if r.decision == "ACCEPT"]
    rejects = [r for r in semantic if r.decision == "REJECT"]
    acc_ok = sum(r.label == "correct" for r in accepts)
    rej_ok = sum(r.label == "incorrect" for r in rejects)
    return {
        "candidates": len(rows), "labelled": len(lab), "unknown_labels": len(rows) - len(lab),
        "decided": len(semantic), "coverage": len(semantic) / len(lab) if lab else None,
        "policy_refusals": sum(r.claim == "admission_policy" for r in lab),
        "accept": len(accepts), "accept_correct": acc_ok,
        "accept_precision": acc_ok / len(accepts) if accepts else None,
        "accept_wilson": wilson(acc_ok, len(accepts)),
        "reject": len(rejects), "reject_correct": rej_ok,
        "reject_precision": rej_ok / len(rejects) if rejects else None,
        "reject_wilson": wilson(rej_ok, len(rejects)),
        "wrong": sum(is_wrong(r) for r in semantic),
        "tasks": len({r.task for r in rows}),
        "mean_seconds": sum(r.seconds for r in rows) / len(rows) if rows else None,
    }


def cluster_bootstrap(rows: Sequence[Row], stat: str, *, resamples: int = 2000, seed: int = 0,
                      policy: set[str] | None = None) -> tuple[float, float] | None:
    """95 % percentile interval resampling whole tasks (deterministic seed)."""
    by_task: dict[str, list[Row]] = defaultdict(list)
    for r in rows:
        by_task[r.task].append(r)
    tasks = sorted(by_task)
    if len(tasks) < 2:
        return None
    rng, values = random.Random(seed), []
    for _ in range(resamples):
        sample = [r for t in (rng.choice(tasks) for _ in tasks) for r in by_task[t]]
        v = summary(sample, policy=policy)[stat]
        if v is not None:
            values.append(v)
    if len(values) < resamples // 2:
        return None
    values.sort()
    return values[int(0.025 * len(values))], values[min(len(values) - 1, int(0.975 * len(values)))]


def paired_by_task(a: Sequence[Row], b: Sequence[Row]) -> dict:
    """Task-level paired comparison of right-decision counts (same labelled candidates)."""
    key = lambda r: (r.task, r.candidate)
    bmap = {key(r): r for r in _labelled(b)}
    per_task: dict[str, int] = defaultdict(int)
    wrong_task: dict[str, int] = defaultdict(int)
    for r in _labelled(a):
        other = bmap.get(key(r))
        if other is not None:
            per_task[r.task] += int(is_right(r)) - int(is_right(other))
            wrong_task[r.task] += int(is_wrong(r)) - int(is_wrong(other))
    wins = sum(d > 0 for d in per_task.values())
    losses = sum(d < 0 for d in per_task.values())
    fewer = sum(d < 0 for d in wrong_task.values())
    more = sum(d > 0 for d in wrong_task.values())
    return {"tasks_compared": len(per_task), "wins": wins, "losses": losses,
            "ties": len(per_task) - wins - losses, "sign_test_p": sign_test(wins, losses),
            "net_right_decisions": sum(per_task.values()),
            "net_wrong_decisions": sum(wrong_task.values()),
            "tasks_fewer_wrong": fewer, "tasks_more_wrong": more,
            "wrong_sign_test_p": sign_test(fewer, more)}


def breakdown(rows: Sequence[Row], attribute: Mapping[str, str]) -> dict[str, dict]:
    """Summaries grouped by a task attribute (e.g. bug type)."""
    groups: dict[str, list[Row]] = defaultdict(list)
    for r in rows:
        groups[attribute.get(r.task, "?")].append(r)
    return {k: summary(v) for k, v in sorted(groups.items())}


def unsound_core(rows: Sequence[Row]) -> list[Row]:
    """Wrong E0/E1 verdicts: these classes are claimed sound, so each one is a bug."""
    return [r for r in rows if is_wrong(r) and r.evidence in ("E0", "E1")]
