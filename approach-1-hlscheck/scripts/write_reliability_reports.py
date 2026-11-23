"""Write transparent reports for actual local-model errors and extra controls."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from collections import Counter
import json
import shutil

ROOT = Path(__file__).resolve().parents[1]


def read(path):
    return json.loads((ROOT/path).read_text())


def write_local():
    summary = read('results/local_llm/summary.json'); hls = read('results/local_llm/hls/summary.json')
    for name in ('MODEL_LICENSE', 'MODEL_README.md', 'PROVENANCE.json'):
        shutil.copyfile(ROOT/'tools/local_llm'/name, ROOT/'experiments/local_model'/name)
    lines = ['# Zero-API-cost local LLM experiment', '',
        'Forty raw optimization attempts were generated and evaluated: 20 fixed source kernels, each sampled once at seed 5291 / temperature 0.2 and once at seed 5292 / temperature 0.8. The model was **Qwen2.5-Coder-1.5B-Instruct, Q4_K_M**, run locally through llama.cpp b12619 on the NVIDIA RTX 3050 laptop GPU using Vulkan. No paid or free external inference API was called.', '',
        'The plan and complete prompts were saved before generation. Raw requests, response JSON, response text, extracted C and model/runtime hashes are retained. Only code-fence extraction was applied; no semantic edits, verifier feedback, repair prompts, resampling or discarded attempts. Seeds do not guarantee bit-identical output across runtime versions or GPU backends.', '',
        '| Outcome | Attempts |', '|---|---:|']
    labels = {'equivalent': 'Proved equivalent', 'not_equivalent': 'Safe but non-equivalent', 'candidate_undefined': 'Candidate has undefined C behavior', 'unsupported': 'Outside the admitted checker interface', 'unknown': 'Inconclusive within resource limits'}
    for status, count in summary['counts'].items(): lines.append(f'| {labels[status]} | {count} |')
    lines += ['', f"Of the {summary['counts']['equivalent']} equivalent outputs, {summary['ast_unchanged']} are unchanged after C AST normalization and {summary['nontrivial_equivalent_rewrites']} change the AST. AST changes alone do not demonstrate an optimization; identical RTL and QoR can result.", '',
        'The eight safe non-equivalent outputs are actual mistakes from this recorded local model, not artificial mutations. Six were found by the custom backend, whose solver witnesses were replayed in compiled C with exact original/candidate output agreement. Two required the reused ESBMC fallback (prefix / seed 5292 and absolute difference / seed 5292); both were also exposed by the independent native trials. All 36 conclusive safe pairs passed native validation (264 trials each), and all 34 available custom-backend SMT queries replayed successfully. ESBMC harnesses and traces are retained separately. Undefined and unresolved candidates were not executed in the native differential harness.', '',
        '## Actual mistakes', '',
        '| Attempt | Observed change | Evidence |', '|---|---|---|',
        '| FIR / seed 5291 | Replaces symmetric FIR coefficients with `2*i+1`. | [Raw C](generations/fir_seed5291/candidate.c), [verdict and witness](evaluations/fir_seed5291/evaluation.json) |',
        '| Absolute difference / seed 5291 | Replaces absolute subtraction by XOR. | [Raw C](generations/absdiff16_seed5291/candidate.c), [evidence](evaluations/absdiff16_seed5291/evaluation.json) |',
        '| Prefix / seed 5292 | Repeats the first input and uses an unsigned sum `< 0` test. | [Raw C](generations/prefix_seed5292/candidate.c), [evidence](evaluations/prefix_seed5292/evaluation.json) |',
        '| SYRK / seed 5292 | Computes matrix multiplication with the wrong second index orientation. | [Raw C](generations/syrk4_seed5292/candidate.c), [evidence](evaluations/syrk4_seed5292/evaluation.json) |',
        '| Byte popcount / seed 5292 | Adds overlapping two-bit numeric values instead of individual bits. | [Raw C](generations/popcount8_seed5292/candidate.c), [evidence](evaluations/popcount8_seed5292/evaluation.json) |',
        '| Bit reversal / seed 5292 | Incorrect shifts and lane assembly. | [Raw C](generations/bitreverse32_seed5292/candidate.c), [evidence](evaluations/bitreverse32_seed5292/evaluation.json) |',
        '| Absolute difference / seed 5292 | Adds an incorrect special case: absolute difference of two zero inputs becomes one. | [Raw C](generations/absdiff16_seed5292/candidate.c), [evidence](evaluations/absdiff16_seed5292/evaluation.json) |',
        '| Convolution / seed 5292 | The second output uses inputs 3..5 instead of 1..3. | [Raw C](generations/convolution1d8_seed5292/candidate.c), [evidence](evaluations/convolution1d8_seed5292/evaluation.json) |', '',
        'Undefined-C examples are also instructive: GEMM / seed 5292 uses `(1u << 32)` as a modulus, and histogram / seed 5292 reads beyond its 16-element input. These are reported as `candidate_undefined`, rather than ordinary numerical mismatches. Integral-image / seed 5292 uses unsupported function calls; range / seed 5292 remains inconclusive. Neither is counted as a demonstrated model bug.', '',
        '## Hardware measurements of every verified changed output', '',
        'All nine AST-changing, proved-equivalent outputs were synthesized with Bambu, simulated for sixteen RTL calls each, mapped with Yosys and timed with OpenSTA using the same Nangate45 typical / 10 ns settings as the main study. Baseline measurements were reused only after exact source and configuration hash checks. None was selected by a favorable hardware result.', '',
        '| Attempt | Area ratio | Cycle ratio | Delay ratio | Area × latency ratio | Decision |', '|---|---:|---:|---:|---:|---|']
    for row in hls['cases']:
        r = row['ratios']; adp = r['area_latency_product_um2_ns']
        decision = 'improved' if row['selected_by_adp_policy'] else ('regressed' if adp > 1.001 else 'unchanged')
        lines.append(f"| {row['id']} | {r['area_um2']:.4f} | {r['cycles']:.4f} | {r['delay_ns']:.4f} | {adp:.4f} | {decision} |")
    lines += ['', 'Three attempts improve area × latency, five are unchanged within 0.1%, and one regresses. Prefix / seed 5291 changes 62 to 40 cycles and reduces area by 15.6%, while its delay estimate increases. The two triangular-matvec attempts change 62 to 24 cycles with roughly 7.8% more area. They share one baseline and are not independent applications. The verified box-filter rewrite becomes slower and larger.', '',
        'These nine implementations add 144 RTL calls to the main study, which remains a separate 50-pair cohort. Do not combine the two cohorts into a success-rate statistic or call the local model superior/inferior to larger models. This is one small quantized model and a selected workload. Seed and temperature change together, so this experiment cannot isolate a temperature effect.', '',
        '## Reproduce', '', '```powershell',
        r'.\.venv\Scripts\python.exe scripts/evaluate_local_candidates.py',
        r'.\.venv\Scripts\python.exe tools/run_local_llm_hls_linux.py --prepare-only',
        'wsl.exe --exec python3 "/mnt/c/Users/ARYAN/Desktop/7th Semester/C-Based VLSI Design/Course_Project/tools/run_local_llm_hls_linux.py" --jobs 3',
        '```', '',
        'To generate a fresh study, use `tools/setup_local_coder.py`, `tools/serve_local_coder.py` and `scripts/generate_local_candidates.py`. Existing responses are protected by request/source hashes. Archive the existing attempt directory before intentionally making a new generation study.', '',
        'Model download: 1,117,320,768 bytes (1.04 GiB); Vulkan runtime archive: 38,863,716 bytes (37.06 MiB). These large binaries are excluded from the submission ZIP; hashes, setup scripts and the model Apache-2.0 license are included. Electricity and hardware are outside the zero-API-charge statement.', '',
        'Sources: [official Qwen model](https://huggingface.co/Qwen/Qwen2.5-Coder-1.5B-Instruct-GGUF), [llama.cpp release b12619](https://github.com/ggml-org/llama.cpp/releases/tag/b12619).', '',
        '## Complete attempt ledger', '', '| Attempt | Verdict | AST unchanged |', '|---|---|---|']
    for row in summary['cases']:
        lines.append(f"| [{row['id']}](evaluations/{row['id']}/evaluation.json) | {row['status']} | {row.get('ast_unchanged', 'not established')} |")
    (ROOT/'results/local_llm/REPORT.md').write_text('\n'.join(lines)+'\n', encoding='utf-8')


def write_subtle():
    summary = read('results/subtle_faults/summary.json')
    missed = [r for r in summary['cases'] if r['status']=='not_equivalent' and r['native']['mismatches']==0]
    lines = ['# Controlled subtle-fault study', '',
        '**These are deliberately injected faults and constructed semantic controls, not spontaneous LLM mistakes.** The real local-model mistakes are reported separately in [the local-model experiment](../local_llm/REPORT.md).', '',
        'The suite contains 50 token-scale edits to already-proved candidates, four additional semantic pitfalls, 20 changed-code equivalent controls and six undefined-C controls. Expected labels are declared in the manifest before any verification. The 50 local edits retain the original algorithm and alter an index, bound, mask, coefficient, operation or recurrence; none simply flips the final result bit.', '',
        '| Category | Expected | Observed |', '|---|---:|---:|',
        '| Safe non-equivalent | 54 | 54 |', '| Equivalent semantic edits | 20 | 20 |', '| Undefined candidate C | 6 | 6 |', '',
        f"All {summary['matched_expected']}/{summary['total']} expected categories matched. Every safe mismatch has a saved solver counterexample and compiled-C replay with exact solver/native output agreement. All available SMT replays passed, including accepted lemma dependencies. Undefined-C examples were not executed natively.", '',
        'The equivalent controls matter: changing `<` to `<=` in a minimum expression still returns the same value on ties. Reassociation, unsigned modular subtraction identities and valid strength reductions must also remain accepted. A detector that rejects every syntactic edit would fail these controls.', '',
        'Five faulty programs escaped all 264 conventional differential test inputs (eight fixed edge patterns and 256 deterministic random trials). SMT found and native C reproduced a counterexample for each:', '',
        '| Case | Small error | Evidence |', '|---|---|---|']
    for row in missed:
        lines.append(f"| {row['id']} | {row['rationale']} | [Witness and native replay]({row['id']}/evaluation.json) |")
    lines += ['', 'This is a demonstration on this particular test set, not a universal comparison with all possible directed testing. For example, explicitly testing threshold 128 would expose its equality-boundary fault.', '',
        '## Reproduce', '', '```powershell', r'.\.venv\Scripts\python.exe scripts/run_subtle_fault_study.py', '```', '',
        'Sources, rationale, expected labels, hashes and exact diffs are in `experiments/subtle_faults/manifest.json` and each case directory. Raw proofs and native logs are retained below this report.', '',
        '| Case | Expected | Observed | Native witness |', '|---|---|---|---|']
    for r in summary['cases']:
        lines.append(f"| [{r['id']}]({r['id']}/evaluation.json) | {r['expected']} | {r['status']} | {r.get('native',{}).get('witness_replayed','not executed')} |")
    (ROOT/'results/subtle_faults/REPORT.md').write_text('\n'.join(lines)+'\n', encoding='utf-8')


def write_datasets():
    audit = read('results/dataset_audit/inventory.json'); study = read('results/dataset_leaves/summary.json')
    manifest = read('experiments/dataset_leaves/manifest.json')
    lines = ['# Reuse of the downloaded HLS datasets', '',
        'CHStone, MachSuite and HLS-Eval are HLS design/testbench sources, rather than ready-made labeled equivalent/non-equivalent C pairs. EqBench remains the separate public labeled-pair evaluation. The existing 50-pair HLS cohort is primarily educational kernels plus explicitly reduced uint32_t MachSuite adaptations; it is not 50 unmodified designs from these suites.', '',
        '## Actual downloaded coverage', '', '| Suite | Available designs inventoried | Commit |', '|---|---:|---|']
    for suite, count in audit['design_counts'].items():
        lines.append(f"| {suite} | {count} | `{audit['commits'][suite]}` |")
    lines += ['', f"All {audit['hls_eval_tracked_design_count']} tracked `hls_eval_data` design `top.txt` records at the pinned revision are materialized and inventoried in this checkout. Test fixtures outside the dataset directory are excluded. This is the pinned repository's actual design count, rather than the paper's original count.", '',
        'The direct frontend audit preserves raw sources and tests the custom interpreter with a small exploration budget (max_unroll=8, max_paths=8). No raw design source was accepted. The saved rejection reasons include non-stdint includes, preprocessing, declarations/globals, custom types, C++ constructs and unsupported interfaces. This is an eligibility audit, not failed equivalence or evidence that the benchmark programs are incorrect. It identifies why raw suites cannot simply be passed to this restricted prototype.', '',
        '## Type-preserving leaf-function experiment', '',
        'Eight real functions were isolated without changing their original function text, integer types or domain. Required typedefs/macros are retained and unrelated includes/prototypes/functions are removed. C-compatible HLS-Eval `.cpp` function bodies are compiled as C. Candidate rewrites and seeded bugs were authored in this Codex session; they are separate from the raw Qwen samples.', '',
        '| Suite | Function | Preserved data | Equivalent rewrite |', '|---|---|---|---|']
    for c in manifest['cases']:
        lines.append(f"| {c['suite']} | {c['function']} | {', '.join(c['input_kinds'])} | {c['transformation']} |")
    native = [read('results/dataset_leaves/'+c['id']+'/native.json') for c in manifest['cases']]
    lines += ['', f"Reused ESBMC 8.7 / Z3 proved all eight candidates equivalent and rejected all eight seeded faults. There are {sum(n['trials'] for n in native):,} independent native trials with zero equivalent-pair mismatches; all seeded bugs are also observed natively. The GSM absolute-value function is tested exhaustively over all 65,536 signed 16-bit inputs, and the MachSuite AES byte operation over all 256 unsigned-byte inputs.", '',
        'The ESBMC scalar miters use unconstrained nondeterministic variables of the exact input type, including unsigned long long for the full 64-bit domain. No narrowing to 32-bit nondeterminism or hidden range constraints is used. Static assertions enforce short16/int32/long32/long-long64; the native Windows and ESBMC `--32` integer models agree on these widths. Signed narrowing follows the chosen implementation, so this is not a claim across all implementation-defined C targets.', '',
        'The HLS-Eval functions manipulate binary64 **bit patterns stored in unsigned 64-bit integers**; this is not general floating-point equivalence support. ESBMC handles this experiment through a separate scalar-leaf miter. The custom uint32_t symbolic interpreter has not acquired signed-16 or unsigned-64 semantics.', '',
        'One instructive counterexample is CHStone `gsm_abs(-32768)`: the original saturates to 32767, while removing the saturation guard returns -32768 on the stated target. This single input is caught both by ESBMC and exhaustive compiled-C testing.', '',
        'These are leaf extractions, not proofs of full GSM, AES, JPEG or other benchmark applications. No additional hardware results are claimed for these eight functions. The main and local-Qwen studies retain their measured HLS results separately.', '',
        '## Attribution and reproduction', '',
        'Original source paths, hashes, header hashes, exact extracted text and every preparation step are in `experiments/dataset_leaves/manifest.json`. The MachSuite license is retained with the extracts. CHStone GSM copyright comments are retained; their referenced `COPYRIGHT` file is absent from the downloaded CHStone snapshot, so no broader license is invented. HLS-Eval is credited to Stefan Abi-Karam and Cong Hao, ICLAD 2025, DOI 10.1109/ICLAD65226.2025.00021. Preserve each upstream source notice.', '',
        '```powershell', r'.\.venv\Scripts\python.exe scripts/audit_hls_datasets.py', r'.\.venv\Scripts\python.exe scripts/run_dataset_leaf_study.py', '```', '',
        'The downloaded upstream repositories and ESBMC executable are needed to regenerate extracts and logs. The portable submission includes the prepared leaf C files, generated miters and recorded evidence.', '',
        'Sources: [CHStone repository](https://github.com/ferrandi/CHStone), [MachSuite repository](https://github.com/breagen/MachSuite), [HLS-Eval repository](https://github.com/sharc-lab/hls-eval).']
    (ROOT/'results/dataset_audit/REPORT.md').write_text('\n'.join(lines)+'\n', encoding='utf-8')


def main():
    write_local(); write_subtle(); write_datasets()
    print('Wrote local-model, subtle-fault and dataset reports.')


if __name__ == '__main__':
    main()
