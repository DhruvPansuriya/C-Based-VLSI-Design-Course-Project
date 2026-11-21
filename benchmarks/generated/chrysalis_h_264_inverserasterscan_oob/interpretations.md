# Generated interpretations for `chrysalis_h_264_inverserasterscan_oob` (request `original`)

Set hash: `2a06ee881550770ef91bb08c014a9924abbb41f76ae3e8d0b3b17f0e4473525b`. Families: groq_gptoss, groq_qwen. Families answered live in this run: groq_gptoss, groq_qwen.
No candidate or evaluation data was sent to any model. These are conditional readings; validity checks do not prove they match the English request.

## chrysalis_h_264_inverserasterscan_oob.groq_gptoss.strict.0
- source: llm / groq_gptoss / prompt strict
- reading: The function returns the same value as before for all inputs, while any out-of-bounds array accesses are corrected internally.
- when `true`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `unknown`

## chrysalis_h_264_inverserasterscan_oob.groq_gptoss.permissive.0
- source: llm / groq_gptoss / prompt permissive
- reading: For every combination of inputs the function now guarantees that any internal array accesses stay within the array bounds while returning exactly the same result as the original implementation.
- when `true`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `true`

## chrysalis_h_264_inverserasterscan_oob.groq_gptoss.adversarial.0
- source: llm / groq_gptoss / prompt adversarial
- reading: When any argument falls outside the 0‑255 range the function returns a safe default (0) instead of the previous undefined result; otherwise it behaves exactly as before.
- when `(a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255 || e < 0 || e > 255)`: `out_ret == 0`
- elsewhere: `out_ret == old_ret`
- reach: `(a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255 || e < 0 || e > 255)`

## chrysalis_h_264_inverserasterscan_oob.groq_qwen.strict.0
- source: llm / groq_qwen / prompt strict
- reading: For all inputs, the function must return the same value as the original function, implying that the original function's logic was correct for all valid inputs and the fix only prevents out-of-bounds access without altering the computed result for valid cases.
- when `true`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `true`

## chrysalis_h_264_inverserasterscan_oob.groq_qwen.permissive.0
- source: llm / groq_qwen / prompt permissive
- reading: For all inputs, the function must return the same value as the original implementation, ensuring that any internal array accesses are corrected to stay within bounds while preserving the intended computational result.
- when `true`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `true`

## chrysalis_h_264_inverserasterscan_oob.groq_qwen.adversarial.0
- source: llm / groq_qwen / prompt adversarial
- reading: The function must return exactly the same value as the original buggy function for every possible input, implying that the original logic was mathematically correct for all valid inputs and the fix only prevents out-of-bounds access without altering the computed result for any case.
- when `true`: `out_ret == old_ret`
- elsewhere: `out_ret == old_ret`
- reach: `true`

