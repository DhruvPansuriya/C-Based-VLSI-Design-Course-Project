"""T12 isolation tests (AGENTS.md rule 1). Never delete: they guard the no-P1 boundary."""
from __future__ import annotations

import ast
import dataclasses
import json
import shutil
from pathlib import Path
from typing import Mapping

import pytest

from vwe.llm import LLMClient, MockProvider, PromptTemplate, RequestContext, ContextError
from vwe.tasks import PipelineTask, load_full, load_pipeline_view

ROOT = Path(__file__).resolve().parent.parent
CANARY = "CANARY_P1_7f3a"
LLM_DIR = ROOT / "vwe" / "llm"
TEMPLATE = PromptTemplate("probe", "1", "sys ${signature}", "N: ${request_text}\n${shape_candidates}")
GOOD = (ROOT / "tests/fixtures/llm/strict.json").read_text()


def test_static_fields_cannot_carry_candidates():
    names = {f.name for f in dataclasses.fields(RequestContext)}
    assert names == {"task_id", "request_id", "request_text", "signature", "shape_candidates",
                     "prior_readings"}
    for f in dataclasses.fields(RequestContext):
        assert f.type in ("str", "tuple[str, ...]"), f"{f.name}: {f.type}"
    assert dataclasses.is_dataclass(RequestContext) and RequestContext.__dataclass_params__.frozen


def test_static_llm_package_never_reads_candidates_or_eval_data():
    forbidden_attrs = {"candidates", "interpretations", "eval_only", "p_ref", "phi_ref",
                       "true_shape", "true_change_zone", "acceptable_readings", "p1_views"}
    forbidden_imports = {"vwe.admission", "vwe.pipeline", "vwe.views", "vwe.replay"}
    for path in LLM_DIR.glob("*.py"):
        tree = ast.parse(path.read_text())
        for node in ast.walk(tree):
            if isinstance(node, ast.Attribute):
                assert node.attr not in forbidden_attrs, f"{path.name}: .{node.attr}"
            if isinstance(node, ast.ImportFrom):
                module = ("vwe." + node.module) if node.level == 2 and node.module else node.module
                assert module not in forbidden_imports, f"{path.name} imports {module}"
                if path.name != "context.py":
                    assert node.module != "tasks" and node.module != "..tasks"
                    assert not (node.level == 2 and node.module == "tasks"), path.name
            if isinstance(node, ast.Name):
                assert node.id not in {"Candidate", "FullTask", "EvaluationData"}, f"{path.name}: {node.id}"


class Exploding(Mapping):
    """Fails the test if anything enumerates or reads the candidate mapping."""
    def __getitem__(self, key): raise AssertionError("candidate mapping was read")
    def __iter__(self): raise AssertionError("candidate mapping was iterated")
    def __len__(self): raise AssertionError("candidate mapping was measured")


def test_constructor_never_touches_candidates():
    task = load_pipeline_view(ROOT / "examples/tasks/ex1_saturate")
    hostile = dataclasses.replace(task, candidates=Exploding(), interpretations=Exploding())
    context = RequestContext.from_task(hostile, "original")
    assert context.request_text == task.requests[0].text


def test_constructor_rejects_full_task_and_unknown_request():
    full = load_full(ROOT / "examples/tasks/ex1_saturate")
    with pytest.raises(ContextError):
        RequestContext.from_task(full, "original")  # type: ignore[arg-type]
    with pytest.raises(ContextError):
        RequestContext.from_task(full.pipeline, "missing")


def test_runtime_canary_in_candidate_never_reaches_prompts_cache_or_logs(tmp_path):
    work = tmp_path / "ex1"
    shutil.copytree(ROOT / "examples/tasks/ex1_saturate", work)
    for path in (work / "candidates").glob("*.c"):
        path.write_text(f"/* {CANARY} */\n" + path.read_text())
    manifest = json.loads((work / "task.json").read_text())
    manifest["candidates"]["v1"] = "candidates/v1.c"
    manifest["candidates"][f"{CANARY}_id"] = "candidates/v2.c"
    (work / "task.json").write_text(json.dumps(manifest))
    task = load_pipeline_view(work)
    assert CANARY in task.candidates["v1"].source.text  # the canary is genuinely loaded
    context = RequestContext.from_task(task, "original")
    mock = MockProvider({"probe": GOOD})
    cache, log = tmp_path / "cache", tmp_path / "log.jsonl"
    client = LLMClient(mock, "mock-1", cache_dir=cache, log_path=log)
    assert client.generate(context, TEMPLATE).status == "ok"
    assert mock.prompts, "mock recorded no prompt"
    for prompt in mock.prompts:
        assert all(CANARY not in m.content for m in prompt)
    artifacts = list(cache.glob("*.json")) + [log]
    assert all(CANARY not in p.read_text() for p in artifacts)
    assert CANARY not in json.dumps(context.canonical())


def test_p0_is_the_only_program_text_in_context(tmp_path):
    work = tmp_path / "ex2"
    shutil.copytree(ROOT / "examples/tasks/ex2_argmax", work)
    p0 = (work / "p0.c").read_text().replace("int m=a[0];", f"int m=a[0]; /* {CANARY}_P0_BODY */")
    (work / "p0.c").write_text(p0)
    task = load_pipeline_view(work)
    context = RequestContext.from_task(task, "original")
    assert "argmax" in context.signature
    assert "CANARY" not in json.dumps(context.canonical()), "only the signature, never P0's body"
