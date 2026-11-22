# crc8_byte: Two-step CRC recurrence unrolling

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** bit manipulation.

**Rewrite:** Two-step CRC recurrence unrolling.

**Motivation:** Unroll a byte-wide polynomial-0x07 recurrence by two; this is a small CRC-like educational primitive, not a named protocol conformance claim.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `f04edd847694922146bf747e0f02e2e0b23b2b72be2243fa87fabfb1b3638377`.

[Standalone C file](../../benchmarks/expanded/crc8_byte_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t crc=x&255u;for(int i=0;i<8;i++){crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;}return crc;
}
```

### Optimized

SHA-256: `101ffea38ff971d3fb6f850aa065ade20bc73dc79c582284e499c58d2f60d5b8`.

[Standalone C file](../../benchmarks/expanded/crc8_byte_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-step CRC recurrence unrolling. */
uint32_t kernel(uint32_t x) {
    uint32_t crc=x&255u;for(int i=0;i<4;i++){crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;}return crc;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.010374 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/crc8_byte_optimized.json) and [main SMT query](../../results/submission_verification/crc8_byte_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/crc8_byte_buggy.c) and [counterexample record](../../results/submission_verification/crc8_byte_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 119.434 | 119.966 | 1.004 |
| STA period estimate (ns) | 0.322509 | 0.323469 | 1.003 |
| RTL latency cycles | 10 | 6 | 0.6 |
| Latency at 10 ns clock (ns) | 100 | 60 | 0.6 |
| Area x latency (um² ns) | 11943.4 | 7197.96 | 0.6027 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/crc8_byte_original/) / [candidate raw evidence](../../results/hls/crc8_byte_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/crc8_byte_original.c benchmarks/expanded/crc8_byte_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_crc8_byte.smt2
```
