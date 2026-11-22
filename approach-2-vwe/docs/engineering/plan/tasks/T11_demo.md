# T11 — Professor demo (`make demo`) and demo guide

**Priority:** must · **Depends on:** T10 · **Effort:** about 1 day · **Milestone M2**

## Goal

In about 5 minutes, without network access, show what the project proposes and that the implementation works.

## Steps

1. **`scripts/demo.py`** (and `make demo`). It runs `vwe verify` on a curated list of 8 to 10 cases and prints a coloured table (use ANSI codes only; no new dependency):

| Case | Shows |
|---|---|
| ex1 v1 (correct saturation) | ACCEPT E2 |
| ex1 v3 (always 255) | REJECT E1: "passes the narrow property, breaks everything else" |
| ex2 v2 (tie-break regression) | REJECT E1: caught **without** any spec of tie-breaking |
| ex2 v3 (reads `a[n]`) | REJECT E0 + native ASan replay |
| ex4 v1 / v2 | shape as interpretation: correct fix accepted, `a[n]` rejected |
| ex5 error-code | UNDECIDED (ambiguous), with the disagreement input |
| ex7 | REJECT E0: build-view mismatch |
| spike T03 (abort) | "without our defence: SUCCESS; with it: caught" (side by side) |

   It also writes `runs/demo/index.html`, linking to every report.
2. **`docs/DEMO_GUIDE.md`:** a one-page script for presenting. For each case: the problem in plain words, what naive approaches would say (equivalence check, narrow property, LLM-judge), what VWE says and why. Add a final slide-style summary of the evidence classes.
3. **Timing:** each case should run within 60 s on a laptop. If one does not, reduce `K` for the demo config (`config/demo.toml`) and state it on screen.

## Acceptance criteria

```bash
time make demo     # < 5 min, all rows show the expected verdicts, index.html exists
```
