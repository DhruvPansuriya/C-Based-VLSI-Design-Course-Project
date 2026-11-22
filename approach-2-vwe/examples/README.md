# examples/ - the hand-made example tasks

These are the inputs used in the demo and in the golden tests. Each task folder has:

| File | What it is |
|---|---|
| `p0.c` | the original buggy function (P0) |
| `request.txt` | the change request in English (N) |
| `candidates/` | candidate new versions (P1), some correct and some wrong |
| `interpretations/` | handwritten readings of the request (strict, permissive, ...) |
| `task.json` | function name, input ranges and buffer sizes, list of candidates |
| `eval/` | the reference answer, used only for scoring, never shown to the pipeline |

| Task | What it tests |
|---|---|
| `ex1_saturate` | 8-bit add that should saturate at 255 instead of wrapping |
| `ex2_argmax` | argmax on an empty array; v2 breaks the tie order (REJECT E1) |
| `ex3_avg_half_away` | round averages half away from zero |
| `ex4_sum` | fix an off-by-one so the sum covers all n elements |
| `ex5_add32_ambiguous` | "handle overflow" without saying how; a candidate that fits only one reading gets UNDECIDED |
| `ex6_copy_overflow` | fix a buffer overflow in a copy and keep normal copies the same |
| `ex7_build_views` | restructure for HLS without changing behaviour, including the `__SYNTHESIS__` build |

Run one: `python scripts/demo_steps.py --task ex1_saturate --candidate v3`
