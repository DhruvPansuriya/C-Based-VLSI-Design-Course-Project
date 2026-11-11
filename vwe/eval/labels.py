"""Ground-truth labels for candidate pools (T16).

Two checks, combined conservatively:

* formal: the pipeline's own obligations with P_ref in the reference role: admission,
  P_ref-only region certification, E0 (candidate safe on the certified guard) and E1
  with an identity relation and an empty change region (every output equals P_ref's
  everywhere on the guard). ACCEPT = both PROVED; REJECT = a violation that
  reproduces with its inputs fixed. (Running the full method instead is wrong: its
  V-2 check correctly discards a reading that P0 = P_ref already satisfies.)
* differential: native sanitizer testing against P_ref (vwe.eval.differential).

correct   = formal ACCEPT and no differential counterexample
incorrect = formal REJECT, or a differential counterexample while formal is not ACCEPT
unknown   = everything else, including formal ACCEPT contradicted by testing (flagged)

The formal check reuses the verifier being evaluated, so a defect shared by both
would be invisible to it; the independent native check exists to reduce that risk.
Labels describe the bounded, value-profiled domain, not unrestricted inputs.
"""
from __future__ import annotations

from dataclasses import asdict, dataclass
import json
from pathlib import Path
from typing import Any, Callable, Mapping

from pycparser import c_ast as C, c_parser

from ..c_frontend import analyze
from ..harness.profile import plain
from .differential import DiffResult, _preprocess, differential


@dataclass(frozen=True)
class Label:
    candidate: str
    label: str  # correct | incorrect | unknown
    formal: str
    formal_reason: str
    differential: str
    counterexample: Mapping[str, Any] | None
    flag: str = ""


def identity_reading(p_ref: str, fn: str, shape: Mapping[str, Any]) -> dict[str, Any] | None:
    """'Every observable output equals P_ref's' — or None if outputs are not all expressible."""
    pre = _preprocess(p_ref)
    analysis = analyze(pre, fn)
    if any(role == "input_output" for _, role in analysis.globals):
        return None  # mutable globals are outputs the identity relation would not constrain
    fdef = next(n for n in c_parser.CParser().parse(pre).ext
                if isinstance(n, C.FuncDef) and n.decl.name == fn)
    parts = []
    ret = fdef.decl.type.type
    if not (isinstance(ret, C.TypeDecl) and getattr(ret.type, "names", None) == ["void"]):
        parts.append("out_ret == old_ret")
    for p in (fdef.decl.type.args.params if fdef.decl.type.args else []):
        if isinstance(p.type, C.ArrayDecl) and "const" not in (p.type.type.quals or []):
            size = shape["buffers"][p.name]
            parts.append(f"forall(i, 0, {size}, out_{p.name}[i] == old_{p.name}[i])")
    if not parts:
        return None
    equal = " && ".join(parts)
    return {"id": "label.identity", "provenance": {"source": "computed", "computed_kind": "T5_identity"},
            "request_type": "T5", "shape": plain(shape),
            "clauses": [{"zone": "true", "behaviour": equal}], "ext": equal, "reach": "true",
            "nl_rendering": "Outputs equal the reference implementation's on every input."}


def formal_identity(task_dir: Path, candidate: str, cfg, out: Path) -> tuple[str, str]:
    """Bounded formal equivalence of a candidate with P_ref (see module docstring)."""
    from dataclasses import replace
    from ..admission import admit
    from ..harness.generate import Generator
    from ..proof_jobs import run_job
    from ..regions import compute_regions
    from ..replay import bind_inputs
    from ..tasks import SourceFile, load_full
    from ..verdict import Outcome
    full = load_full(task_dir)
    task = replace(full.pipeline, p0=SourceFile("p_ref.c", full.eval_only.p_ref.text, full.eval_only.p_ref.sha256))
    reading = identity_reading(task.p0.text, task.function, task.caller_domain)
    if reading is None:
        return "UNDECIDED", "outputs not expressible as an identity relation"
    reading = {**reading, "clauses": [{"zone": "false", "behaviour": "true"}], "reach": "false"}
    adm = admit(task, candidate, cfg, out_dir=out / "admission")
    if adm.verdict is not None:
        return adm.verdict.decision if adm.verdict.claim_target == "admission_policy" else "UNDECIDED", \
            f"admission: {adm.reason}"
    if not adm.p0_views or not adm.p1_views or adm.required_library_models:
        return "UNDECIDED", "admission did not provide qualified views"
    guard = compute_regions(adm.p0_views, task.caller_domain, out / "regions", config=cfg).reference_safe_guard
    if guard is None:
        return "UNDECIDED", "no certified safe reference guard for P_ref"
    gen = Generator(adm.p0_views, adm.p1_views, task.caller_domain, config=cfg, reference_guard=guard)
    for part in ("e0", "e1"):
        job = gen.gen_core(out / part, (reading,) if part == "e1" else (), part=part)
        result = run_job(job, config=cfg).obligation
        if result.outcome is Outcome.INCONCLUSIVE:
            return "UNDECIDED", f"{part}: {result.note}"
        if result.outcome is Outcome.VIOLATED:
            if result.witness is None:
                return "UNDECIDED", f"{part}: violation without an input trace"
            again = run_job(bind_inputs(job, result.witness, out / f"{part}_fixed"), config=cfg).obligation
            if again.outcome is not Outcome.VIOLATED:
                return "UNDECIDED", f"{part}: violation did not reproduce with fixed inputs"
            return "REJECT", f"{part}: differs from P_ref or unsafe (fixed-input confirmed)"
    return "ACCEPT", f"equal to P_ref on certified guard {guard}"


def combine(candidate: str, formal: tuple[str, str], diff: DiffResult) -> Label:
    decision, reason = formal
    cex = diff.counterexamples[0] if diff.counterexamples else None
    if decision == "ACCEPT" and diff.status == "agree":
        return Label(candidate, "correct", decision, reason, diff.status, None)
    if decision == "ACCEPT" and cex is not None:
        return Label(candidate, "unknown", decision, reason, diff.status, cex,
                     flag="formal ACCEPT contradicted by native testing: investigate")
    if decision == "REJECT":
        return Label(candidate, "incorrect", decision, reason, diff.status, cex)
    if cex is not None:
        return Label(candidate, "incorrect", decision, reason, diff.status, cex)
    return Label(candidate, "unknown", decision, reason, diff.status, None)


FormalFn = Callable[[Path, str], tuple[str, str]]


def label_pool(task_dir: Path, pool: Mapping[str, str], formal_fn: FormalFn, *,
               samples: int = 10000) -> list[Label]:
    """formal_fn(task_dir, candidate) is normally `formal_identity` with a config."""
    manifest = json.loads((task_dir / "task.json").read_text())
    p_ref = (task_dir / manifest["eval_only"]["p_ref"]).read_text()
    labels = []
    for name, text in pool.items():
        formal = formal_fn(task_dir, name)
        diff = differential(p_ref, text, manifest["function"], manifest["caller_domain"], samples=samples)
        labels.append(combine(name, formal, diff))
    return labels


def as_json(labels: list[Label]) -> list[dict[str, Any]]:
    return [asdict(l) for l in labels]
