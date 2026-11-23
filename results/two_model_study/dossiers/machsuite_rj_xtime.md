# machsuite_rj_xtime

Origin: MachSuite

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only rj_xtime to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

## Frozen original

```c
#include <stdint.h>
uint8_t kernel(uint8_t x)
{
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/machsuite_rj_xtime/response.txt) | [Exact prompt](../prompts/machsuite_rj_xtime/prompt.txt) | [Proof](../evaluations/qwen15/machsuite_rj_xtime/proof/result.json)

```c
#include <stdint.h>

typedef uint8_t uint8_t_t;
typedef uint16_t uint16_t_t;
typedef uint32_t uint32_t_t;
typedef uint64_t uint64_t_t;

uint8_t_t kernel(uint8_t_t x)
{
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}
```

Area: 6.118 -> 6.118 um^2. Cycles: 1 -> 1. Critical-path delay: 0.097150 -> 0.097150 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Replace conditional reduction with branchless top-bit-controlled XOR.

[Raw response](../generations/gpt61sol/machsuite_rj_xtime/response.txt) | [Exact prompt](../prompts/machsuite_rj_xtime/prompt.txt) | [Proof](../evaluations/gpt61sol/machsuite_rj_xtime/proof/result.json)

```c
#include <stdint.h>

uint8_t kernel(uint8_t x)
{
    return (uint8_t)((x << 1) ^ ((x >> 7) * 0x1b));
}
```

Area: 6.118 -> 6.118 um^2. Cycles: 1 -> 1. Critical-path delay: 0.097150 -> 0.097150 ns. Area-latency ratio: 1.000000.
