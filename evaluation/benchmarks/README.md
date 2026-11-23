# evaluation/benchmarks/

| Path | What it is |
|---|---|
| `generated/<task>/` | readings of each Chrysalis-HLS request written by the LLMs (gpt-oss-120b and Qwen), with the full call log |
| `adaptation_log.json` | how each Chrysalis-HLS bug was turned into a task |
| `labels_summary.json` | the label of every candidate (correct or not) |
| `ref_check.json`, `ref_check.log` | check that every reference fix passes |
| `project3/adaptation_log.json` | how the HLSCheck (Approach-1) cases were turned into tasks |

The task folders themselves (`tasks/` and `project3/tasks/`) are generated, so they are not in git.
Rebuild them with:

```sh
python scripts/fetch_benchmarks.py && python scripts/adapt_chrysalis.py      # tasks/
python scripts/adapt_project3.py --handoff ../approach-1-hlscheck            # project3/tasks/
```
