# chstone_gsm_abs

Origin: CHStone

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only gsm_abs to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

## Frozen original

```c
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */


typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))
word
kernel (word a)
{
  return a < 0 ? (a == MIN_WORD ? MAX_WORD : -a) : a;
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/chstone_gsm_abs/response.txt) | [Exact prompt](../prompts/chstone_gsm_abs/prompt.txt) | [Proof](../evaluations/qwen15/chstone_gsm_abs/proof/result.json)

```c
/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */


typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))
word
kernel (word a)
{
  return a < 0 ? (a == MIN_WORD ? MAX_WORD : -a) : a;
}
```

Area: 63.042 -> 63.042 um^2. Cycles: 1 -> 1. Critical-path delay: 0.769578 -> 0.769578 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Unsigned bitwise magnitude and explicit saturation adjustment.

[Raw response](../generations/gpt61sol/chstone_gsm_abs/response.txt) | [Exact prompt](../prompts/chstone_gsm_abs/prompt.txt) | [Proof](../evaluations/gpt61sol/chstone_gsm_abs/proof/result.json)

```c
typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))

word kernel(word a)
{
    unsigned short bits = (unsigned short)a;
    unsigned short sign = (unsigned short)(0u - (bits >> 15));
    unsigned short magnitude =
        (unsigned short)((bits ^ sign) + (bits >> 15));
    return (word)(magnitude - (magnitude >> 15));
}
```

Area: 63.042 -> 72.618 um^2. Cycles: 1 -> 1. Critical-path delay: 0.769578 -> 0.650275 ns. Area-latency ratio: 1.151899.
