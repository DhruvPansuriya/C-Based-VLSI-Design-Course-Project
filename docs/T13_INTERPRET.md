# T13 — automatic interpretation generation

Status: implemented and tested with **authored mock fixtures only**. No live model
was called (no credentials or pinned model ids), so there is no measurement of
real-model formalisation quality, and the "at least two model families" goal is
**not met with live models**. The code supports N families; tests use two *mock*
families, which are not independent models.

## Flow (`vwe/interpret.py`)

1. `RequestContext` from P0 + request text (T12). The caller profile in the task
   manifest is user-supplied domain information, offered as the single shape
   candidate; it is not derived from any candidate.
2. Per family: `typing` (informational request type), `shape` (informational
   cross-check against the caller profile, recorded as `agrees_with_caller_profile`),
   then `strict`, `permissive` per run, then `adversarial`, which receives only the
   English `nl_rendering` of that run's strict reading (`prior_readings`).
3. Each reply is schema-validated by the T12 client (two bounded retries). Failed,
   unavailable or invalid replies are recorded and contribute no reading.
4. The client's provenance overwrites the reading's `id` and `provenance`.
   **The model's own `shape` is replaced by the caller profile** (the pipeline is
   profile-local and abstains on mixed profiles); `model_shape_replaced` records
   whether that changed anything. This is a deliberate normalisation, not model output.
5. `generated_set.json` (members, SHA-256 over canonical members, per-call records,
   prompt versions/hashes, live/mock family lists) and a readable
   `interpretations.md` are written.
6. `verify --auto` freezes the set exactly like handwritten readings (P0-only
   validation, grouping, hash). Auto mode **never** loads the task's handwritten
   interpretations; with no generated set the verdict is UNDECIDED.

`p1_seen_by_any_llm` is always false because nothing candidate-derived can reach
`RequestContext`; `tests/test_interpret.py` repeats the canary check through the
real `--auto` verification path.

## Commands

```sh
vwe interpret examples/tasks/ex1_saturate --family mock --fixtures tests/fixtures/llm/auto/ex1_saturate
vwe verify examples/tasks/ex1_saturate --candidate v3 --auto --family mock \
    --fixtures tests/fixtures/llm/auto/ex1_saturate
pytest -q tests/test_interpret.py
python scripts/compare_auto_handwritten.py      # writes results/auto_vs_handwritten.md
```

A live family (`anthropic`, `openai`) reports `unavailable` until `config/llm.toml`
pins a model id and the API key variable is set.

## Not implemented

* Certified computed readings (T3 from P0-only regions, T5 identity). Region
  certification exists (`vwe/regions.py`) but a computed-reading generator has not
  been built; it remains UNKNOWN rather than being approximated.
* Repetition/union/stability measurement (T14). `--runs` only generates repeated
  readings with distinct cache keys.
* Prompt effectiveness: the prompts were never run against a real model.
