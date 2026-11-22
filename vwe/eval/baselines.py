"""Comparison baselines (T17). Kept out of the production method and its CLI.

B1 tests-only: ACCEPT iff the candidate runs sanitizer-clean (no abort, no hang)
   on profile-bounded random/boundary inputs; otherwise REJECT. The tasks have no
   test oracle, and using P_ref would leak evaluation data, so B1 checks crashes
   and UB only. UNDECIDED only when the harness cannot be built (recorded).
B2 LLM-as-judge: NOT IMPLEMENTED. It sends P1 to an LLM, which CONTRIBUTING.md rule 1
   forbids without exception; it needs an explicit, separately scoped approval.
B3 single strict contract: the full pipeline restricted to the one strict reading
   (no multi-interpretation bracketing). A "no Ext" variant (ext "true") is vetoed by
   the method's scope-agreement check, so it cannot be a faithful pipeline baseline.
B4 regression-only: P1 == P0 outside the strict reading's region, anything allowed
   inside. Such a "reading" is (correctly) discarded by the method's V-2 check, so
   B4 runs the pipeline's own E1 preservation obligation directly after admission
   and P0-only reference-guard certification. Witnesses are not natively replayed.
B3/B4 need a generated strict reading (from P0 and N only); without one they are
UNDECIDED.
"""
from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path
from typing import Any, Callable, Mapping

from ..interpret import GeneratedSet
from .differential import differential
from .labels import identity_reading

NAMES = ("tests_only", "single_contract", "regression_only")
B2_STATUS = "not implemented: requires sending P1 to an LLM, forbidden by CONTRIBUTING.md rule 1"


@dataclass(frozen=True)
class BaselineVerdict:
    baseline: str
    task_id: str
    candidate: str
    decision: str
    reason: str


def tests_only(task_dir: Path, candidate: str, *, samples: int = 1000) -> BaselineVerdict:
    manifest = json.loads((task_dir / "task.json").read_text())
    code = (task_dir / manifest["candidates"][candidate]).read_text()
    # candidate vs itself: an input is "excluded" exactly when the candidate aborts or hangs
    run = differential(code, code, manifest["function"], manifest["caller_domain"], samples=samples)
    if run.status == "unsupported":
        decision, reason = "UNDECIDED", f"harness unsupported: {run.detail}"
    elif run.inputs_excluded or run.status == "reference_undefined":
        decision, reason = "REJECT", f"aborted or hung on {run.inputs_excluded} input(s)"
    else:
        decision, reason = "ACCEPT", f"sanitizer-clean on {run.inputs_run} inputs"
    return BaselineVerdict("tests_only", manifest["task_id"], candidate, decision, reason)


def _strict(generated: GeneratedSet | None) -> Mapping[str, Any] | None:
    if generated is None:
        return None
    return next((m for m in generated.members if m["provenance"].get("prompt") == "strict"), None)


def _preserve_p0(p0: str, function: str, shape: Mapping[str, Any]) -> str | None:
    """'Every output equals P0's' built from P0's signature (None if not expressible)."""
    reading = identity_reading(p0, function, shape)
    return reading["ext"] if reading else None


def single_contract_set(generated: GeneratedSet | None) -> GeneratedSet | None:
    strict = _strict(generated)
    if strict is None:
        return None
    reading = json.loads(json.dumps(strict))
    reading["id"] += ".b3"
    return GeneratedSet(generated.task_id, generated.request_id, (reading,), generated.generation, ())


def regression_only_set(generated: GeneratedSet | None, p0: str, function: str,
                        shape: Mapping[str, Any]) -> GeneratedSet | None:
    strict = _strict(generated)
    keep = _preserve_p0(p0, function, shape) if strict else None
    if strict is None or keep is None:
        return None
    region = " || ".join(f"({c['zone']})" for c in strict["clauses"]) or "false"
    reading = json.loads(json.dumps(strict))
    reading.update(id=strict["id"] + ".b4", ext=keep, reach=region,
                   clauses=[{"zone": region, "behaviour": "true"}])
    return GeneratedSet(generated.task_id, generated.request_id, (reading,), generated.generation, ())


VerifyFn = Callable[[Path, str, GeneratedSet], Mapping[str, Any]]


def pipeline_baseline(name: str, task_dir: Path, candidate: str, generated: GeneratedSet | None,
                      verify_fn: VerifyFn) -> BaselineVerdict:
    manifest = json.loads((task_dir / "task.json").read_text())
    task_id = manifest["task_id"]
    subset = (single_contract_set(generated) if name == "single_contract" else
              regression_only_set(generated, (task_dir / manifest["p0"]).read_text(),
                                  manifest["function"], manifest["caller_domain"]))
    if subset is None:
        return BaselineVerdict(name, task_id, candidate, "UNDECIDED",
                               "no usable generated strict reading for this task")
    data = verify_fn(task_dir, candidate, subset)
    return BaselineVerdict(name, task_id, candidate, data["decision"],
                           f"{data['evidence_class']}: {data['reason']}")


def regression_only(task_dir: Path, candidate: str, generated: GeneratedSet | None, cfg, out: Path) -> BaselineVerdict:
    from ..admission import admit
    from ..harness.generate import Generator
    from ..proof_jobs import run_job
    from ..regions import compute_regions
    from ..tasks import load_pipeline_view
    from ..verdict import Outcome
    task = load_pipeline_view(task_dir)

    def result(decision: str, reason: str) -> BaselineVerdict:
        return BaselineVerdict("regression_only", task.task_id, candidate, decision, reason)

    subset = regression_only_set(generated, task.p0.text, task.function, task.caller_domain)
    if subset is None:
        return result("UNDECIDED", "no usable generated strict reading for this task")
    adm = admit(task, candidate, cfg, out_dir=out / "admission")
    if adm.verdict is not None:
        return result(adm.verdict.decision, f"admission: {adm.reason}")
    if not adm.p0_views or not adm.p1_views or adm.required_library_models:
        return result("UNDECIDED", "admission did not provide qualified views")
    guard = compute_regions(adm.p0_views, task.caller_domain, out / "regions", config=cfg).reference_safe_guard
    if guard is None:
        return result("UNDECIDED", "no certified safe reference guard")
    gen = Generator(adm.p0_views, adm.p1_views, task.caller_domain, config=cfg, reference_guard=guard)
    job = gen.gen_core(out / "e1", subset.members)
    if not job.e1_decisive:
        return result("UNDECIDED", "preservation relation is not decisive")
    outcome = run_job(job, config=cfg).obligation
    if outcome.outcome is Outcome.PROVED:
        return result("ACCEPT", "P1 equals P0 outside the region")
    if outcome.outcome is Outcome.VIOLATED:
        return result("REJECT", "P1 differs from P0 outside the region (solver witness, not replayed)")
    return result("UNDECIDED", outcome.note or "inconclusive")
