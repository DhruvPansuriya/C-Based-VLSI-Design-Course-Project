# Retained initial inconclusive attempt

The same hamming8 original/candidate source pair was first checked using the
monolithic bit-vector mismatch query, with modular polynomial simplification
but without component lemmas. The measured result was `unknown` after the
30-second solver budget, not a mismatch or a proof. The source files, hashes,
result and exported query are retained here.

The later checker groups additive terms by symbolic-variable dependencies,
proves zero components with independent unconditional SMT queries, and removes
only components whose queries return UNSAT. Failed or unknown component checks
remain in the final mismatch query. On this pair it proves eight byte-level
lemmas, then proves the remaining aggregate query. All accepted lemma queries
are exported and are replayed by `replay_smt_evidence.py`.

This is an implementation of standard compositional reasoning, not a claim of
a new general verification algorithm or an independent proof-certificate
checker. The recorded initial timeout is retained in the expanded study.
