# Generated interpretations for `chrysalis_chstone_abs_use` (request `original`)

Set hash: `630f9c2c68a424ef06c9efb0b93de2678058b629860676123f84f70d184eacfd`. Families: groq_gptoss, groq_qwen. Families answered live in this run: groq_gptoss, groq_qwen.
No candidate or evaluation data was sent to any model. These are conditional readings; validity checks do not prove they match the English request.

## chrysalis_chstone_abs_use.groq_gptoss.strict.0
- source: llm / groq_gptoss / prompt strict
- reading: When n is negative return its negation; otherwise behave exactly as before.
- when `n < 0`: `out_ret == -n`
- elsewhere: `out_ret == old_ret`
- reach: `n < 0`

## chrysalis_chstone_abs_use.groq_gptoss.permissive.0
- source: llm / groq_gptoss / prompt permissive
- reading: When n is negative, return its negation (the absolute value) using unsigned‑safe arithmetic; otherwise the function behaves exactly as before.
- when `n < 0`: `out_ret == (n < 0 ? -n : n)`
- elsewhere: `out_ret == old_ret`
- reach: `n < 0`

## chrysalis_chstone_abs_use.groq_gptoss.adversarial.0
- source: llm / groq_gptoss / prompt adversarial
- reading: For non‑negative inputs the function behaves exactly as before; for negative inputs it returns the unsigned reinterpretation of n (n & UINT_MAX), leaving all other behavior unchanged.
- when `n >= 0`: `out_ret == old_ret`
- when `n < 0`: `out_ret == (n & UINT_MAX)`
- elsewhere: `out_ret == old_ret`
- reach: `true`

## chrysalis_chstone_abs_use.groq_qwen.strict.0
- source: llm / groq_qwen / prompt strict
- reading: When n is negative, return -n to correct the sign-extension error; otherwise behave exactly as before.
- when `n < 0`: `out_ret == -n`
- elsewhere: `out_ret == old_ret`
- reach: `n < 0`

## chrysalis_chstone_abs_use.groq_qwen.permissive.0
- source: llm / groq_qwen / prompt permissive
- reading: When n is negative, return the correct absolute value -n; otherwise behave exactly as before.
- when `n < 0`: `out_ret == -n`
- when `n >= 0`: `out_ret == n`
- elsewhere: `out_ret == old_ret`
- reach: `n < 0`

## chrysalis_chstone_abs_use.groq_qwen.adversarial.0
- source: llm / groq_qwen / prompt adversarial
- reading: When n is negative, the function must return the positive magnitude -n to correct the sign-extension artifact, while for all non-negative inputs the output must remain identical to the original buggy implementation.
- when `n < 0`: `out_ret == -n`
- elsewhere: `out_ret == old_ret`
- reach: `n < 0`

