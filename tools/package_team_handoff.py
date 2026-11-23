"""Build a teammate-oriented source/evidence ZIP and readable result overview."""
import hashlib
import json
from pathlib import Path
import re
import zipfile

from package_submission import selected_files

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'output/team_handoff'
ZIP = ROOT / 'output/Project3_Team_Handoff.zip'


def read(name):
    return json.loads((ROOT / name).read_text(encoding='utf-8'))


def table(headers, rows):
    return '\n'.join(['| ' + ' | '.join(headers) + ' |',
        '| ' + ' | '.join(['---'] * len(headers)) + ' |'] +
        ['| ' + ' | '.join(str(x).replace('|', '\\|') for x in row) + ' |' for row in rows])


def improvement(a, b):
    return f'{100 * (1 - b / a):+.2f}%'


README = '''# Project 3: LLM-optimized HLS code with formal equivalence

This is our CS5291 team handoff. Start here, then read [RESULTS.md](RESULTS.md)
for all experiment groups, measured tables and links to their evidence.

## What the project does

An LLM rewrites a C kernel to improve hardware. We first check whether the
rewrite preserves behavior, then measure its synthesized hardware. Correctness
and hardware benefit are separate decisions: a correct rewrite can be slower
or larger.

```text
Original C + LLM candidate
    -> input/contract checks
    -> formal C-to-C equivalence
    -> proof-evidence replay and input binding
    -> compiled-C edge/random checks
    -> Bambu HLS + Verilator RTL simulation
    -> Yosys area + OpenSTA timing
    -> original/candidate comparison
```

The checker lives in `hlscheck/`. Our symbolic executor and Z3 prove relations
between program regions. Those certified relations simplify a C product program
whose remaining behavior ESBMC/Z3 verifies. If an abstract mismatch loses a
necessary relationship, the checker refines the summary or restores original
code. This combines established verification ideas; ESBMC itself is reused
without modification. See [the algorithm](docs/INTEGRATED_ALGORITHM.md) when
you want the proof details.

## Run it

After installing the dependencies described in [SETUP.md](SETUP.md), run from
the extracted project root:

```powershell
.\\.venv\\Scripts\\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

It prints all seven stages. Add `--verify-only` for proof and compiled-C checks
without HLS. Non-equivalent or unproved code stops before synthesis. Each run
gets a fresh `results/demo_pipeline/run_*` folder; `latest.json` points to it.
Use `python run_demo.py --help` for options.

The two top-level matmul files are a simple 4x4 example. `matmul.cpp` uses
i-j-k loops; `matmul_opti.cpp` uses k-i-j. Both first zero the output and add
`a[i*4+k] * b[k*4+j]` to `out[i*4+j]`. Arrays are flattened row-major uint32
values, with addition/multiplication modulo 2^32. They must not overlap.
The pair proves equivalent, but recorded hardware area/latency regress.
The ZIP uses the canonical equivalent example; it does not overwrite the
sender's current editor files.

A small negative example is ready too:

```powershell
.\\.venv\\Scripts\\python.exe run_demo.py benchmarks/pipeline_smoke/wrong_original.c benchmarks/pipeline_smoke/wrong_optimized.c --function kernel
```

For a subtle matmul mistake, `matmul_wrong.cpp` changes multiplication to
addition. Comparing it with `matmul.cpp` should produce a non-equivalence
witness and stop before HLS:

```powershell
.\\.venv\\Scripts\\python.exe run_demo.py matmul.cpp matmul_wrong.cpp --function kernel
```

## Where to look

| Folder/file | Purpose |
| --- | --- |
| `RESULTS.md` | Combined results overview; positive percentage means improvement |
| `hlscheck/` | Frontend, symbolic reasoning, summaries, residual products and evidence checking |
| `scripts/design_pipeline.py`, `scripts/design_testbench.py` | Full pipeline and generated native/RTL reference harnesses |
| `tools/run_hls_linux.py` | Bambu, Verilator, Yosys and OpenSTA driver |
| `benchmarks/`, `matmul*.cpp` | Runnable originals, rewrites and negative controls |
| `experiments/`, `results/` | Plans, provenance, prompts, raw responses, candidates, proofs and hardware evidence |
| `tests/`, `docs/` | Regression checks and optional detailed explanations |
| `output/pdf/`, `output/presentation/` | Existing course report and slides |
| `datasets/papers/` | Eight downloaded related-work papers |

For the presentation, lead with the two-model study and use the 50-pair cohort
and fault controls as supporting evidence. The key finding is that formal
equivalence filters semantic mistakes, while measured HLS reveals whether a
correct optimization helps. There are substantial wins and real regressions.

Scope: supported C11/ILP32 integer kernels, valid nonoverlapping arrays, and
explicit input assumptions. `.cpp` examples use the C-compatible subset.
Hardware numbers are mapped pre-layout Nangate45 ASIC estimates. RTL simulation
is sampled validation, not a formal C-to-RTL proof. No paid inference API is
needed to inspect results or run the supplied candidate pairs.
'''


SETUP = '''# Running this handoff on another computer

Extract the ZIP completely. Run commands from `Project3_Team_Handoff/`.
Recorded Markdown/JSON/CSV results, C files, logs, PDFs and slides can be read
without installing any tool. All required project source code is included.

## Python and a first lightweight check

Use Python 3.12 and create a fresh environment; this ZIP does not copy `.venv`:

```powershell
py -3.12 -m venv .venv
.\\.venv\\Scripts\\python.exe -m pip install -r requirements.txt
.\\.venv\\Scripts\\python.exe -m hlscheck benchmarks/demo/scale_original.c benchmarks/demo/scale_optimized.c --backend symbolic --function kernel
```

That explicit standalone symbolic example uses the Python dependencies. The
default combined checker additionally needs Clang and ESBMC. The supplied
requirements pin Z3, pycparser and pytest. Optional figure/report regeneration
uses `requirements-report.txt`.

## Combined formal checking and compiled-C validation

The tested formal/native setup is Windows with Clang targeting ILP32 and
ESBMC 8.7. Install Clang with a compatible 32-bit C linker/runtime and put it
on PATH. The native harness asserts `short16/int32/long32/long-long64` and
32-bit pointers; a mismatched ABI fails rather than silently changing the
model. A generic 64-bit Linux native compiler is not a drop-in replacement.

Obtain ESBMC 8.7 from the release linked in
[the resource manifest](docs/RESOURCE_MANIFEST.md). Preserve its bundled
runtime libraries and license notices. Set its executable path, for example:

```powershell
$env:ESBMC_PATH = 'C:\\path\\to\\esbmc\\bin\\esbmc.exe'
clang --version
.\\.venv\\Scripts\\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel --verify-only
```

Alternatively the adapter finds `esbmc` on PATH or the original bundled
location `tools/esbmc-v8.7/release/bin/esbmc.exe`. A missing dependency produces
an error or unproved outcome; it must not be described as a successful proof.

## Full hardware pipeline

The tested configuration uses WSL Ubuntu for Bambu/Verilator/Yosys/OpenSTA.
Install WSL Ubuntu and the Linux packages `libtcl8.6`, `verilator`, `gcc`,
`g++`, and `make`. Then, from PowerShell in this project root:

```powershell
wsl -d Ubuntu -- python3 tools/bootstrap_hls_linux.py --download
.\\.venv\\Scripts\\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

The bootstrap prints the pinned downloads and checks their recorded hashes:
Bambu 508.89 MiB and backend bundle 74.14 MiB. It installs under the Linux
home directory. The Nangate45 library and its license are included. No Vitis
license is required. See [REPRODUCE.md](docs/REPRODUCE.md) and
[FILE_PIPELINE.md](docs/FILE_PIPELINE.md) for the detailed configuration.

Large binary toolchains, model weights, virtual environments and whole upstream
repositories are excluded. Prepared benchmark extracts, notices/provenance,
raw model responses, generated candidates and recorded evidence are included.
New model generation is optional; `tools/setup_local_coder.py` and
`tools/serve_local_coder.py` support the original Qwen experiment. GPT candidates
are retained responses from actual Codex tasks; no cloud credentials are bundled.

Historical logs retain the original machine paths and percentage conventions.
They are evidence records, not portable commands to copy literally. `RESULTS.md`
recomputes all improvement percentages from recorded measurements; positive
means better. Its cohort counts must not be added into one independent sample.
The older PDF/slides predate the latest model study; use `RESULTS.md` for the
current combined overview.
'''


def results_markdown():
    main = read('results/submission/summary.json')
    models = read('results/two_model_study/summary.json')
    validation = read('results/two_model_study/validation.json')
    hybrid = read('results/hybrid/study/summary.json')
    large = read('results/large/summary.json')
    local = read('results/local_llm/summary.json')
    local_hls = read('results/local_llm/hls/summary.json')
    faults = read('results/subtle_faults/summary.json')
    leaves = read('results/dataset_leaves/summary.json')
    names = {'qwen15': 'Qwen Coder 1.5B', 'gpt61sol': 'GPT-6.1-Sol'}
    sections = ['# Project 3 results', '''This overview groups the completed experiments and links to their detailed
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
''']
    sections.append(f'''{main['design_pairs']} original/candidate pairs, {main['unique_original_c_asts']} distinct original C ASTs,
{main['synthesized_implementations']} synthesized implementations. All {main['proved_optimized_pairs']} candidates proved equivalent;
all {main['rejected_seeded_mutants']} separate seeded faults were rejected. There are
{main['native_optimized_trials']:,} compiled-C pair trials, {main['native_witnesses_replayed']} exact native witness replays and
{main['rtl_simulation_calls']:,} RTL transactions. All 100 implementations meet the common clock.

ALP outcomes: **22 improved, 25 regressed, 3 unchanged**. Area improves in
14 pairs, cycles in 34 and critical-path delay in 11. These are LLM-assisted
educational/adapted/feedback rewrites, not a first-response LLM success rate
or fifty whole unmodified public benchmark applications.
''')
    rows=[]
    for c in main['comparisons']:
        a,b=c['original'],c['optimized']
        rows.append([c['case'],f"{a['area_um2']:.2f} -> {b['area_um2']:.2f}",
            improvement(a['area_um2'],b['area_um2']),f"{a['cycles']:g} -> {b['cycles']:g}",
            improvement(a['cycles'],b['cycles']),f"{a['delay_ns']:.3f} -> {b['delay_ns']:.3f}",
            improvement(a['delay_ns'],b['delay_ns']),improvement(a['area_latency_product_um2_ns'],b['area_latency_product_um2_ns'])])
    sections.append(table(['Case','Area original -> candidate','Area improvement','Cycles original -> candidate','Latency improvement','Delay ns original -> candidate','Delay improvement','ALP improvement'],rows))
    sections.append('''Prefix reuse reduces repeated work (62 -> 26 cycles and roughly half the
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
''')
    sections.append(table(['Model','Attempts','Equivalent','Confirmed mismatch','Inconclusive','AST unchanged','Measured candidates','ALP wins / regressions / unchanged'],[
        [names[k],12,v['status_counts'].get('equivalent',0),v['status_counts'].get('not_equivalent',0),
         v['status_counts'].get('inconclusive',0),v['ast_unchanged'],v['measured_candidates'],
         f"{v['useful_improvements']} / {v['area_latency_regressions']} / {v['area_latency_unchanged']}"]
         for k,v in models['models'].items()]))
    rows=[]
    for c in models['cases']:
        a,b=c.get('baseline_hardware'),c.get('hardware')
        if a and b:
            rows.append([c['case'],names[c['model']],c['status'],
              f"{a['cycles']:g} -> {b['cycles']:g}",f"{c['latency_speedup']:.3f}x",
              improvement(a['area_um2'],b['area_um2']),improvement(a['delay_ns'],b['delay_ns']),
              improvement(a['area_latency_product_um2_ns'],b['area_latency_product_um2_ns'])])
        else:
            rows.append([c['case'],names[c['model']],c['status'],'not measured','-','-','-','-'])
    sections.append(table(['Case','Model','Verdict','Cycles original -> candidate','Speedup','Area improvement','Delay improvement','ALP improvement'],rows))
    sections.append(table(['Model','Same measured cases','Geomean latency speedup','Geomean ALP ratio (lower is better)'],[
        [names[k],v['count'],f"{v['geomean_latency_speedup']:.3f}x",f"{v['geomean_area_latency_ratio']:.3f}"]
        for k,v in models['paired_common_case_comparison'].items()]))
    sections.append(f'''GPT SYRK is the useful ALP win: 232 -> 100 cycles, roughly 39.68% less area,
and **74.00% ALP improvement**, although its delay increases. GPT GEMM,
stencil and MVT reduce latency but increase ALP. Nine Qwen responses are AST
unchanged; equivalence does not mean useful optimization. GPT ATAX/BiCG
remain inconclusive at 60 seconds per obligation (specialized-frontend
limitations followed by ESBMC timeout); neither is called incorrect or given
hardware numbers.

Validation: {validation['actual_hls_implementations']} hardware implementations,
{validation['rtl_transactions']} RTL transactions, {validation['primary_compiled_c_pair_trials']:,} primary plus
{validation['supplementary_compiled_c_pair_trials']:,} supplementary compiled-C pair trials,
{validation['primary_smt_queries_replayed']} accepted SMT query replays, and five native-harness controls
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
''')
    sections.append(table(['Initial outcome','Attempts'],list(local['counts'].items())))
    sections.append('''Initially, 19 equivalent responses were AST unchanged and nine changed.
A later 60-second retry proves the unresolved range8 pair equivalent, giving
29 established equivalent attempts across runs, ten with changed AST. Only
the initial nine changed equivalent outputs have hardware measurements:
three ALP wins, five unchanged and one regression. The newly proved retry
has no added HLS measurement.
''')
    sections.append(table(['Attempt','Cycles original -> candidate','Area improvement','Latency improvement','Delay improvement','ALP improvement'],[
        [c['id'],f"{c['baseline']['cycles']:g} -> {c['candidate']['cycles']:g}",
         *[improvement(c['baseline'][key],c['candidate'][key]) for key in
           ('area_um2','cycles','delay_ns','area_latency_product_um2_ns')]] for c in local_hls['cases']]))
    sections.append('''The eight safe mismatches are genuine saved model errors: FIR coefficients,
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
''')
    sections.append(table(['Outcome','Pairs'],list(hybrid['counts'].items())))
    sections.append(f'''These {hybrid['total']} checks reuse cases from the main, local-model, subtle-fault,
public-leaf and targeted mixed cohorts. {hybrid['matched_known_labels']}/{hybrid['known_labels']} previously established labels
match; the remaining known-equivalent case is inconclusive, with no
contradictory conclusive verdict. Summaries are accepted in
{hybrid['accepted_summaries']} cases and refinement occurs in {hybrid['refined_cases']}.
All accepted SMT dependencies replay, and all {hybrid['available_native_witnesses']} available concrete mismatch
inputs reproduce a difference in compiled C. This does not establish
soundness for arbitrary C or independence of all test cases.
''')
    ablation=read('results/hybrid/ablation/summary.json')
    sections.append(table(['Targeted case','Standalone symbolic','Monolithic ESBMC/Z3','Combined','Combined seconds'],[
        [c['id'],c['standalone_symbolic']['status'],c['monolithic_bmc']['status'],c['hybrid_status'],
         f"{c['hybrid_elapsed_seconds']:.3f}"] for c in ablation['cases']]))
    sections.append('''The mixed GEMM example needs both contributions: a symbolic loop-relation
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
''')
    sections.append(f'''{large['total']} checks: 27 scaled pairs plus two retries of identical earlier inputs.
Outcomes: 22 equivalent, three non-equivalent, four inconclusive. The limit
is 60 seconds per SMT/C-verifier obligation, not per whole source pair.
Accepted dependency replays and available native witnesses pass. No new
hardware QoR is claimed for this scaling study.
''')
    sections.append(table(['Case','Scale','Verdict','Total seconds'],[
        [c['id'],c['scale'],c['status'],f"{c['elapsed_seconds']:.3f}"] for c in large['cases']]))
    sections.append('''Notable proofs include 16x16 GEMM (3.379 s), indexed 16x16 GEMM (15.762 s),
128-element prefix (2.639 s), 128-element dot (0.958 s), 64-tap FIR
(0.713 s), and 16x16 stencil (2.491 s). The two prior inconclusive pairs
resolve at the longer budget; other unresolved cases remain explicit.
''')
    loops=read('results/loop_budget/summary.json')
    sections.append(table(['Additional loop-budget check','Unwind bound','Verdict','Seconds'],[
        [c['id'],c['max_unroll'],c['status'],f"{c['elapsed_seconds']:.3f}"] for c in loops['cases']]))
    sections.append('''Tightening unwind bounds for these input-dependent loops does not make
their proof problems disappear; inconclusive remains a valid outcome.
Evidence: [larger-case report](results/large/REPORT.md),
[full summary](results/large/summary.json),
[loop-budget experiment](results/loop_budget/summary.json).

## 6. Subtle faults and semantic controls
''')
    sections.append(table(['Expected and observed outcome','Cases'],list(faults['counts'].items())))
    sections.append('''All 80 controlled labels match: 54 semantic faults rejected, 20 equivalent
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
''')
    sections.append(table(['Public-leaf result','Pairs'],list(leaves['counts'].items())))
    sections.append('''All eight rewrites prove equivalent and all eight seeded bugs are rejected
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
''')
    sections.append(table(['Model','Formal/frontend outcome','Hardware result'],[
        ['SmolLM2-360M','compile failure','not measured'],
        ['Qwen Coder 1.5B','unsupported builtin','not measured'],
        ['IBM Granite 3.3 2B','equivalent','62 cycles; unchanged QoR'],
        ['GPT-6.1-Sol','equivalent','62 -> 26 cycles; +79.38% ALP improvement']]))
    sections.append('''The Qwen pilot also has a separately compiled concrete mismatch; its formal
status remains unsupported. Three implementations (including baseline)
underwent fresh hardware runs: 48 RTL transactions. One prompt on one kernel
validates the workflow, not model accuracy. [Pilot evidence](results/model_pilot_quick/REPORT.md).

## 9. Complete file-to-file pipeline demonstration

`run_demo.py matmul.cpp matmul_opti.cpp --function kernel` compares the actual
top-level files. The recorded i-j-k / k-i-j pair proves equivalent and passes
264 compiled-C comparisons and 32 RTL transactions, but its hardware regresses:
''')
    demo=read('results/demo_pipeline_validation/run_ada9001fc0a9/hardware.json')['measurements']
    a,b=demo['original'],demo['optimized']
    sections.append(table(['Metric','Original','Candidate','Improvement'],[
        [name,f'{a[key]:.6g}',f'{b[key]:.6g}',improvement(a[key],b[key])] for name,key in
        [('Area (um^2)','area_um2'),('Latency (cycles)','cycles'),('Latency at 10 ns (ns)','latency_at_target_ns'),
         ('Critical-path delay (ns)','delay_ns'),('Area x latency','area_latency_product_um2_ns')]]))
    sections.append('''A second full run checks a 64-bit sign extraction and certified top-name
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
''')
    return '\n\n'.join(sections) + '\n'


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    generated = {'README.md': README, 'RESULTS.md': results_markdown(), 'SETUP.md': SETUP,
                 'tmp/README.md': 'Scratch directory for new local verification and pytest runs.\n'}
    # Ship a stable, documented teaching pair even when the editor pair has
    # been intentionally mutated. Never modify the sender's working sources.
    generated['matmul.cpp'] = (ROOT/'benchmarks/matmul_loop_order/matmul_ijk.cpp').read_text(encoding='utf-8')
    generated['matmul_opti.cpp'] = (ROOT/'benchmarks/matmul_loop_order/matmul_kij.cpp').read_text(encoding='utf-8')
    needle='a[i * 4 + k] * b[k * 4 + j]'
    assert generated['matmul_opti.cpp'].count(needle)==1
    generated['matmul_wrong.cpp'] = generated['matmul_opti.cpp'].replace(needle,'a[i * 4 + k] + b[k * 4 + j]')
    for name in ('README.md', 'RESULTS.md', 'SETUP.md'):
        (OUT / name).write_text(generated[name], encoding='utf-8', newline='\n')
    paths = {p.relative_to(ROOT).as_posix(): p for p in selected_files()}
    for p in (ROOT / 'datasets/papers').glob('*.pdf'):
        paths[p.relative_to(ROOT).as_posix()] = p
    for folder in ('datasets/MachSuite','datasets/CHStone','datasets/hls-eval','datasets/EqBench'):
        for p in (ROOT / folder).glob('*'):
            if p.is_file() and p.name.lower().startswith(('license','copying','copyright','notice')):
                paths[p.relative_to(ROOT).as_posix()] = p
    for name in ('results/local_llm/server.log','results/local_llm/server_process.json'):
        paths.pop(name,None)
    for name in generated:
        paths.pop(name,None)
    entries=[]
    secret=re.compile(rb'(?<![A-Za-z0-9])(?:xai-|sk-ant-|sk-proj-)[A-Za-z0-9_-]{24,}')
    with zipfile.ZipFile(ZIP,'w',compression=zipfile.ZIP_DEFLATED,compresslevel=6) as archive:
        for name in sorted(set(paths) | set(generated)):
            data=generated[name].encode('utf-8') if name in generated else paths[name].read_bytes()
            if Path(name).suffix.lower() not in ('.pdf','.png','.svg') and secret.search(data):
                raise RuntimeError('Possible API credential in '+name+'; not safe to share')
            archive.writestr('Project3_Team_Handoff/'+name,data)
            entries.append({'path':name,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()})
        manifest={'purpose':'Teammate handoff: concise README, complete results overview, source and recorded evidence',
            'excluded':'virtual environments, binary toolchains, model weights, complete upstream repositories, machine server state',
            'files':entries}
        archive.writestr('Project3_Team_Handoff/MANIFEST.json',json.dumps(manifest,indent=2)+'\n')
    with zipfile.ZipFile(ZIP) as archive:
        for entry in entries:
            data=archive.read('Project3_Team_Handoff/'+entry['path'])
            assert len(data)==entry['bytes'] and hashlib.sha256(data).hexdigest()==entry['sha256']
        names=set(archive.namelist())
        for text in generated.values():
            for target in re.findall(r'\]\(([^)]+)\)',text):
                if target.startswith(('http:','https:','#')):
                    continue
                target=target.split('#')[0]
                prefix='Project3_Team_Handoff/'+target
                assert prefix in names or any(n.startswith(prefix.rstrip('/')+'/') for n in names),target
    (OUT/'MANIFEST.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
    digest=hashlib.sha256(ZIP.read_bytes()).hexdigest()
    assert ZIP.stat().st_size < 50_000_000, 'Team ZIP exceeds the requested 50 MB limit'
    ZIP.with_suffix('.sha256').write_text(digest+'  '+ZIP.name+'\n',encoding='utf-8')
    print(f'Packaged {len(entries)} files; {ZIP.stat().st_size/2**20:.2f} MiB; all entry hashes/CRCs and handoff links verified.',flush=True)


if __name__ == '__main__':
    main()
