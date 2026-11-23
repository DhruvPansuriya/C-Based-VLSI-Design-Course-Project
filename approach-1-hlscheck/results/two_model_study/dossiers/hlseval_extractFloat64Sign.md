# hlseval_extractFloat64Sign

Origin: hls-eval

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only extractFloat64Sign to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

## Frozen original

```c
typedef int flag;
typedef unsigned long long float64;
flag kernel(float64 a) { return a >> 63; }
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/hlseval_extractFloat64Sign/response.txt) | [Exact prompt](../prompts/hlseval_extractFloat64Sign/prompt.txt) | [Proof](../evaluations/qwen15/hlseval_extractFloat64Sign/proof/result.json)

```c
#include <stdint.h>

typedef int flag;
typedef unsigned long long float64;

flag kernel(float64 a) {
    return a >> 63;
}
```

Area: 0.532 -> 0.532 um^2. Cycles: 1 -> 1. Critical-path delay: 0.054166 -> 0.054166 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Explicit return cast; the sign extraction remains the same.

[Raw response](../generations/gpt61sol/hlseval_extractFloat64Sign/response.txt) | [Exact prompt](../prompts/hlseval_extractFloat64Sign/prompt.txt) | [Proof](../evaluations/gpt61sol/hlseval_extractFloat64Sign/proof/result.json)

```c
typedef int flag;
typedef unsigned long long float64;

flag kernel(float64 a) {
    return (flag)(a >> 63);
}
```

Area: 0.532 -> 0.532 um^2. Cycles: 1 -> 1. Critical-path delay: 0.054166 -> 0.054166 ns. Area-latency ratio: 1.000000.
