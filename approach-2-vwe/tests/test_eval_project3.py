"""EVAL-P3 adapter and comparison logic (no solvers, no handoff data needed)."""
from __future__ import annotations

import importlib.util
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent


def load(name):
    spec = importlib.util.spec_from_file_location(name, ROOT / f"scripts/{name}.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


ADAPT, EVAL = load("adapt_project3"), load("eval_project3")
SRC = "#include <stdint.h>\nvoid kernel(const uint32_t a[4], uint32_t out[4]) { for (int i = 0; i < 4; i++) out[i] = a[i]; }\n"


def test_stdint_replacement_is_recorded_and_other_includes_skip():
    text, notes = ADAPT.adapt(SRC)
    assert "typedef unsigned int uint32_t;" in text and "#include" not in text and notes
    with pytest.raises(ADAPT.Skip):
        ADAPT.adapt("#include <stdio.h>\nvoid kernel(void) {}\n")


def test_preservation_reading_covers_only_mutable_outputs():
    shape, outputs = ADAPT.signature_info(ADAPT.adapt(SRC)[0])
    assert shape["buffers"] == {"a": "4", "out": "4"}
    assert outputs == ["forall(i, 0, 4, out_out[i] == old_out[i])"]
    reading = ADAPT.preservation_reading("t", shape, outputs)
    assert reading["request_type"] == "T5" and reading["clauses"] == [] and reading["reach"] == "false"
    with pytest.raises(ADAPT.Skip):
        ADAPT.signature_info("void kernel(unsigned *p) { *p = 1; }\n")


def test_outcome_classes():
    assert EVAL.outcome_class("ACCEPT", "equivalent") == "agree"
    assert EVAL.outcome_class("REJECT", "not_equivalent") == "agree"
    assert EVAL.outcome_class("REJECT", "candidate_undefined") == "agree"
    assert EVAL.outcome_class("ACCEPT", "not_equivalent") == "DISAGREE"
    assert EVAL.outcome_class("UNDECIDED", "equivalent") == "abstained"
