# moving_sum_register16: Keep the four-element moving window in scalar registers

**Origin:** Explicit follow-up against the existing benchmarks/expanded/moving_sum16_original.c reference; not a new independent original algorithm.

**Algorithm group:** feedback variants.

**Rewrite:** Keep the four-element moving window in scalar registers.

**Motivation:** Follow up the sliding-sum area regression: load only one new input per output, with explicit local window state instead of rereading the outgoing array element.

**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.

## Exact source artifacts

### Original

SHA-256: `cfa8d1d79c54aec578ff396c4379607c3eaa401a284144ef9f1860943e0192cb`.

[Standalone C file](../../benchmarks/feedback/moving_sum_register16_original.c)

```c
#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    for(int i=0;i<13;i++){uint32_t sum=0u;for(int j=0;j<4;j++) sum+=a[i+j];out[i]=sum;}
}
```

### Optimized

SHA-256: `0c824ac65f29f1f5010f31d08f1bb05470ea7acbd8527a0050530b6a7483fb84`.

[Standalone C file](../../benchmarks/feedback/moving_sum_register16_optimized.c)

```c
#include <stdint.h>

/* Feedback candidate: one new memory read per output after initialization. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t w0=a[0], w1=a[1], w2=a[2], w3=a[3];
    for(int i=0;i<13;i++) {
        out[i]=(w0+w1)+(w2+w3);
        if(i<12) {
            w0=w1;
            w1=w2;
            w2=w3;
            w3=a[i+4];
        }
    }
}
```

## C-to-C result

Verdict: **equivalent**.

Elapsed time: 1.287891 s. Z3: 5.1.0. Accepted unconditional component lemmas: 0.

[Proof record](../../results/submission_verification/moving_sum_register16_optimized.json) and [main SMT query](../../results/submission_verification/moving_sum_register16_optimized.smt2).

## Seeded negative control

Flip bit zero of the first output element after the full candidate computation.

[Faulty source](../../benchmarks/feedback/moving_sum_register16_buggy.c) and [counterexample record](../../results/submission_verification/moving_sum_register16_buggy.json).

The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.

Recorded verdict: **not_equivalent**. The native test runner independently replays its witness and compares concrete outputs with the solver.

## Hardware measurement

| Metric | Original | Candidate | Candidate / original |
|---|---:|---:|---:|
| Mapped cell area (um²) | 978.082 | 4111.03 | 4.203 |
| STA period estimate (ns) | 1.54108 | 1.89855 | 1.232 |
| RTL latency cycles | 93 | 41 | 0.4409 |
| Latency at 10 ns clock (ns) | 930 | 410 | 0.4409 |
| Area x latency (um² ns) | 909616 | 1.68552e+06 | 1.853 |

**Area x latency policy:** retain the original.

Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.

[Original raw evidence](../../results/hls/moving_sum_register16_original/) / [candidate raw evidence](../../results/hls/moving_sum_register16_optimized/). Both have sixteen successful RTL calls.

## Related earlier candidates

These share the original algorithm and are follow-up candidates, not independent application samples.

| Candidate pair | Candidate area (um²) | Candidate cycles | ADP ratio against its original |
|---|---:|---:|---:|
| [moving_sum16](moving_sum16.md) | 3338.566 | 41 | 1.505 |
| [moving_sum_register16](moving_sum_register16.md) | 4111.030 | 41 | 1.853 |

## Reproduce this proof

```powershell
.\.venv\Scripts\python.exe -m hlscheck benchmarks/feedback/moving_sum_register16_original.c benchmarks/feedback/moving_sum_register16_optimized.c --function kernel --timeout-ms 30000 --smt results/recheck_moving_sum_register16.smt2
```
