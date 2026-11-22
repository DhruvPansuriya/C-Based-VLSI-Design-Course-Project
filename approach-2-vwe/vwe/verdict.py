"""Verdict rules (research draft, Section 5.2), as a pure, unit-tested function.

Inputs are already-computed obligation outcomes; this module never runs a tool.
Order of rules: E0 reject -> E1 reject -> ACCEPT (E2) -> REJECT (E2) -> UNDECIDED.
Any inconclusive or unconfirmed outcome that the deciding rule depends on yields UNDECIDED.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
from typing import Dict, List, Optional


class Outcome(str, Enum):
    PROVED = "PROVED"            # obligation holds within complete scope, vacuity probes OK
    VIOLATED = "VIOLATED"        # confirmed witness
    INCONCLUSIVE = "INCONCLUSIVE"  # timeout, incomplete bound, unconfirmed, tool disagreement


@dataclass
class Obligation:
    outcome: Outcome
    witness: Optional[Dict[str, str]] = None
    note: str = ""


@dataclass
class Evidence:
    """All outcomes for one (P0, N, P1) triple."""
    e0_core: Obligation                      # new UB / nondeterminism / build-view mismatch / forbidden construct
    e1_core: Obligation                      # regression outside B_max rejected by every known Ext
    ext_all_known: bool                      # False if some interpretation has Ext = unknown
    per_class: Dict[str, Obligation] = field(default_factory=dict)  # Sat(P1, I_k) per equivalence class


@dataclass
class Verdict:
    decision: str        # ACCEPT | REJECT | UNDECIDED
    evidence_class: str  # E0 | E1 | E2 | -
    reason: str
    witness: Optional[Dict[str, str]] = None
    claim_target: str = "repair_correctness"


def admission_verdict(status: str, reason: str) -> Optional[Verdict]:
    """Structural refusal is policy evidence, not semantic RC refutation."""
    if status == "ok":
        return None
    if status == "refused":
        return Verdict("REJECT", "E0", reason, claim_target="admission_policy")
    if status in {"unsupported", "interface_change", "inconclusive"}:
        return Verdict("UNDECIDED", "-", reason, claim_target="none")
    raise ValueError(f"Unknown admission status: {status}")


def decide(ev: Evidence) -> Verdict:
    if ev.e0_core.outcome is Outcome.VIOLATED:
        return Verdict("REJECT", "E0", "computed fact: " + (ev.e0_core.note or "new UB/nondeterminism/view mismatch"),
                       ev.e0_core.witness)
    if ev.e0_core.outcome is Outcome.INCONCLUSIVE:
        return Verdict("UNDECIDED", "-", "inconclusive: E0 core")
    if ev.e1_core.outcome is Outcome.VIOLATED:
        if ev.ext_all_known:
            return Verdict("REJECT", "E1", "regression outside B_max rejected by every Ext", ev.e1_core.witness)
        return Verdict("UNDECIDED", "-", "scope disagreement: some Ext unknown", ev.e1_core.witness)
    if ev.e1_core.outcome is Outcome.INCONCLUSIVE:
        return Verdict("UNDECIDED", "-", "inconclusive: E1 core")
    if not ev.per_class:
        return Verdict("UNDECIDED", "-", "no interpretation survived")
    outs = [o.outcome for o in ev.per_class.values()]
    if any(o is Outcome.INCONCLUSIVE for o in outs):
        return Verdict("UNDECIDED", "-", "inconclusive: per-interpretation check")
    if all(o is Outcome.PROVED for o in outs):
        return Verdict("ACCEPT", "E2", "satisfies every interpretation")
    if all(o is Outcome.VIOLATED for o in outs):
        w = next(iter(ev.per_class.values())).witness
        return Verdict("REJECT", "E2", "violates every interpretation", w)
    dis = next(o.witness for o in ev.per_class.values() if o.outcome is Outcome.VIOLATED)
    return Verdict("UNDECIDED", "-", "ambiguous: interpretations disagree", dis)
