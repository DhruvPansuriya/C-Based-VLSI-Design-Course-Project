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

* Formal (`formal_identity`): the pipeline's own obligations with P_ref as the
  reference: admission, P_ref-only region certification, E0 safety on the guard,
  and E1 with an identity relation and an empty change region; violations must
  reproduce with fixed inputs. A first version ran the full method on a task whose
  P0 was P_ref; its V-2 check (correctly) discards a reading P0 already satisfies,
  so nothing could ever be labelled correct. That bug was found on the first run and
  fixed before any labels were used. Functions with mutable globals or no
  observable output are not expressible and stay unknown.
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
