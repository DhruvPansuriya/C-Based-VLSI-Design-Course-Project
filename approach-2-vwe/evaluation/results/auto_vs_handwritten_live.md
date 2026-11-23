# Auto versus handwritten interpretations (examples 1, 2, 4)

**Generator:** live models via Groq: groq_gptoss, groq_qwen (seed 0, prompts v2). Live families answering: ['groq_gptoss', 'groq_qwen']. Each difference below is explained from the generated readings.

| task | candidate | handwritten | auto (live) | |
|---|---|---|---|---|
| ex1_saturate | v1 | ACCEPT E2 | UNDECIDED - | DIFFERENT |
| ex1_saturate | v2 | ACCEPT E2 | UNDECIDED - | DIFFERENT |
| ex1_saturate | v3 | REJECT E1 | UNDECIDED - | DIFFERENT |
| ex1_saturate | v4 | REJECT E2 | UNDECIDED - | DIFFERENT |
| ex1_saturate | v5 | REJECT E2 | UNDECIDED - | DIFFERENT |
| ex2_argmax | v1 | ACCEPT E2 | UNDECIDED - | DIFFERENT |
| ex2_argmax | v2 | REJECT E1 | UNDECIDED - | DIFFERENT |
| ex2_argmax | v3 | REJECT E0 | REJECT E0 | same |
| ex4_sum | v1 | ACCEPT E2 | ACCEPT E2 | same |
| ex4_sum | v2 | REJECT E0 | REJECT E0 | same |

Differences: 7 of 10.
## Why the 7 differences occur (from the run reports)

All 7 are abstentions; there is no contradictory decision (no auto ACCEPT where the
handwritten set REJECTs, or vice versa).

* **Example 1 (5 candidates).** gpt-oss's adversarial reading covers the whole domain with
  two clauses but sets Ext to `unknown`; any unknown Ext makes E1 non-decisive, so every
  candidate is UNDECIDED ("scope is unresolved"). See Q26.
* **Example 2 v1, v2.** gpt-oss's adversarial reading uses the pointer `idx` in a zone
  (`n == 0 && idx != 0`), which the contract language cannot evaluate; its validation is
  UNKNOWN, and UNKNOWN readings block universal verdicts instead of being deleted
  (AGENTS.md rule 7). The gpt-oss permissive call hit the free-tier token limit and
  contributed no reading. v3 (new UB) is still REJECT E0, which needs no reading.
* **Example 4.** Both verdicts match.

The live readings are conservative-safe here but cost coverage; the handwritten readings
are tighter. This is a measurement on 3 authored examples, not a benchmark.

## Generated readings

### ex1_saturate (set `10ad774b05b2`)
- ex1_saturate.groq_gptoss.strict.0: `a + b > 255` -> `out_ret == 255`; ext `out_ret == old_ret`; reach `a + b > 255`
- ex1_saturate.groq_gptoss.permissive.0: `a + b > 255` -> `out_ret == 255`; ext `out_ret == old_ret`; reach `a + b > 255`
- ex1_saturate.groq_gptoss.adversarial.0: `a + b > 255` -> `out_ret == 255`; `a + b <= 255` -> `out_ret == a + b`; ext `unknown`; reach `true`
- ex1_saturate.groq_qwen.strict.0: `a + b > 255` -> `out_ret == 255`; ext `out_ret == old_ret`; reach `a + b > 255`
- ex1_saturate.groq_qwen.permissive.0: `a + b > 255` -> `out_ret == 255`; ext `out_ret == old_ret`; reach `a + b > 255`
- ex1_saturate.groq_qwen.adversarial.0: `a + b > 255` -> `out_ret == 255`; ext `out_ret == old_ret`; reach `a + b > 255`

### ex2_argmax (set `8b8cbf0eda8a`)
- ex2_argmax.groq_gptoss.strict.0: `n == 0` -> `out_ret == INT_MIN && out_idx[0] == -1`; ext `out_ret == old_ret && out_idx[0] == old_idx[0]`; reach `n == 0`
- ex2_argmax.groq_gptoss.adversarial.0: `n == 0 && idx != 0` -> `out_ret == INT_MIN && out_idx[0] == -1`; `n == 0 && idx == 0` -> `out_ret == INT_MIN`; ext `out_ret == old_ret && out_idx[0] == old_idx[0]`; reach `n == 0`
- ex2_argmax.groq_qwen.strict.0: `n == 0` -> `out_ret == INT_MIN && out_idx[0] == -1`; ext `out_ret == old_ret && out_idx[0] == old_idx[0]`; reach `n == 0`
- ex2_argmax.groq_qwen.permissive.0: `n == 0` -> `out_ret == INT_MIN && out_idx[0] == -1`; ext `out_ret == old_ret && out_idx[0] == old_idx[0]`; reach `n == 0`
- ex2_argmax.groq_qwen.adversarial.0: `n == 0` -> `out_ret == INT_MIN && out_idx[0] == -1`; ext `out_ret == old_ret && out_idx[0] == old_idx[0]`; reach `n == 0`
- groq_gptoss/permissive: failed provider error: HTTP 429 (tokens, rate_limit_exceeded)

### ex4_sum (set `30ed111cb202`)
- ex4_sum.groq_gptoss.strict.0: `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 1`
- ex4_sum.groq_gptoss.permissive.0: `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 1`
- ex4_sum.groq_gptoss.adversarial.0: `n == 0` -> `out_ret == 0`; `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 0`
- ex4_sum.groq_qwen.strict.0: `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 1`
- ex4_sum.groq_qwen.permissive.0: `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 1`
- ex4_sum.groq_qwen.adversarial.0: `n >= 1` -> `out_ret == sum(i, 0, n, a[i])`; ext `out_ret == old_ret`; reach `n >= 1`

