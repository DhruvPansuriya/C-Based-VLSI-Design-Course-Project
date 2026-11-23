# gemm_tile2: Tile GEMM columns by two with local accumulators

**Origin:** Explicit follow-up against the existing benchmarks/machsuite_u32/gemm_original.c reference; not a new independent original algorithm.

**Algorithm group:** feedback variants.

**Rewrite:** Tile GEMM columns by two with local accumulators.

**Motivation:** Follow up the four-accumulator design: test whether two simultaneous output accumulators reduce mapped area while retaining some row-input reuse. Improvement is determined by measurements.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `d34b316a62c77526f14598b5987f8b8a1dfe86a57d3bbda47702b89bfb50cb8f`.

[Standalone C file](../../benchmarks/feedback/gemm_tile2_original.c)

```c
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

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

SHA-256: `cc3d74d05400a9e1fae8f93c7e54243b79d3dd7ac02f0c01f108f35a832336b9`.

[Standalone C file](../../benchmarks/feedback/gemm_tile2_optimized.c)

```c
#include <stdint.h>

/* MachSuite-derived reference algorithm; LICENSE.MachSuite is retained.
   Feedback candidate: two local accumulators rather than four. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j+=2) {
            uint32_t s0=0u, s1=0u;
            for(int k=0;k<4;k++) {
                uint32_t value=m1[i*4+k];
                s0+=value*m2[k*4+j];
                s1+=value*m2[k*4+j+1];
            }
            prod[i*4+j]=s0;
            prod[i*4+j+1]=s1;
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.716833 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/gemm_tile2_optimized.json) and [main SMT query](../../results/submission_verification/gemm_tile2_optimized.smt2).

## Seeded negative control

Flip bit zero of the first output element after the full candidate computation.

[Faulty source](../../benchmarks/feedback/gemm_tile2_buggy.c) and [counterexample record](../../results/submission_verification/gemm_tile2_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4506.57 | 5770.6 | 1.28 |
| STA period estimate (ns) | 1.90345 | 3.85838 | 2.027 |
| RTL latency cycles | 122 | 94 | 0.7705 |
| Latency at 10 ns clock (ns) | 1220 | 940 | 0.7705 |
| Area x latency (um² ns) | 5.49802e+06 | 5.42437e+06 | 0.9866 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/gemm_tile2_original/) / [candidate raw evidence](../../results/hls/gemm_tile2_optimized/). Both have sixteen successful RTL calls.

## Related earlier candidates

These share the original algorithm and are follow-up candidates, not independent application samples.

| Candidate pair | Candidate area (um²) | Candidate cycles | ADP ratio against its original |
|---|---:|---:|---:|
| [gemm](gemm.md) | 4760.070 | 266 | 2.303 |
| [gemm_local4](gemm_local4.md) | 11236.904 | 66 | 1.349 |
| [gemm_tile2](gemm_tile2.md) | 5770.604 | 94 | 0.9866 |

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/feedback/gemm_tile2_original.c benchmarks/feedback/gemm_tile2_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_gemm_tile2.smt2
```
