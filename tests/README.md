# tests/ - automatic tests

```sh
make test        # about 10 minutes; last run: 436 passed, 1 skipped (ESBMC only runs on Linux)
```

There is one test file per part of the code (`test_admission.py`, `test_validate.py`,
`test_verdict.py`, ...). Some tests are worth knowing about:

* `test_llm_isolation.py` plants a marker string in every candidate and checks it never reaches an
  LLM prompt. This is the guard for "no LLM ever sees P1".
* `test_golden.py` runs the example tasks end to end and compares with expected verdicts in `golden/`.
* `test_t10_regressions.py` keeps bugs we fixed from coming back.

Tests that need CBMC are skipped automatically when it is not installed. `fixtures/` holds small
input files used by the tests.
