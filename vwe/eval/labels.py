"""Ground-truth labels for candidate pools (T16).

Two checks, combined conservatively:

* formal: the VWE pipeline run on a *labelling task* whose P0 is P_ref and whose
  only reading is identity ("every output equals P_ref's", zone true). ACCEPT means
  equal to P_ref on the certified-safe part of the bounded caller profile; REJECT
  comes with a fixed-input-confirmed, natively replayed witness.
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
import shutil
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


def write_labelling_task(task_dir: Path, pool: Mapping[str, str], out: Path) -> Path | None:
    """A throwaway task: P0 := P_ref, candidates := pool, one identity reading."""
    manifest = json.loads((task_dir / "task.json").read_text())
    p_ref = (task_dir / manifest["eval_only"]["p_ref"]).read_text()
    reading = identity_reading(p_ref, manifest["function"], manifest["caller_domain"])
    if reading is None:
        return None
    if out.exists():
        shutil.rmtree(out)
    (out / "candidates").mkdir(parents=True)
    (out / "eval").mkdir()
    (out / "interpretations").mkdir()
    (out / "p0.c").write_text(p_ref)
    (out / "eval/p_ref.c").write_text(p_ref)
    (out / "eval/phi_ref.c").write_text("/* identity with P_ref */\n")
    (out / "request.txt").write_text("Behave exactly like the reference implementation.\n")
    (out / "interpretations/identity.json").write_text(json.dumps(reading, indent=2))
    for name, text in pool.items():
        (out / f"candidates/{name}.c").write_text(text)
    labelling = {
        "task_id": manifest["task_id"] + "__label", "source": manifest["source"],
        "function": manifest["function"], "p0": "p0.c",
        "requests": [{"id": "original", "file": "request.txt", "origin": "injection_test"}],
        "candidates": {name: f"candidates/{name}.c" for name in pool},
        "interpretations": ["interpretations/identity.json"],
        "caller_domain": manifest["caller_domain"],
        "eval_only": {"p_ref": "eval/p_ref.c", "phi_ref": "eval/phi_ref.c",
                      "true_shape": manifest["caller_domain"]}}
    (out / "task.json").write_text(json.dumps(labelling, indent=2))
    return out


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


def label_pool(task_dir: Path, pool: Mapping[str, str], work: Path, formal_fn: FormalFn, *,
               samples: int = 10000) -> list[Label]:
    manifest = json.loads((task_dir / "task.json").read_text())
    p_ref = (task_dir / manifest["eval_only"]["p_ref"]).read_text()
    label_task = write_labelling_task(task_dir, pool, work / "label_task")
    labels = []
    for name, text in pool.items():
        formal = (formal_fn(label_task, name) if label_task is not None
                  else ("UNDECIDED", "outputs not expressible as an identity reading"))
        diff = differential(p_ref, text, manifest["function"], manifest["caller_domain"], samples=samples)
        labels.append(combine(name, formal, diff))
    return labels


def as_json(labels: list[Label]) -> list[dict[str, Any]]:
    return [asdict(l) for l in labels]
