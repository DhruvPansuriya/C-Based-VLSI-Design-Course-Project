# AGENTS.md — rules for coding agents in this repository

## Project in one paragraph

VWE decides whether an AI-revised C function `P1` correctly implements a natural-language fix request `N` on a buggy function `P0`, using CBMC (primary verifier, Z3 and SAT backends), ESBMC (confirmation only) and sanitizer replay. Method: `docs/research/`. Engineering design: `docs/technical-design/`. Plan: `plan/`.

## Non-negotiable soundness rules (each comes from a verified finding)

1. **No LLM ever receives `P1` or anything derived from it.** LLM prompts may only be built from `vwe.llm.RequestContext` (request text, `P0` signature, shape candidates). There is no production FIFO exception: P1-derived state names/types also reveal P1 information. Use deterministic/template invariants. This follows the user's original information-boundary requirement; see `docs/CLAUDE_IMPORT_REVIEW.md`. A test enforces this rule; never delete that test.
2. **Every CBMC run uses `vwe.tools.cbmc.BASE_FLAGS`:**
   - `--unwinding-assertions` and `--no-self-loops-to-assumptions` (spike T01);
   - `--no-malloc-may-fail` (spike T04, review R5);
   - all standard checks.

   Never remove a flag to make something pass.
3. **Path cuts:** before analysis, `abort|exit|_Exit|longjmp` get generated bodies (`goto-instrument --generate-function-body ... assert-false-assume-false`) (spike T03).
4. **Harness buffers are allocated with exact symbolic size** (`malloc(n*sizeof(T))`), never fixed-size arrays (spike T04).
5. **Inconclusive never becomes a decision.** Timeouts, failed unwinding assertions, backend disagreement and vacuity probes that do not fire all yield `Outcome.INCONCLUSIVE`.
6. **ESBMC is confirmation-only.** ESBMC can veto an ACCEPT. It can never produce one (review R3).
7. **Interpretations are discarded only on conclusive invalidity checks.** V-5 size/plausibility sampling is informational. UNKNOWN validation remains unresolved and blocks E2; it is never silently deleted. LLM-generated examples are informational. See the import review before implementing T06/T07.
8. **`eval_only` data** (`P_ref`, `Phi_ref`, true shape and zone) is never visible to the pipeline. Load tasks through `vwe.tasks.load_pipeline_view`.
9. **Do not invent tool flags, versions, URLs or results.** Verify them, or record them in `plan/OPEN_QUESTIONS.md`.

## Code conventions

- Python ≥ 3.10, type hints everywhere, `dataclasses` for records, no global mutable state.
- Every external tool call goes through `vwe/tools/*.py` with a timeout and returns structured results.
- Every artifact for a run goes under `runs/<task>/<candidate>/<run_id>/` (git-ignored).
- New dependencies go in `requirements.txt` with pinned versions.
- Tests:
  - `pytest`; unit tests must not need CBMC;
  - tests that need CBMC use `@pytest.mark.skipif(not cbmc.cbmc_available(), ...)`;
  - golden tests live in `tests/golden/`.
- Keep functions small. Keep the verdict logic in `vwe/verdict.py` only.

## Commands

```bash
make test        # all tests
make golden      # golden end-to-end examples
make spikes      # tool-behaviour spikes (regression on tool upgrades)
make demo        # professor demo (added in T11)
```

## Definition of done for any task

Its acceptance commands pass, `make test` is green, the docs or README are updated if behaviour changed, and there is one commit with the prefix `Txx:`.
