# matvec4: Expand matrix-vector inner product with balanced sums

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Expand matrix-vector inner product with balanced sums.

**Motivation:** Expose four products and a balanced adder tree per row.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `9858e09b3a201ab51fb70154142f992ac20aa31df5b43e2543575ab1615fdbdc`.

[Standalone C file](../../benchmarks/expanded/matvec4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++) sum+=a[r*4+c]*x[c];out[r]=sum;}
}
```

### Optimized

SHA-256: `459992c29136c2c2d7c39b9913a4c8723c24c15e3163755863648a7ca6175e02`.

[Standalone C file](../../benchmarks/expanded/matvec4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Expand matrix-vector inner product with balanced sums. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t p0=a[r*4]*x[0],p1=a[r*4+1]*x[1],p2=a[r*4+2]*x[2],p3=a[r*4+3]*x[3];out[r]=(p0+p1)+(p2+p3);}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.007300 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/matvec4_optimized.json) and [main SMT query](../../results/submission_verification/matvec4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/matvec4_buggy.c) and [counterexample record](../../results/submission_verification/matvec4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4250.95 | 11156 | 2.624 |
| STA period estimate (ns) | 1.94475 | 5.0738 | 2.609 |
| RTL latency cycles | 30 | 26 | 0.8667 |
| Latency at 10 ns clock (ns) | 300 | 260 | 0.8667 |
| Area x latency (um² ns) | 1.27528e+06 | 2.90057e+06 | 2.274 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/matvec4_original/) / [candidate raw evidence](../../results/hls/matvec4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/matvec4_original.c benchmarks/expanded/matvec4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_matvec4.smt2
```
