# Presentation outline (about 15 minutes)

Every number below is from a committed result file; keep the caveats on the slides.

1. **Problem (1 min).** An AI rewrites buggy C `P0` given an English request `N`, producing
   `P1`. Is `P1` right? Tests miss things; one LLM-written spec can be wrong; a judge LLM
   that reads `P1` can be fooled.
2. **Idea (2 min).** Verdicts with Evidence: several readings of `N`, built from `P0` and `N`
   only (never `P1`); prove the requested change *and* preservation elsewhere; ACCEPT /
   REJECT only with evidence (E0 computed defect, E1 regression, E2 all readings), otherwise
   UNDECIDED. Draft Sections 4–7.
3. **Pipeline (2 min).** Admission → P0-only regions → validate and freeze readings → CBMC
   SAT+Z3 proofs (mandatory flags, exact buffers) → fixed-input re-proof → ASan/UBSan replay
   → verdict. Show `docs/METHODOLOGY_WALKTHROUGH.md` figure or `make demo-steps`.
4. **Live demo (4 min).** `python scripts/demo_steps.py --task ex2_argmax --candidate v2
   --interactive`: step 8 shows the tie-break regression witness (all `INT_MAX`, `idx` 0 vs 3),
   step 10 the native replay, step 11 REJECT E1. Optionally `--auto groq` on Example 1 to show
   live readings from two model families.
5. **Results (4 min).**
   * Golden Examples 1–7: 20/20 (authored fixtures).
   * Project 3 benchmarks: 181 candidates, 125 decided, **125/125 agree, 0 wrong**, coverage 0.69
     (`docs/EVAL_P3.md`). The CBMC uninitialised-array false positive caught by native replay (Q27).
   * Chrysalis adaptation: method 0 wrong but 1/89 decided; tests-only 41 wrong, regression-only 10
     wrong (`docs/T18_EVAL.md`). Explain why: injected bugs invisible in the scaled profile, SAT
     timeouts.
6. **Limits (1 min).** Bounded, profile-local; template requests; labels partly from the same
   verifier; SAT timeouts on multiplication; no HLS QoR measured (T19–T21 not built);
   theorems not proved.
7. **Takeaway (1 min).** Abstaining is cheap, being wrong is not: across all evaluations the
   method made no wrong decision. Next: qualify a Z3-only determinism path and the
   uninitialised-array check to recover coverage.
