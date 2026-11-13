"""Replay every core proof query, including all accepted component lemmas."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
import json
import z3
from pycparser import c_ast
from hlscheck.checker import parse

ROOT=Path(__file__).resolve().parents[1]


def resolve_lemma(path):
    # Result records can contain Windows absolute paths from the measured run.
    # Match the filename inside the local proof-evidence directory for portability.
    name=path.replace('\\','/').split('/')[-1]
    return ROOT/'results/submission_verification'/name


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--timeout-ms',type=int,default=30000);args=parser.parse_args()
    proof=json.loads((ROOT/'results/submission_verification/summary.json').read_text())
    rows=[]
    for row in proof['cases']:
        identifier=row['case']+'_'+row['variant']
        dependencies=[]
        for lemma in row['verification'].get('component_lemmas',[]):
            if lemma['status']!='unsat':continue
            path=resolve_lemma(lemma['smt_file']);solver=z3.Solver();solver.set(timeout=args.timeout_ms);solver.from_file(str(path));verdict=str(solver.check())
            dependencies.append({'file':str(path.relative_to(ROOT)),'status':verdict})
        path=ROOT/'results/submission_verification'/(identifier+'.smt2')
        solver=z3.Solver();solver.set(timeout=args.timeout_ms);solver.from_file(str(path))
        witness_pinned=row['expected']=='not_equivalent'
        if witness_pinned:
            # A recorded counterexample is a SAT certificate: checking it is
            # deterministic and avoids a second nonlinear model search.
            original_path=ROOT/row['original'].replace('\\','/')
            fn=parse(original_path.read_text(),'kernel')
            witness=row['verification']['counterexample']
            for position,parameter in enumerate(fn.decl.type.args.params):
                value=witness[parameter.name]
                if isinstance(parameter.type,c_ast.ArrayDecl):
                    for index,element in enumerate(value):
                        solver.add(z3.BitVec(f'arg{position}_{index}',32)==element)
                else:
                    solver.add(z3.BitVec(f'arg{position}',32)==value)
        verdict=str(solver.check())
        expected='unsat' if row['expected']=='equivalent' else 'sat'
        passed=verdict==expected and all(d['status']=='unsat' for d in dependencies)
        rows.append({'case':identifier,'expected_smt_status':expected,'replayed_status':verdict,'dependencies':dependencies,'witness_pinned':witness_pinned,'passed':passed})
        print(identifier,verdict,'lemmas',len(dependencies),flush=True)
    result={'passed':all(r['passed'] for r in rows),'scope':'UNSAT queries/lemmas replayed unrestricted; SAT queries replayed at their recorded witnesses. Same Z3 implementation, not independent proof-certificate checking.','cases':rows}
    (ROOT/'results/submission/smt_replay.json').write_text(json.dumps(result,indent=2)+'\n')
    return 0 if result['passed'] else 1


if __name__=='__main__':
    raise SystemExit(main())
