# syrk4: Compute one triangle of a Gram matrix

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** linear algebra.

**Rewrite:** Compute one triangle of a Gram matrix.

**Motivation:** Exploit symmetry of A*A-transpose for arbitrary unsigned A; no symmetry assumption on input data is introduced.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `96b3d566620c663fedad5dc0a4ddddd2d17a0eaa168e504d8032e85c1d22aba9`.

[Standalone C file](../../benchmarks/expanded/syrk4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) for(int j=0;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;}
}
```

### Optimized

SHA-256: `19d9d6bebfd59065dee600d67ff658a211a42acbae8edacb93cf9562e8339021`.

[Standalone C file](../../benchmarks/expanded/syrk4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Compute one triangle of a Gram matrix. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) for(int j=i;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;if(i!=j) out[j*4+i]=sum;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.020440 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/syrk4_optimized.json) and [main SMT query](../../results/submission_verification/syrk4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/syrk4_buggy.c) and [counterexample record](../../results/submission_verification/syrk4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4528.92 | 4692.51 | 1.036 |
| STA period estimate (ns) | 1.89531 | 1.9763 | 1.043 |
| RTL latency cycles | 122 | 86 | 0.7049 |
| Latency at 10 ns clock (ns) | 1220 | 860 | 0.7049 |
| Area x latency (um² ns) | 5.52528e+06 | 4.03556e+06 | 0.7304 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/syrk4_original/) / [candidate raw evidence](../../results/hls/syrk4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/syrk4_original.c benchmarks/expanded/syrk4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_syrk4.smt2
```
