"""Build the written report, scientific figures and an offline presentation.

Content is derived from recorded experiment JSON. No missing results are
estimated or filled in. Run with the reporting Python environment.
"""
from __future__ import annotations

import html
import json
from pathlib import Path
import sys
import textwrap

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/report-deps'))

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER
from reportlab.lib.styles import ParagraphStyle,getSampleStyleSheet
from reportlab.lib.utils import ImageReader
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import SimpleDocTemplate,Paragraph,Spacer,Table,TableStyle,PageBreak,Image,Preformatted,KeepTogether
from reportlab.lib.pagesizes import A4

SUMMARY=json.loads((ROOT/'results/submission/summary.json').read_text())
PROOFS=json.loads((ROOT/'results/submission_verification/summary.json').read_text())
HLS=json.loads((ROOT/'results/hls/summary.json').read_text())
CASES=SUMMARY['comparisons']
BY_NAME={r['case']:r for r in CASES}
FIGURES=ROOT/'output/figures'
PDFS=ROOT/'output/pdf'
DECK=ROOT/'output/presentation'
NAVY='#142b43'
BLUE='#206d9e'
TEAL='#0c7a68'
GOLD='#b57015'
RED='#b54e42'

REFERENCES=[
    ('Dahiya and Bansal (APLAS 2017)', 'Black-box equivalence checking across compiler optimizations.', 'https://www.cse.iitd.ac.in/~sbansal/pubs/aplas17.pdf'),
    ('Pouchet et al. (FPGA 2024)', 'Formal Verification of Source-to-Source Transformations for HLS.', 'https://doi.org/10.1145/3626202.3637563'),
    ('Lopes et al. (PLDI 2021)', 'Alive2: Bounded Translation Validation for LLVM.', 'https://doi.org/10.1145/3453483.3454030'),
    ('Xiong et al. (2024 preprint)', 'HLSPilot: LLM-based High-Level Synthesis.', 'https://arxiv.org/abs/2408.06810'),
    ('Abi-Karam and Hao (2025 preprint)', 'HLS-Eval: A Benchmark and Framework for Evaluating LLMs on High-Level Synthesis Design Tasks.', 'https://arxiv.org/abs/2504.12268'),
    ('Jakobs (2021 technical report)', 'PEQcheck: Localized and Context-aware Checking of Functional Equivalence.', 'https://arxiv.org/abs/2101.09042'),
    ('ESBMC project', 'Released ESBMC 8.7 implementation used with Z3.', 'https://github.com/esbmc/esbmc/releases/tag/v8.7'),
    ('PAST authors', 'PAST Python bindings, release 0.7.2.', 'https://github.com/cornell-zhang/past-python-bindings'),
    ('PandA Bambu project', 'Bambu HLS source and releases; exact local binary revision retained in logs.', 'https://github.com/ferrandi/PandA-bambu'),
    ('OpenROAD project', 'Nangate45 typical Liberty and license in OpenROAD-flow-scripts.', 'https://github.com/The-OpenROAD-Project/OpenROAD-flow-scripts/tree/master/flow/platforms/nangate45'),
    ('MachSuite', 'GEMM and stencil reference algorithms; commit 6236e593012cb86b0d2f08d9fb9ba0411ff989b4.', 'https://github.com/breagen/MachSuite'),
    ('EqBench', 'Public equivalence pairs; commit 3724fce5b287cc63165028444daf904f25b0158b.', 'https://github.com/shrBadihi/EqBench'),
]


def percent(ratio):
    return f'{(ratio-1)*100:+.1f}%'


def figures():
    plt.rcParams.update({'font.family':'DejaVu Sans','font.size':11,'axes.spines.top':False,'axes.spines.right':False})
    labels=[r['case'] for r in CASES]
    fig,ax=plt.subplots(figsize=(10.5,4.7),layout='constrained')
    y=np.arange(len(CASES))
    for offset,key,label,color,marker in [(-.18,'area_um2','Cell area',BLUE,'s'),(0,'cycles','Latency cycles',GOLD,'o'),(.18,'area_latency_product_um2_ns','Area x latency',TEAL,'D')]:
        ax.scatter([r['ratios'][key] for r in CASES],y+offset,s=48,color=color,marker=marker,label=label,zorder=3)
    ax.axvline(1,color=NAVY,lw=1.4,ls='--',label='Original = 1')
    ax.set_xscale('log');ax.set_xlim(.15,11)
    ax.set_xticks([.2,.5,1,2,5,10],labels=['0.2','0.5','1','2','5','10'])
    ax.set_yticks(y,labels);ax.invert_yaxis()
    ax.set_xlabel('Candidate / original ratio (log scale; lower is better)')
    ax.grid(axis='x',which='major',alpha=.18);ax.set_axisbelow(True)
    ax.legend(loc='upper center',bbox_to_anchor=(.5,1.17),ncol=4,frameon=False,fontsize=10)
    fig.savefig(FIGURES/'qor_ratios.png',dpi=190,facecolor='white');fig.savefig(FIGURES/'qor_ratios.svg');plt.close(fig)
    p=BY_NAME['prefix'];a,b=p['original'],p['optimized']
    fig,axes=plt.subplots(1,2,figsize=(9.8,3.1),layout='constrained')
    for ax,key,title,unit in [(axes[0],'area_um2','Mapped cell area','um²'),(axes[1],'cycles','Function latency','cycles')]:
        vals=[a[key],b[key]]
        bars=ax.bar(['Original','Reuse'],vals,color=[BLUE,TEAL],width=.55)
        ax.set_title(title,loc='left',fontweight='bold',fontsize=12);ax.set_ylabel(unit);ax.set_ylim(0,max(vals)*1.24)
        ax.bar_label(bars,labels=[f'{v:,.2f}' if key=='area_um2' else f'{v:g}' for v in vals],padding=5,fontsize=12)
        ax.spines['left'].set_visible(False);ax.grid(axis='y',alpha=.15);ax.set_axisbelow(True)
    fig.savefig(FIGURES/'prefix_gain.png',dpi=190,facecolor='white');fig.savefig(FIGURES/'prefix_gain.svg');plt.close(fig)


def report_pages():
    p=BY_NAME['prefix'];f=BY_NAME['fir'];s=BY_NAME['stencil'];b=BY_NAME['boxfilter']
    results=[['Kernel','Area: original /\ncandidate (um²)','Delay: original /\ncandidate (ns)','Cycles: original /\ncandidate','ADP\nratio']]
    for r in CASES:
        a,c=r['original'],r['optimized']
        results.append([r['case'],f"{a['area_um2']:.2f} / {c['area_um2']:.2f}",f"{a['delay_ns']:.3f} / {c['delay_ns']:.3f}",f"{a['cycles']:g} / {c['cycles']:g}",f"{r['ratios']['area_latency_product_um2_ns']:.3f}"])
    validation=[['Kernel','Optimized proof (ms)','Fault found (ms)']]
    for c in CASES:
        pair=[next(x for x in PROOFS['cases'] if x['case']==c['case'] and x['variant']==v) for v in ('optimized','buggy')]
        validation.append([c['case']]+[f"{r['verification']['elapsed_seconds']*1000:.1f}" for r in pair])
    return [
    ('Formal Equivalence Checking of LLM-Optimized HLS Code',[
        ('subtitle','CS5291: C-Based VLSI Design | Project 3 | Submission report | 22 November 2026'),
        ('h2','Abstract'),
        ('p','This project implements and evaluates a workflow in which an LLM proposes C source rewrites, an SMT-backed C-to-C checker validates their behavior, and real HLS experiments determine whether the rewrites improve hardware. The checker propagates symbolic 32-bit values through C control flow, completely expands supported finite loops and asks Z3 whether any common input produces different observable outputs. An ESBMC/Z3 adapter provides a separate fallback for selected cases outside this interpreter subset.'),
        ('p','Eight kernel families are evaluated: two small, explicitly documented MachSuite adaptations and six educational kernels. All eight candidate rewrites are proved equivalent in the modeled domain; all eight deliberately seeded faulty variants are rejected with witnesses reproduced in compiled C. Bambu, Verilator, Yosys and OpenSTA provide measured RTL latency, mapped cell area and pre-layout timing for all sixteen original/candidate designs.'),
        ('image','prefix_gain.png',172),
        ('p',f"Prefix reuse reduces mapped area by {(1-p['ratios']['area_um2'])*100:.1f}% and latency cycles by {(1-p['ratios']['cycles'])*100:.1f}%. Its area x latency product falls by {(1-p['ratios']['area_latency_product_um2_ns'])*100:.1f}%. FIR pre-addition saves {(1-f['ratios']['area_um2'])*100:.1f}% area at unchanged cycle latency. Other candidates trade area for latency, regress, or match compiler-generated hardware. Thus equivalence and hardware improvement are separate acceptance conditions."),
        ('h2','Course-project contribution'),
        ('p','The contribution is an independently implemented restricted-C checker, an attributed ESBMC integration, calibration against the released PAST implementation, and a reproducible formal-plus-HLS evaluation with negative controls and explicit assumptions. It combines established techniques; it does not claim a new equivalence algorithm or general support for all C programs.'),
        ('small','All QoR results are synthesis estimates for Nangate45 typical at a common 10 ns target. No commercial FPGA tool or placed-and-routed silicon measurements are claimed.')]),
    ('1. Problem and related work',[
        ('p','HLS maps C operations and memory accesses to a scheduled datapath and controller. Equivalent C expressions can expose different sharing, parallelism or memory traffic. LLMs can propose useful rewrites but cannot certify them. Testing samples inputs; the required formal question is whether any admissible input can cause a mismatch.'),
        ('h2','What Project 3 requires'),
        ('table',[['Requirement','Delivered evidence'],['LLM source-to-source optimization','Eight recorded original/candidate pairs and transformation provenance'],['Area / delay / latency evaluation','Sixteen Bambu + Yosys + OpenSTA runs with Verilator cycle measurements'],['Develop an SMT-backed C-to-C checker','Python C-AST interpreter, Z3 bit-vectors, SMT-LIB export and witnesses'],['Show the checker working','Positive proofs, seeded faults, native replay, fallback and public-data audit']], [1,2.15]),
        ('h2','Promising papers and their role'),
        ('table',[['Work','Idea used or studied','Difference from this project'],['Dahiya & Bansal [1]','Black-box correlation across compiler optimizations; semantic assumptions matter','We do not reproduce their binary transfer-graph correlation algorithm'],['Pouchet et al. / PAST [2,8]','Concrete control with symbolic computations for HLS source rewrites','We build a smaller C interpreter and discharge bit-vector queries with Z3'],['Alive2 [3]','SMT translation validation and precise machine arithmetic / UB reasoning','Our subset is much smaller; we check total defined behavior, not full LLVM refinement'],['HLSPilot / HLS-Eval [4,5]','LLM HLS transformations and empirical evaluation','We couple source equivalence with a small measured hardware study'],['PEQcheck / ESBMC [6,7]','Reduce equivalence to assertion verification','Our adapter generates a whole-function miter and retains safety / unwinding checks']], [1.1,1.4,1.7]),
        ('p','The course slides on program equivalence motivate execution conditions and symbolic value propagation. We compare final observables without requiring equal temporary variables or identical control flow. Unlike the full FSMD/cutpoint methods in the slides, the custom interpreter does not infer loop invariants. Attribution and details are in docs/RELATED_WORK_AND_NOVELTY.md and docs/COURSE_CONNECTIONS.md.')]),
    ('2. Formal contract and supported semantics',[
        ('p','Let P and Q receive the same initial scalar values and equal copies of each array. An observation contains the return value, when present, and every final parameter-array element, including untouched elements. Parameter arrays are valid and pairwise nonoverlapping. Only function-completion behavior is compared.'),
        ('code','Mismatch(x) = OR over final path pairs (p,q):\n  guard_P(p,x) AND guard_Q(q,x)\n  AND observations_P(p,x) != observations_Q(q,x)\n\nSAT     -> a concrete behavioral counterexample\nUNSAT   -> equivalence in the supported, fully explored domain\nUNKNOWN -> no equivalence or mismatch conclusion'),
        ('p','Both executions must be defined over the admitted input domain before an equivalence verdict is accepted. Reachable division by zero, invalid shift counts and modeled out-of-bounds accesses are reported separately. An unsafe source is not vacuously accepted. This policy is stricter than a source-to-target refinement relation that ignores source-undefined executions.'),
        ('h2','Supported by the custom symbolic interpreter'),
        ('table',[['Feature','Contract'],['Data','32-bit unsigned int / uint32_t; modulo-2^32 arithmetic'],['Interface','One function; unsigned scalar or void result; fixed-size 1D unsigned arrays'],['Control','Symbolic if / conditional expressions, guarded short-circuit evaluation, early returns'],['Loops and memory','Complete expansion of concrete-resolvable finite bounds and subscripts; explicit resource budgets'],['Locals','Unsigned data; concrete signed int loop counters; initialization required'],['Outputs','Return value and all final parameter arrays, matched by argument position']], [1,2.4]),
        ('p','Unsupported cases include arbitrary pointers and aliases, helper calls, globals, persistent state, recursion, floating point, symbolic signed arithmetic, symbolic indices or general input-dependent loops in the custom interpreter. Unsupported syntax is rejected. General preprocessing is not performed; stdint.h and HLS pragmas are handled narrowly.'),
        ('h2','What a proof does not establish'),
        ('p','The result is conditional on the encoded C subset and memory assumptions. It is not a proof for aliasing callers, for different numeric types or dimensions, or for the correctness of the HLS compiler. It does not establish cycle-by-cycle C-to-RTL equivalence. The interpreter itself is experimental software, tested and cross-checked but not formally verified. Exported SMT-LIB queries are replayable queries, not independently checked proof certificates.')]),
    ('3. Implementation and acceptance workflow',[
        ('code','original C + LLM candidate C\n  -> parse and validate the supported interface\n  -> execute both on common symbolic inputs\n  -> retain path guards and final observations\n  -> check reachable semantic hazards\n  -> simplify the bit-vector mismatch formula\n  -> Z3: proof / counterexample / inconclusive\n  -> native checks and witness replay\n  -> exact-source proof gate\n  -> HLS + RTL simulation + mapping + timing\n  -> choose according to the declared QoR objective'),
        ('p','hlscheck/checker.py uses pycparser for the C AST and Z3 expressions for data. State forks copy mutable containers while sharing immutable symbolic expressions. Loop execution terminates only after the actual finite bound has been explored; exceeding an iteration, path or execution budget yields an unsupported/inconclusive result. The solver is allowed to time out without turning that timeout into a proof.'),
        ('h2','ESBMC fallback'),
        ('p','The auto backend first attempts the custom interpreter. On an unsupported or inconclusive case it can generate a C miter for ESBMC 8.7 with Z3. Separate original/candidate arrays begin with equal nondeterministic contents; assertions compare all final arrays and the return value. Bounds, pointer, overflow, shift, initialization and unwinding assertions remain enabled. A source bug or modeled undefined behavior is not silently overridden by fallback.'),
        ('p','The adapter can handle signed int interfaces and symbolic array indexing through ESBMC; this does not extend the semantics implemented by our own interpreter. Explicit scalar range assumptions are supported when supplied and are recorded. The public-data experiment adds no such ranges. An incomplete unwind is reported as incomplete_unwind, never equivalent.'),
        ('h2','Hardware gate and objective'),
        ('p','Each optimized source and baseline must match the source hashes in an equivalent proof record before synthesis. For the reported selection policy, a candidate must meet the common 10 ns timing constraint and strictly reduce mapped area x latency. Correct candidates that regress this objective remain in the report and the original implementation is retained. A latency-first policy could instead accept a documented area increase.'),
        ('small','PAST is an independently invoked structural reference, not an implicit acceptance stage and not an SMT proof substitute. Existing verifiers are credited and kept separate from the custom implementation.')]),
    ('4. Benchmarks and experimental method',[
        ('table',[['Family','Origin / dimensions','LLM transformation'],['scale','Educational; 8 values','Strength reduction + two-way source unrolling'],['unswitch','Course example; 4 outputs','Move an input-invariant branch outside the loop'],['gemm','MachSuite adaptation; unsigned 4 x 4','Loop interchange and reuse of an input scalar'],['stencil','MachSuite adaptation; 5 x 5, 3 x 3 filter','Expand filter-column computations'],['prefix','Educational; 8 prefix sums','Reuse the running prefix instead of recomputing'],['fir','Educational; 8 symmetric taps','Pre-add mirrored samples before constant multiply'],['boxfilter','Educational; 5 x 5 to 3 x 3','Separable horizontal buffer and sliding reuse'],['factor','Educational; 3 unsigned scalars','Distributive arithmetic factoring']], [0.65,1.35,1.65]),
        ('p','The GEMM reference was adapted from MachSuite gemm/ncubed (double, 64 x 64) and the stencil from stencil2d (signed 128 x 64). Our dimensions and uint32_t types are the same within each checked pair. We do not claim a proof relating those adapted references to the upstream floating/signed programs. The upstream commit and BSD license are preserved [11].'),
        ('h2','LLM and negative-control provenance'),
        ('p','Candidates were authored by the Codex assistant during this project session under instructions to preserve signatures, all final outputs, modulo arithmetic and the nonaliasing domain. Exact source files and hashes are retained. API model ID, temperature and token statistics were not exposed and are not invented. This is a single-session case study, not a reproducible multi-model benchmark. Faulty files are deliberate mutations, not spontaneous LLM errors.'),
        ('h2','Hardware configuration'),
        ('p','Bambu 2026.11, exact revision 6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda, uses Clang 16 and BAMBU-BALANCED-MP (-O2), seed 0, with a 10 ns target for both sources. Verilator 5.020 executes 16 calls per design: eight directed patterns and eight deterministic pseudorandom calls. Yosys 0.36 maps to Nangate45 typical cells (1.1 V, 25 C), and OpenSTA 2.0.18 performs max-path timing [9,10].'),
        ('p','STA uses ideal clocks, zero input/output delay, 50 ps input transitions, 10 fF output loads and no extracted interconnect. Reported delay is 10 ns minus worst setup/max-path slack. All reported unconstrained endpoints are verified to be constant outputs in the mapped netlist. Area includes accelerator logic and any mapped register memory; external host and memory resources are excluded. These are pre-layout ASIC estimates, not FPGA LUT counts or routed measurements.')]),
    ('5. Measured hardware results',[
        ('table',results,[.65,1.5,1.3,1.2,.6]),
        ('small','ADP = mapped cell area x cycles x 10 ns. Candidate/original ratios below 1 improve the selected objective. All sixteen designs meet the 10 ns clock in the stated pre-layout model. Latency in nanoseconds is cycles x 10, not cycles x the individual unconstrained minimum-period estimate.'),
        ('image','qor_ratios.png',232),
        ('p','Two of eight candidates improve area x latency and are selected by that policy: prefix and FIR. Five increase the product; factoring is unchanged. All candidates remain in the experiment. The choice of objective matters: stencil and boxfilter reduce cycles while consuming more area. A correctness proof is necessary for acceptance, but does not predict physical quality.'),
        ('p','The common target, compiler configuration, numeric types and interfaces are fixed within each pair. The measured implementation includes Bambu-generated interfaces and memory access logic, so source operation counts alone are insufficient to predict the outcome. Raw logs and netlists permit inspection beyond the summary table.')]),
    ('6. Interpreting gains, trade-offs and regressions',[
        ('h2','Prefix sums: reuse reduces work'),
        ('p',f"The reference recomputes each prefix, performing 1+2+...+8 = 36 input additions/reads at source level. The candidate maintains one running sum and reads eight inputs. Mapped area changes from {p['original']['area_um2']:.2f} to {p['optimized']['area_um2']:.2f} um²; latency changes from 62 to 26 cycles (620 to 260 ns at the common clock). Delay changes from 1.901 to 1.510 ns. The combined area x latency ratio is {p['ratios']['area_latency_product_um2_ns']:.3f}. The formal proof includes every 32-bit array element, including overflow cases."),
        ('h2','FIR: exploit coefficient symmetry'),
        ('p',f"Mirrored samples are added before multiplying by the equal coefficients 3, 5, 7 and 11. Area falls from {f['original']['area_um2']:.2f} to {f['optimized']['area_um2']:.2f} um² ({(1-f['ratios']['area_um2'])*100:.1f}% lower) while latency remains five cycles. Mapped delay rises slightly from 3.182 to 3.209 ns. It meets the common clock and improves ADP, but does not dominate the baseline on every metric."),
        ('h2','Stencil and boxfilter: faster with a hardware cost'),
        ('p',f"Stencil source unrolling reduces cycles from 158 to 116 ({(1-s['ratios']['cycles'])*100:.1f}% lower), with {(s['ratios']['area_um2']-1)*100:.1f}% more area. Boxfilter reuse reduces cycles from 158 to 87 ({(1-b['ratios']['cycles'])*100:.1f}% lower), but area grows by {(b['ratios']['area_um2']-1)*100:.1f}%. Its temporary horizontal buffer and associated control/access hardware are visible in the generated design. This implementation illustrates why reuse buffers can be expensive on small problems; it is rejected by the ADP policy."),
        ('h2','Regressions and a compiler control'),
        ('p','The scale candidate keeps the same 26-cycle latency while its source unrolling increases mapped area. Unswitching also keeps 14 cycles and costs area. GEMM loop interchange changes 122 cycles to 266 and slightly increases area. A likely explanation is increased output-memory traffic after directly updating the product array; this is an interpretation of the source and synthesized design, not an isolated causal ablation. A better next candidate would keep output accumulators local.'),
        ('p','The factoring pair produces equal mapped area, delay and cycles. Bambu/Clang already canonicalizes the reference arithmetic. It serves as a control showing that a shorter or more algebraic C expression does not necessarily add hardware benefit beyond compiler optimization.'),
        ('small','These are single-configuration, small-kernel observations. They do not establish a general LLM success rate, prove that a transformation class is always beneficial, or predict results on a different memory interface, target or HLS tool.')]),
    ('7. Verification evaluation and public data',[
        ('table',validation,[1,1.35,1.35]),
        ('p','All eight optimized candidates receive equivalent, and all eight seeded faults receive not_equivalent. Each fault witness is compiled and executed independently of the symbolic interpreter; concrete return values and all final arrays match the solver-reported outputs. The optimized pairs also pass 264 compiled-C tests each: eight directed patterns and 256 deterministic random trials, 2,112 executions in total. RTL simulation adds 256 calls across sixteen designs. Testing supports implementation validation; the universal argument is the conditional SMT result.'),
        ('h2','A controlled example that random testing misses'),
        ('p','An additional artificial mutation returns x+2 instead of x+1 only when x is 0xdeadbeef. Ten thousand deterministic pseudorandom compiled-C trials find no mismatch. Z3 supplies x = 3735928559, and compiled C reproduces outputs 3735928560 and 3735928561. This is an illustration of a rare-input bug, not a statistical claim about test effectiveness or LLM error rates.'),
        ('h2','Existing implementations'),
        ('p','On the initial four-family, eight-pair comparison, ESBMC/Z3 resolves seven pairs and agrees on all seven; GEMM equivalence reaches the configured wall-clock limit. The released PAST wheel accepts pure unrolling, GEMM interchange and stencil expansion. It returns 0 on the tested strength reduction, recorded as not_proved rather than a disproof. Input formats and proof strategies differ, so this is calibration and triangulation, not a ranking of general verifier quality.'),
        ('h2','Unmodified EqBench audit'),
        ('p','The pinned public C tree has 247 indexed old-version records and 246 complete source pairs, differing from aggregate README counts. Fourteen pairs are compatible with the current harness adapter. With full signed-input domains, no added preconditions, unwind 32 and a requested 3 s budget plus a 10 s process grace, two are proved, nine report incomplete_unwind and three are unknown. Both proofs agree with upstream labels. This is not 100% accuracy on EqBench: 12/14 evaluated pairs remain inconclusive and most source records are excluded. All fourteen use ESBMC fallback, not signed reasoning in the custom interpreter [12].')]),
    ('8. Reproducibility, limitations and extensions',[
        ('h2','Run the submission'),
        ('code',r'.\.venv\Scripts\python.exe scripts/demo.py'+'\n'+r'.\.venv\Scripts\python.exe run_submission.py --tests'+'\n'+r'.\.venv\Scripts\python.exe run_submission.py --synthesize --force-hls'),
        ('p','The demo performs live proofs and counterexample generation, then clearly labels hardware figures as recorded measurements. The second command reruns core verification, native testing and provenance checks against retained hardware evidence. The last command regenerates hardware with WSL tools. docs/REPRODUCE.md includes a clean-install path and optional independent-verifier/public-data runs.'),
        ('table',[['Artifact','Location'],['Checker and adapters','hlscheck/'],['Recorded LLM sources and provenance','benchmarks/; experiments/'],['Proof verdicts, witnesses and SMT queries','results/submission_verification/'],['Independent compiled-C evidence','results/native/; results/rare_bug/'],['HLS logs, RTL, netlists and constraints','results/hls/'],['Selection policy and complete QoR table','results/submission/'],['Existing-tool / public-data evidence','results/benchmarks/; results/past/; results/eqbench/'],['Report, charts and presentation','output/pdf/; output/figures/; output/presentation/']], [1.25,1.75]),
        ('h2','Material limitations'),
        ('p','Proofs are limited by an explicit C subset and nonaliasing assumptions. There is no inferred invariant for arbitrary loops, no general memory model, no floating-point support and no independent proof of interpreter correctness. Existing-tool checks and compiled witness replay reduce implementation risk but cannot eliminate it. Public-data coverage is small and inconclusive cases are retained.'),
        ('p','Hardware evaluation uses reduced dimensions, one library corner and one clock/configuration. Area and timing are pre-layout estimates; external memory/host costs and physical interconnect are excluded. RTL simulations check finite executions; they are not a C-to-RTL formal equivalence proof. LLM provenance is an assistant-session record and does not enable exact stochastic regeneration.'),
        ('h2','Useful next steps'),
        ('p','Extend the custom backend with typed symbolic memory and selected signed semantics; explore relational invariants for general loops; synthesize larger kernels and additional clock targets; compare local-accumulator GEMM rewrites; and run controlled LLM generation/repair experiments with recorded model IDs and equal budgets. These are extensions rather than claims made by this submission.')]),
    ('References and submission scope',[
        *[('ref',f'[{i}] {authors}. {title}',url) for i,(authors,title,url) in enumerate(REFERENCES,1)],
        ('h2','Additional downloaded reading'),
        ('p','Collini, Garg and Karri, C2HLSC: Can LLMs Bridge the Software-to-Hardware Design Gap? (2024 preprint), and Li et al., ESBMC v7.6: Enhanced Model Checking of C++ Programs with Clang AST (2025 preprint), are retained in papers/. The implementation run uses released ESBMC 8.7, not the paper version.'),
        ('h2','Scope of the claim'),
        ('p','The completed course project demonstrates LLM-authored source candidates, an executable SMT-backed checker, counterexamples, independent replay and measured HLS quality changes. The supported-subset proof, existing-tool reuse and empirical hardware results are explicitly distinguished. No first-of-its-kind research claim, unrestricted C equivalence guarantee, fabricated synthesis result or spontaneous-LLM-fault statistic is asserted.'),
        ('small','Experimental records were produced on Windows with Ubuntu 24.04 under WSL. Tool versions, exact flags, input hashes and library provenance accompany the results. Refer to docs/RESOURCE_MANIFEST.md and docs/THIRD_PARTY_NOTICES.md for resources and attribution.')])]


def init_fonts():
    path=Path(matplotlib.get_data_path())/'fonts/ttf'
    for name,file in [('Body','DejaVuSans.ttf'),('BodyBold','DejaVuSans-Bold.ttf'),('Mono','DejaVuSansMono.ttf')]:
        pdfmetrics.registerFont(TTFont(name,str(path/file)))
    pdfmetrics.registerFontFamily('Body',normal='Body',bold='BodyBold',italic='Body',boldItalic='BodyBold')


def report_pdf(pages):
    styles=getSampleStyleSheet()
    styles.add(ParagraphStyle(name='ProjectBody',fontName='Body',fontSize=9.3,leading=14,spaceAfter=9,textColor=colors.HexColor(NAVY)))
    styles.add(ParagraphStyle(name='ProjectTitle',fontName='BodyBold',fontSize=22,leading=28,spaceAfter=19,textColor=colors.HexColor(NAVY)))
    styles.add(ParagraphStyle(name='ProjectH2',fontName='BodyBold',fontSize=11.3,leading=16,spaceBefore=8,spaceAfter=8,textColor=colors.HexColor(TEAL)))
    styles.add(ParagraphStyle(name='ProjectSmall',parent=styles['ProjectBody'],fontSize=8,leading=11,textColor=colors.HexColor('#536477')))
    styles.add(ParagraphStyle(name='ProjectCode',fontName='Mono',fontSize=8,leading=12,spaceAfter=11,backColor=colors.HexColor('#f2f5f7'),borderPadding=8))
    tablebody=ParagraphStyle(name='TableBody',parent=styles['ProjectBody'],fontSize=7.6,leading=10.4,spaceAfter=0)
    tablehead=ParagraphStyle(name='TableHead',parent=tablebody,fontName='BodyBold',textColor=colors.white)
    story=[]
    markdown=['# Project 3 submission report','']
    def p(text,style='ProjectBody'):
        return Paragraph(html.escape(text).replace('\n','<br/>'),styles[style])
    for page_index,(title,blocks) in enumerate(pages):
        if page_index:story.append(PageBreak())
        story.append(p(title,'ProjectTitle'));markdown += ['## '+title,'']
        for block in blocks:
            kind=block[0]
            if kind in ('p','small','subtitle','h2'):
                style={'p':'ProjectBody','small':'ProjectSmall','subtitle':'ProjectSmall','h2':'ProjectH2'}[kind]
                story.append(p(block[1],style));markdown += [('### ' if kind=='h2' else '')+block[1],'']
            elif kind=='code':
                story.append(Preformatted(block[1],styles['ProjectCode']));markdown+=['```text',block[1],'```','']
            elif kind=='table':
                rows,weights=block[1:]
                width=A4[0]-88
                cells=[[Paragraph(html.escape(str(x)).replace('\n','<br/>'),tablehead if i==0 else tablebody) for x in row] for i,row in enumerate(rows)]
                table=Table(cells,colWidths=[width*x/sum(weights) for x in weights],repeatRows=1,hAlign='LEFT')
                table.setStyle(TableStyle([('BACKGROUND',(0,0),(-1,0),colors.HexColor(NAVY)),('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.HexColor('#f1f5f7'),colors.white]),('VALIGN',(0,0),(-1,-1),'TOP'),('LEFTPADDING',(0,0),(-1,-1),7),('RIGHTPADDING',(0,0),(-1,-1),7),('TOPPADDING',(0,0),(-1,-1),7),('BOTTOMPADDING',(0,0),(-1,-1),7)]))
                story += [table,Spacer(1,11)]
                markdown += ['| '+' | '.join(str(x).replace('\n',' ') for x in rows[0])+' |','| '+' | '.join('---' for _ in rows[0])+' |']
                markdown += ['| '+' | '.join(str(x).replace('\n',' ') for x in row)+' |' for row in rows[1:]]+['']
            elif kind=='image':
                img=Image(str(FIGURES/block[1]));aspect=img.imageHeight/img.imageWidth
                width=min(A4[0]-88,block[2]/aspect)
                img.drawWidth,img.drawHeight=width,width*aspect;story += [img,Spacer(1,9)]
                markdown += [f'![Measured experiment figure](../output/figures/{block[1]})','']
            elif kind=='ref':
                link='<link href="'+html.escape(block[2],quote=True)+'" color="'+BLUE+'">Primary source</link>'
                story.append(Paragraph(html.escape(block[1])+' '+link,styles['ProjectSmall']));markdown += [f'{block[1]} [Primary source]({block[2]}).','']
    def footer(canvas,doc):
        canvas.setStrokeColor(colors.HexColor('#d5dfe5'));canvas.line(44,39,A4[0]-44,39)
        canvas.setFont('Body',7.2);canvas.setFillColor(colors.HexColor('#536477'))
        canvas.drawString(44,26,'CS5291 | HLSCheck | Measured results and conditional equivalence')
        canvas.drawRightString(A4[0]-44,26,str(doc.page))
    doc=SimpleDocTemplate(str(PDFS/'Project3_Report.pdf'),pagesize=A4,leftMargin=44,rightMargin=44,topMargin=38,bottomMargin=49,title='Formal Equivalence Checking of LLM-Optimized HLS Code',author='CS5291 Course Project')
    doc.build(story,onFirstPage=footer,onLaterPages=footer)
    (ROOT/'docs/PROJECT_REPORT.md').write_text('\n'.join(markdown),encoding='utf-8')


def slide_content():
    p=BY_NAME['prefix'];f=BY_NAME['fir']
    return [
    {'title':'Can we trust LLM-optimized HLS code?','tag':'CS5291 / PROJECT 3','lead':'Prove the C rewrite. Measure the hardware.','bullets':['An SMT-backed C-to-C checker, with executable proofs and counterexamples.','Eight kernel families; real HLS, RTL simulation and synthesis results.','Prefix reuse: 51% less cell area and 58% fewer cycles.'],'note':'Introduce the course problem: an LLM can propose a useful rewrite, but correctness and hardware quality both need evidence. The result is a course-level engineering contribution using established formal techniques.'},
    {'title':'Three requirements, three kinds of evidence','table':[['Course requirement','What we deliver'],['LLM C-to-C optimization','Eight recorded candidate rewrites and provenance'],['Area, delay and latency','16 Bambu + Verilator + Yosys + OpenSTA designs'],['Develop an SMT-backed checker','Custom symbolic interpreter, Z3, witnesses and ESBMC fallback']],'foot':'No Vitis installation required. Hardware target: Nangate45 typical, 10 ns.','note':'Explain that running an existing verifier alone would not satisfy our interpretation of developing a checker. We implement the restricted interpreter and separately reuse ESBMC for a broader fallback.'},
    {'title':'Existing papers provide the foundation','table':[['Work','What we take from it'],['Black-box equivalence, APLAS 2017','Do not assume identical control flow; respect semantic assumptions'],['Source transformations for HLS, FPGA 2024 / PAST','Concrete control plus symbolic computation for HLS rewrites'],['Alive2, PLDI 2021','SMT validation, machine arithmetic and precise verdicts'],['PEQcheck / ESBMC','Reduce equivalence to an assertion-verification task'],['HLSPilot / HLS-Eval','LLM transformations need empirical HLS evaluation']],'foot':'Contribution: implementation, integration and evaluation. No new general equivalence algorithm is claimed.','note':'Emphasize PAST as the closest HLS-source paper. The checker shares standard ideas, but does not reproduce its full algorithm. Alive2 operates on LLVM and has a much richer semantic model.'},
    {'title':'Correctness and hardware benefit are separate gates','flow':['Original C + LLM candidate','SMT equivalence check','Compiled-C checks / replay','HLS + RTL simulation','Mapped area + timing','QoR acceptance'],'bullets':['A counterexample rejects a faulty candidate.','A proof permits hardware evaluation of those exact source hashes.','A correct candidate can still lose to the original hardware.'],'note':'Explain the source hash gate. Our selected objective is area times cycles times the common 10 ns period, with the timing constraint satisfied. We keep failed QoR candidates visible.'},
    {'title':'The proof contract is explicit','code':'same initial inputs\nAND a reachable pair of final paths\nAND different observable outputs\n\nSAT   -> concrete counterexample\nUNSAT -> equivalent in the modeled domain','bullets':['uint32_t data: arithmetic wraps modulo 2^32.','Compare return values and every final parameter-array element.','Valid nonoverlapping arrays; complete supported loop expansion.','Unsupported / timeout / incomplete unwind remain inconclusive.'],'note':'Describe a miter query. Equality is at function completion. These are conditional C-to-C guarantees, not cycle-by-cycle C-to-RTL guarantees. All supported paths and finite loop iterations must be covered.'},
    {'title':'A small checker, with a mature fallback','table':[['Our implementation','Reused implementation'],['C AST + symbolic states and path guards','ESBMC 8.7 C miter with Z3'],['Concrete-resolvable bounds and array indices','Selected signed interfaces and symbolic indices'],['Bit-vector mismatch query and SMT-LIB export','Bounds, safety and unwinding assertions retained'],['Reject unsupported syntax conservatively','Record the initial stage and fallback verdict']],'foot':'PAST is a separate structural reference; its failure to prove is not a concrete disproof.','note':'Use index & 7 versus index % 8 as the fallback example. The custom stage rejects symbolic indexing; ESBMC proves it. We do not claim to have implemented ESBMC or PAST.'},
    {'title':'Eight families, with provenance kept visible','table':[['Family','Candidate transformation'],['Scale / unswitch','Strength reduction + unrolling / loop unswitching'],['GEMM / stencil','Loop interchange / filter-column expansion'],['Prefix','Incremental running-sum reuse'],['FIR','Symmetric sample pre-addition'],['Boxfilter','Separable sliding-window buffer'],['Factor','Distributive factoring']],'foot':'GEMM and stencil: reduced unsigned MachSuite adaptations. Six other kernels: educational examples.','note':'State dimensions: GEMM 4x4, stencil 5x5 with 3x3 filter, prefix eight values, FIR eight taps. All pairs have identical interface and data types. This is not untouched MachSuite coverage.'},
    {'title':'Proofs, witnesses and independent execution','stats':[('8 / 8','optimized pairs proved'),('8 / 8','seeded faults rejected'),('2,112','compiled-C tests'),('256','RTL simulation calls')],'code':'Rare-input mutation: wrong only at x = 0xdeadbeef\n10,000 random trials: no mismatch\nZ3 witness: 3735928559\nCompiled-C replay: mismatch confirmed','foot':'Seeded mutations demonstrate checker behavior; they do not estimate an LLM bug rate.','note':'Each of the eight fault witnesses was independently compiled and the full concrete outputs matched the solver report. The rare example is a deliberately controlled illustration, not a statistical experiment.'},
    {'title':'Measured QoR: fewer operations does not guarantee a win','chart':'qor_ratios.png','foot':'Candidate / original; below 1 is better. Same 10 ns clock. Two candidates improve area x latency.','note':'Walk through prefix and FIR on the left of one, then scale, GEMM and boxfilter on the right. Stencil and boxfilter have lower cycle counts but greater area. Do not average these tiny heterogeneous benchmarks into an LLM success rate.'},
    {'title':'Prefix reuse gives a clear hardware improvement','chart':'prefix_gain.png','bullets':['Area: 1,857.48 -> 913.18 um²; 50.8% lower.','Latency: 62 -> 26 cycles; 58.1% lower.','Delay: 1.901 -> 1.510 ns; ADP ratio 0.206.'],'foot':'Complete unsigned-domain proof; mapped pre-layout estimates, Nangate45 typical.','note':'Explain 36 repeated prefix reads/additions versus eight running-sum updates. At 10 ns the function latency changes from 620 to 260 ns. The timing estimate is separate from the target clock used to calculate latency.'},
    {'title':'Keep the trade-offs and regressions in the report','table':[['Candidate','Area change','Cycle change','Interpretation'],['FIR',percent(f['ratios']['area_um2']),'0.0%','Smaller; slightly higher delay'],['Stencil',percent(BY_NAME['stencil']['ratios']['area_um2']),percent(BY_NAME['stencil']['ratios']['cycles']),'Latency / area trade-off'],['Boxfilter',percent(BY_NAME['boxfilter']['ratios']['area_um2']),percent(BY_NAME['boxfilter']['ratios']['cycles']),'Buffer hardware is costly'],['GEMM',percent(BY_NAME['gemm']['ratios']['area_um2']),percent(BY_NAME['gemm']['ratios']['cycles']),'Memory traffic likely hurts'],['Factoring','0.0%','0.0%','Compiler already does it']],'foot':'ADP policy selects prefix and FIR. A latency-first policy can make different choices.','note':'GEMM causality is an interpretation, not a measured isolated ablation. A better future rewrite could use local accumulators. These findings show the need for actual HLS feedback rather than source-level intuition.'},
    {'title':'Cross-checks support confidence; public coverage is limited','bullets':['ESBMC/Z3: 7 of 8 initial pairs resolved; all seven agree. GEMM equivalence timed out.','PAST: accepted unrolling, GEMM and stencil; tested strength reduction was not proved.','EqBench: 246 complete source pairs; 14 compatible with the adapter.','Those 14: 2 proofs, 9 incomplete unwinds, 3 unknown. No added preconditions.'],'foot':'Not a verifier ranking, and not 100% accuracy on EqBench. All public pairs used ESBMC fallback.','note':'Different input formats, instrumentation and proof methods mean raw timing comparisons are not a fair competition. Report inconclusive outcomes and exclusions, not just successful cases.'},
    {'title':'Live demonstration: proof, fault and measured hardware','code':r'.\.venv\Scripts\python.exe scripts/demo.py'+'\n\n'+r'.\.venv\Scripts\python.exe run_submission.py --tests'+'\n\n'+r'.\.venv\Scripts\python.exe run_submission.py --synthesize --force-hls','bullets':['First command: live prefix proof and counterexample; recorded QoR is labeled.','Second: rerun formal checks, native checks and tests.','Third: regenerate the actual hardware results in WSL.'],'note':'Run scripts/demo.py in the terminal. Show the two prefix statuses and the rare input. Then open results/submission/HLS_RESULTS.md and one raw RTL or synthesis log. The hardware synthesis is a separate actual run, not simulated by the demo.'},
    {'title':'Know the limits of the result','bullets':['Restricted C subset; no general pointer, alias, floating-point or invariant support.','Small adapted kernels, one clock/configuration and one library corner.','Pre-layout cell area and ideal-wire timing; external host/memory excluded.','RTL simulation is finite; C-to-C proof does not prove the HLS compiler.','Single assistant-session candidate generation; no multi-model statistics.'],'foot':'Next steps: symbolic memory, loop invariants, larger workloads and controlled LLM repair experiments.','note':'Acknowledge that the interpreter is tested, not formally proved correct. Replaying solver witnesses and cross-checking existing tools validates aspects of the implementation but is not a proof of the verifier.'},
    {'title':'The project demonstrates a complete course workflow','lead':'LLM proposes. Formal checking validates. Synthesis decides.','bullets':['An executable C-to-C checker with explicit semantic limits.','Universal subset proofs plus concrete, independently replayed failures.','Measured hardware gains, trade-offs and regressions retained together.','Sources, queries, raw logs, report and a reproducible demo are included.'],'note':'End on the central outcome: source correctness and hardware benefit are different questions. Prefix is the strongest positive result; keeping the regressions makes the evaluation useful and honest.'},
    {'title':'Primary references and implementations','table':[['Reference','Link / identifier'],['Dahiya & Bansal, APLAS 2017','cse.iitd.ac.in/~sbansal/pubs/aplas17.pdf'],['Pouchet et al., FPGA 2024','doi:10.1145/3626202.3637563'],['Alive2, PLDI 2021','doi:10.1145/3453483.3454030'],['HLSPilot / HLS-Eval','arXiv:2408.06810 / arXiv:2504.12268'],['Implementations / benchmarks','ESBMC, PAST, Bambu, Yosys, OpenSTA, MachSuite, EqBench']],'foot':'Full references, snapshots and licenses are in the report and resource manifest.','note':'Use this slide for questions about related work and code reuse. The custom interpreter is separate from upstream binaries. MachSuite-derived sources retain their license.'},
    ]


def deck_html(slides):
    sections=[]
    notes=['# Presentation notes and viva preparation','','Suggested duration: 12-15 minutes. All slide numbers below refer to the offline deck.','']
    for i,s in enumerate(slides,1):
        chunks=[f'<section class="slide" id="s{i}"><div class="content"><div class="eyebrow">{html.escape(s.get("tag","CS5291 / FORMAL VALIDATION + HLS"))}</div><h1>{html.escape(s["title"])}</h1>']
        if s.get('lead'):chunks.append('<p class="lead">'+html.escape(s['lead'])+'</p>')
        if s.get('stats'):chunks.append('<div class="stats">'+''.join('<div><strong>'+a+'</strong><span>'+b+'</span></div>' for a,b in s['stats'])+'</div>')
        if s.get('flow'):chunks.append('<div class="flow">'+''.join('<div>'+html.escape(x)+'</div>' for x in s['flow'])+'</div>')
        if s.get('chart'):chunks.append('<img class="chart" src="../figures/'+s['chart']+'" alt="Measured '+s['chart'].replace('_',' ')+'"/>')
        if s.get('table'):
            chunks.append('<table>'+''.join('<tr>'+''.join(('<th>' if j==0 else '<td>')+html.escape(str(x))+('</th>' if j==0 else '</td>') for x in r)+'</tr>' for j,r in enumerate(s['table']))+'</table>')
        if s.get('code'):chunks.append('<pre>'+html.escape(s['code'])+'</pre>')
        if s.get('bullets'):chunks.append('<ul>'+''.join('<li>'+html.escape(x)+'</li>' for x in s['bullets'])+'</ul>')
        if s.get('foot'):chunks.append('<p class="footnote">'+html.escape(s['foot'])+'</p>')
        chunks.append(f'</div><footer><span>Project 3 | 22 November 2026</span><span>{i:02d} / {len(slides):02d}</span></footer></section>')
        sections.append(''.join(chunks))
        notes += [f'## Slide {i}: {s["title"]}','',s['note'],'']
    style='''
*{box-sizing:border-box}html,body{margin:0;background:#dce4e9;color:#142b43;font-family:Arial,Helvetica,sans-serif}
.slide{width:1280px;min-height:720px;height:720px;background:white;margin:25px auto;padding:44px 60px 60px;position:relative;overflow:hidden;box-shadow:0 4px 22px #142b4320}
.eyebrow{font-size:13px;letter-spacing:2px;color:#0c7a68;font-weight:700;margin-bottom:17px}h1{font-size:39px;line-height:1.13;max-width:1140px;margin:0 0 28px;letter-spacing:-.7px}
.lead{font-size:29px;line-height:1.35;max-width:1050px;margin:26px 0 32px;color:#206d9e}ul{padding-left:28px;margin:20px 0}li{font-size:23px;line-height:1.43;margin:13px 0;max-width:1090px}table{border-collapse:collapse;width:100%;font-size:21px;line-height:1.3;margin:12px 0 20px}th{text-align:left;background:#142b43;color:white;padding:13px 16px;font-size:18px}td{padding:13px 16px;border-bottom:1px solid #dce4e9;vertical-align:top}tr:nth-child(even){background:#f2f5f7}pre{font-family:Consolas,'DejaVu Sans Mono',monospace;font-size:20px;line-height:1.48;padding:20px 24px;background:#f2f5f7;white-space:pre-wrap;margin:14px 0 18px}.footnote{font-size:16px;line-height:1.35;color:#536477;margin-top:18px}footer{position:absolute;left:60px;right:60px;bottom:24px;display:flex;justify-content:space-between;border-top:1px solid #cbd7df;padding-top:12px;font-size:12px;color:#536477}.chart{display:block;max-width:100%;height:415px;object-fit:contain;margin:0 auto}.chart+ul{display:flex;gap:28px;padding-left:0;list-style:none;margin:8px 0}.chart+ul li{font-size:19px;flex:1}.chart:has(+ul){height:310px}.stats{display:flex;gap:35px;padding:15px 0}.stats div{flex:1;border-top:3px solid #0c7a68;padding-top:17px}.stats strong{font-size:42px;display:block;color:#0c7a68}.stats span{font-size:18px;display:block;margin-top:8px}.flow{display:grid;grid-template-columns:repeat(3,1fr);gap:22px;margin-bottom:25px}.flow div{font-size:20px;border:1px solid #bdced8;padding:19px;background:#f2f5f7;counter-increment:steps}.flow div:before{content:counter(steps) '. ';color:#0c7a68;font-weight:bold}.flow{counter-reset:steps}
#controls{position:fixed;right:15px;bottom:10px;z-index:10;background:#142b43e8;color:white;padding:8px 13px;border-radius:4px;font-size:12px}button{border:0;background:transparent;color:white;font-size:15px;padding:4px 8px;cursor:pointer}
.content{transform-origin:top left}
body.presenting{background:#142b43;overflow:hidden}body.presenting .slide{display:none;margin:0;position:absolute;left:50%;top:50%;transform:translate(-50%,-50%) scale(var(--scale));box-shadow:none}body.presenting .slide.active{display:block}
@media print{@page{size:338.67mm 190.5mm;margin:0}html,body,body.presenting{background:white;overflow:visible}.slide,body.presenting .slide{display:block;margin:0;position:relative;left:auto;top:auto;transform:none;box-shadow:none;page-break-after:always;break-inside:avoid;width:1280px;height:720px}#controls{display:none}}
'''
    script='''
let current=0;const slides=[...document.querySelectorAll('.slide')];
function fitContent(slide){const content=slide.querySelector('.content');content.style.transform='none';if(content.scrollHeight>606)content.style.transform='scale('+(606/content.scrollHeight)+')';}
function fit(){document.documentElement.style.setProperty('--scale',Math.min(innerWidth/1280,innerHeight/720));slides.filter(s=>s.offsetHeight).forEach(fitContent);}
function show(n){current=Math.max(0,Math.min(slides.length-1,n));slides.forEach((s,i)=>s.classList.toggle('active',i===current));document.querySelector('#page').textContent=(current+1)+' / '+slides.length;location.hash='s'+(current+1);fit();}
function present(){document.body.classList.toggle('presenting');fit();show(current);}
document.addEventListener('keydown',e=>{if(['ArrowRight','PageDown',' '].includes(e.key)){e.preventDefault();show(current+1)}else if(['ArrowLeft','PageUp'].includes(e.key)){e.preventDefault();show(current-1)}else if(e.key==='Home')show(0);else if(e.key==='End')show(slides.length-1);else if(e.key.toLowerCase()==='p')present();});
let restorePresenting=false;addEventListener('beforeprint',()=>{restorePresenting=document.body.classList.contains('presenting');document.body.classList.remove('presenting');fit();});addEventListener('afterprint',()=>{if(restorePresenting)document.body.classList.add('presenting');fit();});
addEventListener('resize',fit);addEventListener('load',fit);const n=parseInt(location.hash.slice(2));if(n)current=n-1;present();
'''
    content='<!DOCTYPE html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>Project 3 - Formal Equivalence of LLM HLS Optimizations</title><style>'+style+'</style></head><body>'+''.join(sections)+'<div id="controls"><button onclick="show(current-1)" aria-label="Previous slide">←</button><span id="page"></span><button onclick="show(current+1)" aria-label="Next slide">→</button><button onclick="present()">P: view</button><button onclick="print()">Print</button></div><script>'+script+'</script></body></html>'
    (DECK/'project3_slides.html').write_text(content,encoding='utf-8')
    (ROOT/'docs/PRESENTATION_NOTES.md').write_text('\n'.join(notes)+viva_notes(),encoding='utf-8')


def viva_notes():
    return '''
## Likely viva questions

**What is new in your project?** We combine established symbolic propagation,
complete finite loop expansion and SMT bit-vector mismatch checking in our own
small checker, with an attributed ESBMC fallback and actual HLS evaluation. This
is a course-level implementation and empirical contribution, not a new general
verification algorithm.

**Why uint32_t?** It gives defined modulo-2^32 arithmetic suitable for bit-vector
reasoning and many hardware datapaths. We explicitly adapted the references;
we do not claim to have proved equivalence to their floating or signed versions.

**Does UNSAT prove equivalence for all C?** No. It proves no mismatch in the
modeled subset and domain, with valid disjoint arrays and complete finite
execution. Unsupported syntax, solver unknown and incomplete unwinding are
separate outcomes.

**How is this different from testing?** Testing tries finitely many concrete
inputs. The mismatch formula represents every admitted 32-bit input. The
controlled rare-input mutation shows a bug missed by 10,000 trials but exposed
by a concrete solver witness.

**What exactly is observable?** The return and every element of every parameter
array at function completion, including original input arrays and untouched
boundaries. Temporary variables and intermediate cycle values need not match.

**Why keep ESBMC and PAST?** ESBMC supplies a mature broader C frontend with the
required SMT backend; PAST is an independently invoked implementation from the
closest HLS-source paper. They provide references and cross-checks, not proof
that our interpreter is itself correct.

**Why not Vitis?** It was unavailable. The project document also permits Bambu.
We measured actual Bambu RTL and mapped standard-cell area/timing with open
tools; we do not invent FPGA LUT, DSP or BRAM counts.

**How are delay and latency different?** Delay is the constrained max-path
period estimate from OpenSTA. Function latency is the number of RTL cycles
times the common 10 ns clock. We do not multiply each cycle count by its own
best-case period while claiming a fixed-clock comparison.

**Why does GEMM get worse?** The candidate updates output memory inside the
interchanged loops; additional memory traffic is a plausible explanation.
That explanation is not an isolated causal experiment. A local-accumulator
rewrite is a useful future candidate.

**Does the source proof certify generated RTL?** No. RTL simulation checks the
generated hardware on finite test calls. The formal guarantee in this project
is C-to-C, as required by Project 3.

**What are the proof files?** SMT-LIB mismatch queries plus solver verdicts and
source hashes. UNSAT is the solver result; these are not independently checked
proof certificates.

**Why so few public-data proofs?** EqBench contains richer signed code and
general loops. Only fourteen pairs pass the current adapter's restrictions;
twelve remain inconclusive. We report that coverage instead of presenting the
two correct proofs as 100% dataset accuracy.

## A safe 3-minute live demo

1. Open this directory in PowerShell and run the command on slide 13.
2. Show the live prefix equivalent verdict and the faulty version's witness.
3. Show the rare-input witness 0xdeadbeef.
4. Open results/submission/HLS_RESULTS.md; distinguish recorded hardware data
   from the live proof computation.
5. If asked, open results/hls/prefix_optimized/sta.log and yosys.log.
6. Use --backend auto on the symbolic-index pair only if time permits.
'''


def slides_pdf(slides):
    from reportlab.pdfgen import canvas
    width,height=960,540
    c=canvas.Canvas(str(PDFS/'Project3_Slides.pdf'),pagesize=(width,height))
    c.setTitle('CS5291 Project 3 - Presentation')
    def text(value,x,y,size=17,bold=False,maxwidth=860,leading=None,color=NAVY):
        font='BodyBold' if bold else 'Body'
        c.setFont(font,size);c.setFillColor(colors.HexColor(color))
        leading=leading or size*1.4
        for raw in value.split('\n'):
            words=raw.split(' ');line=''
            for word in words:
                test=(line+' '+word).strip()
                if pdfmetrics.stringWidth(test,font,size)>maxwidth and line:
                    c.drawString(x,y,line);y-=leading;line=word
                else:line=test
            c.drawString(x,y,line);y-=leading
        return y
    for i,s in enumerate(slides,1):
        c.setFillColor(colors.white);c.rect(0,0,width,height,fill=1,stroke=0)
        text(s.get('tag','CS5291 / FORMAL VALIDATION + HLS'),45,508,9,True,color=TEAL)
        y=text(s['title'],45,478,26,True,maxwidth=870,leading=30)-14
        if s.get('lead'):y=text(s['lead'],45,y,21,maxwidth=865,color=BLUE)-12
        if s.get('stats'):
            for j,(a,b) in enumerate(s['stats']):
                x=45+j*225;text(a,x,y,29,True,color=TEAL);text(b,x,y-30,12,maxwidth=200)
            y-=86
        if s.get('flow'):
            for j,value in enumerate(s['flow']):
                x=45+(j%3)*295;yy=y-(j//3)*57
                text(str(j+1)+'. '+value,x,yy,14,True,maxwidth=275)
            y-=126
        if s.get('chart'):
            image=ImageReader(str(FIGURES/s['chart']));iw,ih=image.getSize();draw_h=240 if s.get('bullets') else 310;draw_w=min(855,draw_h*iw/ih);draw_h=draw_w*ih/iw
            c.drawImage(image,45+(870-draw_w)/2,y-draw_h,width=draw_w,height=draw_h);y-=draw_h+10
        if s.get('table'):
            rows=s['table'];cols=len(rows[0]);colw=870/cols
            body=ParagraphStyle('SlideCell',fontName='Body',fontSize=13.2 if cols<=2 else 12,leading=18 if cols<=2 else 16,textColor=colors.HexColor(NAVY))
            head=ParagraphStyle('SlideHead',parent=body,fontName='BodyBold',textColor=colors.white)
            data=[[Paragraph(html.escape(str(x)),head if k==0 else body) for x in row] for k,row in enumerate(rows)]
            table=Table(data,colWidths=[colw]*cols)
            table.setStyle(TableStyle([('BACKGROUND',(0,0),(-1,0),colors.HexColor(NAVY)),('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.HexColor('#f2f5f7'),colors.white]),('VALIGN',(0,0),(-1,-1),'TOP'),('TOPPADDING',(0,0),(-1,-1),9),('BOTTOMPADDING',(0,0),(-1,-1),9),('LEFTPADDING',(0,0),(-1,-1),11),('RIGHTPADDING',(0,0),(-1,-1),11)]))
            tw,th=table.wrap(870,400);table.drawOn(c,45,y-th);y-=th+14
        if s.get('code'):
            font='Mono';fs=14 if len(s['code'].splitlines())>5 else 14.5;lines=s['code'].splitlines();boxh=len(lines)*20+26
            c.setFillColor(colors.HexColor('#f2f5f7'));c.rect(45,y-boxh,870,boxh,fill=1,stroke=0)
            c.setFillColor(colors.HexColor(NAVY));c.setFont(font,fs)
            for k,line in enumerate(lines):c.drawString(62,y-22-k*20,line)
            y-=boxh+14
        if s.get('bullets'):
            fs=13.5 if s.get('chart') else 16
            for bullet in s['bullets']:
                y=text('- '+bullet,49,y,fs,maxwidth=850,leading=fs*1.4)-9
        if s.get('foot'):
            # Keep a separate footer zone so notes never collide with charts.
            text(s['foot'],45,58,10.1,maxwidth=870,leading=13,color='#536477')
        c.setStrokeColor(colors.HexColor('#cbd7df'));c.line(45,25,915,25)
        text('CS5291 | Project 3',45,14,8,color='#536477');text(f'{i:02d} / {len(slides):02d}',875,14,8,color='#536477')
        c.showPage()
    c.save()


def main():
    assert SUMMARY['passed'] and HLS['passed']
    if len(CASES)>8:
        from build_expanded_artifacts import build
        return build()
    for path in (FIGURES,PDFS,DECK):path.mkdir(exist_ok=True,parents=True)
    init_fonts();figures();report_pdf(report_pages());slides=slide_content();deck_html(slides);slides_pdf(slides)
    print('Built report, figures,',len(slides),'HTML/PDF slides and presentation notes.')


if __name__=='__main__':
    main()
