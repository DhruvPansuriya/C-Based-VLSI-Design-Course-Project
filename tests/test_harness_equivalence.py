"""Compare generated bounded jobs with the handwritten spike verdicts."""
import json

import pytest

from vwe.harness.profile import plain
from vwe.obligations import classify
from vwe.verdict import Evidence, Outcome, decide

from .test_harness_generator import ROOT, REAL, example, solve

EXPECTED = json.loads((ROOT / "tests/golden/expected.json").read_text())
CASES = [(name, int(i), want) for name, variants in EXPECTED.items()
         if not name.startswith("_") for i, want in variants.items()]


def paired(bundle, selector, **options):
    runs = {backend: solve(bundle, backend) for backend in ("sat", "z3")}
    return classify(runs, selector, bundle.kind, **options)[0]


@REAL
@pytest.mark.parametrize(("name", "variant", "want"), CASES)
def test_generated_verdict_matches_handwritten_golden(name, variant, want, tmp_path):
    task, gen = example(name, variant, tmp_path)
    interps = tuple(it for it in task.interpretations if plain(it["shape"]) == plain(task.caller_domain))
    ref = paired(gen.gen_reference(tmp_path / "ref"), lambda _: True)
    assert ref.outcome is Outcome.PROVED, ref
    e0 = paired(gen.gen_core(tmp_path / "e0", interps, part="e0"),
                lambda p: p.property_id.startswith("p1_") and ".assertion." not in p.property_id,
                allow_empty=True, independent_safety_refutation=True)
    if e0.outcome is Outcome.VIOLATED:
        e1, per_class, decisive = e0, {}, False
    else:
        old_keep = paired(gen.gen_reference(tmp_path / "keep", interps, domain="e1_keep"),
                          lambda _: True)
        assert old_keep.outcome is Outcome.PROVED, old_keep
        keep = gen.gen_core(tmp_path / "e1", interps)
        e1 = paired(keep, lambda p: p.description == "VWE.E1.preservation")
        decisive = keep.e1_decisive
        per_class = {}
        if e1.outcome is Outcome.PROVED:
            for i, it in enumerate(interps):
                old_class = paired(gen.gen_reference(tmp_path / f"keep_class{i}", (it,), domain="keep"),
                                   lambda _: True)
                assert old_class.outcome is Outcome.PROVED, old_class
                b = gen.gen_class(tmp_path / f"class{i}", it)
                per_class[it["id"]] = paired(b, lambda p: p.description.startswith("VWE.class."))
    verdict = decide(Evidence(e0, e1, decisive, per_class))
    assert [verdict.decision, verdict.evidence_class] == want, (verdict, e0, e1, per_class)
