"""Task loading with explicit pipeline/evaluation data separation.

The pipeline receives immutable in-memory snapshots, never an evaluation directory
or a FullTask. This is an API boundary, not an OS sandbox for arbitrary Python.
"""
from __future__ import annotations
from dataclasses import dataclass
from hashlib import sha256
import json
from pathlib import Path, PurePosixPath
from types import MappingProxyType
from typing import Any, Mapping
from jsonschema import ValidationError
from .schemas import validate


class TaskError(ValueError):
    """A task cannot be loaded without escaping its declared input boundary."""


@dataclass(frozen=True)
class SourceFile:
    relative_path: str
    text: str
    sha256: str


@dataclass(frozen=True)
class Request:
    id: str
    text: str
    origin: str


@dataclass(frozen=True)
class Candidate:
    id: str
    source: SourceFile


@dataclass(frozen=True)
class PipelineTask:
    task_id: str
    function: str
    p0: SourceFile
    requests: tuple[Request, ...]
    candidates: Mapping[str, Candidate]
    interpretations: tuple[Mapping[str, Any], ...]
    caller_domain: Mapping[str, Any]


@dataclass(frozen=True)
class EvaluationData:
    p_ref: SourceFile
    phi_ref: SourceFile
    true_shape: Mapping[str, Any]
    true_change_zone: str | None
    acceptable_readings: Mapping[str, tuple[str, ...]]


@dataclass(frozen=True)
class FullTask:
    pipeline: PipelineTask
    eval_only: EvaluationData


def _freeze(value: Any) -> Any:
    if isinstance(value, dict):
        return MappingProxyType({k: _freeze(v) for k, v in value.items()})
    if isinstance(value, list):
        return tuple(_freeze(v) for v in value)
    return value


def _object(pairs: list[tuple[str, Any]]) -> dict[str, Any]:
    out: dict[str, Any] = {}
    for k, v in pairs:
        if k in out:
            raise TaskError(f"Duplicate JSON key {k!r}")
        out[k] = v
    return out


def _json(path: Path) -> dict[str, Any]:
    try:
        def invalid_constant(value: str) -> None:
            raise TaskError(f"Invalid JSON constant {value}")
        value = json.loads(path.read_text(encoding="utf-8"), object_pairs_hook=_object,
                           parse_constant=invalid_constant)
    except (OSError, UnicodeError, json.JSONDecodeError) as exc:
        raise TaskError(f"Cannot read JSON {path.name}: {exc}") from exc
    if not isinstance(value, dict):
        raise TaskError(f"{path.name} must be a JSON object")
    return value


def _resolve(root: Path, relative: str, *, evaluation: bool = False) -> Path:
    p = PurePosixPath(relative)
    if not relative or p.is_absolute() or ".." in p.parts or "\\" in relative or ":" in relative:
        raise TaskError(f"Expected a contained relative POSIX path: {relative!r}")
    if not p.parts or (p.parts[0] == "eval") != evaluation:
        raise TaskError(f"Path is in the wrong data partition: {relative!r}")
    try:
        resolved = (root / relative).resolve(strict=True)
        resolved.relative_to(root)
        if not resolved.is_file():
            raise TaskError(f"Not a regular file: {relative!r}")
        eval_root = (root / "eval").resolve()
        inside_eval = resolved.is_relative_to(eval_root)
        if inside_eval != evaluation:
            raise TaskError(f"Symlink crosses the data partition: {relative!r}")
    except (OSError, ValueError, RuntimeError) as exc:
        if isinstance(exc, TaskError):
            raise
        raise TaskError(f"Unsafe or missing task file: {relative!r}") from exc
    return resolved


def _source(root: Path, relative: str, *, evaluation: bool = False) -> SourceFile:
    path = _resolve(root, relative, evaluation=evaluation)
    try:
        data = path.read_bytes()
        text = data.decode("utf-8")
    except (OSError, UnicodeError) as exc:
        raise TaskError(f"Cannot read UTF-8 source {relative!r}") from exc
    return SourceFile(relative, text, sha256(data).hexdigest())


def _manifest(path: str | Path) -> tuple[Path, dict[str, Any]]:
    root = Path(path).resolve()
    doc = _json(_resolve(root, "task.json"))
    try:
        validate("task", doc)
    except ValidationError as exc:
        raise TaskError(f"Invalid task manifest: {exc.message}") from exc
    return root, doc


def _pipeline(root: Path, doc: dict[str, Any]) -> PipelineTask:
    requests: list[Request] = []
    ids: set[str] = set()
    for item in doc["requests"]:
        if item["id"] in ids:
            raise TaskError(f"Duplicate request id {item['id']!r}")
        ids.add(item["id"])
        text = item["text"] if "text" in item else _source(root, item["file"]).text
        requests.append(Request(item["id"], text, item["origin"]))
    candidates = {
        cid: Candidate(cid, _source(root, file))
        for cid, file in sorted(doc["candidates"].items())
    }
    readings: list[Mapping[str, Any]] = []
    seen: set[str] = set()
    for file in doc["interpretations"]:
        reading = _json(_resolve(root, file))
        try:
            validate("interpretation", reading)
        except ValidationError as exc:
            raise TaskError(f"Invalid interpretation {file}: {exc.message}") from exc
        if reading["id"] in seen:
            raise TaskError(f"Duplicate interpretation id {reading['id']!r}")
        seen.add(reading["id"])
        readings.append(_freeze(reading))
    return PipelineTask(doc["task_id"], doc["function"], _source(root, doc["p0"]),
                        tuple(requests), MappingProxyType(candidates), tuple(readings),
                        _freeze(doc["caller_domain"]))


def load_pipeline_view(path: str | Path) -> PipelineTask:
    """Load allowlisted inputs; never open an eval/ file or retain eval metadata."""
    root, doc = _manifest(path)
    return _pipeline(root, doc)


def load_full(path: str | Path) -> FullTask:
    """Evaluation-only entry point; no production pipeline may call this."""
    root, doc = _manifest(path)
    ev = doc["eval_only"]
    oracle = EvaluationData(
        _source(root, ev["p_ref"], evaluation=True),
        _source(root, ev["phi_ref"], evaluation=True),
        _freeze(ev["true_shape"]), ev.get("true_change_zone"),
        MappingProxyType({r["id"]: tuple(r.get("acceptable_readings", ())) for r in doc["requests"]}),
    )
    return FullTask(_pipeline(root, doc), oracle)
