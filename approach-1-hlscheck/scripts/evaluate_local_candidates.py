"""Evaluate saved model outputs without editing, repairing, or resampling them.

Also exposes evaluate_pair for separately labelled controlled-fault studies.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
from collections import Counter
import hashlib
import json
import shutil
import subprocess

from pycparser import c_ast, c_generator
import z3

from hlscheck.checker import parse, Unsupported
from hlscheck.esbmc_backend import make_harness
from hlscheck.pipeline import check_with_fallback
from scripts.validate_native import interface, renamed, declarations, calls, comparison, RANDOM

ROOT = Path(__file__).resolve().parents[1]


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def canonical(source):
    return c_generator.CGenerator().visit(parse(source, 'kernel'))


def replay_smt(folder, original, verdict, timeout_ms):
    if verdict.get('backend') != 'hlscheck/Z3' or verdict['status'] not in ('equivalent', 'not_equivalent'):
        return {'available': False, 'reason': 'No conclusive custom-backend SMT query'}
    rows = []
    for lemma in verdict.get('component_lemmas', []):
        if lemma['status'] != 'unsat':
            continue
        path = folder / Path(lemma['smt_file']).name
        solver = z3.Solver(); solver.set(timeout=timeout_ms); solver.from_file(str(path))
        rows.append({'file': path.name, 'expected': 'unsat', 'observed': str(solver.check())})
    solver = z3.Solver(); solver.set(timeout=timeout_ms); solver.from_file(str(folder / 'symbolic.smt2'))
    pinned = verdict['status'] == 'not_equivalent'
    if pinned:
        fn = parse(original, 'kernel')
        for position, parameter in enumerate(fn.decl.type.args.params):
            value = verdict['counterexample'][parameter.name]
            if isinstance(parameter.type, c_ast.ArrayDecl):
                for i, element in enumerate(value):
                    solver.add(z3.BitVec(f'arg{position}_{i}', 32) == element)
            else:
                solver.add(z3.BitVec(f'arg{position}', 32) == value)
    rows.append({'file': 'symbolic.smt2', 'expected': 'sat' if pinned else 'unsat', 'observed': str(solver.check())})
    return {'available': True, 'passed': all(r['expected'] == r['observed'] for r in rows),
            'witness_pinned': pinned, 'queries': rows,
            'scope': 'Same Z3 solver; unrestricted UNSAT/lemma replay, SAT replay at recorded input. Not independent proof certificates.'}


def native_check(original, candidate, verification, folder, index, trials=264):
    """Execute only functions already proved free of modelled UB by a backend."""
    returns, params = interface(original)
    lines = ['#include <stdint.h>', '#include <stdio.h>',
             renamed(original, 'original'), renamed(candidate, 'optimized'), RANDOM,
             'int main(void){', 'unsigned failures=0, first=0;', f'for(unsigned t=0;t<{trials};++t){{']
    da, aa = declarations(params, '_a'); db, ab = declarations(params, '_b', copy='_a')
    lines += da + db + calls(returns, aa, ab)
    lines += [f'if({comparison(returns, params)}){{ if(!failures)first=t; ++failures; }}', '}',
              'unsigned witness_mismatch=0, witness_agrees=0;']
    witness = verification.get('counterexample') if verification['status'] == 'not_equivalent' else None
    if witness is not None:
        lines += ['{']
        da, aa = declarations(params, '_a', values=witness); db, ab = declarations(params, '_b', values=witness)
        lines += da + db + calls(returns, aa, ab)
        lines += [f'witness_mismatch=({comparison(returns, params)});', 'witness_agrees=1;']
        for n, length in params:
            for i in range(length or 0):
                a = verification['original_outputs'][n][i]; b = verification['candidate_outputs'][n][i]
                lines += [f'witness_agrees &= ({n}_a[{i}]=={a}u && {n}_b[{i}]=={b}u);']
        if returns:
            a = verification['original_outputs']['return']; b = verification['candidate_outputs']['return']
            lines += [f'witness_agrees &= (ret_a=={a}u && ret_b=={b}u);']
        lines += ['}']
    lines += ['printf("%u %u %u %u\\n", failures, first, witness_mismatch, witness_agrees);', 'return 0; }']
    source = folder / 'native_differential.c'; source.write_text('\n'.join(lines) + '\n')
    executable = folder / f'native_check_{index:03d}.exe'
    compiler = shutil.which('clang') or shutil.which('gcc')
    command = [compiler, '-std=c11', '-O2', str(source), '-o', str(executable)]
    built = subprocess.run(command, capture_output=True, text=True, timeout=60)
    (folder / 'native_compile.log').write_text(built.stdout + built.stderr)
    if built.returncode:
        return {'passed': False, 'reason': 'Native harness compilation failed', 'command': command}
    run = subprocess.run([str(executable)], capture_output=True, text=True, timeout=15)
    (folder / 'native_run.log').write_text(run.stdout + run.stderr)
    failures, first, mismatch, agrees = map(int, run.stdout.split())
    valid = run.returncode == 0 and (failures == 0 if verification['status'] == 'equivalent' else True)
    if witness is not None:
        valid &= bool(mismatch and agrees)
    return {'passed': bool(valid), 'trials': trials, 'directed_trials': 8, 'random_trials': trials - 8,
            'mismatches': failures, 'first_mismatch_trial': first if failures else None,
            'witness_replayed': bool(mismatch) if witness is not None else None,
            'witness_outputs_agree': bool(agrees) if witness is not None else None,
            'harness_sha256': digest(source), 'command': command, 'exit_code': run.returncode}


def evaluate_pair(original_path, candidate_path, folder, index=0, timeout_ms=10000, force=False):
    original_path, candidate_path, folder = map(Path, (original_path, candidate_path, folder))
    folder.mkdir(parents=True, exist_ok=True)
    fingerprints = {'original': digest(original_path), 'candidate': digest(candidate_path),
                    'evaluator': digest(__file__),
                    **{f: digest(ROOT / 'hlscheck' / f) for f in ('checker.py', 'esbmc_backend.py', 'pipeline.py')},
                    'native_helpers': digest(ROOT / 'scripts/validate_native.py'), 'timeout_ms': timeout_ms}
    record_path = folder / 'evaluation.json'
    if record_path.exists() and not force:
        saved = json.loads(record_path.read_text())
        if saved.get('fingerprints') == fingerprints:
            return saved
    record = {'fingerprints': fingerprints, 'manual_semantic_edits': False}
    original, candidate = original_path.read_text(), candidate_path.read_text()
    compiler = shutil.which('clang') or shutil.which('gcc')
    syntax = subprocess.run([compiler, '-std=c11', '-fsyntax-only', '-Wall', '-Wextra', str(candidate_path)],
                            capture_output=True, text=True, timeout=30)
    (folder / 'syntax.log').write_text(syntax.stdout + syntax.stderr)
    record['syntax_compiles'] = syntax.returncode == 0
    if syntax.returncode:
        record['status'] = 'compile_failure'
    else:
        try:
            # Check complete signatures, calls and persistent-state exclusions
            # independently before either backend or native execution.
            make_harness(original, candidate, 'kernel')
            record['ast_unchanged'] = canonical(original) == canonical(candidate)
        except (Unsupported, Exception) as error:
            record.update(status='unsupported', reason=str(error))
        else:
            verification = check_with_fallback(original, candidate, function='kernel',
                output_dir=folder / 'proof', timeout_ms=timeout_ms)
            record['verification'] = verification
            record['status'] = verification['status']
            if verification['status'] in ('equivalent', 'not_equivalent'):
                record['smt_replay'] = replay_smt(folder / 'proof', original, verification, timeout_ms)
                # ESBMC may support types outside this native harness. The core
                # 40-attempt experiment has exclusively uint32_t interfaces.
                try:
                    record['native'] = native_check(original, candidate, verification, folder, index)
                except (Unsupported, subprocess.TimeoutExpired, ValueError) as error:
                    record['native'] = {'passed': False, 'reason': str(error)}
    record_path.write_text(json.dumps(record, indent=2) + '\n')
    return record


def main():
    parser = argparse.ArgumentParser(); parser.add_argument('--timeout-ms', type=int, default=10000)
    parser.add_argument('--force', action='store_true'); parser.add_argument('--limit', type=int, default=40)
    args = parser.parse_args()
    plan = json.loads((ROOT / 'experiments/local_model/plan.json').read_text())
    rows = []
    for index, item in enumerate(plan['attempts'][:args.limit]):
        folder = ROOT / 'results/local_llm/generations' / item['id']
        generation = json.loads((folder / 'generation.json').read_text())
        if digest(folder / 'candidate.c') != generation['candidate_sha256']:
            raise RuntimeError('Raw model candidate was changed: ' + item['id'])
        if digest(folder / 'original.c') != generation['source_sha256']:
            raise RuntimeError('Original changed: ' + item['id'])
        row = evaluate_pair(folder / 'original.c', folder / 'candidate.c',
            ROOT / 'results/local_llm/evaluations' / item['id'], index, args.timeout_ms, args.force)
        rows.append({'id': item['id'], 'case': item['case'], 'finish_reason': generation['finish_reason'], **row})
        print(item['id'], row['status'], 'unchanged=' + str(row.get('ast_unchanged')),
              'native=' + str(row.get('native', {}).get('passed')), flush=True)
    counts = dict(Counter(r['status'] for r in rows))
    result = {'model': plan['model_provenance'], 'api_charge_usd': 0, 'planned': len(plan['attempts']),
        'evaluated': len(rows), 'counts': counts, 'ast_unchanged': sum(r.get('ast_unchanged', False) for r in rows),
        'nontrivial_equivalent_rewrites': sum(r['status'] == 'equivalent' and not r.get('ast_unchanged', True) for r in rows),
        'all_available_native_checks_passed': all(r.get('native', {}).get('passed', True) for r in rows),
        'all_available_smt_replays_passed': all(r.get('smt_replay', {}).get('passed', True) for r in rows),
        'scope': '40 fixed attempts: 20 sources x 2 seed/temperature settings from one small quantized model. No verifier feedback, repair or selective discarding. Not a general LLM error-rate estimate.',
        'cases': rows}
    (ROOT / 'results/local_llm/summary.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: v for k, v in result.items() if k not in ('cases', 'model')}, indent=2), flush=True)


if __name__ == '__main__':
    main()
