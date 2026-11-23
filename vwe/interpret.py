"""Automatic interpretation generation (draft Stage 2).

Inputs are P0 and N only, through RequestContext. The caller profile in the task
manifest is explicit user-supplied domain information (not derived from any
candidate); it is offered as the shape candidate and is written into every
generated reading, with the model's own shape retained in the record. Readings are
conditional formalisations: logical validity later does not prove English adequacy.
"""
from __future__ import annotations

from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path
from typing import Any, Mapping, Sequence

from jsonschema import ValidationError

from .harness.profile import plain
from .llm import GenerationResult, LLMClient, RequestContext
from .llm.prompt_files import PROMPT_NAMES, load_prompt
from .schemas import validate as validate_schema
from .tasks import PipelineTask
from .validate import canonical


@dataclass(frozen=True)
class GeneratedSet:
    task_id: str
    request_id: str
    members: tuple[Mapping[str, Any], ...]
    generation: Mapping[str, Any]
    records: tuple[Mapping[str, Any], ...]

    @property
    def sha256(self) -> str:
        return sha256(canonical(list(self.members))).hexdigest()

    def as_json(self) -> dict[str, Any]:
        return {"task_id": self.task_id, "request_id": self.request_id, "sha256": self.sha256,
                "members": list(self.members), "generation": dict(self.generation),
                "records": list(self.records)}


def _record(client: LLMClient, prompt: str, run: int, result: GenerationResult,
            **extra: Any) -> dict[str, Any]:
    return {"family": client.provider.family, "prompt": prompt, "run_index": run,
            "status": result.status, "detail": result.detail,
            "origins": [a.origin for a in result.attempts], "live": result.live,
            "provenance": dict(result.provenance), **extra}


def _finish_reading(raw: Mapping[str, Any], task_id: str, client: LLMClient, prompt: str,
                    run: int, shape: Mapping[str, Any], request_type: str | None) -> dict[str, Any] | None:
    reading = json.loads(json.dumps(raw))
    reading["id"] = f"{task_id}.{client.provider.family}.{prompt}.{run}"
    reading["provenance"] = {"source": "llm", "model_family": client.provider.family,
                             "model_id": client.model_id, "prompt": prompt, "run_index": run}
    reading["shape"] = dict(shape)
    if "request_type" not in reading and request_type:
        reading["request_type"] = request_type
    try:
        validate_schema("interpretation", reading)
    except ValidationError:
        return None
    return reading


def generate_interpretations(task: PipelineTask, clients: Sequence[LLMClient], *,
                             request_id: str | None = None, runs: int = 1,
                             out_dir: Path | None = None) -> GeneratedSet:
    if not clients:
        raise ValueError("at least one LLM client is required")
    if runs < 1:
        raise ValueError("runs must be positive")
    rid = request_id or task.requests[0].id
    shape = plain(task.caller_domain)
    base = RequestContext.from_task(task, rid).with_shapes((json.dumps(shape, sort_keys=True),))
    prompts = {name: load_prompt(name) for name in PROMPT_NAMES}
    members: list[dict[str, Any]] = []
    records: list[dict[str, Any]] = []
    for client in clients:
        typed = client.generate(base, prompts["typing"], schema_name="request_typing")
        records.append(_record(client, "typing", 0, typed))
        rtype = typed.parsed["type"] if typed.parsed else None
        proposal = client.generate(base, prompts["shape"], schema_name="shape_proposal")
        agree = (proposal.parsed is not None
                 and dict(proposal.parsed["buffers"]) == {k: str(v) for k, v in shape.get("buffers", {}).items()})
        records.append(_record(client, "shape", 0, proposal, agrees_with_caller_profile=agree))
        for run in range(runs):
            renderings: list[str] = []
            for name in ("strict", "permissive"):
                result = client.generate(base, prompts[name], run_index=run)
                reading = (_finish_reading(result.parsed, task.task_id, client, name, run, shape, rtype)
                           if result.parsed else None)
                records.append(_record(client, name, run, result, accepted=reading is not None,
                                       model_shape_replaced=bool(
                                           reading and result.parsed and result.parsed.get("shape") != reading["shape"])))
                if reading:
                    members.append(reading)
                    if name == "strict" and reading.get("nl_rendering"):
                        renderings.append(reading["nl_rendering"])
            if renderings:  # the adversarial prompt sees English renderings only
                ctx = base.with_prior_readings(tuple(renderings))
                result = client.generate(ctx, prompts["adversarial"], run_index=run)
                reading = (_finish_reading(result.parsed, task.task_id, client, "adversarial", run, shape, rtype)
                           if result.parsed else None)
                records.append(_record(client, "adversarial", run, result, accepted=reading is not None))
                if reading:
                    members.append(reading)
            else:
                records.append({"family": client.provider.family, "prompt": "adversarial",
                                "run_index": run, "status": "skipped",
                                "detail": "no strict reading with an English rendering"})
    families = sorted({c.provider.family for c in clients})
    live = sorted({r["family"] for r in records if r.get("live") and r.get("status") == "ok"})
    generation = {"runs": runs, "families": families, "p1_seen_by_any_llm": False,
                  "live_families": live,
                  "independent_live_family_count": len(live),
                  "prompts": {n: {"version": p.version, "sha256": p.sha256} for n, p in prompts.items()},
                  "shape_policy": "caller profile copied into every reading; model shape retained in records"}
    result_set = GeneratedSet(task.task_id, rid, tuple(members), generation, tuple(records))
    if out_dir is not None:
        write_generated(result_set, out_dir)
    return result_set


def write_generated(generated: GeneratedSet, out_dir: Path) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "generated_set.json").write_text(json.dumps(generated.as_json(), indent=2) + "\n")
    (out_dir / "interpretations.md").write_text(explain(generated))


def load_generated(path: Path) -> GeneratedSet:
    doc = json.loads(Path(path).read_text(encoding="utf-8"))
    members = tuple(doc["members"])
    for m in members:
        validate_schema("interpretation", m)
    result = GeneratedSet(doc["task_id"], doc["request_id"], members, doc["generation"],
                          tuple(doc["records"]))
    if result.sha256 != doc["sha256"]:
        raise ValueError("generated set hash mismatch")
    return result


def explain(generated: GeneratedSet) -> str:
    g = generated.generation
    lines = [f"# Generated interpretations for `{generated.task_id}` (request `{generated.request_id}`)", "",
             f"Set hash: `{generated.sha256}`. Families: {', '.join(g['families'])}. "
             f"Families answered live in this run: {', '.join(g['live_families']) or 'none'}.",
             "No candidate or evaluation data was sent to any model. These are conditional "
             "readings; validity checks do not prove they match the English request.", ""]
    for m in generated.members:
        p = m["provenance"]
        lines += [f"## {m['id']}", f"- source: {p['source']} / {p.get('model_family')} / prompt {p.get('prompt')}",
                  f"- reading: {m.get('nl_rendering', '(none)')}"]
        lines += [f"- when `{c['zone']}`: `{c['behaviour']}`" for c in m["clauses"]]
        lines += [f"- elsewhere: `{m['ext']}`", f"- reach: `{m['reach']}`", ""]
    problems = [r for r in generated.records if r["status"] != "ok" or r.get("accepted") is False]
    if problems:
        lines += ["## Generation problems", ""]
        lines += [f"- {r['family']}/{r['prompt']}#{r['run_index']}: {r['status']} — {r['detail']}" for r in problems]
    return "\n".join(lines) + "\n"
