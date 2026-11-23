# machsuite_stencil5

Origin: MachSuite

Reuse the earlier original-only adaptation: 128x64 signed32 grid becomes5x5 uint32 flat grid with unchanged3x3 filter. Writes only the top-left3x3 of a5x5 output; remaining outputs retain incoming values. This is a new unsigned domain, not equivalence to upstream signed arithmetic.

## Frozen original

```c
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    temp += filter[k1 * 3 + k2] * orig[(r + k1) * 5 + c + k2];
                }
            }
            sol[r * 5 + c] = temp;
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/machsuite_stencil5/response.txt) | [Exact prompt](../prompts/machsuite_stencil5/prompt.txt) | [Proof](../evaluations/qwen15/machsuite_stencil5/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    temp += filter[k1 * 3 + k2] * orig[(r + k1) * 5 + c + k2];
                }
            }
            sol[r * 5 + c] = temp;
        }
    }
}
```

Area: 4493.006 -> 4493.006 um^2. Cycles: 158 -> 158. Critical-path delay: 1.896485 -> 1.896485 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Three partial accumulators with unrolled filter columns.

[Raw response](../generations/gpt61sol/machsuite_stencil5/response.txt) | [Exact prompt](../prompts/machsuite_stencil5/prompt.txt) | [Proof](../evaluations/gpt61sol/machsuite_stencil5/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            uint32_t sum0 = 0u;
            uint32_t sum1 = 0u;
            uint32_t sum2 = 0u;
            for (int k = 0; k < 3; ++k) {
                int base = (r + k) * 5 + c;
                sum0 += filter[k * 3] * orig[base];
                sum1 += filter[k * 3 + 1] * orig[base + 1];
                sum2 += filter[k * 3 + 2] * orig[base + 2];
            }
            sol[r * 5 + c] = (sum0 + sum1) + sum2;
        }
    }
}
```

Area: 4493.006 -> 7012.558 um^2. Cycles: 158 -> 116. Critical-path delay: 1.896485 -> 2.138454 ns. Area-latency ratio: 1.145883.
