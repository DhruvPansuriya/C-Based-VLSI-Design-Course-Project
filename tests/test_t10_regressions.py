"""Soundness boundaries exercised by the remaining draft examples."""
from dataclasses import replace
import json
import shutil

import pytest

from vwe.config import Config, Native
from vwe.harness.profile import plain
from vwe.pipeline import verify
from vwe.regions import compute_regions
from vwe.tasks import load_pipeline_view
from vwe.tools.cbmc import _witness
from vwe.validate import State, freeze_interpretations
from vwe.verdict import Outcome
from vwe.views import make_views
from .test_harness_generator import EXAMPLES, REAL


@pytest.mark.parametrize("data,want", [
    ("4294967295u", "4294967295"),
    ("-9223372036854775808l", "-9223372036854775808"),
    ("18446744073709551615ull", "18446744073709551615"),
    ("0x10u", "0x10u"),
])
def test_cbmc_integer_tokens(data, want):
    value = {"name": "integer", "data": data}
    trace = [{"stepType": "assignment", "lhs": "n", "value": value},
             {"stepType": "output", "outputID": "result", "values": [value]}]
    assert _witness(trace, ("n", "result")) == {"n": want, "result": want}


@REAL
@pytest.mark.parametrize("body", [
    "if (index > 0) dst[index] = 0; return 0;",
    "dst[index++] = 0; return 0;",
    "dst[index] = g(); return 0;",
])
def test_nonqualifying_store_never_gets_exactness(tmp_path, body):
    source = tmp_path / "p0.c"
    source.write_text("int g(void) { return 0; } int f(int *dst,int index,int cap) {" + body + "}")
    views = make_views(source, "f", tmp_path / "views", prefix="p0")
    shape = {"buffers": {"dst": "cap"}, "alias": "disjoint", "bounds": {"cap": [1, 4]},
             "value_bounds": {"index": [-1, 4]}}
    result = compute_regions(views, shape, tmp_path / "regions", parallel=False)
    assert result.exact_ub is None
    assert result.reference_safe_guard is None


@REAL
def test_initial_store_covers_negative_index(tmp_path):
    source = tmp_path / "p0.c"
    source.write_text("int f(int *dst,int index,int cap) { dst[index] = 0; (void)cap; return 0; }")
    views = make_views(source, "f", tmp_path / "views", prefix="p0")
    shape = {"buffers": {"dst": "cap"}, "alias": "disjoint", "bounds": {"cap": [1, 4]},
             "value_bounds": {"index": [-1, 4]}}
    result = compute_regions(views, shape, tmp_path / "regions", parallel=False)
    assert result.exact_ub is not None
    assert result.universal_inside.outcome is Outcome.PROVED
    assert result.reference_safe_guard


@REAL
def test_disjunction_requires_full_universal_constructive_proof(tmp_path):
    task = load_pipeline_view(EXAMPLES / "ex1_saturate")
    views = make_views(EXAMPLES / "ex1_saturate/p0.c", "add8", tmp_path / "views", prefix="p0")
    base = plain(task.interpretations[0])

    def reading(name, relation):
        return {**base, "id": name, "clauses": [{"zone": "a + b > 255", "behaviour": relation}]}

    # The second witness construction overflows the byte output. A satisfiable
    # alternate branch is insufficient to validate it for every input.
    frozen = freeze_interpretations(task.task_id, views, [
        reading("good", "out_ret == 255 || out_ret == 254"),
        reading("unproved", "out_ret == a + b || out_ret == 255"),
    ], tmp_path / "freeze", parallel=False)
    assert {r.id: r.state for r in frozen.results} == {"good": State.VALID, "unproved": State.UNKNOWN}
    assert not frozen.fully_validated and len(frozen.members) == 2


@REAL
def test_empty_zone_identity_does_not_require_a_repair_bug(tmp_path):
    task = load_pipeline_view(EXAMPLES / "ex7_build_views")
    views = make_views(EXAMPLES / "ex7_build_views/p0.c", "transform", tmp_path / "views", prefix="p0")
    identity = plain(task.interpretations[0])
    repair = {**identity, "id": "empty_repair", "request_type": "T2"}
    frozen = freeze_interpretations(task.task_id, views, [identity, repair], tmp_path / "freeze", parallel=False)
    checks = {r.id: r for r in frozen.results}
    assert checks[identity["id"]].state is State.VALID
    assert checks["empty_repair"].state is State.INVALID and checks["empty_repair"].check == "V-2"
    assert frozen.fully_validated


@REAL
@pytest.mark.parametrize("candidate,decision", [("v1", "ACCEPT"), ("v2", "REJECT")])
def test_overflow_verdict_depends_on_the_interpretation_set(tmp_path, candidate, decision):
    folder = tmp_path / "task"
    shutil.copytree(EXAMPLES / "ex5_add32_ambiguous", folder)
    manifest = folder / "task.json"
    data = json.loads(manifest.read_text())
    data["interpretations"] = ["interpretations/strict.json"]
    manifest.write_text(json.dumps(data))
    config = replace(Config(), native=Native(prepass_samples=0))
    report = verify(folder, candidate, config, runs_root=tmp_path / "runs", parallel=False)
    assert (report.decision, report.evidence_class) == (decision, "E2"), report.data
