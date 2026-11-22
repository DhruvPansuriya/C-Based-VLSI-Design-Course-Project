# symv4: Reuse stored triangular matrix elements

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Reuse stored triangular matrix elements.

**Motivation:** The original already defines a symmetric matrix using lower-triangle storage; reuse each stored value for both output contributions.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `fa11ef578edcd736b709d937cb04b31a7340106e8a26d82db658ea4aad13d0ea`.

[Standalone C file](../../benchmarks/expanded/symv4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++){int hi=r>c?r:c;int lo=r>c?c:r;sum+=a[hi*4+lo]*x[c];}out[r]=sum;}
}
```

### Optimized

SHA-256: `f2db215754e21dacd4acf135323ab234c9937d29d0715e66f3309ce2bb2cca38`.

[Standalone C file](../../benchmarks/expanded/symv4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reuse stored triangular matrix elements. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++) out[r]=0u;
    for(int r=0;r<4;r++) for(int c=0;c<=r;c++){uint32_t value=a[r*4+c];out[r]+=value*x[c];if(c!=r) out[c]+=value*x[r];}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.014742 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/symv4_optimized.json) and [main SMT query](../../results/submission_verification/symv4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/symv4_buggy.c) and [counterexample record](../../results/submission_verification/symv4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4248.55 | 7941.96 | 1.869 |
| STA period estimate (ns) | 1.8553 | 8.50755 | 4.586 |
| RTL latency cycles | 30 | 78 | 2.6 |
| Latency at 10 ns clock (ns) | 300 | 780 | 2.6 |
| Area x latency (um² ns) | 1.27457e+06 | 6.19473e+06 | 4.86 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/symv4_original/) / [candidate raw evidence](../../results/hls/symv4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/symv4_original.c benchmarks/expanded/symv4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_symv4.smt2
```
