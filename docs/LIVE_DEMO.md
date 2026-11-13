# Live demo guide

Everything needed to run the demo in front of the professor and to answer "where is X?" questions.
There are two ways to show it:

* **Option 1 (main): run it live in the VS Code terminal.** The professor watches the real pipeline
  run stage by stage. Use this.
* **Option 2 (optional): the demo web page** `runs/index.html`, which lists the runs you just made and
  links to every report. Use it at the end, or if something goes wrong with the terminal.

Tools on this laptop: CBMC 6.11.0, Z3 5.4.1, Clang (for ASan/UBSan replay), Python 3.13 in `.venv`.
ESBMC is not installed locally; it only runs in CI and can only cancel an ACCEPT, never create one.

---

## Option 1: live in VS Code (learn this)

### A. Set up the screen (2 minutes, before the professor arrives)

1. Open VS Code, then **File > Open Folder...** and choose `c-based-vlsi-design-course-project`.
2. Open a terminal: **View > Terminal** (or Ctrl + backtick). It opens at the bottom, already in the
   repository folder.
3. In the terminal, type once:
   ```sh
   source .venv/bin/activate
   cbmc --version        # must print 6.11.0
   ```
   The prompt now starts with `(.venv)`.
   Then clear old demo outputs, so everything the professor sees is created live:
   ```sh
   make demo-reset       # empties runs/demo-steps, runs/demo and runs/index.html
   ```
   After this, `runs/demo-steps/` does not exist. Each command below creates a new folder
   `runs/demo-steps/<task>/<candidate>/<run id>/` while it runs (watch it appear in the Explorer).
4. In the Explorer on the left, open `docs/demo_diagrams/1_where_is_the_run.png`. Drag its tab to the
   right half of the editor (or right-click the tab > **Split Right**). Open the other three PNGs in
   the same right-hand group, so you can click between them.
5. Make the terminal bigger: drag its top edge up, or click the **^** (Maximize Panel Size) icon.
   Increase the font if needed with Cmd + plus.
6. Open `examples/tasks/ex1_saturate/` in the Explorer: `p0.c`, `request.txt`, `candidates/v3.c`.
   These are the inputs you will talk about first.

Layout: inputs and diagrams on the top right, the running terminal at the bottom.

### B. The first run (the one to explain slowly)

```sh
python scripts/demo_steps.py --task ex1_saturate --candidate v3 --interactive
```

* `--interactive` stops after every stage and waits for **Enter**. While it waits, explain the stage
  using diagram 1 (find the `STEP n:` row), then press Enter.
* At STEP 6 to 9 (`Proof: ...`) switch to diagram 2. At STEP 11 (`Verdict`) switch to diagram 3.
* Section 1b below lists exactly what each step prints and what to say.

**Everything is computed live.** Every run calls CBMC, Z3 and the sanitizers again and writes a new
folder; nothing is copied from earlier runs (the optional `VWE_REGION_CACHE` speed-up is off unless you
set that variable). The `t=...s` on each `STEP` heading is the real elapsed time. The only cache is for
LLM answers with `--auto groq`; `make demo-reset` clears it too, so the next `--auto groq` run asks the
models again (it prints which models "answered live").

### C. Show the evidence that was saved

1. The last line is `Full evidence: .../runs/demo-steps/ex1_saturate/v3/<run id>/report.html`.
   **Cmd-click** the path: it opens in the browser with every proof, both solvers' answers, the witness
   and both programs' outputs.
2. In the VS Code Explorer, open `runs/demo-steps/ex1_saturate/v3/` and the newest run folder inside it
   (`runs/` looks greyed out because it is git-ignored; that is normal). Click through:
   * `e1/main.c`: the generated harness with P0 and P1 side by side and the `VWE.E1.preservation` assert
   * `e0/verification/sat.command.json`: the exact CBMC command and flags
   * `native/witness-0.json`: the real outputs of P0 and P1 on a=0, b=0
   * `report.json`: the verdict, evidence class and witness as data
   Diagram 4 shows this folder layout.

### D. Then run the rest

Run the remaining commands from the table in section 1 (copy them from here or from the web page).
Without `--interactive` each runs straight through in about 20 to 30 seconds.

### E. Close with the web page (Option 2)

```sh
make portal              # writes runs/index.html from the runs you just made
open runs/index.html
```

It shows the pipeline, the four diagrams, the commands, a table of the latest runs (verdict, witness,
time, links to each `report.html` and run folder), the last `make demo` table, the saved evaluation
numbers and a map of where everything is. It only reads files. Run `make portal` again after new runs
and refresh the browser.

---

## 1. The demo, in order (about 10 minutes)

| # | What to show | Command | Time | Expected |
|---|---|---|---|---|
| 1 | Bad fix, every stage, pausing after each | `python scripts/demo_steps.py --task ex1_saturate --candidate v3 --interactive` | ~20 s | REJECT E1, witness a=0, b=0 (P0 gives 0, P1 gives 255) |
| 2 | Correct fix of the same task | `python scripts/demo_steps.py --task ex1_saturate --candidate v1` | ~20 s | ACCEPT E2 |
| 3 | A subtle regression (tie-break) | `python scripts/demo_steps.py --task ex2_argmax --candidate v2 --interactive` | ~30 s | REJECT E1, all values INT_MAX, idx 0 vs 3 |
| 4 | HLSCheck fault that slipped past 264 tests | `python scripts/demo_steps.py --task benchmarks/project3/tasks/p3_sf_clamp16 --candidate candidate --config config/project3.toml` | ~20 s | REJECT E1: all inputs 254, P0 gives 254, P1 gives 255 |
| 5 | HLSCheck correct optimisation | `python scripts/demo_steps.py --task benchmarks/project3/tasks/p3_expanded_clamp16 --candidate optimized --config config/project3.toml` | ~20 s | ACCEPT E2 |
| 6 | All 9 demo cases in one table | `make demo` | 1 to 3 min | 9 of 9 rows match (checked 23 Nov: 95 s) |
| 7 | (optional, needs internet) readings written live by two LLMs | `python scripts/demo_steps.py --task ex1_saturate --candidate v3 --auto groq` | ~1 min | REJECT E1; prints the models' readings |
| 8 | Refresh the web page, show the new runs and saved results | `make portal`, refresh `runs/index.html` | 1 s | runs listed newest first |

Tips:
* `--interactive` waits for Enter after each stage, so you can explain while it is paused.
* `python scripts/demo_steps.py --list` lists every example task and its candidates.
* Step-by-step runs are saved under `runs/demo-steps/<task>/<candidate>/<run id>/`; `python -m vwe verify`
  saves under `runs/<task>/<candidate>/<run id>/`. Same files in both.
* Every run ends with a line `Full evidence: runs/.../report.html`. Cmd-click it in the VS Code
  terminal, or `open <path>`; it has every proof, both solvers' answers, the witness and both
  programs' outputs.
* Step 7 uses the Groq key in `config/secrets/groq.key` (git-ignored, never printed). If there is no
  internet, skip it: steps 1 to 6 are fully offline.

To check one candidate without the step-by-step printing:

```sh
python -m vwe verify examples/tasks/ex1_saturate --candidate v3      # one candidate
python -m vwe verify-all examples/tasks/ex2_argmax                    # every candidate of a task
```


---

## 1a. Four diagrams to keep open next to the terminal

Folder `docs/demo_diagrams/` (PNG, plus the TikZ source `diagrams.tex`):

| File | Use it when |
|---|---|
| `1_where_is_the_run.png` | while a run prints: match the `STEP n:` heading to its phase, its code file and its run folder |
| `2_inside_one_proof.png` | at a `Proof:` step: harness with P0 and P1 side by side, CBMC with SAT and Z3, witness, two confirmations |
| `3_verdict_rules.png` | at the `Verdict` step: why it is E0, E1, E2 or UNDECIDED |
| `4_repo_map.png` | when asked "where is the code / input / output?" |

## 1b. What the terminal shows, step by step (study this)

Real output of `python scripts/demo_steps.py --task ex1_saturate --candidate v3` (23 Nov, 22 s).
The left column is what appears; the right column is what to say.

| Terminal | What it means / what to point at |
|---|---|
| `STEP 1: Inputs` - P0, N, P1 (v3: `return 255u;`), caller profile | The three inputs. P1 is shown to us but never to any LLM. The caller profile is the input range we prove over (here all 8-bit values). Diagram 1, row 1. |
| `STEP 2: Interpretations of N` - strict and permissive, each `when a + b > 255: out_ret == 255`, `reach: a + b > 255` | Two readings of the English request. "when" is the change zone; outside it the strict reading says keep the old answer. Files: `examples/tasks/ex1_saturate/interpretations/`. |
| `STEP 3: Structural admission` - `status: ok` | Both programs parse, same signature, nothing unsupported (no new globals, no unknown calls). |
| `STEP 4: P0-only reference regions` - `exact UB region: false`, guard `!(false)` | Using P0 alone: where is P0 safe? Unsigned add never has undefined behaviour, so P0 is safe everywhere and can be the reference. |
| `STEP 5: Validate and freeze` - both `valid`, one equivalence class, `frozen set sha256` | Readings are checked on P0 before P1 is used, then hashed, so they cannot be changed after seeing P1. The two readings mean the same here, so only one needs checking. |
| `STEP 6: Proof: candidate safety` - `PROVED sat=success, z3=success` | E0: P1 adds no crash or undefined behaviour. Both solvers agree. Folder `e0/`. Diagram 2. |
| `STEP 7: Proof: reference on common keep region` - `PROVED` | P0 is deterministic where behaviour must be kept, so "same as P0" is well defined. Folder `e1_keep/`. |
| `STEP 8: Proof: pre-pass preservation hint` - `VIOLATED`, witness `a=0, b=0`, P0 `ret 0`, P1 `ret 255` | E1: a quick native test suggested an input, and both solvers proved it: 0+0 has no overflow, so the answer must stay 0, but v3 returns 255. Folder `prepass_e1/`. |
| `STEP 9: Proof: counterexample with fixed inputs 0` - `VIOLATED` | Confirmation 1: re-prove with a=0, b=0 fixed. Folder `fixed/0/`. |
| `STEP 10: Native witness replay` - `confirmed` | Confirmation 2: P0 and P1 compiled with ASan/UBSan and actually run on (0, 0): 0 vs 255. Folder `native/`. |
| `STEP 11: Verdict` - `REJECT E1`, `replayed natively: True`, `Full evidence: .../report.html` | Regression outside the change zone, so REJECT whatever N exactly meant. Diagram 3. Open the report. |

For the correct fix (`--candidate v1`) steps 1 to 7 are the same, then: `preservation or Ext outside scope
union` PROVED, `scope agreement` PROVED for both readings, `class path reachability` PROVED (the overflow
zone can really be reached, so the proof is not empty), `interpretation ... permissive` PROVED, then
`ACCEPT E2`. No witness, so no confirmation steps.

### What to check on the day (practice once before)

1. `cd` into the repo in the VS Code terminal and run `source .venv/bin/activate`.
2. `cbmc --version` prints 6.11.0 and `z3 --version` prints 5.4.1.
3. Run step 1 of the table; the verdict must be `REJECT E1` in about 20 s.
4. `make portal`, then open `runs/index.html`; the run just made is the first row.
5. Open the PNGs in `docs/demo_diagrams/` and the report PDFs in `docs/report/`.
6. If there is time before the meeting, run `make demo` once (1 to 3 minutes); 9 of 9 must match.

---

## 2. Where the main code is (`vwe/`)

The pipeline is `vwe/pipeline.py: verify()`. Each stage lives in its own file:

| Pipeline stage | File(s) | What it does |
|---|---|---|
| Load a task (hides answers) | `vwe/tasks.py` | reads `task.json`; `eval/` files are never visible to the pipeline |
| 1. Admission | `vwe/admission.py`, `vwe/views.py`, `vwe/c_frontend.py` | parses P0 and P1, same signature, supported C only, sim/synth build views |
| 2. Readings of the request | `vwe/contract/` (reading language), `vwe/interpret.py` + `vwe/llm/` (LLM generation) | handwritten JSON readings, or LLM-generated from P0 + request only (never P1) |
| 3a. Regions on P0 alone | `vwe/regions.py` | where P0 is safe and deterministic (the reference guard) |
| 3b. Validate and freeze readings | `vwe/validate.py` | checks V-G, V-1 to V-4; drops readings P0 already meets; freezes the set (hash) |
| 4. Proofs E0 / E1 / E2 | `vwe/obligations.py`, `vwe/proof_jobs.py`, `vwe/harness/` | builds the C harness (P0 and P1 side by side) for each proof |
| CBMC / Z3 / sanitizer calls | `vwe/tools/` (`cbmc.py` has the mandatory `BASE_FLAGS`) | every external tool call, with timeouts |
| 5. Confirmation | `vwe/replay.py` | re-proof with fixed inputs, compile and run with ASan/UBSan |
| 6. Verdict | `vwe/verdict.py` | the only place ACCEPT / REJECT / UNDECIDED is decided |
| 7. Report | `vwe/report.py` | `report.html` and `report.json` |
| Command line | `vwe/cli.py` (`python -m vwe ...`) | `verify`, `verify-all`, `interpret`, `stability` |
| Evaluation code | `vwe/eval/` | labels, mutants, baselines B1/B3/B4, metrics |

Settings: `config/default.toml` (bounds, timeouts), `config/benchmark.toml` (Chrysalis, K=4),
`config/project3.toml` (HLSCheck cases, K=32), `config/llm.toml` (model names).

---

## 3. Where the inputs and test cases are

### What one task looks like (input to the pipeline)

```
examples/tasks/ex1_saturate/
  p0.c                    the original buggy function (P0)
  request.txt             the English request (N)
  candidates/v1.c ...     AI-made new versions (P1), one file each
  interpretations/*.json  handwritten readings of the request (strict, permissive)
  task.json               function name, input bounds (caller domain), file list
  eval/                   the true answer (P_ref): used only for scoring, never by the pipeline
```

### All test sets

| Test set | Where | Size | How it was made |
|---|---|---|---|
| Golden examples | `examples/tasks/ex1_saturate` ... `ex7_build_views` | 7 tasks, 20 candidates | written by us from the 7 examples in the design draft; expected verdicts in `tests/golden/` |
| Demo cases | made by `scripts/demo.py` from the golden tasks | 9 cases | same tasks with smaller sizes (K=2) so each runs in under a minute |
| Unit and integration tests | `tests/` | 436 tests | `pytest`; `make test` |
| Chrysalis-HLS benchmark | `benchmarks/tasks/` (generated, git-ignored) | 20 tasks, 97 candidates | `scripts/fetch_benchmarks.py` + `scripts/adapt_chrysalis.py` from the public Chrysalis-HLS bugs; mutants by `scripts/gen_mutants.py`; labels by `scripts/label_candidates.py` |
| LLM readings for Chrysalis | `benchmarks/generated/<task>/generated_set.json` | 20 tasks | gpt-oss-120b and Qwen via Groq, from P0 + request only |
| HLSCheck (Approach-1) cases | `benchmarks/project3/tasks/` (generated, git-ignored) | 131 tasks, 181 candidates | `scripts/adapt_project3.py --handoff <unzipped Project3_Team.zip>` |

The two `benchmarks/.../tasks/` folders are not in git (they are generated). They exist on this
laptop. On a fresh clone, rebuild them with the commands in section 6.

---

## 4. Where results are stored

### A single run

Every run writes a new folder (`demo_steps.py` puts it under `runs/demo-steps/`):

```
runs/<task>/<candidate>/<run_id>/
  run_manifest.json      tool versions, file hashes, config used
  admission/             stage 1: admission.json, parsed P0 and P1
  interpretations/       stage 3b: validation.json, interpretation_set.json (frozen readings + hash)
  regions/               stage 3a: regions.json (P0-only safe / deterministic regions)
  e0/                    stage 4: new-undefined-behaviour proof: main.c harness + verification/
  e1/, e1_keep/          stage 4: preservation proof outside the change zone
  prepass_e1/            quick native hint, then proved formally
  fixed/0/               stage 5: re-proof with the witness inputs fixed
  native/                stage 5: replay.c, compiled drivers, witness-0.json (real outputs)
  report.json            stage 6/7: verdict, evidence class, witness, every proof
  report.html            the same, readable in a browser
```

Inside each `verification/` folder: `sat.command.json` and `z3.command.json` (the exact CBMC
command lines), `sat.json` / `z3.json` (the results), and the `.goto` files CBMC produced.
`runs/latest.json` points to the newest run. `runs/` is git-ignored scratch space.

### The demo
`make demo` writes `runs/demo/index.html` (a table linking to each case's `report.html`).
`make portal` writes `runs/index.html`, the demo web page that links to all recent runs.

### Committed results (what the report quotes)

| Result | File |
|---|---|
| Golden examples, 20/20 | `results/golden/golden_results.json`, `results/checkpoints/2026-11-23-t22/` |
| Chrysalis evaluation (VWE vs baselines) | `results/eval/summary.md`, `results/eval/errors.md`, raw rows `results/eval/raw.jsonl` |
| HLSCheck cases (181) | `results/eval_project3/summary.md`, per-case `results/eval_project3/joined.jsonl` |
| Live LLM readings vs handwritten | `results/auto_vs_handwritten_live.md` |
| Index of everything | `results/README.md`, `results/latest.json` |
| Reports and slides | `docs/report/` (VWE and HLSCheck PDFs and PPTX) |

---

## 5. Questions the professor may ask

**Does the LLM ever see the AI's new code (P1)?** No. Prompts are built only from
`vwe/llm/context.py: RequestContext`, which has no field for P1. `tests/test_llm_isolation.py`
fails if that changes.

**Which tool proves things?** CBMC 6.11, run twice per proof: once with its SAT solver and once with
Z3. Both must agree. The flags are fixed in `vwe/tools/cbmc.py: BASE_FLAGS`.

**How do you know a counterexample is real?** It is re-proved with the inputs fixed, then both
programs are compiled with ASan/UBSan and actually run on it (`runs/.../native/witness-0.json`).

**What if the solver times out?** The answer is UNDECIDED, with the reason. A timeout never becomes
ACCEPT or REJECT.

**What do E0, E1, E2 mean?** E0: P1 has new undefined behaviour where P0 was safe. E1: P1 changed
P0's behaviour outside the part the request allows to change. E2: P1 meets every surviving
reading (ACCEPT) or none of them (REJECT).

**How good is it?** No wrong decision in any evaluation. HLSCheck cases: 125 of 181 decided, all
125 agree with the labels. Chrysalis: 1 of 89 decided (correct); a tests-only checker made 41
wrong calls. The weakness is coverage: SAT timeouts on multiplication, and small bounds.

**Are results limited?** Yes: they hold for the declared input sizes (K) and value ranges in
`task.json`; no hardware area or latency is measured by VWE (HLSCheck does that).

---

## 6. Rebuild and re-run everything (long; not for the live demo)

```sh
make test                      # 436 tests (1 skipped: ESBMC, Linux only), about 10 min
make golden                    # 20 golden cases, about 3 min
python scripts/fetch_benchmarks.py && python scripts/adapt_chrysalis.py --limit 30
python scripts/gen_mutants.py --all --limit 4 && python scripts/label_candidates.py --all
make eval                      # Chrysalis evaluation, hours
python scripts/adapt_project3.py --handoff <unzipped Project3_Team.zip folder>
python scripts/eval_project3.py --jobs 3     # HLSCheck cases, about 4 hours
```

## 7. If something goes wrong during the demo

* `command not found: cbmc` - run from the repo root with the venv active; CBMC is in `/opt/homebrew/bin`.
* A run is slow - the laptop is busy; close other programs. Steps 1 to 5 each take under a minute.
* Groq error or no internet - skip step 7; everything else is offline.
* Want a clean `runs/` folder first - `make clean` deletes all of `runs/` (scratch only; committed
  results in `results/` are untouched).
