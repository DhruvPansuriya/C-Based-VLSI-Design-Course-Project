# T15 — benchmark ingestion

Status: 30 tasks are adapted deterministically from Chrysalis-HLS single-bug
instances. **These are not a human-authored benchmark.** Request texts come from
one fixed template per documented bug type (`origin: agent_template`); there are no
independent paraphrases, no ambiguous variants with `acceptable_readings`, no fresh
tasks, and `phi_ref` is "outputs equal P_ref" rather than an independently written
specification. The draft's authoring protocol (§11.2, different people for request
and reference) could not be followed: only one agent did this work.

## Sources (pinned 2026-11-23 with `git ls-remote`)

| Source | Commit | Use |
|---|---|---|
| Chrysalis-HLS (Apache-2.0) | `63be1a13a706cdbef4b88fab25aa21167f978b74` | bug files + sources |
| MachSuite | `6236e593012cb86b0d2f08d9fb9ba0411ff989b4` | fetched; fresh injection not done |
| CHStone mirror | `2b7e20ffd3365016faf1e4e2b86496a5c95445fb` | fetched for licence inspection |

**Licensing (Q5).** CHStone asks users to follow each program's copyright. The
adpcm functions (`abs`, `filtep`, `uppol1`, `uppol2`) come from Embree's book and
carry no redistribution grant, and Chrysalis's Apache licence cannot relicense them.
Adapted task sources are therefore **not committed** (`evaluation/benchmarks/tasks/` is
git-ignored). They are regenerated from the pinned checkouts. What is committed:
the adapter, the selection/skip log and P_ref-check evidence keyed by per-task
SHA-256, which also checks that regeneration is byte-for-byte reproducible.

## Adaptation (`scripts/adapt_chrysalis.py`)

Inputs: `Error Size: 1`, types OOB/INIT/SHFT/INF/USE/ZERO/BUF/MLU, exactly one
source file. P_ref = upstream source, P0 = the faulty edit applied by exact
single-occurrence replacement. Each change is recorded in `source.adaptations`:
removed includes, `#define` constants above 4 scaled to K=4, missing size macros
defined as 4 (only when used in a size/arithmetic position; an undefined type name
rejects the instance), `<stdint.h>` added for fixed-width types. An instance is
rejected unless both P0 and P_ref compile as standalone C11 (`cc -fsyntax-only`) and
pass the VWE frontend. Unsized pointer and multidimensional array parameters, floats,
structs, C++ features and I/O are rejected. Selection is deterministic: round-robin
over bug types, preferring MachSuite/CHStone/polybench, then short sources, at most
2 per design. No BUF instance compiled standalone, so BUF is absent.

Scaling sizes to K=4 changes the programs; results on these tasks are about the
scaled programs, not the upstream designs.

## Commands

```sh
python scripts/fetch_benchmarks.py           # pinned clones into third_party/
python scripts/adapt_chrysalis.py --limit 30 # writes evaluation/benchmarks/tasks/ and adaptation_log.json
python scripts/benchmark_stats.py
python scripts/check_benchmark_refs.py       # writes evaluation/benchmarks/ref_check.json
pytest -q tests/test_benchmark_tasks.py      # skips if tasks were not generated
```

`check_benchmark_refs.py` runs the real pipeline on a copy of P_ref with no
interpretations: ACCEPT is impossible, but admission, P0-only reference-guard
certification and candidate E0 safety all run. A REJECT would mean a bad task
or a tool bug.

## P_ref check result (`evaluation/benchmarks/ref_check.json`, 2026-11-23)

20 tasks, **0 REJECT**, 441 s total on this laptop (benchmark profile, 120 s solver
timeouts). 9 tasks reach "no interpretation survived" (expected: no readings yet).
**11** have no certified reference guard (commit `1ae1a06` says 10; it was written
before the last task finished):

| Cause | Tasks |
|---|---|
| P0 undefined on the profile (uninitialised read, shift, OOB from the injected bug) | uppol1_init, uppol2_shft, machsuite init_oob |
| incomplete unwinding (loops exceed max_unwind) | 4 gnn-builder tasks |
| SAT backend timeout at 120 s (determinism with 64-bit products) | filtep_init, filtep_use |
| CBMC local-initialisation instrumentation failed (unqualified) | 2 H.264 tasks |

All are conservative abstentions; every candidate on these tasks will be UNDECIDED
under the method, and this counts against coverage.
