"""Pinned-tool integration tests for the prepared proof jobs."""
from dataclasses import replace
from pathlib import Path

import pytest

from vwe.harness.model import HarnessBundle
from vwe.proof_jobs import run_job
from vwe.tools import cbmc, esbmc
from vwe.verdict import Outcome
from .test_harness_generator import REAL, ROOT, example

SPIKES = ROOT / "spikes" / "tool_behaviour"


def job(out, source, kind="fixture", labels=()):
    return HarnessBundle(kind, out, (source,), "main", 9, ("x", "n"), labels,
                         ("fixture",), "fixture")


@REAL
def test_self_loop_fails_closed(tmp_path):
    result = run_job(job(tmp_path, SPIKES / "t01_while1/harness.c"), selector=lambda _: True)
    assert result.obligation.outcome is Outcome.INCONCLUSIVE, result.obligation
    assert "unwinding" in result.obligation.note
    assert all(set(cbmc.BASE_FLAGS) <= set(r.command) for r in result.runs.values())


@REAL
def test_linked_path_cut_replaced_and_reachable(tmp_path):
    result = run_job(job(tmp_path, SPIKES / "t03_abort/harness.c", "e0"))
    assert result.instrumentation.trapped == ("abort",)
    assert result.obligation.outcome is Outcome.VIOLATED, result.obligation
    assert all([p.property_id for p in r.failed()] == ["abort.assertion.1"]
               for r in result.runs.values())
    assert (tmp_path / "verification" / "instrumentation.json").exists()


@REAL
def test_exact_malloc_checked_after_linking(tmp_path):
    bundle = job(tmp_path, SPIKES / "t04_buffer_size/exact.c", "e0")
    bundle = replace(bundle, program_symbols=((), ("p1_last",)))
    result = run_job(bundle)
    assert result.obligation.outcome is Outcome.VIOLATED, result.obligation
    assert all([p.property_id.split(".")[0] for p in r.failed()] == ["p1_last"]
               for r in result.runs.values())


@REAL
def test_local_initialization_diagnostic(tmp_path):
    result = run_job(job(tmp_path, SPIKES / "t05_uninit/harness.c"), selector=lambda _: True)
    assert result.obligation.outcome is Outcome.VIOLATED
    assert all(r.failed(lambda p: ".uninitialized_local." in p.property_id)
               for r in result.runs.values())


@REAL
def test_missing_callee_fails_closed(tmp_path):
    result = run_job(job(tmp_path, SPIKES / "t02_bodyless/harness.c"), selector=lambda _: True)
    assert result.obligation.outcome is Outcome.INCONCLUSIVE
    assert "unmodeled callee" in result.obligation.note


@REAL
def test_contradictory_harness_probe_does_not_fire(tmp_path):
    src = tmp_path / "empty.c"
    src.write_text('int main(void) { __CPROVER_assume(0); '
                   '__CPROVER_assert(0, "VWE.vacuity.keep"); }')
    result = run_job(job(tmp_path, src, "vacuity", ("VWE.vacuity.keep",)))
    assert result.obligation.outcome is Outcome.INCONCLUSIVE
    assert result.runs["sat"].status == "success"


@REAL
def test_expected_assertion_removal_detected(tmp_path):
    task, gen = example("ex1_saturate", 1, tmp_path)
    bundle = gen.gen_class(tmp_path / "class", task.interpretations[0])
    result = run_job(bundle)
    assert result.obligation.outcome is Outcome.PROVED, result.obligation
    altered_plan = replace(bundle, property_labels=(*bundle.property_labels, "VWE.class.clause.9"))
    result = run_job(altered_plan)
    assert result.obligation.outcome is Outcome.INCONCLUSIVE
    assert "inventory mismatch" in result.obligation.note


@pytest.mark.skipif(not esbmc.available(), reason="pinned Linux ESBMC required")
def test_esbmc_corroborates_correct_example(tmp_path):
    folder = ROOT / "spikes" / "examples" / "ex1_saturate"
    filenames = ("p0.c", "p1_variants.c", "harness_interp.c")
    result = esbmc.confirm([folder / f for f in filenames], cwd=tmp_path,
                           unwind=9, defines=("VARIANT=1",))
    assert result.status is esbmc.Confirmation.AGREE, result


def test_esbmc_pointer_model_is_explicitly_unsupported(tmp_path, monkeypatch):
    monkeypatch.setattr(esbmc, "available", lambda: True)
    src = tmp_path / "pointer.c"
    src.write_text("int main(void) { return __CPROVER_POINTER_OFFSET((void *)0); }")
    result = esbmc.confirm([src], cwd=tmp_path, unwind=9)
    assert result.status is esbmc.Confirmation.UNSUPPORTED
    assert result.command is None
