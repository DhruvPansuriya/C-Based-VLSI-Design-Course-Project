"""LLM candidate-fix generation for evaluation pools (T16).

This is the only place an LLM writes candidates. It deliberately does not use
vwe.llm.LLMClient / RequestContext (interpretation generation): it takes a bare
Provider, its own cache namespace and its own prompt, so no interpretation context,
cache entry or prompt can be shared. Inputs are P0 and N only. Calls are bounded by
`max_calls`; unavailable providers are recorded, never replaced by mock output.
"""
from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime, timezone
from hashlib import sha256
import json
from pathlib import Path
import re
from typing import Any, Sequence

from ..llm.client import Message, Provider, ProviderError, ProviderUnavailable
from .mutants import compiles

PROMPT_VERSION = "1"
SYSTEM = ("You repair C functions. Reply with a single JSON object {\"code\": \"<complete corrected C "
          "source>\"} and nothing else. Keep the same function name and signature.")
USER = "Buggy C source:\n```c\n{p0}\n```\nRequested change: {request}\nReturn the full corrected source."


@dataclass(frozen=True)
class CandidateRecord:
    name: str
    status: str  # ok | invalid | unavailable | budget
    origin: str  # live | mock | cache:live | cache:mock | none
    detail: str


class CandidateGenerator:
    def __init__(self, provider: Provider, model_id: str, cache_dir: Path, *, temperature: float = 0.8,
                 max_calls: int = 50) -> None:
        if type(provider).__name__ == "LLMClient":
            raise TypeError("pass a bare provider; interpretation clients must not be reused")
        self.provider, self.model_id, self.temperature = provider, model_id, temperature
        self.cache_dir, self.max_calls, self.calls = Path(cache_dir) / "candidate-generation", max_calls, 0

    def prompt_sha256(self) -> str:
        return sha256(json.dumps([PROMPT_VERSION, SYSTEM, USER]).encode()).hexdigest()

    def _key(self, messages: Sequence[Message], sample: int) -> str:
        blob = json.dumps({"namespace": "candidate-generation", "provider": self.provider.name,
                           "family": self.provider.family, "model": self.model_id,
                           "temperature": self.temperature, "sample": sample,
                           "messages": [[m.role, m.content] for m in messages]}, sort_keys=True)
        return sha256(blob.encode()).hexdigest()

    def _complete(self, messages: Sequence[Message], sample: int) -> tuple[str, str]:
        path = self.cache_dir / f"{self._key(messages, sample)}.json"
        if path.is_file():
            entry = json.loads(path.read_text())
            return entry["raw"], "cache:" + ("live" if entry["is_live"] else "mock")
        if self.calls >= self.max_calls:
            raise BudgetExhausted()
        self.calls += 1
        raw = self.provider.complete(messages, None, self.model_id, self.temperature, sample, "candidate")
        self.cache_dir.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps({"raw": raw, "is_live": bool(self.provider.is_live),
                                    "model_id": self.model_id}))
        return raw, "live" if self.provider.is_live else "mock"

    def generate(self, p0: str, request: str, function: str, out_dir: Path, samples: int) -> list[CandidateRecord]:
        messages = (Message("system", SYSTEM), Message("user", USER.format(p0=p0, request=request)))
        records = []
        for k in range(samples):
            name = f"llm_{self.provider.family}_{k}"
            try:
                raw, origin = self._complete(messages, k)
            except BudgetExhausted:
                records.append(CandidateRecord(name, "budget", "none", "call budget exhausted"))
                break
            except (ProviderUnavailable, ProviderError) as exc:
                records.append(CandidateRecord(name, "unavailable", "none", str(exc)))
                break
            code = _extract(raw)
            if code is None or not re.search(rf"\b{re.escape(function)}\s*\(", code) or not compiles(code):
                records.append(CandidateRecord(name, "invalid", origin, "no compiling function in reply"))
                continue
            out_dir.mkdir(parents=True, exist_ok=True)
            (out_dir / f"{name}.c").write_text(code)
            records.append(CandidateRecord(name, "ok", origin, "written"))
        return records

    def provenance(self, records: list[CandidateRecord]) -> dict[str, Any]:
        return {"provider": self.provider.name, "family": self.provider.family, "model_id": self.model_id,
                "temperature": self.temperature, "prompt_version": PROMPT_VERSION,
                "prompt_sha256": self.prompt_sha256(), "provider_calls": self.calls,
                "date_utc": datetime.now(timezone.utc).isoformat(),
                "records": [r.__dict__ for r in records],
                "cost_note": "token usage is not reported by the adapters; provider_calls is the cost proxy"}


class BudgetExhausted(RuntimeError):
    pass


def _extract(raw: str) -> str | None:
    text = raw.strip()
    fenced = re.fullmatch(r"```(?:json)?\s*(.*?)\s*```", text, re.S)
    try:
        doc = json.loads(fenced.group(1) if fenced else text)
    except ValueError:
        return None
    code = doc.get("code") if isinstance(doc, dict) else None
    return code if isinstance(code, str) and code.strip() else None
