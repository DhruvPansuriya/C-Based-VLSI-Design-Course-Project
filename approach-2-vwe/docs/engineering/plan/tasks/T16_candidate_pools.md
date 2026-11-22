# T16 — Candidate pools and labelling

**Priority:** should · **Depends on:** T15, T12 · **Effort:** about 2 days

## Goal

For each benchmark task, a pool of candidate fixes with a ground-truth label, so that verdicts can be scored.

## Steps

1. **LLM fixes (`scripts/gen_candidates.py`):** for each task, ask ≥ 2 model families for a fix given only `P0` + `N` (temperature 0.8, 5 samples each). Store the outputs in `benchmarks/tasks/<t>/candidates/llm_<family>_<k>.c` together with a provenance JSON (model ID, prompt hash, date). This is the **only** place where an LLM writes candidates. It must use a separate client instance that is never given an interpretation-generation context.
2. **Mutants (`scripts/gen_mutants.py`):** apply deterministic mutation operators to `P_ref`: off-by-one in loop bounds, relational operator swap, constant ±1, deleted guard, swapped `min`/`max`. Keep only mutants that compile.
3. **Deduplicate** by normalised token stream (strip comments and whitespace).
4. **Labelling (`scripts/label_candidates.py`):**
   - **reference check:** run CBMC on `eval/phi_ref.c` (from T15) over the candidate and record PROVED / VIOLATED / INCONCLUSIVE;
   - **differential testing:** 10 000 random inputs plus boundary inputs, comparing against `P_ref`;
   - label `correct` only if the reference check is PROVED; label `incorrect` if it is VIOLATED or differential testing finds a counterexample with no UB in `P_ref`; otherwise label `unknown` (excluded from metrics, counted and reported).
   - The label files live in `eval/labels.json`, which the pipeline is **never** allowed to read (enforced by the `eval_only` test from T01).
5. Report the class balance per task. If a task has no correct or no incorrect candidates, flag it in `results/eval/pool_stats.md`.

## Acceptance criteria

```bash
python scripts/gen_mutants.py --all && python scripts/label_candidates.py --all
pytest -q tests/test_labels_isolation.py
```

Every task has ≥ 1 correct and ≥ 1 incorrect labelled candidate, or is flagged.
