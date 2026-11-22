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
def test_shipped_config_pins_no_model_ids():
    settings = load_llm_settings()
    assert settings.families["mock"].adapter == "mock"
    assert settings.families["anthropic"].model_id == "" and settings.families["openai"].model_id == ""
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
