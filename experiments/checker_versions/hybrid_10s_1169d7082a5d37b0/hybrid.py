"""Relational-summary abstraction/refinement for C-to-C equivalence.

One proof algorithm combines custom SMT region proofs with a residual C
product-program check. ESBMC is always the final C verification engine; it is
not selected as a fallback to an independent whole-function checker.

No abstract counterexample is reported as a concrete mismatch. Shared-havoc
failures are refined with a separately certified functional summary, or by
restoring the original region. Accepted region lemmas remain proof dependencies.
"""
import hashlib
import json
import os
import re
from pathlib import Path
import shutil
import subprocess
import time

from .checker import Unsupported, check_equivalence
from .esbmc_backend import classify_log
from .frontend import InvalidC, compile_pair
from .miter import make_miter
from .relational import split_region, whole_function_region, exact_summary


ROOT = Path(__file__).resolve().parents[1]


def sha(data):
    return hashlib.sha256(data.encode('utf-8') if isinstance(data, str) else data).hexdigest()


def save(path, value):
    Path(path).write_text(json.dumps(value, indent=2)+'\n', encoding='utf-8')


def verify_c_miter(source, folder, *, executable=None, max_unroll=256, timeout_ms=10000,
                   retain_inputs=False, json_report=True):
    folder = Path(folder); folder.mkdir(parents=True, exist_ok=True)
    path = folder/'miter.c'; path.write_text(source, encoding='utf-8')
    report_path=folder/'report.json'
    if report_path.exists(): report_path.unlink()
    bundled = ROOT/'tools/esbmc-v8.7/release/bin/esbmc.exe'
    executable = executable or os.environ.get('ESBMC_PATH') or (str(bundled) if bundled.exists() else shutil.which('esbmc'))
    record = {'engine': 'ESBMC with Z3', 'status': 'error', 'miter_sha256': sha(path.read_bytes())}
    if not executable:
        record['reason'] = 'Install ESBMC or set ESBMC_PATH; the integrated algorithm requires its residual proof'
        save(folder/'result.json', record); return record
    command = [str(Path(executable).resolve()), str(path.resolve()), '--i386-win32', '--32', '--z3', '--bv',
               '--unwind', str(max_unroll), '--overflow-check', '--ub-shift-check',
               '--uninitialised-vars-check', '--multi-property']
    if json_report: command += ['--generate-json-report']
    if retain_inputs: command += ['--no-slice']
    # Retain initial inputs when a counterexample is produced. These are not
    # range restrictions and do not change the verified state space.
    started = time.perf_counter()
    try:
        run = subprocess.run(command, cwd=folder, capture_output=True, text=True,
                             errors='replace', timeout=timeout_ms/1000)
        log = run.stdout+'\n'+run.stderr
        record.update(status=classify_log(log, run.returncode), returncode=run.returncode)
        record['version'] = next((l for l in log.splitlines() if 'ESBMC version' in l), 'not reported')
    except subprocess.TimeoutExpired as error:
        def decoded(value): return value.decode(errors='replace') if isinstance(value, bytes) else (value or '')
        log = decoded(error.stdout)+'\n'+decoded(error.stderr)+'\nExternal wall-clock timeout.\n'
        record.update(status='unknown', reason='Residual verification exceeded the wall-clock limit')
    except OSError as error:
        log = str(error); record['reason'] = str(error)
    (folder/'esbmc.log').write_text(log, encoding='utf-8')
    record.update(command=command, max_unroll=max_unroll, timeout_ms=timeout_ms,
                  elapsed_seconds=round(time.perf_counter()-started,6),
                  bounds_pointer_division_overflow_shift_uninitialized_unwinding_checks_retained=True)
    save(folder/'result.json', record)
    return record


def counterexample_inputs(folder, contract):
    """Read complete initial inputs from the current unsliced ESBMC report.

    Missing or abbreviated values are never silently filled with zero. Raw
    traces remain available when this decoder cannot recover a full vector.
    """
    path=Path(folder)/'report.json'
    if not path.exists(): return None
    try:
        reports=json.loads(path.read_text(encoding='utf-8'))
        if isinstance(reports, dict): reports=[reports]
        for report in reports:
            steps=report.get('steps',[])
            if not any(s.get('type')=='violation' and s.get('assertion',{}).get('comment','').startswith('EQUIV:') for s in steps):
                continue
            values={}
            for step in steps:
                assignment=step.get('assignment',{})
                name=assignment.get('lhs','')
                if re.fullmatch(r'__hlscheck_input_\d+',name) and name not in values:
                    values[name]=assignment.get('rhs','')
            decoded={}
            for p in contract['parameters']:
                text=values.get(f'__hlscheck_input_{p["position"]}')
                if text is None: break
                if p['length'] is None:
                    value=int(text,0) if text.lower().startswith(('0x','-0x')) else int(text)
                    decoded[p['name']]=value
                else:
                    if not text.startswith('{') or not text.endswith('}'): break
                    parts=[s.strip() for s in text[1:-1].split(',')]
                    if len(parts)!=p['length']: break
                    decoded[p['name']]=[int(s,0) if s.lower().startswith(('0x','-0x')) else int(s) for s in parts]
            if len(decoded)==len(contract['parameters']): return decoded
    except (ValueError,TypeError,KeyError):
        pass
    return None


def verify_equivalence(original, candidate, function=None, *, output_dir,
                       scalar_ranges=None, timeout_ms=10000, max_unroll=256, max_paths=256,
                       executable=None):
    """Verify a pair with one common contract and explicit proof dependencies.

    Timeout is per proof obligation. max_unroll is not a restricted input
    domain: incomplete unwinding is inconclusive, never a bounded equivalence
    claim. Existing source files and historical standalone results are untouched.
    """
    started = time.perf_counter(); output = Path(output_dir); output.mkdir(parents=True, exist_ok=True)
    result = {'tool': 'HLSCheck', 'algorithm': 'certified relational summaries with residual-C abstraction/refinement',
              'status': 'error', 'source_sha256': {'original': sha(original), 'candidate': sha(candidate)},
              'upstream_components': ['Z3', 'ESBMC'], 'proof_dependencies': [], 'refinements': [],
              'obligations': [], 'engine_selection': 'No router: ESBMC checks the residual C product; custom SMT proofs justify region abstraction.'}
    result['implementation_sha256'] = {name: sha((Path(__file__).parent/name).read_bytes())
        for name in ('hybrid.py','frontend.py','miter.py','relational.py','checker.py','esbmc_backend.py')}
    try:
        if min(timeout_ms, max_unroll, max_paths) <= 0:
            raise Unsupported('Timeout, unroll and path limits must be positive')
        left, right, contract = compile_pair(original, candidate, function, scalar_ranges)
        result['contract'] = contract
        (output/'original_input.c').write_bytes(original.encode('utf-8'))
        (output/'candidate_input.c').write_bytes(candidate.encode('utf-8'))
        for name, unit in [('original', left), ('candidate', right)]:
            (output/(name+'_canonical.c')).write_bytes(unit.canonical.encode('utf-8'))
        save(output/'contract.json', contract)
        regions = None
        proposed_witness = None
        try:
            regions = (split_region(left), split_region(right))
        except Unsupported as error:
            result['region_analysis'] = {'prefix_exclusion': str(error)}
            try:
                regions = (whole_function_region(left), whole_function_region(right))
            except Unsupported:
                result['region_analysis']['abstractable'] = False
        if regions:
            lemmas = output/'lemmas'; lemmas.mkdir(exist_ok=True)
            for name, region in zip(('original','candidate'), regions):
                (lemmas/(name+'_region.c')).write_text(region['region_source'], encoding='utf-8')
            proof = check_equivalence(regions[0]['region_source'], regions[1]['region_source'],
                timeout_ms=timeout_ms, max_unroll=max_unroll, max_paths=max_paths, smt_path=lemmas/'region_equality.smt2')
            save(lemmas/'region_equality.json', proof)
            result['region_analysis'] = {'abstractable': proof['status']=='equivalent',
                'left_statements': regions[0]['statement_count'], 'right_statements': regions[1]['statement_count'],
                'whole_function': regions[0].get('whole_function',False),
                'boundary': regions[0]['boundary'], 'proof_status': proof['status']}
            result['obligations'].append({'id': 'region_equality', 'engine': 'custom symbolic execution / Z3', 'status': proof['status']})
            if proof['status'] == 'equivalent':
                result['proof_dependencies'].append({'id': 'region_equality', 'result': 'lemmas/region_equality.json',
                    'smt': 'lemmas/region_equality.smt2', 'accepted_component_lemmas': proof.get('component_lemmas', [])})
            else:
                # A differing intermediate state may be overwritten later.
                # It is never a whole-program mismatch verdict.
                if regions[0].get('at_function_exit') and regions[1].get('at_function_exit') and proof['status']=='not_equivalent':
                    witness=proof['counterexample']
                    if all(low<=witness[name]<=high for name,(low,high) in contract['scalar_ranges'].items()):
                        proposed_witness=witness
                        result['proposed_counterexample']=witness
                regions = None
        abstraction = 'shared_havoc' if regions else 'none'
        source = make_miter(left, right, contract, regions=regions, abstraction=abstraction, input_values=proposed_witness)
        phase = verify_c_miter(source, output/'residual_0', executable=executable,
                              max_unroll=max_unroll, timeout_ms=timeout_ms,
                              json_report=not (proposed_witness is not None or regions is not None))
        result['obligations'].append({'id': 'residual_0', 'engine': 'ESBMC / Z3', 'abstraction': abstraction,
                                     'input_domain': 'proposed counterexample only' if proposed_witness else 'full stated domain', 'status': phase['status']})
        final_phase = 'residual_0'
        if proposed_witness and phase['status'] not in ('not_equivalent','safety_violation'):
            # Success at one input never proves universal equivalence. Discard
            # an unconfirmed witness and verify the unrestricted product.
            result['refinements'].append({'trigger':phase['status'], 'action':'Discard unconfirmed symbolic witness and restore the full input domain'})
            source=make_miter(left,right,contract)
            phase=verify_c_miter(source, output/'witness_refinement', executable=executable,
                                 max_unroll=max_unroll, timeout_ms=timeout_ms)
            final_phase='witness_refinement'; proposed_witness=None
            result['obligations'].append({'id':final_phase,'engine':'ESBMC / Z3','abstraction':'none','input_domain':'full stated domain','status':phase['status']})
        if regions and phase['status'] != 'equivalent':
            # Abstract SAT, unsafe or incomplete traces can be spurious. Refine
            # the state relation rather than accepting such a result.
            refinement = {'trigger': phase['status'], 'abstract_counterexample_is_conclusive': False}
            summary_source = None
            try:
                summary_source = exact_summary(left, regions[0], max_unroll=max_unroll, max_paths=max_paths)
                (output/'lemmas/exact_summary.c').write_text(summary_source, encoding='utf-8')
                proof = check_equivalence(regions[0]['region_source'], summary_source,
                    timeout_ms=timeout_ms, max_unroll=max_unroll, max_paths=max_paths,
                    smt_path=output/'lemmas/summary_encoding.smt2')
                save(output/'lemmas/summary_encoding.json', proof)
                result['obligations'].append({'id': 'summary_encoding', 'engine': 'custom symbolic execution / Z3', 'status': proof['status']})
                if proof['status'] != 'equivalent':
                    raise Unsupported('Generated exact summary was not proved equivalent: '+proof['status'])
                result['proof_dependencies'].append({'id': 'summary_encoding', 'result': 'lemmas/summary_encoding.json',
                    'smt': 'lemmas/summary_encoding.smt2', 'accepted_component_lemmas': proof.get('component_lemmas', [])})
                abstraction = 'exact'
                refinement['action'] = 'Replace shared havoc by a certified functional summary'
            except Unsupported as error:
                abstraction = 'none'; summary_source = None
                refinement.update(action='Restore the original region in the same C product program', reason=str(error))
                result['proof_dependencies'] = []
            result['refinements'].append(refinement)
            source = make_miter(left, right, contract, regions=regions if abstraction!='none' else None,
                                abstraction=abstraction, summary_source=summary_source)
            phase = verify_c_miter(source, output/'residual_1', executable=executable,
                                  max_unroll=max_unroll, timeout_ms=timeout_ms)
            final_phase = 'residual_1'
            result['obligations'].append({'id': final_phase, 'engine': 'ESBMC / Z3', 'abstraction': abstraction, 'status': phase['status']})
        result['residual_proof'] = {'directory': final_phase, 'abstraction': abstraction, **phase}
        raw_status = phase['status']; result['engine_status'] = raw_status
        result['status'] = {'equivalent':'equivalent', 'not_equivalent':'not_equivalent',
            'safety_violation':'undefined_behavior', 'incomplete_unwind':'inconclusive',
            'unknown':'inconclusive', 'unsupported':'unsupported', 'error':'error'}[raw_status]
        result['complete_unwinding_required'] = True
        if proposed_witness and result['status']=='not_equivalent':
            result['counterexample']=proposed_witness
            result['counterexample_validation']='Actual unabstracted C miter refuted at the custom SMT witness'
        elif result['status']=='not_equivalent':
            witness=counterexample_inputs(output/final_phase,contract)
            if witness is None:
                recovery=verify_c_miter(source,output/'counterexample_trace',executable=executable,
                    max_unroll=max_unroll,timeout_ms=timeout_ms,retain_inputs=True)
                result['counterexample_trace_recovery']=recovery
                if recovery['status']=='not_equivalent':
                    witness=counterexample_inputs(output/'counterexample_trace',contract)
                    if witness is not None:
                        result['counterexample_report']='counterexample_trace/report.json'
            if witness is not None:
                result['counterexample']=witness
                result['counterexample_validation']='Initial-state vector decoded from the concrete or exact-summary C product trace'
        if result['status']=='not_equivalent':
            if 'counterexample_report' not in result and (output/final_phase/'report.json').exists():
                result['counterexample_report']=final_phase+'/report.json'
        result['proof_scope'] = ('Residual C proof plus all listed certified region/encoding lemmas'
                                if result['proof_dependencies'] else 'Unabstracted C product-program verification')
    except Unsupported as error:
        result.update(status='unsupported', reason=str(error))
    except (InvalidC, OSError, ValueError, TypeError, subprocess.TimeoutExpired) as error:
        result.update(status='error', reason=str(error))
    finally:
        result['elapsed_seconds'] = round(time.perf_counter()-started,6)
        result['artifact_sha256']={p.relative_to(output).as_posix():sha(p.read_bytes())
            for p in sorted(output.rglob('*')) if p.is_file() and p != output/'result.json'}
        save(output/'result.json', result)
    return result
