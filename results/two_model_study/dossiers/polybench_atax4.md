# polybench_atax4

Origin: HLS-Eval / PolyBench

Adapt PolyBench source through HLS-Eval: replace double with uint32_t, flatten row-major arrays, reduce dimensions to4, rename kernel_atax to kernel, remove external includes and HLS pragma, and use literal loop limits. Rectangular38x42 dimensions become4x4. Preserve y/tmp initialization and both multiply-accumulation nests; tmp remains an observable output. This unsigned integer benchmark is a new domain; no equivalence to upstream floating point is claimed.

## Frozen original

```c
/* Dataset-derived integer adaptation; see provenance.json and ../README.md. */
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t tmp[4]) {
    for (int i = 0; i < 4; i++) {
        y[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        tmp[i] = 0u;
        for (int j = 0; j < 4; j++) {
            tmp[i] = tmp[i] + a[i * 4 + j] * x[j];
        }
        for (int j = 0; j < 4; j++) {
            y[j] = y[j] + a[i * 4 + j] * tmp[i];
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/polybench_atax4/response.txt) | [Exact prompt](../prompts/polybench_atax4/prompt.txt) | [Proof](../evaluations/qwen15/polybench_atax4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t tmp[4]) {
    for (int i = 0; i < 4; i++) {
        y[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        tmp[i] = 0u;
        for (int j = 0; j < 4; j++) {
            tmp[i] = tmp[i] + a[i * 4 + j] * x[j];
        }
        for (int j = 0; j < 4; j++) {
            y[j] = y[j] + a[i * 4 + j] * tmp[i];
        }
    }
}
```

Area: 6385.330 -> 6385.330 um^2. Cycles: 126 -> 126. Critical-path delay: 7.357983 -> 7.357983 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **inconclusive**. Cache x/row elements, unroll the dot product and use four output accumulators; proof inconclusive.

[Raw response](../generations/gpt61sol/polybench_atax4/response.txt) | [Exact prompt](../prompts/polybench_atax4/prompt.txt) | [Proof](../evaluations/gpt61sol/polybench_atax4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t tmp[4]) {
    const uint32_t x0 = x[0];
    const uint32_t x1 = x[1];
    const uint32_t x2 = x[2];
    const uint32_t x3 = x[3];
    uint32_t y0 = 0u;
    uint32_t y1 = 0u;
    uint32_t y2 = 0u;
    uint32_t y3 = 0u;

    for (int i = 0; i < 4; ++i) {
        const uint32_t a0 = a[4 * i];
        const uint32_t a1 = a[4 * i + 1];
        const uint32_t a2 = a[4 * i + 2];
        const uint32_t a3 = a[4 * i + 3];
        const uint32_t t = (a0 * x0 + a1 * x1)
                         + (a2 * x2 + a3 * x3);
        tmp[i] = t;
        y0 += a0 * t;
        y1 += a1 * t;
        y2 += a2 * t;
        y3 += a3 * t;
    }

    y[0] = y0;
    y[1] = y1;
    y[2] = y2;
    y[3] = y3;
}
```
