# T05 — Tool pipeline: path-cut defences, CBMC backends, ESBMC confirmation, outcome classification

**Priority:** must · **Depends on:** T04 · **Effort:** about 2 days

## Goal

Run any `HarnessBundle` soundly and turn tool output into an `Obligation` (`PROVED` / `VIOLATED` / `INCONCLUSIVE`).

## Steps

1. **`vwe/tools/goto.py`.** `goto-cc` the bundle into a goto binary. Then run `goto-instrument --generate-function-body '(abort|exit|_Exit|longjmp)' --generate-function-body-options assert-false-assume-false` (spike T03; verified on CBMC 6.11.0). Then run `cbmc` on the instrumented binary with `BASE_FLAGS`.
   - Note: in T03 `abort` appeared in `--list-undefined-functions` before library linking. Add a test that the generated body really fires (reuse `spikes/tool_behaviour/t03_abort/harness.c`).
2. **Extend `vwe/tools/cbmc.py`** to accept a goto binary, and to return the properties grouped by frame (`p1_*`, `p0_*`, `main`/`vwe_clause_*`, `*.no-body.*`, `*.unwind.*`).
3. **`vwe/obligations.py`: `classify(runs: dict[backend, CbmcRun], selector) -> Obligation`**, generalising `scripts/run_golden_examples.classify`:
   - any backend error or timeout → INCONCLUSIVE;
   - any `*.unwind.*` failure → INCONCLUSIVE ("incomplete bound");
   - any `*.no-body.*` failure → raise `AdmissionError` (it should have been caught in T02);
   - SAT and Z3 disagree → INCONCLUSIVE;
   - otherwise VIOLATED (with witness) or PROVED.
4. **`vwe/tools/esbmc.py`: confirmation only.** `esbmc <files> --unwind B --z3` (ESBMC 8.7.0 accepted the CBMC-style `nondet_*` and `__CPROVER_assert` in our spikes; review R19). Returns `agree` / `disagree` / `unsupported`. Used only when the verdict would be ACCEPT: `disagree` → INCONCLUSIVE.
5. **Vacuity:** run the vacuity bundle; every probe must be FAILURE. Otherwise the obligations of that harness are INCONCLUSIVE ("vacuous").
6. **Parallelism:** `concurrent.futures.ProcessPoolExecutor`, with per-run timeout from config.

## Acceptance criteria

```bash
pytest -q tests/test_tool_pipeline.py
```

The tests must cover:

- spike T01 with `BASE_FLAGS` → INCONCLUSIVE (unwinding assertion fails);
- spike T03 after generated bodies → VIOLATED;
- spike T04 exact-size → VIOLATED in `p1_last`;
- a harness whose assumptions are contradictory → its vacuity probe does not fire → INCONCLUSIVE;
- ESBMC on the Example 1 correct candidate → `agree`.

`make spikes` still shows the documented outcomes.

## Pitfalls

- Never pass `--no-standard-checks`, and never drop `--no-self-loops-to-assumptions` or `--no-malloc-may-fail`.
- ESBMC passes `while(1)` and `abort` (spikes T01, T03). Never let ESBMC produce an ACCEPT on its own.
