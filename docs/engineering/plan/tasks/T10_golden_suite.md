# T10 — Golden suite for draft Examples 1–7

**Priority:** must · **Depends on:** T09 · **Effort:** about 2 days

## Goal

Every worked example in the research draft (§9) is an executable regression test. This is **Milestone M1**.

## Steps

1. **Create task folders** in `examples/tasks/` for:
   - **ex3_avg_half_away:** `avg = (a+b)/2` (truncating). Request: "round half away from zero". Interpretations: zone "sum odd and negative" (a deliberate collapse) with one Ext stating the full rounding rule. Candidates: a correct full fix (expected **UNDECIDED, scope disagreement**), a fix only for negative sums, and a wrong fix.
   - **ex5_add32_ambiguous:** "Handle overflow in add32". Strict (saturate), permissive (no UB and no silent wrap), adversarial (error code). Candidates: saturate, error-code, unchanged. Expected: saturate → ACCEPT? Only if it satisfies every interpretation. Compute the expected verdicts by hand **before** running, and write the reasoning in `examples/tasks/ex5_add32_ambiguous/README.md`.
   - **ex6_copy_overflow:** a buffer-copy function with an out-of-bounds write. T3 computed zone. Candidates: a correct fix; a fix that also truncates normal copies (E1).
   - **ex7_build_views:** the `__SYNTHESIS__` divergence (spike T06) → REJECT E0.
2. **Extend `tests/golden/expected.json`** with every candidate. Expectations must be derived from the draft's rules *before* running. If the tool disagrees, investigate; do not edit the expectation to match the tool without writing the reason in `plan/OPEN_QUESTIONS.md`.
3. **Replace `scripts/run_golden_examples.py`** internals with `vwe.pipeline.verify` (hand-written interpretations). Keep the old hand-written harnesses in `spikes/` as an independent cross-check.
4. **`make golden`** prints a table and exits non-zero on any mismatch.

## Acceptance criteria

```bash
make golden        # all rows OK
make test          # green, including tests/test_golden.py
```

## Pitfalls

- Example 5 is the case where the verdict depends on the interpretation set. That is the point of the example; keep it.
