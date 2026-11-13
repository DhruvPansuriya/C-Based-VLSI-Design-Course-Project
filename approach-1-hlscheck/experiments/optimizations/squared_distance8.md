# squared_distance8: Expand squared distance into three reductions

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** arithmetic.

**Rewrite:** Expand squared distance into three reductions.

**Motivation:** A deliberate candidate to test algebraic normalization and hardware trade-offs; more multiplies may regress QoR. Distance is modular, not real-valued.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `390e57e41ef4dc9c3ff0b42b9b9b57e1af751464066d57dc07086385e78175a2`.

[Standalone C file](../../benchmarks/expanded/squared_distance8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t sum=0u;for(int i=0;i<8;i++){uint32_t d=a[i]-b[i];sum+=d*d;}return sum;
}
```

### Optimized

SHA-256: `8f978a4bbd2e8c8f6328ba555d55d0f5839f699baf9d0d34a495a6f41d5ced32`.

[Standalone C file](../../benchmarks/expanded/squared_distance8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Expand squared distance into three reductions. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return aa+bb-2u*ab;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.007573 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/squared_distance8_optimized.json) and [main SMT query](../../results/submission_verification/squared_distance8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/squared_distance8_buggy.c) and [counterexample record](../../results/submission_verification/squared_distance8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 3889.98 | 10619 | 2.73 |
| STA period estimate (ns) | 2.83401 | 1.96122 | 0.692 |
| RTL latency cycles | 11 | 11 | 1 |
| Latency at 10 ns clock (ns) | 110 | 110 | 1 |
| Area x latency (um² ns) | 427898 | 1.16809e+06 | 2.73 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/squared_distance8_original/) / [candidate raw evidence](../../results/hls/squared_distance8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/squared_distance8_original.c benchmarks/expanded/squared_distance8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_squared_distance8.smt2
```
