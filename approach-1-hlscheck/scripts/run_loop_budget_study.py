"""Retest bounded dynamic loops with a contract-derived unwinding resource cap.

The input precondition is unchanged, and unwinding assertions remain enabled.
Reducing an overlarge expansion cap is not restricting the input domain.
"""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json

from hlscheck import verify_equivalence
from hlscheck.evidence import verify_evidence

ROOT=Path(__file__).resolve().parents[1]


def main():
    manifest=json.loads((ROOT/'benchmarks/large/manifest.json').read_text())
    rows=[]
    for case in manifest['cases']:
        if case['family']!='dynamic_sum': continue
        folder=ROOT/'results/loop_budget'/case['id'];folder.mkdir(parents=True,exist_ok=True)
        old=json.loads((ROOT/'results/large'/case['id']/'evaluation.json').read_text())
        bound=case['scale']+1
        result=verify_equivalence((ROOT/case['original']).read_text(),(ROOT/case['candidate']).read_text(),
            case['function'],output_dir=folder/'proof',timeout_ms=60000,max_unroll=bound,scalar_ranges=case['scalar_ranges'])
        replay=verify_evidence(folder/'proof')
        row={'id':case['id'],'previous_status':old['status'],'previous_max_unroll':old['fingerprint']['max_unroll'],
            'max_unroll':bound,'timeout_ms_per_obligation':60000,'unchanged_scalar_ranges':case['scalar_ranges'],
            'status':result['status'],'elapsed_seconds':result['elapsed_seconds'],'verification':result,'evidence':replay,
            'scope':'Same C inputs and preconditions; smaller expansion cap with all unwinding assertions retained'}
        (folder/'evaluation.json').write_text(json.dumps(row,indent=2)+'\n');rows.append(row)
        print(case['id'],'unwind',bound,result['status'],round(result['elapsed_seconds'],3),'s',flush=True)
    (ROOT/'results/loop_budget/summary.json').write_text(json.dumps({'cases':rows},indent=2)+'\n')


if __name__=='__main__':
    main()
