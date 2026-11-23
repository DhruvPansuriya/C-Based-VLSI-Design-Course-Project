# gemm: loop interchange and scalar reuse

**Origin:** MachSuite gemm/ncubed adapted to uint32_t and 4x4 dimensions.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** loop interchange and scalar reuse.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `d34b316a62c77526f14598b5987f8b8a1dfe86a57d3bbda47702b89bfb50cb8f`.

[Standalone C file](../../benchmarks/machsuite_u32/gemm_original.c)

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

SHA-256: `b00c6d42d612683b6b151b710171bdf6aefe6bd070f22ec3479d29cb5afedebd`.

[Standalone C file](../../benchmarks/machsuite_u32/gemm_optimized.c)

```c
/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int p = 0; p < 16; p++) {
        prod[p] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            uint32_t a = m1[i * 4 + k];
            for (int j = 0; j < 4; j++) {
                prod[i * 4 + j] += a * m2[k * 4 + j];
            }
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.033113 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/gemm_optimized.json) and [main SMT query](../../results/submission_verification/gemm_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/machsuite_u32/gemm_buggy.c) and [counterexample record](../../results/submission_verification/gemm_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 4506.57 | 4760.07 | 1.056 |
| STA period estimate (ns) | 1.90345 | 2.21755 | 1.165 |
| RTL latency cycles | 122 | 266 | 2.18 |
| Latency at 10 ns clock (ns) | 1220 | 2660 | 2.18 |
| Area x latency (um² ns) | 5.49802e+06 | 1.26618e+07 | 2.303 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/gemm_original/) / [candidate raw evidence](../../results/hls/gemm_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/machsuite_u32/gemm_original.c benchmarks/machsuite_u32/gemm_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_gemm.smt2
```
