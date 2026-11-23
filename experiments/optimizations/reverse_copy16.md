# reverse_copy16: Paired reverse-copy staging

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** data movement.

**Rewrite:** Paired reverse-copy staging.

**Motivation:** Read symmetric input pairs and emit two output writes per iteration.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `a205e3127f87a1f95d50bd1575633d4908056dc2614e5409b20fa61c5600981f`.

[Standalone C file](../../benchmarks/expanded/reverse_copy16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<16;i++) out[15-i]=a[i];
}
```

### Optimized

SHA-256: `c1e64150cf09797c6f4e754aa8bb8cef96008e3863c8ab1495459d25ca21445f`.

[Standalone C file](../../benchmarks/expanded/reverse_copy16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Paired reverse-copy staging. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<8;i++){uint32_t x=a[i],y=a[15-i];out[i]=y;out[15-i]=x;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.006280 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/reverse_copy16_optimized.json) and [main SMT query](../../results/submission_verification/reverse_copy16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/reverse_copy16_buggy.c) and [counterexample record](../../results/submission_verification/reverse_copy16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 784.7 | 1412.73 | 1.8 |
| STA period estimate (ns) | 1.32737 | 1.79115 | 1.349 |
| RTL latency cycles | 50 | 34 | 0.68 |
| Latency at 10 ns clock (ns) | 500 | 340 | 0.68 |
| Area x latency (um² ns) | 392350 | 480327 | 1.224 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/reverse_copy16_original/) / [candidate raw evidence](../../results/hls/reverse_copy16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/reverse_copy16_original.c benchmarks/expanded/reverse_copy16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_reverse_copy16.smt2
```
