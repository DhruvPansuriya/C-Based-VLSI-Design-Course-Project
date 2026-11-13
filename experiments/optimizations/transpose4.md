# transpose4: Two-element transpose staging

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** data movement.

**Rewrite:** Two-element transpose staging.

**Motivation:** Stage pairs of source reads and expose two destination writes per loop body.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `e822e33f2ab1446568a0fd9cbc159ac474c8f51ad516ff542d72c9d13b516efc`.

[Standalone C file](../../benchmarks/expanded/transpose4_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++) out[c*4+r]=a[r*4+c];
}
```

### Optimized

SHA-256: `ffdb20d20b2e4a4e241360996d69335239dabe560cf8a0ee6a73d964cad377d7`.

[Standalone C file](../../benchmarks/expanded/transpose4_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-element transpose staging. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c+=2){uint32_t x=a[r*4+c],y=a[r*4+c+1];out[c*4+r]=x;out[(c+1)*4+r]=y;}
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 0.007727 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/transpose4_optimized.json) and [main SMT query](../../results/submission_verification/transpose4_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/transpose4_buggy.c) and [counterexample record](../../results/submission_verification/transpose4_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 804.65 | 1390.38 | 1.728 |
| STA period estimate (ns) | 1.49005 | 1.38027 | 0.9263 |
| RTL latency cycles | 58 | 34 | 0.5862 |
| Latency at 10 ns clock (ns) | 580 | 340 | 0.5862 |
| Area x latency (um² ns) | 466697 | 472730 | 1.013 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/transpose4_original/) / [candidate raw evidence](../../results/hls/transpose4_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/transpose4_original.c benchmarks/expanded/transpose4_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_transpose4.smt2
```
