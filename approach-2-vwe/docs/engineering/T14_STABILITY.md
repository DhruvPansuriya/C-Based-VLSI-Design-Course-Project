# T14 — repetition, union and stability

Status: implemented and tested with authored mock fixtures. **No live-model
stability was measured.** Mock fixtures return the same reply for every run, so
the measured agreement/coverage in tests is a plumbing check, not a finding.

## What exists

* `config/llm.toml [client] runs` (default 1) and `--runs`; run `k` carries
  `run_index=k` in the cache key and provenance.
* Seeds: with `--seed S`, run `k` is requested with seed `S+k`; the value is recorded
  per call. A seed is a request parameter. Provider determinism is not assumed, so a
  repeated live run may differ; the cache is what makes a past run replayable.
* `vwe/stability.py`: `union` (semantic-duplicate merge, keeping the first id),
  `select_runs`, `stability_report`.
* `vwe stability <task> --runs 3 --family F [--candidate c]` generates the runs once,
  verifies each single run and each cumulative union prefix, and writes
  `stability.json`: per-candidate single-run decisions, modal agreement,
  cumulative decisions, per-step conservativeness, coverage (fraction not
  UNDECIDED) by union size, and distinct-reading counts by union size.

## Monotonicity: the valid premise

The card states "verdict(set ∪ extra) is UNDECIDED or the same". Against
`vwe.verdict.decide` this is true **only if** the candidate-side E0 and E1
outcomes and `ext_all_known` for the base readings are held fixed and the base
set is non-empty. `tests/test_stability.py` checks that exhaustively (over 1,000
outcome combinations). It is **not** guaranteed pipeline-wide: more readings can
enlarge `B_max`, turning an E1 violation into PROVED (REJECT E1 → ACCEPT E2), and an
empty base can become decided. `stability_report` therefore flags any non-conservative
step (`nonconservative_steps`) instead of asserting it, and such a step must be
explained from the run reports.

## Not done

Live repeated-generation measurements, stability on benchmark tasks (T15+) and any
claim about real-model collapse onto one reading.
