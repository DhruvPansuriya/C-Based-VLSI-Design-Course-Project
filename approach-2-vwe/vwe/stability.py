"""Repetition, union over runs and verdict-stability measurements (T14).

Union semantics (draft consequence C2): more readings can only make a verdict
more conservative *when the candidate-side E0/E1 outcomes and the keep region are
unchanged and the base set is non-empty*. Adding readings can enlarge B_max, which
can change an E1 outcome, so the pipeline-level comparison is measured and flagged
rather than assumed (see `conservative_step`).
"""
from __future__ import annotations

from collections import Counter
from typing import Any, Callable, Iterable, Mapping, Sequence

from .interpret import GeneratedSet
from .validate import canonical

Decision = tuple[str, str]  # (decision, evidence class)
VerifyFn = Callable[[str, GeneratedSet], Decision]


def semantic_key(reading: Mapping[str, Any]) -> bytes:
    """Identity of a reading's meaning: ignores id, provenance and English text."""
    keep = {k: reading.get(k) for k in ("shape", "clauses", "ext", "reach")}
    return canonical(keep)


def _generation(base: Mapping[str, Any], runs: int, families: Iterable[str]) -> dict[str, Any]:
    out = dict(base)
    out["runs"] = runs
    out["families"] = sorted(set(families))
    return out


def select_runs(generated: GeneratedSet, runs: Iterable[int]) -> GeneratedSet:
    wanted = set(runs)
    members = tuple(m for m in generated.members if m["provenance"].get("run_index") in wanted)
    records = tuple(r for r in generated.records if r.get("run_index", 0) in wanted or r["prompt"] in {"typing", "shape"})
    return GeneratedSet(generated.task_id, generated.request_id, members,
                        _generation(generated.generation, len(wanted), generated.generation["families"]),
                        records)


def union(sets: Sequence[GeneratedSet]) -> GeneratedSet:
    """Union of generation runs; semantically identical readings are merged (first id kept)."""
    if not sets or len({(s.task_id, s.request_id) for s in sets}) != 1:
        raise ValueError("union needs sets for one task and request")
    seen: dict[bytes, str] = {}
    members: list[Mapping[str, Any]] = []
    for s in sets:
        for m in s.members:
            key = semantic_key(m)
            if key not in seen:
                seen[key] = m["id"]
                members.append(m)
    ids = {m["id"] for m in members}
    if len(ids) != len(members):
        raise ValueError("interpretation ids are not unique across the union")
    first = sets[0]
    families = [f for s in sets for f in s.generation["families"]]
    gen = _generation(first.generation, sum(int(s.generation["runs"]) for s in sets), families)
    return GeneratedSet(first.task_id, first.request_id, tuple(members), gen,
                        tuple(r for s in sets for r in s.records))


def conservative_step(before: Decision, after: Decision) -> bool:
    """Is `after` a valid consequence of enlarging the set (same decision or UNDECIDED)?"""
    return after == before or after[0] == "UNDECIDED"


def stability_report(task_id: str, generated: GeneratedSet, candidates: Sequence[str],
                     verify_fn: VerifyFn) -> dict[str, Any]:
    run_ids = sorted({m["provenance"]["run_index"] for m in generated.members})
    if len(run_ids) < 1:
        raise ValueError("no generated readings to measure")
    singles = {k: select_runs(generated, [k]) for k in run_ids}
    prefixes = [union([singles[k] for k in run_ids[: j + 1]]) for j in range(len(run_ids))]
    per_candidate: dict[str, Any] = {}
    for cid in candidates:
        single = [verify_fn(cid, singles[k]) for k in run_ids]
        cumulative = [single[0]] + [verify_fn(cid, prefixes[j]) for j in range(1, len(run_ids))]
        modal = Counter(single).most_common(1)[0][1]
        steps = [{"runs": j + 1, "decision": " ".join(cumulative[j]),
                  "conservative_step": conservative_step(cumulative[j - 1], cumulative[j])}
                 for j in range(1, len(cumulative))]
        per_candidate[cid] = {"single_runs": [" ".join(d) for d in single],
                              "agreement": modal / len(single),
                              "cumulative": [" ".join(d) for d in cumulative], "steps": steps}
    coverage = [sum(1 for c in per_candidate.values() if not c["cumulative"][j].startswith("UNDECIDED"))
                / len(candidates) for j in range(len(run_ids))] if candidates else []
    return {"task_id": task_id, "runs": len(run_ids), "candidates": per_candidate,
            "coverage_by_union_size": coverage,
            "distinct_readings_by_union_size": [len(p.members) for p in prefixes],
            "mean_agreement": (sum(c["agreement"] for c in per_candidate.values()) / len(per_candidate)
                               if per_candidate else None),
            "nonconservative_steps": [(cid, s["runs"]) for cid, c in per_candidate.items()
                                      for s in c["steps"] if not s["conservative_step"]],
            "note": ("Union monotonicity holds only with E0/E1 facts fixed; a flagged step means the "
                     "premise changed (for example B_max grew) or a defect, and needs explanation. "
                     "Seeds are request parameters; provider determinism is not assumed.")}
