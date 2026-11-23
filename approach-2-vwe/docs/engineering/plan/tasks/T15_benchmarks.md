# T15 — Benchmark ingestion

**Priority:** should · **Depends on:** T10 · **Effort:** about 3 days

## Goal

About **20 evaluation tasks** in the task format, with authored requests and reference specifications.

## Sources (links verified; see `docs/technical-design/03_links_versions_and_verification_log.md`)

| Source | Use |
|---|---|
| **Chrysalis-HLS** (https://github.com/UIUC-ChenLab/Chrysalis-HLS, Apache-2.0) | `HLS_Bug_Dataset/{MachSuite,CHStone,polybench,...}/<design>/Source_Code` + `Bugs/bug_<TYPE>.txt`. The bug files are JSON with `Error Type`, `Original Code` and `Faulty Code`. Select single-bug (`Error Size: 1`) instances of the logic types OOB, INIT, SHFT, INF, USE, ZERO, BUF, MLU on **integer** designs. $P_{ref}$ = source; $P_0$ = apply the faulty edit (exact string replace; skip if the original snippet is not found exactly once). |
| **CHStone** mirror (https://github.com/ferrandi/CHStone; per-program copyright) and **MachSuite** (https://github.com/breagen/MachSuite) | extra integer kernels for fresh bug injection |
| **IntroClass** (https://github.com/ProgramRepair/IntroClass, about 2.2 GB) | optional: 3–4 tasks with real student bugs; requires wrapping I/O `main` into a function |
| **Fresh tasks** | 4–5 written by the team after this point, with renamed identifiers (contamination control) |

## Steps

1. `scripts/fetch_benchmarks.py`: shallow clone into `third_party/` (git-ignored), pin commits, and write `third_party/MANIFEST.json`.
2. `scripts/adapt_chrysalis.py`: produce task folders `benchmarks/tasks/<suite>_<design>_<bug>/`:
   - extract the single function containing the edit plus its dependencies (static helpers, `#define`s, typedefs);
   - scale array sizes to ≤ $K$ by editing `#define` constants, recording each change in `task.json.source.adaptations`;
   - reject designs outside the C subset (floating point, C++ features). Chrysalis sources are `.cpp`; accept only files that compile as C after the size edits, and record the conversion.
3. **Authoring protocol** (the draft §11.2), done by a team member who did not write the prompts:
   - `request.txt`: the observed failure plus the desired change (≤ 3 sentences);
   - 2 paraphrases;
   - for about 5 tasks, a deliberately ambiguous variant with `acceptable_readings`;
   - `eval/phi_ref.c` written by a *different* team member than the request author.
4. Validate every task with `vwe.tasks` and run `vwe verify` with the reference fix as candidate (`P_ref` must be ACCEPTed or UNDECIDED; a REJECT means a bad task or a tool bug, so investigate).

## Acceptance criteria

```bash
python scripts/fetch_benchmarks.py && python scripts/adapt_chrysalis.py --limit 30
pytest -q tests/test_benchmark_tasks.py   # every task validates; P_ref never REJECTed
```

At least 20 tasks exist, and their suite and bug-type distribution is printed by `scripts/benchmark_stats.py`.
