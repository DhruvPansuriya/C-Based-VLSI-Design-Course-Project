"""T13: generation with authored mock fixtures; verification tests need CBMC."""
from __future__ import annotations

import json
import shutil
from pathlib import Path

import pytest

from vwe.interpret import generate_interpretations, load_generated
from vwe.llm import LLMClient, MockProvider, RequestContext
from vwe.llm.prompt_files import PROMPT_NAMES, load_prompt
from vwe.tasks import load_pipeline_view
from vwe.tools import cbmc

ROOT = Path(__file__).resolve().parent.parent
FIX = ROOT / "tests/fixtures/llm/auto"
CANARY = "CANARY_P1_7f3a"


def client(task_name: str, family: str, tmp_path: Path) -> LLMClient:
    provider = MockProvider(fixture_dir=FIX / task_name, family=family)
    return LLMClient(provider, f"{family}-fixture", cache_dir=tmp_path / family)


def test_prompts_are_versioned_and_hashed():
    hashes = {n: load_prompt(n) for n in PROMPT_NAMES}
    assert all(t.version == "1" and len(t.sha256) == 64 for t in hashes.values())
    assert len({t.sha256 for t in hashes.values()}) == 5


def test_few_shot_examples_are_not_evaluation_tasks():
    text = "".join(load_prompt(n).system for n in ("strict", "permissive", "adversarial"))
    for task_dir in (ROOT / "examples/tasks").iterdir():
        context = RequestContext.from_task(load_pipeline_view(task_dir), "original")
        assert context.signature not in text, task_dir.name
        assert (task_dir / "request.txt").read_text().strip() not in text


def test_generation_two_mock_families_is_not_called_live(tmp_path):
    task = load_pipeline_view(ROOT / "examples/tasks/ex1_saturate")
    clients = [client("ex1_saturate", "mock_a", tmp_path), client("ex1_saturate", "mock_b", tmp_path)]
    result = generate_interpretations(task, clients, out_dir=tmp_path / "out")
    assert len(result.members) == 6  # strict, permissive, adversarial x 2 families
    assert result.generation["live_families"] == [] and result.generation["independent_live_family_count"] == 0
    assert result.generation["p1_seen_by_any_llm"] is False
    assert {m["provenance"]["model_family"] for m in result.members} == {"mock_a", "mock_b"}
    assert all(m["shape"] == dict(json.loads(json.dumps(task.caller_domain, default=dict))) for m in result.members)
    again = load_generated(tmp_path / "out/generated_set.json")
    assert again.sha256 == result.sha256
    assert "No candidate" in (tmp_path / "out/interpretations.md").read_text()


def test_invalid_response_is_recorded_not_guessed(tmp_path):
    task = load_pipeline_view(ROOT / "examples/tasks/ex1_saturate")
    provider = MockProvider({"typing": json.dumps({"type": "T2", "rationale": "x"}),
                             "shape": json.dumps({"buffers": {}, "rationale": "x"}),
                             "strict": "garbage", "permissive": "garbage"}, family="bad")
    result = generate_interpretations(task, [LLMClient(provider, "m", cache_dir=tmp_path)])
    assert result.members == ()
    statuses = {r["prompt"]: r["status"] for r in result.records}
    assert statuses["strict"] == "failed" and statuses["adversarial"] == "skipped"


def test_unavailable_live_family_yields_empty_set(tmp_path):
    from vwe.llm import build_client, load_llm_settings
    task = load_pipeline_view(ROOT / "examples/tasks/ex1_saturate")
    c = build_client(load_llm_settings(), "anthropic", cache_dir=tmp_path)
    result = generate_interpretations(task, [c])
    assert result.members == () and result.generation["live_families"] == []
    assert {r["status"] for r in result.records} <= {"unavailable", "skipped"}


def test_repeat_runs_use_distinct_cache_entries(tmp_path):
    task = load_pipeline_view(ROOT / "examples/tasks/ex2_argmax")
    result = generate_interpretations(task, [client("ex2_argmax", "m", tmp_path)], runs=2)
    assert len(result.members) == 6
    assert len({m["id"] for m in result.members}) == 6


needs_cbmc = pytest.mark.skipif(not cbmc.cbmc_available(), reason="CBMC unavailable")


@needs_cbmc
def test_auto_verify_matches_handwritten_and_never_uses_handwritten_set(tmp_path):
    from vwe.config import load_config
    from vwe.pipeline import verify
    task = ROOT / "examples/tasks/ex1_saturate"
    generated = generate_interpretations(load_pipeline_view(task), [client("ex1_saturate", "mock_a", tmp_path)])
    cfg = load_config()
    auto = verify(task, "v3", cfg, "auto", runs_root=tmp_path / "runs", generated=generated)
    hand = verify(task, "v3", cfg, "handwritten", runs_root=tmp_path / "runs")
    assert auto.data["interpretation_mode"] == "auto"
    assert (auto.data["decision"], auto.data["evidence_class"]) == (hand.data["decision"], hand.data["evidence_class"])
    ids = {i["id"] for i in auto.data["interpretations"]}
    assert ids and all(".mock_a." in i for i in ids)
    none = verify(task, "v3", cfg, "auto", runs_root=tmp_path / "runs")
    assert none.data["decision"] == "UNDECIDED" and "no automatically generated" in none.data["reason"]


@needs_cbmc
def test_canary_in_candidate_never_reaches_auto_pipeline_prompts(tmp_path):
    from vwe.config import load_config
    from vwe.pipeline import verify
    work = tmp_path / "ex1"
    shutil.copytree(ROOT / "examples/tasks/ex1_saturate", work)
    for path in (work / "candidates").glob("*.c"):
        path.write_text(f"/* {CANARY} */\n" + path.read_text())
    task = load_pipeline_view(work)
    c = client("ex1_saturate", "mock_a", tmp_path)
    generated = generate_interpretations(task, [c], out_dir=tmp_path / "gen")
    report = verify(work, "v3", load_config(), "auto", runs_root=tmp_path / "runs", generated=generated)
    assert report.data["decision"] in {"ACCEPT", "REJECT", "UNDECIDED"}
    for prompt in c.provider.prompts:
        assert all(CANARY not in m.content for m in prompt)
    stored = "".join(p.read_text() for p in (tmp_path / "gen").glob("*")) + \
        "".join(p.read_text() for p in (tmp_path / "mock_a").glob("*.json"))
    assert CANARY not in stored


def test_cli_interpret_mock_and_unavailable_live(tmp_path, capsys):
    from vwe.cli import main
    task = str(ROOT / "examples/tasks/ex1_saturate")
    ok = main(["interpret", task, "--family", "mock", "--fixtures", str(FIX / "ex1_saturate"),
               "--cache-dir", str(tmp_path / "c1"), "--out", str(tmp_path / "ok")])
    assert ok == 0 and (tmp_path / "ok/generated_set.json").is_file()
    assert "live families: none" in capsys.readouterr().out
    bad = main(["interpret", task, "--family", "anthropic", "--cache-dir", str(tmp_path / "c2"),
                "--out", str(tmp_path / "bad")])
    assert bad == 1
    assert "unavailable" in (tmp_path / "bad/interpretations.md").read_text()
    with pytest.raises(SystemExit):
        main(["interpret", task, "--out", str(tmp_path / "none")])  # no --family given
