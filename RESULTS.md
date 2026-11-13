# Project 3 results

This overview groups the completed experiments and links to their detailed
records. These cohorts overlap: the integrated-checker study rechecks earlier
pairs, larger cases share algorithms, and some variants share baselines.
Do not add their counts and call the sum independent HLS designs or model
samples. The main curated rewrites are distinct from raw first-response model
experiments and deliberately injected faults.

## Metric conventions

`Improvement (%) = 100 * (original - candidate) / original`.
Positive means better for area, cycles, latency, critical-path delay and area
x latency. `Latency speedup = original cycles / candidate cycles`; above 1
is faster. Area x latency (ALP) is area x cycles x 10 ns. A useful ALP win
requires a proved-equivalent changed candidate, passing hardware validation,
the clock constraint, and at least 0.1% lower ALP. A faster design can still
regress ALP by using more area.

Hardware settings: Bambu 2026.11 / I386 Clang16, BAMBU-BALANCED-MP / -O2,
seed 0, Verilator RTL simulation, Yosys 0.36, OpenSTA 2.0.18, Nangate45
typical, common 10 ns clock. Area is mapped standard-cell area in um^2;
delay is a constrained pre-layout critical-path estimate. These are not
routed timing or FPGA LUT counts. Execution latency is cycles x 10 ns,
which is distinct from critical-path delay.

## 1. Main curated optimization cohort


50 original/candidate pairs, 47 distinct original C ASTs,
100 synthesized implementations. All 50 candidates proved equivalent;
all 50 separate seeded faults were rejected. There are
13,200 compiled-C pair trials, 50 exact native witness replays and
1,600 RTL transactions. All 100 implementations meet the common clock.

ALP outcomes: **22 improved, 25 regressed, 3 unchanged**. Area improves in
14 pairs, cycles in 34 and critical-path delay in 11. These are LLM-assisted
educational/adapted/feedback rewrites, not a first-response LLM success rate
or fifty whole unmodified public benchmark applications.


| Case | Area original -> candidate | Area improvement | Cycles original -> candidate | Latency improvement | Delay ns original -> candidate | Delay improvement | ALP improvement |
| --- | --- | --- | --- | --- | --- | --- | --- |
| scale | 719.00 -> 2122.15 | -195.15% | 26 -> 26 | +0.00% | 1.304 -> 1.427 | -9.46% | -195.15% |
| unswitch | 1125.98 -> 1863.06 | -65.46% | 14 -> 14 | +0.00% | 1.537 -> 1.928 | -25.39% | -65.46% |
| gemm | 4506.57 -> 4760.07 | -5.63% | 122 -> 266 | -118.03% | 1.903 -> 2.218 | -16.50% | -130.30% |
| stencil | 4493.01 -> 6646.54 | -47.93% | 158 -> 116 | +26.58% | 1.896 -> 2.452 | -29.29% | -8.61% |
| prefix | 1857.48 -> 913.18 | +50.84% | 62 -> 26 | +58.06% | 1.901 -> 1.510 | +20.57% | +79.38% |
| fir | 5558.07 -> 5092.57 | +8.38% | 5 -> 5 | +0.00% | 3.182 -> 3.209 | -0.84% | +8.38% |
| boxfilter | 1135.82 -> 9712.99 | -755.15% | 158 -> 87 | +44.94% | 1.559 -> 5.976 | -283.41% | -370.87% |
| factor | 3412.25 -> 3412.25 | +0.00% | 1 -> 1 | +0.00% | 2.696 -> 2.696 | +0.00% | +0.00% |
| dot16 | 3993.72 -> 8760.71 | -119.36% | 19 -> 19 | +0.00% | 2.004 -> 2.967 | -48.11% | -119.36% |
| sum32 | 572.96 -> 3992.39 | -596.80% | 35 -> 19 | +45.71% | 1.455 -> 3.890 | -167.42% | -278.26% |
| xor32 | 439.17 -> 2488.96 | -466.75% | 35 -> 19 | +45.71% | 1.129 -> 3.206 | -184.03% | -207.66% |
| min8 | 803.05 -> 4145.08 | -416.16% | 11 -> 5 | +54.55% | 1.394 -> 2.802 | -100.94% | -134.62% |
| max8 | 779.91 -> 4228.07 | -442.12% | 11 -> 5 | +54.55% | 0.972 -> 2.915 | -199.72% | -146.42% |
| range8 | 1822.63 -> 1341.17 | +26.42% | 11 -> 11 | +0.00% | 1.744 -> 1.457 | +16.44% | +26.42% |
| count_nonzero16 | 437.30 -> 3587.81 | -720.44% | 19 -> 11 | +42.11% | 1.414 -> 4.400 | -211.12% | -374.99% |
| all_equal16 | 471.09 -> 669.26 | -42.07% | 19 -> 19 | +0.00% | 0.696 -> 0.767 | -10.20% | -42.07% |
| parity32 | 130.34 -> 50.01 | +61.63% | 34 -> 1 | +97.06% | 0.545 -> 0.276 | +49.39% | +98.87% |
| popcount8 | 329.31 -> 29.26 | +91.11% | 10 -> 1 | +90.00% | 0.747 -> 0.255 | +65.93% | +99.11% |
| bitreverse32 | 515.51 -> 0.53 | +99.90% | 34 -> 1 | +97.06% | 0.689 -> 0.054 | +92.14% | +100.00% |
| byteswap32 | 308.83 -> 0.53 | +99.83% | 6 -> 1 | +83.33% | 0.498 -> 0.054 | +89.13% | +99.97% |
| crc8_byte | 119.43 -> 119.97 | -0.45% | 10 -> 6 | +40.00% | 0.323 -> 0.323 | -0.30% | +39.73% |
| hamming8 | 628.29 -> 567.64 | +9.65% | 90 -> 11 | +87.78% | 1.089 -> 1.112 | -2.12% | +88.96% |
| clamp16 | 619.78 -> 619.78 | +0.00% | 50 -> 50 | +0.00% | 1.323 -> 1.323 | +0.00% | +0.00% |
| threshold_pack8 | 250.84 -> 326.65 | -30.22% | 11 -> 7 | +36.36% | 1.062 -> 1.009 | +4.93% | +17.13% |
| absdiff16 | 1261.64 -> 1258.18 | +0.27% | 50 -> 50 | +0.00% | 1.402 -> 1.578 | -12.58% | +0.27% |
| squared_distance8 | 3889.98 -> 10618.99 | -172.98% | 11 -> 11 | +0.00% | 2.834 -> 1.961 | +30.80% | -172.98% |
| saxpy16 | 4469.86 -> 6051.50 | -35.38% | 50 -> 50 | +0.00% | 1.924 -> 2.018 | -4.92% | -35.38% |
| quadratic | 6971.59 -> 6971.59 | +0.00% | 1 -> 1 | +0.00% | 3.454 -> 3.454 | +0.00% | +0.00% |
| convolution1d8 | 2310.48 -> 2125.07 | +8.02% | 26 -> 26 | +0.00% | 2.125 -> 1.722 | +18.97% | +8.02% |
| moving_sum16 | 978.08 -> 3338.57 | -241.34% | 93 -> 41 | +55.91% | 1.541 -> 1.973 | -28.05% | -50.48% |
| triangular_fir16 | 1958.03 -> 1510.61 | +22.85% | 58 -> 45 | +22.41% | 1.685 -> 2.214 | -31.42% | +40.14% |
| gaussian5 | 1800.82 -> 8919.25 | -395.29% | 158 -> 102 | +35.44% | 2.229 -> 5.689 | -155.30% | -219.74% |
| integral_image4 | 3076.02 -> 3029.21 | +1.52% | 262 -> 102 | +61.07% | 2.337 -> 2.786 | -19.21% | +61.66% |
| transpose4 | 804.65 -> 1390.38 | -72.79% | 58 -> 34 | +41.38% | 1.490 -> 1.380 | +7.37% | -1.29% |
| matvec4 | 4250.95 -> 11156.04 | -162.44% | 30 -> 26 | +13.33% | 1.945 -> 5.074 | -160.90% | -127.45% |
| gemm_local4 | 4506.57 -> 11236.90 | -149.34% | 122 -> 66 | +45.90% | 1.903 -> 6.758 | -255.01% | -34.89% |
| syrk4 | 4528.92 -> 4692.51 | -3.61% | 122 -> 86 | +29.51% | 1.895 -> 1.976 | -4.27% | +26.96% |
| rank1_update4 | 5331.44 -> 8667.34 | -62.57% | 74 -> 54 | +27.03% | 2.351 -> 3.504 | -49.04% | -18.63% |
| triangular_matvec4 | 4971.01 -> 5360.96 | -7.84% | 62 -> 24 | +61.29% | 2.386 -> 2.029 | +14.97% | +58.25% |
| symv4 | 4248.55 -> 7941.96 | -86.93% | 30 -> 78 | -160.00% | 1.855 -> 8.508 | -358.55% | -386.03% |
| matrix_trace4 | 850.93 -> 544.50 | +36.01% | 50 -> 7 | +86.00% | 1.362 -> 1.429 | -4.97% | +91.04% |
| matrix_diagsum4 | 865.83 -> 806.78 | +6.82% | 58 -> 7 | +87.93% | 1.374 -> 1.611 | -17.24% | +88.75% |
| histogram4 | 833.11 -> 2279.09 | -173.56% | 78 -> 21 | +73.08% | 1.302 -> 1.538 | -18.13% | +26.35% |
| search_count16 | 490.50 -> 1427.89 | -191.11% | 19 -> 11 | +42.11% | 1.291 -> 2.053 | -59.03% | -68.54% |
| reverse_copy16 | 784.70 -> 1412.73 | -80.03% | 50 -> 34 | +32.00% | 1.327 -> 1.791 | -34.94% | -22.42% |
| deinterleave16 | 1166.94 -> 1426.82 | -22.27% | 50 -> 34 | +32.00% | 1.691 -> 2.048 | -21.12% | +16.86% |
| interleave8 | 1284.51 -> 1426.29 | -11.04% | 50 -> 50 | +0.00% | 1.308 -> 1.958 | -49.68% | -11.04% |
| maxpool4 | 1074.64 -> 2170.29 | -101.96% | 48 -> 20 | +58.33% | 1.387 -> 2.606 | -87.88% | +15.85% |
| moving_sum_register16 | 978.08 -> 4111.03 | -320.32% | 93 -> 41 | +55.91% | 1.541 -> 1.899 | -23.20% | -85.30% |
| gemm_tile2 | 4506.57 -> 5770.60 | -28.05% | 122 -> 94 | +22.95% | 1.903 -> 3.858 | -102.70% | +1.34% |

Prefix reuse reduces repeated work (62 -> 26 cycles and roughly half the
area). FIR saves area at unchanged latency. Parity, bit reversal and byte
swap expose strong bit-level simplifications. Some unrolling/parallelization
reduces cycles but increases area enough to lose the ALP objective.

Evidence: [all transformations and source/proof dossiers](experiments/OPTIMIZATION_CATALOG.md),
[machine-readable measurements](results/submission/summary.json),
[hardware logs/RTL/netlists](results/hls/).

## 2. Two-model study: twelve dataset-derived inputs

One first response per model per frozen original; same instruction/source
text, no repair or verification feedback. Six inputs are reduced unsigned
compute adaptations and six are type-preserving scalar leaves from
MachSuite, CHStone and HLS-Eval. Qwen2.5-Coder-1.5B Q4_K_M ran locally;
GPT-6.1-Sol ran through fresh Codex tasks. Codex sampling controls are not
exposed, so this is a small descriptive inter-model comparison, not a
controlled model-size ranking. No external paid API was used.


| Model | Attempts | Equivalent | Confirmed mismatch | Inconclusive | AST unchanged | Measured candidates | ALP wins / regressions / unchanged |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Qwen Coder 1.5B | 12 | 12 | 0 | 0 | 9 | 12 | 0 / 1 / 11 |
| GPT-6.1-Sol | 12 | 10 | 0 | 2 | 0 | 10 | 1 / 4 / 5 |

| Case | Model | Verdict | Cycles original -> candidate | Speedup | Area improvement | Delay improvement | ALP improvement |
| --- | --- | --- | --- | --- | --- | --- | --- |
| machsuite_gemm4 | Qwen Coder 1.5B | equivalent | 122 -> 234 | 0.521x | +1.29% | +8.40% | -89.32% |
| machsuite_gemm4 | GPT-6.1-Sol | equivalent | 122 -> 82 | 1.488x | -138.04% | -208.27% | -60.00% |
| machsuite_stencil5 | Qwen Coder 1.5B | equivalent | 158 -> 158 | 1.000x | +0.00% | +0.00% | +0.00% |
| machsuite_stencil5 | GPT-6.1-Sol | equivalent | 158 -> 116 | 1.362x | -56.08% | -12.76% | -14.59% |
| polybench_mvt4 | Qwen Coder 1.5B | equivalent | 122 -> 122 | 1.000x | +0.00% | +0.00% | +0.00% |
| polybench_mvt4 | GPT-6.1-Sol | equivalent | 122 -> 58 | 2.103x | -187.30% | -125.37% | -36.58% |
| polybench_atax4 | Qwen Coder 1.5B | equivalent | 126 -> 126 | 1.000x | +0.00% | +0.00% | +0.00% |
| polybench_atax4 | GPT-6.1-Sol | inconclusive | not measured | - | - | - | - |
| polybench_bicg4 | Qwen Coder 1.5B | equivalent | 142 -> 142 | 1.000x | +0.00% | +0.00% | +0.00% |
| polybench_bicg4 | GPT-6.1-Sol | inconclusive | not measured | - | - | - | - |
| polybench_syrk4 | Qwen Coder 1.5B | equivalent | 232 -> 232 | 1.000x | +0.00% | +0.00% | +0.00% |
| polybench_syrk4 | GPT-6.1-Sol | equivalent | 232 -> 100 | 2.320x | +39.68% | -16.72% | +74.00% |
| machsuite_rj_xtime | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| machsuite_rj_xtime | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| chstone_gsm_abs | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| chstone_gsm_abs | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | -15.19% | +15.50% | -15.19% |
| chstone_gsm_add | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| chstone_gsm_add | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_extractFloat64Sign | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_extractFloat64Sign | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_extractFloat64Frac | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_extractFloat64Frac | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_float64_is_nan | Qwen Coder 1.5B | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |
| hlseval_float64_is_nan | GPT-6.1-Sol | equivalent | 1 -> 1 | 1.000x | +0.00% | +0.00% | +0.00% |

| Model | Same measured cases | Geomean latency speedup | Geomean ALP ratio (lower is better) |
| --- | --- | --- | --- |
| Qwen Coder 1.5B | 10 | 0.937x | 1.066 |
| GPT-6.1-Sol | 10 | 1.258x | 0.972 |

GPT SYRK is the useful ALP win: 232 -> 100 cycles, roughly 39.68% less area,
and **74.00% ALP improvement**, although its delay increases. GPT GEMM,
stencil and MVT reduce latency but increase ALP. Nine Qwen responses are AST
unchanged; equivalence does not mean useful optimization. GPT ATAX/BiCG
remain inconclusive at 60 seconds per obligation (specialized-frontend
limitations followed by ESBMC timeout); neither is called incorrect or given
hardware numbers.

Validation: 34 hardware implementations,
544 RTL transactions, 5,808 primary plus
5,808 supplementary compiled-C pair trials,
9 accepted SMT query replays, and five native-harness controls
(one equivalent and four deliberate errors). All checks pass.

Evidence: [study report](results/two_model_study/REPORT.md),
[full CSV](results/two_model_study/measurements.csv),
[comparison figure](results/two_model_study/figures/comparison.png),
[twelve source/proof dossiers](results/two_model_study/dossiers/),
[raw responses](results/two_model_study/generations/),
[validation](results/two_model_study/validation.json).

## 3. Earlier actual local-model experiment: forty attempts

Twenty fixed kernels x two seed/temperature settings from the same local
Qwen Coder 1.5B Q4_K_M. Raw first responses were retained without semantic
edits, selective discarding, repair or feedback. Seed and temperature changed
together, so their effects cannot be separated.


| Initial outcome | Attempts |
| --- | --- |
| equivalent | 28 |
| not_equivalent | 8 |
| candidate_undefined | 2 |
| unsupported | 1 |
| unknown | 1 |

Initially, 19 equivalent responses were AST unchanged and nine changed.
A later 60-second retry proves the unresolved range8 pair equivalent, giving
29 established equivalent attempts across runs, ten with changed AST. Only
the initial nine changed equivalent outputs have hardware measurements:
three ALP wins, five unchanged and one regression. The newly proved retry
has no added HLS measurement.


| Attempt | Cycles original -> candidate | Area improvement | Latency improvement | Delay improvement | ALP improvement |
| --- | --- | --- | --- | --- | --- |
| boxfilter_seed5292 | 158 -> 341 | -22.27% | -115.82% | -7.97% | -163.89% |
| convolution1d8_seed5291 | 26 -> 26 | +0.00% | +0.00% | +0.00% | +0.00% |
| min8_seed5291 | 11 -> 11 | +0.00% | +0.00% | +0.00% | +0.00% |
| min8_seed5292 | 11 -> 11 | +0.00% | +0.00% | +0.00% | +0.00% |
| prefix_seed5291 | 62 -> 40 | +15.60% | +35.48% | -18.04% | +45.55% |
| quadratic_seed5292 | 1 -> 1 | +0.00% | +0.00% | +0.00% | +0.00% |
| threshold_pack8_seed5292 | 11 -> 11 | +0.00% | +0.00% | +0.00% | +0.00% |
| triangular_matvec4_seed5291 | 62 -> 24 | -7.84% | +61.29% | +14.97% | +58.25% |
| triangular_matvec4_seed5292 | 62 -> 24 | -7.80% | +61.29% | +22.00% | +58.27% |

The eight safe mismatches are genuine saved model errors: FIR coefficients,
XOR used as absolute difference, broken prefix logic, wrong SYRK indexing,
overlapping popcount groups, bad bit-reversal shifts, a spurious zero-input
special case, and a convolution offset error. Their errors are independently
observable in compiled C. Two additional responses have undefined behavior
(shift by 32 and out-of-bounds indexing); unsupported is not a semantic bug.

Evidence: [report and every mistake](results/local_llm/REPORT.md),
[raw generations](results/local_llm/generations/),
[evaluation records](results/local_llm/evaluations/),
[nine hardware records](results/local_llm/hls/summary.json).

## 4. Integrated equivalence checker evaluation


| Outcome | Pairs |
| --- | --- |
| equivalent | 107 |
| not_equivalent | 121 |
| undefined_behavior | 8 |
| unsupported | 1 |
| inconclusive | 2 |

These 239 checks reuse cases from the main, local-model, subtle-fault,
public-leaf and targeted mixed cohorts. 236/237 previously established labels
match; the remaining known-equivalent case is inconclusive, with no
contradictory conclusive verdict. Summaries are accepted in
120 cases and refinement occurs in 22.
All accepted SMT dependencies replay, and all 121 available concrete mismatch
inputs reproduce a difference in compiled C. This does not establish
soundness for arbitrary C or independence of all test cases.


| Targeted case | Standalone symbolic | Monolithic ESBMC/Z3 | Combined | Combined seconds |
| --- | --- | --- | --- | --- |
| mixed_array_equivalent | unsupported | unknown | inconclusive | 11.602 |
| mixed_array_incorrect | unsupported | not_equivalent | not_equivalent | 2.645 |
| mixed_gemm_lookup | unsupported | unknown | equivalent | 1.061 |

The mixed GEMM example needs both contributions: a symbolic loop-relation
proof reduces the residual C problem containing a symbolic-index read. The
combined run proves it while the specialized checker is unsupported and
monolithic ESBMC reaches its tested limit. Conversely, the wrong-array suffix
is found faster monolithically (about 0.56 s versus 2.65 s combined). These
are targeted examples with per-obligation budgets, not equal-total-budget
evidence of universal speedup. Z3 is used by both approaches; no result here
shows that Z3 itself returned a wrong mathematical answer.

Evidence: [algorithm and scope](docs/INTEGRATED_ALGORITHM.md),
[integrated report](results/hybrid/REPORT.md),
[239-case records](results/hybrid/study/summary.json),
[ablation](results/hybrid/ablation/summary.json).

## 5. Larger checker-only instances


29 checks: 27 scaled pairs plus two retries of identical earlier inputs.
Outcomes: 22 equivalent, three non-equivalent, four inconclusive. The limit
is 60 seconds per SMT/C-verifier obligation, not per whole source pair.
Accepted dependency replays and available native witnesses pass. No new
hardware QoR is claimed for this scaling study.


| Case | Scale | Verdict | Total seconds |
| --- | --- | --- | --- |
| retry_mixed_array_equivalent | 8 | equivalent | 24.485 |
| retry_local_range8_seed5292 | 8 | equivalent | 32.371 |
| correlation_4 | 4 | equivalent | 7.163 |
| correlation_8 | 8 | equivalent | 18.977 |
| correlation_16 | 16 | inconclusive | 62.725 |
| dot_32 | 32 | equivalent | 0.609 |
| dot_64 | 64 | equivalent | 0.615 |
| dot_128 | 128 | equivalent | 0.958 |
| dot_32_lane_fault | 32 | not_equivalent | 2.985 |
| dynamic_sum_16 | 16 | inconclusive | 60.555 |
| dynamic_sum_64 | 64 | inconclusive | 61.113 |
| fir_16 | 16 | equivalent | 0.929 |
| fir_32 | 32 | equivalent | 0.641 |
| fir_64 | 64 | equivalent | 0.713 |
| fir_32_coefficient_fault | 32 | not_equivalent | 2.097 |
| gemm_4 | 4 | equivalent | 0.824 |
| gemm_8 | 8 | equivalent | 1.195 |
| gemm_12 | 12 | equivalent | 2.247 |
| gemm_16 | 16 | equivalent | 3.379 |
| gemm_8_transpose_fault | 8 | inconclusive | 128.568 |
| gemm_lookup_8 | 8 | equivalent | 3.176 |
| gemm_lookup_16 | 16 | equivalent | 15.762 |
| prefix_32 | 32 | equivalent | 0.648 |
| prefix_64 | 64 | equivalent | 1.073 |
| prefix_128 | 128 | equivalent | 2.639 |
| prefix_64_recurrence_fault | 64 | not_equivalent | 44.453 |
| stencil_8 | 8 | equivalent | 0.652 |
| stencil_12 | 12 | equivalent | 1.067 |
| stencil_16 | 16 | equivalent | 2.491 |

Notable proofs include 16x16 GEMM (3.379 s), indexed 16x16 GEMM (15.762 s),
128-element prefix (2.639 s), 128-element dot (0.958 s), 64-tap FIR
(0.713 s), and 16x16 stencil (2.491 s). The two prior inconclusive pairs
resolve at the longer budget; other unresolved cases remain explicit.


| Additional loop-budget check | Unwind bound | Verdict | Seconds |
| --- | --- | --- | --- |
| dynamic_sum_16 | 17 | inconclusive | 60.311 |
| dynamic_sum_64 | 65 | inconclusive | 60.444 |

Tightening unwind bounds for these input-dependent loops does not make
their proof problems disappear; inconclusive remains a valid outcome.
Evidence: [larger-case report](results/large/REPORT.md),
[full summary](results/large/summary.json),
[loop-budget experiment](results/loop_budget/summary.json).

## 6. Subtle faults and semantic controls


| Expected and observed outcome | Cases |
| --- | --- |
| not_equivalent | 54 |
| equivalent | 20 |
| candidate_undefined | 6 |

All 80 controlled labels match: 54 semantic faults rejected, 20 equivalent
edits accepted, six undefined-C cases classified separately. These are
deliberate controls, not spontaneous LLM mistakes. Five faults escape the
particular 264-input edge/random set but are exposed by SMT and compiled-C
witness replay: all_equal16 cancellation, clamp16 boundary, threshold_pack8
equality, search_count16 lane selection, and a rare magic-input exception.
This illustrates why finite testing supplements rather than replaces proof.
Evidence: [all controls and witnesses](results/subtle_faults/REPORT.md),
[machine-readable summary](results/subtle_faults/summary.json).

## 7. Public benchmarks and labeled equivalence data

The downloaded inventory contains 12 CHStone, 19 MachSuite and 132 HLS-Eval
design records at pinned revisions. The raw whole designs were not admitted
by the restricted frontend audit. That is an interface/syntax eligibility
result, not evidence of incorrect designs. Eight type-preserving real leaf
functions were extracted and evaluated separately: five HLS-Eval unsigned
64-bit bit-pattern operations, CHStone GSM absolute value and saturating add,
and MachSuite AES byte xtime.


| Public-leaf result | Pairs |
| --- | --- |
| equivalent | 8 |
| not_equivalent | 8 |

All eight rewrites prove equivalent and all eight seeded bugs are rejected
with reused ESBMC/Z3. Independent native validation covers 96,272 trials,
including every signed-16 GSM abs input and every unsigned-byte AES input.
This is not a proof of complete GSM/AES applications or general floating-point
arithmetic: the binary64 helpers manipulate integer bit patterns.

EqBench's pinned C snapshot has 247 indexed old files and 246 complete
old/new pairs. Fourteen fit the generated adapter and all fourteen were
evaluated: two equivalent, nine incomplete-unwind, three unknown. The two
conclusive results match upstream labels. This is not 100% accuracy or
coverage on EqBench; the initial run used unwind 32 and a 3-second requested
solver budget, with the recorded external grace period.

Evidence: [dataset audit and eight-function study](results/dataset_audit/REPORT.md),
[leaf records](results/dataset_leaves/summary.json),
[every eligible EqBench result](results/eqbench/REPORT.md).

## 8. Initial external-tool comparison and model-family pilot

The initial eight-pair symbolic/ESBMC/PAST comparison resolved all eight
symbolically, seven with ESBMC (all agreeing), and left one GEMM equivalence
unknown under that run's limit. PAST independently accepted GEMM and stencil;
its `not_proved` result is not a semantic refutation. These are small annotated
adaptations with different proof strategies, not a broad tool ranking.
Evidence: [initial comparison](results/IMPLEMENTATION_COMPARISON.md).

The earlier one-kernel, one-response-per-model prefix pilot is separate:


| Model | Formal/frontend outcome | Hardware result |
| --- | --- | --- |
| SmolLM2-360M | compile failure | not measured |
| Qwen Coder 1.5B | unsupported builtin | not measured |
| IBM Granite 3.3 2B | equivalent | 62 cycles; unchanged QoR |
| GPT-6.1-Sol | equivalent | 62 -> 26 cycles; +79.38% ALP improvement |

The Qwen pilot also has a separately compiled concrete mismatch; its formal
status remains unsupported. Three implementations (including baseline)
underwent fresh hardware runs: 48 RTL transactions. One prompt on one kernel
validates the workflow, not model accuracy. [Pilot evidence](results/model_pilot_quick/REPORT.md).

## 9. Complete file-to-file pipeline demonstration

`run_demo.py matmul.cpp matmul_opti.cpp --function kernel` compares the actual
top-level files. The recorded i-j-k / k-i-j pair proves equivalent and passes
264 compiled-C comparisons and 32 RTL transactions, but its hardware regresses:


| Metric | Original | Candidate | Improvement |
| --- | --- | --- | --- |
| Area (um^2) | 4612.97 | 5004.26 | -8.48% |
| Latency (cycles) | 266 | 314 | -18.05% |
| Latency at 10 ns (ns) | 2660 | 3140 | -18.05% |
| Critical-path delay (ns) | 1.86574 | 1.83468 | +1.66% |
| Area x latency | 1.22705e+07 | 1.57134e+07 | -28.06% |

A second full run checks a 64-bit sign extraction and certified top-name
renaming: equivalent, 264 compiled-C comparisons, 32 RTL calls, one cycle in
both versions and unchanged hardware. A real incorrect x8/x4 pair produces
a concrete, natively reproduced mismatch and stops before HLS. Additional
controls reject stale source/HLS inputs and failed prerequisites.

The full regression suite passed **98 tests**, including six pipeline controls.
A compiled LP64 reference check also validates ILP32 long-local/literal
conversion behavior. Evidence: [pipeline walkthrough](docs/FILE_PIPELINE.md),
[validation](results/demo_pipeline_validation/validation.json),
[test results](results/demo_pipeline_validation/pytest_full_60s.xml),
[matmul report](results/demo_pipeline_validation/run_ada9001fc0a9/REPORT.md).
Raw console logs keep their original sign convention; this overview and the
current formatter use positive-is-better improvement. Hardware regressions
remain successful measurement runs, not failed equivalence proofs.

## What to present and what remains limited

The project delivers an executable, evidence-producing C-to-C checker, a
proof-gated HLS comparison pipeline, retained LLM outputs, real semantic-error
examples, equivalent controls, and measured hardware wins/regressions.
The course contribution is the implementation/integration/evaluation of
established techniques, rather than a claim of inventing SMT or modifying
ESBMC/Z3. Useful optimization and behavioral preservation require separate
checks; inconclusive is retained as inconclusive.

Support remains restricted to the documented C integer/interface model,
nonaliasing arrays, bounded/unwound terminating paths and explicit assumptions.
Calls, globals, arbitrary pointer-rich code and general floating-point programs
are outside the shared frontend. The custom summary engine is narrower than
the residual verifier. There is no formal proof of our checker implementation
or the HLS compiler, no routed silicon measurements, and no statistically
established model ranking. Related work, source notices and saved evidence
remain in the archive for attribution and review.

