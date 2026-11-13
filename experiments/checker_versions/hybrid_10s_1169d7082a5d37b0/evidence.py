"""Replay certified lemmas and native witnesses for integrated-checker evidence."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

import z3

from .frontend import ABI_ASSERTIONS, compile_pair
from .miter import literal, function_source


def verify_evidence(folder, *, timeout_ms=30000):
    folder=Path(folder); result=json.loads((folder/'result.json').read_text())
    sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
    for name,value in result['artifact_sha256'].items():
        if sha(folder/name)!=value: raise ValueError('Changed proof artifact: '+name)
    for name,value in result['implementation_sha256'].items():
        if sha(Path(__file__).parent/name)!=value: raise ValueError('Different implementation: '+name)
    rows=[]
    for dependency in result['proof_dependencies']:
        for lemma in dependency['accepted_component_lemmas']:
            if lemma['status']!='unsat': continue
            name=lemma['smt_file'].replace('\\','/').split('/')[-1]
            solver=z3.Solver();solver.set(timeout=timeout_ms);solver.from_file(str(folder/'lemmas'/name))
            observed=str(solver.check());rows.append({'query':'lemmas/'+name,'expected':'unsat','observed':observed})
        solver=z3.Solver();solver.set(timeout=timeout_ms);solver.from_file(str(folder/dependency['smt']))
        observed=str(solver.check());rows.append({'query':dependency['smt'],'expected':'unsat','observed':observed})
    return {'passed':all(r['observed']==r['expected'] for r in rows), 'queries':rows,
            'scope':'Current implementation and saved artifact hashes; accepted SMT lemmas replayed with Z3. ESBMC log retained, not an independent proof certificate.'}


def replay_native_witness(folder, destination):
    folder,destination=map(Path,(folder,destination));destination.mkdir(parents=True,exist_ok=True)
    result=json.loads((folder/'result.json').read_text())
    if result['status']!='not_equivalent' or 'counterexample' not in result:
        return {'available':False,'reason':'No complete concrete mismatch input'}
    original=(folder/'original_input.c').read_text();candidate=(folder/'candidate_input.c').read_text()
    left,right,contract=compile_pair(original,candidate,scalar_ranges=result['contract']['scalar_ranges'])
    witness=result['counterexample'];lines=['#include <stdio.h>',ABI_ASSERTIONS,
        function_source(left,'__hlscheck_original'),function_source(right,'__hlscheck_candidate'),'int main(void){']
    a_args=[];b_args=[];conditions=[]
    for p in left.parameters:
        i,kind,n=p['position'],p['c_type'],p['length']
        a,b=f'input_a_{i}',f'input_b_{i}';a_args.append(a);b_args.append(b)
        if n is None:
            lines += [f'{kind} {a}={literal(witness[p["name"]],p)};',f'{kind} {b}={a};']
        else:
            values=','.join(literal(x,p) for x in witness[p['name']])
            lines += [f'{kind} {a}[{n}]={{{values}}};',f'{kind} {b}[{n}]={{{values}}};']
            conditions += [f'{a}[{j}]!={b}[{j}]' for j in range(n)]
    a_call='__hlscheck_original('+','.join(a_args)+')'
    b_call='__hlscheck_candidate('+','.join(b_args)+')'
    if left.return_type.c_type=='void': lines += [a_call+';',b_call+';']
    else:
        kind=left.return_type.c_type
        lines += [f'{kind} a_return={a_call};',f'{kind} b_return={b_call};']
        conditions += ['a_return!=b_return']
    test=' || '.join(conditions) or '0'
    lines += [f'int mismatch=({test});','printf("%d\\n",mismatch);return !mismatch;}']
    source=destination/'witness.c';source.write_text('\n'.join(lines)+'\n')
    compiler=shutil.which('clang')
    if not compiler: return {'available':False,'reason':'Clang unavailable'}
    executable=destination/'witness_check.exe'
    built=subprocess.run([compiler,'-std=c11','-O2',str(source),'-o',str(executable)],capture_output=True,text=True,timeout=30)
    (destination/'compile.log').write_text(built.stdout+built.stderr)
    if built.returncode: return {'available':True,'passed':False,'reason':'Native build failed, including integer/pointer ABI assertions'}
    try:
        run=subprocess.run([str(executable.resolve())],capture_output=True,text=True,timeout=10)
    except subprocess.TimeoutExpired:
        return {'available':True,'passed':False,'reason':'Native witness exceeded execution limit'}
    (destination/'run.log').write_text(run.stdout+run.stderr)
    return {'available':True,'passed':run.returncode==0 and run.stdout.strip()=='1',
            'harness_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
            'scope':'Actual original C and candidate C at the complete verified input; no abstract state is executed'}
