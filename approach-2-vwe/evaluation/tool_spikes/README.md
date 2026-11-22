# Spikes

Small, runnable experiments that check how the verification tools really behave. Every design decision in the technical design that depends on tool behaviour points to one of these.

## Tool behaviour (`tool_behaviour/`, run `run_spikes.sh`)

| Spike | Question | Observed (CBMC 6.11.0 / ESBMC 8.7.0) | Design consequence |
|---|---|---|---|
| T01 `while1` | Does an infinite loop on hard inputs make a proof vacuous? | CBMC default: yes ("no unwinding assertion will be generated for self-loop", SUCCESS). With `--unwinding-assertions --no-self-loops-to-assumptions`: unwinding assertion FAILURE. ESBMC: SUCCESS (vacuous). | Both flags always on; ESBMC confirm-only |
| T02 `bodyless` | Are calls to functions without a body silent? | CBMC 6.11: property `no body for callee helper: FAILURE`; `goto-instrument --list-undefined-functions` lists it | Admission check; classify as admission failure |
| T03 `abort` | Does `abort()` cut paths silently? | CBMC and ESBMC: SUCCESS (vacuous). After `--generate-function-body abort ... assert-false-assume-false`: FAILURE | Generated bodies for abort/exit/_Exit/longjmp |
| T04 `buffer_size` | Do fixed-size harness arrays hide off-by-one reads? | Fixed `int a[8]`: SUCCESS (hidden). Exact `malloc(n)`: `pointer outside object bounds` FAILURE. Without `--no-malloc-may-fail`, spurious NULL failures | Exact-size malloc + `--no-malloc-may-fail` |
| T05 `uninit` | Does self-composition detect a nondeterministic P0? | Yes: `P0 deterministic at x: FAILURE` | Computed region B_nd |
| T06 `build_views` | Can `__SYNTHESIS__` hide different behaviour? | Requirement passes without `-D__SYNTHESIS__`, fails with it | Two build views, required equivalent |

## Worked examples (`examples/`)

Hand-written harnesses for draft Examples 1, 2 and 4. `scripts/run_golden_examples.py` runs them on SAT and Z3 and applies `vwe.verdict.decide`. Expected verdicts are in `tests/golden/expected.json`.

## Replay (`replay/`)

Native replay of the CBMC witness for Example 2, variant 3 (`n = 3`) under GCC ASan/UBSan. The result is `heap-buffer-overflow` in `p1_argmax`.
