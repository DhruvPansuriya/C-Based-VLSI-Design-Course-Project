import json
from pathlib import Path

import pytest
from jsonschema import ValidationError

from vwe.schemas import validate

ROOT = Path(__file__).resolve().parent.parent


def test_example_interpretation_valid():
    validate("interpretation", json.loads((ROOT / "examples/interpretations/ex2_argmax_strict.json").read_text()))


def test_interpretation_rejects_unknown_alias():
    doc = json.loads((ROOT / "examples/interpretations/ex2_argmax_strict.json").read_text())
    doc["shape"]["alias"] = "may_alias"
    with pytest.raises(ValidationError):
        validate("interpretation", doc)


def test_interpretation_set_with_member():
    member = json.loads((ROOT / "examples/interpretations/ex2_argmax_strict.json").read_text())
    validate("interpretation_set", {
        "task_id": "ex2", "sha256": "0" * 64, "members": [member], "discarded": [],
        "generation": {"runs": 1, "families": ["family-A"], "p1_seen_by_any_llm": False}})
    member_bad = dict(member, shape={"buffers": {}, "alias": "x", "bounds": {}})
    with pytest.raises(ValidationError):
        validate("interpretation_set", {
            "task_id": "ex2", "sha256": "0" * 64, "members": [member_bad], "discarded": [],
            "generation": {"runs": 1, "families": ["family-A"]}})
