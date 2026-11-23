# Generated verification harnesses

`vwe.harness.generate.Generator` accepts two admitted build views and one exact
caller profile. It emits C, the watched input names, expected assertion labels,
loop bound, source and artifact hashes, and prerequisite checks in `bundle.json`.
A generated job has no verdict. Each C implementation lives in a separate
translation unit. Trusted adapters give it real C values and extract observable
fields without comparing struct padding.

| Job | Meaning |
| --- | --- |
| E0 | Check P1 safety within a proposed reference guard. A separate P0 safety and determinism job must certify the guard before it can support a rejection. |
| E1 | Check equality or at least one known Ext outside the union of clause and reach zones for this exact profile. Unknown Ext or reach disables a decisive E1. |
| Class | Check each clause in its zone and full preservation outside the union of its clauses. The keep region must first be safe and deterministic for P0. |
| Reference and determinism | Run two independent copies with the same caller state. Check safety and compare outputs on the supplied guard. |
| Vacuity | Emit a reachability probe for each clause and the keep region, optionally with the candidate call removed. Compare before and after call results to distinguish an empty region from a cut path. |
| Build views | Compare the candidate with `__SYNTHESIS__` off and on. |
| Contract UB | Evaluate lowered observers over exact inputs and arbitrary type-correct outputs without running the candidate or the reference. |

The class job checks P1 on the entire profile. Once P0 is certified on the keep
region, the full profile equals the obligation domain `Safe0 ∪ B_k`. A failure
of the reference certificate leaves the class unresolved until an exact P0
definedness model is available. A clause that reads old outputs currently
requires a full-profile P0 certificate. The contract UB check uses an
overapproximation of reachable old outputs. A finding on an unreachable synthetic
output cannot on its own invalidate a contract that depends on old state.

The profile uses LP64 with signed `char`, initialized caller state, and disjoint
allocation regions. Each buffer has exactly the declared symbolic size. A
zero-size region explores both NULL and the allocator's zero-size result, using
the same choice for corresponding copies. Input elements and global fields
have individually named witness slots. A returned pointer is compared by region
and byte offset, including one-past pointers, or by NULL. Other pointer targets
raise an observation support obligation. Pointer-bearing input graphs, const
members that prevent initialization, and nonliteral fixed array layouts require
another profile. The contract DSL exposes integer scalars and flat buffers.
Relational equality also observes supported composite values.

The pointer intrinsics were checked against the [CBMC 6.11.0 built-in declarations](https://github.com/diffblue/cbmc/blob/cbmc-6.11.0/src/ansi-c/cprover_builtin_headers.h)
and tested on independent allocations. The T04 tests compile each job with
`goto-cc`, check a deliberately too-small contract shape with both solvers,
verify field-wise and pointer observations, and reproduce the ten handwritten
golden verdicts under the fixtures' declared profiles. They exercise the
generated obligations. Production verdicts still depend on T05 instrumentation,
T06 definedness, T07 interpretation validation, and T08 orchestration.
