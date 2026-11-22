"""T17: baselines on example 1 with mock-fixture readings; B2 is refused, not faked."""
from __future__ import annotations

from pathlib import Path

import pytest

from vwe.eval.baselines import (B2_STATUS, pipeline_baseline, regression_only_set,
                                single_contract_set)
from vwe.eval.baselines import tests_only as run_tests_only
from vwe.interpret import generate_interpretations
from vwe.llm import LLMClient, MockProvider
from vwe.tasks import load_pipeline_view
from vwe.tools import cbmc

ROOT = Path(__file__).resolve().parent.parent
EX1 = ROOT / "examples/tasks/ex1_saturate"


@pytest.fixture(scope="module")
def generated(tmp_path_factory):
    tmp = tmp_path_factory.mktemp("b")
    client = LLMClient(MockProvider(fixture_dir=ROOT / "tests/fixtures/llm/auto/ex1_saturate"), "f",
                       cache_dir=tmp)
    return generate_interpretations(load_pipeline_view(EX1), [client])


def test_b3_keeps_only_strict_and_b4_drops_the_change(generated):
    b3 = single_contract_set(generated).members[0]
    b4 = regression_only_set(generated, (EX1 / "p0.c").read_text(), "add8",
                             {"buffers": {}, "alias": "disjoint", "bounds": {}}).members[0]
    assert b3["ext"] == "out_ret == min(a + b, 255)" and b3["clauses"] == [dict(c) for c in
                                                     next(m for m in generated.members if m["provenance"]["prompt"] == "strict")["clauses"]]
    assert b4["clauses"][0]["behaviour"] == "true" and "old_" not in b4["clauses"][0]["behaviour"]
    assert b4["reach"] == "(a + b > 255)" and b4["ext"] == "out_ret == old_ret"


def test_without_readings_b3_b4_abstain():
    v = pipeline_baseline("single_contract", EX1, "v1", None, lambda *a: pytest.fail("must not verify"))
    assert v.decision == "UNDECIDED"


def test_b2_is_refused_with_reason():
    assert "AGENTS.md rule 1" in B2_STATUS


def test_b1_rejects_sanitizer_failure_and_accepts_clean_code(tmp_path):
    import json, shutil
    work = tmp_path / "t"
    shutil.copytree(EX1, work)
    (work / "candidates/v1.c").write_text("int add8(int a, int b) { int x[2]; return x[a + b] + a; }\n")
    manifest = json.loads((work / "task.json").read_text())
    manifest["caller_domain"] = {"buffers": {}, "alias": "disjoint", "bounds": {},
                                 "value_bounds": {"a": [0, 255], "b": [0, 255]}}
    (work / "task.json").write_text(json.dumps(manifest))
    assert run_tests_only(work, "v1", samples=200).decision == "REJECT"
    (work / "candidates/v1.c").write_text("int add8(int a, int b) { return a + b; }\n")
    assert run_tests_only(work, "v1", samples=200).decision == "ACCEPT"


@pytest.mark.skipif(not cbmc.cbmc_available(), reason="CBMC unavailable")
def test_b3_and_b4_run_through_pipeline(generated, tmp_path):
    from vwe.config import load_config
    from vwe.pipeline import verify
    from vwe.eval.baselines import regression_only
    fn = lambda t, c, g: verify(t, c, load_config(), "auto", runs_root=tmp_path, generated=g).data
    # v3 always returns 255: it breaks ordinary addition outside the overflow zone.
    # B4 and B3 (strict reading only, its Ext included) must both see that.
    assert regression_only(EX1, "v3", generated, load_config(), tmp_path / "b4").decision == "REJECT"
    assert regression_only(EX1, "v1", generated, load_config(), tmp_path / "b4v1").decision == "ACCEPT"
    assert pipeline_baseline("single_contract", EX1, "v3", generated, fn).decision == "REJECT"
    assert pipeline_baseline("single_contract", EX1, "v1", generated, fn).decision == "ACCEPT"
