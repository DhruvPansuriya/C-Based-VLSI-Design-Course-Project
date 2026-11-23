#!/usr/bin/env python3
"""Preserve existing verification evidence without invoking a verifier."""
from __future__ import annotations

import argparse
from hashlib import sha256
from datetime import datetime, timezone
from html import escape
import json
from pathlib import Path
import re
import shutil
import sys
import tarfile
from typing import Any

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from vwe.report import write_json
from vwe.schemas import validate
from vwe.tools.frontend import execute

TEXT_SUFFIXES = {'.c', '.h', '.json', '.stdout', '.stderr', '.txt'}


def digest(path: Path) -> str:
    return sha256(path.read_bytes()).hexdigest()


def pytest_summary(path: Path) -> dict[str, Any]:
    lines = path.read_text().splitlines()
    summaries = [line.strip('= ') for line in lines
                 if re.match(r'^\s*(?:=+\s*)?\d+ (?:passed|failed)', line)]
    if not summaries or re.search(r'\b\d+ (?:failed|errors?)\b', summaries[-1]):
        raise ValueError('test log has no successful pytest completion summary')
    summary = summaries[-1]
    passed = re.search(r'(\d+) passed', summary)
    skipped = re.search(r'(\d+) skipped', summary)
    if not passed:
        raise ValueError('test log does not record passing tests')
    return {'summary': summary, 'passed': int(passed[1]),
            'skipped': int(skipped[1]) if skipped else 0}


def copy_report(source: Path, destination: Path, *, semantic: bool) -> dict[str, Any]:
    destination.mkdir(parents=True)
    if semantic:
        report = json.loads(source.with_name('report.json').read_text())
        validate('verdict_report', report)
        for name in ('report.json', 'report.html', 'run_manifest.json'):
            shutil.copyfile(source.with_name(name), destination / name)
        for name in ('regions/regions.json', 'interpretations/validation.json',
                     'interpretations/interpretation_set.json'):
            path = source.parent / name
            if path.is_file():
                shutil.copyfile(path, destination / Path(name).name)
        return report
    shutil.copyfile(source, destination / 'report.html')
    shutil.copyfile(source.with_name('comparison.json'), destination / 'comparison.json')
    return json.loads(source.with_name('comparison.json').read_text())


def archive(args: argparse.Namespace) -> Path:
    if not re.fullmatch(r'[A-Za-z0-9][A-Za-z0-9._-]*', args.label):
        raise ValueError('label must be a single safe directory name')
    output = (args.out / args.label).resolve()
    if output.exists():
        raise ValueError('checkpoint already exists; choose a new label to preserve history')
    golden = json.loads(args.golden.read_text())
    demo = json.loads(args.demo.read_text())
    if not golden.get('rows') or not all(row.get('match') for row in golden['rows']):
        raise ValueError('golden evidence contains mismatches or no cases')
    if not demo.get('rows') or not all(row.get('match') for row in demo['rows']):
        raise ValueError('demo evidence contains mismatches or no cases')
    if not demo.get('within_budget'):
        raise ValueError('demo evidence did not meet its timing budget')
    tests = pytest_summary(args.test_log)
    head = execute(['git', 'rev-parse', 'HEAD'], cwd=ROOT, timeout_s=10)
    if not head.ok:
        raise ValueError('cannot record repository commit')
    output.mkdir(parents=True)
    roots: list[tuple[Path, str]] = []
    executions = []
    rows_by_group = {}
    for group, data in (('golden', golden), ('demo', demo)):
        rows = []
        for original in data['rows']:
            row = dict(original)
            source = Path(row['report']).resolve()
            semantic = group == 'golden' or 'task' in row
            task = row.get('example', row.get('task', 'path_cut'))
            candidate = 'v' + row['variant'] if group == 'golden' else row.get('candidate')
            relative = Path(group) / task
            if candidate:
                relative /= candidate
            if not (output / relative).resolve().is_relative_to(output):
                raise ValueError('report identifiers escape the checkpoint directory')
            report = copy_report(source, output / relative, semantic=semantic)
            if semantic:
                actual = [report['decision'], report['evidence_class']]
                wanted = row['got'] if group == 'golden' else [row['decision'], row['evidence_class']]
                if actual != wanted:
                    raise ValueError('aggregate and individual verdict disagree')
                manifest = json.loads((output / relative / 'run_manifest.json').read_text())
                executions.append({'group': group, 'task': task, 'candidate': candidate,
                                   'run_id': manifest['run_id'],
                                   'execution_git_commit': manifest['git_commit'],
                                   'timestamp_utc': manifest['timestamp_utc']})
            row['report'] = (relative / ('report.json' if group == 'golden' else 'report.html')).as_posix()
            rows.append(row)
            roots.append((source.parent, relative.as_posix()))
        portable = {**data, 'rows': rows}
        write_json(output / (group + '.json'), portable)
        rows_by_group[group] = rows
    (output / 'logs').mkdir()
    shutil.copyfile(args.test_log, output / 'logs/tests.log')
    for index, path in enumerate(args.log):
        shutil.copyfile(path, output / 'logs' / f'{index + 1:02}-{path.name}')
    listing = execute(['git', 'ls-files', '-z', 'vwe', 'config', 'schemas', 'examples/tasks',
                       'tests', 'scripts', 'pyproject.toml', 'requirements.txt'], cwd=ROOT, timeout_s=10)
    if not listing.ok:
        raise ValueError('cannot inventory implementation files')
    sources = {name: digest(ROOT / name) for name in listing.stdout.split('\0')
               if name and (ROOT / name).is_file()}
    write_json(output / 'source-inventory.json', sources)
    included = 0
    with tarfile.open(output / 'raw-evidence.tar.gz', 'w:gz', compresslevel=6) as tar:
        for folder, relative in roots:
            for path in sorted(folder.rglob('*')):
                if path.is_file() and path.suffix in TEXT_SUFFIXES:
                    tar.add(path, arcname=(Path(relative) / path.relative_to(folder)).as_posix())
                    included += 1
    metadata = {
        'schema_version': 1, 'checkpoint': args.label, 'checkpoint_git_commit': head.stdout.strip(),
        'archived_at_utc': datetime.now(timezone.utc).isoformat(),
        'source': 'existing run artifacts; no solver, compiler or native program was executed by this exporter',
        'tests': tests, 'golden_cases': len(golden['rows']), 'golden_matches': len(golden['rows']),
        'demo_rows': len(demo['rows']), 'demo_seconds': demo['seconds'], 'demo_K': demo['K'],
        'demo_max_case_seconds': max(row['seconds'] for row in demo['rows']),
        'raw_text_files': included,
        'raw_policy': 'Generated C/headers, JSON traces/manifests and text diagnostics included; GOTO binaries and native executables excluded.',
        'execution_provenance': executions,
        'provenance_note': 'Run manifests retain execution-time HEADs. The checkpoint HEAD identifies packaging state, not a fresh execution. Preserve original SHAs; document tested uncommitted changes and later implementation commits separately rather than relabeling earlier observations.',
        'ci': json.loads(args.ci.read_text()) if args.ci else [],
        'scope': 'Authored regression fixtures, bounded exact disjoint caller profiles, handwritten interpretations; not research-scale accuracy or HLS QoR results.',
    }
    write_json(output / 'metadata.json', metadata)
    lines = [f'# Evidence checkpoint: {args.label}', '',
             'This is preserved evidence, not a new verification run. Read this before rerunning tools.', '',
             f"- Tests: **{tests['summary']}**.",
             f"- Golden cases: **{len(golden['rows'])}/{len(golden['rows'])} matched**.",
             f"- Demo: **{len(demo['rows'])}/{len(demo['rows'])} rows matched in {demo['seconds']:.1f}s**, K={demo['K']}.",
             '- Inspect individual tool records for confirmation availability; do not infer an optional tool ran merely because the final verdict is present.',
             '- Detailed provenance, configuration, hashes and original execution-parent commits are retained.', '',
             '| Task | Candidate | Expected | Observed | Reason |', '|---|---|---|---|---|']
    for row in rows_by_group['golden']:
        lines.append(f"| {row['example']} | v{row['variant']} | {' '.join(row['expected'])} | {' '.join(row['got'])} | {row['reason']} |")
    lines += ['', '## Files', '',
              '- `golden.json`, `demo.json`: portable aggregate results.',
              '- `golden/`, `demo/`: standalone reports, manifests and validation/region evidence.',
              '- `logs/`: exact captured test, golden and demo console logs.',
              '- `raw-evidence.tar.gz`: generated sources and raw solver/native text evidence. Extract in a separate directory to inspect; no verification tools are needed.',
              '- `source-inventory.json`: implementation file SHA-256 inventory at archival time.',
              '- `checksums.json`: hashes of the archived payload.', '',
              'The old `evaluation/results/golden/` is a separate imported ten-case prototype snapshot. It is not this twenty-case public-pipeline run.', '',
              metadata['provenance_note'], '',
              'Passing fixtures establishes these regressions and the runnable demo. It does not establish general natural-language correctness, benchmark accuracy, universal shape transfer, synthesis readiness or area/latency improvement.']
    (output / 'README.md').write_text('\n'.join(lines) + '\n')
    html = ['<!doctype html><html lang="en"><meta charset="utf-8"><title>Preserved VWE evidence</title>',
            '<style>body{max-width:75rem;margin:2rem auto;padding:0 1rem;font:16px/1.5 system-ui}td,th{padding:.5rem;text-align:left;border-bottom:1px solid #ccc}table{border-collapse:collapse}</style>',
            '<h1>Preserved VWE evidence</h1><p>Existing observations; no verification was rerun to create this archive. Read README.md and metadata.json for provenance and limits.</p>']
    for group, rows in rows_by_group.items():
        html.append(f'<h2>{escape(group.title())}</h2><table><tr><th>Case</th><th>Verdict</th><th>Reason</th></tr>')
        for row in rows:
            label = row.get('label', row.get('example', ''))
            result = row['got'] if group == 'golden' else [row['decision'], row['evidence_class']]
            path = Path(row['report']).with_suffix('.html').as_posix()
            html.append(f'<tr><td><a href="{escape(path, quote=True)}">{escape(label)} {escape(row.get("variant", ""))}</a></td><td>{escape(" ".join(result))}</td><td>{escape(row["reason"])}</td></tr>')
        html.append('</table>')
    (output / 'index.html').write_text(''.join(html) + '</html>')
    hashes = {p.relative_to(output).as_posix(): digest(p) for p in sorted(output.rglob('*')) if p.is_file()}
    write_json(output / 'checksums.json', hashes)
    return output


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--label', required=True)
    parser.add_argument('--out', type=Path, default=ROOT / 'evaluation/results/checkpoints')
    parser.add_argument('--golden', type=Path, default=ROOT / 'runs/golden/golden_results.json')
    parser.add_argument('--demo', type=Path, default=ROOT / 'runs/demo/summary.json')
    parser.add_argument('--test-log', type=Path, required=True)
    parser.add_argument('--log', type=Path, action='append', default=[])
    parser.add_argument('--ci', type=Path)
    args = parser.parse_args()
    try:
        print(archive(args))
    except (OSError, ValueError, KeyError) as exc:
        parser.error(str(exc))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
