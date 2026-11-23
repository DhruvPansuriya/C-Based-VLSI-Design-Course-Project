# Existing checkers and the course-project contribution

Current integration: the default checker now implements certified relational
summaries with residual-C abstraction/refinement. Custom SMT obligations
justify transformations of the C verification problem processed by ESBMC.
This replaces engine-answer routing in the normal workflow. The historical
comparison and planning sections below retain their original scope; see
`docs/INTEGRATED_ALGORITHM.md` and `results/hybrid/` for the new procedure.
The contribution is an implemented combination of standard ideas, not an
unsupported claim that compositional checking or CEGAR was invented here.

Research check: 2026-11-21. This is a bounded review of primary papers and
repository documentation, not an exhaustive novelty search. Tools listed
below have not been benchmarked locally unless explicitly stated. ESBMC and
PAST now have measured local results in `results/IMPLEMENTATION_COMPARISON.md`.
The completed eight-family hardware evaluation is recorded in
`results/submission/HLS_RESULTS.md`; the planning discussion below is retained
as context for the scope chosen.

Expanded status, 22 November 2026: the main study now has 48 recorded C pairs
and 96 synthesized implementations, including related educational variants
and a second GEMM candidate against the same original. The checker adds Z3
modular polynomial normalization and independently proved additive components.
This is standard compositional proof reasoning used as an implementation
acceleration, not a new general equivalence algorithm. Accepted SMT lemmas are
retained and replayed alongside their dependent final queries. The initial
Hamming timeout remains in the evidence. External-tool comparisons below still
refer to their recorded initial cohorts.

## Agreed course-project scope

The objective is a working, well-evaluated combination of established ideas.
The course does not require a new verification algorithm or a claim of global
research novelty. The professor expects existing papers to be used and cited.

Our chosen combination is:

1. **Symbolic value propagation and complete expansion of fixed-bound loops.**
   This connects the course's path-condition/value-transformation reasoning
   with the restricted static-control setting discussed in the FPGA 2024 HLS
   verification paper. We implement this on a C AST, not its complete PAST
   system or the course's full FSMD/cutpoint algorithm.
2. **Bit-vector mismatch checking with Z3.** Both programs use identical
   symbolic inputs; the solver searches for different return values or final
   parameter-array values. SMT translation-validation literature such as
   Alive2 provides a reference for semantic precision and conservative verdicts.
   We do not implement Alive2's full LLVM refinement and undefined-behavior model.

The resulting course contribution is our implementation, explicit supported C
subset, documented assumptions, test/negative-control suite, LLM transformation
examples, and eventual measured HLS QoR comparison. Existing-tool comparison is
useful if time permits; it does not need to become a separate research project.

## What already exists

| Tool | Main approach and relevance | Role in this project |
|---|---|---|
| [Alive2](https://github.com/AliveToolkit/alive2) | SMT-based LLVM refinement validation, with a symbolic executor and UB-aware semantics. Building the current translation-validator frontend needs a compatible LLVM configuration. | Reference for semantics, refinement versus equivalence, and validation discipline; already downloaded but not built. |
| [ESBMC](https://github.com/esbmc/esbmc) | Clang-based C/C++ verification with SMT backends, bounds/pointer/overflow checks, incremental BMC and induction strategies. | Installed version 8.7; integrated C-to-C harness with Z3. Seven of eight initial cases resolved and agreed; one timeout. |
| [CBMC](https://github.com/diffblue/cbmc) | Mature C/C++ bounded model checker; unwinds loops and verifies assertions. | Independent baseline with identical inputs, separate memories, output assertions and unwinding assertions. Not inherently a turnkey C-to-C interface. |
| [llreve](https://github.com/mattulbrich/llreve) | LLVM-based relational/regression verification; its documented assumptions include no integer overflow and valid memory accesses. | Reference for relational specifications and loops. Its arithmetic assumptions need care for wrapping HLS arithmetic. |
| [CounterTV / Counter](https://github.com/compilerai/counter) | Product-CFG correlation for compiler translation validation. The current repository describes later CounterTV work, not simply an untouched implementation of the 2017 paper. | Reference for black-box correlation and proofs across different control flow; its artifact setup is heavy for this sprint. |
| [PAST Python bindings](https://github.com/cornell-zhang/past-python-bindings) | Exposes a `past.verify` API connected to the FPGA 2024 source-to-source HLS verification paper. | Installed authors' 0.7.2 wheel in WSL; calibrated and tested on annotated-region adaptations. Accepted unrolling, GEMM and stencil; did not prove the tested strength reduction. |
| [HEC](https://github.com/Yu-Maryland/HEC) | MLIR frontend plus equality saturation for datapath and loop transformations; the repository also uses Z3 for checking dynamic transformation conditions. | Reference for scalable structural reasoning. It is inaccurate to describe HEC as having no SMT involvement. |

Primary references: [Alive2 README](https://raw.githubusercontent.com/AliveToolkit/alive2/master/README.md),
[ESBMC README](https://raw.githubusercontent.com/esbmc/esbmc/master/README.md),
[CBMC README](https://raw.githubusercontent.com/diffblue/cbmc/develop/README.md),
[llreve assumptions](https://raw.githubusercontent.com/mattulbrich/llreve/master/reve/README.md),
[CounterTV artifact](https://raw.githubusercontent.com/compilerai/counter/master/README.md),
[PAST API](https://raw.githubusercontent.com/cornell-zhang/past-python-bindings/main/README.md),
and [HEC paper](https://www.usenix.org/conference/atc25/presentation/yin).

## Relevant LLM workflows

[HLS-Eval](https://github.com/sharc-lab/hls-eval) provides HLS design tasks,
testbenches and evaluation infrastructure. [HLSPilot](https://github.com/xcw-1010/HLSPilot)
combines LLM transformations with HLS optimization and design-space exploration.
Both are useful for experimental design and workload selection.

[HLS-LeVeri](https://arxiv.org/abs/2606.17128) studies consistency between
original C and HLS-C using an LLM agent, testbench alignment, symbolic execution
and coverage feedback. Its abstract reports coverage and dynamic consistency;
those numbers are not universal SMT equivalence guarantees.

[semopt](https://github.com/woolcoxm/semopt) is a particularly relevant recent
repository: its README already describes LLM-generated C optimizations,
differential testing, performance measurement and optional CBMC checking on a
bounded domain. These are repository claims, not results independently
reproduced here. Still, its existence rules out claiming that connecting an
LLM to a formal checker is by itself our invention.

## Claims we cannot make

- First C-to-C equivalence checker.
- First formal checker for HLS source transformations.
- First use of bit-vectors, symbolic execution, SMT, path conditions, or complete
  loop expansion to check equivalence.
- First LLM optimization workflow with formal validation or counterexamples.
- Better scalability or correctness than Alive2, ESBMC, CBMC or PAST without
  controlled comparisons.
- A seeded negative control is a real error spontaneously produced by an LLM.

## A defensible course-project contribution

The immediate contribution is an independently developed restricted-C checker
and a reproducible evaluation focused on **verified HLS QoR**, not CPU runtime.
That is an engineering and empirical contribution; a new verification algorithm
has not yet been established.

The core submission needs working proofs/counterexamples and measured HLS
results on benchmark kernels. The following experiments are optional extensions
if time permits:

1. **Semantic errors missed by ordinary testing.** Classify boundary mistakes,
   unsigned wraparound, shifts, array-index errors and invalid loop rewrites.
   Compare random tests, directed tests and formal checking on the same pairs.
2. **Repair feedback quality.** Compare no feedback, failing-test feedback, and
   SMT counterexamples containing concrete inputs and differing outputs. Measure
   verified repair success, attempts and synthesis results using equal budgets.
3. **Hardware gains after correctness filtering.** Measure how apparent area or
   latency improvements change after incorrect candidates are removed. Use the
   same target and HLS settings and report regressions and inconclusive cases.

These experiments can strengthen the submission but are not prerequisites for
an acceptable course project. We will describe our adaptation and integration
accurately and credit the papers and tools used.

## Reference and reuse policy

Use existing work to avoid semantic mistakes and to establish baselines. Keep
our checker code clearly separate from upstream checkouts. If code is copied
or adapted later, preserve its license and record the exact repository, commit,
file and modifications. At this milestone, no upstream checker implementation
has been copied into `hlscheck`; it is an original small implementation based on
standard symbolic-execution and SMT techniques.

ESBMC with Z3 is now integrated as both a reference and a fallback backend
because it matches the requested SMT backend and has a mature C frontend.
Generating an equivalence harness and running an existing verifier is a reused
component of the course contribution, with explicit attribution.
For our own implementation, wider type support or faster path handling would
be extensions, but must be evaluated before calling them improvements.

## Additional papers with usable implementations

- **PEQcheck: Localized and Context-aware Checking of Functional Equivalence**
  (Marie-Christine Jakobs, 2021): reduces equivalence to verification tasks,
  using context and live/modified variables to limit the comparison. The paper
  is saved as `papers/07_peqcheck_2021.pdf`; the
  [FECheck repository](https://gitlab.com/mjakobs/FECheck) has PEQcheck release
  tags. It is relevant to our generated-harness approach, but is not installed.
- **Relational Program Reasoning Using Compiler IR** (Kiefer, Klebanov and
  Ulbrich, VSTTE 2016): associated with llreve. Its
  [official publication list](https://formal.kastel.kit.edu/ulbrich/reve-pubs.phtml?lang=en)
  and [implementation](https://github.com/mattulbrich/llreve) are available.
  The documented LLVM 5.0/Z3 4.5 requirements make it a poor first installation
  target for this sprint.
- **ESBMC v7.6: Enhanced Model Checking of C++ Programs with Clang AST**:
  [paper](https://doi.org/10.1016/j.scico.2025.103336), saved as
  `papers/08_esbmc_v76_2025.pdf`. It documents the underlying verifier family;
  our experiments use 8.7, not the paper's 7.6. ESBMC itself is a program
  verifier; our adapter supplies the C-to-C equivalence problem.
- **Practical Correctness and Equivalence Checking for MLIR** (PACT 2026):
  [authors' publication page](https://axolotls73.github.io/research/) and
  [PEQC-MLIR implementation](https://github.com/axolotls73/PEQC-MLIR).
  It extends the related hybrid-interpretation direction through an MLIR
  frontend; its substantial LLVM/MLIR build is outside our first milestone.

The important implementation reuse is now concrete: PAST is invoked as the
authors' library, and ESBMC as the released verifier with Z3. Our project adds
interface adaptation, generated comparison harnesses, reproducible benchmark
pairs and evidence collection rather than relabeling upstream tools as our own.

`hlscheck/pipeline.py` combines our restricted checker with ESBMC fallback. The
CLI's `--backend auto` mode records both stages. A symbolic-index example was
proved by ESBMC after our concrete-index interpreter returned unsupported.
PAST is retained as a structural comparison tool; its 0 return value is not
treated as a solver-certified counterexample. Both default and all-normalization
PAST configurations failed to establish the tested multiplication-to-shift
identity, while both SMT checkers established it.

PEQcheck (Jakobs/FECheck) and the PAST/PEQC/PEQC-MLIR family are different
research tools with similar names; they should not be conflated in the report.
