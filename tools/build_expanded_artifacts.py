"""Render the full measured cohort with readable tables and plots."""
import json
from pathlib import Path
import math
import re
import sys
import xml.etree.ElementTree as ET

import build_submission_artifacts as core
import matplotlib.pyplot as plt
import numpy as np

ROOT=Path(__file__).resolve().parents[1]
S=core.SUMMARY
C=core.CASES
CAT=json.loads((ROOT/'experiments/catalog.json').read_text())
PROOFS=core.PROOFS['cases']
CHUNK=10
JUNIT=ET.parse(ROOT/'results/hybrid/pytest_all.xml' if (ROOT/'results/hybrid/pytest_all.xml').exists() else ROOT/'results/submission/pytest.xml').getroot()
TEST_SUITE=JUNIT.find('testsuite') if JUNIT.tag=='testsuites' else JUNIT
TEST_COUNT=int(TEST_SUITE.attrib['tests'])
LOCAL=json.loads((ROOT/'results/local_llm/summary.json').read_text())
LOCAL_HLS=json.loads((ROOT/'results/local_llm/hls/summary.json').read_text())
SUBTLE=json.loads((ROOT/'results/subtle_faults/summary.json').read_text())
DATASET_AUDIT=json.loads((ROOT/'results/dataset_audit/inventory.json').read_text())
LEAVES=json.loads((ROOT/'experiments/dataset_leaves/manifest.json').read_text())
HYBRID=json.loads((ROOT/'results/hybrid/study/summary.json').read_text()) if (ROOT/'results/hybrid/study/summary.json').exists() else None
ABLATION=json.loads((ROOT/'results/hybrid/ablation/summary.json').read_text()) if (ROOT/'results/hybrid/ablation/summary.json').exists() else None
LARGE=json.loads((ROOT/'results/large/summary.json').read_text()) if (ROOT/'results/large/summary.json').exists() else None
core.REFERENCES.extend([
    ('Qwen', 'Qwen2.5-Coder-1.5B-Instruct-GGUF official model card and Apache-2.0 license.', 'https://huggingface.co/Qwen/Qwen2.5-Coder-1.5B-Instruct-GGUF'),
    ('ggml-org', 'llama.cpp b12619 runtime release used for local inference.', 'https://github.com/ggml-org/llama.cpp/releases/tag/b12619'),
])


def charts():
    plt.rcParams.update({'font.family':'DejaVu Sans','font.size':10,'axes.spines.top':False,'axes.spines.right':False})
    for start in range(0,len(C),CHUNK):
        rows=C[start:start+CHUNK]
        fig,ax=plt.subplots(figsize=(10.5,4.7),layout='constrained')
        y=np.arange(len(rows))
        for offset,key,label,color,marker in [(-.18,'area_um2','Cell area',core.BLUE,'s'),(0,'cycles','Latency cycles',core.GOLD,'o'),(.18,'area_latency_product_um2_ns','Area x latency',core.TEAL,'D')]:
            ax.scatter([r['ratios'][key] for r in rows],y+offset,color=color,marker=marker,s=35,label=label,zorder=3)
        values=[r['ratios'][k] for r in rows for k in ('area_um2','cycles','area_latency_product_um2_ns')]
        ax.set_xscale('log');ax.set_xlim(min(values)*.55,max(values)*1.6)
        ax.axvline(1,color=core.NAVY,lw=1,ls='--')
        ax.set_yticks(y,[r['case'] for r in rows]);ax.invert_yaxis();ax.grid(axis='x',which='major',alpha=.2)
        ax.set_xlabel('Candidate / original ratio (log scale; lower is better)')
        ax.legend(loc='upper center',bbox_to_anchor=(.5,1.16),ncol=3,frameon=False)
        fig.savefig(core.FIGURES/f'expanded_qor_{start//CHUNK+1}.png',dpi=190,facecolor='white')
        fig.savefig(core.FIGURES/f'expanded_qor_{start//CHUNK+1}.svg');plt.close(fig)
    names=['prefix','parity32','popcount8']
    fig,axes=plt.subplots(1,3,figsize=(10.5,3.0),layout='constrained')
    for ax,name in zip(axes,names):
        r=core.BY_NAME[name]
        ax.bar([-.18,.82],[1,1],width=.34,color=core.BLUE,label='Original')
        bars=ax.bar([.18,1.18],[r['ratios']['area_um2'],r['ratios']['cycles']],width=.34,color=core.TEAL,label='Candidate')
        ax.set_xticks([0,1],['Cell area','Cycles']);ax.set_ylim(0,1.24);ax.set_title(name,fontweight='bold',loc='left')
        ax.bar_label(bars,labels=[f"{r['ratios'][k]:.3f}" for k in ('area_um2','cycles')],padding=3,fontsize=9)
        ax.grid(axis='y',alpha=.15);ax.set_axisbelow(True)
    axes[0].set_ylabel('Ratio to original');axes[2].legend(frameon=False,fontsize=8,loc='upper right')
    fig.savefig(core.FIGURES/'expanded_highlights.png',dpi=190,facecolor='white');fig.savefig(core.FIGURES/'expanded_highlights.svg');plt.close(fig)


def metric_table(rows):
    table=[['Pair','Area: original /\ncandidate (um²)','Delay: original /\ncandidate (ns)','Cycles: original /\ncandidate','ADP\nratio']]
    for r in rows:
        a,b=r['original'],r['optimized']
        table.append([r['case'],f"{a['area_um2']:.2f} / {b['area_um2']:.2f}",f"{a['delay_ns']:.3f} / {b['delay_ns']:.3f}",f"{a['cycles']:g} / {b['cycles']:g}",f"{r['ratios']['area_latency_product_um2_ns']:.4g}"])
    return table


def pages():
    n=S['design_pairs'];q=S['qor_outcomes']
    h=core.BY_NAME['hamming8'];p=core.BY_NAME['prefix'];par=core.BY_NAME['parity32'];pop=core.BY_NAME['popcount8']
    gemm=core.BY_NAME['gemm'];local=core.BY_NAME['gemm_local4']
    tile=core.BY_NAME['gemm_tile2'];window=core.BY_NAME['moving_sum_register16']
    groups=[['Recorded group','Pairs']]+[[key,str(value)] for key,value in S['group_counts'].items()]
    proof_times=[r['verification']['elapsed_seconds'] for r in PROOFS if r['variant']=='optimized']
    replay=json.loads((ROOT/'results/submission/smt_replay.json').read_text())
    accepted=sum(len(r['dependencies']) for r in replay['cases'])
    selected=sorted([r for r in C if r['selected_for_area_latency']=='optimized'],key=lambda r:r['ratios']['area_latency_product_um2_ns'])
    winners=[['Pair','Area ratio','Cycle ratio','ADP ratio']]+[[r['case'],f"{r['ratios']['area_um2']:.4f}",f"{r['ratios']['cycles']:.4f}",f"{r['ratios']['area_latency_product_um2_ns']:.5f}"] for r in selected[:10]]
    result=[
    ('Formal Equivalence Checking of LLM-Optimized HLS Code',[
        ('subtitle','CS5291 | Project 3 | Expanded measured study | 22 November 2026'),
        ('h2','Abstract'),
        ('p',f'The expanded submission records {n} original/candidate C pairs and {2*n} real synthesized implementations. Forty educational additions and two feedback-driven follow-ups extend the initial eight-pair study with reductions, bit manipulation, filters, images, linear algebra and data movement. The custom checker proves every candidate equivalent within its supported unsigned C domain, and rejects every deliberately seeded faulty variant. Exact original/optimized sources, transformation explanations, input hashes, SMT queries, native replay and hardware logs accompany each pair.'),
        ('p',f"The hardware experiment uses Bambu, Verilator, Yosys and OpenSTA with common settings. {q['area_latency_improved']} candidates improve mapped area x latency, {q['area_latency_regressed']} regress it and {q['area_latency_unchanged']} are unchanged within a 0.1% classification tolerance. Independently, {q['area_improved']} reduce area and {q['cycles_improved']} reduce cycle latency. These are descriptive results on selected related educational kernels, not a distributional LLM success rate."),
        ('p','A separate zero-API-charge local Qwen experiment records forty raw attempts: 28 equivalent, eight non-equivalent, two undefined-C and two unresolved. Nine verified changed outputs receive hardware measurements. An 80-case subtle-edit suite and eight type-preserving public-suite leaf functions strengthen the correctness evaluation; Sections 9-12 report these distinct cohorts.'),
        ('image','expanded_highlights.png',165),
        ('p',f"Prefix reuse saves {(1-p['ratios']['area_um2'])*100:.1f}% area and {(1-p['ratios']['cycles'])*100:.1f}% cycles. XOR-fold parity saves {(1-par['ratios']['area_um2'])*100:.1f}% area and changes latency from {par['original']['cycles']:g} to {par['optimized']['cycles']:g} cycles. Byte SWAR population count saves {(1-pop['ratios']['area_um2'])*100:.1f}% area. The bit-permutation cases map mostly to wires and minimal interface logic; their extreme ratios are interpreted separately from arithmetic kernels."),
        ('h2','What was built'),
        ('p','The original implementation combines a restricted-C symbolic interpreter, Z3 modular arithmetic, component lemmas and an attributed ESBMC adapter. The default checker now uses certified relational summaries and counterexample refinement: symbolic proofs simplify the C product verified by ESBMC. Sections 13-14 evaluate that proof-level combination separately. Existing ideas and upstream engines are credited; no first-ever verification algorithm is claimed.'),
        ('small','All proofs are conditional on the supported C semantics and nonaliasing arrays. Hardware values are Nangate45 typical pre-layout estimates, not routed timing or FPGA resource counts.')]),
    ('1. Scope and workload accounting',[
        ('p',f"The study unit is one original/candidate pair. There are {n} pairs, {2*n} hardware implementations and {S['unique_original_c_asts']} distinct original C ASTs after comment/format removal. gemm_local4 and gemm_tile2 reuse the original GEMM reference; moving_sum_register16 reuses the moving-window reference. Min/max, population-count, reduction and data-movement variants also share algorithmic ideas. The study therefore does not claim {n} independent applications or unmodified public-suite benchmarks."),
        ('table',groups,[2.2,1]),
        ('p','The original GEMM and stencil references are reduced uint32_t adaptations of downloaded MachSuite algorithms. The second GEMM candidate uses the same adapted reference and preserves its BSD-style license. Remaining additions are independently authored educational implementations selected for the explicit checker subset. Types and dimensions are identical within each pair; upstream floating/signed semantics are not claimed.'),
        ('h2','Recorded LLM work'),
        ('p','The Codex assistant authored the source rewrites in this conversation. The generation record states the preservation constraints and exposes all actual C artifacts. No unobserved model ID, temperature, response identifier or token count is invented. tools/expand_benchmarks.py materializes the forty additional source definitions; it is not an external LLM sampling experiment.'),
        ('p','Every per-pair dossier in experiments/optimizations includes the exact original and optimized C, the transformation, expected hardware motivation, source hashes, proof and query links, negative control, actual metrics and the objective-specific acceptance decision.')]),
    ('2. Checker semantics and compositional proofs',[
        ('code','Common initial inputs + reachable final path pair\n+ different return / final parameter-array contents\n    SAT -> concrete mismatch\n    UNSAT -> equivalence in the modeled domain'),
        ('p','The custom interpreter models uint32_t arithmetic as 32-bit modular bit-vectors, concrete signed loop counters, fixed-size one-dimensional arrays, symbolic predicates and early returns. Supported loops are expanded completely; symbolic indices, unrestricted pointers, calls, globals, persistent state, floating point and general symbolic signed arithmetic are rejected. All arrays are valid and disjoint; every final parameter-array element is observable.'),
        ('p','Both source programs must be free of modeled undefined behavior throughout the admitted input domain. Zero divisors, invalid shifts and out-of-bounds accesses are separate outcomes. Budget exhaustion and solver unknown do not become equivalence claims. This is a stricter contract than source-defined-subset compiler refinement.'),
        ('h2','New proof acceleration in the expanded study'),
        ('p','Z3 first normalizes modular polynomial output differences. When an additive expression separates into terms with disjoint symbolic-variable dependencies, the checker tries unconditional zero-component queries. Only an UNSAT component query permits removing that component. SAT, timeout or unknown components remain in the final mismatch query. Independence is a grouping heuristic; acceptance rests on exact additive decomposition and universally proved-zero components.'),
        ('p','The eight-byte Hamming reduction initially reached a 30 s monolithic timeout. Its source, query, hashes and unknown verdict remain under experiments/attempts/hamming8_monolithic. The enhanced checker proves eight byte-level component lemmas and then the remaining aggregate query. Every accepted lemma is exported; the final SMT file identifies its dependencies. A final simplified query alone is not the full evidence chain.'),
        ('p','The historical ESBMC/Z3 adapter and PAST experiments remain reproducible. The new default integrates symbolic region proofs with residual C verification and refinement; see Sections 13-14. Bounds, safety and unwinding checks remain enabled. Upstream engines are attributed.')]),
    ('3. Experimental protocol and validation',[
        ('table',[['Stage','Recorded method'],['Formal checking',f'{n} optimized pairs + {n} seeded controls; complete supported execution, 30 s main solver budget'],['SMT replay',f"{n} unrestricted UNSAT main queries, {accepted} unrestricted component queries, and {n} witness-pinned SAT queries"],['Compiled C',f"{S['native_optimized_trials']:,} original/candidate test trials; {S['native_witnesses_replayed']} concrete witnesses reproduced with exact output agreement"],['RTL simulation',f"{S['rtl_simulation_calls']:,} calls; sixteen per hardware implementation"],['Hardware comparison','Identical types, dimensions, HLS setup, library and 10 ns clock within each pair']], [1,2.8]),
        ('p',f'Each native pair receives eight directed patterns and 256 deterministic xorshift trials, seed 0x5291abcd. These validate executions and witness reporting; testing is not the universal equivalence argument. The unit suite has {TEST_COUNT} passing tests on the measured machine, including polynomial/component-proof regressions and real external-verifier checks.'),
        ('p','The original eight faults include structural/arithmetic mutations. The forty-two additional controls deliberately flip one output bit after computing the candidate result. They validate rejection and replay but are not a challenging independent mutation benchmark, naturally occurring LLM mistakes, or an estimate of an LLM bug rate.'),
        ('h2','Hardware settings'),
        ('p','Bambu 2026.11 revision 6407a63da948c1b2223d63a9e91891a5628fe174-dev/panda, Clang 16, BAMBU-BALANCED-MP (-O2), seed 0, target Nangate45 typical at 10 ns. Verilator 5.020 measures function cycles; Yosys 0.36 maps cells; OpenSTA 2.0.18 performs max-path timing. Source hashes and a configuration fingerprint guard cached results.'),
        ('p','The library is typical 1.1 V, 25 C. Timing uses ideal clocks, zero IO delays, 50 ps input transitions, 10 fF output loads and no extracted wires. Delay is 10 ns minus worst max-path slack. Reported unconstrained endpoints must match constant outputs in the mapped netlist. Cell area includes mapped local memory, excludes external memory/host resources and does not include physical placement/routing overhead.')]),
    ('4. Aggregate QoR and strongest candidates',[
        ('table',[['Metric with at least 0.1% improvement','Pairs'],['Mapped area',str(q['area_improved'])],['Cycle latency',str(q['cycles_improved'])],['STA period estimate',str(q['delay_improved'])],['Area x latency',str(q['area_latency_improved'])],['ADP regressions',str(q['area_latency_regressed'])],['ADP unchanged',str(q['area_latency_unchanged'])]], [2,1]),
        ('table',winners,[1.5,1,1,1]),
        ('p',f'ADP is mapped cell area x cycles x the common 10 ns period. The acceptance policy retains a candidate only if it meets the timing target and improves this product. A latency-first policy can accept an area increase. Full original/candidate values for all {n} pairs appear in the appendix and per-pair dossiers.'),
        ('p','Bit reversal and byte swapping expose constant bit permutations, so their optimized datapaths largely collapse to wiring plus minimal interface logic in this model. Their extreme relative gains describe removal of a serial loop controller in a microkernel. They are not evidence of similar reductions in a large accelerator or realistic physical IO cost. No mean ratio is used to let those tiny cases dominate a headline result.')]),
    ('5. Follow-up optimization and trade-offs',[
        ('h2','GEMM: retain the earlier regression, test a new candidate'),
        ('p','The first GEMM interchange repeatedly updates output memory. Follow-ups keep four or two output accumulators local, reusing row inputs and writing each product once. These are three candidates against the same original algorithm, not independent applications.'),
        ('table',[['GEMM implementation','Area (um²)','Cycles','ADP ratio'],['Original',f"{gemm['original']['area_um2']:.2f}",f"{gemm['original']['cycles']:g}",'1'],*[[r['case'],f"{r['optimized']['area_um2']:.2f}",f"{r['optimized']['cycles']:g}",f"{r['ratios']['area_latency_product_um2_ns']:.4g}"] for r in (gemm,local,tile)]],[1.6,1,1,1]),
        ('h2','Moving window: follow the memory-traffic feedback'),
        ('p',f"The register-window follow-up keeps four samples locally and loads one new value per output. Against the repeated-window reference it measures {window['original']['cycles']:g} to {window['optimized']['cycles']:g} cycles, area ratio {window['ratios']['area_um2']:.3f} and ADP ratio {window['ratios']['area_latency_product_um2_ns']:.3f}. The earlier sliding recurrence and its area regression remain in the data."),
        ('h2','Useful gains beyond the initial cohort'),
        ('p',f"parity32 changes {par['original']['cycles']:g} to {par['optimized']['cycles']:g} cycles and {par['original']['area_um2']:.3f} to {par['optimized']['area_um2']:.3f} um². popcount8 changes {pop['original']['cycles']:g} to {pop['optimized']['cycles']:g} cycles and {pop['original']['area_um2']:.3f} to {pop['optimized']['area_um2']:.3f} um². Both are fully checked over every 32-bit input; popcount8 explicitly observes only the low byte in both sources."),
        ('p',f"The Hamming candidate replaces nested bit scans with SWAR byte operations. It measures {h['original']['cycles']:g} to {h['optimized']['cycles']:g} cycles and area ratio {h['ratios']['area_um2']:.3f}. Its equivalence relies on the separately recorded byte lemmas, not finite tests alone."),
        ('h2','Why correct candidates can regress'),
        ('p','Independent accumulators, source unrolling and balanced comparison trees can expose more hardware while the external-memory interface limits throughput. Buffering can cost more mapped registers/muxes than the saved arithmetic on small dimensions. The full data retains these outcomes. Where an explanation has not been isolated by an ablation, it is an interpretation of the source/generated structure, not a demonstrated causal claim.'),
        ('p','Cases such as factoring and coefficient rewriting may also converge to compiler-identical hardware. These controls are useful evidence that a shorter source expression does not guarantee benefit beyond the existing compiler passes.')]),
    ('6. Formal results, references and public-data limits',[
        ('p',f"All {n} optimized pairs are equivalent in the modeled domain, and all {n} seeded controls are not_equivalent with compiled witness agreement. Positive custom-checker runtimes range from {min(proof_times)*1000:.1f} to {max(proof_times)*1000:.1f} ms in the recorded run. The range is descriptive for these chosen small cases, not a scalability claim. The retained monolithic Hamming timeout is excluded from the final successful run but explicitly documented as an earlier inconclusive attempt."),
        ('p',f"All {n} UNSAT final queries and {accepted} accepted component queries replay unrestricted. The {n} SAT queries replay at their recorded input counterexamples, proving the witnesses satisfy the mismatch formula without repeating nonlinear model search. Earlier unconstrained SAT-replay budget failures are retained under experiments/attempts/sat_replay_budget. This uses the same Z3 implementation, not independent proof-certificate checking. The interpreter itself is experimental tested software, not a formally verified C frontend."),
        ('table',[['Existing comparison','Actual scope'],['ESBMC + Z3','Initial eight pairs: seven conclusive agreements, one GEMM timeout'],['PAST release','Annotated-region initial examples; accepted unrolling/GEMM/stencil, did not prove tested strength reduction'],['EqBench','246 complete C pairs in pinned tree; fourteen adapter-compatible pairs evaluated'],['EqBench results','Two equivalent, nine incomplete_unwind, three unknown; no added ranges']], [1,2.6]),
        ('p','The initial ESBMC/PAST comparison has not been expanded to a full-cohort tool competition. The public EqBench run uses the ESBMC fallback for signed interfaces. It does not establish signed support in our custom interpreter or 100% dataset accuracy. Most public source pairs remain outside the adapter subset.'),
        ('p','The key references are black-box equivalence checking [1], HLS source verification / PAST [2,8], Alive2 [3], LLM HLS workflows [4,5], and equivalence-to-verification reduction [6,7]. The contribution is an implementation and measured integration of established ideas.')]),
    ('7. Reproduction and artifact map',[
        ('code',r'.\.venv\Scripts\python.exe scripts/demo.py'+'\n'+r'.\.venv\Scripts\python.exe run_submission.py --tests'+'\n'+r'.\.venv\Scripts\python.exe run_submission.py --synthesize --tests --jobs 3'),
        ('p','The first command is a short live proof demonstration with clearly labeled recorded hardware data. The second rechecks/replays all current proof evidence and reruns native tests. The third also performs hardware runs, using exact-source/configuration caches; add --force-hls to regenerate every implementation. Large HLS tools remain installed under the WSL home directory; no Vitis license is needed.'),
        ('table',[['Artifact','Location'],[f'{n} source pairs and seeded controls','benchmarks/; experiments/catalog.json'],['Before/after code and transformation dossiers','experiments/OPTIMIZATION_CATALOG.md; experiments/optimizations/'],['Proofs, dependencies and witnesses','results/submission_verification/; results/submission/smt_replay.json'],['Native execution and replay','results/native/'],[f'{2*n} RTL / mapping / timing runs','results/hls/'],['Full QoR table and acceptance decisions','results/submission/'],['Retained inconclusive attempt','experiments/attempts/hamming8_monolithic/'],['Presentation / report / source package','output/']], [1.3,2.3]),
        ('p','The portable ZIP includes code, result evidence, report, slides, licensed input library and a file-hash manifest. Upstream binary archives, repository clones, research PDFs, virtual environments and temporary builds are excluded. The package smoke test replays proofs and dependencies from extracted files.')]),
    ('8. Limitations and next steps',[
        ('p','The proof domain remains restricted to explicitly modeled C. There is no general alias analysis, arbitrary pointer memory model, recursive call support, floating-point semantics or invariant inference for unbounded/input-dependent loops. Component lemmas speed one algebraic pattern but do not solve arbitrary relational loop reasoning. Failures and unknowns remain possible.'),
        ('p','The main 50 pairs were deliberately selected/constructed to fit this domain, and several share algorithms. This is not an independently sampled benchmark of LLM competence. Their original seeded controls include simple output-bit mutations. Sections 9-12 add a separately logged 40-attempt local-model experiment, diverse subtle edits and type-preserving public-suite leaves; these supplementary cohorts remain separate.'),
        ('p','Hardware results use small fixed dimensions, one library corner and one target clock. They include mapped interface/local-memory costs but omit external host/memory and physical wiring/placement. Tiny bit-permutation implementations can appear almost free in this model. These observations do not predict whole-system FPGA or ASIC performance.'),
        ('p','C-to-C equivalence is distinct from proving the HLS compiler correct. Verilator provides finite RTL checks, not a formal C-to-RTL guarantee. SMT replay uses the same solver and is not a separately checked proof certificate. Cross-tool references and compiled-C replay increase confidence without eliminating implementation risk.'),
        ('h2','Next useful experiments'),
        ('p','Scale selected winners to larger dimensions; sweep clock and memory interface settings; compare multiple source candidates per algorithm without counting them as independent workloads; extend symbolic memory and loop reasoning; and run controlled LLM repair trials with exact generation metadata.')])]
    result.extend(supplement_pages())
    if HYBRID and HYBRID['total']==239:
        result.extend(integrated_pages())
    if LARGE and LARGE['total']==29:
        result.extend(large_pages())
    for start in range(0,len(C),CHUNK):
        result.append((f'Appendix A{start//CHUNK+1}. Measured pairs {start+1}-{min(start+CHUNK,len(C))}',[
            ('table',metric_table(C[start:start+CHUNK]),[1.35,1.5,1.2,1,.65]),
            ('image',f'expanded_qor_{start//CHUNK+1}.png',218),
            ('small','Ratios below one improve the metric. ADP uses the same feasible 10 ns clock for both implementations. Log plots retain extreme tiny-logic ratios. Full-precision values, raw files and source hashes are in the JSON evidence.')]))
    result.append(('References',[
        *[('ref',f'[{i}] {authors}. {title}',url) for i,(authors,title,url) in enumerate(core.REFERENCES,1)],
        ('p','The downloaded C2HLSC and ESBMC v7.6 papers remain additional reading. Experiments use the actual released/tool versions in the logs. Project sources and upstream implementation reuse are kept separate; licenses and precise adaptations are recorded in docs/THIRD_PARTY_NOTICES.md and docs/RESOURCE_MANIFEST.md.')]))
    return result


def supplement_pages():
    counts=LOCAL['counts']
    outcomes=[['Raw model outcome','Attempts'],['Equivalent',str(counts['equivalent'])],['Non-equivalent',str(counts['not_equivalent'])],['Candidate undefined C',str(counts['candidate_undefined'])],['Unsupported',str(counts['unsupported'])],['Unknown',str(counts['unknown'])]]
    hardware=[['Attempt','Area ratio','Cycle ratio','Delay ratio','ADP ratio']]
    for row in LOCAL_HLS['cases']:
        r=row['ratios']
        hardware.append([row['id'],*[f'{r[k]:.4f}' for k in ('area_um2','cycles','delay_ns','area_latency_product_um2_ns')]])
    missed=[r for r in SUBTLE['cases'] if r['status']=='not_equivalent' and r['native']['mismatches']==0]
    audit=[['Downloaded suite','Available designs','Raw frontend eligible']]+[[name,str(n),'0'] for name,n in DATASET_AUDIT['design_counts'].items()]
    leaf_table=[['Suite','Extracted function','Input type']]+[[c['suite'],c['function'],', '.join(c['input_kinds'])] for c in LEAVES['cases']]
    return [
        ('9. Genuine local-model optimization attempts',[
            ('p','To collect actual model mistakes without paid API calls, Qwen2.5-Coder-1.5B-Instruct Q4_K_M was run locally using llama.cpp b12619 / Vulkan on an RTX 3050 laptop GPU. Twenty fixed source kernels were sampled at seed 5291 / temperature 0.2 and seed 5292 / temperature 0.8, producing forty raw attempts. The GGUF is 1.04 GiB; the runtime archive is 37.06 MiB. API charges were zero.'),
            ('p','The complete plan and prompts were saved before generation. Every request, raw response JSON, response text, code extraction, model/runtime hash and generation setting is retained. Code-fence extraction made no semantic repairs. There was no verifier feedback, regeneration or selective discarding; all forty responses ended normally.'),
            ('table',outcomes,[2.5,1]),
            ('p','Nineteen outputs are unchanged after AST normalization. Nine AST-changing outputs proved equivalent. Six genuine mismatches were found by the custom backend and replayed at the exact SMT inputs with matching compiled-C outputs. Two more required ESBMC fallback and were independently exposed by native testing. All 36 conclusive safe pairs passed 264 native trials each; all 34 available custom SMT queries replayed.'),
            ('p','Observed mistakes include wrong FIR coefficients, replacing absolute difference with XOR, changing matrix index orientation, incorrect population-count/bit-reversal shifts and a wrong convolution window. Two unsafe candidates use a 32-bit shift by 32 and out-of-bounds histogram reads. Unsafe candidates are reported separately and were not executed natively.'),
            ('small','This is a case study of one selected small quantized model, not a general LLM error rate. Seed and temperature change together; no causal temperature comparison is claimed. Full ledger: results/local_llm/REPORT.md.')]),
        ('10. Hardware results for the local-model rewrites',[
            ('p','All nine AST-changing proved-equivalent outputs were synthesized, with no selection by favorable hardware results. Sixteen RTL calls per candidate add 144 calls to the evidence. Original hardware runs are reused only when original-source and configuration hashes match. The baseline clock, library, HLS compiler and mapping/timing settings match the main cohort.'),
            ('table',hardware,[1.9,.85,.85,.85,.85]),
            ('p','Three attempts improve area x latency, five are unchanged within 0.1% and one regresses. The two triangular-matvec candidates share one original, so three successful attempts represent two algorithms. AST-level changes often compile into the same hardware; an equivalence verdict is not evidence of QoR improvement.'),
            ('p','The local prefix candidate changes 62 to 40 cycles and reduces area by 15.6%; its critical-path estimate increases. Both triangular-matvec candidates change 62 to 24 cycles at roughly 7.8% higher area. The verified box-filter rewrite increases both area and latency and is rejected by the ADP policy.'),
            ('p','Keep these outcomes separate from the curated 50-pair cohort. There are 109 actual synthesized implementations in total: 100 main-cohort implementations plus nine local-model outputs. Existing baselines are not counted again. These remain pre-layout ASIC estimates, not placed/routed silicon or FPGA resource counts.'),
            ('small','Raw source-to-proof bindings, testbenches, RTL, mapping/timing logs and full-precision metrics: results/local_llm/hls/.')]),
        ('11. Subtle faults and equivalent-edit controls',[
            ('p','The original output-bit controls are supplemented by 50 token-scale edits to already-proved candidates and four semantic pitfalls. Expected labels were declared before checking. These are deliberately injected errors, distinct from the actual local-model mistakes. Edits affect thresholds, indices, masks, coefficients, recurrences, diagonal handling and window reuse.'),
            ('table',[['Expected category','Cases','Observed'],['Safe non-equivalent','54','54 rejected'],['Equivalent semantic edits','20','20 proved'],['Undefined candidate C','6','6 separately identified']],[2,1,1.5]),
            ('p','All 54 safe mismatches have compiled-C replay at the exact solver input with exact output agreement. All available proof queries and accepted dependencies replay. Equivalent edits test tie comparisons, unsigned modular identities, valid strength reductions and guarded division. These controls protect against a checker that rejects every syntactic change.'),
            ('h2','Bugs missed by the conventional test set'),
            ('table',[['Case','Small edit']]+[[r['id'],r['rationale']] for r in missed],[1.3,3]),
            ('p','Each listed faulty pair passes all eight conventional edge patterns and 256 deterministic random trials, yet SMT finds a counterexample reproduced in native C. This demonstrates a concrete coverage gap for that fixed test set. A tailored directed test can expose some of these faults; for example threshold 128 finds the threshold-boundary error.'),
            ('small','Exact diffs and rationale: experiments/subtle_faults/. Full results, witnesses and native logs: results/subtle_faults/REPORT.md.')]),
        ('12. Downloaded datasets and type-preserving reuse',[
            ('p','The downloaded suites supply HLS workloads and testbenches, not labeled C-to-C equivalence pairs. The inventory selects designs, excluding testbench files and repository test fixtures. Raw frontend eligibility was audited without changing types or dimensions; rejected preprocessing/headers/interfaces are coverage exclusions, not incorrect-program verdicts.'),
            ('table',audit,[1.3,1.5,1.6]),
            ('table',leaf_table,[1,2,1.5]),
            ('p','The eight leaf functions retain exact upstream function text and required types/macros. Reused ESBMC 8.7 / Z3 proves eight assistant-authored candidates equivalent and rejects eight seeded bugs over full typed input domains. Unconstrained unsigned-long-long inputs preserve all 64 bits. Static assertions enforce short16/int32/long32/long-long64; native Windows and the ESBMC target agree on these integer widths.'),
            ('p','Independent native tests cover 96,272 inputs, including exhaustive signed-16 GSM absolute value and all 256 byte inputs for AES xtime. For gsm_abs(-32768), removing saturation changes 32767 into -32768 on the stated implementation. The 64-bit HLS-Eval functions manipulate binary64 bit patterns, not general floating-point operations.'),
            ('small','These are isolated leaves verified through a separate reused-backend miter, not full application proofs or new signed/64-bit support in the custom interpreter. No extra hardware results are claimed for the leaves. Provenance, extraction steps, notices and raw logs: results/dataset_audit/REPORT.md; experiments/dataset_leaves/.')])]


def slides():
    n=S['design_pairs'];q=S['qor_outcomes'];base=core.slide_content()
    # Reuse semantic/related-work slides, replacing all initial-cohort counts.
    base[0].update(title=f'Formal checking and HLS optimization across {n} design pairs',lead=f'{n} recorded rewrites. {2*n} synthesized implementations.',bullets=['Every candidate proved within the explicit unsigned C subset.','Exact before/after code, transformation dossiers and solver evidence.','Hardware gains, trade-offs, unchanged cases and regressions retained.'])
    base[1]['table']=[['Requirement','Expanded evidence'],['LLM C-to-C rewrites',f'{n} recorded pairs; related variants identified'],['Area / delay / latency',f'{2*n} Bambu / Verilator / Yosys / OpenSTA implementations'],['SMT-backed checker','Certified relational summaries, C product verification and counterexample refinement']]
    base[6].update(title='Workload accounting stays explicit',table=[['Quantity','Count / scope'],['Original / candidate pairs',str(n)],['Hardware implementations',str(2*n)],['Distinct original C ASTs',str(S['unique_original_c_asts'])],['New pairs since initial cohort',str(n-8)],['Sample type','Selected educational kernels and documented MachSuite adaptations']],foot='Related algorithms and feedback candidates are not independent application samples.')
    base[7].update(stats=[(f'{n} / {n}','candidates proved'),(f'{n} / {n}','seeded controls rejected'),(f"{S['native_optimized_trials']:,}",'compiled-C trials'),(f"{S['rtl_simulation_calls']:,}",'RTL calls')])
    base[8].update(title='Expanded measured outcomes',chart='expanded_highlights.png',foot=f"{q['area_latency_improved']} improve ADP; {q['area_latency_regressed']} regress it; {q['area_latency_unchanged']} unchanged (0.1% tolerance). Related selected kernels; not an LLM success-rate estimate.")
    base[8].pop('chart',None)
    base[8]['table']=[['Outcome (0.1% classification tolerance)','Pairs'],['Lower area',str(q['area_improved'])],['Fewer latency cycles',str(q['cycles_improved'])],['Lower period estimate',str(q['delay_improved'])],['Better area x latency',str(q['area_latency_improved'])],['Worse area x latency',str(q['area_latency_regressed'])],['Unchanged area x latency',str(q['area_latency_unchanged'])]]
    base[8]['foot']='Same target and settings within each pair. Related selected kernels; not an LLM success-rate estimate.'
    base[9].update(title='Three useful wins under the common clock',chart='expanded_highlights.png',bullets=['Prefix: 62 -> 26 cycles; 50.8% smaller area.','Parity: 34 -> 1 cycle; 61.6% smaller area.','Byte popcount: 10 -> 1 cycle; 91.1% smaller area.'],foot='Real pre-layout Nangate45 measurements; universal subset proofs for all three.')
    base[10]['foot']=f"The ADP policy selects {S['selected_optimized']} candidates across the full cohort. A latency-first objective can choose differently."
    local=core.BY_NAME['gemm_local4']
    tile=core.BY_NAME['gemm_tile2']
    base.insert(11,{'title':'GEMM follow-ups: test the area/latency balance','table':[['Candidate against the same original','Cycles','ADP ratio'],['Original baseline','122','1.000'],['First interchange candidate','266','2.303'],['Four local accumulators',f"{local['optimized']['cycles']:g}",f"{local['ratios']['area_latency_product_um2_ns']:.3f}"],['Two-column tile',f"{tile['optimized']['cycles']:g}",f"{tile['ratios']['area_latency_product_um2_ns']:.3f}"]],
        'bullets':['Reuse each m1 row value across four products.','Keep four output accumulators local; write each result once.','Retain the earlier regression and identify the shared original.'],
        'foot':'Every earlier candidate is retained. The ADP policy and a latency-first policy can select different implementations.',
        'note':'This is a measured follow-up candidate, not an extra independently sampled application. Explain the source code and compare both actual measurements.'})
    base.insert(6,{'title':'A compositional check resolves the Hamming timeout','code':'Initial monolithic query: UNKNOWN at 30 s\n\n8 disjoint byte contributions\n  -> 8 universal zero-difference SMT lemmas\n  -> remaining aggregate mismatch query\n  -> UNSAT','bullets':['Only UNSAT components are removed. Unknown/SAT components remain.','Every accepted lemma is exported and replayed with the final query.'],
        'foot':'Standard compositional reasoning implemented as a proof acceleration; no new general algorithm claimed.',
        'note':'Show experiments/attempts/hamming8_monolithic and hamming8_optimized.json. The simplified final query alone is not the entire proof evidence.'})
    for slide in base:
        if slide.get('title','').startswith('Cross-checks'):
            slide['foot']='The existing-tool comparison remains the initial eight pairs; public pairs used ESBMC fallback.'
        if slide.get('title','').startswith('Live demonstration'):
            slide['note']=f'Run scripts/demo.py, then open experiments/OPTIMIZATION_CATALOG.md and a per-pair dossier. Hardware metrics are recorded measurements, and the proof command executes live. Full pipeline reruns all {n} pairs.'
        if slide.get('title','').startswith('Know the limits'):
            slide['bullets']=['Main cohort is curated; local Qwen sampling is a separate case study.'
                if b.startswith('Single assistant-session') else b for b in slide.get('bullets',[])]
        if slide.get('title','').startswith('A small checker'):
            slide.update(title='Two components now contribute to one proof',
                table=[['Our integration','Role in the combined proof'],['Typed frontend / cut boundaries','One contract; preserve live state and primitive integer types'],['Symbolic execution / Z3','Prove region relations and summary encodings'],['C product / ESBMC with Z3','Verify residual behavior; validate concrete mismatch inputs'],['Refinement and evidence','Reject spurious abstract traces; retain every proof dependency']],
                foot='ESBMC is an attributed upstream component. The default algorithm is proof-level composition; legacy modes reproduce earlier experiments.')
    base.insert(-2,{'title':'Every rewrite has a source and evidence dossier','code':'experiments/OPTIMIZATION_CATALOG.md\nexperiments/optimizations/<case>.md\nbenchmarks/expanded/<case>_original.c\nbenchmarks/expanded/<case>_optimized.c\nresults/submission_verification/<case>_optimized.json\nresults/hls/<case>_<variant>/','bullets':['Before/after C and the actual transformation.','Hashes, proof chain, seeded-control replay and measured QoR.'],
        'note':'Open any record requested by the professor. Every pair has actual artifacts; files are not generated placeholders or missing-result estimates.'})
    base[-2:-2]=[
        {'title':'Actual small-model mistakes at zero API charge','lead':'Qwen2.5-Coder-1.5B Q4_K_M: 40 saved raw attempts',
         'stats':[('28','equivalent'),('8','non-equivalent'),('2','undefined C'),('2','unresolved')],
         'bullets':['20 fixed kernels x two seed/temperature settings; no repair or discarded attempts.','19 unchanged outputs; nine verified AST-changing rewrites.','Six mismatches found by our backend; two by reused ESBMC.'],
         'foot':'Single-model case study. All eight safe errors also appear in native C tests; six exact custom-SMT witnesses replayed.',
         'note':'Open results/local_llm/REPORT.md. Show raw popcount or absolute-difference output. The incorrect special case changes absdiff(0,0) to 1. Never call seeded controls spontaneous LLM errors.'},
        {'title':'Verified model code still needs hardware measurement',
         'table':[['Local-model attempt','Cycle change','ADP ratio'],['Prefix / 5291','62 -> 40','0.545'],['Triangular matvec / 5291','62 -> 24','0.417'],['Triangular matvec / 5292','62 -> 24','0.417'],['Box filter / 5292','158 -> 341','2.639']],
         'bullets':['All nine verified changed outputs measured: three improve, five unchanged, one worse.','Two triangular candidates share one baseline; report that dependence.'],
         'foot':'Same Nangate45 / 10 ns protocol. Nine extra implementations and 144 RTL calls; existing baselines reused by hashes.',
         'note':'Explain why correctness is a gate, not an optimization objective. Both wins and regressions remain recorded in results/local_llm/hls.'},
        {'title':'Subtle errors beyond output-bit mutations',
         'table':[['Controlled category','Result'],['54 safe semantic faults','54 rejected; exact native witness replay'],['20 equivalent code edits','20 accepted'],['6 undefined-C edits','6 separately identified']],
         'bullets':['Indices, masks, thresholds, recurrence state and diagonal handling.','Five faults escaped 264 conventional inputs; SMT found concrete witnesses.'],
         'foot':'Constructed controls, separate from Qwen mistakes. Full ledger: results/subtle_faults/REPORT.md.',
         'note':'Examples missed by the fixed test set: all_equal16 cancellation, clamp16, threshold_pack8, search_count16, rare magic value. Show an equivalent min tie edit to explain why syntax alone is insufficient.'},
        {'title':'Real public functions, with original types preserved',
         'table':[['Source suite','Leaf functions','Preserved inputs'],['CHStone','gsm_abs, gsm_add','Signed short'],['MachSuite','AES rj_xtime','Unsigned byte'],['HLS-Eval','Five binary64-field functions','Unsigned 64-bit bit patterns']],
         'bullets':['Eight candidates proved; eight seeded bugs rejected using reused ESBMC / Z3.','96,272 native inputs; exhaustive signed-16 absolute value and AES byte tests.'],
         'foot':'Leaf extractions with source hashes and notices. No whole-application, floating-point, or custom-backend signed/64-bit claims.',
         'note':'Show gsm_abs(-32768): original 32767, faulty implementation -32768. The dataset audit records 12 CHStone, 19 MachSuite variants and 132 HLS-Eval designs; raw frontend exclusions are explicit.'}]
    if HYBRID and HYBRID['total']==239:
        comparisons=[['Example','Symbolic alone','Monolithic C','Combined']]
        labels={'mixed_array_equivalent':'Correlated array outputs','mixed_array_incorrect':'Faulty suffix','mixed_gemm_lookup':'GEMM + indexed read'}
        for row in ABLATION['cases']:
            comparisons.append([labels[row['id']],row['standalone_symbolic']['status'],row['monolithic_bmc']['status'],row['hybrid_status']])
        base[-2:-2]=[
            {'title':'One algorithm: relational summaries and refinement',
             'code':'1. Prove a region relation with symbolic execution / Z3\n2. Share its poststate in one residual C product\n3. Verify the remaining C with ESBMC / Z3\n4. Refine spurious traces using a certified exact summary\n5. Keep all accepted lemmas as proof dependencies',
             'bullets':['A differing prefix may be overwritten later: no automatic mismatch verdict.','Agreement at one proposed input never proves universal equivalence.'],
             'foot':'Implemented combination of standard compositional verification and abstraction/refinement ideas; no research-first claim.',
             'note':'Run scripts/demo_hybrid.py. Show the first coarse SAT result, the exact-summary certificate and the final equivalent C result. The incorrect suffix still fails and is replayed in actual C.'},
            {'title':'Targeted evidence that the methods cooperate', 'table':comparisons,
             'bullets':[f"Integrated run: {HYBRID['total']} pairs; {HYBRID['matched_known_labels']}/{HYBRID['known_labels']} known labels matched.",
                        f"{HYBRID['accepted_summaries']} accepted summaries; {HYBRID['refined_cases']} refined cases; {HYBRID['available_native_witnesses']} native mismatch replays."],
             'foot':'One measured run per method; per-obligation limits and total budgets differ. Constructed mixed examples, not a statistical speedup claim.',
             'note':'The GEMM loop algebra is discharged symbolically while the indexed access is checked in C. The C backend remains unmodified upstream ESBMC. New shared frontend handles signed/unsigned primitive integers through 64 bits; custom summaries remain unsigned-32.'}]
    if LARGE and LARGE['total']==29:
        winners={f:max([r for r in LARGE['cases'] if r['family']==f and r['status']=='equivalent'],key=lambda r:r['scale']) for f in ('gemm','indexed_gemm','prefix','dot','fir','stencil')}
        base.insert(-2,{'title':'Larger examples under a 60-second attempt limit',
            'table':[['Instance','Size','Measured check time'],['Matrix product','16 x 16',f"{winners['gemm']['elapsed_seconds']:.2f} s"],['Matrix + indexed read','16 x 16',f"{winners['indexed_gemm']['elapsed_seconds']:.2f} s"],['Prefix / dot product','128 elements',f"{winners['prefix']['elapsed_seconds']:.2f} / {winners['dot']['elapsed_seconds']:.2f} s"],['FIR / stencil','64 taps / 16 x 16',f"{winners['fir']['elapsed_seconds']:.2f} / {winners['stencil']['elapsed_seconds']:.2f} s"]],
            'bullets':['29 checks: 22 equivalent, three confirmed mismatches, four inconclusive.','Both formerly inconclusive pairs now prove equivalent.'],
            'foot':'Per solver/C invocation, not total case wall time. Related generated size variants; no new hardware QoR measurements.',
            'note':'The minute applies to each proof obligation. Larger dynamic-count sums and the 16-element correlation case remain inconclusive. Every timeout and precondition is retained in results/large/REPORT.md.'})
    return base


def integrated_pages():
    comparison=[['Mixed example','Symbolic alone','Monolithic C','Combined','Combined time']]
    for row in ABLATION['cases']:
        name={'mixed_array_equivalent':'Correlated array','mixed_array_incorrect':'Faulty suffix','mixed_gemm_lookup':'GEMM + index'}[row['id']]
        comparison.append([name,row['standalone_symbolic']['status'],row['monolithic_bmc']['status'],row['hybrid_status'],f"{row['hybrid_elapsed_seconds']:.3f} s"])
    counts=[['Cohort','Eq','Neq','Undefined','Unsupported','Inconclusive']]
    for name,values in HYBRID['cohort_counts'].items():
        counts.append([name,*[str(values.get(k,0)) for k in ('equivalent','not_equivalent','undefined_behavior','unsupported','inconclusive')]])
    return [
        ('13. Integrated algorithm: relational summary refinement',[
            ('p','The default checker now combines proof methods rather than routing between independent answers. Our symbolic executor and Z3 certify a region relation that changes the C product program verified by ESBMC/Z3. Uncertified regions remain opaque in that same product. Historical standalone/fallback modes remain available for reproduction and ablation.'),
            ('code','Find an explicit state boundary\n  -> prove prefix safety and equal poststates with SMT\n  -> replace prefix pair by shared arbitrary poststates\n  -> check residual C safety and output equality\n  -> if the trace is abstract, certify an exact summary\n  -> recheck the residual product with restored correlations'),
            ('p','A leading region may contain declarations and loop nests, but may not modify scalar parameters or leave local state used by the suffix. A function-exit boundary additionally observes the return value. Prefix proof success permits overapproximating the actual equal poststates by arbitrary equal states. A successful C residual proof over that larger set therefore covers actual executions.'),
            ('p','A coarse counterexample can violate a relation such as out[i]=13*a[i] that the abstraction discarded. The symbolic engine generates a functional summary and separately proves that its C encoding matches the source region. The C engine then rechecks the suffix using those restored correlations. If certification fails, the original region is restored. A differing intermediate region alone is never a final mismatch.'),
            ('p','For a full-exit symbolic mismatch, the concrete input is checked in the actual unabstracted C product. Agreement at that single input cannot prove equivalence; an unconfirmed proposal is discarded and the full input domain is checked. Bounds, pointer, signed-overflow, division, shift, uninitialized and unwinding checks remain enabled.'),
            ('small','This is our implementation of standard compositional and abstraction/refinement ideas. ESBMC itself is not modified or claimed as our code. Files: frontend.py, relational.py, miter.py, hybrid.py and evidence.py under hlscheck/. Full proof rules: docs/INTEGRATED_ALGORITHM.md.')]),
        ('14. Integrated-algorithm evaluation',[
            ('table',counts,[1.25,.55,.55,.8,.85,.85]),
            ('p',f"The separate integrated run checks {HYBRID['total']} pairs and matches {HYBRID['matched_known_labels']}/{HYBRID['known_labels']} known labels; the remaining known pair is inconclusive, with no contradictory conclusive result. Two previously unsupported/unknown local-model cases have no required label. The method accepts summaries in {HYBRID['accepted_summaries']} cases and refines {HYBRID['refined_cases']} cases. Every accepted SMT dependency replays; all {HYBRID['available_native_witnesses']} complete mismatch inputs reproduce a difference in actual C."),
            ('table',comparison,[1.2,1,1,1,.85]),
            ('p','The GEMM example combines different fixed-loop implementations with a symbolic indexed read. Standalone symbolic checking cannot handle that read; the monolithic C check does not resolve it at the tested limit. The combined proof discharges the loop algebra symbolically and leaves the indexed access to residual C verification. A four-element correlation example proves after refinement in the tests/live demo; its eight-element counterpart is inconclusive at the recorded limit. The faulty suffix remains non-equivalent.'),
            ('p','These are constructed target examples and one measured run per method. Limits apply to individual SMT checks and C process invocations; frontend work and symbolic expression construction add wall time. The combined method can issue several obligations, so an equal total budget and uniform speedup are not claimed. Some simple examples are faster monolithically.'),
            ('p','The new frontend preserves primitive signed/unsigned types through 64 bits, isolated typedefs/macros and an explicit ILP32 contract. The summary engine remains unsigned-32, and the first implementation extracts one leading or exit-state region. General calls, heap/pointers, globals, aggregate state and floating-point semantics remain outside the shared frontend.'),
            ('code',r'.\.venv\Scripts\python.exe scripts/demo_hybrid.py'+'\n'+r'.\.venv\Scripts\python.exe scripts/run_hybrid_study.py --ablation'),
            ('small','Raw integrated results, proof dependencies and comparison logs: results/hybrid/. Historical measurements remain unchanged and separately scoped.')])]


def large_pages():
    rows=[['Family','Largest proved size','Original terms/ops','Measured time']]
    for family in ('gemm','indexed_gemm','prefix','dot','fir','stencil'):
        r=max([x for x in LARGE['cases'] if x['family']==family and x['status']=='equivalent'],key=lambda x:x['scale'])
        size=f"{r['scale']} x {r['scale']}" if family in ('gemm','indexed_gemm','stencil') else str(r['scale'])
        rows.append([family,size,str(r['dominant_operations_original']),f"{r['elapsed_seconds']:.3f} s"])
    retry=[['Identical-source retry','Old outcome','60 s outcome','Measured time']]+[[r['id'].removeprefix('retry_'),r['previous_status'],r['status'],f"{r['elapsed_seconds']:.3f} s"] for r in LARGE['cases'] if r['family']=='budget_retry']
    return [('15. Larger instances and a one-minute attempt budget',[
        ('p','The integrated checker now defaults to 60 seconds per SMT check or C-verifier invocation. Frontend/expression construction and multiple refinements add wall time; this is not a one-minute cap on a complete source-pair run. The original 10-second baseline and its exact source snapshot remain separate.'),
        ('table',rows,[1.35,1.25,1.4,1]),('table',retry,[2,1,1,1]),
        ('p','The study checks 27 generated size-scaled pairs and two identical-source retries: 22 equivalent, three confirmed non-equivalent and four inconclusive. All available SMT evidence and native mismatch checks pass; there are no contradictory conclusive verdicts. The 16 x 16 matrix product has 4,096 multiply-accumulate terms; the 128-element prefix reference has 8,256 additions.'),
        ('p','Both earlier inconclusive pairs now prove equivalent. The range8 retry is one of the same forty raw Qwen outputs, so 29 outputs are now established equivalent across budgets. Ten have verified code changes; hardware measurements still cover the initial nine changed outputs, with no inferred QoR for the late proof.'),
        ('p','Unresolved cases are a 16-element correlation, dynamic sums with capacities 16/64 and an 8 x 8 matrix transpose fault. The dynamic loops retain explicit 0<=n<=capacity preconditions. Smaller contract-derived unwind caps, with unwinding assertions still enabled, also remain inconclusive. Increasing time alone does not guarantee a proof.'),
        ('small','These are related generated families, not independent applications or additional hardware measurements. Current/archived source hashes identify the implementation used. Unmodelled source-context, string-storage and address observations are conservatively rejected. Full ledger: results/large/REPORT.md.')])]


def build():
    assert S['passed'] and len(C)==len(CAT['cases'])
    for path in (core.FIGURES,core.PDFS,core.DECK):path.mkdir(exist_ok=True,parents=True)
    core.init_fonts();charts();core.report_pdf(pages());deck=slides();core.deck_html(deck);core.slides_pdf(deck)
    notes_path=ROOT/'docs/PRESENTATION_NOTES.md'
    demo_index=next(i for i,s in enumerate(deck,1) if s['title'].startswith('Live demonstration'))
    notes=notes_path.read_text(encoding='utf-8').split('\n## Expanded study: scope and evidence\n')[0]
    notes=re.sub(r'on slide \d+\.',f'on slide {demo_index}.',notes)
    notes=notes.replace('A local-accumulator\nrewrite is a useful future candidate.','Local-accumulator and two-column candidates are now measured;\nsee the shared-original comparison table.')
    notes+=f'\n## Expanded study: scope and evidence\n\n{len(C)} pairs mean {2*len(C)} synthesized implementations, not {len(C)} independent applications. There are {S["unique_original_c_asts"]} unique original C ASTs. The optimization catalog has a before/after dossier for every pair. The initial Hamming timeout is retained; its successful component proof requires all eight accepted lemma queries as well as the final query.\n'
    notes+='\nThe local Qwen experiment is separate: 40 raw attempts, 28 equivalent (19 unchanged), eight non-equivalent, two undefined-C candidates and two unresolved. Our backend finds six mismatches; ESBMC finds two more. All nine verified changed outputs have hardware results: three improve ADP, five unchanged, one regresses. The two triangular candidates share a baseline.\n\nRun `scripts/demo_local_model.py` for a fresh proof and native replay of an actual raw model error. Do not call artificial mutations spontaneous LLM mistakes. The 80-case controlled suite has 54 faults, 20 equivalent edits and six undefined-C cases; all expected outcomes match. Five faults evade the fixed 264-input set. Public-suite reuse covers eight type-preserving leaves through ESBMC, not whole applications or signed/64-bit semantics in our interpreter.\n'
    if HYBRID and HYBRID['total']==239:
        notes+=f'\n## Integrated algorithm: the contribution to explain\n\nThe default tool uses proof-level composition, not an engine-answer router. Explain a certified region relation, shared arbitrary poststates, a spurious trace caused by lost correlation, and certification of an exact summary before rechecking the residual C. Run `scripts/demo_hybrid.py` for all three stages and a real faulty suffix. The typed frontend and C product are ours; ESBMC itself is upstream code.\n\nThe integrated run covers {HYBRID["total"]} pairs, with {HYBRID["matched_known_labels"]}/{HYBRID["known_labels"]} known labels matched and {HYBRID["available_native_witnesses"]} actual-C mismatch replays. Show the targeted GEMM comparison: standalone symbolic cannot handle the indexed read, monolithic C is inconclusive within the tested limit, and the combined proof succeeds. This is one constructed example and a measured run, not a claim of a generally superior or research-first algorithm.\n'
    notes_path.write_text(notes,encoding='utf-8')
    print('Built expanded report and',len(deck),'slides for',len(C),'pairs.')


if __name__=='__main__':
    build()
