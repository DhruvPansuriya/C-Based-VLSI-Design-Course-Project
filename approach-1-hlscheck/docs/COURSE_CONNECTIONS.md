# Connection to the CS5291 course material

The course PDFs were read from `../Post Midsem/`. They remain outside the
project checkout; the original teaching material has not been changed.

## Program equivalence

`W10L2_ProgramEquivalence.pdf` introduces translation validation, FSMDs,
execution conditions, symbolic value propagation and equivalence of paths.
PDF page 37 defines a path's execution condition and data transformation;
page 38 relates path equivalence to both. Pages 40-42 discuss finite path
covers and cutpoints. The PDF has animation/overlay pages, so its PDF page
numbers differ from the printed slide numbers.

Our checker uses the same underlying idea: propagate symbolic input values
through assignments while retaining conditions under which each execution
occurs. It compares function return values and observable parameter arrays.
The current implementation traverses a C AST rather than constructing an
explicit FSMD or inferring cutpoint invariants.

For every original/candidate terminating-path pair `(p,q)`, it checks:

`guard(p) AND guard(q) AND outputs_differ(p,q)`

The disjunction over all such pairs is the mismatch query. UNSAT means that
no input covered by both executions yields different outputs. With complete
finite execution and identical input domains, this avoids requiring matching
branch structure or a one-to-one path pairing.

The introductory loop-unswitching example inspired
`benchmarks/demo/unswitch_*.c`. The adaptation fixes the dimension, changes
one-based to zero-based indexing, and uses unsigned 32-bit arithmetic. A seeded
`>` to `>=` error provides a boundary counterexample.

## Loop-invariant code motion

`W10L3_VerificationOfLoopInvariantCodeMotion.pdf` explains why comparing isolated
instructions or blocks may fail after code motion. It describes cutpoints,
path covers and value propagation, including a dependency example where naive
comparison would give the wrong answer (PDF pages 22-23).

This motivates comparing final symbolic observables instead of assuming that
temporary variables or individual statements correspond. However, our current
loop support relies on complete expansion of concrete-bounded loops. It does
not reproduce the slide method for general loops or establish a novel method
for invariant inference.

## C-to-RTL checking

`W10M4_C_to_RTL_Equivalence_Checking.pdf` describes trace-level checking,
compatible-trace merging, potential correspondences and SMT validation.
PDF pages 9-16 are especially relevant. Its static-bound discussion supports
starting with fixed-size HLS kernels.

Our Project 3 checks C against C, so it does not implement RTL-to-C extraction,
KLEE trace discovery, cycle alignment or the complete DEEQ flow. The slides
provide foundations and useful examples; our research comparison and eventual
contribution are recorded separately in `RELATED_WORK_AND_NOVELTY.md`.
