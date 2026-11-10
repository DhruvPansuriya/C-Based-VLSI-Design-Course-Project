#!/usr/bin/env python3
"""Run the bounded professor demo offline and publish a local report index."""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
from html import escape
import json
import os
from pathlib import Path
import shutil
import sys
from time import monotonic
from uuid import uuid4

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from vwe.config import Config, load_config
from vwe.pipeline import verify
from vwe.report import write_json
from vwe.tools import cbmc, goto

CASES = (
    ('ex1_saturate', 'v1', 'ACCEPT', 'E2', 'Correct saturation'),
    ('ex1_saturate', 'v3', 'REJECT', 'E1', 'Always 255 breaks ordinary sums'),
    ('ex2_argmax', 'v2', 'REJECT', 'E1', 'Tie-break regression'),
    ('ex2_argmax', 'v3', 'REJECT', 'E0', 'New out-of-bounds read + native replay'),
    ('ex4_sum', 'v1', 'ACCEPT', 'E2', 'Include the final element'),
    ('ex4_sum', 'v2', 'REJECT', 'E0', 'Read one past the exact buffer'),
    ('ex5_add32_ambiguous', 'v2', 'UNDECIDED', '-', 'Overflow readings disagree'),
    ('ex7_build_views', 'v1', 'REJECT', 'E0', 'Simulation and synthesis disagree'),
)


def prepare_task(task: str, destination: Path, bound: int) -> dict:
    """Materialize an explicitly reduced caller profile for this demo run."""
    shutil.copytree(ROOT / 'examples/tasks' / task, destination)
    manifest = destination / 'task.json'
    data = json.loads(manifest.read_text())

    def bounded(shape: dict) -> None:
        for name, limits in shape.get('bounds', {}).items():
            if limits[0] > bound:
                raise ValueError(f'{task}: minimum {name} exceeds demo K')
            limits[1] = min(limits[1], bound)

    bounded(data['caller_domain'])
    data['source'].setdefault('adaptations', []).append(f'Demo-only size bounds capped to K={bound}.')
    manifest.write_text(json.dumps(data, indent=2) + '\n')
    for name in data['interpretations']:
        path = destination / name
        interp = json.loads(path.read_text())
        bounded(interp['shape'])
        path.write_text(json.dumps(interp, indent=2) + '\n')
    return data['caller_domain']


def path_cut_demo(out: Path, cfg: Config) -> dict:
    """Compare the unprotected library model with the audited path-cut trap."""
    started = monotonic()
    out.mkdir(parents=True)
    source = out / 'harness.c'
    shutil.copyfile(ROOT / 'spikes/tool_behaviour/t03_abort/harness.c', source)
    naive = cbmc.run([str(source)], timeout_s=cfg.timeouts.cbmc_s)
    (out / 'unprotected.json').write_text(naive.stdout)
    write_json(out / 'unprotected.command.json', {'argv': naive.command, 'ok': naive.ok,
               'status': naive.status, 'returncode': naive.returncode, 'stderr': naive.stderr_tail})
    checked = goto.prepare((source,), out / 'instrumented', timeout_s=cfg.timeouts.cbmc_s)
    protected = {}
    if checked.ok:
        for backend in ('sat', 'z3'):
            result = cbmc.run([str(checked.artifact)], backend=backend,
                              extra=('--no-library',), timeout_s=cfg.timeouts.cbmc_s)
            (out / f'{backend}.json').write_text(result.stdout)
            write_json(out / f'{backend}.command.json', {'argv': result.command, 'ok': result.ok,
                       'status': result.status, 'returncode': result.returncode, 'stderr': result.stderr_tail})
            protected[backend] = result.ok and result.status == 'failure' and any(
                p.description == 'undefined function should be unreachable' for p in result.failed())
    ok = naive.ok and naive.status == 'success' and all(protected.values()) and len(protected) == 2
    elapsed = monotonic() - started
    report = out / 'report.html'
    report.write_text('<!doctype html><meta charset="utf-8"><title>Path-cut defence</title>'
                      '<h1>Path-cut defence</h1><p>Unprotected library model: '
                      + escape(naive.status) + '</p><p>Audited SAT/Z3 trap: '
                      + escape(json.dumps(protected)) + '</p><p>This comparison illustrates a '
                      'vacuous proof; it is not a repair acceptance.</p>')
    row = {'label': 'Abort path-cut defence', 'decision': 'DEMONSTRATED' if ok else 'UNRESOLVED',
           'evidence_class': '-', 'match': ok, 'seconds': elapsed,
           'reason': 'Unprotected SUCCESS; audited SAT/Z3 trap caught the path cut' if ok else checked.reason,
           'report': str(report), 'unprotected': naive.status, 'protected': protected}
    write_json(out / 'comparison.json', row)
    return row


def write_index(destination: Path, rows: list[dict], bound: int, seconds: float) -> None:
    body = [f'<!doctype html><html lang="en"><meta charset="utf-8">'
            f'<meta name="viewport" content="width=device-width,initial-scale=1">'
            f'<title>VWE professor demo</title><style>body{{max-width:70rem;margin:2rem auto;'
            f'padding:0 1rem;font:16px/1.5 system-ui}}table{{border-collapse:collapse;width:100%}}'
            f'th,td{{padding:.7rem;text-align:left;border-bottom:1px solid #ccc}}</style>'
            f'<h1>Verdicts with Evidence</h1><p>Offline demo; declared K={bound}; handwritten '
            f'interpretations; {seconds:.1f} seconds. Claims are bounded and conditional on '
            f'adequate interpretations. See each report for exact caller bounds and evidence.</p>'
            f'<table><tr><th>Case</th><th>Verdict</th><th>Why</th><th>Time</th></tr>']
    for row in rows:
        relative = Path(row['report']).relative_to(destination.parent).as_posix()
        body.append(f'<tr><td><a href="{escape(relative, quote=True)}">{escape(row["label"])}</a></td>'
                    f'<td>{escape(row["decision"])} {escape(row["evidence_class"])}</td>'
                    f'<td>{escape(row["reason"])}</td><td>{row["seconds"]:.1f}s</td></tr>')
    destination.write_text(''.join(body) + '</table></html>')


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, default=ROOT / 'runs/demo')
    parser.add_argument('--config', type=Path, default=ROOT / 'config/demo.toml')
    parser.add_argument('--workers', type=int, choices=range(1, 5), default=3)
    args = parser.parse_args()
    if not cbmc.cbmc_available():
        parser.error('CBMC is unavailable; install the pinned tools first')
    cfg = load_config(args.config)
    start = monotonic()
    destination = args.out.resolve()
    session = destination / uuid4().hex
    session.mkdir(parents=True)
    profiles = {task: prepare_task(task, session / 'tasks' / task, cfg.bounds.K)
                for task in dict.fromkeys(case[0] for case in CASES)}
    print(f'VWE offline demo: K={cfg.bounds.K}, explicitly reduced caller profiles, '
          'handwritten interpretations. No provider calls.', flush=True)

    def check(case: tuple[str, str, str, str, str]) -> dict:
        task, candidate, decision, evidence, label = case
        report = verify(session / 'tasks' / task, candidate, cfg,
                        runs_root=session, parallel=False)
        return {'label': label, 'task': task, 'candidate': candidate, 'decision': report.decision,
                'evidence_class': report.evidence_class,
                'match': (report.decision, report.evidence_class) == (decision, evidence),
                'seconds': report.data['timing']['wall_seconds'], 'reason': report.data['reason'],
                'report': str(report.folder / 'report.html'), 'witness': report.data['witness']}

    rows = []
    colour = sys.stdout.isatty() and 'NO_COLOR' not in os.environ
    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        for row in pool.map(check, CASES):
            rows.append(row)
            code = '\033[32m' if row['match'] else '\033[31m'
            value = f"{row['decision']} {row['evidence_class']}".ljust(14)
            if colour:
                value = code + value + '\033[0m'
            print(f"{row['label']:42s} {value} {row['seconds']:6.1f}s", flush=True)
    row = path_cut_demo(session / 'path_cut', cfg)
    rows.append(row)
    print(f"{row['label']:42s} {row['decision']:14s} {row['seconds']:6.1f}s", flush=True)
    seconds = monotonic() - start
    within_budget = seconds < 300 and all(r['seconds'] < 60 for r in rows)
    summary = {'K': cfg.bounds.K, 'profiles': profiles, 'seconds': seconds,
               'within_budget': within_budget, 'rows': rows}
    write_json(session / 'summary.json', summary)
    write_json(destination / 'summary.json', summary)
    write_index(destination / 'index.html', rows, cfg.bounds.K, seconds)
    print(f'Total: {seconds:.1f}s. Reports: {destination / "index.html"}', flush=True)
    if not within_budget:
        print('Demo timing budget exceeded; inspect per-case timings.', file=sys.stderr)
    return int(not within_budget or any(not r['match'] for r in rows))


if __name__ == '__main__':
    raise SystemExit(main())
