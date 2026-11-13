# absdiff16: Share comparison before subtraction

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** elementwise.

**Rewrite:** Share comparison before subtraction.

**Motivation:** Select larger/smaller operands then subtract; may change mux/subtractor sharing.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `4fb2285ef52ac7db6a24b12d781463f465ed133b75417305c6e0cf67b272ba28`.

[Standalone C file](../../benchmarks/expanded/absdiff16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++) out[i]=a[i]>b[i]?a[i]-b[i]:b[i]-a[i];
}
```

### Optimized

SHA-256: `881fc122466cc057304e1f0f6f7cc2d064b7204c0e294ab15ed29b3276e46e44`.

[Standalone C file](../../benchmarks/expanded/absdiff16_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Share comparison before subtraction. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?y:x;out[i]=high-low;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 3.295092 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/absdiff16_optimized.json) and [main SMT query](../../results/submission_verification/absdiff16_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/absdiff16_buggy.c) and [counterexample record](../../results/submission_verification/absdiff16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 1261.64 | 1258.18 | 0.9973 |
| STA period estimate (ns) | 1.40177 | 1.57808 | 1.126 |
| RTL latency cycles | 50 | 50 | 1 |
| Latency at 10 ns clock (ns) | 500 | 500 | 1 |
| Area x latency (um² ns) | 630819 | 629090 | 0.9973 |

**Area x latency policy:** select the candidate.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/absdiff16_original/) / [candidate raw evidence](../../results/hls/absdiff16_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/absdiff16_original.c benchmarks/expanded/absdiff16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_absdiff16.smt2
```
