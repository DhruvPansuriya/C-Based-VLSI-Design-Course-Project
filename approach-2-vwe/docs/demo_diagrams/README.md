# Demo diagrams

Four PNGs to keep open next to the terminal during the live demo (see `docs/LIVE_DEMO.md`, section 1a):

1. `1_where_is_the_run.png`: each `STEP n:` heading printed by `scripts/demo_steps.py`, its pipeline
   phase, its code file and the folder it writes in the run directory.
2. `2_inside_one_proof.png`: one proof (E1 on saturating add v3): harness, CBMC with SAT and Z3,
   the witness a=0, b=0, then the two confirmations.
3. `3_verdict_rules.png`: the order of the verdict checks (E0, E1, E2, UNDECIDED) with the demo cases.
4. `4_repo_map.png`: inputs, code, per-run outputs and saved results.

They are also shown on the demo web page (`make portal`, then open `runs/index.html`).

Rebuild after editing `diagrams.tex`:

```sh
cd docs/demo_diagrams && tectonic diagrams.tex
python -c "import fitz; d=fitz.open('diagrams.pdf'); n=['1_where_is_the_run','2_inside_one_proof','3_verdict_rules','4_repo_map']; [p.get_pixmap(dpi=200, alpha=False).save(n[i]+'.png') for i,p in enumerate(d)]"   # needs pymupdf
```
