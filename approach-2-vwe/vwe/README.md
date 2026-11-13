# vwe/ - the VWE source code

This is the Python package that does the checking. `pipeline.py` runs the stages in order and
every stage has its own file.

| File or folder | Stage | What it does |
|---|---|---|
| `admission.py`, `c_frontend.py`, `views.py` | 1 | parse P0 and P1 (normal and `__SYNTHESIS__` views), refuse unsupported code |
| `interpret.py`, `llm/` | 2 | load readings of the request, or ask an LLM for them (P0 and N only, never P1) |
| `regions.py` | 3a | find where P0 is safe and deterministic (the reference guard) |
| `validate.py` | 3b | checks V-G, V-1 to V-4 on each reading, then group and freeze them |
| `harness/` | 4 | write the C harness that runs P0 and P1 side by side |
| `contract/` | 4 | the small reading language: grammar, type checker, translation to C |
| `obligations.py`, `proof_jobs.py`, `tools/` | 4 | run CBMC (SAT and Z3), goto-cc, goto-instrument, ESBMC |
| `replay.py` | 5 | re-prove with fixed inputs, then compile with ASan/UBSan and run the witness |
| `verdict.py` | 6 | the fixed rule table: ACCEPT, REJECT or UNDECIDED with E0, E1 or E2 |
| `report.py` | 7 | write `report.json` and `report.html` |
| `eval/` | - | baselines, labelling and metrics used only for the evaluation |
| `cli.py`, `__main__.py` | - | the `python -m vwe` command line |
| `config.py`, `schemas.py`, `tasks.py` | - | settings, JSON schemas and task loading |

Command line:

```sh
python -m vwe verify examples/tasks/ex1_saturate --candidate v3   # one candidate
python -m vwe verify-all examples/tasks/ex1_saturate              # every candidate of a task
python -m vwe interpret examples/tasks/ex1_saturate               # only generate readings
```
