# polybench_mvt4

Origin: HLS-Eval / PolyBench

Adapt PolyBench source through HLS-Eval: replace double with uint32_t, flatten row-major arrays, reduce dimensions to4, rename kernel_mvt to kernel, remove external includes and HLS pragma, and use literal loop limits. Dimension40 becomes4. The two accumulations retain their initial x1/x2 values; y_1,y_2 and matrix remain observable and unchanged. This unsigned integer benchmark is a new domain; no equivalence to upstream floating point is claimed.

## Frozen original

```c
/* Dataset-derived integer adaptation; see provenance.json and ../README.md. */
#include <stdint.h>

void kernel(uint32_t x1[4], uint32_t x2[4], uint32_t y_1[4], uint32_t y_2[4], uint32_t a[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            x1[i] = x1[i] + a[i * 4 + j] * y_1[j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            x2[i] = x2[i] + a[j * 4 + i] * y_2[j];
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Compound assignment spelling only.

[Raw response](../generations/qwen15/polybench_mvt4/response.txt) | [Exact prompt](../prompts/polybench_mvt4/prompt.txt) | [Proof](../evaluations/qwen15/polybench_mvt4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t x1[4], uint32_t x2[4], uint32_t y_1[4], uint32_t y_2[4], uint32_t a[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            x1[i] += a[i * 4 + j] * y_1[j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            x2[i] += a[j * 4 + i] * y_2[j];
        }
    }
}
```

Area: 5498.752 -> 5498.752 um^2. Cycles: 122 -> 122. Critical-path delay: 2.824075 -> 2.824075 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Fuse the two output loops and unroll four-product sums.

[Raw response](../generations/gpt61sol/polybench_mvt4/response.txt) | [Exact prompt](../prompts/polybench_mvt4/prompt.txt) | [Proof](../evaluations/gpt61sol/polybench_mvt4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t x1[4], uint32_t x2[4], uint32_t y_1[4], uint32_t y_2[4], uint32_t a[16]) {
    for (int i = 0; i < 4; ++i) {
        uint32_t p0 = a[4 * i] * y_1[0];
        uint32_t p1 = a[4 * i + 1] * y_1[1];
        uint32_t p2 = a[4 * i + 2] * y_1[2];
        uint32_t p3 = a[4 * i + 3] * y_1[3];
        uint32_t q0 = a[i] * y_2[0];
        uint32_t q1 = a[4 + i] * y_2[1];
        uint32_t q2 = a[8 + i] * y_2[2];
        uint32_t q3 = a[12 + i] * y_2[3];

        x1[i] += (p0 + p1) + (p2 + p3);
        x2[i] += (q0 + q1) + (q2 + q3);
    }
}
```

Area: 5498.752 -> 15797.740 um^2. Cycles: 122 -> 58. Critical-path delay: 2.824075 -> 6.364731 ns. Area-latency ratio: 1.365837.
