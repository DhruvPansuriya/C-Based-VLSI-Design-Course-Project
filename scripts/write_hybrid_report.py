"""Summarize the integrated algorithm's own runs, keeping legacy runs separate."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json

ROOT=Path(__file__).resolve().parents[1]


def main():
    study=json.loads((ROOT/'results/hybrid/study/summary.json').read_text())
    ablation=json.loads((ROOT/'results/hybrid/ablation/summary.json').read_text())
    assert study['total']==239, 'Finish the full integrated study before building its report'
    assert study['all_accepted_smt_replays_passed'] and study['all_available_native_witnesses_passed']
    lines=['# Integrated relational-summary/refinement checker', '',
        'The default HLSCheck command now implements proof-level composition. Custom symbolic/Z3 region proofs justify state summaries inside one C product program; ESBMC/Z3 verifies its residual behavior. A coarse counterexample is refined before it can become a final mismatch or safety verdict. This is an implementation of established compositional verification and abstraction/refinement ideas, not a claim of a first-ever algorithm.', '',
        'The code and proof rules are explained in [the algorithm document](../../docs/INTEGRATED_ALGORITHM.md). The initial standalone/fallback experiments remain unchanged elsewhere in the repository. All figures below come from separately executed integrated-algorithm runs.', '',
        '## Evaluation scope', '',
        '| Cohort | Equivalent | Non-equivalent | Undefined C | Unsupported | Inconclusive |',
        '|---|---:|---:|---:|---:|---:|']
    for name,counts in study['cohort_counts'].items():
        lines.append('| '+name+' | '+' | '.join(str(counts.get(k,0)) for k in ('equivalent','not_equivalent','undefined_behavior','unsupported','inconclusive'))+' |')
    lines += ['', f"There are {study['total']} checked pairs. {study['matched_known_labels']}/{study['known_labels']} previously established labels match. The two formerly unsupported/unknown local-model attempts have no required correctness label; their observed new statuses are retained. These cohorts reuse selected cases and are not independent application samples.", '',
        f"The algorithm accepts relational summaries in {study['accepted_summaries']} cases and performs refinement in {study['refined_cases']}. All accepted SMT dependencies replay successfully. All {study['available_native_witnesses']} available complete mismatch inputs reproduce a difference in compiled original/candidate C. Undefined-C and abstract-state traces are not executed as native witnesses. One known equivalent mixed example is inconclusive at the recorded limit; there are no contradictory conclusive verdicts.", '',
        '## What actually combines the methods', '',
        'A region lemma proves equality and modelled safety of both prefixes over their full admitted domain. The C product shares an arbitrary prefix poststate and verifies the suffixes. If that overapproximation loses correlations, the symbolic engine emits an exact summary, proves its C encoding against the real region, and rebuilds the residual C check. If a summary cannot be certified, original C remains in the product. Function-exit summaries include returns as well as array contents.', '',
        'A complete symbolic counterexample can also guide the C engine: the actual unabstracted pair is checked at that input. A confirmed mismatch is concrete. If the input happens to agree, the method discards it and verifies the unrestricted input domain; it never interprets agreement at one input as a universal proof.', '',
        '## Targeted comparison with standalone methods', '',
        '| Example | Standalone symbolic | Monolithic C / Z3 | Combined method | Combined wall time |',
        '|---|---|---|---|---:|']
    for row in ablation['cases']:
        lines.append(f"| {row['id']} | {row['standalone_symbolic']['status']} | {row['monolithic_bmc']['status']} | {row['hybrid_status']} | {row['hybrid_elapsed_seconds']:.3f} s |")
    lines += ['', 'The GEMM example first computes a reduced unsigned-32 matrix product using different loop organizations, then returns a result through a symbolic index. The symbolic engine proves the loop relation but rejects the symbolic array read. Monolithic C checking does not resolve that example within the tested limit. The combined proof uses the certified loop relation to leave a much smaller indexed-read problem for the C engine.', '',
        'The array-correlation example compares a stored result with recomputation from its input. Shared arbitrary arrays initially admit an unreachable mismatch. The exact summary restores the source relationship. Its four-element version is proved in the unit tests and live demo; the eight-element benchmark remains inconclusive at the recorded 10-second C-process limit. A deliberately wrong suffix remains non-equivalent after refinement and its witness is reproduced in actual C.', '',
        'These are targeted constructions and one measured run per method, not a statistical benchmark or a uniform speedup claim. The combined method can issue multiple obligations. Solver limits apply to individual SMT checks, and the C process has a per-invocation wall-clock limit; frontend work and expression construction add time. An equal total budget is not claimed. Some simple examples are faster monolithically.', '',
        '## New implementation and retained upstream code', '',
        '| Component | Project implementation |', '|---|---|',
        '| Shared typed frontend | `hlscheck/frontend.py`: preprocessing, typedefs, primitive ranks, ILP32 contract, C semantic checks |',
        '| Region reasoning | `hlscheck/relational.py`: cut boundaries, local liveness, state effects, generated summaries |',
        '| Product construction | `hlscheck/miter.py`: independent memories, common inputs, state abstraction and concrete-witness products |',
        '| Combined algorithm | `hlscheck/hybrid.py`: proof dependencies, refinement, one final verdict |',
        '| Evidence checking | `hlscheck/evidence.py`: accepted-lemma replay and actual-C witness execution |',
        '| Reused engines | Existing project symbolic interpreter/Z3 plus unmodified ESBMC 8.7 / bundled Z3 |', '',
        'ESBMC is not relabelled as independently written code. The shared frontend now admits signed/unsigned primitive integers through 64 bits and isolated integer typedefs/macros. The custom symbolic summary engine remains unsigned-32; other regions can remain opaque in the same C product. Function calls, globals, arbitrary pointer interfaces, aggregate state and general floating point remain outside the shared frontend.', '',
        '## Reproduce', '', '```powershell',
        r'.\.venv\Scripts\python.exe scripts/demo_hybrid.py',
        r'.\.venv\Scripts\python.exe -m hlscheck original.c candidate.c --function kernel --output-dir results/my_check',
        r'.\.venv\Scripts\python.exe scripts/run_hybrid_study.py --ablation',
        r'.\.venv\Scripts\python.exe -m pytest -q', '```', '',
        'Each checked pair has input/canonical C, a common contract, region/encoding SMT queries, residual C, engine logs, raw traces and source/implementation/artifact hashes. `study/summary.json` contains every outcome. `ablation/summary.json` contains the standalone comparisons. Proof evidence depends on every listed accepted lemma; the last residual query alone is insufficient.', '',
        '## Unresolved outcomes and differences', '',
        '| Case | Previous/expected | Observed |', '|---|---|---|']
    for row in study['cases']:
        if row['status'] in ('inconclusive','unsupported','error') or row['matched_expected'] is False:
            lines.append(f"| [{row['id']}](study/{row['id']}/evaluation.json) | {row.get('previous_status') or row.get('expected')} | {row['status']} |")
    (ROOT/'results/hybrid/REPORT.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print('Wrote integrated algorithm report for',study['total'],'pairs.')


if __name__=='__main__':
    main()
