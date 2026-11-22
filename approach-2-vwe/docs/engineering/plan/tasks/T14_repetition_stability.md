# T14 — Repetition, union over runs, stability metric

**Priority:** nice · **Depends on:** T13 · **Effort:** about 0.5 day

## Steps

1. Add the config `llm.runs = r` (default 1). Generation is repeated with different seeds, and the union is taken before validation (draft consequence C2: the union can only make verdicts more conservative).
2. `vwe stability <task> --runs 3`: runs three independent generations, computes each verdict, and reports the agreement rate and the coverage drop as $r$ grows.
3. Add a unit test of the monotonicity property on stored sets: verdict(set ∪ extra) is either UNDECIDED or the same as verdict(set). Reuse `vwe.verdict` and recorded obligation outcomes.

## Acceptance criteria

```bash
pytest -q tests/test_stability.py
```
