# polybench_syrk4

Origin: HLS-Eval / PolyBench

Adapt PolyBench source through HLS-Eval: replace double with uint32_t, flatten row-major arrays, reduce dimensions to4, rename kernel_syrk to kernel, remove external includes and HLS pragma, and use literal loop limits. Dimensions30x30 and30x20 become4x4. Preserve the beta scaling, alpha accumulation and lower-triangle-only writes; upper-triangle c retains initial values. This unsigned integer benchmark is a new domain; no equivalence to upstream floating point is claimed.

## Frozen original

```c
/* Dataset-derived integer adaptation; see provenance.json and ../README.md. */
#include <stdint.h>

void kernel(uint32_t alpha, uint32_t beta, uint32_t c[16], uint32_t a[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            c[i * 4 + j] *= beta;
        }
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j <= i; j++) {
                c[i * 4 + j] += alpha * a[i * 4 + k] * a[j * 4 + k];
            }
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/polybench_syrk4/response.txt) | [Exact prompt](../prompts/polybench_syrk4/prompt.txt) | [Proof](../evaluations/qwen15/polybench_syrk4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t alpha, uint32_t beta, uint32_t c[16], uint32_t a[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            c[i * 4 + j] *= beta;
        }
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j <= i; j++) {
                c[i * 4 + j] += alpha * a[i * 4 + k] * a[j * 4 + k];
            }
        }
    }
}
```

Area: 10619.518 -> 10619.518 um^2. Cycles: 232 -> 232. Critical-path delay: 4.231561 -> 4.231561 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Factor alpha outside the dot product and update each lower-triangle c element once.

[Raw response](../generations/gpt61sol/polybench_syrk4/response.txt) | [Exact prompt](../prompts/polybench_syrk4/prompt.txt) | [Proof](../evaluations/gpt61sol/polybench_syrk4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t alpha, uint32_t beta, uint32_t c[16], uint32_t a[16]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j <= i; ++j) {
            uint32_t sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += a[i * 4 + k] * a[j * 4 + k];
            }
            c[i * 4 + j] = beta * c[i * 4 + j] + alpha * sum;
        }
    }
}
```

Area: 10619.518 -> 6405.546 um^2. Cycles: 232 -> 100. Critical-path delay: 4.231561 -> 4.938995 ns. Area-latency ratio: 0.259994.
