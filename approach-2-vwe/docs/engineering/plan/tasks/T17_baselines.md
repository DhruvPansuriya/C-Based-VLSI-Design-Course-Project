# T17 — Baselines

**Priority:** should · **Depends on:** T16 · **Effort:** about 1.5 days

## Baselines (each produces ACCEPT / REJECT / UNDECIDED on the same pools)

| ID | Baseline | Rule |
|---|---|---|
| B1 | **Tests only** | ACCEPT if the candidate passes the task's test inputs plus 1 000 random inputs without sanitizer errors; otherwise REJECT. Never UNDECIDED. |
| B2 | **LLM-as-judge** | Give an LLM `P0`, `N` and the candidate and ask "does this implement the request? yes / no / unsure". This baseline **is** allowed to see the candidate; it is a comparison point, not part of the method. |
| B3 | **Single strict contract** | Our pipeline with only the strict interpretation (no bracketing, no Ext). |
| B4 | **Equivalence outside the bug region** | Prove `P1 == P0` outside an LLM-chosen bug region; accept otherwise. Approximates the "regression only" approach. |

## Steps

1. `vwe/baselines/{tests_only,llm_judge,single_contract,regression_only}.py`, each exposing `verdict(task, candidate) -> Verdict`.
2. `vwe baseline <name> <task> --candidate <c>` CLI.
3. Store the results in `results/eval/baselines/<name>.jsonl` (one line per task × candidate).

## Acceptance criteria

```bash
pytest -q tests/test_baselines.py   # with MockProvider for B2
```
