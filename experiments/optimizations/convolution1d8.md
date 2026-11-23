# convolution1d8: Exploit three-tap coefficient symmetry

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** filter.

**Rewrite:** Exploit three-tap coefficient symmetry.

**Motivation:** Pre-add mirrored samples before multiplication, applied to a sliding valid convolution.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `81c9e816a1f7336112c62a19450ca413634c1c25e15f2af754ddc82a487cb839`.

[Standalone C file](../../benchmarks/expanded/convolution1d8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[8], uint32_t out[6]) {
    for(int i=0;i<6;i++) out[i]=3u*a[i]+5u*a[i+1]+3u*a[i+2];
}
```

### Optimized

SHA-256: `a8e742a655fe604069a34c157530b533d8e4db3dda0d5fc008b2c78860a6ba28`.

[Standalone C file](../../benchmarks/expanded/convolution1d8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Exploit three-tap coefficient symmetry. */
void kernel(uint32_t a[8], uint32_t out[6]) {
    for(int i=0;i<6;i++) out[i]=3u*(a[i]+a[i+2])+5u*a[i+1];
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.004603 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/convolution1d8_optimized.json) and [main SMT query](../../results/submission_verification/convolution1d8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/convolution1d8_buggy.c) and [counterexample record](../../results/submission_verification/convolution1d8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 2310.48 | 2125.07 | 0.9198 |
| STA period estimate (ns) | 2.12461 | 1.72155 | 0.8103 |
| RTL latency cycles | 26 | 26 | 1 |
| Latency at 10 ns clock (ns) | 260 | 260 | 1 |
| Area x latency (um² ns) | 600724 | 552519 | 0.9198 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/convolution1d8_original/) / [candidate raw evidence](../../results/hls/convolution1d8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/convolution1d8_original.c benchmarks/expanded/convolution1d8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_convolution1d8.smt2
```
