# T13 — Interpretation generation prompts

**Priority:** should · **Depends on:** T12 · **Effort:** about 2.5 days · **Milestone M3**

## Goal

Generate interpretation sets automatically (draft Stage 2), so that `vwe verify --auto` needs no hand-written interpretations.

## Steps

1. **Prompt files** in `vwe/llm/prompts/*.md`. Each is versioned, and its hash is stored in the run manifest.
   - `typing.md`: classify $N$ into T1–T6, with justification. Output JSON `{type, rationale}`.
   - `shape.md`: buffer sizes as expressions over parameters, for each pointer parameter, from the signature and $N$.
   - `strict.md`, `permissive.md`, `adversarial.md`: produce an interpretation JSON (schema-conformant). It must include `ext` (or `"unknown"`), `reach` and an `nl_rendering`. The adversarial prompt receives the strict interpretation's **English rendering only** and asks for a reading under which it would be wrong.
   - Every prompt includes the contract-grammar summary and 2 few-shot examples. The few-shot examples must **not** be from the evaluation tasks.
2. **Generation loop:** families (≥ 2) × prompts (3) × `runs` (default 1; T14 adds repetition), plus computed interpretations (T3 from $B_{ub}$ via T06 validation, T5 identity).
3. **For T3 requests:** a P0-only predicate proposal must be certified by T06. Incomplete or failed certification remains UNKNOWN. Witness enumeration may provide hints but must never be called an exact region without the required coverage and universal-inside evidence. P1 or evaluation metadata must not influence generation.
4. **`vwe interpret <task>`:** writes `runs/<task>/interpretation_set.json` (frozen, hashed) and a readable `interpretations.md`.
5. **Comparison script:** for Examples 1, 2 and 4, compare auto vs hand-written verdicts and write `results/auto_vs_handwritten.md`. Differences are allowed but must be explained (for example, "the auto set has an extra permissive reading, so UNDECIDED instead of REJECT E2").

## Acceptance criteria

```bash
vwe interpret examples/tasks/ex1_saturate         # with a real provider configured, or MockProvider fixtures
vwe verify examples/tasks/ex1_saturate --candidate v3 --auto     # REJECT E1 expected
pytest -q tests/test_interpret.py                  # uses MockProvider fixtures
```
