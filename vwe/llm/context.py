"""The only object from which an LLM prompt may be built.

CONTRIBUTING.md rule 1: no LLM receives P1 or anything derived from it. This record
has no field for candidates, and its constructor reads exactly three things from
a task: the chosen request text, P0, and the function name. It never touches
``task.candidates``, ``task.interpretations`` or evaluation data.
"""
from __future__ import annotations

from dataclasses import dataclass, replace
import json
from typing import Any

from pycparser import c_ast as C, c_generator

from ..c_frontend import UnsupportedC, analyze, without_comments
from ..tasks import PipelineTask


class ContextError(ValueError):
    """A request context cannot be built from P0 and the request alone."""


@dataclass(frozen=True)
class RequestContext:
    """Immutable, P1-free prompt input: request text, P0 signature, shape candidates."""
    task_id: str
    request_id: str
    request_text: str
    signature: str
    shape_candidates: tuple[str, ...] = ()
    prior_readings: tuple[str, ...] = ()  # English renderings generated from P0 and N only

    @classmethod
    def from_task(cls, task: PipelineTask, request_id: str) -> "RequestContext":
        if type(task) is not PipelineTask:
            raise ContextError("RequestContext requires a PipelineTask (never a FullTask)")
        matches = [r for r in task.requests if r.id == request_id]
        if len(matches) != 1:
            raise ContextError(f"Unknown request id {request_id!r}")
        return cls(task.task_id, request_id, matches[0].text,
                   p0_signature_text(task.p0.text, task.function))

    def with_shapes(self, shapes: tuple[str, ...]) -> "RequestContext":
        """Add certified/model shape candidates; they derive from P0 and N only."""
        if not all(isinstance(s, str) for s in shapes):
            raise ContextError("shape candidates must be strings")
        return replace(self, shape_candidates=tuple(shapes))

    def with_prior_readings(self, readings: tuple[str, ...]) -> "RequestContext":
        """Add English renderings of earlier readings (adversarial prompt input)."""
        if not all(isinstance(r, str) for r in readings):
            raise ContextError("prior readings must be strings")
        return replace(self, prior_readings=tuple(readings))

    def canonical(self) -> dict[str, Any]:
        return {"task_id": self.task_id, "request_id": self.request_id,
                "request_text": self.request_text, "signature": self.signature,
                "shape_candidates": list(self.shape_candidates),
                "prior_readings": list(self.prior_readings)}

    def placeholders(self) -> dict[str, str]:
        """The complete set of values a prompt template may substitute."""
        return {"request_text": self.request_text, "signature": self.signature,
                "shape_candidates": json.dumps(list(self.shape_candidates)),
                "prior_readings": json.dumps(list(self.prior_readings))}


def _preprocessed(p0_source: str) -> str:
    """Expand P0's own macros with the qualified frontend wrapper (P0 only)."""
    import tempfile
    from pathlib import Path
    from ..tools import frontend
    with tempfile.TemporaryDirectory(prefix="vwe-ctx-") as tmp:
        src = Path(tmp) / "p0.c"
        src.write_text(p0_source, encoding="utf-8")
        text, _, how = frontend.preprocess(src, synth=False, timeout_s=60)
    if how == "failed":
        raise ContextError("P0 signature unavailable: preprocessing failed")
    return text


def p0_signature_text(p0_source: str, function: str) -> str:
    """Render the P0 function declaration (no body, no comments); macro sizes appear expanded."""
    try:
        analysis = analyze(without_comments(p0_source), function)
    except UnsupportedC:
        try:
            analysis = analyze(_preprocessed(p0_source), function)
        except UnsupportedC as exc:
            raise ContextError(f"P0 signature unavailable: {exc}") from exc
    for node in analysis.ast.ext:
        if isinstance(node, C.FuncDef) and node.decl.name == function:
            return c_generator.CGenerator().visit(node.decl) + ";"
    raise ContextError(f"function {function!r} not found in P0")
