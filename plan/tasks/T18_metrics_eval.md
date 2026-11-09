# T18 — Metrics and evaluation harness

**Priority:** should · **Depends on:** T16, T17 · **Effort:** about 2 days · **Milestone M4**

## Metrics

- **Selective precision:** of ACCEPTs, the fraction labelled correct; of REJECTs, the fraction labelled incorrect. Report a **Wilson 95 % interval** for each.
- **Coverage:** the fraction of candidates that get a decision (not UNDECIDED).
- **Risk–coverage curve:** order decisions by evidence class (E0 < E1 < E2 < E3) and plot risk against coverage.
- **Paired comparison with baselines:** McNemar's exact test on the per-candidate correct/incorrect decision, with Holm correction across baselines.
- **Per-class breakdown:** by evidence class, request type (T1–T6) and bug type.
- **Cost:** wall-clock time per verdict and number of solver calls; also the inconclusive rate.

## Steps

1. `vwe/eval/metrics.py`: implement the metrics as pure functions, with unit tests on hand-computed small cases (Wilson and exact McNemar have closed forms; test against values computed by hand in the test file, and also cross-check against `scipy.stats` if it is installed).
2. `scripts/run_eval.py`: run the method and all baselines across all tasks and candidates, in parallel with a per-job timeout; write `results/eval/raw.jsonl`.
3. `scripts/summarise_eval.py`: write `results/eval/summary.md` with tables and a `risk_coverage.png` (matplotlib).
4. Add the Makefile target `make eval`.
5. **Unsound-verdict audit:** every wrong ACCEPT or wrong REJECT is listed with its evidence trail in `results/eval/errors.md`. Each one must be explained: a bad label, a contract-generation miss (the E2 assumption failed), or a **tool or implementation bug** (fix it and re-run).

## Acceptance criteria

```bash
make eval      # finishes; writes summary.md, risk_coverage.png, errors.md
pytest -q tests/test_metrics.py
```

**No wrong E0 or E1 verdict.** Those classes are claimed sound, so any wrong one is a bug that must be fixed before reporting.
