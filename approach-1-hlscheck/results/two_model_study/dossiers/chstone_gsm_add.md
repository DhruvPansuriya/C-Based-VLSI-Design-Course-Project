# chstone_gsm_add

Origin: CHStone

Reuse the type-preserving original leaf extraction (not any candidate). Retain all typedefs/macros, widths and source notices. Rename only gsm_add to kernel before freezing; remove unrelated compilation-unit material as documented in the earlier extraction. No dimension, type or input-domain reduction.

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
kernel (word a, word b)
{
  longword sum;
  sum = (longword) a + (longword) b;
  return saturate (sum);
}
```

## qwen15

Verdict: **equivalent**. Canonical source unchanged.

[Raw response](../generations/qwen15/chstone_gsm_add/response.txt) | [Exact prompt](../prompts/chstone_gsm_add/prompt.txt) | [Proof](../evaluations/qwen15/chstone_gsm_add/proof/result.json)

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
kernel (word a, word b)
{
  longword sum;
  sum = (longword) a + (longword) b;
  return saturate (sum);
}
```

Area: 105.070 -> 105.070 um^2. Cycles: 1 -> 1. Critical-path delay: 0.928095 -> 0.928095 ns. Area-latency ratio: 1.000000.

## gpt61sol

Verdict: **equivalent**. Biased unsigned range test and one saturation branch.

[Raw response](../generations/gpt61sol/chstone_gsm_add/response.txt) | [Exact prompt](../prompts/chstone_gsm_add/prompt.txt) | [Proof](../evaluations/gpt61sol/chstone_gsm_add/proof/result.json)

```c
typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))

word kernel(word a, word b)
{
    int sum = (int)a + (int)b;
    unsigned int biased = (unsigned int)sum + 32768u;
    if (biased > 65535u)
        return a < 0 ? MIN_WORD : MAX_WORD;
    return (word)sum;
}
```

Area: 105.070 -> 105.070 um^2. Cycles: 1 -> 1. Critical-path delay: 0.928095 -> 0.928095 ns. Area-latency ratio: 1.000000.
