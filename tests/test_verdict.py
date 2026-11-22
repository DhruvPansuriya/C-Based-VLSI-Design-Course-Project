"""Unit tests for the verdict rules (research draft Section 5.2)."""
from vwe.verdict import Evidence, Obligation, Outcome, decide

P, V, I = Outcome.PROVED, Outcome.VIOLATED, Outcome.INCONCLUSIVE


def ev(e0=P, e1=P, ext=True, **classes):
    return Evidence(Obligation(e0, {"x": "1"}), Obligation(e1, {"x": "2"}), ext,
                    {k: Obligation(v, {"x": k}) for k, v in classes.items()})


def test_e0_has_priority_over_everything():
    v = decide(ev(e0=V, e1=V, A=P))
    assert (v.decision, v.evidence_class) == ("REJECT", "E0")


def test_e1_reject_requires_all_ext_known():
    assert decide(ev(e1=V, A=P)).evidence_class == "E1"
    v = decide(ev(e1=V, ext=False, A=P))
    assert v.decision == "UNDECIDED" and "scope" in v.reason


def test_accept_requires_every_interpretation():
    assert decide(ev(A=P, B=P)).decision == "ACCEPT"
    assert decide(ev(A=P, B=V)).decision == "UNDECIDED"


def test_reject_e2_requires_every_interpretation_violated():
    v = decide(ev(A=V, B=V))
    assert (v.decision, v.evidence_class) == ("REJECT", "E2")


def test_inconclusive_never_upgrades():
    assert decide(ev(A=P, B=I)).decision == "UNDECIDED"
    assert decide(ev(e0=I, A=P)).decision == "UNDECIDED"
    assert decide(ev(e1=I, A=P)).decision == "UNDECIDED"


def test_no_interpretation():
    assert decide(ev()).decision == "UNDECIDED"


def test_lemma5_monotonicity_adding_interpretations_only_removes_decisions():
    # Exhaustive check over small sets: a decision with a superset implies the same decision with the subset.
    import itertools
    outs = [P, V]
    for base in itertools.product(outs, repeat=2):
        for extra in outs:
            small = decide(ev(**{f"c{i}": o for i, o in enumerate(base)}))
            big = decide(ev(**{f"c{i}": o for i, o in enumerate(base + (extra,))}))
            if big.decision != "UNDECIDED":
                assert big.decision == small.decision
