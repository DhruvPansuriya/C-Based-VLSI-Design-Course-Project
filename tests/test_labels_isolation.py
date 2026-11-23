"""T16: evaluation labels and the vwe.eval package are invisible to the production pipeline."""
from __future__ import annotations

import ast
import builtins
import io
import json
from pathlib import Path
import shutil

from vwe.eval.labels import combine, identity_reading
from vwe.eval.differential import DiffResult
from vwe.eval.mutants import deduplicate, mutants, normalised
from vwe.llm import RequestContext
from vwe.tasks import load_pipeline_view

ROOT = Path(__file__).resolve().parent.parent
PRODUCTION = [p for p in (ROOT / "vwe").rglob("*.py") if "eval" not in p.relative_to(ROOT / "vwe").parts]


def test_production_code_never_imports_eval_or_mentions_labels():
    for path in PRODUCTION:
        text = path.read_text()
        assert "labels.json" not in text and "pool.json" not in text, path.name
        for node in ast.walk(ast.parse(text)):
            if isinstance(node, ast.ImportFrom):
                mod = node.module or ""
                assert not (mod == "eval" or mod.startswith("eval.") or mod.startswith("vwe.eval")), path
            if isinstance(node, ast.Import):
                assert not any(a.name.startswith("vwe.eval") for a in node.names), path


def test_loading_and_context_never_open_label_files(tmp_path, monkeypatch):
    work = tmp_path / "ex1"
    shutil.copytree(ROOT / "examples/tasks/ex1_saturate", work)
    (work / "eval/labels.json").write_text(json.dumps([{"candidate": "v1", "label": "correct"}]))
    real_open, real_io_open = builtins.open, io.open
    touched = []

    def guard(file, *a, **k):
        if "labels.json" in str(file):
            touched.append(str(file))
            raise AssertionError("label file opened")
        return real_open(file, *a, **k)

    monkeypatch.setattr(builtins, "open", guard)
    monkeypatch.setattr(io, "open", guard)
    original_read = Path.read_bytes
    monkeypatch.setattr(Path, "read_bytes", lambda self: (_ for _ in ()).throw(AssertionError("label read"))
                        if "labels.json" in str(self) else original_read(self))
    task = load_pipeline_view(work)
    RequestContext.from_task(task, "original")
    assert touched == []


def test_mutants_are_deterministic_compile_and_differ():
    src = "int f(int a, int b) {\n  if (a < b) return b - 1;\n  return a + 2;\n}\n"
    first, second = mutants(src, limit=5), mutants(src, limit=5)
    assert [m.text for m in first] == [m.text for m in second] and first
    assert all(normalised(m.text) != normalised(src) for m in first)
    assert {m.operator for m in first} >= {"relational"}


def test_dedup_ignores_comments_and_whitespace():
    kept, dropped = deduplicate({"a": "int f(void){return 1;}", "b": "int f(void) { /* x */ return 1; }",
                                 "c": "int f(void){return 2;}"})
    assert set(kept) == {"a", "c"} and dropped == {"b": "a"}


def test_label_combination_is_conservative():
    agree, cex = DiffResult("agree"), DiffResult("disagree", counterexamples=[{"index": 3, "kind": "output"}])
    assert combine("x", ("ACCEPT", ""), agree).label == "correct"
    conflict = combine("x", ("ACCEPT", ""), cex)
    assert conflict.label == "unknown" and "contradicted" in conflict.flag
    assert combine("x", ("REJECT", ""), agree).label == "incorrect"
    assert combine("x", ("UNDECIDED", ""), cex).label == "incorrect"
    assert combine("x", ("UNDECIDED", ""), agree).label == "unknown"
    assert combine("x", ("UNDECIDED", ""), DiffResult("incomplete")).label == "unknown"


def test_identity_reading_refuses_unconstrained_outputs():
    shape = {"buffers": {"a": "4"}, "alias": "disjoint", "bounds": {}}
    globals_src = "int g;\nint f(int x) { g = x; return x; }\n"
    assert identity_reading(globals_src, "f", shape) is None
    arr = "void h(int a[4]) { a[0] = 1; }\n"
    reading = identity_reading(arr, "h", shape)
    assert reading and "forall(i, 0, 4, out_a[i] == old_a[i])" in reading["ext"]
    assert identity_reading("void k(const int a[4]) { }\n", "k", shape) is None


def test_candidate_generator_is_separate_bounded_and_honest(tmp_path):
    from vwe.eval.candidate_gen import CandidateGenerator
    from vwe.llm import LLMClient, MockProvider
    code = "int add8(int a, int b) { int s = a + b; return s > 255 ? 255 : s; }"
    mock = MockProvider({"candidate": json.dumps({"code": code})}, family="mockfam")
    gen = CandidateGenerator(mock, "m", tmp_path, max_calls=2)
    recs = gen.generate("int add8(int a, int b) { return a + b; }", "saturate", "add8", tmp_path / "c", 3)
    assert [r.status for r in recs] == ["ok", "ok", "budget"] and gen.calls == 2
    assert all(r.origin == "mock" for r in recs[:2])
    assert (tmp_path / "c/llm_mockfam_0.c").read_text() == code
    prov = gen.provenance(recs)
    assert prov["provider_calls"] == 2 and len(prov["prompt_sha256"]) == 64
    import pytest
    with pytest.raises(TypeError):
        CandidateGenerator(LLMClient(mock, "m", cache_dir=tmp_path), "m", tmp_path)
    tree = ast.parse((ROOT / "vwe/eval/candidate_gen.py").read_text())
    imported = {a.name for n in ast.walk(tree) if isinstance(n, (ast.Import, ast.ImportFrom)) for a in n.names}
    modules = {n.module for n in ast.walk(tree) if isinstance(n, ast.ImportFrom)}
    assert not imported & {"RequestContext", "LLMClient", "PromptTemplate", "generate_interpretations"}
    assert not any(m and ("interpret" in m or m.endswith("context")) for m in modules)


def test_unavailable_candidate_provider_writes_nothing(tmp_path):
    from vwe.eval.candidate_gen import CandidateGenerator
    from vwe.llm import AnthropicProvider
    gen = CandidateGenerator(AnthropicProvider("anthropic", "", "UNSET_ENV_FOR_TEST"), "", tmp_path)
    recs = gen.generate("int f(void){return 0;}", "x", "f", tmp_path / "c", 5)
    assert [r.status for r in recs] == ["unavailable"] and not (tmp_path / "c").exists()
