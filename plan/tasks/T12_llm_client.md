# T12 — LLM client: provider-neutral, cached, schema-enforced, isolation-tested

**Priority:** should · **Depends on:** T08 · **Effort:** about 1.5 days

## Goal

A single, safe way to call LLMs that makes the "no LLM ever sees P1" rule structurally impossible to break.

## Steps

1. **`vwe/llm/context.py`:** `RequestContext` (frozen dataclass) with fields `request_text`, `signature`, `shape_candidates`, and optional `p0_comments` (ablation flag). Its constructor accepts **only** a `PipelineTask` and the admission result for `P0`. It has no parameter for candidates.
2. **`vwe/llm/client.py`:**
   - a `Provider` protocol: `complete(messages, json_schema, model_id, temperature, seed) -> str`;
   - two adapters, behind optional imports, chosen by `config/llm.toml`: an Anthropic Claude family and an OpenAI GPT family;
   - a `MockProvider` that returns canned JSON from `tests/fixtures/llm/`, used by default in tests and the demo.
   - Exact model IDs are **pinned in config at setup time**; do not hard-code names in code.
3. **Schema enforcement:** parse the JSON, validate against `interpretation.schema.json`, and retry at most 2 times with the validation error appended. On final failure, record "generation failed" (never guess).
4. **Cache:** `~/.cache/vwe/llm/<sha256(model_id|prompt|run_index)>.json`. Offline mode reads only from the cache.
5. **Isolation tests (`tests/test_llm_isolation.py`):**
   - **(a) static:** `RequestContext` fields contain nothing typed as a candidate or path to `candidates/`;
   - **(b) canary:** insert the string `CANARY_P1_7f3a` into a candidate file, run the full pipeline with `--auto` using `MockProvider` (which records all prompts), and assert the canary never appears in any recorded prompt;
   - **(c)** the FIFO structural-summary exception (T21) is the only other entry point, and it is tested separately.

## Acceptance criteria

```bash
pytest -q tests/test_llm_isolation.py tests/test_llm_client.py
```
