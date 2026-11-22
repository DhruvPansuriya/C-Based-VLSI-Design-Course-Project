"""Computed regions distinguish an exact region from a safe overapproximation."""
import pytest

from pathlib import Path
from vwe.regions import compute_regions
from vwe.tools import cbmc
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


@pytest.mark.skipif(not cbmc.cbmc_available(), reason="CBMC unavailable")
def test_region_cache_is_opt_in_exact_and_keyed_on_code_and_config(tmp_path, monkeypatch):
    from dataclasses import asdict
    from vwe.config import Config, Timeouts
    from vwe.regions import compute_regions
    from vwe.tasks import load_pipeline_view
    from vwe.views import make_views
    task = load_pipeline_view(Path(__file__).resolve().parent.parent / "examples/tasks/ex2_argmax")
    (tmp_path / "p0.c").write_text(task.p0.text)
    views = make_views(tmp_path / "p0.c", task.function, tmp_path / "views", prefix="p0")
    monkeypatch.setenv("VWE_REGION_CACHE", str(tmp_path / "cache"))
    first = compute_regions(views, task.caller_domain, tmp_path / "a")
    assert not (tmp_path / "a/cache_hit.json").exists()
    second = compute_regions(views, task.caller_domain, tmp_path / "b")
    assert (tmp_path / "b/cache_hit.json").exists() and asdict(second) == asdict(first)
    other = Config(timeouts=Timeouts(cbmc_s=599))
    compute_regions(views, task.caller_domain, tmp_path / "c", config=other)
    assert not (tmp_path / "c/cache_hit.json").exists()  # configuration is part of the key
    monkeypatch.delenv("VWE_REGION_CACHE")
    compute_regions(views, task.caller_domain, tmp_path / "d")
    assert not (tmp_path / "d/cache_hit.json").exists()  # off by default
