# Generated interpretations for `chrysalis_chstone_uppol2_shft` (request `original`)

Set hash: `6ac5dfe615d0d71093bd1322909791ea6c51faba2705406fab7c410d5b2aa320`. Families: groq_gptoss, groq_qwen. Families answered live in this run: groq_gptoss, groq_qwen.
No candidate or evaluation data was sent to any model. These are conditional readings; validity checks do not prove they match the English request.

## chrysalis_chstone_uppol2_shft.groq_gptoss.strict.0
- source: llm / groq_gptoss / prompt strict
- reading: The function must adjust any out‑of‑range shift amount to a defined value so the shift yields the intended result, while all other behavior remains as before; behavior outside the affected region is not specified.
- elsewhere: `unknown`
- reach: `unknown`

## chrysalis_chstone_uppol2_shft.groq_gptoss.permissive.0
- source: llm / groq_gptoss / prompt permissive
- reading: When any shift amount parameter is negative or at least 32, the function returns the same result as the original would have produced with a well‑defined shift (i.e., the shift amount is treated as within the valid range); otherwise it behaves exactly as before.
- when `(al1 < 0 || al1 >= 32) || (al2 < 0 || al2 >= 32) || (plt < 0 || plt >= 32) || (plt1 < 0 || plt1 >= 32) || (plt2 < 0 || plt2 >= 32)`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `(al1 < 0 || al1 >= 32) || (al2 < 0 || al2 >= 32) || (plt < 0 || plt >= 32) || (plt1 < 0 || plt1 >= 32) || (plt2 < 0 || plt2 >= 32)`

## chrysalis_chstone_uppol2_shft.groq_gptoss.adversarial.0
- source: llm / groq_gptoss / prompt adversarial
- reading: When the shift count plt is outside the 0‑31 range the function returns INT_MIN; for all other inputs it behaves exactly as before.
- when `plt < 0 || plt > 31`: `out_ret == INT_MIN`
- elsewhere: `out_ret == old_ret`
- reach: `plt < 0 || plt > 31`

## chrysalis_chstone_uppol2_shft.groq_qwen.strict.0
- source: llm / groq_qwen / prompt strict
- reading: The function returns the sum of al1, al2, and plt2, each left-shifted by plt, plt1, and plt2 respectively, with the shift amounts masked to the lower 5 bits to ensure they are within the valid range for 32-bit integers.
- when `true`: `out_ret == (al1 << (plt % 32)) + (al2 << (plt1 % 32)) + (plt2 << (plt2 % 32))`
- elsewhere: `unknown`
- reach: `true`

## chrysalis_chstone_uppol2_shft.groq_qwen.permissive.0
- source: llm / groq_qwen / prompt permissive
- reading: The function returns the sum of al1, al2, and plt2, each left-shifted by their respective shift amounts (plt, plt1, plt2) masked to the lower 5 bits to ensure the shift is well-defined, while all other behaviour remains unchanged.
- when `true`: `out_ret == (al1 << (plt & 31)) + (al2 << (plt1 & 31)) + (plt2 << (plt2 & 31))`
- elsewhere: `unknown`
- reach: `true`

## chrysalis_chstone_uppol2_shft.groq_qwen.adversarial.0
- source: llm / groq_qwen / prompt adversarial
- reading: The function computes the sum of al1, al2, and plt2, each left-shifted by plt, plt1, and plt2 respectively, but the shift amounts are masked to the lower 5 bits to ensure they are within the valid range for 32-bit integers, and all other behaviour remains unchanged.
- when `true`: `out_ret == (al1 << (plt & 31)) + (al2 << (plt1 & 31)) + (plt2 << (plt2 & 31))`
- elsewhere: `out_ret == old_ret`
- reach: `true`

