"""Compile the emitted jobs and exercise observation layouts with real CBMC."""
from pathlib import Path
import shutil

import pytest

from vwe.c_frontend import analyze
from vwe.harness.generate import Generator
from vwe.harness.layout import HarnessUnsupported
from vwe.tasks import load_pipeline_view
from vwe.tools import cbmc
from vwe.tools.frontend import execute
from vwe.views import make_views

ROOT = Path(__file__).resolve().parents[1]
EXAMPLES = ROOT / "examples" / "tasks"
REAL = pytest.mark.skipif(not cbmc.cbmc_available() or not shutil.which("goto-cc"),
                         reason="CBMC and goto-cc required")


def example(name, variant, out):
    folder = EXAMPLES / name
    task = load_pipeline_view(folder)
    p0 = make_views(folder / "p0.c", task.function, out / "p0", prefix="p0")
    p1 = make_views(folder / "candidates" / f"v{variant}.c", task.function,
                    out / "p1", prefix="p1")
    guard = "n > 0" if name == "ex2_argmax" else "true"
    return task, Generator(p0, p1, task.caller_domain, reference_guard=guard)


def solve(bundle, backend="sat"):
    result = cbmc.run([str(p) for p in bundle.files], backend=backend, unwind=bundle.unwind,
                      watch=bundle.watch, timeout_s=60, cwd=str(bundle.folder))
    assert result.ok, result.stderr_tail + result.stdout[-2000:]
    return result


def test_local_struct_cannot_override_public_tag():
    old = analyze("struct S {int x;}; struct S f(void) {struct S s={0}; return s;}", "f")
    new = analyze("struct S {long x;}; struct S f(void) {struct S s={0}; "
                  "{struct S {int x;} local={0}; s.x=local.x;} return s;}", "f")
    assert old.signature != new.signature


@REAL
def test_all_job_kinds_compile(tmp_path):
    task, gen = example("ex2_argmax", 1, tmp_path)
    it = task.interpretations[0]
    for bundle in (
        gen.gen_core(tmp_path / "e0", (it,), part="e0"),
        gen.gen_core(tmp_path / "e1", (it,)),
        gen.gen_class(tmp_path / "class", it),
        gen.gen_vacuity(tmp_path / "vacuity", (it,)),
        gen.gen_reference(tmp_path / "reference", (it,), domain="e1_keep"),
        gen.gen_determinism(tmp_path / "candidate_det", "p1"),
        gen.gen_views_equiv(tmp_path / "views"),
        gen.gen_contract_ub(tmp_path / "vg", it),
    ):
        result = execute(["goto-cc", *map(str, bundle.files), "-o", "job.goto"],
                         cwd=bundle.folder, timeout_s=30)
        assert result.ok, result.stderr
        assert not bundle.ready_for_decision
    result = solve(gen.gen_vacuity(tmp_path / "run_vacuity", (it,)))
    failures = {p.description: p.witness for p in result.failed()}
    assert set(failures) == {"VWE.vacuity.keep", "VWE.vacuity.zone.0.0"}
    assert failures["VWE.vacuity.zone.0.0"]["__vwe_in_scalar_1_0"] == "0"


@REAL
def test_smaller_shape_is_checked_separately(tmp_path):
    task, gen = example("ex4_sum", 1, tmp_path)
    invalid = next(i for i in task.interpretations if "invalid" in i["id"])
    with pytest.raises(HarnessUnsupported, match="separate exact-profile"):
        gen.gen_class(tmp_path / "bad_request", invalid)
    smaller = Generator(gen.p0, gen.p1, invalid["shape"])
    bundle = smaller.gen_contract_ub(tmp_path / "vg_bad", invalid)
    assert bundle.profile_sha256 != gen.profile.sha256
    for backend in ("sat", "z3"):
        run = solve(bundle, backend)
        assert run.failed(lambda p: p.property_id.startswith("vwe_observer_"))


@REAL
def test_struct_pointer_and_global_observations(tmp_path):
    # Same logical pointer in separate allocations compares equal. A field or a
    # byte-offset change must remain visible even with identical return scalars.
    body = ("struct R {int *ptr; int val;}; int g[2]; "
            "struct R f(int *a, int n) {struct R r; r.ptr=a%s; r.val=n; "
            "g[1]=%s; return r;}")
    views = []
    for index, offsets in enumerate((("", "n"), ("", "n"), ("+1", "n"), ("", "0"))):
        src = tmp_path / f"source{index}.c"
        src.write_text(body % offsets)
        views.append(make_views(src, "f", tmp_path / f"view{index}", prefix=f"p{index}"))
    shape = {"buffers": {"a": "n"}, "alias": "disjoint", "bounds": {"n": [1, 2]}}
    it = {"shape": shape, "clauses": [], "reach": "false", "ext": "false"}
    for index, expected in enumerate(("success", "failure", "failure"), start=1):
        gen = Generator(views[0], views[index], shape)
        run = solve(gen.gen_class(tmp_path / f"job{index}", it))
        assert run.status == expected
        assert all(p.description == "VWE.class.preservation" for p in run.failed())


@REAL
def test_synthesis_view_change_detected(tmp_path):
    src = tmp_path / "source.c"
    src.write_text("int f(int n) {\n#ifdef __SYNTHESIS__\nreturn 0;\n#else\nreturn n;\n#endif\n}")
    views = make_views(src, "f", tmp_path / "views", prefix="p1")
    shape = {"buffers": {}, "alias": "disjoint", "bounds": {}}
    gen = Generator(views, views, shape)
    assert [p.description for p in solve(gen.gen_views_equiv(tmp_path / "job")).failed()] == [
        "VWE.views.equivalence"
    ]
