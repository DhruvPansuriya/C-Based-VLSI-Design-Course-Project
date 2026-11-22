"""T12: client behavior with the deterministic mock; no network, no solvers."""
from __future__ import annotations

import json
from pathlib import Path

import pytest

from vwe.config import ConfigError
from vwe.llm import (AnthropicProvider, LLMClient, MockProvider, OpenAIProvider, PromptTemplate,
                     ProviderError, RequestContext, build_client, load_llm_settings)
from vwe.tasks import load_pipeline_view

ROOT = Path(__file__).resolve().parent.parent
FIXTURES = ROOT / "tests" / "fixtures" / "llm"
GOOD = (FIXTURES / "strict.json").read_text()
TEMPLATE = PromptTemplate("strict", "test-1", "You formalise requests.",
                          "Signature: ${signature}\nRequest: ${request_text}\nShapes: ${shape_candidates}")


@pytest.fixture(scope="module")
def context() -> RequestContext:
    task = load_pipeline_view(ROOT / "examples/tasks/ex1_saturate")
    return RequestContext.from_task(task, "original")


def client(provider, tmp_path: Path, **kw) -> LLMClient:
    return LLMClient(provider, "mock-model", cache_dir=tmp_path / "cache", **kw)


def test_context_is_signature_and_request_only(context):
    assert "add8" in context.signature and "{" not in context.signature
    assert context.request_text and context.shape_candidates == ()


def test_success_records_mock_origin_and_never_claims_live(context, tmp_path):
    result = client(MockProvider({"strict": GOOD}), tmp_path).generate(context, TEMPLATE)
    assert result.status == "ok" and result.parsed["id"] == "fixture.strict"
    assert [a.origin for a in result.attempts] == ["mock"]
    assert result.live is False and result.provenance["provider_is_live"] is False
    assert result.provenance["prompt"]["sha256"] == TEMPLATE.sha256


def test_fixture_directory_provider(context, tmp_path):
    result = client(MockProvider(fixture_dir=FIXTURES), tmp_path).generate(context, TEMPLATE)
    assert result.status == "ok"


def test_missing_fixture_is_unavailable_not_invented(context, tmp_path):
    result = client(MockProvider({}), tmp_path).generate(context, TEMPLATE)
    assert result.status == "unavailable" and result.parsed is None and not result.attempts


def test_retry_appends_error_then_succeeds(context, tmp_path):
    mock = MockProvider({"strict": ["not json", GOOD]})
    result = client(mock, tmp_path).generate(context, TEMPLATE)
    assert result.status == "ok" and len(result.attempts) == 2
    retry_prompt = mock.prompts[1]
    assert retry_prompt[-2].role == "assistant" and "not valid JSON" in retry_prompt[-1].content


def test_schema_violation_retries_are_bounded(context, tmp_path):
    mock = MockProvider({"strict": json.dumps({"id": "x"})})
    result = client(mock, tmp_path).generate(context, TEMPLATE)
    assert result.status == "failed" and len(result.attempts) == 3  # 1 + 2 retries
    assert result.parsed is None and "schema violation" in result.detail
    assert len(mock.prompts) == 3


def test_cache_replays_without_calling_provider(context, tmp_path):
    first = MockProvider({"strict": GOOD})
    client(first, tmp_path).generate(context, TEMPLATE)
    second = MockProvider({})
    again = client(second, tmp_path).generate(context, TEMPLATE)
    assert again.status == "ok" and second.prompts == []
    assert [a.origin for a in again.attempts] == ["cache:mock"] and not again.live


def test_cache_key_covers_context_model_and_config(context, tmp_path):
    base = client(MockProvider({"strict": GOOD}), tmp_path)
    msgs = TEMPLATE.render(context)
    keys = {base.request_key(msgs, "s", 0, "strict"),
            base.request_key(msgs, "s", 1, "strict"),
            base.request_key(msgs, "t", 0, "strict"),
            base.request_key(TEMPLATE.render(context.with_shapes(("{}",))), "s", 0, "strict"),
            client(MockProvider({}), tmp_path, temperature=0.7).request_key(msgs, "s", 0, "strict"),
            client(MockProvider({}), tmp_path, seed=3).request_key(msgs, "s", 0, "strict"),
            LLMClient(MockProvider({}), "other", cache_dir=tmp_path).request_key(msgs, "s", 0, "strict")}
    assert len(keys) == 7


def test_offline_cache_miss_is_explicit(context, tmp_path):
    mock = MockProvider({"strict": GOOD})
    result = client(mock, tmp_path, offline=True).generate(context, TEMPLATE)
    assert result.status == "cache_miss" and mock.prompts == []
    with pytest.raises(ValueError):
        LLMClient(mock, "m", offline=True)


def test_cached_live_origin_is_not_a_fresh_live_claim(context, tmp_path):
    class Live(MockProvider):
        is_live, name = True, "fake-live"
    c = client(Live({"strict": GOOD}), tmp_path)
    assert c.generate(context, TEMPLATE).live is True
    replay = client(MockProvider({}), tmp_path)  # different provider name -> different key
    assert replay.generate(context, TEMPLATE).status == "unavailable"
    same = client(Live({}), tmp_path, offline=True).generate(context, TEMPLATE)
    assert same.status == "ok" and same.live is False
    assert [a.origin for a in same.attempts] == ["cache:live"]


def test_template_rejects_foreign_placeholders():
    with pytest.raises(ValueError):
        PromptTemplate("bad", "1", "s", "${candidate_source}")
    with pytest.raises(ValueError):
        PromptTemplate("bad", "1", "s", "cost: $5")


def test_substituted_text_is_not_rescanned(context):
    tricky = RequestContext("t", "r", "use ${signature} and $x", "int f(void);")
    user = TEMPLATE.render(tricky)[1].content
    assert "use ${signature} and $x" in user


def test_corrupt_cache_entry_is_ignored(context, tmp_path):
    c = client(MockProvider({"strict": GOOD}), tmp_path)
    key = c.request_key(TEMPLATE.render(context), json_hash(), 0, "strict")
    (tmp_path / "cache").mkdir()
    (tmp_path / "cache" / f"{key}.json").write_text("{broken")
    assert c.generate(context, TEMPLATE).status == "ok"


def json_hash() -> str:
    from hashlib import sha256
    from vwe.llm.client import _canonical
    from vwe.schemas import load
    return sha256(_canonical(load("interpretation")).encode()).hexdigest()


def test_log_records_raw_responses_without_secrets(context, tmp_path, monkeypatch):
    monkeypatch.setenv("ANTHROPIC_API_KEY", "sk-secret-value")
    log = tmp_path / "gen.jsonl"
    client(MockProvider({"strict": GOOD}), tmp_path, log_path=log).generate(context, TEMPLATE)
    text = log.read_text()
    assert "sk-secret-value" not in text and "fixture.strict" in text


# --- live adapters: explicit unavailable behavior and request layout -----------------
def test_live_adapters_refuse_without_model_or_key(context, tmp_path, monkeypatch):
    monkeypatch.delenv("ANTHROPIC_API_KEY", raising=False)
    calls = []
    transport = lambda *a: calls.append(a) or b"{}"
    no_model = AnthropicProvider("anthropic", "", "ANTHROPIC_API_KEY", transport=transport)
    no_key = OpenAIProvider("openai", "some-model", "OPENAI_API_KEY_UNSET_FOR_TEST", transport=transport)
    for provider in (no_model, no_key):
        result = LLMClient(provider, provider.model_id, cache_dir=tmp_path / provider.name).generate(context, TEMPLATE)
        assert result.status == "unavailable" and not result.attempts
    assert calls == []


def test_anthropic_request_layout_and_secret_isolation(context, tmp_path, monkeypatch):
    monkeypatch.setenv("TEST_KEY", "sk-test-123")
    seen = {}
    def transport(url, headers, body, timeout):
        seen.update(url=url, headers=dict(headers), body=json.loads(body))
        return json.dumps({"content": [{"type": "text", "text": GOOD}]}).encode()
    provider = AnthropicProvider("anthropic", "pinned-model", "TEST_KEY", transport=transport)
    c = LLMClient(provider, "pinned-model", cache_dir=tmp_path, log_path=tmp_path / "log.jsonl")
    result = c.generate(context, TEMPLATE)
    assert result.status == "ok" and result.live is True
    assert seen["headers"]["x-api-key"] == "sk-test-123" and seen["body"]["model"] == "pinned-model"
    assert "JSON Schema" in seen["body"]["system"]
    on_disk = "".join(p.read_text() for p in tmp_path.rglob("*.json*"))
    assert "sk-test-123" not in on_disk


def test_openai_layout_and_malformed_reply(context, tmp_path, monkeypatch):
    monkeypatch.setenv("TEST_KEY", "k")
    bodies = []
    def transport(url, headers, body, timeout):
        bodies.append(json.loads(body))
        return json.dumps({"unexpected": 1}).encode()
    provider = OpenAIProvider("openai", "pinned", "TEST_KEY", transport=transport)
    result = LLMClient(provider, "pinned", cache_dir=tmp_path, seed=7).generate(context, TEMPLATE)
    assert result.status == "failed" and "provider error" in result.detail
    assert bodies[0]["seed"] == 7 and bodies[0]["model"] == "pinned"
    assert issubclass(ProviderError, RuntimeError)


# --- configuration -----------------------------------------------------------------
def test_shipped_config_pins_only_verified_model_ids():
    settings = load_llm_settings()
    assert settings.families["mock"].adapter == "mock"
    assert settings.families["anthropic"].model_id == ""  # not verified on any account
    assert settings.families["openai"].model_id == "gpt-4.1-mini-2025-04-14"  # GET /v1/models, 2026-11-23
    assert settings.families["openai"].api_key_file.name == "openai.key"
    assert settings.max_retries == 2


def test_unconfigured_live_family_is_unavailable(context, tmp_path):
    c = build_client(load_llm_settings(), "anthropic", cache_dir=tmp_path)
    assert c.generate(context, TEMPLATE).status == "unavailable"


def test_bad_config_rejected(tmp_path):
    bad = tmp_path / "llm.toml"
    bad.write_text('[client]\nmax_retries = 5\n')
    with pytest.raises(ConfigError):
        load_llm_settings(bad)
    bad.write_text('[families.x]\nadapter = "other"\n')
    with pytest.raises(ConfigError):
        load_llm_settings(bad)
    with pytest.raises(ConfigError):
        build_client(load_llm_settings(), "nope")


def test_key_file_is_read_at_call_time_and_never_stored(context, tmp_path, monkeypatch):
    monkeypatch.delenv("UNSET_KEY_ENV_FOR_TEST", raising=False)
    key_file = tmp_path / "k.key"
    key_file.write_text("sk-file-secret-999\n")
    seen = {}
    def transport(url, headers, body, timeout):
        seen.update(headers)
        return json.dumps({"choices": [{"message": {"content": GOOD}}]}).encode()
    provider = OpenAIProvider("openai", "pinned", "UNSET_KEY_ENV_FOR_TEST", transport=transport,
                              api_key_file=key_file)
    c = LLMClient(provider, "pinned", cache_dir=tmp_path / "cache", log_path=tmp_path / "log.jsonl")
    assert c.generate(context, TEMPLATE).status == "ok"
    assert seen["Authorization"] == "Bearer sk-file-secret-999"
    stored = "".join(p.read_text() for p in (tmp_path / "cache").glob("*.json")) + (tmp_path / "log.jsonl").read_text()
    assert "sk-file-secret" not in stored


def test_config_key_file_resolves_relative_to_project(tmp_path):
    (tmp_path / "config").mkdir()
    cfg = tmp_path / "config" / "llm.toml"
    cfg.write_text('[families.o]\nadapter = "openai"\nmodel_id = "m"\napi_key_file = "config/secrets/x.key"\n')
    assert load_llm_settings(cfg).families["o"].api_key_file == (tmp_path / "config/secrets/x.key").resolve()


def test_tls_context_verifies_certificates():
    import ssl
    from vwe.llm.providers import tls_context
    ctx = tls_context()
    assert ctx.verify_mode == ssl.CERT_REQUIRED and ctx.check_hostname
    assert ctx.cert_store_stats()["x509_ca"] > 0


def test_http_error_reports_vendor_code_but_not_message():
    import io, urllib.error
    from vwe.llm.providers import _error_code
    body = json.dumps({"error": {"type": "insufficient_quota", "code": "credit_balance_exhausted",
                                 "message": "echo of SECRET-REQUEST-TEXT"}}).encode()
    exc = urllib.error.HTTPError("u", 429, "x", {}, io.BytesIO(body))
    code = _error_code(exc)
    assert "insufficient_quota" in code and "credit_balance_exhausted" in code
    assert "SECRET" not in code
    assert _error_code(urllib.error.HTTPError("u", 500, "x", {}, io.BytesIO(b"not json"))) == ""


def test_backoff_only_for_transient_errors(context, tmp_path, monkeypatch):
    monkeypatch.setenv("TEST_KEY", "k")
    calls, sleeps = [], []
    replies = [ProviderError("HTTP 429 (requests, rate_limit_exceeded)"), ProviderError("HTTP 503"),
               json.dumps({"choices": [{"message": {"content": GOOD}}]}).encode()]
    def transport(*a):
        calls.append(1)
        r = replies[len(calls) - 1]
        if isinstance(r, Exception):
            raise r
        return r
    provider = OpenAIProvider("openai", "m", "TEST_KEY", transport=transport)
    provider.sleep = sleeps.append
    assert LLMClient(provider, "m", cache_dir=tmp_path / "a").generate(context, TEMPLATE).status == "ok"
    assert len(calls) == 3 and sleeps == [5.0, 20.0]
    quota = OpenAIProvider("openai", "m", "TEST_KEY",
                           transport=lambda *a: (_ for _ in ()).throw(ProviderError("HTTP 429 (insufficient_quota)")))
    quota.sleep = sleeps.append
    result = LLMClient(quota, "m", cache_dir=tmp_path / "b").generate(context, TEMPLATE)
    assert result.status == "failed" and "insufficient_quota" in result.detail and sleeps == [5.0, 20.0]


def test_groq_uses_openai_layout_on_its_own_endpoint(context, tmp_path, monkeypatch):
    from vwe.llm import GroqProvider, list_models
    monkeypatch.setenv("TEST_KEY", "gsk-test")
    seen = {}
    def transport(url, headers, body, timeout, *rest):
        seen.setdefault("urls", []).append(url)
        if url.endswith("/models"):
            return json.dumps({"data": [{"id": "b"}, {"id": "a"}]}).encode()
        seen["body"] = json.loads(body)
        return json.dumps({"choices": [{"message": {"content": GOOD}}]}).encode()
    p = GroqProvider("groq", "pinned", "TEST_KEY", transport=transport)
    assert LLMClient(p, "pinned", cache_dir=tmp_path).generate(context, TEMPLATE).status == "ok"
    assert seen["urls"][0] == "https://api.groq.com/openai/v1/chat/completions"
    assert seen["body"]["model"] == "pinned"
    assert list_models(p, transport=transport) == ["a", "b"]
    fams = load_llm_settings().families
    assert {fams["groq_gptoss"].model_id, fams["groq_qwen"].model_id} == {"openai/gpt-oss-120b", "qwen/qwen3.8-27b"}
    assert all(fams[f].adapter == "groq" and fams[f].api_key_file.name == "groq.key" for f in ("groq_gptoss", "groq_qwen"))
