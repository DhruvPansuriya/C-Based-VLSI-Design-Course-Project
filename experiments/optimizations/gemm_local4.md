# gemm_local4: Keep four row accumulators local during GEMM interchange

**Origin:** MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained.

**Algorithm group:** linear algebra.

**Rewrite:** Keep four row accumulators local during GEMM interchange.

**Motivation:** Follow up the earlier regressing GEMM candidate: reuse m1 reads while writing each product only once.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `beb59f64218ee627d3ff327be4af7045a47cbe08ef01e9505049064c50c7a108`.

[Standalone C file](../../benchmarks/expanded/gemm_local4_original.c)

```c
#include <stdint.h>

/* MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained.
   Reference implementation. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                uint32_t sum = 0u;
                for (int k = 0; k < 4; k++) {
                    sum += m1[i * 4 + k] * m2[k * 4 + j];
                }
                prod[i * 4 + j] = sum;
            }
        }
}
```

### Optimized

SHA-256: `c7d351511352262d1cd582214aec6e5f5dd2250b30dd3efb42e738a31b2a5d7e`.

[Standalone C file](../../benchmarks/expanded/gemm_local4_optimized.c)

```c
#include <stdint.h>

/* MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained.
   Keep four row accumulators local during GEMM interchange. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++){
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int k=0;k<4;k++){uint32_t v=m1[i*4+k];s0+=v*m2[k*4];s1+=v*m2[k*4+1];s2+=v*m2[k*4+2];s3+=v*m2[k*4+3];}
    prod[i*4]=s0;prod[i*4+1]=s1;prod[i*4+2]=s2;prod[i*4+3]=s3;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.024656 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/gemm_local4_optimized.json) and [main SMT query](../../results/submission_verification/gemm_local4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/gemm_local4_buggy.c) and [counterexample record](../../results/submission_verification/gemm_local4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4506.57 | 11236.9 | 2.493 |
| STA period estimate (ns) | 1.90345 | 6.75752 | 3.55 |
| RTL latency cycles | 122 | 66 | 0.541 |
| Latency at 10 ns clock (ns) | 1220 | 660 | 0.541 |
| Area x latency (um² ns) | 5.49802e+06 | 7.41636e+06 | 1.349 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/gemm_local4_original/) / [candidate raw evidence](../../results/hls/gemm_local4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/gemm_local4_original.c benchmarks/expanded/gemm_local4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_gemm_local4.smt2
```
