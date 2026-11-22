"""Fail-closed classification for the prototype's SAT/Z3 obligation pairs.

This is a T05 prerequisite, not the full confirmation or property-inventory stage.
"""
from __future__ import annotations
from typing import Callable, Mapping
from .tools.cbmc import CbmcRun, PropertyResult
from .verdict import Obligation, Outcome


def classify(runs: Mapping[str, CbmcRun], selector: Callable[[PropertyResult], bool],
             name: str, *, allow_empty: bool = False,
             ignore_unselected_assertions: bool = False,
             independent_safety_refutation: bool = False) -> tuple[Obligation, Mapping[str, CbmcRun]]:
    def unknown(reason: str) -> tuple[Obligation, Mapping[str, CbmcRun]]:
        return Obligation(Outcome.INCONCLUSIVE, note=f"{name}: {reason}"), runs

    if set(runs) != {"sat", "z3"}:
        return unknown("both SAT and Z3 results are required")
    selected: dict[str, dict[str, PropertyResult]] = {}
    inventories: dict[str, dict[str, str]] = {}
    unchecked = False
    unchecked_only_selected_safety = True
    for backend, run in runs.items():
        if not run.ok:
            return unknown(f"{backend} tool error")
        if run.status not in {"success", "failure"}:
            return unknown(f"{backend} invalid overall status")
        ids = [p.property_id for p in run.properties]
        if len(set(ids)) != len(ids):
            return unknown(f"{backend} duplicate property IDs")
        unchecked |= any(p.status not in {"SUCCESS", "FAILURE"} for p in run.properties)
        for p in run.properties:
            if p.status not in {"SUCCESS", "FAILURE"}:
                unchecked_only_selected_safety &= (selector(p) and ".assertion." not in p.property_id
                                                    and p.status in {"UNKNOWN", "NOT_CHECKED"})
        if (run.status == "failure") != any(p.status == "FAILURE" for p in run.properties):
            return unknown(f"{backend} inconsistent overall/property status")
        for p in run.failed():
            if ".unwind." in p.property_id:
                return unknown("incomplete unwinding")
            if ".no-body." in p.property_id:
                return unknown("unmodeled callee (admission failure)")
            if not selector(p):
                ignorable = (ignore_unselected_assertions
                             and p.property_id.startswith("main.assertion."))
                if not ignorable:
                    return unknown(f"unselected failure {p.property_id}")
        selected[backend] = {p.property_id: p for p in run.properties if selector(p)}
        inventories[backend] = {p.property_id: p.status for p in run.properties}
        if not selected[backend] and not allow_empty:
            return unknown(f"{backend} no selected property; missing obligation")
    if inventories["sat"] != inventories["z3"]:
        return unknown("SAT/Z3 property inventory or status disagreement")
    failures = [p for p in selected["sat"].values() if p.status == "FAILURE"]
    partial_safety_failure = (independent_safety_refutation and failures
                              and unchecked_only_selected_safety
                              and all(".assertion." not in p.property_id for p in failures))
    if unchecked and not partial_safety_failure:
        return unknown("unchecked property")
    if failures:
        p = failures[0]
        return Obligation(Outcome.VIOLATED, p.witness,
                          f"{name}: {p.property_id} {p.description}"), runs
    return Obligation(Outcome.PROVED, note=name), runs
