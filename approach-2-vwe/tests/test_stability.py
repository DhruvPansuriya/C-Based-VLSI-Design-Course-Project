"""T14: union semantics, stability measurement and the valid monotonicity premise."""
from __future__ import annotations

import itertools
import json
from pathlib import Path

import pytest

from vwe.interpret import generate_interpretations
from vwe.llm import LLMClient, MockProvider
from vwe.stability import conservative_step, select_runs, stability_report, union
from vwe.tasks import load_pipeline_view
from vwe.tools import cbmc
from vwe.verdict import Evidence, Obligation, Outcome, decide

ROOT = Path(__file__).resolve().parent.parent
FIX = ROOT / "tests/fixtures/llm/auto/ex1_saturate"
P, V, I = Outcome.PROVED, Outcome.VIOLATED, Outcome.INCONCLUSIVE


def generated(tmp_path, runs=3, seed=None):
    provider = MockProvider(fixture_dir=FIX, family="mock_a")
    client = LLMClient(provider, "fixture", cache_dir=tmp_path / "cache", seed=seed)
    return generate_interpretations(load_pipeline_view(ROOT / "examples/tasks/ex1_saturate"),
                                    [client], runs=runs), provider


def test_union_monotonicity_under_its_premise_exhaustive():
    """With E0/E1 fixed and a nonempty base, enlarging the set gives same-or-UNDECIDED."""
    outcomes = (P, V, I)
    checked = 0
    for e1, base_known, extra_known in itertools.product((P, V, I), (True, False), (True, False)):
        for nb, ne in ((1, 1), (2, 1), (1, 2), (2, 2), (3, 1)):
            for base in itertools.product(outcomes, repeat=nb):
                for extra in itertools.product(outcomes, repeat=ne):
                    def ev(outs, known):
                        return Evidence(Obligation(P), Obligation(e1), known,
                                        {f"c{i}": Obligation(o) for i, o in enumerate(outs)})
                    before = decide(ev(base, base_known))
                    after = decide(ev(base + extra, base_known and extra_known))
                    assert conservative_step((before.decision, before.evidence_class),
                                             (after.decision, after.evidence_class)), (base, extra, e1)
                    checked += 1
    assert checked > 1000


def test_premise_matters_empty_base_and_changed_e1_are_not_covered():
    empty = decide(Evidence(Obligation(P), Obligation(P), True, {}))
    later = decide(Evidence(Obligation(P), Obligation(P), True, {"x": Obligation(P)}))
    assert empty.decision == "UNDECIDED" and later.decision == "ACCEPT"  # empty base is excluded
    # A larger B_max can turn an E1 violation into PROVED: a pipeline-level step need not be conservative.
    rejected = decide(Evidence(Obligation(P), Obligation(V), True, {"x": Obligation(P)}))
    widened = decide(Evidence(Obligation(P), Obligation(P), True, {"x": Obligation(P)}))
    assert (rejected.decision, widened.decision) == ("REJECT", "ACCEPT")
    assert not conservative_step(("REJECT", "E1"), ("ACCEPT", "E2"))


def test_runs_union_merges_semantic_duplicates(tmp_path):
    gen, _ = generated(tmp_path)
    assert len(gen.members) == 9
    runs = sorted({m["provenance"]["run_index"] for m in gen.members})
    assert runs == [0, 1, 2]
    one = select_runs(gen, [1])
    assert len(one.members) == 3 and one.generation["runs"] == 1
    merged = union([select_runs(gen, [0]), select_runs(gen, [1])])
    assert len(merged.members) == 2 and len({m["id"] for m in merged.members}) == 2
    assert merged.generation["runs"] == 2 and merged.sha256 != one.sha256


def test_seeds_are_recorded_per_run_and_change_cache_keys(tmp_path):
    gen, _ = generated(tmp_path, runs=2, seed=10)
    seeds = {(r["prompt"], r["run_index"]): r["provenance"]["seed"]
             for r in gen.records if r["prompt"] == "strict"}
    assert seeds == {("strict", 0): 10, ("strict", 1): 11}
    keys = {a["request_key"] for r in gen.records if r["prompt"] == "strict"
            for a in r["provenance"]["attempts"]}
    assert len(keys) == 2
    assert "determinism is not assumed" in gen.records[0]["provenance"]["seed_note"]


def scripted(table):
    """verify_fn answering in call order: per candidate singles first, then union prefixes."""
    iters = {cid: iter(seq) for cid, seq in table.items()}
    return lambda cid, subset: next(iters[cid])


def test_stability_report_measures_agreement_and_coverage(tmp_path):
    gen, _ = generated(tmp_path)
    acc, und, rej = ("ACCEPT", "E2"), ("UNDECIDED", "-"), ("REJECT", "E1")
    # order: single run 0, 1, 2, then union of runs {0,1}, then {0,1,2}
    verify_fn = scripted({"a": [acc, acc, und, acc, und], "b": [rej] * 5})
    report = stability_report("ex1_saturate", gen, ["a", "b"], verify_fn)
    assert report["candidates"]["a"]["agreement"] == pytest.approx(2 / 3)
    assert report["candidates"]["b"]["agreement"] == 1.0
    assert report["coverage_by_union_size"] == [1.0, 1.0, 0.5]
    assert report["distinct_readings_by_union_size"] == [2, 2, 2]
    assert report["nonconservative_steps"] == []


def test_nonconservative_step_is_flagged_not_hidden(tmp_path):
    gen, _ = generated(tmp_path, runs=2)
    rej, acc = ("REJECT", "E1"), ("ACCEPT", "E2")
    report = stability_report("ex1_saturate", gen, ["a"], scripted({"a": [rej, rej, acc]}))
    assert report["nonconservative_steps"] == [("a", 2)]


@pytest.mark.skipif(not cbmc.cbmc_available(), reason="CBMC unavailable")
def test_cli_stability_end_to_end_with_mock_fixtures(tmp_path):
    from vwe.cli import main
    out = tmp_path / "stab"
    code = main(["stability", str(ROOT / "examples/tasks/ex1_saturate"), "--candidate", "v3", "--runs", "2",
                 "--family", "mock", "--fixtures", str(FIX), "--cache-dir", str(tmp_path / "c"),
                 "--runs-root", str(tmp_path / "runs"), "--out", str(out)])
    report = json.loads((out / "stability.json").read_text())
    assert code == 0 and report["runs"] == 2
    assert report["candidates"]["v3"]["cumulative"] == ["REJECT E1", "REJECT E1"]
    assert report["nonconservative_steps"] == []
