# Replaying an already known SAT result

An additional unconstrained replay run reached its 30-second budget on three
nonlinear negative-case queries (GEMM, stencil and dot product), although the
original checker had found counterexamples and compiled C had reproduced them.
The replay statuses are retained here. An unknown replay is not converted to
a new proof or disproof.

The final replay runner checks SAT queries at the exact recorded input witness.
SAT with those additional constraints also establishes SAT of the original
unconstrained mismatch query. It is a concrete witness check, not a second
unconstrained model-search experiment. Every UNSAT main query and every
accepted zero-component lemma is still replayed without input restrictions.
The replay JSON records which queries were witness-pinned. Compiled-C replay
remains a separate independent execution check.
