# min8: Balanced comparison tree

**Origin:** Educational fixed-size uint32_t kernel, authored independently in this Codex session.

**Algorithm group:** comparison reduction.

**Rewrite:** Balanced comparison tree.

**Motivation:** Replace seven serial comparison/select steps with a three-level tree; related min/max variants are reported as such.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `e0f2736d0afd4329c5ffea1780fefe1c220376cec7299674eb71a7808fdf68e6`.

[Standalone C file](../../benchmarks/expanded/min8_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t value=a[0];for(int i=1;i<8;i++) value=a[i]<value?a[i]:value;return value;
}
```

### Optimized

SHA-256: `77308c91e803c6e2af851cd5d2bf5c057e4a24a5da346df750561fb469d76f03`.

[Standalone C file](../../benchmarks/expanded/min8_optimized.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Balanced comparison tree. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t p0=a[0]<a[1]?a[0]:a[1];
    uint32_t p1=a[2]<a[3]?a[2]:a[3];
    uint32_t p2=a[4]<a[5]?a[4]:a[5];
    uint32_t p3=a[6]<a[7]?a[6]:a[7];
    uint32_t q0=p0<p1?p0:p1;uint32_t q1=p2<p3?p2:p3;return q0<q1?q0:q1;
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 1.661253 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/min8_optimized.json) and [main SMT query](../../results/submission_verification/min8_optimized.smt2).

## Seeded negative control

Flip bit zero of the scalar return or first designated output element.

[Faulty source](../../benchmarks/expanded/min8_buggy.c) and [counterexample record](../../results/submission_verification/min8_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 803.054 | 4145.08 | 5.162 |
| STA period estimate (ns) | 1.39448 | 2.80211 | 2.009 |
| RTL latency cycles | 11 | 5 | 0.4545 |
| Latency at 10 ns clock (ns) | 110 | 50 | 0.4545 |
| Area x latency (um² ns) | 88335.9 | 207254 | 2.346 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/min8_original/) / [candidate raw evidence](../../results/hls/min8_optimized/). Both have sixteen successful RTL calls.

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/expanded/min8_original.c benchmarks/expanded/min8_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_min8.smt2
```
