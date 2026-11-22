"""The demo web page generator only reads files and links to existing runs."""
from __future__ import annotations

import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def _load():
    spec = importlib.util.spec_from_file_location("demo_portal", ROOT / "scripts/demo_portal.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def test_portal_lists_runs_and_sections(tmp_path, monkeypatch):
    mod = _load()
    run = tmp_path / "runs/ex1_saturate/v3/abc"
    run.mkdir(parents=True)
    (run / "report.json").write_text(json.dumps({
        "task_id": "ex1_saturate", "candidate_id": "v3", "decision": "REJECT", "evidence_class": "E1",
        "reason": "regression <outside>", "timing": {"wall_seconds": 21.7},
        "witness": {"inputs": {"a": "0", "b": "0"}, "p0_output": {"ret": "0"}, "p1_output": {"ret": "255"}}}))
    (run / "report.html").write_text("<html></html>")
    (tmp_path / "runs/broken").mkdir()
    (tmp_path / "runs/broken/report.json").write_text("{not json")
    monkeypatch.setattr(mod, "ROOT", tmp_path)
    out = tmp_path / "runs/index.html"
    mod.build(out, limit=10)
    page = out.read_text()
    for anchor in ("id=\"pipeline\"", "id=\"run\"", "id=\"runs\"", "id=\"results\"", "id=\"where\""):
        assert anchor in page
    assert "REJECT E1" in page and "a=0, b=0" in page and "P1: ret=255" in page and "22 s" in page
    assert "ex1_saturate/v3/abc/report.html" in page
    assert "regression &lt;outside&gt;" in page          # escaped, never raw HTML from a report


def test_portal_with_no_runs(tmp_path, monkeypatch):
    mod = _load()
    monkeypatch.setattr(mod, "ROOT", tmp_path)
    (tmp_path / "runs").mkdir()
    mod.build(tmp_path / "runs/index.html", limit=5)
    assert "No runs yet" in (tmp_path / "runs/index.html").read_text()
