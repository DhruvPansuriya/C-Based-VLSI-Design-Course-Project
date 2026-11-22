# T16 — candidate pools and labels

Status: tooling implemented and unit-tested; the full labelling run over the 30
benchmark tasks is recorded separately in `results/eval/pool_stats.md` once
it completes. **No LLM candidates exist**: no live provider is configured, so
`scripts/gen_candidates.py` records every family as unavailable.

## Pools (`scripts/gen_mutants.py`)

Per task: `ref` (P_ref copy), `unchanged` (P0 submitted as the fix) and up to N
deterministic mutants of P_ref (`vwe/eval/mutants.py`: relational swap, constant
±1, deleted `if` guard, swapped min/max at evenly spaced sites; only compiling
mutants), plus any `llm_*` files. Deduplicated by comment/whitespace-insensitive
token stream; provenance in `eval/pool.json`.

## LLM candidates (`vwe/eval/candidate_gen.py`)

The only place an LLM writes candidates. It takes a bare provider (an
interpretation `LLMClient` is refused), has its own prompt and cache namespace,
sees P0 and N only, and stops at `max_calls` (provider calls are the recorded
cost proxy; token usage is not reported by the adapters).

## Labels (`vwe/eval/labels.py`, `scripts/label_candidates.py`)

* Formal: the VWE pipeline on a labelling task whose P0 is P_ref and whose only
  reading is identity (all outputs equal P_ref's, zone true). Functions with
  mutable globals or no observable output are not expressible and stay unknown.
* Differential: 10,000 deterministic profile-bounded inputs plus boundaries,
  ASan/UBSan, per-input exclusion where P_ref aborts or hangs, deterministic replay.
* correct = formal ACCEPT and testing agrees; incorrect = formal REJECT, or a
  native counterexample while formal is not ACCEPT; otherwise unknown. Formal
  ACCEPT contradicted by testing is flagged and left unknown.

Limits: the formal check reuses the verifier under evaluation (shared defects
would be invisible; the native check is the independent cross-check), labels hold
for the bounded caller profile only, and uninitialised reads are not detected
natively. Labels live in `eval/labels.json`; `tests/test_labels_isolation.py`
checks that production code never imports `vwe.eval` or opens label files.
