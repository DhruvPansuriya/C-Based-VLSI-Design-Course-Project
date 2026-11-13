# threshold_pack8: Split threshold packing into two independent lanes

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** elementwise.

**Rewrite:** Split threshold packing into two independent lanes.

**Motivation:** Expose four low and four high output-bit computations independently.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `e7cb3ff3a207b30b239e82a3187b757ee56b6a7a9cbb1178a28b3b695ae7f4a5`.

[Standalone C file](../../benchmarks/expanded/threshold_pack8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t packed=0u;for(int i=0;i<8;i++) packed|=(a[i]>128u?1u:0u)<<i;return packed;
}
```

### Optimized

SHA-256: `36529014c0438b2b75719410233e401b9ec426b925c34b90c8289ebc1f8c8c4b`.

[Standalone C file](../../benchmarks/expanded/threshold_pack8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Split threshold packing into two independent lanes. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t lo=0u,hi=0u;for(int i=0;i<4;i++){lo|=(a[i]>128u?1u:0u)<<i;hi|=(a[i+4]>128u?1u:0u)<<i;}return lo|(hi<<4);
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.022528 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/threshold_pack8_optimized.json) and [main SMT query](../../results/submission_verification/threshold_pack8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/threshold_pack8_buggy.c) and [counterexample record](../../results/submission_verification/threshold_pack8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 250.838 | 326.648 | 1.302 |
| STA period estimate (ns) | 1.06167 | 1.00928 | 0.9507 |
| RTL latency cycles | 11 | 7 | 0.6364 |
| Latency at 10 ns clock (ns) | 110 | 70 | 0.6364 |
| Area x latency (um² ns) | 27592.2 | 22865.4 | 0.8287 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/threshold_pack8_original/) / [candidate raw evidence](../../results/hls/threshold_pack8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/threshold_pack8_original.c benchmarks/expanded/threshold_pack8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_threshold_pack8.smt2
```
