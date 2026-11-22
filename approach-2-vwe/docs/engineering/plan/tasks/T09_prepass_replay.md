# T09 — Native pre-pass and witness replay (GCC sanitizers)

**Priority:** must · **Depends on:** T08 · **Effort:** about 1.5 days

## Goal

Cheap early rejection, and native confirmation of every REJECT witness (draft Stages 4 and 6).

## Steps

1. **`vwe/tools/native.py`:** build a driver C file for (P0 view, P1 view, inputs from a JSON list) with `gcc -std=c11 -g -O0 -fsanitize=address,undefined -fno-sanitize-recover=all` (verified with GCC 13.3.0; Clang's sanitizer runtime was missing in the reference environment, so default to GCC). Buffers are `malloc`ed with exact sizes, as in harnesses.
2. **Pre-pass:**
   - inputs = boundary values (0, ±1, type min/max, sizes 0, 1, K) × random samples (default 10,000, seeded);
   - report candidate witnesses: (a) sanitizer error in P1 where P0 runs clean; (b) output difference outside $B_{\max}$ (evaluate the $B_{\max}$ predicate natively with the T03 emitter);
   - these witnesses are **only hints**: they are re-checked in CBMC with the inputs fixed (`assume(x == w)`) before they can count.
3. **Replay:**
   - for every VIOLATED obligation that decides a REJECT, run P0 and P1 natively on the witness;
   - expected: a sanitizer error in P1 (E0), or P1 output ≠ expected (E1/E2);
   - mismatch → the obligation becomes INCONCLUSIVE ("replay discrepancy"), logged;
   - exception: witnesses that rely on P0's UB are marked `replayed_natively = false`, with a reason.
4. **ACCEPT confirmation:** differential testing of P1 against every interpretation's executable check (from T03 emitted C) on the pre-pass inputs. Any failure → INCONCLUSIVE plus a bug report (the formal proof and the test disagree).

## Acceptance criteria

```bash
pytest -q tests/test_native.py
```

The tests must cover:

- Example 2 v3 witness `n=3` → `heap-buffer-overflow` detected (reuse `spikes/replay/ex2_v3_replay.c`);
- Example 1 v3 → pre-pass finds an output difference outside $B_{\max}$ within the first 100 inputs;
- a deliberately wrong "witness" → replay discrepancy → INCONCLUSIVE.

## Pitfalls

- Run native code in a subprocess with a timeout and resource limits (`ulimit -v`, no network). Candidates are untrusted code.
