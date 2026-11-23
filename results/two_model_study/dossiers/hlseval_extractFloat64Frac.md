# hlseval_extractFloat64Frac

Origin: hls-eval

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only extractFloat64Frac to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

## Frozen original

```c
typedef unsigned long long int bits64;
typedef unsigned long long float64;
bits64 kernel(float64 a) { return a & 0x000FFFFFFFFFFFFFLL; }
```

## qwen15

Verdict: **equivalent**. Equivalent typedef/mask spelling.

[Raw response](../generations/qwen15/hlseval_extractFloat64Frac/response.txt) | [Exact prompt](../prompts/hlseval_extractFloat64Frac/prompt.txt) | [Proof](../evaluations/qwen15/hlseval_extractFloat64Frac/proof/result.json)

```c
#include <stdint.h>

typedef uint64_t bits64;
typedef uint64_t float64;
bits64 kernel(float64 a) { return a & 0xFFFFFFFFFFFFFLL; }
```

Area: 0.532 -> 0.532 um^2. Cycles: 1 -> 1. Critical-path delay: 0.054166 -> 0.054166 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Explicit unsigned mask suffix; no algorithmic change.

[Raw response](../generations/gpt61sol/hlseval_extractFloat64Frac/response.txt) | [Exact prompt](../prompts/hlseval_extractFloat64Frac/prompt.txt) | [Proof](../evaluations/gpt61sol/hlseval_extractFloat64Frac/proof/result.json)

```c
typedef unsigned long long int bits64;
typedef unsigned long long float64;

bits64 kernel(float64 a)
{
    return a & 0x000FFFFFFFFFFFFFULL;
}
```

Area: 0.532 -> 0.532 um^2. Cycles: 1 -> 1. Critical-path delay: 0.054166 -> 0.054166 ns. Area-latency ratio: 1.000000.
