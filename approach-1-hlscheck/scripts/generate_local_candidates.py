"""Collect raw, unedited small-model optimization attempts at zero API cost."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
import hashlib
import json
import re
import time
import urllib.request

ROOT=Path(__file__).resolve().parents[1]
ENDPOINT='http://127.0.0.1:8089'
SELECTED=['prefix','gemm','stencil','fir','boxfilter','moving_sum16','integral_image4','histogram4',
          'syrk4','triangular_matvec4','parity32','popcount8','bitreverse32','absdiff16','min8',
          'threshold_pack8','quadratic','convolution1d8','range8','deinterleave16']
SYSTEM='You optimize C11 functions for high-level synthesis. Preserve exact C behavior and the full interface. Return only the complete C source code, with no explanation.'
INSTRUCTION='''Rewrite the following function to improve hardware area or function latency in HLS.
Preserve its exact function name, return type, parameter types, array dimensions,
every return value, and all final parameter-array contents for every admitted input.
All uint32_t data use modulo-2^32 arithmetic. Arrays are valid and nonoverlapping.
Do not add input restrictions. Use C11, not C++. Emit exactly one function, include
stdint.h, and use no helper functions, dynamic memory, extra macros, or vendor pragmas.
Use source transformations such as reuse, loop restructuring, or exposed parallelism
when useful. Preserve unsigned overflow, boundary elements and edge cases.

Original source:
```c
{source}
```
'''


def get_json(url):
    return json.load(urllib.request.urlopen(url,timeout=30))


def extract_code(content):
    blocks=re.findall(r'```(?:c|C|cpp|c\+\+)?\s*\n(.*?)```',content,re.S)
    if blocks:
        return max(blocks,key=len).strip()+'\n','largest fenced code block; no semantic edits'
    return content.strip()+'\n','entire response; no semantic edits'


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--limit',type=int,default=40);args=parser.parse_args()
    catalog=json.loads((ROOT/'experiments/catalog.json').read_text())
    cases={c['name']:c for c in catalog['cases']}
    provenance=json.loads((ROOT/'tools/local_llm/PROVENANCE.json').read_text())
    model_id=get_json(ENDPOINT+'/v1/models')['data'][0]['id']
    plan=[]
    for seed,temperature in [(5291,.2),(5292,.8)]:
        for name in SELECTED:
            c=cases[name];source_path=ROOT/c['directory']/(name+'_original.c');source=source_path.read_text()
            identifier=f'{name}_seed{seed}'
            request={'model':model_id,'messages':[{'role':'system','content':SYSTEM},{'role':'user','content':INSTRUCTION.format(source=source)}],
                'seed':seed,'temperature':temperature,'top_p':.95,'max_tokens':1536,'stream':False}
            plan.append({'id':identifier,'case':name,'source':str(source_path.relative_to(ROOT)),
                'source_sha256':hashlib.sha256(source_path.read_bytes()).hexdigest(),'request':request})
    plan_record={'provider':'Local llama.cpp / NVIDIA Vulkan','model_provenance':provenance,'endpoint':ENDPOINT,
        'api_charge_usd':0,'selection':SELECTED,'sample_count':len(plan),
        'protocol':'Fixed 20 sources x 2 seeds/temperatures. No verifier feedback or manual correction. All outcomes retained.',
        'truncation_policy':'Length-limited responses are separately labeled; syntax failures are not semantic counterexamples.',
        'attempts':plan}
    destination=ROOT/'experiments/local_model';destination.mkdir(exist_ok=True)
    (destination/'plan.json').write_text(json.dumps(plan_record,indent=2)+'\n')
    output=ROOT/'results/local_llm/generations';output.mkdir(exist_ok=True,parents=True)
    for item in plan[:args.limit]:
        folder=output/item['id'];folder.mkdir(exist_ok=True)
        request_bytes=json.dumps(item['request'],ensure_ascii=False).encode()
        request_hash=hashlib.sha256(request_bytes).hexdigest()
        record_path=folder/'generation.json'
        if record_path.exists():
            old=json.loads(record_path.read_text())
            if old.get('request_sha256')==request_hash and (folder/'response.json').exists():
                print(item['id'],'cached',flush=True);continue
            raise RuntimeError('Existing response belongs to a different prompt/configuration')
        (folder/'request.json').write_bytes(request_bytes+b'\n')
        (folder/'original.c').write_bytes((ROOT/item['source']).read_bytes())
        started=time.perf_counter()
        request=urllib.request.Request(ENDPOINT+'/v1/chat/completions',data=request_bytes,headers={'Content-Type':'application/json'})
        with urllib.request.urlopen(request,timeout=300) as response:
            raw=response.read()
        (folder/'response.json').write_bytes(raw)
        data=json.loads(raw);choice=data['choices'][0];content=choice['message'].get('content') or ''
        (folder/'response.txt').write_text(content,encoding='utf-8')
        code,extraction=extract_code(content)
        (folder/'candidate.c').write_text(code,encoding='utf-8')
        record={**{k:v for k,v in item.items() if k!='request'},'request_sha256':request_hash,
            'raw_response_sha256':hashlib.sha256(raw).hexdigest(),'candidate_sha256':hashlib.sha256((folder/'candidate.c').read_bytes()).hexdigest(),
            'finish_reason':choice.get('finish_reason'),'usage':data.get('usage'),'timings':data.get('timings'),
            'elapsed_seconds':round(time.perf_counter()-started,3),'extraction':extraction,
            'model_repository':provenance['model_repository'],'model_revision':provenance['model_revision'],
            'model_sha256':provenance['model_sha256'],'runtime_release':provenance['runtime_release'],
            'origin':'Actual independently generated local-model optimization attempt; not an injected mutation',
            'manual_semantic_edits':False,'api_charge_usd':0}
        record_path.write_text(json.dumps(record,indent=2)+'\n')
        print(item['id'],record['finish_reason'],record['usage'],record['elapsed_seconds'],'s',flush=True)
    print('Raw candidates saved. Evaluate separately; no generation requests contain solver feedback.',flush=True)


if __name__=='__main__':
    main()
