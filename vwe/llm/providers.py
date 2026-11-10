"""Provider adapters. The mock is deterministic; live adapters fail closed.

The Anthropic and OpenAI adapters use only the standard library HTTP stack and
are driven by an injectable transport. Their request layout follows each
vendor's documented chat endpoint but has NOT been exercised against a live
service in this repository (see plan/OPEN_QUESTIONS.md Q7/Q24). Without a pinned
model id and an API key in the configured environment variable they raise
ProviderUnavailable; they never fall back to mock output.
"""
from __future__ import annotations

import json
import os
import ssl
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence
import urllib.error
import urllib.request

from .client import Message, Provider, ProviderError, ProviderUnavailable

Transport = Callable[[str, Mapping[str, str], bytes, int], bytes]


_SYSTEM_CA_FILES = ("/etc/ssl/cert.pem", "/etc/ssl/certs/ca-certificates.crt")


def tls_context() -> ssl.SSLContext:
    """Verifying TLS context. Some Python builds (python.org macOS) ship no CA store;
    then the operating-system bundle is loaded. Verification is never disabled."""
    context = ssl.create_default_context()
    if not context.cert_store_stats().get("x509_ca"):
        for path in _SYSTEM_CA_FILES:
            if os.path.isfile(path):
                context.load_verify_locations(cafile=path)
                break
    if not context.cert_store_stats().get("x509_ca"):
        raise ProviderUnavailable("no CA certificates available for TLS verification")
    return context


def urllib_transport(url: str, headers: Mapping[str, str], body: bytes, timeout_s: int,
                     method: str = "POST") -> bytes:
    request = urllib.request.Request(url, data=body if method == "POST" else None,
                                     headers=dict(headers), method=method)
    try:
        with urllib.request.urlopen(request, timeout=timeout_s, context=tls_context()) as response:  # noqa: S310
            return response.read()
    except urllib.error.HTTPError as exc:
        raise ProviderError(f"HTTP {exc.code}{_error_code(exc)}") from None
    except (urllib.error.URLError, TimeoutError, OSError) as exc:
        raise ProviderUnavailable(f"network failure: {type(exc).__name__}") from None


def _error_code(exc: urllib.error.HTTPError) -> str:
    """Only the vendor's machine-readable error code/type; the message may echo request data."""
    try:
        err = json.loads(exc.read().decode("utf-8", "replace")).get("error", {})
    except (ValueError, OSError, AttributeError):
        return ""
    if not isinstance(err, dict):
        return ""
    parts = [str(err[k]) for k in ("type", "code") if isinstance(err.get(k), str)]
    return (" (" + ", ".join(dict.fromkeys(parts)) + ")") if parts else ""


class MockProvider:
    """Deterministic fixture provider that records every prompt it receives.

    ``responses`` maps a prompt label to one reply or a list of replies used for
    successive calls (retry tests). A missing label is an explicit error, never a
    guessed answer. Output is flagged ``is_live = False`` everywhere.
    """
    name = "mock"
    is_live = False

    def __init__(self, responses: Mapping[str, str | Sequence[str]] | None = None, *,
                 fixture_dir: Path | None = None, family: str = "mock") -> None:
        self.family = family
        self.responses = dict(responses or {})
        self.fixture_dir = Path(fixture_dir) if fixture_dir else None
        self.prompts: list[tuple[Message, ...]] = []
        self.calls: dict[str, int] = {}

    def complete(self, messages: Sequence[Message], json_schema: Mapping[str, Any] | None,
                 model_id: str, temperature: float, seed: int | None, label: str = "") -> str:
        self.prompts.append(tuple(messages))
        index = self.calls.get(label, 0)
        self.calls[label] = index + 1
        reply = self.responses.get(label)
        if reply is None and self.fixture_dir is not None:
            path = self.fixture_dir / f"{label}.json"
            if path.is_file():
                reply = path.read_text(encoding="utf-8")
        if reply is None:
            raise ProviderUnavailable(f"mock has no fixture for prompt label {label!r}")
        if isinstance(reply, str):
            return reply
        return reply[min(index, len(reply) - 1)]


class _HttpProvider:
    is_live = True
    name = ""
    url = ""

    def __init__(self, family: str, model_id: str, api_key_env: str, *,
                 transport: Transport = urllib_transport, timeout_s: int = 120,
                 api_key_file: Path | None = None) -> None:
        self.family, self.model_id = family, model_id
        self.api_key_file = api_key_file
        self.api_key_env, self.transport, self.timeout_s = api_key_env, transport, timeout_s

    def _key(self, model_id: str) -> str:
        if not model_id.strip():
            raise ProviderUnavailable(f"{self.name}: no model id is pinned in config/llm.toml")
        key = os.environ.get(self.api_key_env, "").strip() if self.api_key_env else ""
        if not key and self.api_key_file is not None and self.api_key_file.is_file():
            key = self.api_key_file.read_text(encoding="utf-8").strip()  # git-ignored local file
        if not key:
            raise ProviderUnavailable(f"{self.name}: no API key (environment variable "
                                      f"{self.api_key_env or '-'} unset and no key file)")
        return key

    def _post(self, headers: Mapping[str, str], payload: Mapping[str, Any]) -> Any:
        raw = self.transport(self.url, headers, json.dumps(payload).encode(), self.timeout_s)
        try:
            return json.loads(raw)
        except ValueError as exc:
            raise ProviderError("response was not JSON") from exc


def _with_schema(system: str, schema: Mapping[str, Any] | None) -> str:
    if schema is None:
        return system
    return system + "\n\nReply with a single JSON object conforming to this JSON Schema:\n" + \
        json.dumps(schema, sort_keys=True)


class AnthropicProvider(_HttpProvider):
    name = "anthropic"
    url = "https://api.anthropic.com/v1/messages"

    def complete(self, messages: Sequence[Message], json_schema: Mapping[str, Any] | None,
                 model_id: str, temperature: float, seed: int | None, label: str = "") -> str:
        key = self._key(model_id)  # seed is not a documented parameter here; it is not sent
        system = "\n".join(m.content for m in messages if m.role == "system")
        chat = [{"role": m.role, "content": m.content} for m in messages if m.role != "system"]
        data = self._post({"x-api-key": key, "anthropic-version": "2023-06-01",
                           "content-type": "application/json"},
                          {"model": model_id, "max_tokens": 4096, "temperature": temperature,
                           "system": _with_schema(system, json_schema), "messages": chat})
        try:
            return "".join(b["text"] for b in data["content"] if b.get("type") == "text")
        except (KeyError, TypeError) as exc:
            raise ProviderError("unexpected response layout") from exc


class OpenAIProvider(_HttpProvider):
    name = "openai"
    url = "https://api.openai.com/v1/chat/completions"

    def complete(self, messages: Sequence[Message], json_schema: Mapping[str, Any] | None,
                 model_id: str, temperature: float, seed: int | None, label: str = "") -> str:
        key = self._key(model_id)
        chat = [{"role": m.role, "content": _with_schema(m.content, json_schema)
                 if m.role == "system" else m.content} for m in messages]
        payload: dict[str, Any] = {"model": model_id, "messages": chat, "temperature": temperature,
                                   "max_completion_tokens": 4096}  # per-call cost cap
        if seed is not None:
            payload["seed"] = seed  # best-effort per vendor; determinism not assumed
        data = self._post({"Authorization": f"Bearer {key}", "Content-Type": "application/json"},
                          payload)
        try:
            return data["choices"][0]["message"]["content"]
        except (KeyError, IndexError, TypeError) as exc:
            raise ProviderError("unexpected response layout") from exc


def make_provider(adapter: str, family: str, model_id: str, api_key_env: str = "", *,
                  timeout_s: int = 120, fixture_dir: Path | None = None,
                  api_key_file: Path | None = None) -> Provider:
    if adapter == "mock":
        return MockProvider(fixture_dir=fixture_dir, family=family)
    if adapter == "anthropic":
        return AnthropicProvider(family, model_id, api_key_env, timeout_s=timeout_s, api_key_file=api_key_file)
    if adapter == "openai":
        return OpenAIProvider(family, model_id, api_key_env, timeout_s=timeout_s, api_key_file=api_key_file)
    raise ValueError(f"unknown provider adapter {adapter!r}")
