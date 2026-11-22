# Submission contents and evidence map

The local submission is a source-and-evidence package. Uploading it to the
course portal is left to the student; no external submission has been made.

| Project requirement | Evidence |
|---|---|
| LLM source-to-source optimization | 50 recorded pairs in `experiments/catalog.json`; 47 distinct original ASTs; full C and per-pair transformation dossiers |
| Develop a C-to-C checker | `hlscheck/hybrid.py`, shared frontend/product program, certified summaries, refinement and evidence replay |
| SMT backend | Z3 bit-vectors in the custom checker; Z3 explicitly selected in the ESBMC adapter |
| Show equivalence | 50 positive proofs, exported component dependencies and full SMT replay |
| Show rejection and debugging | 50 seeded controls, concrete witnesses and independent compiled replay |
| Show real area/delay/latency | 100 full hardware runs in `results/hls`, summarized in `results/submission` |
| Use existing work appropriately | Related-work discussion, PAST/ESBMC runs and preserved notices |
| Present the whole project | Updated report and HTML/PDF deck, speaking/viva notes, `scripts/demo_hybrid.py` and recorded experiment reports |
| Reproduce it | `run_submission.py`, pinned Python dependencies, HLS bootstrap and exact raw commands |

The portable `output/Project3_Submission.zip` excludes virtual environments,
large downloaded binaries, upstream repository clones, research PDFs and
temporary build files. `output/SUBMISSION_MANIFEST.json` lists every packaged
file with a SHA-256 hash. Source and recorded results remain directly available
outside the ZIP in this folder.

Before presenting, read `docs/PRESENTATION_NOTES.md` and run `scripts/demo.py` once.

The integrated algorithm's 239-pair baseline remains separate from the
29 larger-instance/60-second checks. See `results/hybrid/REPORT.md` and
`results/large/REPORT.md`. Run `scripts/demo_hybrid.py` for proof-level composition.
The 60-second limit is per solver/C invocation; complete runs may take longer.
The report deliberately states that proofs are for a restricted unsigned C
domain, that faults are seeded, and that hardware numbers are pre-layout
Nangate45 estimates. These qualifications are part of the result.

The presentation-authoring integration was unavailable in this tool session,
so the supplied slides are offline HTML and PDF. The PDFs were rendered and
visually inspected. An attempted live browser preview was blocked by the
computer-use app permission for Chrome; no claim of an in-browser visual check
is made.
