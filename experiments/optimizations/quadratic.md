# quadratic: Horner-form quadratic evaluation

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** arithmetic.

**Rewrite:** Horner-form quadratic evaluation.

**Motivation:** Factor a polynomial to alter multiplier/addition scheduling; both versions use modular arithmetic.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `b1a5c33f2e20a7e8a13c85d755f69da4f532c0075724d08387f37e8a2421ee44`.

[Standalone C file](../../benchmarks/expanded/quadratic_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return a*x*x+b*x+c;
}
```

### Optimized

SHA-256: `6fcea3d95f9064470b3ebb7aa11651b84a2daed53673abe9a4def6aa7df8787f`.

[Standalone C file](../../benchmarks/expanded/quadratic_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Horner-form quadratic evaluation. */
uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return (a*x+b)*x+c;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.002189 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/quadratic_optimized.json) and [main SMT query](../../results/submission_verification/quadratic_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/quadratic_buggy.c) and [counterexample record](../../results/submission_verification/quadratic_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 6971.59 | 6971.59 | 1 |
| STA period estimate (ns) | 3.45378 | 3.45378 | 1 |
| RTL latency cycles | 1 | 1 | 1 |
| Latency at 10 ns clock (ns) | 10 | 10 | 1 |
| Area x latency (um² ns) | 69715.9 | 69715.9 | 1 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/quadratic_original/) / [candidate raw evidence](../../results/hls/quadratic_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/quadratic_original.c benchmarks/expanded/quadratic_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_quadratic.smt2
```
