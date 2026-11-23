# evaluation/sample_runs/

One complete run from the live demo, kept so the output can be read without running anything.

`ex1_saturate_v3_reject/` comes from:

```sh
python scripts/demo_steps.py --task ex1_saturate --candidate v3
```

The candidate always returns 255. VWE answers REJECT E1 with the witness a = 0, b = 0
(P0 returns 0, P1 returns 255), confirmed by a re-proof and a real run.

| Path | Stage | What is inside |
|---|---|---|
| `run_manifest.json` | 1 | input hashes, tool versions, settings |
| `admission/` | 1 | `admission.json`, parsed copies of P0 and P1 |
| `regions/` | 3a | `regions.json` with the reference guard, one proof folder per check |
| `interpretations/` | 3b | `validation.json`, the frozen `interpretation_set.json`, one folder per check |
| `e0/` | 4 | E0 harness (`main.c`, `a0.c`, `a1.c`, `frame.h`) and `verification/` |
| `e1_keep/` | 4 | proof that P0 is deterministic |
| `e1/`, `prepass_e1/` | 4 | E1 harness; `prepass_e1/verification/` has the CBMC commands and SAT/Z3 results |
| `fixed/0/` | 5 | the witness with fixed inputs, proved again |
| `native/witness-0.json` | 5 | the real outputs of P0 and P1 on the witness |
| `report.json`, `report.html` | 6, 7 | the verdict and all the evidence |

Compiled binaries and `.goto` files were left out to keep the folder small, and local paths were
shortened.
