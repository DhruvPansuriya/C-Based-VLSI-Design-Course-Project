# triangular_matvec4: Tighten triangular loop bounds

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Tighten triangular loop bounds.

**Motivation:** Eliminate iterations with a false structural predicate, without restricting input matrix values.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `15a86280cc9ba8e62a44b1ba000df6e9fa4def37f2a481c2e5a2e548fb9e6224`.

[Standalone C file](../../benchmarks/expanded/triangular_matvec4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++){if(c<=r) sum+=a[r*4+c]*x[c];}out[r]=sum;}
}
```

### Optimized

SHA-256: `b255d8ae7e000a67376c70496b3dd5f4f285f4e81754cb09eca22eea397079ec`.

[Standalone C file](../../benchmarks/expanded/triangular_matvec4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Tighten triangular loop bounds. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<=r;c++) sum+=a[r*4+c]*x[c];out[r]=sum;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.008564 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/triangular_matvec4_optimized.json) and [main SMT query](../../results/submission_verification/triangular_matvec4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/triangular_matvec4_buggy.c) and [counterexample record](../../results/submission_verification/triangular_matvec4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4971.01 | 5360.96 | 1.078 |
| STA period estimate (ns) | 2.38577 | 2.02873 | 0.8503 |
| RTL latency cycles | 62 | 24 | 0.3871 |
| Latency at 10 ns clock (ns) | 620 | 240 | 0.3871 |
| Area x latency (um² ns) | 3.08202e+06 | 1.28663e+06 | 0.4175 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/triangular_matvec4_original/) / [candidate raw evidence](../../results/hls/triangular_matvec4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/triangular_matvec4_original.c benchmarks/expanded/triangular_matvec4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_triangular_matvec4.smt2
```
