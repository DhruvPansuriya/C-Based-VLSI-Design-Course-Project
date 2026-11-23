# prefix: incremental prefix accumulation

**Origin:** educational prefix-sum reference.

**Algorithm group:** initial eight-pair cohort.

**Rewrite:** incremental prefix accumulation.

**Motivation:** Expose the recorded transformation to HLS; the measured result determines whether it is accepted.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `966bfcab111db30808da089a868f990161e9e1ece3060b3cb491ae034ec80763`.

[Standalone C file](../../benchmarks/submission/prefix_original.c)

```c
#include <stdint.h>

/* Educational reference: recompute each prefix independently. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        uint32_t sum = 0u;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        out[i] = sum;
    }
}
```

### Optimized

SHA-256: `bce502911df665cc7d079ed4ffddbeb927db71e9b9f4bcc012a6a1ba5109b896`.

[Standalone C file](../../benchmarks/submission/prefix_optimized.c)

```c
#include <stdint.h>

/* LLM rewrite: reuse the preceding prefix instead of recomputing it. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    uint32_t running = 0u;
    for (int i = 0; i < 8; i++) {
        running += a[i];
        out[i] = running;
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.009688 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/prefix_optimized.json) and [main SMT query](../../results/submission_verification/prefix_optimized.smt2).

## Seeded negative control

Deliberate mutation documented at the head of the faulty source file.

[Faulty source](../../benchmarks/submission/prefix_buggy.c) and [counterexample record](../../results/submission_verification/prefix_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1857.48 | 913.178 | 0.4916 |
| STA period estimate (ns) | 1.90062 | 1.50974 | 0.7943 |
| RTL latency cycles | 62 | 26 | 0.4194 |
| Latency at 10 ns clock (ns) | 620 | 260 | 0.4194 |
| Area x latency (um² ns) | 1.15164e+06 | 237426 | 0.2062 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/prefix_original/) / [candidate raw evidence](../../results/hls/prefix_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/submission/prefix_original.c benchmarks/submission/prefix_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_prefix.smt2
```
