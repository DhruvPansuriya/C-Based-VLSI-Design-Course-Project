#!/usr/bin/env python3
"""Demonstrate T02 structural admission; no repair verdicts are produced."""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import sys
from uuid import uuid4

ROOT=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(ROOT))
from vwe.admission import admit
from vwe.tasks import load_pipeline_view


def main(argv: list[str] | None = None) -> int:
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--out',type=Path,default=ROOT/'runs/admission')
    args=p.parse_args(argv)
    folder=args.out.resolve()/uuid4().hex
    rows=[]
    for name in ('ex1_saturate','ex2_argmax','ex4_sum'):
        result=admit(load_pipeline_view(ROOT/'examples/tasks'/name),'v1',out_dir=folder/name)
        rows.append({'task':name,'candidate':'v1','status':result.status,'reason':result.reason,
                     'artifact_dir':str(result.artifact_dir),'functional_proof':'NOT_RUN'})
        print(f'{name}: {result.status}; views_differ={result.views_differ}; {result.reason}')
    folder.mkdir(parents=True,exist_ok=True)
    (folder/'summary.json').write_text(json.dumps(rows,indent=2)+'\n')
    print(f'Artifacts: {folder}')
    return 0 if all(r['status']=='ok' for r in rows) else 1


if __name__=='__main__':
    raise SystemExit(main())
