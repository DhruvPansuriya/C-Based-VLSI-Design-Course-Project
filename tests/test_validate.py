"""Interpretations are removed only by an objective counterexample or proof."""
import json

from vwe.harness.profile import plain
from vwe.validate import State, freeze_interpretations
from .test_harness_generator import REAL, example


@REAL
def test_invalid_shape_and_equivalence(tmp_path):
    task, gen = example("ex4_sum", 1, tmp_path / "setup")
    frozen = freeze_interpretations(task.task_id, gen.p0, task.interpretations,
                                    tmp_path / "validation", parallel=False)
    assert frozen.fully_validated, frozen.results
    invalid = next(r for r in frozen.results if "invalid" in r.id)
    assert (invalid.state, invalid.check) == (State.INVALID, "V-G")
    assert frozen.classes == (("ex4_sum.permissive", "ex4_sum.strict"),)
    assert json.loads(frozen.path.read_text())["sha256"] == frozen.sha256


@REAL
def test_noop_contradiction_and_joint_witness(tmp_path):
    task, gen = example("ex1_saturate", 1, tmp_path / "setup")
    template = plain(task.interpretations[0])

    def interp(name, behaviour, zone="a + b > 255"):
        return {**template, "id": name, "clauses": [{"zone": zone, "behaviour": behaviour}]}

    model = (
        interp("contradiction", "out_ret == 1 && out_ret == 2"),
        interp("unchanged", "out_ret == a + b", "a + b <= 255"),
        interp("unsupported", "out_ret > 0"),
        *task.interpretations,
    )
    frozen = freeze_interpretations(task.task_id, gen.p0, model, tmp_path / "first", parallel=False)
    results = {r.id: (r.state, r.check) for r in frozen.results}
    assert results["contradiction"] == (State.INVALID, "V-4")
    assert results["unchanged"] == (State.INVALID, "V-2")
    assert results["unsupported"] == (State.UNKNOWN, "V-4")
    assert not frozen.fully_validated
    assert len(frozen.members) == 3
    assert frozen.classes == (("ex1_saturate.permissive", "ex1_saturate.strict"),)
    repeated = freeze_interpretations(task.task_id, gen.p0, model[::-1],
                                      tmp_path / "second", parallel=False)
    assert repeated.sha256 == frozen.sha256


@REAL
def test_unsafe_original_can_supply_bug_witness(tmp_path):
    task, gen = example("ex2_argmax", 1, tmp_path / "setup")
    frozen = freeze_interpretations(task.task_id, gen.p0, task.interpretations,
                                    tmp_path / "validation", parallel=False)
    assert frozen.fully_validated, frozen.results
    assert frozen.classes == (("ex2_argmax.permissive", "ex2_argmax.strict"),)
    assert all(r.witness["__vwe_in_scalar_1_0"] == "0" for r in frozen.results)
