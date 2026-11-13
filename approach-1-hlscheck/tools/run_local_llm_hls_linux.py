"""Measure all changed, proved-equivalent local-model candidates under WSL."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from run_hls_linux import run_one, CONFIG_HASH


def prepare_case(row):
    from scripts.validate_native import hls_testbench
    name = row['id']; generation = ROOT/'results/local_llm/generations'/name
    output = ROOT/'results/local_llm/hls'; inputs = output/'inputs'/name
    inputs.mkdir(parents=True, exist_ok=True)
    original = generation/'original.c'; candidate = generation/'candidate.c'
    assert hashlib.sha256(candidate.read_bytes()).hexdigest() == row['fingerprints']['candidate']
    assert hashlib.sha256(original.read_bytes()).hexdigest() == row['fingerprints']['original']
    tb = inputs/'tb.c'; tb.write_text(hls_testbench(original.read_text()))
    proof = inputs/'proof.json'
    proof.write_text(json.dumps({'original_sha256': row['fingerprints']['original'],
        'candidate_sha256': row['fingerprints']['candidate'], 'verification': row['verification']}, indent=2)+'\n')
    return inputs


def run_case(row, force):
    name = row['id']; generation = ROOT/'results/local_llm/generations'/name
    output = ROOT/'results/local_llm/hls'; inputs = output/'inputs'/name
    original = generation/'original.c'; candidate = generation/'candidate.c'
    assert hashlib.sha256(candidate.read_bytes()).hexdigest() == row['fingerprints']['candidate']
    assert hashlib.sha256(original.read_bytes()).hexdigest() == row['fingerprints']['original']
    tb = inputs/'tb.c'; proof = inputs/'proof.json'
    assert tb.exists() and proof.exists(), 'Run --prepare-only with the project Python first'
    measured = run_one({'name': name, 'directory': str(generation.relative_to(ROOT))}, 'optimized', force,
        source_override=candidate, testbench_override=tb, proof_override=proof, output_root=output)
    baseline_path = ROOT/'results/hls'/(row['case']+'_original')/'metrics.json'
    baseline = json.loads(baseline_path.read_text())
    assert baseline['status'] == 'complete' and baseline['source_sha256'] == row['fingerprints']['original']
    assert baseline['configuration_sha256'] == CONFIG_HASH
    result = {'id': name, 'original_case': row['case'], 'baseline_reused_from': baseline_path.relative_to(ROOT).as_posix(),
              'baseline': baseline, 'candidate': measured}
    if measured['status'] == 'complete':
        result['ratios'] = {key: measured[key]/baseline[key] for key in ('area_um2', 'cycles', 'delay_ns', 'area_latency_product_um2_ns')}
        result['selected_by_adp_policy'] = measured['meets_10ns'] and result['ratios']['area_latency_product_um2_ns'] < .999
    return result


def main():
    parser = argparse.ArgumentParser(); parser.add_argument('--jobs', type=int, default=3)
    parser.add_argument('--force', action='store_true'); parser.add_argument('--prepare-only', action='store_true')
    args = parser.parse_args()
    study = json.loads((ROOT/'results/local_llm/summary.json').read_text())
    eligible = [r for r in study['cases'] if r['status'] == 'equivalent' and not r['ast_unchanged']]
    assert all(r['native']['passed'] and r['smt_replay']['passed'] for r in eligible)
    if args.prepare_only:
        for row in eligible: prepare_case(row)
        print('Prepared', len(eligible), 'proof-bound HLS inputs', flush=True)
        return 0
    rows = []
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [pool.submit(run_case, row, args.force) for row in eligible]
        for future in as_completed(futures): rows.append(future.result())
    rows.sort(key=lambda r:r['id'])
    result = {'selection': 'All changed local-model outputs proved equivalent; no selection by hardware result.',
        'passed': all(r['candidate']['status'] == 'complete' for r in rows), 'configuration_sha256': CONFIG_HASH,
        'counts': {'eligible': len(eligible), 'synthesized': len(rows), 'improved_adp': sum(r.get('selected_by_adp_policy', False) for r in rows)},
        'cases': rows}
    (ROOT/'results/local_llm/hls/summary.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result['counts']), flush=True)
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
