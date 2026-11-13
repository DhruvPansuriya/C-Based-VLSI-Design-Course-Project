# Public datasets for C-to-C equivalence evaluation

Checked on 2026-11-21. The datasets below are distinct from verification tools.

| Dataset | Contents | Fit for this project | Local status |
|---|---|---|---|
| [EqBench](https://github.com/shrBadihi/EqBench), MSR 2021 | Labeled equivalent/non-equivalent C and Java pairs; old/new files and JSON descriptors. The README advertises 147 Eq + 125 Neq cases. | Best first public correctness benchmark; much richer semantics than our initial uint32 HLS subset. | Downloaded; 247 old-version C records indexed, 246 complete source pairs; 14 currently adapter-compatible pairs evaluated. |
| [EquiBench](https://anjiang-wei.github.io/EquiBench-Website/), EMNLP 2025 | 2400 pairs across languages. Its C DCE subset has 400 pairs: 200 equivalent and 200 non-equivalent. | Useful harder extension. Inspected Csmith examples contain globals, multiple functions, structs and volatile state beyond our frontend. | Not downloaded. The small GitHub repository is evaluation code, not the dataset itself. |
| [HLStrans](https://arxiv.org/abs/2507.04315) | Paired original C/C++ and HLS implementations, with testbenches and synthesis annotations described in the paper. | Better suited to HLS transformation/QoR experiments than general equivalence classification. Do not treat simulation validation as formal ground truth. | Not downloaded; its Hugging Face listing reports about 2.08 GB. Revisit a small subset rather than downloading the entire dataset. |

EqBench and EquiBench are different datasets. Neither is the unrelated
emotional-intelligence benchmark called EQ-Bench.

## How to use the datasets fairly

Keep two evaluation tracks:

1. **Verifier correctness and coverage:** use public labeled program pairs,
   preserve their language semantics and explicit input assumptions, and
   report unsupported, safety-violating and inconclusive cases separately.
2. **HLS usefulness:** use synthesizable kernels and recorded LLM rewrites,
   establish equivalence under a stated contract, then measure hardware QoR
   under common synthesis settings.

A large public C dataset is not automatically synthesizable. Conversely,
MachSuite/CHStone/HLSFactory kernels are useful HLS workloads but generally do
not provide a ready-made set of labeled equivalent/non-equivalent C pairs.
Our initial hand-built controls remain useful regression tests; they do not
replace external evaluation.

Do not convert signed dataset programs to unsigned just to fit our interpreter.
Do not add small input ranges and report the resulting conditional proof as
equivalence over the original full domain. If a derived subset or a restricted
domain is used, record it as a separate experiment.

## EqBench snapshot and current findings

Location: `datasets/EqBench`.
Commit: `3724fce5b287cc63165028444daf904f25b0158b`.
License: MIT, retained in `datasets/EqBench/LICENSE.md`.
Current working-tree source size: approximately 2.13 MiB, excluding Git metadata.

Run:

```powershell
.\.venv\Scripts\python.exe scripts/run_eqbench.py --audit-only
.\.venv\Scripts\python.exe scripts/run_eqbench.py --limit 14 --timeout-ms 3000 --max-unroll 32
.\.venv\Scripts\python.exe scripts/write_eqbench_report.py
```

The first run indexes every available old/new record, hashes sources and
records all exclusions. The evaluation runs all 14 current eligible pairs:
2 equivalent verdicts, 9 incomplete-unwind results, and 3 unknown results.
Both conclusive verdicts agree with the labels; most of the dataset remains
outside the supported interface. These results are not a high overall accuracy
claim. They identify the concrete need for richer input handling and stronger
loop reasoning. See `results/eqbench/REPORT.md` for the full account.

The dataset also has an [open report of disputed C labels](https://github.com/shrBadihi/EqBench/issues/15),
including signed-overflow and NaN-related cases. Preserve the published labels
and audit disagreements against their precise semantics rather than assuming
either the dataset or our checker must be correct.

## Sources

- [EqBench authors' repository and citation](https://github.com/shrBadihi/EqBench).
- [EqBench paper](https://people.ece.ubc.ca/mjulia/publications/EQBench_2021.pdf).
- [EquiBench official dataset statistics](https://anjiang-wei.github.io/EquiBench-Website/).
- [EquiBench C data preview](https://huggingface.co/datasets/anjiangwei/EquiBench-Datasets).
- [HLStrans authors' repository](https://github.com/NuoJohnChen/C2HLS).
- [HLStrans data listing](https://huggingface.co/datasets/qingyun777yes/HLStrans).
