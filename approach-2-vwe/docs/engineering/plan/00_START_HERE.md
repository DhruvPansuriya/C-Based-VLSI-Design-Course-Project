# START HERE — implementation plan for Codex

You are implementing **Verdicts with Evidence (VWE)**: a tool that takes

- a buggy C function `P0`,
- a natural-language fix request `N`, and
- an AI-revised function `P1`,

and returns **ACCEPT / REJECT / UNDECIDED** with an evidence class (E0/E1/E2), a witness input and a report.

**The professor's emphasis:** a clear idea *and* working code that demonstrates it. Every task below therefore ends in something that **runs**, and the plan is ordered so that a complete, demonstrable tool exists early (end of Phase 2). The tool is then made automatic (Phase 3), evaluated (Phase 4) and extended (Phase 5).

## Read these first, in this order (about 45 minutes)

1. `README.md`: what already runs.
2. `docs/research/Verdicts_with_Evidence_Final_Draft.md`: the method. Read §4–§7 and §9 carefully; skim the rest.
3. `docs/technical-design/01_review_of_final_draft.md`: tool facts **verified by running CBMC 6.11.0 / ESBMC 8.7.0**. Several of them correct the draft. When the draft and the review disagree, the review wins.
4. `docs/technical-design/02_technical_design_document.md`: architecture, interfaces, flags, testing.
5. `evaluation/tool_spikes/README.md`, plus `scripts/run_golden_examples.py`: the working prototype you will generalise.
6. `CONTRIBUTING.md`: rules you must follow in this repository.
7. `docs/engineering/plan/01_PLAN.md`: phases, milestones, demo definition.
8. `docs/engineering/plan/tasks/`: one file per task, in order.

## How to work

- Do tasks **in numeric order** unless a task says it can run in parallel. Each task lists its dependencies.
- Each task has **acceptance criteria with exact commands**. A task is done only when all of them pass and `make test` is green.
- Commit after each task: `git commit -m "T07: <summary>"`. Keep commits small.
- If a task needs a fact you cannot verify (a tool flag, a version, a link), **do not invent it**. Write it in `docs/engineering/plan/OPEN_QUESTIONS.md` and continue with the documented fallback.
- Never weaken a soundness rule to make a test pass. If a golden expectation looks wrong, record why in `docs/engineering/plan/OPEN_QUESTIONS.md` and ask.

## Environment (verified on Ubuntu 24.04)

```bash
tools/install_tools.sh        # CBMC 6.11.0, ESBMC 8.7.0, Z3 5.4.1 (pinned)
export PATH=/opt/cbmc/usr/bin:/opt/esbmc/release/bin:$PATH
pip install -r requirements.txt
make test                     # added in T00
```

LLM API keys are **not** needed until Phase 3. Phases 1–2 use hand-written interpretations and a deterministic mock LLM.
