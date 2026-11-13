"""Dimension-scaled checks and 60-second retries; no new hardware claims."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import argparse
from collections import Counter
import hashlib
import json

from hlscheck import verify_equivalence
from hlscheck.evidence import verify_evidence,replay_native_witness

ROOT=Path(__file__).resolve().parents[1]


def sha(path): return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def prepare():
    destination=ROOT/'benchmarks/large';destination.mkdir(exist_ok=True)
    cases=[]
    def add(name,family,n,original,candidate,expected='equivalent',words=None,ops=None,ranges=None):
        folder=destination/name;folder.mkdir(exist_ok=True)
        for label,text in [('original',original),('candidate',candidate)]:
            (folder/(label+'.c')).write_text('#include <stdint.h>\n'+text+'\n')
        cases.append({'id':name,'family':family,'scale':n,'original':(folder/'original.c').relative_to(ROOT).as_posix(),
            'candidate':(folder/'candidate.c').relative_to(ROOT).as_posix(),'function':'kernel','expected':expected,
            'input_words_u32':words,'dominant_operations_original':ops,'scalar_ranges':ranges or {},
            'origin':'Generated educational size-scaled kernel, not an unmodified external benchmark or a new model sampling experiment'})

    for n in (4,8,12,16):
        original=f'''void kernel(uint32_t a[{n*n}],uint32_t b[{n*n}],uint32_t out[{n*n}]){{
 for(int i=0;i<{n};i++)for(int j=0;j<{n};j++){{uint32_t s=0u;
  for(int k=0;k<{n};k++)s+=a[i*{n}+k]*b[k*{n}+j];out[i*{n}+j]=s;}}
}}'''
        candidate=f'''void kernel(uint32_t a[{n*n}],uint32_t b[{n*n}],uint32_t out[{n*n}]){{
 for(int p=0;p<{n*n};p++)out[p]=0u;
 for(int i=0;i<{n};i++)for(int k=0;k<{n};k++){{uint32_t v=a[i*{n}+k];
  for(int j=0;j<{n};j++)out[i*{n}+j]+=v*b[k*{n}+j];}}
}}'''
        add(f'gemm_{n}','gemm',n,original,candidate,words=3*n*n,ops=n**3)
        if n in (8,16):
            def indexed(text):
                text=text.replace('void kernel','uint32_t kernel').replace(f'out[{n*n}])',f'out[{n*n}],uint32_t index)')
                return text[:-1]+f'return out[index&{n*n-1}u];\n}}'
            indexed_a=indexed(original);indexed_b=indexed(candidate).replace(f'index&{n*n-1}u',f'index%{n*n}u')
            add(f'gemm_lookup_{n}','indexed_gemm',n,indexed_a,indexed_b,words=3*n*n+1,ops=n**3)
        if n==8:
            add('gemm_8_transpose_fault','gemm_fault',n,original,candidate.replace(f'b[k*{n}+j]',f'b[j*{n}+k]'),
                'not_equivalent',words=3*n*n,ops=n**3)

    for n in (32,64,128):
        original=f'void kernel(uint32_t a[{n}],uint32_t out[{n}]){{for(int i=0;i<{n};i++){{uint32_t s=0u;for(int j=0;j<=i;j++)s+=a[j];out[i]=s;}}}}'
        candidate=f'void kernel(uint32_t a[{n}],uint32_t out[{n}]){{uint32_t s=0u;for(int i=0;i<{n};i++){{s+=a[i];out[i]=s;}}}}'
        add(f'prefix_{n}','prefix',n,original,candidate,words=2*n,ops=n*(n+1)//2)
        if n==64:
            add('prefix_64_recurrence_fault','prefix_fault',n,original,candidate.replace('s+=a[i]','s+=a[0]'),
                'not_equivalent',words=2*n,ops=n*(n+1)//2)
        original=f'uint32_t kernel(uint32_t a[{n}],uint32_t b[{n}]){{uint32_t s=0u;for(int i=0;i<{n};i++)s+=a[i]*b[i];return s;}}'
        candidate=f'''uint32_t kernel(uint32_t a[{n}],uint32_t b[{n}]){{uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
 for(int i=0;i<{n};i+=4){{s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}}
 return (s0+s1)+(s2+s3);}}'''
        add(f'dot_{n}','dot',n,original,candidate,words=2*n,ops=n)
        if n==32:
            add('dot_32_lane_fault','dot_fault',n,original,candidate.replace('a[i+3]*b[i+3]','a[i+2]*b[i+3]'),
                'not_equivalent',words=2*n,ops=n)

    for n in (16,32,64):
        original=f'''uint32_t kernel(uint32_t a[{n}]){{uint32_t s=0u;for(int i=0;i<{n};i++){{
 int tap=i<{n//2}?i:{n-1}-i;s+=a[i]*(3u+2u*(unsigned)tap);}}return s;}}'''
        candidate=f'uint32_t kernel(uint32_t a[{n}]){{uint32_t s=0u;for(int i=0;i<{n//2};i++)s+=(a[i]+a[{n-1}-i])*(3u+2u*(unsigned)i);return s;}}'
        add(f'fir_{n}','fir',n,original,candidate,words=n,ops=n)
        if n==32:
            add('fir_32_coefficient_fault','fir_fault',n,original,candidate.replace('2u*(unsigned)i','2u*(unsigned)(i+1)'),
                'not_equivalent',words=n,ops=n)

    for n in (8,12,16):
        original=f'''void kernel(uint32_t a[{n*n}],uint32_t filter[9],uint32_t out[{n*n}]){{
 for(int r=0;r<{n-2};r++)for(int c=0;c<{n-2};c++){{uint32_t s=0u;
 for(int u=0;u<3;u++)for(int v=0;v<3;v++)s+=filter[u*3+v]*a[(r+u)*{n}+c+v];out[r*{n}+c]=s;}}}}'''
        candidate=f'''void kernel(uint32_t a[{n*n}],uint32_t filter[9],uint32_t out[{n*n}]){{
 for(int r=0;r<{n-2};r++)for(int c=0;c<{n-2};c++){{uint32_t s=0u;for(int u=0;u<3;u++){{
 int p=(r+u)*{n}+c;s+=filter[u*3]*a[p];s+=filter[u*3+1]*a[p+1];s+=filter[u*3+2]*a[p+2];}}out[r*{n}+c]=s;}}}}'''
        add(f'stencil_{n}','stencil',n,original,candidate,words=2*n*n+9,ops=(n-2)**2*9)

    for n in (4,8,16):
        original=f'uint32_t kernel(uint32_t a[{n}],uint32_t k,uint32_t out[{n}]){{for(int i=0;i<{n};i++)out[i]=a[i]*13u;return out[k&{n-1}u];}}'
        candidate=f'uint32_t kernel(uint32_t a[{n}],uint32_t k,uint32_t out[{n}]){{for(int i={n-1};i>=0;i--)out[i]=(a[i]<<3)+(a[i]<<2)+a[i];return a[k%{n}u]*13u;}}'
        add(f'correlation_{n}','correlation',n,original,candidate,words=2*n+1,ops=n)

    for n in (16,64):
        original=f'uint32_t kernel(uint32_t a[{n}],uint32_t n){{uint32_t s=0u;for(unsigned i=0u;i<n;i++)s+=a[i];return s;}}'
        candidate=f'''uint32_t kernel(uint32_t a[{n}],uint32_t n){{uint32_t s0=0u,s1=0u;
 for(unsigned i=0u;i+1u<n;i+=2u){{s0+=a[i];s1+=a[i+1u];}}if((n&1u)!=0u)s0+=a[n-1u];return s0+s1;}}'''
        add(f'dynamic_sum_{n}','dynamic_sum',n,original,candidate,words=n+1,ops=f'0..{n}',ranges={'n':[0,n]})

    for name in ('mixed_array_equivalent','local_range8_seed5292'):
        old=json.loads((ROOT/'results/hybrid/study'/name/'evaluation.json').read_text())
        cases.append({'id':'retry_'+name,'family':'budget_retry','scale':8,'original':old['original'],
            'candidate':old['candidate'],'function':old['function'],'expected':old['expected'],
            'previous_status':old['status'],'previous_timeout_ms':old['fingerprint']['timeout_ms'],
            'scalar_ranges':{},'origin':'Same exact sources as the preserved 10-second baseline'})
    manifest={'description':'Size-scaled checker experiments and 60-second retries; not new hardware measurements or independent application samples',
              'cases':cases}
    (destination/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    return cases


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--timeout-ms',type=int,default=60000)
    parser.add_argument('--families',nargs='*');parser.add_argument('--force',action='store_true')
    parser.add_argument('--max-unroll',type=int,default=256);args=parser.parse_args()
    cases=prepare();output=ROOT/'results/large';output.mkdir(exist_ok=True)
    engines={p.name:sha(p) for p in (ROOT/'hlscheck').glob('*.py')}
    # Retry the actual inconclusive cases first, then work through size sweeps.
    cases.sort(key=lambda c:(c['family']!='budget_retry',c['family'],c['scale']))
    rows=[]
    for case in cases:
        if args.families and case['family'] not in args.families: continue
        folder=output/case['id'];folder.mkdir(exist_ok=True)
        fingerprint={'source_sha256':[sha(ROOT/case['original']),sha(ROOT/case['candidate'])],
            'engine_sha256':engines,'timeout_ms':args.timeout_ms,'max_unroll':args.max_unroll,
            'scalar_ranges':case['scalar_ranges']}
        record=folder/'evaluation.json'
        if record.exists() and not args.force:
            old=json.loads(record.read_text())
            if old.get('fingerprint')==fingerprint:
                rows.append(old);print(case['id'],old['status'],'cached',flush=True);continue
        result=verify_equivalence((ROOT/case['original']).read_text(),(ROOT/case['candidate']).read_text(),case['function'],
            output_dir=folder/'proof',timeout_ms=args.timeout_ms,max_unroll=args.max_unroll,scalar_ranges=case['scalar_ranges'])
        evidence=verify_evidence(folder/'proof')
        native=replay_native_witness(folder/'proof',folder/'native') if result['status']=='not_equivalent' else {'available':False}
        row={**case,'fingerprint':fingerprint,'status':result['status'],'elapsed_seconds':result['elapsed_seconds'],
            'verification':result,'smt_replay':evidence,'native_witness':native,
            'matched_expected':None if case['expected'] is None else result['status']==case['expected']}
        record.write_text(json.dumps(row,indent=2)+'\n');rows.append(row)
        print(case['id'],result['status'],round(result['elapsed_seconds'],3),'s',
            'summaries',len(result['proof_dependencies']),'refinements',len(result['refinements']),
            'native',native.get('passed'),flush=True)
    summary={'total':len(rows),'timeout_ms_per_obligation':args.timeout_ms,'max_unroll':args.max_unroll,
        'counts':dict(Counter(r['status'] for r in rows)),
        'all_available_evidence_passed':all(r['smt_replay']['passed'] and r['native_witness'].get('passed',True) for r in rows),
        'matched_expected':sum(r['matched_expected'] is True for r in rows),
        'unresolved_expected':sum(r['matched_expected'] is False and r['status'] in ('inconclusive','unsupported','error') for r in rows),
        'contradictory_conclusive_verdicts':sum(r['matched_expected'] is False and r['status'] in ('equivalent','not_equivalent','undefined_behavior') for r in rows),
        'scope':'C equivalence only. Generated size-scaled families share algorithms; two retries reuse identical earlier sources. No added HLS QoR results.',
        'cases':rows}
    (output/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(json.dumps({k:v for k,v in summary.items() if k!='cases'},indent=2),flush=True)


if __name__=='__main__':
    main()
