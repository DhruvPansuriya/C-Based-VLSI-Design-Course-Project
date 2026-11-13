# Larger C-to-C checks with a 60-second solver budget

The integrated checker now defaults to **60,000 ms per SMT check or C-verifier invocation**. Frontend work and expression construction add time, and a case can issue several obligations or refinements. This is not a 60-second total wall-clock cap per source pair.

The 10-second integrated baseline is retained under `results/hybrid/`. Its exact implementation is preserved in `experiments/checker_versions/`. This study uses separate sources/results and records the larger budget for every invocation.

There are 27 dimension-scaled educational kernel pairs and two retries of identical previously inconclusive source pairs. The size variants share algorithms and are not independent applications or newly sampled Qwen responses. All original/candidate C and deliberate fault definitions are saved under `benchmarks/large/`. These are **checker-scaling experiments**; no new HLS area/delay/latency measurements are claimed.

| Formal outcome | Pairs |
|---|---:|
| equivalent | 22 |
| inconclusive | 4 |
| not_equivalent | 3 |

All available SMT dependency replays and native mismatch checks pass. There are 0 contradictory conclusive verdicts. Inconclusive outcomes remain unresolved; their expected labels are not substituted for checker results.

## What the extra budget resolves

| Same source pair | Earlier budget/result | New result | Total measured time |
|---|---|---|---:|
| retry_mixed_array_equivalent | 10 s / inconclusive | equivalent | 24.485 s |
| retry_local_range8_seed5292 | 10 s / inconclusive | equivalent | 32.371 s |

The range8 retry is an actual retained Qwen output. The initial local-model evaluation had 28 equivalent outputs; this later proof raises the number established equivalent across all runs to 29 of the same 40 attempts. Nineteen remain unchanged, so ten outputs now have verified code changes. Hardware measurements still cover the initial nine changed outputs; the newly proved range8 rewrite has no additional QoR measurement in this study.

## Successful larger instances

| Family | Largest proved instance | Work in original | Total measured time |
|---|---|---|---:|
| gemm | 16 x 16 | 4096 principal terms/operations | 3.379 s |
| indexed_gemm | 16 x 16 | 4096 principal terms/operations | 15.762 s |
| prefix | 128 elements | 8256 principal terms/operations | 2.639 s |
| dot | 128 elements | 128 principal terms/operations | 0.958 s |
| fir | 64 elements | 64 principal terms/operations | 0.713 s |
| stencil | 16 x 16 | 1764 principal terms/operations | 2.491 s |
| correlation | 8 elements | 8 principal terms/operations | 18.977 s |

The 16 x 16 GEMM contains 4,096 multiply-accumulate terms, compared with 64 in the earlier 4 x 4 example. The 128-element prefix reference performs 8,256 additions. Each admitted unsigned data word ranges over its full 32-bit domain; these are symbolic proofs, rather than tests of one large input. Interface-word counts include initial output-buffer contents even when those contents are later overwritten.

The static-loop proofs benefit from symbolic execution and modular polynomial normalization; their residual C checks use certified shared poststates. Larger array dimensions alone do not predict SMT difficulty. The indexed correlation and input-dependent-loop cases exercise different, harder relations.

## Unresolved cases

| Case | Expected relationship | Observed | Total measured time |
|---|---|---|---:|
| [correlation_16](correlation_16/evaluation.json) | equivalent | inconclusive | 62.725 s |
| [dynamic_sum_16](dynamic_sum_16/evaluation.json) | equivalent | inconclusive | 60.555 s |
| [dynamic_sum_64](dynamic_sum_64/evaluation.json) | equivalent | inconclusive | 61.113 s |
| [gemm_8_transpose_fault](gemm_8_transpose_fault/evaluation.json) | not_equivalent | inconclusive | 128.568 s |

The matrix fault transposes an input access; its inconclusive result is not an equivalence verdict. The 16-element correlation case still needs a stronger or longer residual proof. Both dynamic sums have explicit unchanged preconditions `0 <= n <= capacity`; they are not proofs over unrestricted `n`.

We also retried the dynamic loops with smaller contract-derived unwinding caps while retaining all unwinding assertions. The input domains were unchanged. Both remained inconclusive:

| Case | Previous cap | Retry cap | Result |
|---|---:|---:|---|
| dynamic_sum_16 | 256 | 17 | inconclusive |
| dynamic_sum_64 | 256 | 65 | inconclusive |

These outcomes identify a limitation in relational reasoning about symbolic loop counts; simply increasing time or changing an expansion cap does not guarantee a proof. No bounds, pointer, overflow, shift, uninitialized or unwinding checks were disabled.

## Reproduce

```powershell
.\.venv\Scripts\python.exe -m hlscheck original.c candidate.c --function kernel --output-dir results/my_check
.\.venv\Scripts\python.exe run_large_study.py --timeout-ms 60000
.\.venv\Scripts\python.exe run_loop_budget_study.py
.\.venv\Scripts\python.exe validate_large_evidence.py
```

The recorded implementation versions are matched by hashes against current or archived source modules when evidence is replayed. Current admission checks additionally reject context-dependent preprocessor builtins, string storage and floating-point constants outside the integer model. The archived runs use numeric integer kernels, which are unaffected by those additional admission exclusions.

## Complete ledger

| Case | Scale | Outcome | Wall time |
|---|---:|---|---:|
| [retry_mixed_array_equivalent](retry_mixed_array_equivalent/evaluation.json) | 8 | equivalent | 24.485 s |
| [retry_local_range8_seed5292](retry_local_range8_seed5292/evaluation.json) | 8 | equivalent | 32.371 s |
| [correlation_4](correlation_4/evaluation.json) | 4 | equivalent | 7.163 s |
| [correlation_8](correlation_8/evaluation.json) | 8 | equivalent | 18.977 s |
| [correlation_16](correlation_16/evaluation.json) | 16 | inconclusive | 62.725 s |
| [dot_32](dot_32/evaluation.json) | 32 | equivalent | 0.609 s |
| [dot_64](dot_64/evaluation.json) | 64 | equivalent | 0.615 s |
| [dot_128](dot_128/evaluation.json) | 128 | equivalent | 0.958 s |
| [dot_32_lane_fault](dot_32_lane_fault/evaluation.json) | 32 | not_equivalent | 2.985 s |
| [dynamic_sum_16](dynamic_sum_16/evaluation.json) | 16 | inconclusive | 60.555 s |
| [dynamic_sum_64](dynamic_sum_64/evaluation.json) | 64 | inconclusive | 61.113 s |
| [fir_16](fir_16/evaluation.json) | 16 | equivalent | 0.929 s |
| [fir_32](fir_32/evaluation.json) | 32 | equivalent | 0.641 s |
| [fir_64](fir_64/evaluation.json) | 64 | equivalent | 0.713 s |
| [fir_32_coefficient_fault](fir_32_coefficient_fault/evaluation.json) | 32 | not_equivalent | 2.097 s |
| [gemm_4](gemm_4/evaluation.json) | 4 | equivalent | 0.824 s |
| [gemm_8](gemm_8/evaluation.json) | 8 | equivalent | 1.195 s |
| [gemm_12](gemm_12/evaluation.json) | 12 | equivalent | 2.247 s |
| [gemm_16](gemm_16/evaluation.json) | 16 | equivalent | 3.379 s |
| [gemm_8_transpose_fault](gemm_8_transpose_fault/evaluation.json) | 8 | inconclusive | 128.568 s |
| [gemm_lookup_8](gemm_lookup_8/evaluation.json) | 8 | equivalent | 3.176 s |
| [gemm_lookup_16](gemm_lookup_16/evaluation.json) | 16 | equivalent | 15.762 s |
| [prefix_32](prefix_32/evaluation.json) | 32 | equivalent | 0.648 s |
| [prefix_64](prefix_64/evaluation.json) | 64 | equivalent | 1.073 s |
| [prefix_128](prefix_128/evaluation.json) | 128 | equivalent | 2.639 s |
| [prefix_64_recurrence_fault](prefix_64_recurrence_fault/evaluation.json) | 64 | not_equivalent | 44.453 s |
| [stencil_8](stencil_8/evaluation.json) | 8 | equivalent | 0.652 s |
| [stencil_12](stencil_12/evaluation.json) | 12 | equivalent | 1.067 s |
| [stencil_16](stencil_16/evaluation.json) | 16 | equivalent | 2.491 s |
