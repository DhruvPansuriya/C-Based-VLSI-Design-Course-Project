# Reuse of the downloaded HLS datasets

CHStone, MachSuite and HLS-Eval are HLS design/testbench sources, rather than ready-made labeled equivalent/non-equivalent C pairs. EqBench remains the separate public labeled-pair evaluation. The existing 50-pair HLS cohort is primarily educational kernels plus explicitly reduced uint32_t MachSuite adaptations; it is not 50 unmodified designs from these suites.

## Actual downloaded coverage

| Suite | Available designs inventoried | Commit |
|---|---:|---|
| CHStone | 12 | `2b7e20ffd3365016faf1e4e2b86496a5c95445fb` |
| MachSuite | 19 | `6236e593012cb86b0d2f08d9fb9ba0411ff989b4` |
| hls-eval | 132 | `e373bc0a005f0a6030f77f27b3f0d71b16a35a0b` |

All 132 tracked `hls_eval_data` design `top.txt` records at the pinned revision are materialized and inventoried in this checkout. Test fixtures outside the dataset directory are excluded. This is the pinned repository's actual design count, rather than the paper's original count.

The direct frontend audit preserves raw sources and tests the custom interpreter with a small exploration budget (max_unroll=8, max_paths=8). No raw design source was accepted. The saved rejection reasons include non-stdint includes, preprocessing, declarations/globals, custom types, C++ constructs and unsupported interfaces. This is an eligibility audit, not failed equivalence or evidence that the benchmark programs are incorrect. It identifies why raw suites cannot simply be passed to this restricted prototype.

## Type-preserving leaf-function experiment

Eight real functions were isolated without changing their original function text, integer types or domain. Required typedefs/macros are retained and unrelated includes/prototypes/functions are removed. C-compatible HLS-Eval `.cpp` function bodies are compiled as C. Candidate rewrites and seeded bugs were authored in this Codex session; they are separate from the raw Qwen samples.

| Suite | Function | Preserved data | Equivalent rewrite |
|---|---|---|---|
| hls-eval | extractFloat64Sign | unsigned long long | isolate sign bit |
| hls-eval | extractFloat64Frac | unsigned long long | unsigned shift pair extracts low 52 bits |
| hls-eval | extractFloat64Exp | unsigned long long | mask then shift |
| hls-eval | float64_abs | unsigned long long | clear sign with unsigned shift pair |
| hls-eval | float64_is_nan | unsigned long long | explicit exponent/fraction predicates |
| CHStone | gsm_abs | short | explicit saturation guards |
| CHStone | gsm_add | short, short | explicit saturation guards |
| MachSuite | rj_xtime | unsigned char | branchless AES multiply by x |

Reused ESBMC 8.7 / Z3 proved all eight candidates equivalent and rejected all eight seeded faults. There are 96,272 independent native trials with zero equivalent-pair mismatches; all seeded bugs are also observed natively. The GSM absolute-value function is tested exhaustively over all 65,536 signed 16-bit inputs, and the MachSuite AES byte operation over all 256 unsigned-byte inputs.

The ESBMC scalar miters use unconstrained nondeterministic variables of the exact input type, including unsigned long long for the full 64-bit domain. No narrowing to 32-bit nondeterminism or hidden range constraints is used. Static assertions enforce short16/int32/long32/long-long64; the native Windows and ESBMC `--32` integer models agree on these widths. Signed narrowing follows the chosen implementation, so this is not a claim across all implementation-defined C targets.

The HLS-Eval functions manipulate binary64 **bit patterns stored in unsigned 64-bit integers**; this is not general floating-point equivalence support. ESBMC handles this experiment through a separate scalar-leaf miter. The custom uint32_t symbolic interpreter has not acquired signed-16 or unsigned-64 semantics.

One instructive counterexample is CHStone `gsm_abs(-32768)`: the original saturates to 32767, while removing the saturation guard returns -32768 on the stated target. This single input is caught both by ESBMC and exhaustive compiled-C testing.

These are leaf extractions, not proofs of full GSM, AES, JPEG or other benchmark applications. No additional hardware results are claimed for these eight functions. The main and local-Qwen studies retain their measured HLS results separately.

## Attribution and reproduction

Original source paths, hashes, header hashes, exact extracted text and every preparation step are in `experiments/dataset_leaves/manifest.json`. The MachSuite license is retained with the extracts. CHStone GSM copyright comments are retained; their referenced `COPYRIGHT` file is absent from the downloaded CHStone snapshot, so no broader license is invented. HLS-Eval is credited to Stefan Abi-Karam and Cong Hao, ICLAD 2025, DOI 10.1109/ICLAD65226.2025.00021. Preserve each upstream source notice.

```powershell
.\.venv\Scripts\python.exe audit_hls_datasets.py
.\.venv\Scripts\python.exe run_dataset_leaf_study.py
```

The downloaded upstream repositories and ESBMC executable are needed to regenerate extracts and logs. The portable submission includes the prepared leaf C files, generated miters and recorded evidence.

Sources: [CHStone repository](https://github.com/ferrandi/CHStone), [MachSuite repository](https://github.com/breagen/MachSuite), [HLS-Eval repository](https://github.com/sharc-lab/hls-eval).
