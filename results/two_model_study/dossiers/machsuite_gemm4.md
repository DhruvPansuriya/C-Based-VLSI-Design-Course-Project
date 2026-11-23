# machsuite_gemm4

Origin: MachSuite

Reuse the earlier original-only educational adaptation: 64x64 double matrices become4x4 uint32 flat row-major matrices; top function named kernel; no host harness. This is a new integer problem, not equivalent to upstream floating point.

## Frozen original

```c
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            uint32_t sum = 0u;
            for (int k = 0; k < 4; k++) {
                sum += m1[i * 4 + k] * m2[k * 4 + j];
            }
            prod[i * 4 + j] = sum;
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Move accumulation into output array instead of a local scalar.

[Raw response](../generations/qwen15/machsuite_gemm4/response.txt) | [Exact prompt](../prompts/machsuite_gemm4/prompt.txt) | [Proof](../evaluations/qwen15/machsuite_gemm4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            prod[i * 4 + j] = 0u;
            for (int k = 0; k < 4; k++) {
                prod[i * 4 + j] += m1[i * 4 + k] * m2[k * 4 + j];
            }
        }
    }
}
```

Area: 4506.572 -> 4448.318 um^2. Cycles: 122 -> 234. Critical-path delay: 1.903448 -> 1.743472 ns. Area-latency ratio: 1.893239.

## gpt61sol

Verdict: **equivalent**. Unroll the four-product dot product, cache each input row and use grouped additions.

[Raw response](../generations/gpt61sol/machsuite_gemm4/response.txt) | [Exact prompt](../prompts/machsuite_gemm4/prompt.txt) | [Proof](../evaluations/gpt61sol/machsuite_gemm4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; ++i) {
        const uint32_t a0 = m1[i * 4];
        const uint32_t a1 = m1[i * 4 + 1];
        const uint32_t a2 = m1[i * 4 + 2];
        const uint32_t a3 = m1[i * 4 + 3];

        for (int j = 0; j < 4; ++j) {
            prod[i * 4 + j] =
                (a0 * m2[j] + a1 * m2[4 + j]) +
                (a2 * m2[8 + j] + a3 * m2[12 + j]);
        }
    }
}
```

Area: 4506.572 -> 10727.514 um^2. Cycles: 122 -> 82. Critical-path delay: 1.903448 -> 5.867722 ns. Area-latency ratio: 1.599951.
