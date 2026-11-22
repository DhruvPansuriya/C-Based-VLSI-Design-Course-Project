# hlseval_float64_is_nan

Origin: hls-eval

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only float64_is_nan to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

## Frozen original

```c
typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;
flag kernel(float64 a) {
    return (0xFFE0000000000000LL < (bits64)(a << 1));
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/hlseval_float64_is_nan/response.txt) | [Exact prompt](../prompts/hlseval_float64_is_nan/prompt.txt) | [Proof](../evaluations/qwen15/hlseval_float64_is_nan/proof/result.json)

```c
#include <stdint.h>

typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;
flag kernel(float64 a) {
    return (0xFFE0000000000000LL < (bits64)(a << 1));
}
```

Area: 29.792 -> 29.792 um^2. Cycles: 1 -> 1. Critical-path delay: 0.200968 -> 0.200968 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Exponent/fraction predicates replace the shifted-pattern comparison.

[Raw response](../generations/gpt61sol/hlseval_float64_is_nan/response.txt) | [Exact prompt](../prompts/hlseval_float64_is_nan/prompt.txt) | [Proof](../evaluations/gpt61sol/hlseval_float64_is_nan/proof/result.json)

```c
typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;

flag kernel(float64 a) {
    return ((a & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL)
         & ((a & 0x000FFFFFFFFFFFFFULL) != 0);
}
```

Area: 29.792 -> 29.792 um^2. Cycles: 1 -> 1. Critical-path delay: 0.200968 -> 0.200968 ns. Area-latency ratio: 1.000000.
