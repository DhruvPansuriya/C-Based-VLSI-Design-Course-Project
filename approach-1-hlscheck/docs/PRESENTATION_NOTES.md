# Presentation notes and viva preparation

Suggested duration: 12-15 minutes. All slide numbers below refer to the offline deck.

## Slide 1: Formal checking and HLS optimization across 50 design pairs

Introduce the course problem: an LLM can propose a useful rewrite, but correctness and hardware quality both need evidence. The result is a course-level engineering contribution using established formal techniques.

## Slide 2: Three requirements, three kinds of evidence

Explain that running an existing verifier alone would not satisfy our interpretation of developing a checker. We implement the restricted interpreter and separately reuse ESBMC for a broader fallback.

## Slide 3: Existing papers provide the foundation

Emphasize PAST as the closest HLS-source paper. The checker shares standard ideas, but does not reproduce its full algorithm. Alive2 operates on LLVM and has a much richer semantic model.

## Slide 4: Correctness and hardware benefit are separate gates

Explain the source hash gate. Our selected objective is area times cycles times the common 10 ns period, with the timing constraint satisfied. We keep failed QoR candidates visible.

## Slide 5: The proof contract is explicit

Describe a miter query. Equality is at function completion. These are conditional C-to-C guarantees, not cycle-by-cycle C-to-RTL guarantees. All supported paths and finite loop iterations must be covered.

## Slide 6: Two components now contribute to one proof

Use index & 7 versus index % 8 as the fallback example. The custom stage rejects symbolic indexing; ESBMC proves it. We do not claim to have implemented ESBMC or PAST.

## Slide 7: A compositional check resolves the Hamming timeout

Show experiments/attempts/hamming8_monolithic and hamming8_optimized.json. The simplified final query alone is not the entire proof evidence.

## Slide 8: Workload accounting stays explicit

State dimensions: GEMM 4x4, stencil 5x5 with 3x3 filter, prefix eight values, FIR eight taps. All pairs have identical interface and data types. This is not untouched MachSuite coverage.

## Slide 9: Proofs, witnesses and independent execution

Each of the eight fault witnesses was independently compiled and the full concrete outputs matched the solver report. The rare example is a deliberately controlled illustration, not a statistical experiment.

## Slide 10: Expanded measured outcomes

Walk through prefix and FIR on the left of one, then scale, GEMM and boxfilter on the right. Stencil and boxfilter have lower cycle counts but greater area. Do not average these tiny heterogeneous benchmarks into an LLM success rate.

## Slide 11: Three useful wins under the common clock

Explain 36 repeated prefix reads/additions versus eight running-sum updates. At 10 ns the function latency changes from 620 to 260 ns. The timing estimate is separate from the target clock used to calculate latency.

## Slide 12: Keep the trade-offs and regressions in the report

GEMM causality is an interpretation, not a measured isolated ablation. A better future rewrite could use local accumulators. These findings show the need for actual HLS feedback rather than source-level intuition.

## Slide 13: GEMM follow-ups: test the area/latency balance

This is a measured follow-up candidate, not an extra independently sampled application. Explain the source code and compare both actual measurements.

## Slide 14: Cross-checks support confidence; public coverage is limited

Different input formats, instrumentation and proof methods mean raw timing comparisons are not a fair competition. Report inconclusive outcomes and exclusions, not just successful cases.

## Slide 15: Live demonstration: proof, fault and measured hardware

Run scripts/demo.py, then open experiments/OPTIMIZATION_CATALOG.md and a per-pair dossier. Hardware metrics are recorded measurements, and the proof command executes live. Full pipeline reruns all 50 pairs.

## Slide 16: Know the limits of the result

Acknowledge that the interpreter is tested, not formally proved correct. Replaying solver witnesses and cross-checking existing tools validates aspects of the implementation but is not a proof of the verifier.

## Slide 17: Every rewrite has a source and evidence dossier

Open any record requested by the professor. Every pair has actual artifacts; files are not generated placeholders or missing-result estimates.

## Slide 18: Actual small-model mistakes at zero API charge

Open results/local_llm/REPORT.md. Show raw popcount or absolute-difference output. The incorrect special case changes absdiff(0,0) to 1. Never call seeded controls spontaneous LLM errors.

## Slide 19: Verified model code still needs hardware measurement

Explain why correctness is a gate, not an optimization objective. Both wins and regressions remain recorded in results/local_llm/hls.

## Slide 20: Subtle errors beyond output-bit mutations

Examples missed by the fixed test set: all_equal16 cancellation, clamp16, threshold_pack8, search_count16, rare magic value. Show an equivalent min tie edit to explain why syntax alone is insufficient.

## Slide 21: Real public functions, with original types preserved

Show gsm_abs(-32768): original 32767, faulty implementation -32768. The dataset audit records 12 CHStone, 19 MachSuite variants and 132 HLS-Eval designs; raw frontend exclusions are explicit.

## Slide 22: One algorithm: relational summaries and refinement

Run scripts/demo_hybrid.py. Show the first coarse SAT result, the exact-summary certificate and the final equivalent C result. The incorrect suffix still fails and is replayed in actual C.

## Slide 23: Targeted evidence that the methods cooperate

The GEMM loop algebra is discharged symbolically while the indexed access is checked in C. The C backend remains unmodified upstream ESBMC. New shared frontend handles signed/unsigned primitive integers through 64 bits; custom summaries remain unsigned-32.

## Slide 24: Larger examples under a 60-second attempt limit

The minute applies to each proof obligation. Larger dynamic-count sums and the 16-element correlation case remain inconclusive. Every timeout and precondition is retained in results/large/REPORT.md.

## Slide 25: The project demonstrates a complete course workflow

End on the central outcome: source correctness and hardware benefit are different questions. Prefix is the strongest positive result; keeping the regressions makes the evaluation useful and honest.

## Slide 26: Primary references and implementations

Use this slide for questions about related work and code reuse. The custom interpreter is separate from upstream binaries. MachSuite-derived sources retain their license.

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
That explanation is not an isolated causal experiment. Local-accumulator and two-column candidates are now measured;
see the shared-original comparison table.

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

1. Open this directory in PowerShell and run the command on slide 15.
2. Show the live prefix equivalent verdict and the faulty version's witness.
3. Show the rare-input witness 0xdeadbeef.
4. Open results/submission/HLS_RESULTS.md; distinguish recorded hardware data
   from the live proof computation.
5. If asked, open results/hls/prefix_optimized/sta.log and yosys.log.
6. Use --backend auto on the symbolic-index pair only if time permits.

## Expanded study: scope and evidence

50 pairs mean 100 synthesized implementations, not 50 independent applications. There are 47 unique original C ASTs. The optimization catalog has a before/after dossier for every pair. The initial Hamming timeout is retained; its successful component proof requires all eight accepted lemma queries as well as the final query.

The local Qwen experiment is separate: 40 raw attempts, 28 equivalent (19 unchanged), eight non-equivalent, two undefined-C candidates and two unresolved. Our backend finds six mismatches; ESBMC finds two more. All nine verified changed outputs have hardware results: three improve ADP, five unchanged, one regresses. The two triangular candidates share a baseline.

Run `scripts/demo_local_model.py` for a fresh proof and native replay of an actual raw model error. Do not call artificial mutations spontaneous LLM mistakes. The 80-case controlled suite has 54 faults, 20 equivalent edits and six undefined-C cases; all expected outcomes match. Five faults evade the fixed 264-input set. Public-suite reuse covers eight type-preserving leaves through ESBMC, not whole applications or signed/64-bit semantics in our interpreter.

## Integrated algorithm: the contribution to explain

The default tool uses proof-level composition, not an engine-answer router. Explain a certified region relation, shared arbitrary poststates, a spurious trace caused by lost correlation, and certification of an exact summary before rechecking the residual C. Run `scripts/demo_hybrid.py` for all three stages and a real faulty suffix. The typed frontend and C product are ours; ESBMC itself is upstream code.

The integrated run covers 239 pairs, with 236/237 known labels matched and 121 actual-C mismatch replays. Show the targeted GEMM comparison: standalone symbolic cannot handle the indexed read, monolithic C is inconclusive within the tested limit, and the combined proof succeeds. This is one constructed example and a measured run, not a claim of a generally superior or research-first algorithm.
