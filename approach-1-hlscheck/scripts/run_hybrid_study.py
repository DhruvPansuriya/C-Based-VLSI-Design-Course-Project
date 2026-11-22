"""Evaluate the integrated algorithm separately from immutable historical runs."""

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
import time

from pycparser import c_ast, c_generator
from hlscheck import verify_equivalence
from hlscheck.checker import parse, check_equivalence
from hlscheck.frontend import compile_pair
from hlscheck.hybrid import verify_c_miter
from hlscheck.miter import make_miter
from hlscheck.evidence import verify_evidence,replay_native_witness

ROOT=Path(__file__).resolve().parents[1]


def read(path): return json.loads((ROOT/path).read_text())
def filehash(path): return hashlib.sha256(path.read_bytes()).hexdigest()


def prepare_gemm_lookup():
    target=ROOT/'benchmarks/hybrid';target.mkdir(exist_ok=True)
    for variant in ('original','optimized'):
        path=ROOT/'benchmarks/machsuite_u32'/('gemm_'+variant+'.c')
        fn=parse(path.read_text(),'kernel')
        fn.decl.name=fn.decl.type.type.declname='gemm_lookup'
        fn.decl.type.type.type=c_ast.IdentifierType(['unsigned','int'])
        extra=parse('void f(unsigned index){}',None).decl.type.args.params[0]
        fn.decl.type.args.params.append(extra)
        index=c_ast.BinaryOp('&' if variant=='original' else '%',c_ast.ID('index'),c_ast.Constant('unsigned int','15u' if variant=='original' else '16u'))
        fn.body.block_items.append(c_ast.Return(c_ast.ArrayRef(c_ast.ID('prod'),index)))
        text='/* Reduced MachSuite-derived GEMM plus indexed read; see LICENSE.MachSuite. */\n'+c_generator.CGenerator().visit(fn)+'\n'
        (target/('gemm_lookup_'+variant+'.c')).write_text(text)
    shutil.copyfile(ROOT/'benchmarks/machsuite_u32/LICENSE',target/'LICENSE.MachSuite')


def cases():
    selected=[]
    for row in read('experiments/catalog.json')['cases']:
        folder=ROOT/row['directory'];name=row['name']
        for variant,expected in [('optimized','equivalent'),('buggy','not_equivalent')]:
            selected.append({'id':'main_'+name+'_'+variant,'cohort':'main','original':folder/(name+'_original.c'),
                'candidate':folder/(name+'_'+variant+'.c'),'function':'kernel','expected':expected})
    for row in read('experiments/local_model/plan.json')['attempts']:
        folder=ROOT/'results/local_llm/generations'/row['id']
        old=read('results/local_llm/evaluations/'+row['id']+'/evaluation.json')['status']
        expected={'candidate_undefined':'undefined_behavior','compile_failure':'error'}.get(old,old)
        if expected in ('unknown','unsupported','error'): expected=None
        selected.append({'id':'local_'+row['id'],'cohort':'local_model','original':folder/'original.c',
            'candidate':folder/'candidate.c','function':'kernel','expected':expected,'previous_status':old})
    for row in read('experiments/subtle_faults/manifest.json')['cases']:
        folder=ROOT/row['directory']
        selected.append({'id':'subtle_'+row['id'],'cohort':'subtle','original':folder/'original.c','candidate':folder/'candidate.c',
            'function':'kernel','expected':{'candidate_undefined':'undefined_behavior'}.get(row['expected'],row['expected'])})
    for row in read('experiments/dataset_leaves/manifest.json')['cases']:
        folder=ROOT/row['directory']
        for variant,expected in [('optimized','equivalent'),('buggy','not_equivalent')]:
            selected.append({'id':'leaf_'+row['id']+'_'+variant,'cohort':'public_leaves','original':folder/'original.c',
                'candidate':folder/(variant+'.c'),'function':row['function'],'expected':expected})
    for variant,expected in [('equivalent','equivalent'),('incorrect','not_equivalent')]:
        selected.append({'id':'mixed_array_'+variant,'cohort':'mixed','original':ROOT/'benchmarks/hybrid/array_region_original.c',
            'candidate':ROOT/('benchmarks/hybrid/array_region_'+variant+'.c'),'function':'transform','expected':expected})
    selected.append({'id':'mixed_gemm_lookup','cohort':'mixed','original':ROOT/'benchmarks/hybrid/gemm_lookup_original.c',
        'candidate':ROOT/'benchmarks/hybrid/gemm_lookup_optimized.c','function':'gemm_lookup','expected':'equivalent'})
    return selected


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--cohorts',nargs='*');parser.add_argument('--timeout-ms',type=int,default=10000)
    parser.add_argument('--force',action='store_true');parser.add_argument('--ablation',action='store_true')
    args=parser.parse_args();prepare_gemm_lookup()
    rows=[];all_cases=cases();engine={p.name:filehash(p) for p in (ROOT/'hlscheck').glob('*.py')}
    output=ROOT/'results/hybrid/study';output.mkdir(exist_ok=True,parents=True)
    for case in all_cases:
        if args.cohorts and case['cohort'] not in args.cohorts: continue
        folder=output/case['id'];fingerprint={'sources':[filehash(case['original']),filehash(case['candidate'])],
            'engine':engine,'driver':filehash(Path(__file__)),'timeout_ms':args.timeout_ms}
        path=folder/'evaluation.json'
        if path.exists() and not args.force:
            old=json.loads(path.read_text())
            if old.get('fingerprint')==fingerprint:
                rows.append(old);print(case['id'],old['status'],'cached',flush=True);continue
        result=verify_equivalence(case['original'].read_text(),case['candidate'].read_text(),function=case['function'],
                                  output_dir=folder/'proof',timeout_ms=args.timeout_ms)
        replay=verify_evidence(folder/'proof')
        native=replay_native_witness(folder/'proof',folder/'native') if result['status']=='not_equivalent' else {'available':False}
        row={**{k:v for k,v in case.items() if k not in ('original','candidate')},
             'original':case['original'].relative_to(ROOT).as_posix(),'candidate':case['candidate'].relative_to(ROOT).as_posix(),
             'fingerprint':fingerprint,'status':result['status'],'elapsed_seconds':result['elapsed_seconds'],
             'accepted_summary':bool(result['proof_dependencies']), 'refinement_count':len(result['refinements']),
             'smt_replay':replay,'native_witness':native,'verification':result}
        row['matched_expected']=None if case['expected'] is None else result['status']==case['expected']
        path.write_text(json.dumps(row,indent=2)+'\n');rows.append(row)
        print(case['id'],result['status'],'summary',row['accepted_summary'],'refinements',row['refinement_count'],
              'native',native.get('passed'),round(result['elapsed_seconds'],3),'s',flush=True)
    summary={'algorithm':'Certified relational summary abstraction/refinement plus residual C verification',
        'total':len(rows),'counts':dict(Counter(r['status'] for r in rows)),
        'cohort_counts':{c:dict(Counter(r['status'] for r in rows if r['cohort']==c)) for c in sorted({r['cohort'] for r in rows})},
        'matched_known_labels':sum(r['matched_expected'] is True for r in rows),
        'known_labels':sum(r['expected'] is not None for r in rows),
        'accepted_summaries':sum(r['accepted_summary'] for r in rows),'refined_cases':sum(r['refinement_count']>0 for r in rows),
        'all_accepted_smt_replays_passed':all(r['smt_replay']['passed'] for r in rows),
        'available_native_witnesses':sum(r['native_witness']['available'] for r in rows),
        'all_available_native_witnesses_passed':all(r['native_witness'].get('passed',True) for r in rows),'cases':rows}
    (output/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps({k:v for k,v in summary.items() if k!='cases'},indent=2),flush=True)
    if args.ablation:
        ablation=[]
        for case in [c for c in all_cases if c['cohort']=='mixed']:
            folder=ROOT/'results/hybrid/ablation'/case['id'];folder.mkdir(exist_ok=True,parents=True)
            original=case['original'].read_text();candidate=case['candidate'].read_text()
            symbolic=check_equivalence(original,candidate,case['function'],timeout_ms=args.timeout_ms,smt_path=folder/'symbolic.smt2')
            left,right,contract=compile_pair(original,candidate,case['function'])
            monolithic=verify_c_miter(make_miter(left,right,contract),folder/'monolithic',timeout_ms=args.timeout_ms)
            hybrid=json.loads((output/case['id']/'evaluation.json').read_text())
            ablation.append({'id':case['id'],'standalone_symbolic':symbolic,'monolithic_bmc':monolithic,
                'hybrid_status':hybrid['status'],'hybrid_elapsed_seconds':hybrid['elapsed_seconds'],
                'hybrid_accepted_summary':hybrid['accepted_summary'],'hybrid_refinements':hybrid['refinement_count']})
            print('ablation',case['id'],symbolic['status'],monolithic['status'],hybrid['status'],flush=True)
        (ROOT/'results/hybrid/ablation/summary.json').write_text(json.dumps({'cases':ablation,'scope':'One measured run per method, common per-obligation limits. Hybrid may issue multiple obligations; not an equal-total-budget or statistical speedup study.'},indent=2)+'\n')


if __name__=='__main__':
    main()
