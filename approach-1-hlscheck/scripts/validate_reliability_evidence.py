"""Check saved supplementary-study provenance and replay available SMT evidence.

Works in the portable package without the model, upstream clones or ESBMC.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json

from scripts.evaluate_local_candidates import digest, replay_smt
from scripts.generate_local_candidates import extract_code
from scripts.run_dataset_leaf_study import miter

ROOT = Path(__file__).resolve().parents[1]


def read(path):
    return json.loads((ROOT/path).read_text())


def driver_hash_matches(name, recorded_hash):
    """Bind saved evidence to its exact current or retained driver version."""
    candidates = [ROOT/'scripts'/name,
                  ROOT/'experiments/script_versions/root_layout_2026-11-22'/name]
    return any(path.is_file() and digest(path) == recorded_hash for path in candidates)


def validate_pair(folder, original, candidate):
    row = read(folder/'evaluation.json')
    assert row['fingerprints']['original'] == digest(ROOT/original)
    assert row['fingerprints']['candidate'] == digest(ROOT/candidate)
    for name in ('checker.py', 'esbmc_backend.py', 'pipeline.py'):
        assert row['fingerprints'][name] == digest(ROOT/'hlscheck'/name)
    assert driver_hash_matches('evaluate_local_candidates.py', row['fingerprints']['evaluator'])
    if 'native_helpers' in row['fingerprints']:
        assert driver_hash_matches('validate_native.py', row['fingerprints']['native_helpers'])
    if 'native' in row:
        assert row['native']['passed'], str(folder)
        assert row['native']['harness_sha256'] == digest(ROOT/folder/'native_differential.c')
        if row['status'] == 'equivalent':
            assert row['native']['mismatches'] == 0
        elif row['status'] == 'not_equivalent':
            assert row['native'].get('witness_replayed') or row['native']['mismatches'] > 0
    verification = row.get('verification', {})
    if verification.get('backend') == 'hlscheck/Z3' and row['status'] in ('equivalent', 'not_equivalent'):
        replay = replay_smt(ROOT/folder/'proof', (ROOT/original).read_text(), verification, 30000)
        assert replay['passed'], str(folder)
        return len(replay['queries'])
    return 0


def main():
    plan = read(Path('experiments/local_model/plan.json')); local = read(Path('results/local_llm/summary.json'))
    assert len(plan['attempts']) == local['evaluated'] == 40
    queries = 0
    for item in plan['attempts']:
        generation = Path('results/local_llm/generations')/item['id']
        record = read(generation/'generation.json'); raw_path = ROOT/generation/'response.json'
        assert record['raw_response_sha256'] == digest(raw_path)
        raw = json.loads(raw_path.read_bytes())
        extracted, _ = extract_code(raw['choices'][0]['message']['content'])
        assert extracted == (ROOT/generation/'candidate.c').read_text(encoding='utf-8')
        assert record['candidate_sha256'] == digest(ROOT/generation/'candidate.c')
        assert item['source_sha256'] == record['source_sha256'] == digest(ROOT/generation/'original.c')
        assert record['manual_semantic_edits'] is False and record['api_charge_usd'] == 0
        queries += validate_pair(Path('results/local_llm/evaluations')/item['id'], generation/'original.c', generation/'candidate.c')
    subtle = read(Path('experiments/subtle_faults/manifest.json'))
    for item in subtle['cases']:
        source = Path(item['directory'])
        assert item['original_sha256'] == digest(ROOT/source/'original.c')
        assert item['candidate_sha256'] == digest(ROOT/source/'candidate.c')
        row = read(Path('results/subtle_faults')/item['id']/'evaluation.json')
        assert row['status'] == item['expected']
        queries += validate_pair(Path('results/subtle_faults')/item['id'], source/'original.c', source/'candidate.c')
    hardware = read(Path('results/local_llm/hls/summary.json'))
    for row in hardware['cases']:
        generation = ROOT/'results/local_llm/generations'/row['id']
        assert row['candidate']['source_sha256'] == digest(generation/'candidate.c')
        assert row['baseline']['source_sha256'] == digest(generation/'original.c')
        assert row['candidate']['configuration_sha256'] == row['baseline']['configuration_sha256'] == hardware['configuration_sha256']
        assert row['candidate']['rtl_simulation_passed'] and row['candidate']['rtl_simulation_calls'] == 16
    leaves = read(Path('experiments/dataset_leaves/manifest.json'))
    for case in leaves['cases']:
        source = ROOT/case['directory']; result = ROOT/'results/dataset_leaves'/case['id']
        assert case['exact_function_text_sha256'] == digest(source/'upstream_function.txt')
        assert (source/'original.c').read_text().endswith((source/'upstream_function.txt').read_text())
        for variant, expected in [('optimized', 'equivalent'), ('buggy', 'not_equivalent')]:
            row = json.loads((result/variant/'result.json').read_text())
            assert row['status'] == expected and row['miter_sha256'] == digest(result/variant/'miter.c')
            assert miter(case, variant) == (result/variant/'miter.c').read_text()
        native = json.loads((result/'native.json').read_text())
        assert native['passed'] and native['harness_sha256'] == digest(result/'native_differential.c')
    record = {'passed': True, 'raw_model_attempts_integrity_checked': 40, 'controlled_cases_integrity_checked': len(subtle['cases']),
              'smt_queries_replayed': queries, 'hls_candidate_source_config_checks': len(hardware['cases']),
              'dataset_leaf_functions_integrity_checked': len(leaves['cases']),
              'scope': 'Raw generation extraction/source hashes, current engine hashes, exact current or retained evaluator/helper hashes, native harness hashes, available SMT replay and HLS source/configuration checks. Does not rerun external ESBMC, model generation or synthesis.'}
    (ROOT/'results/submission/reliability_validation.json').write_text(json.dumps(record, indent=2)+'\n')
    print(json.dumps(record, indent=2), flush=True)


if __name__ == '__main__':
    main()
