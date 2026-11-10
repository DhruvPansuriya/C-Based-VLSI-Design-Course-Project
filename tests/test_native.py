"""Native findings remain hints; disagreement must veto a formal decision."""
from dataclasses import replace
import json
from pathlib import Path
import shutil

import pytest

from vwe.config import Config, Native
from vwe.harness.model import HarnessBundle
from vwe.harness.native import InputSlot
from vwe.pipeline import verify
from vwe.replay import NativeSession, Observation, Replay, bind_inputs, samples
from vwe.tools import native
from vwe.tools.frontend import CommandResult
from vwe.views import make_views
from vwe.harness.generate import Generator
from .test_harness_generator import EXAMPLES, REAL, example

NATIVE = pytest.mark.skipif(not shutil.which("gcc") or not native.sandbox_available(),
                            reason="native compiler and network isolation required")


def test_boundary_sampling_is_seeded_and_bounded():
    slots = (InputSlot("n", 0, 4), InputSlot("a", -128, 127))
    first = list(samples(slots, 50, 7))
    assert first == list(samples(slots, 50, 7))
    assert first != list(samples(slots, 50, 8))
    assert first[:5] == [{"n": "0", "a": "0"}, {"n": "1", "a": "1"},
                         {"n": "0", "a": "-1"}, {"n": "0", "a": "-128"},
                         {"n": "4", "a": "127"}]
    assert len(first) == 50
    assert list(samples(slots, 0, 7)) == []


def test_fixed_binding_prunes_missing_active_inputs(tmp_path):
    src = tmp_path / "original"
    src.mkdir()
    (src / "frame.h").write_text("/* frame */")
    main = src / "main.c"
    main.write_text("int main(void) {\n  int __vwe_in_n=nondet___vwe_0();\n"
                    "  if (__vwe_in_n) {\n  unsigned char __vwe_in_a=nondet___vwe_1();\n}\n}\n")
    bundle = HarnessBundle("e0", src, (main,), "main", 5,
                           ("__vwe_in_n", "__vwe_in_a"), (), (), "profile")
    fixed = bind_inputs(bundle, {"__vwe_in_n": "0"}, tmp_path / "fixed")
    text = fixed.files[0].read_text()
    assert "__CPROVER_assume(__vwe_in_n == 0LL)" in text
    assert "__CPROVER_assume(0); /* missing replay slot */" in text
    main.write_text(main.read_text().replace("unsigned char", "unsupported type name here"))
    with pytest.raises(ValueError, match="full planned witness inventory"):
        bind_inputs(bundle, {}, tmp_path / "unmatched")


def test_sandbox_unavailable_never_executes_candidate(tmp_path, monkeypatch):
    monkeypatch.setattr(native, "_sandbox", lambda executable: None)
    result = native.run_driver(tmp_path / "candidate", ())
    assert result.outcome == "unsupported" and result.command is None


@pytest.mark.parametrize("stderr,code,outcome", [
    ("ERROR: AddressSanitizer: heap-buffer-overflow", 1, "sanitizer"),
    ("runtime error: signed integer overflow", 1, "sanitizer"),
    ("", 77, "invalid_input"), ("", 1, "error"),
])
def test_native_process_classification(tmp_path, monkeypatch, stderr, code, outcome):
    monkeypatch.setattr(native, "_sandbox", lambda executable: (str(executable),))
    command = CommandResult(("driver",), str(tmp_path), code, "", stderr, 0)
    monkeypatch.setattr(native, "_execute_driver", lambda *args: command)
    assert native.run_driver(tmp_path / "driver", ()).outcome == outcome


def test_rejected_reference_input_cannot_confirm_a_class_witness(monkeypatch):
    # A class witness may omit P0 outputs, but P0 must still execute or expose UB.
    observation = Observation(native.NativeResult("invalid_input", {}, None),
                              native.NativeResult("clean", {"ret": "1"}, None))
    monkeypatch.setattr(NativeSession, "ready", property(lambda self: True))
    monkeypatch.setattr(NativeSession, "observe", lambda *args: observation)
    session = object.__new__(NativeSession)
    replay = session.confirm("E2", {"__vwe_out_one_ret": "1"}, "invalid")
    assert replay.status == "discrepancy"
    assert "input constraint" in replay.reason


@NATIVE
@REAL
def test_argmax_n3_replays_as_heap_buffer_overflow(tmp_path):
    _, gen = example("ex2_argmax", 3, tmp_path)
    session = NativeSession(gen, tmp_path / "native", Native())
    assert session.ready, session.reason
    inputs = {s.name: "0" for s in session.drivers["p1"].slots}
    inputs["__vwe_in_scalar_1_0"] = "3"
    replay = session.confirm("E0", inputs, "n3")
    assert replay.status == "confirmed", replay
    assert replay.observation.p0.outcome == "clean"
    assert replay.observation.p1.detail == "heap-buffer-overflow"
    assert (session.folder / "n3.json").is_file()


@NATIVE
@REAL
def test_prepass_finds_constant_saturation_outside_scope(tmp_path):
    task, gen = example("ex1_saturate", 3, tmp_path)
    session = NativeSession(gen, tmp_path / "native", Native())
    hint, count = session.prepass(task.interpretations, 100, 0)
    assert hint and hint.kind == "e1" and 0 < count <= 100
    assert hint.observation.p0.outputs != hint.observation.p1.outputs
    assert (session.folder / "prepass-hint.json").is_file()


@NATIVE
@REAL
@pytest.mark.parametrize("variant,expected", [(1, "confirmed"), (3, "discrepancy")])
def test_acceptance_uses_executable_contract_checks(tmp_path, variant, expected):
    task, gen = example("ex1_saturate", variant, tmp_path)
    session = NativeSession(gen, tmp_path / "native", Native())
    session.prepass(task.interpretations, 5, 0)
    result = session.check_acceptance(task.interpretations)
    assert result.status == expected, result
    if expected == "discrepancy":
        bug = json.loads((session.folder / "checks" / "discrepancy.json").read_text())
        assert bug["failed_interpretations"]


@NATIVE
@REAL
def test_p0_undefined_exception_is_explicit(tmp_path):
    _, gen = example("ex2_argmax", 1, tmp_path)
    session = NativeSession(gen, tmp_path / "native", Native())
    inputs = {s.name: "0" for s in session.drivers["p1"].slots}
    observation = session.observe(inputs)
    assert observation.p0.outcome == "sanitizer" and observation.p1.outcome == "clean"
    witness = {**inputs, **{"__vwe_out_one_" + k: v for k, v in observation.p1.outputs.items()}}
    assert session.confirm("E2", witness, "undefined").status == "p0_undefined"


@NATIVE
@REAL
def test_wrong_witness_cannot_confirm_rejection(tmp_path):
    _, gen = example("ex1_saturate", 3, tmp_path)
    session = NativeSession(gen, tmp_path / "native", Native())
    inputs = {s.name: "0" for s in session.drivers["p1"].slots}
    witness = {**inputs, "__vwe_out_one_ret": "0", "__vwe_out_zero_ret": "0"}
    assert session.confirm("E1", witness, "wrong").status == "discrepancy"


@NATIVE
@REAL
def test_simulation_and_synthesis_replay_have_separate_namespaces(tmp_path):
    source = tmp_path / "source.c"
    source.write_text("int f(int n) {\n#ifdef __SYNTHESIS__\nreturn 0;\n#else\nreturn n;\n#endif\n}")
    views = make_views(source, "f", tmp_path / "views", prefix="p1")
    shape = {"buffers": {}, "alias": "disjoint", "bounds": {}}
    gen = Generator(views, views, shape)
    session = NativeSession(gen, tmp_path / "native", Native(), build_views=True)
    assert session.ready, session.reason
    replay = session.confirm("views", {"__vwe_in_scalar_0_0": "3",
                                       "__vwe_out_zero_ret": "3", "__vwe_out_one_ret": "0"}, "views")
    assert replay.status == "confirmed", replay


@REAL
@pytest.mark.parametrize("status", ["discrepancy", "unsupported"])
def test_replay_discrepancy_vetoes_pipeline_reject(tmp_path, monkeypatch, status):
    monkeypatch.setattr(NativeSession, "confirm", lambda *args: Replay(status, "wrong witness"))
    cfg = replace(Config(), native=Native(prepass_samples=0))
    report = verify(EXAMPLES / "ex1_saturate", "v3", cfg, runs_root=tmp_path, parallel=False)
    assert report.decision == "UNDECIDED"
    assert "replay " + status in report.data["reason"]
    assert not report.data["witness"]["replayed_natively"]


@REAL
def test_native_disagreement_vetoes_pipeline_accept(tmp_path, monkeypatch):
    monkeypatch.setattr(NativeSession, "check_acceptance",
                        lambda *args: Replay("discrepancy", "native contract disagreement"))
    cfg = replace(Config(), native=Native(prepass_samples=0))
    report = verify(EXAMPLES / "ex1_saturate", "v1", cfg, runs_root=tmp_path, parallel=False)
    assert report.decision == "UNDECIDED" and "disagreement" in report.data["reason"]
