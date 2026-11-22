# Zero-API-cost local LLM experiment

Forty raw optimization attempts were generated and evaluated: 20 fixed source kernels, each sampled once at seed 5291 / temperature 0.2 and once at seed 5292 / temperature 0.8. The model was **Qwen2.5-Coder-1.5B-Instruct, Q4_K_M**, run locally through llama.cpp b12619 on the NVIDIA RTX 3050 laptop GPU using Vulkan. No paid or free external inference API was called.

The plan and complete prompts were saved before generation. Raw requests, response JSON, response text, extracted C and model/runtime hashes are retained. Only code-fence extraction was applied; no semantic edits, verifier feedback, repair prompts, resampling or discarded attempts. Seeds do not guarantee bit-identical output across runtime versions or GPU backends.

| Outcome | Attempts |
|---|---:|
| Proved equivalent | 28 |
| Safe but non-equivalent | 8 |
| Candidate has undefined C behavior | 2 |
| Outside the admitted checker interface | 1 |
| Inconclusive within resource limits | 1 |

Of the 28 equivalent outputs, 19 are unchanged after C AST normalization and 9 change the AST. AST changes alone do not demonstrate an optimization; identical RTL and QoR can result.

The eight safe non-equivalent outputs are actual mistakes from this recorded local model, not artificial mutations. Six were found by the custom backend, whose solver witnesses were replayed in compiled C with exact original/candidate output agreement. Two required the reused ESBMC fallback (prefix / seed 5292 and absolute difference / seed 5292); both were also exposed by the independent native trials. All 36 conclusive safe pairs passed native validation (264 trials each), and all 34 available custom-backend SMT queries replayed successfully. ESBMC harnesses and traces are retained separately. Undefined and unresolved candidates were not executed in the native differential harness.

## Actual mistakes

| Attempt | Observed change | Evidence |
|---|---|---|
| FIR / seed 5291 | Replaces symmetric FIR coefficients with `2*i+1`. | [Raw C](generations/fir_seed5291/candidate.c), [verdict and witness](evaluations/fir_seed5291/evaluation.json) |
| Absolute difference / seed 5291 | Replaces absolute subtraction by XOR. | [Raw C](generations/absdiff16_seed5291/candidate.c), [evidence](evaluations/absdiff16_seed5291/evaluation.json) |
| Prefix / seed 5292 | Repeats the first input and uses an unsigned sum `< 0` test. | [Raw C](generations/prefix_seed5292/candidate.c), [evidence](evaluations/prefix_seed5292/evaluation.json) |
| SYRK / seed 5292 | Computes matrix multiplication with the wrong second index orientation. | [Raw C](generations/syrk4_seed5292/candidate.c), [evidence](evaluations/syrk4_seed5292/evaluation.json) |
| Byte popcount / seed 5292 | Adds overlapping two-bit numeric values instead of individual bits. | [Raw C](generations/popcount8_seed5292/candidate.c), [evidence](evaluations/popcount8_seed5292/evaluation.json) |
| Bit reversal / seed 5292 | Incorrect shifts and lane assembly. | [Raw C](generations/bitreverse32_seed5292/candidate.c), [evidence](evaluations/bitreverse32_seed5292/evaluation.json) |
| Absolute difference / seed 5292 | Adds an incorrect special case: absolute difference of two zero inputs becomes one. | [Raw C](generations/absdiff16_seed5292/candidate.c), [evidence](evaluations/absdiff16_seed5292/evaluation.json) |
| Convolution / seed 5292 | The second output uses inputs 3..5 instead of 1..3. | [Raw C](generations/convolution1d8_seed5292/candidate.c), [evidence](evaluations/convolution1d8_seed5292/evaluation.json) |

Undefined-C examples are also instructive: GEMM / seed 5292 uses `(1u << 32)` as a modulus, and histogram / seed 5292 reads beyond its 16-element input. These are reported as `candidate_undefined`, rather than ordinary numerical mismatches. Integral-image / seed 5292 uses unsupported function calls; range / seed 5292 remains inconclusive. Neither is counted as a demonstrated model bug.

## Hardware measurements of every verified changed output

All nine AST-changing, proved-equivalent outputs were synthesized with Bambu, simulated for sixteen RTL calls each, mapped with Yosys and timed with OpenSTA using the same Nangate45 typical / 10 ns settings as the main study. Baseline measurements were reused only after exact source and configuration hash checks. None was selected by a favorable hardware result.

| Attempt | Area ratio | Cycle ratio | Delay ratio | Area × latency ratio | Decision |
|---|---:|---:|---:|---:|---|
| boxfilter_seed5292 | 1.2227 | 2.1582 | 1.0797 | 2.6389 | regressed |
| convolution1d8_seed5291 | 1.0000 | 1.0000 | 1.0000 | 1.0000 | unchanged |
| min8_seed5291 | 1.0000 | 1.0000 | 1.0000 | 1.0000 | unchanged |
| min8_seed5292 | 1.0000 | 1.0000 | 1.0000 | 1.0000 | unchanged |
| prefix_seed5291 | 0.8440 | 0.6452 | 1.1804 | 0.5445 | improved |
| quadratic_seed5292 | 1.0000 | 1.0000 | 1.0000 | 1.0000 | unchanged |
| threshold_pack8_seed5292 | 1.0000 | 1.0000 | 1.0000 | 1.0000 | unchanged |
| triangular_matvec4_seed5291 | 1.0784 | 0.3871 | 0.8503 | 0.4175 | improved |
| triangular_matvec4_seed5292 | 1.0780 | 0.3871 | 0.7800 | 0.4173 | improved |

Three attempts improve area × latency, five are unchanged within 0.1%, and one regresses. Prefix / seed 5291 changes 62 to 40 cycles and reduces area by 15.6%, while its delay estimate increases. The two triangular-matvec attempts change 62 to 24 cycles with roughly 7.8% more area. They share one baseline and are not independent applications. The verified box-filter rewrite becomes slower and larger.

These nine implementations add 144 RTL calls to the main study, which remains a separate 50-pair cohort. Do not combine the two cohorts into a success-rate statistic or call the local model superior/inferior to larger models. This is one small quantized model and a selected workload. Seed and temperature change together, so this experiment cannot isolate a temperature effect.

## Reproduce

```powershell
.\.venv\Scripts\python.exe evaluate_local_candidates.py
.\.venv\Scripts\python.exe tools/run_local_llm_hls_linux.py --prepare-only
wsl.exe --exec python3 "/mnt/c/Users/ARYAN/Desktop/7th Semester/C-Based VLSI Design/Course_Project/tools/run_local_llm_hls_linux.py" --jobs 3
```

To generate a fresh study, use `tools/setup_local_coder.py`, `tools/serve_local_coder.py` and `generate_local_candidates.py`. Existing responses are protected by request/source hashes. Archive the existing attempt directory before intentionally making a new generation study.

Model download: 1,117,320,768 bytes (1.04 GiB); Vulkan runtime archive: 38,863,716 bytes (37.06 MiB). These large binaries are excluded from the submission ZIP; hashes, setup scripts and the model Apache-2.0 license are included. Electricity and hardware are outside the zero-API-charge statement.

Sources: [official Qwen model](https://huggingface.co/Qwen/Qwen2.5-Coder-1.5B-Instruct-GGUF), [llama.cpp release b12619](https://github.com/ggml-org/llama.cpp/releases/tag/b12619).

## Complete attempt ledger

| Attempt | Verdict | AST unchanged |
|---|---|---|
| [prefix_seed5291](evaluations/prefix_seed5291/evaluation.json) | equivalent | False |
| [gemm_seed5291](evaluations/gemm_seed5291/evaluation.json) | equivalent | True |
| [stencil_seed5291](evaluations/stencil_seed5291/evaluation.json) | equivalent | True |
| [fir_seed5291](evaluations/fir_seed5291/evaluation.json) | not_equivalent | False |
| [boxfilter_seed5291](evaluations/boxfilter_seed5291/evaluation.json) | equivalent | True |
| [moving_sum16_seed5291](evaluations/moving_sum16_seed5291/evaluation.json) | equivalent | True |
| [integral_image4_seed5291](evaluations/integral_image4_seed5291/evaluation.json) | equivalent | True |
| [histogram4_seed5291](evaluations/histogram4_seed5291/evaluation.json) | equivalent | True |
| [syrk4_seed5291](evaluations/syrk4_seed5291/evaluation.json) | equivalent | True |
| [triangular_matvec4_seed5291](evaluations/triangular_matvec4_seed5291/evaluation.json) | equivalent | False |
| [parity32_seed5291](evaluations/parity32_seed5291/evaluation.json) | equivalent | True |
| [popcount8_seed5291](evaluations/popcount8_seed5291/evaluation.json) | equivalent | True |
| [bitreverse32_seed5291](evaluations/bitreverse32_seed5291/evaluation.json) | equivalent | True |
| [absdiff16_seed5291](evaluations/absdiff16_seed5291/evaluation.json) | not_equivalent | False |
| [min8_seed5291](evaluations/min8_seed5291/evaluation.json) | equivalent | False |
| [threshold_pack8_seed5291](evaluations/threshold_pack8_seed5291/evaluation.json) | equivalent | True |
| [quadratic_seed5291](evaluations/quadratic_seed5291/evaluation.json) | equivalent | True |
| [convolution1d8_seed5291](evaluations/convolution1d8_seed5291/evaluation.json) | equivalent | False |
| [range8_seed5291](evaluations/range8_seed5291/evaluation.json) | equivalent | True |
| [deinterleave16_seed5291](evaluations/deinterleave16_seed5291/evaluation.json) | equivalent | True |
| [prefix_seed5292](evaluations/prefix_seed5292/evaluation.json) | not_equivalent | False |
| [gemm_seed5292](evaluations/gemm_seed5292/evaluation.json) | candidate_undefined | False |
| [stencil_seed5292](evaluations/stencil_seed5292/evaluation.json) | equivalent | True |
| [fir_seed5292](evaluations/fir_seed5292/evaluation.json) | equivalent | True |
| [boxfilter_seed5292](evaluations/boxfilter_seed5292/evaluation.json) | equivalent | False |
| [moving_sum16_seed5292](evaluations/moving_sum16_seed5292/evaluation.json) | equivalent | True |
| [integral_image4_seed5292](evaluations/integral_image4_seed5292/evaluation.json) | unsupported | not established |
| [histogram4_seed5292](evaluations/histogram4_seed5292/evaluation.json) | candidate_undefined | False |
| [syrk4_seed5292](evaluations/syrk4_seed5292/evaluation.json) | not_equivalent | False |
| [triangular_matvec4_seed5292](evaluations/triangular_matvec4_seed5292/evaluation.json) | equivalent | False |
| [parity32_seed5292](evaluations/parity32_seed5292/evaluation.json) | equivalent | True |
| [popcount8_seed5292](evaluations/popcount8_seed5292/evaluation.json) | not_equivalent | False |
| [bitreverse32_seed5292](evaluations/bitreverse32_seed5292/evaluation.json) | not_equivalent | False |
| [absdiff16_seed5292](evaluations/absdiff16_seed5292/evaluation.json) | not_equivalent | False |
| [min8_seed5292](evaluations/min8_seed5292/evaluation.json) | equivalent | False |
| [threshold_pack8_seed5292](evaluations/threshold_pack8_seed5292/evaluation.json) | equivalent | False |
| [quadratic_seed5292](evaluations/quadratic_seed5292/evaluation.json) | equivalent | False |
| [convolution1d8_seed5292](evaluations/convolution1d8_seed5292/evaluation.json) | not_equivalent | False |
| [range8_seed5292](evaluations/range8_seed5292/evaluation.json) | unknown | False |
| [deinterleave16_seed5292](evaluations/deinterleave16_seed5292/evaluation.json) | equivalent | True |
