#!/usr/bin/env python3
"""Run hand-derived expectations through the public verification pipeline."""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from vwe.pipeline import verify
from vwe.schemas import validate
from vwe.tools import cbmc


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, default=ROOT / 'runs/golden')
    parser.add_argument('--workers', type=int, choices=range(1, 5), default=3)
    args = parser.parse_args()
    if not cbmc.cbmc_available():
        print('cbmc not found on PATH; see tools/install_tools.sh', file=sys.stderr)
        return 2
    expected = json.loads((ROOT / 'tests/golden/expected.json').read_text())
    cases = [(task, variant, want) for task, variants in expected.items()
             if not task.startswith('_') for variant, want in variants.items()]
    args.out.mkdir(parents=True, exist_ok=True)

    def check(case: tuple[str, str, list[str]]) -> dict:
        task, variant, want = case
        report = verify(ROOT / 'examples/tasks' / task, 'v' + variant,
                        runs_root=args.out, parallel=False)
        validate('verdict_report', report.data)
        got = [report.decision, report.evidence_class]
        return {'example': task, 'variant': variant, 'expected': want, 'got': got,
                'match': got == want, 'reason': report.data['reason'],
                'witness': report.data['witness'], 'report': str(report.folder / 'report.json')}

    with ThreadPoolExecutor(max_workers=args.workers) as workers:
        rows = list(workers.map(check, cases))
    for row in rows:
        print(f"{row['example']:24s} v{row['variant']}: "
              f"expected {' '.join(row['expected']):12s} got {' '.join(row['got']):12s} "
              f"{'OK' if row['match'] else 'MISMATCH'}  {row['reason']}", flush=True)
    (args.out / 'golden_results.json').write_text(json.dumps(
        {'cbmc_version': cbmc.version(), 'pipeline': 'vwe.pipeline.verify', 'rows': rows},
        indent=2) + '\n')
    return int(any(not row['match'] for row in rows))


if __name__ == '__main__':
    sys.exit(main())
