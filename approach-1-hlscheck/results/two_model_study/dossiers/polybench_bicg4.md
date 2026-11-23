# polybench_bicg4

Origin: HLS-Eval / PolyBench

Adapt PolyBench source through HLS-Eval: replace double with uint32_t, flatten row-major arrays, reduce dimensions to4, rename kernel_bicg to kernel, remove external includes and HLS pragma, and use literal loop limits. Dimensions42x38 become4x4. Preserve resetting s/q and the joint row/column accumulations. This unsigned integer benchmark is a new domain; no equivalence to upstream floating point is claimed.

## Frozen original

```c
/* Dataset-derived integer adaptation; see provenance.json and ../README.md. */
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t s[4], uint32_t q[4], uint32_t p[4], uint32_t r[4]) {
    for (int i = 0; i < 4; i++) {
        s[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        q[i] = 0u;
        for (int j = 0; j < 4; j++) {
            s[j] = s[j] + r[i] * a[i * 4 + j];
            q[i] = q[i] + a[i * 4 + j] * p[j];
        }
    }
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/polybench_bicg4/response.txt) | [Exact prompt](../prompts/polybench_bicg4/prompt.txt) | [Proof](../evaluations/qwen15/polybench_bicg4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t s[4], uint32_t q[4], uint32_t p[4], uint32_t r[4]) {
    for (int i = 0; i < 4; i++) {
        s[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        q[i] = 0u;
        for (int j = 0; j < 4; j++) {
            s[j] = s[j] + r[i] * a[i * 4 + j];
            q[i] = q[i] + a[i * 4 + j] * p[j];
        }
    }
}
```

Area: 6523.650 -> 6523.650 um^2. Cycles: 142 -> 142. Critical-path delay: 5.924576 -> 5.924576 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **inconclusive**. Cache p/row elements and use four scalar s accumulators; proof inconclusive.

[Raw response](../generations/gpt61sol/polybench_bicg4/response.txt) | [Exact prompt](../prompts/polybench_bicg4/prompt.txt) | [Proof](../evaluations/gpt61sol/polybench_bicg4/proof/result.json)

```c
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t s[4], uint32_t q[4], uint32_t p[4], uint32_t r[4]) {
    uint32_t s0 = 0u, s1 = 0u, s2 = 0u, s3 = 0u;
    const uint32_t p0 = p[0], p1 = p[1], p2 = p[2], p3 = p[3];

    for (int i = 0; i < 4; ++i) {
        const uint32_t ri = r[i];
        const uint32_t a0 = a[4 * i];
        const uint32_t a1 = a[4 * i + 1];
        const uint32_t a2 = a[4 * i + 2];
        const uint32_t a3 = a[4 * i + 3];

        s0 += ri * a0;
        s1 += ri * a1;
        s2 += ri * a2;
        s3 += ri * a3;
        q[i] = (a0 * p0 + a1 * p1) + (a2 * p2 + a3 * p3);
    }

    s[0] = s0;
    s[1] = s1;
    s[2] = s2;
    s[3] = s3;
}
```
