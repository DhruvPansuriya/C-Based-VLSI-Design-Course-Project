"""Provider-neutral, cached, schema-enforcing LLM client.

Every provider call is cached individually (so a retry sequence replays
exactly). The client never substitutes mock output for a live provider: the
origin of every attempt is recorded and ``GenerationResult.live`` is true only
when every attempt was answered by a live provider during this execution.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from datetime import datetime, timezone
from hashlib import sha256
import json
import os
from pathlib import Path
import re
from string import Template
import tempfile
from typing import Any, Mapping, Protocol, Sequence

from jsonschema import ValidationError

from .context import RequestContext
from ..schemas import load as load_schema, validate as validate_schema

CACHE_FORMAT = 1
_TEMPLATE_NAMES = {"request_text", "signature", "shape_candidates", "prior_readings"}


class ProviderUnavailable(RuntimeError):
    """No usable provider: missing key, model id, SDK or network. Never retried."""


class ProviderError(RuntimeError):
    """The provider responded but not with usable text."""


class CacheMiss(LookupError):
    """Offline mode and the exact request is not cached."""


@dataclass(frozen=True)
class Message:
    role: str  # "system" | "user" | "assistant"
    content: str


class Provider(Protocol):
    name: str          # adapter name, e.g. "mock", "anthropic"
    family: str        # model family label recorded in provenance
    is_live: bool      # False for mocks: output must never be called live

    def complete(self, messages: Sequence[Message], json_schema: Mapping[str, Any] | None,
                 model_id: str, temperature: float, seed: int | None,
                 label: str = "") -> str: ...


@dataclass(frozen=True)
class PromptTemplate:
    """Versioned prompt. Only ``${request_text}``, ``${signature}`` and
    ``${shape_candidates}`` may be substituted, so only RequestContext data can enter."""
    name: str
    version: str
    system: str
    user: str

    def __post_init__(self) -> None:
        for text in (self.system, self.user):
            for m in Template.pattern.finditer(text):
                if m.group("invalid") is not None:
                    raise ValueError(f"{self.name}: invalid placeholder syntax")
                key = m.group("named") or m.group("braced")
                if key is not None and key not in _TEMPLATE_NAMES:
                    raise ValueError(f"{self.name}: placeholder {key!r} is not RequestContext data")

    @property
    def sha256(self) -> str:
        blob = json.dumps([self.name, self.version, self.system, self.user])
        return sha256(blob.encode()).hexdigest()

    def render(self, context: RequestContext) -> tuple[Message, ...]:
        if type(context) is not RequestContext:
            raise TypeError("prompts can only be rendered from a RequestContext")
        values = context.placeholders()
        # Values are inserted literally: Template does not re-scan substituted text.
        return (Message("system", Template(self.system).substitute(values)),
                Message("user", Template(self.user).substitute(values)))


@dataclass(frozen=True)
class Attempt:
    request_key: str
    raw: str | None
    error: str | None
    origin: str  # live | mock | cache:live | cache:mock


@dataclass(frozen=True)
class GenerationResult:
    status: str  # ok | failed | unavailable | cache_miss
    parsed: Mapping[str, Any] | None
    attempts: tuple[Attempt, ...]
    detail: str
    provenance: Mapping[str, Any] = field(default_factory=dict)

    @property
    def live(self) -> bool:
        return bool(self.attempts) and all(a.origin == "live" for a in self.attempts)


def _canonical(value: Any) -> str:
    return json.dumps(value, sort_keys=True, separators=(",", ":"), ensure_ascii=True)


def _parse_json(raw: str) -> Any:
    text = raw.strip()
    fenced = re.fullmatch(r"```(?:json)?\s*(.*?)\s*```", text, re.S)
    return json.loads(fenced.group(1) if fenced else text)


class LLMClient:
    def __init__(self, provider: Provider, model_id: str, *, cache_dir: Path | None = None,
                 offline: bool = False, max_retries: int = 2, temperature: float = 0.0,
                 seed: int | None = None, log_path: Path | None = None) -> None:
        if not 0 <= max_retries <= 2:
            raise ValueError("max_retries must be 0..2")
        if offline and cache_dir is None:
            raise ValueError("offline mode requires a cache directory")
        self.provider, self.model_id = provider, model_id
        self.cache_dir = Path(cache_dir).expanduser() if cache_dir else None
        self.offline, self.max_retries = offline, max_retries
        self.temperature, self.seed = temperature, seed
        self.log_path = log_path

    def _seed(self, offset: int) -> int | None:
        """Per-run seed: base seed plus run index (a request parameter, not a guarantee)."""
        return None if self.seed is None else self.seed + offset

    # --- cache -------------------------------------------------------------
    def request_key(self, messages: Sequence[Message], schema_hash: str, run_index: int,
                    label: str, seed_offset: int = 0) -> str:
        return sha256(_canonical({
            "cache_format": CACHE_FORMAT, "provider": self.provider.name,
            "family": self.provider.family, "model_id": self.model_id,
            "messages": [[m.role, m.content] for m in messages], "schema": schema_hash,
            "temperature": self.temperature, "seed": self._seed(seed_offset),
            "run_index": run_index, "label": label}).encode()).hexdigest()

    def _cache_path(self, key: str) -> Path | None:
        return self.cache_dir / f"{key}.json" if self.cache_dir else None

    def _read_cache(self, key: str) -> dict[str, Any] | None:
        path = self._cache_path(key)
        if path is None or not path.is_file():
            return None
        try:
            entry = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return None
        ok = (isinstance(entry, dict) and entry.get("cache_format") == CACHE_FORMAT
              and entry.get("key") == key and isinstance(entry.get("raw"), str))
        return entry if ok else None

    def _write_cache(self, key: str, raw: str) -> None:
        path = self._cache_path(key)
        if path is None:
            return
        entry = {"cache_format": CACHE_FORMAT, "key": key, "raw": raw,
                 "provider": self.provider.name, "family": self.provider.family,
                 "model_id": self.model_id, "is_live": bool(self.provider.is_live),
                 "created_utc": datetime.now(timezone.utc).isoformat()}
        path.parent.mkdir(parents=True, exist_ok=True)
        fd, tmp = tempfile.mkstemp(dir=path.parent, suffix=".tmp")
        with os.fdopen(fd, "w", encoding="utf-8") as stream:
            json.dump(entry, stream, indent=2)
        os.replace(tmp, path)

    def _call(self, messages: Sequence[Message], schema: Mapping[str, Any], schema_hash: str,
              run_index: int, label: str, seed_offset: int = 0) -> tuple[str, str, str]:
        key = self.request_key(messages, schema_hash, run_index, label, seed_offset)
        cached = self._read_cache(key)
        if cached is not None:
            return key, cached["raw"], "cache:" + ("live" if cached.get("is_live") else "mock")
        if self.offline:
            raise CacheMiss(f"offline cache miss for request {key[:12]}")
        raw = self.provider.complete(messages, schema, self.model_id, self.temperature,
                                     self._seed(seed_offset), label)
        if not isinstance(raw, str):
            raise ProviderError("provider returned a non-text response")
        self._write_cache(key, raw)
        return key, raw, "live" if self.provider.is_live else "mock"

    # --- generation --------------------------------------------------------
    def generate(self, context: RequestContext, template: PromptTemplate, *,
                 schema_name: str = "interpretation", run_index: int = 0) -> GenerationResult:
        messages = list(template.render(context))
        schema = load_schema(schema_name)
        schema_hash = sha256(_canonical(schema).encode()).hexdigest()
        attempts: list[Attempt] = []
        status, parsed, detail = "failed", None, "no attempt made"
        for _ in range(self.max_retries + 1):
            try:
                key, raw, origin = self._call(messages, schema, schema_hash, run_index,
                                              template.name, seed_offset=run_index)
            except ProviderUnavailable as exc:
                status, detail = "unavailable", str(exc)
                break
            except CacheMiss as exc:
                status, detail = "cache_miss", str(exc)
                break
            except ProviderError as exc:
                status, detail = "failed", f"provider error: {exc}"
                break
            error = self._check(raw, schema_name)
            attempts.append(Attempt(key, raw, error[0], origin))
            if error[0] is None:
                status, parsed, detail = "ok", error[1], "schema-valid JSON"
                break
            detail = error[0]
            messages = messages + [Message("assistant", raw), Message(
                "user", f"Your reply was rejected: {error[0]}. Reply with corrected JSON only.")]
        else:
            detail = f"generation failed after {len(attempts)} attempts: {detail}"
        result = GenerationResult(status, parsed, tuple(attempts), detail,
                                  self._provenance(template, schema_hash, run_index, attempts, status))
        self._log(result)
        return result

    @staticmethod
    def _check(raw: str, schema_name: str) -> tuple[str | None, Mapping[str, Any] | None]:
        try:
            value = _parse_json(raw)
        except ValueError as exc:
            return f"not valid JSON ({exc})", None
        if not isinstance(value, dict):
            return "top-level JSON value must be an object", None
        try:
            validate_schema(schema_name, value)
        except ValidationError as exc:
            where = "/".join(str(p) for p in exc.absolute_path) or "<root>"
            return f"schema violation at {where}: {exc.message[:300]}", None
        return None, value

    def _provenance(self, template: PromptTemplate, schema_hash: str, run_index: int,
                    attempts: Sequence[Attempt], status: str) -> dict[str, Any]:
        """Run-manifest record. Contains no credentials or environment values."""
        return {"status": status, "provider": self.provider.name, "family": self.provider.family,
                "model_id": self.model_id, "provider_is_live": bool(self.provider.is_live),
                "temperature": self.temperature, "seed": self._seed(run_index),
                "seed_note": "recorded request parameter; provider determinism is not assumed",
                "run_index": run_index, "max_retries": self.max_retries, "offline": self.offline,
                "prompt": {"name": template.name, "version": template.version,
                           "sha256": template.sha256},
                "schema_sha256": schema_hash,
                "attempts": [{"request_key": a.request_key, "origin": a.origin,
                              "error": a.error} for a in attempts]}

    def _log(self, result: GenerationResult) -> None:
        if self.log_path is None:
            return
        self.log_path.parent.mkdir(parents=True, exist_ok=True)
        record = {"provenance": result.provenance, "status": result.status,
                  "detail": result.detail, "raw_responses": [a.raw for a in result.attempts]}
        with self.log_path.open("a", encoding="utf-8") as stream:
            stream.write(json.dumps(record, sort_keys=True) + "\n")
