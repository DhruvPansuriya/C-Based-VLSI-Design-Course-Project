# clamp16: Upper-bit saturation test

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** elementwise.

**Rewrite:** Upper-bit saturation test.

**Motivation:** Exploit the power-of-two unsigned threshold; the compiler may already recognize the same hardware.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `56c2d7705f9463d60ad8bd2fea34de250b729e1cf65313b1ad1f4f2fa6b6fd92`.

[Standalone C file](../../benchmarks/expanded/clamp16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<16;i++) out[i]=a[i]>255u?255u:a[i];
}
```

### Optimized

SHA-256: `94d6a370e325446f7f65eb4ac867dc3fb2c040e498ca16822cfdb17b79df0961`.

[Standalone C file](../../benchmarks/expanded/clamp16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Upper-bit saturation test. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t v=a[i];out[i]=(v>>8)!=0u?255u:v;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.014511 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/clamp16_optimized.json) and [main SMT query](../../results/submission_verification/clamp16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/clamp16_buggy.c) and [counterexample record](../../results/submission_verification/clamp16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 619.78 | 619.78 | 1 |
| STA period estimate (ns) | 1.32287 | 1.32287 | 1 |
| RTL latency cycles | 50 | 50 | 1 |
| Latency at 10 ns clock (ns) | 500 | 500 | 1 |
| Area x latency (um² ns) | 309890 | 309890 | 1 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/clamp16_original/) / [candidate raw evidence](../../results/hls/clamp16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/clamp16_original.c benchmarks/expanded/clamp16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_clamp16.smt2
```
