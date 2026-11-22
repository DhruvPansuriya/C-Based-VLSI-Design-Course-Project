# T22 — Wrap-up: documentation, report, presentation material

**Priority:** must · **Depends on:** T11 (and T18 if done) · **Effort:** about 1.5 days

## Steps

1. **README.md:** the one-paragraph idea, a quick start (`make setup && make demo`), the repo layout and a link to `docs/DEMO_GUIDE.md`.
2. **`docs/IMPLEMENTATION_REPORT.md`:**
   - what was built, mapped to draft sections;
   - what works end to end, with commands;
   - results: the golden table, plus the eval summary if T18 ran;
   - **honest limitations:** what is mocked, what is not implemented, and the inconclusive rate;
   - deviations from the draft, each with a reason.
3. **Slides material:** `docs/slides/outline.md` with 10–12 slides: problem, idea, verdict and evidence classes, pipeline figure, one worked example (ex2 argmax), demo screenshot, results, limitations, next steps. (The slides themselves are made outside Codex.)
4. **Reproducibility check:** on a fresh clone in Docker, run `docker build -t vwe docker/ && docker run vwe make test demo` and confirm it passes. Record the output in `results/repro/`.
5. Tag the release `v0.1-course-demo`.

## Acceptance criteria

The fresh-clone Docker run passes `make test demo`. Every claim in the implementation report has a command or a file next to it.
