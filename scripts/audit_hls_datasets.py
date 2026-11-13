"""Inventory pinned, downloaded HLS suites and audit the exact-source frontend.

This is a coverage/eligibility audit, not an equivalence experiment. Testbenches
are excluded from design selection; no headers, types or dimensions are changed.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from collections import Counter
import hashlib
import json
import re
import subprocess

from hlscheck.checker import parse, Interpreter

ROOT = Path(__file__).resolve().parents[1]


def revision(path):
    return subprocess.check_output(['git', '-C', str(path), 'rev-parse', 'HEAD'], text=True).strip()


def inspect(suite, folder, top, sources):
    rows = []
    for source in sources:
        text = source.read_text(errors='replace')
        try:
            fn = parse(text, top)
            Interpreter(fn, max_unroll=8, max_paths=8).run()
            status, reason = 'accepted_for_bounded_symbolic_execution', None
        except Exception as error:
            status, reason = 'frontend_exclusion', str(error)
        rows.append({'source': source.relative_to(ROOT).as_posix(),
            'sha256': hashlib.sha256(source.read_bytes()).hexdigest(), 'status': status, 'reason': reason,
            'text_indicators_not_semantic_analysis': {
                'includes': re.findall(r'^\s*#\s*include\s+([^\n]+)', text, re.M),
                'float_or_double_token': bool(re.search(r'\b(float|double)\b', text)),
                'vendor_ap_type_token': bool(re.search(r'\b(ap_int|ap_uint|ap_fixed|hls::)', text)),
            }})
    return {'suite': suite, 'design': folder.relative_to(ROOT/'datasets'/suite).as_posix(),
            'top': top, 'sources': rows,
            'eligible_source_count': sum(r['status'] == 'accepted_for_bounded_symbolic_execution' for r in rows)}


def main():
    rows = []; paths = {s: ROOT/'datasets'/s for s in ('CHStone', 'MachSuite', 'hls-eval')}
    for directory in sorted(paths['CHStone'].iterdir()):
        if not directory.is_dir() or directory.name == 'common' or directory.name.startswith('.'):
            continue
        sources = [p for p in directory.glob('*.c') if re.search(r'\bmain\s*\(', p.read_text(errors='replace'))]
        rows.append(inspect('CHStone', directory, 'main', sources))
    for tcl in sorted(paths['MachSuite'].glob('*/*/hls.tcl')):
        text = '\n'.join(l for l in tcl.read_text().splitlines() if not l.lstrip().startswith('#'))
        match = re.search(r'^\s*set_top\s+(\w+)', text, re.M)
        if not match:
            raise ValueError('Missing set_top: ' + str(tcl))
        files = re.findall(r'^\s*add_files\s+([^\s-][^\s]*)\s*$', text, re.M)
        sources = [tcl.parent/f for f in files if f.endswith(('.c', '.cpp')) and (tcl.parent/f).is_file()]
        rows.append(inspect('MachSuite', tcl.parent, match.group(1), sources))
    for top_file in sorted((paths['hls-eval']/'hls_eval_data').rglob('top.txt')):
        top = top_file.read_text().strip(); directory = top_file.parent
        sources = [p for p in sorted(directory.iterdir()) if p.suffix in ('.c', '.cpp')
                   and '_tb' not in p.stem and not p.stem.endswith('_test')]
        rows.append(inspect('hls-eval', directory, top, sources))
    tracked = subprocess.check_output(['git', '-C', str(paths['hls-eval']), 'ls-files'], text=True).splitlines()
    tracked_designs = [p for p in tracked if p.startswith('hls_eval_data/') and p.endswith('/top.txt')]
    result = {'commits': {s: revision(p) for s, p in paths.items()},
        'scope': 'Exact-source frontend audit with max_unroll=8 and max_paths=8. No equivalence or whole-suite validation claims.',
        'design_counts': dict(Counter(r['suite'] for r in rows)),
        'hls_eval_tracked_design_count': len(tracked_designs),
        'hls_eval_materialized_design_count': sum(r['suite'] == 'hls-eval' for r in rows),
        'hls_eval_inventory_scope': 'Available hls_eval_data design directories in the existing sparse checkout. Excludes tests/test_design_for_tools and unmaterialized tracked designs.',
        'accepted_source_counts': {s: sum(r['eligible_source_count'] for r in rows if r['suite'] == s) for s in paths},
        'cases': rows}
    output = ROOT/'results/dataset_audit'; output.mkdir(exist_ok=True)
    (output/'inventory.json').write_text(json.dumps(result, indent=2)+'\n')
    print({k:v for k,v in result.items() if k != 'cases'})


if __name__ == '__main__':
    main()
