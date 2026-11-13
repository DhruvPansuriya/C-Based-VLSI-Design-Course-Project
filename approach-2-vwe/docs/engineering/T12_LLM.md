# T12 — provider-neutral LLM client

Status: implemented with the deterministic mock and explicit unavailable behavior
for live providers. **No live provider was called.** No credentials, model ids or
network access were available or assumed, so nothing here is a live-model result.

## Information boundary (CONTRIBUTING.md rule 1)

`vwe.llm.RequestContext` is the only input from which a prompt can be rendered.
Fields: `task_id`, `request_id`, `request_text`, `signature` (P0 declaration only,
no body, no comments), `shape_candidates`. `from_task` accepts only a
`PipelineTask` and reads only the chosen request, `p0` and `function`. It does not
read `task.candidates`, interpretations or evaluation data, and it rejects a
`FullTask`.

Deviation from the T12 card: the card says the constructor takes "the admission
result for P0". `AdmissionResult` also carries `p1_views`, so passing it would put
P1-derived data one attribute away. The signature is instead rendered from P0 source.
The optional `p0_comments` ablation field is not implemented.

`PromptTemplate` only accepts the placeholders `${request_text}`, `${signature}`,
`${shape_candidates}`; anything else (for example a candidate) raises at definition.
Substituted text is not rescanned.

Tests (`tests/test_llm_isolation.py`, never delete): static dataclass/AST checks,
a candidate mapping that fails if read, and a runtime canary `CANARY_P1_7f3a` in a
candidate body and id which must not reach recorded prompts, cache files or logs.
The canary run through the full `--auto` pipeline is added with T13.

## Behavior

* `LLMClient.generate(context, template, run_index=)` renders, calls, parses JSON
  (a single ```json fence is tolerated), validates against the named project schema
  and retries at most twice, appending the validation error. Final failure returns
  `status="failed"` with no parsed value; nothing is guessed.
* Statuses: `ok`, `failed`, `unavailable` (no fixture / model id / key / network),
  `cache_miss` (offline). Unavailable is never converted into mock output.
* Cache: one file per provider call under the configured directory. The key is the
  SHA-256 of provider, family, model id, full message list (including retry
  feedback), schema hash, temperature, seed, run index and prompt label. Offline
  mode reads only the cache. Entries remember whether they were originally live.
* Provenance (`GenerationResult.provenance`, optional JSONL log with raw replies):
  provider, family, model id, prompt name/version/hash, schema hash, request keys,
  per-attempt origin (`live`, `mock`, `cache:live`, `cache:mock`). `result.live`
  is true only if every attempt was answered live in this execution. Seeds are
  recorded request parameters; provider determinism is not assumed.
* No credential is stored or logged; keys are read from the environment variable
  named in `config/llm.toml` at call time.

## Providers

`MockProvider` (default in tests) replays labeled fixtures from a dict or
`tests/fixtures/llm/<label>.json`, records every prompt and raises
`ProviderUnavailable` for an unknown label. `AnthropicProvider` and
`OpenAIProvider` use stdlib HTTP behind an injectable transport. Their request
layout follows the vendors' documented chat endpoints but is verified here only
against transport stubs (Q24). `config/llm.toml` ships with empty model ids; pin
them after checking the accounts (Q7).

Not done in T12: prompts (T13), multi-family generation, repetition (T14).
