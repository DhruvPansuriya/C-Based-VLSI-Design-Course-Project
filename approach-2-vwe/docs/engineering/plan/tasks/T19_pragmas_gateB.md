# T19 — Pragma policy, DEPENDENCE-false obligation, Gate B

**Priority:** nice · **Depends on:** T05, T08 · **Effort:** about 1.5 days

## Steps

1. **Pragma extraction (`vwe/hls/pragmas.py`):** using pycparser or a regex over `#pragma HLS ...` lines, list the pragmas of `P0` and `P1` with their scope (function and loop label).
2. **Policy:** the pragma diff is classified as:
   - *unchanged*;
   - *performance-only added or removed* (PIPELINE, UNROLL, ARRAY_PARTITION): recorded but not decisive;
   - *semantics-relevant* (`DEPENDENCE ... false`, `INTERFACE` mode changes): this triggers an obligation.
3. **DEPENDENCE-false obligation:** for `#pragma HLS DEPENDENCE variable=a inter false` on a loop, generate a harness that asserts no two iterations within the stated distance write and read the same index of `a` (two symbolic iterations `i < j`, assert `!(write_idx(i) == read_idx(j))`). If it is VIOLATED, the result is **REJECT E0** ("pragma asserts a false independence").
4. **Gate B:** check that the candidate still compiles under the HLS-subset admission (T02) **and**, if Vitis is available (T20), that `csynth` succeeds. If Vitis is unavailable, record "Gate B: not run" (never assume pass).
5. Add golden example `ex8_dependence_pragma` with v1 (correct pragma) → no obligation failure, and v2 (false pragma over a real dependence) → REJECT E0.

## Acceptance criteria

```bash
pytest -q tests/test_pragmas.py
python scripts/run_golden_examples.py   # includes ex8
```
