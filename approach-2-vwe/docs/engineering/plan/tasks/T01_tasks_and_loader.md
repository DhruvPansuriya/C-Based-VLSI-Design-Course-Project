# T01 — Task format, example task folders, loader with `eval_only` isolation

**Priority:** must · **Depends on:** T00 · **Effort:** about 1 day

## Goal

Every input to the tool is a **task folder**. The pipeline can see only the parts it is allowed to see.

## Task folder layout (create `examples/tasks/<task_id>/`)

```text
task.json                  # validated by schemas/task.schema.json
p0.c                       # buggy function (only the function + needed includes)
request.txt                # N (one or more variants listed in task.json)
candidates/<cid>.c         # P1 candidates (each defines the same function name as p0.c)
interpretations/*.json     # hand-written interpretations (Phase 1); validated by interpretation.schema.json
eval/p_ref.c               # evaluation only
eval/phi_ref.c             # evaluation only: a C predicate file  int phi_ref(<inputs>, <outputs>)
```

**Function naming convention.**

- Source files use the **real** function name (e.g. `add8`).
- The harness generator (T04) renames it to `p0_add8` and `p1_add8` with `-D` macros, or by textual renaming of the preprocessed view. Decide which in T02 and document it.
- The existing spike files already use `p0_`/`p1_` names; when converting them, strip the prefixes.

## Steps

1. **Convert the three existing examples** from `spikes/examples/` into `examples/tasks/ex1_saturate`, `ex2_argmax` and `ex4_sum`:
   - one candidate file per variant;
   - `request.txt` with the draft's wording;
   - hand-written interpretations: at least one strict and one permissive per task. For Example 4, add one interpretation with the $(n-1)$ shape so that V-G (T07) has something to discard.
2. **Write `eval/phi_ref.c` and `eval/p_ref.c`** for each.
3. **`vwe/tasks.py`:**
   - `load_full(path) -> FullTask`, for evaluation code only;
   - `load_pipeline_view(path) -> PipelineTask`, which contains **no** `eval_only` fields and **no** access to `eval/`;
   - validation against `task.schema.json`.
4. **Tests (`tests/test_tasks.py`):**
   - every task folder validates;
   - `PipelineTask` has no attribute or path pointing into `eval/` (check by introspection and by scanning all string fields).

## Acceptance criteria

```bash
pytest -q tests/test_tasks.py
python -c "from vwe.tasks import load_pipeline_view as L; t=L('examples/tasks/ex2_argmax'); print(t.function, len(t.candidates))"
# -> argmax 3
```

## Pitfalls

- Keep `task.json` paths relative to the task folder.
- Do not copy `P_ref` into any pipeline-visible file.
