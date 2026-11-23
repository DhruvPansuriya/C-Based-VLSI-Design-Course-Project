"""Write the larger-instance study, keeping budgets and unresolved cases explicit."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json

ROOT=Path(__file__).resolve().parents[1]


def main():
    summary=json.loads((ROOT/'results/large/summary.json').read_text())
    assert summary['total']==29 and summary['all_available_evidence_passed']
    lines=['# Larger C-to-C checks with a 60-second solver budget', '',
        'The integrated checker now defaults to **60,000 ms per SMT check or C-verifier invocation**. Frontend work and expression construction add time, and a case can issue several obligations or refinements. This is not a 60-second total wall-clock cap per source pair.', '',
        'The 10-second integrated baseline is retained under `results/hybrid/`. Its exact implementation is preserved in `experiments/checker_versions/`. This study uses separate sources/results and records the larger budget for every invocation.', '',
        'There are 27 dimension-scaled educational kernel pairs and two retries of identical previously inconclusive source pairs. The size variants share algorithms and are not independent applications or newly sampled Qwen responses. All original/candidate C and deliberate fault definitions are saved under `benchmarks/large/`. These are **checker-scaling experiments**; no new HLS area/delay/latency measurements are claimed.', '',
        '| Formal outcome | Pairs |', '|---|---:|']
    for status,count in summary['counts'].items():lines.append(f'| {status} | {count} |')
    lines += ['', f"All available SMT dependency replays and native mismatch checks pass. There are {summary['contradictory_conclusive_verdicts']} contradictory conclusive verdicts. Inconclusive outcomes remain unresolved; their expected labels are not substituted for checker results.", '',
        '## What the extra budget resolves', '',
        '| Same source pair | Earlier budget/result | New result | Total measured time |', '|---|---|---|---:|']
    for row in summary['cases']:
        if row['family']=='budget_retry':
            lines.append(f"| {row['id']} | {row['previous_timeout_ms']/1000:g} s / {row['previous_status']} | {row['status']} | {row['elapsed_seconds']:.3f} s |")
    lines += ['', 'The range8 retry is an actual retained Qwen output. The initial local-model evaluation had 28 equivalent outputs; this later proof raises the number established equivalent across all runs to 29 of the same 40 attempts. Nineteen remain unchanged, so ten outputs now have verified code changes. Hardware measurements still cover the initial nine changed outputs; the newly proved range8 rewrite has no additional QoR measurement in this study.', '',
        '## Successful larger instances', '',
        '| Family | Largest proved instance | Work in original | Total measured time |', '|---|---|---|---:|']
    for family in ('gemm','indexed_gemm','prefix','dot','fir','stencil','correlation'):
        rows=[r for r in summary['cases'] if r['family']==family and r['status']=='equivalent']
        row=max(rows,key=lambda r:r['scale'])
        size=str(row['scale'])+' x '+str(row['scale']) if family in ('gemm','indexed_gemm','stencil') else str(row['scale'])+' elements'
        lines.append(f"| {family} | {size} | {row['dominant_operations_original']} principal terms/operations | {row['elapsed_seconds']:.3f} s |")
    lines += ['', 'The 16 x 16 GEMM contains 4,096 multiply-accumulate terms, compared with 64 in the earlier 4 x 4 example. The 128-element prefix reference performs 8,256 additions. Each admitted unsigned data word ranges over its full 32-bit domain; these are symbolic proofs, rather than tests of one large input. Interface-word counts include initial output-buffer contents even when those contents are later overwritten.', '',
        'The static-loop proofs benefit from symbolic execution and modular polynomial normalization; their residual C checks use certified shared poststates. Larger array dimensions alone do not predict SMT difficulty. The indexed correlation and input-dependent-loop cases exercise different, harder relations.', '',
        '## Unresolved cases', '',
        '| Case | Expected relationship | Observed | Total measured time |', '|---|---|---|---:|']
    for row in summary['cases']:
        if row['status'] in ('inconclusive','unsupported','error'):
            lines.append(f"| [{row['id']}]({row['id']}/evaluation.json) | {row['expected']} | {row['status']} | {row['elapsed_seconds']:.3f} s |")
    lines += ['', 'The matrix fault transposes an input access; its inconclusive result is not an equivalence verdict. The 16-element correlation case still needs a stronger or longer residual proof. Both dynamic sums have explicit unchanged preconditions `0 <= n <= capacity`; they are not proofs over unrestricted `n`.', '',
        'We also retried the dynamic loops with smaller contract-derived unwinding caps while retaining all unwinding assertions. The input domains were unchanged. Both remained inconclusive:', '',
        '| Case | Previous cap | Retry cap | Result |', '|---|---:|---:|---|']
    loop=json.loads((ROOT/'results/loop_budget/summary.json').read_text())
    for row in loop['cases']:
        lines.append(f"| {row['id']} | {row['previous_max_unroll']} | {row['max_unroll']} | {row['status']} |")
    lines += ['', 'These outcomes identify a limitation in relational reasoning about symbolic loop counts; simply increasing time or changing an expansion cap does not guarantee a proof. No bounds, pointer, overflow, shift, uninitialized or unwinding checks were disabled.', '',
        '## Reproduce', '', '```powershell',
        r'.\.venv\Scripts\python.exe -m hlscheck original.c candidate.c --function kernel --output-dir results/my_check',
        r'.\.venv\Scripts\python.exe scripts/run_large_study.py --timeout-ms 60000',
        r'.\.venv\Scripts\python.exe scripts/run_loop_budget_study.py',
        r'.\.venv\Scripts\python.exe scripts/validate_large_evidence.py', '```', '',
        'The recorded implementation versions are matched by hashes against current or archived source modules when evidence is replayed. Current admission checks additionally reject context-dependent preprocessor builtins, string storage and floating-point constants outside the integer model. The archived runs use numeric integer kernels, which are unaffected by those additional admission exclusions.', '',
        '## Complete ledger', '', '| Case | Scale | Outcome | Wall time |', '|---|---:|---|---:|']
    for row in summary['cases']:
        lines.append(f"| [{row['id']}]({row['id']}/evaluation.json) | {row['scale']} | {row['status']} | {row['elapsed_seconds']:.3f} s |")
    (ROOT/'results/large/REPORT.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print('Wrote larger-instance report for',summary['total'],'pairs.')


if __name__=='__main__':main()
