# Project 3: Formal Equivalence Checking of LLM-Optimized HLS Code

## Project overview

High-Level Synthesis (HLS) converts an algorithm written in C or C++ into a hardware implementation, usually represented in RTL. Although two C programs may appear to implement the same algorithm, their coding styles can lead an HLS tool to produce hardware with very different performance and resource requirements. Loop organization, memory-access patterns, branches, arithmetic expressions, temporary arrays, data types, and exposed parallelism can all affect the generated circuit.

Large Language Models (LLMs) can be used to rewrite ordinary C code into more hardware-friendly forms. For example, an LLM may simplify arithmetic, restructure loops, remove branches, introduce local buffers, or expose independent operations. These transformations may improve the Quality of Results (QoR) produced by HLS, but an LLM is not a trusted compiler. A rewritten program may compile and pass a testbench while still being incorrect for inputs that were not tested.

Project 3 studies the following central question:

> When an LLM rewrites C code to improve HLS results, can we formally prove that the optimized implementation is functionally equivalent to the original implementation?

The project therefore connects three topics:

1. LLM-assisted source-to-source optimization of C code.
2. HLS evaluation using area, timing, latency, and throughput-related metrics.
3. Formal equivalence checking using an SMT solver.

The intended outcome is not merely to generate faster-looking code. An optimization is useful only when it both preserves the required behavior and improves at least one relevant hardware metric without causing an unacceptable regression elsewhere.

## What formal equivalence means

For two functions, an original program `P` and an optimized program `Q`, functional equivalence informally means that they produce the same observable behavior for every valid input:

\[
\forall x:\; P(x) = Q(x)
\]

For functions that update arrays or memory through pointer arguments, equivalence also includes the final observable memory state. Both functions must start from equivalent inputs and produce the same return values and externally visible memory updates.

Formal checking is different from testing. Testing evaluates a finite collection of inputs. Formal equivalence checking asks whether any valid input exists for which the implementations behave differently. An SMT-based checker commonly expresses this as:

\[
\text{ValidInputs} \land (\text{Output}_{P} \ne \text{Output}_{Q})
\]

If the formula is unsatisfiable, no counterexample exists within the modeled semantics, so equivalence has been proved for that domain. If it is satisfiable, the solver supplies an input that demonstrates non-equivalence. A third outcome, such as unsupported or unknown, is also important: failure to prove equivalence must not be reported as proof that the programs are different, and failure to find a bug must not be reported as proof of equivalence.

The phrase "within the modeled semantics" is essential. C contains subtle rules involving signed overflow, shifts, casts, pointers, aliasing, array bounds, and undefined behavior. A proof is only as trustworthy as the semantics encoded by the checker.

## Quality of Results in HLS

The optimized and original programs must be synthesized under the same device, clock constraint, HLS version, interfaces, and relevant directives. Important QoR measurements include:

- LUT and flip-flop usage;
- DSP and block-memory usage;
- latency in clock cycles;
- initiation interval for pipelined designs;
- estimated clock period or maximum frequency;
- estimated execution time, which depends on both latency and clock period.

These metrics often conflict. Unrolling a loop may reduce latency while increasing LUT and DSP usage. Resource sharing may reduce area while increasing latency. Consequently, the project should discuss trade-offs rather than claim that one implementation is universally "better" based on a single number.

## Discussion of downloaded papers

### 1. Black-box equivalence checking across compiler optimizations

[Dahiya and Bansal, APLAS 2017](../datasets/papers/01_black_box_equivalence_aplas2017.pdf) is the paper explicitly suggested in the project statement. It studies equivalence checking when the exact compiler transformations are unknown. This is called a black-box setting: the checker receives two programs but is not told which optimizations were applied or in what order.

The paper represents programs using transfer-function graphs and searches for a simulation relation between them. A joint transfer-function graph correlates program locations and control-flow transitions in the two versions. Relational predicates describe how the states of the two programs correspond at matched locations. These predicates must be inductive and strong enough to establish equality of observable outputs.

An especially important contribution is its treatment of compiler optimizations that rely on C undefined behavior, including alias-related assumptions. The paper demonstrates that ignoring these assumptions causes valid compiler transformations to appear incorrect. It reports black-box equivalence-checking success rates of approximately 76% for `-O2` and 72% for `-O3` in its experiments.

This work is relevant because LLM transformations are also effectively black-box transformations. The checker cannot safely assume that the LLM applied one known rewrite. However, the paper primarily works across compiled binaries and sophisticated compiler optimizations, whereas Project 3 concerns source-level C written for HLS. Its full algorithm would be too large to reproduce in a normal course project, but its definitions of observable equivalence, simulation relations, soundness, and undefined behavior provide an important theoretical foundation.

### 2. Formal Verification of Source-to-Source Transformations for HLS

[Pouchet et al., FPGA 2024](../datasets/papers/02_formal_source_transformations_hls_fpga2024.pdf) is the closest paper to the formal-verification portion of Project 3. It directly addresses semantic equivalence between an original C/C++ program and another program produced through source-to-source transformations for HLS.

The paper observes that important HLS optimizations frequently require major source changes rather than the addition of pragmas alone. Examples include loop transformations, local and reuse buffers, data-layout changes, FIFO communication, and dataflow-style concurrency. Such rewrites are valuable but error-prone.

Its method combines partial concrete interpretation with symbolic analysis. It focuses on statically interpretable control-flow programs, where enough information is available to resolve control flow and identify a finite set of memory accesses. The computations associated with observable memory cells are represented symbolically and compared after normalization. The approach is designed to tolerate large differences in loop structure, buffering, and communication style.

This paper shows that formal checking of substantial HLS source transformations is already an established research problem. Project 3 should therefore not claim to be the first C-to-C equivalence checker for HLS. The distinction is that our project applies formal checking specifically to transformations proposed by an LLM, uses an SMT solver as the required backend, and studies the relationship between correctness and measured QoR.

### 3. Alive2: Bounded Translation Validation for LLVM

[Lopes et al., PLDI 2021](../datasets/papers/03_alive2_pldi2021.pdf) presents Alive2, a mature translation-validation system for LLVM IR. Alive2 uses SMT solving to determine whether an optimized LLVM function refines its source function. Refinement is more precise than simple output equality because an optimization may remove nondeterministic or undefined behaviors but must not introduce new observable behaviors.

Alive2 is particularly important as evidence that SMT-based equivalence checking can find real compiler bugs. It models fixed-width operations, poison values, undefined behavior, and memory semantics at the LLVM level. Its checking is bounded in important cases such as loops, so its guarantees must be interpreted accordingly.

For Project 3, Alive2 is both a conceptual reference and a possible comparison point. It demonstrates the importance of precisely defined semantics and conservative results. It is not, however, a direct solution to the project: it operates on LLVM IR rather than HLS-oriented C source, and source-to-source HLS rewrites may introduce structures that are awkward to compare after lowering.

### 4. HLSPilot: LLM-based High-Level Synthesis

[HLSPilot](../datasets/papers/04_hlspilot_2024.pdf) represents the LLM optimization side of the project. It applies LLMs to identify computational bottlenecks and transform sequential C/C++ code into HLS-oriented implementations. It combines pattern-guided transformations with design-space exploration because LLMs are not consistently reliable at choosing detailed pragma parameters.

HLSPilot provides evidence that LLMs can assist with transformations involving nested loops, local arrays, and other patterns that affect hardware acceleration. It also shows the importance of synthesis feedback: plausible-looking source code is not sufficient, because the final objective is better hardware.

Its central focus is automatic acceleration and QoR, rather than a formal proof that every generated transformation preserves semantics. Project 3 adds a trust layer to this style of workflow by treating LLM output as an untrusted candidate that requires independent validation.

### 5. HLS-Eval: A Benchmark and Framework for Evaluating LLMs on HLS Design Tasks

[HLS-Eval](../datasets/papers/05_hls_eval_2025.pdf) introduces a benchmark and evaluation framework for LLM-driven HLS design. It contains 94 designs gathered from sources including PolyBench, MachSuite, CHStone, Rosetta, C2HLSC, and other accelerator projects. It studies both generation from descriptions and optimization-oriented editing of existing HLS code.

HLS-Eval evaluates several stages of success, including whether generated code can be parsed, compiled, run in C simulation, and synthesized. This staged evaluation is important because an LLM output can fail long before QoR is meaningful.

For Project 3, HLS-Eval is a useful source of curated kernels, testbenches, and experimental conventions. Its validation flow is largely based on compilation and simulation. Passing a testbench gives useful evidence, but it does not prove equivalence for all valid inputs. This difference creates a natural connection between HLS-Eval-style experimentation and formal checking.

### 6. C2HLSC: Can LLMs Bridge the Software-to-Hardware Design Gap?

[C2HLSC](../datasets/papers/06_c2hlsc_2024.pdf) investigates whether LLMs can refactor conventional C into forms accepted by HLS tools. Its case studies include applications such as AES-128, QuickSort, and statistical randomness tests. The work uses iterative interaction with an LLM to remove unsupported constructs and introduce HLS-oriented interfaces and behavior.

C2HLSC demonstrates that producing synthesizable HLS code from software-oriented C is itself nontrivial. Syntactic correctness, functional correctness, synthesizability, and hardware quality are separate requirements. Like HLSPilot, it supports the motivation for using an LLM as a transformation assistant, but it does not replace the need for an independent formal correctness argument.

## Relationship among the papers

The downloaded literature forms two largely complementary research threads:

- **LLM-for-HLS research:** C2HLSC, HLSPilot, and HLS-Eval show that LLMs can generate, refactor, and optimize HLS code, while also revealing that compilation, simulation, synthesizability, and QoR must be evaluated separately.
- **Equivalence-checking research:** the black-box checker, the FPGA 2024 HLS verification work, and Alive2 show how semantic relations, symbolic representations, undefined behavior, and SMT reasoning can be used to validate program transformations.

Project 3 lies at their intersection. Its contribution is not the invention of either thread. Its value is the study of whether formal equivalence checking can act as a dependable correctness filter for LLM-generated HLS optimizations, while synthesis results determine whether the verified transformation is actually useful.

## Research gap and project significance

Existing LLM-for-HLS work commonly relies on compilation, simulation, reference testbenches, or synthesis success. These checks are necessary but do not guarantee correctness for all valid inputs. Existing equivalence checkers provide stronger guarantees, but they are generally designed for compiler IR, binaries, or particular classes of HLS transformations rather than an experimental flow centered on LLM-generated C candidates and their QoR.

The project can therefore investigate questions such as:

- How frequently does an LLM produce functionally incorrect HLS optimizations?
- Can formal checking find errors that ordinary testbenches miss?
- Which classes of LLM transformations are easy or difficult to prove equivalent?
- Among the candidates that are formally verified, how often is area, latency, timing, or initiation interval improved?
- What kinds of C semantics or HLS coding patterns cause the checker to return an inconclusive result?
- Can a concrete SMT counterexample clearly explain an error introduced by the LLM?

These questions are useful even if the LLM does not consistently improve QoR. Negative results can reveal that a transformation is incorrect, that it creates an unfavorable hardware trade-off, or that it falls outside the supported proof domain.

## Important observations

### The LLM must not be part of the trusted proof

The LLM may help write optimized code and help develop the checker, but the final equivalence result must come from deterministic parsing, semantic modeling, and SMT solving. Asking the same LLM whether its own code is correct is not formal verification.

### Passing tests is not equivalent to a proof

Random and directed tests remain useful for debugging and for comparison with the formal method. Nevertheless, a finite testbench cannot generally establish equivalence over a large input space. One of the most informative experimental categories will be candidates that pass all available tests but are rejected by the SMT checker with a counterexample.

### C semantics are central, not an implementation detail

Unsigned fixed-width arithmetic naturally corresponds to hardware bit-vectors, but signed overflow, shifts, casts, pointers, aliasing, and out-of-bounds accesses require careful treatment. Undefined behavior may allow a compiler to make transformations that are not valid under an informal mathematical-integer interpretation. Claims of equivalence must always state the supported language subset and assumptions.

### Source equivalence and C-to-RTL equivalence are different

This project compares original C with LLM-optimized C. It does not by itself prove that an HLS tool translated the optimized C into correct RTL. The latter is the separate C-to-RTL equivalence problem addressed by frameworks such as DEEQ. Project 3 assumes the HLS backend correctly implements the accepted source program when interpreting the QoR results.

### QoR improvement is multidimensional

An optimization may improve latency but consume more resources, or reduce area while lowering throughput. Results should preserve the individual metrics and identify trade-offs or Pareto improvements instead of combining all hardware costs into an unexplained score.

### Inconclusive is a valid formal result

Program equivalence is undecidable in general. A sound checker will necessarily fail to prove some genuinely equivalent programs because of unsupported constructs, difficult loops, aliasing, solver limits, or insufficient invariants. These cases should be reported as inconclusive rather than equivalent or non-equivalent.

## Available local resources

The project folder currently contains:

- [MachSuite](../datasets/MachSuite), with kernels including AES, FFT, GEMM, sorting, sparse matrix-vector multiplication, stencil computation, and Viterbi decoding;
- [CHStone](../datasets/CHStone), containing common HLS applications from cryptography, signal processing, arithmetic, image processing, and processor examples;
- [HLS-Eval](../datasets/hls-eval), providing curated LLM-ready HLS designs and evaluation support;
- [HLSFactory](../third_party/HLSFactory), with selected MachSuite, CHStone, PolyBench, Rosetta, and C2HLSC datasets;
- [Alive2](../third_party/alive2), retained as a reference implementation of SMT-based translation validation;
- the six papers discussed above in the [papers](../datasets/papers) directory.

The complete inventory, versions, repository snapshots, and disk usage are recorded in [docs/RESOURCE_MANIFEST.md](RESOURCE_MANIFEST.md).

## Overall perspective

Project 3 is best understood as a study of **trustworthy LLM-assisted HLS optimization**. The LLM supplies creativity and rapid exploration, HLS synthesis measures hardware consequences, and formal reasoning supplies confidence that the optimized source preserves the intended computation.

Prior work shows that each component is feasible, but it also exposes the main challenge: useful HLS transformations may substantially change loop structure, storage organization, and arithmetic while C semantics contain many corner cases. A credible project must therefore make modest, precise claims. The strongest result will not be that every C program can be checked, but that a clearly defined class of LLM-generated HLS transformations can be evaluated reproducibly, with formal proofs for accepted candidates and concrete counterexamples for incorrect ones.
