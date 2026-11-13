#!/usr/bin/env python3
"""Emit every stored example observer. Emission is not V-G validation."""
from __future__ import annotations
import argparse,json,sys
from pathlib import Path
from uuid import uuid4
ROOT=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(ROOT))
from vwe.tasks import load_pipeline_view
from vwe.contract.env import TypeEnv
from vwe.contract.typecheck import typecheck
from vwe.contract.ast import Sort
from vwe.contract.emit import emit_function


def main(argv: list[str]|None=None) -> int:
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--out',type=Path,default=ROOT/'runs/contracts')
    args=p.parse_args(argv);folder=args.out.resolve()/uuid4().hex;folder.mkdir(parents=True)
    rows=[]
    for path in sorted((ROOT/'examples/tasks').iterdir()):
        task=load_pipeline_view(path)
        for reading in task.interpretations:
            env=TypeEnv.from_task(task,reading['shape'],allow_old=True)
            exprs=[('reach',reading['reach'])]
            if reading['ext']!='unknown': exprs.append(('ext',reading['ext']))
            exprs.extend((f'clause_{i}_{kind}',c[key]) for i,c in enumerate(reading['clauses'])
                         for kind,key in [('zone','zone'),('post','behaviour')])
            for kind,text in exprs:
                name=f've_contract_{len(rows)}';typed=typecheck(text,env,expected=Sort.BOOL)
                emitted=emit_function(typed,name=name);(folder/f'{name}.c').write_text(emitted.source)
                rows.append({'task':task.task_id,'reading':reading['id'],'kind':kind,'expression':text,
                             'function':name,'parameters':emitted.parameters,'old_symbols':emitted.uses_old,
                             'loop_limits':emitted.loop_limits,'status':'EMITTED_UNVALIDATED',
                             'vg_required':True,'old_definedness':'NOT_RUN'})
    (folder/'summary.json').write_text(json.dumps(rows,indent=2)+'\n')
    print(f'{len(rows)} observers emitted; V-G and old-definedness proofs remain NOT_RUN.\nArtifacts: {folder}')
    return 0


if __name__=='__main__': raise SystemExit(main())
