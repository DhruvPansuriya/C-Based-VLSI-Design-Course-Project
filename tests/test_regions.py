"""Computed regions distinguish an exact region from a safe overapproximation."""
import pytest

from vwe.regions import compute_regions
from vwe.verdict import Outcome
from vwe.views import make_views
from .test_harness_generator import REAL, example


@REAL
@pytest.mark.parametrize(("predicate", "exact", "outside", "inside"), [
    ("n == 0", True, Outcome.PROVED, Outcome.VIOLATED),
    ("n == 1", False, Outcome.VIOLATED, Outcome.PROVED),
    ("n < 0", False, Outcome.VIOLATED, Outcome.INCONCLUSIVE),
    ("n <= 1", False, Outcome.PROVED, Outcome.VIOLATED),
])
def test_argmax_regions(tmp_path, predicate, exact, outside, inside):
    task, gen = example("ex2_argmax", 1, tmp_path / "setup")
    result = compute_regions(gen.p0, task.caller_domain, tmp_path / "run",
                             proposed_ub=predicate, parallel=False)
    assert result.ub_coverage.outcome is outside
    assert result.ub_witness.outcome is inside
    assert result.exact_ub == (predicate if exact else None)
    assert result.exact_nd == ("false" if exact else None)
    if predicate == "n < 0":
        assert result.predicate_reach.outcome is Outcome.PROVED
    if predicate == "n <= 1":
        assert result.reference_safe_guard == "!(n <= 1)"
        assert result.universal_inside.outcome is Outcome.VIOLATED
    if exact:
        assert result.ub_witness.witness["__vwe_in_scalar_1_0"] == "0"
        assert result.universal_inside.outcome is Outcome.PROVED
        assert result.determinism_outside.outcome is Outcome.PROVED


@REAL
def test_uninitialized_read_is_not_defined_nondeterminism(tmp_path):
    source = tmp_path / "source.c"
    source.write_text("int f(int x) { int k; if (x > 0) k = 0; return k + x; }")
    p0 = make_views(source, "f", tmp_path / "p0", prefix="p0")
    profile = {"alias": "disjoint", "buffers": {}, "bounds": {},
               "value_bounds": {"x": [-100, 100]}}
    report = compute_regions(p0, profile, tmp_path / "regions", proposed_ub="x <= 0",
                             parallel=False)
    assert report.ub_coverage.outcome is Outcome.PROVED
    assert report.ub_witness.outcome is Outcome.VIOLATED
    assert "uninitialized_local" in report.ub_witness.note
    assert report.exact_ub is None
    assert report.exact_nd is None
