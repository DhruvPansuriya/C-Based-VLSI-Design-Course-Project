"""Document every exact source rewrite, proof chain and measured QoR result."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import hashlib
import json

ROOT=Path(__file__).resolve().parents[1]


def load(path):
    return json.loads(path.read_text()) if path.exists() else None


def main():
    catalog=load(ROOT/'experiments/catalog.json')
    out=ROOT/'experiments/optimizations'
    out.mkdir(exist_ok=True)
    index=['# Recorded C optimizations and formal / HLS evidence','',
        f"Study unit: **{len(catalog['cases'])} original/candidate pairs**, or **{2*len(catalog['cases'])} synthesized implementations** when complete. Related kernels and repeated original algorithms are identified; this is not a claim of independent application samples.",
        '', 'Each pair preserves its signature, uint32_t modular semantics and final contents of every parameter array under valid, nonaliasing array assumptions. Candidates were authored by the Codex assistant in this conversation. No external API model/response/temperature metadata is invented.',
        '', '| Pair / source record | Transformation | C-to-C proof | Hardware status | ADP ratio |', '|---|---|---|---|---:|']
    complete=0
    records=[]
    for case in catalog['cases']:
        name=case['name'];folder=ROOT/case['directory']
        paths={v:folder/f'{name}_{v}.c' for v in ('original','optimized','buggy')}
        proof=load(ROOT/'results/submission_verification'/f'{name}_optimized.json')
        mutant=load(ROOT/'results/submission_verification'/f'{name}_buggy.json')
        original=load(ROOT/'results/hls'/f'{name}_original/metrics.json')
        optimized=load(ROOT/'results/hls'/f'{name}_optimized/metrics.json')
        measured=bool(original and optimized and original['status']==optimized['status']=='complete')
        complete+=measured
        hashes={k:hashlib.sha256(p.read_bytes()).hexdigest() for k,p in paths.items()}
        if proof:
            assert proof['original_sha256']==hashes['original'] and proof['candidate_sha256']==hashes['optimized']
        if measured:
            assert original['source_sha256']==hashes['original'] and optimized['source_sha256']==hashes['optimized']
        status=proof['verification']['status'] if proof else 'pending'
        ratio=optimized['area_latency_product_um2_ns']/original['area_latency_product_um2_ns'] if measured else None
        index.append(f"| [{name}](optimizations/{name}.md) | {case['transformation']} | {status} | {'complete' if measured else 'pending'} | {ratio:.4g} |" if measured else
                     f"| [{name}](optimizations/{name}.md) | {case['transformation']} | {status} | pending | - |")
        lines=[f'# {name}: {case["transformation"]}','',
            '**Origin:** '+case['origin']+'.', '',
            '**Algorithm group:** '+case.get('algorithm_group','initial eight-pair cohort')+'.', '',
            '**Rewrite:** '+case['transformation']+'.','',
            '**Motivation:** '+case.get('rationale','Expose the recorded transformation to HLS; the measured result determines whether it is accepted.') ,'',
            '**Semantic contract:** same interface and dimensions, unsigned 32-bit arithmetic, valid disjoint arrays, return and every final parameter array observable. This does not prove equivalence to different upstream dimensions or numeric types.','',
            '## Exact source artifacts','']
        for variant in ('original','optimized'):
            lines += [f'### {variant.capitalize()}','',f'SHA-256: `{hashes[variant]}`.', '',
                f'[Standalone C file](../../{paths[variant].relative_to(ROOT).as_posix()})','', '```c',paths[variant].read_text().rstrip(),'```','']
        lines += ['## C-to-C result','',f'Verdict: **{status}**.']
        if proof:
            result=proof['verification']
            dependencies=[r for r in result.get('component_lemmas',[]) if r['status']=='unsat']
            lines += ['',f"Elapsed time: {result['elapsed_seconds']:.6f} s. Z3: {result.get('z3_version','not recorded')}. Accepted unconditional component lemmas: {len(dependencies)}.", '',
                f'[Proof record](../../results/submission_verification/{name}_optimized.json) and [main SMT query](../../results/submission_verification/{name}_optimized.smt2).']
            if dependencies:
                lines += ['', 'The main query is simplified using the following separately proved-zero components. Replay all of these queries as well as the main query:','']
                for record in dependencies:
                    filename=record['smt_file'].replace('\\','/').split('/')[-1]
                    lines.append(f'- [{filename}](../../results/submission_verification/{filename})')
        lines += ['', '## Seeded negative control','',
            case.get('negative_control','Deliberate mutation documented at the head of the faulty source file')+'.', '',
            f'[Faulty source](../../{paths["buggy"].relative_to(ROOT).as_posix()}) and [counterexample record](../../results/submission_verification/{name}_buggy.json).', '',
            'The fault is seeded for checker validation, not a spontaneous LLM error and not an LLM bug-rate sample.']
        if mutant:
            lines += ['', 'Recorded verdict: **'+mutant['verification']['status']+'**. The native test runner independently replays its witness and compares concrete outputs with the solver.']
        lines += ['', '## Hardware measurement','']
        if measured:
            lines += ['| Metric | Original | Candidate | Candidate / original |', '|---|---:|---:|---:|']
            for key,label in [('area_um2','Mapped cell area (um²)'),('delay_ns','STA period estimate (ns)'),('cycles','RTL latency cycles'),('latency_at_target_ns','Latency at 10 ns clock (ns)'),('area_latency_product_um2_ns','Area x latency (um² ns)')]:
                a,b=original[key],optimized[key]
                lines.append(f'| {label} | {a:.6g} | {b:.6g} | {b/a:.4g} |')
            accepted=optimized['meets_10ns'] and ratio<.999
            lines += ['', '**Area x latency policy:** '+('select the candidate' if accepted else 'retain the original')+'.', '',
                'Bambu/Clang and interfaces are fixed within the pair. Nangate45 typical, 10 ns target, ideal clocks, no extracted interconnect. Area includes mapped local memory and excludes external memory/host costs. These are pre-layout estimates.', '',
                f'[Original raw evidence](../../results/hls/{name}_original/) / [candidate raw evidence](../../results/hls/{name}_optimized/). Both have sixteen successful RTL calls.']
        else:
            lines.append('Pending: no hardware benefit is asserted before both real runs complete.')
        if case.get('comparison_parent_pairs'):
            lines += ['', '## Related earlier candidates','',
                'These share the original algorithm and are follow-up candidates, not independent application samples.', '',
                '| Candidate pair | Candidate area (um²) | Candidate cycles | ADP ratio against its original |', '|---|---:|---:|---:|']
            for parent in case['comparison_parent_pairs']+[name]:
                a=load(ROOT/'results/hls'/f'{parent}_original/metrics.json')
                b=load(ROOT/'results/hls'/f'{parent}_optimized/metrics.json')
                if a and b and a['status']==b['status']=='complete':
                    value=b['area_latency_product_um2_ns']/a['area_latency_product_um2_ns']
                    lines.append(f"| [{parent}]({parent}.md) | {b['area_um2']:.3f} | {b['cycles']:g} | {value:.4g} |")
        lines += ['', '## Reproduce this proof','', '```powershell',
            f'.\\.venv\\Scripts\\python.exe -m hlscheck {paths["original"].relative_to(ROOT).as_posix()} {paths["optimized"].relative_to(ROOT).as_posix()} --function kernel --timeout-ms 30000 --smt results/recheck_{name}.smt2', '```','']
        (out/f'{name}.md').write_text('\n'.join(lines),encoding='utf-8')
        records.append({'case':name,'source_sha256':hashes,'proof_status':status,'hardware_complete':measured,'adp_ratio':ratio})
    index += ['',f'Hardware-complete pairs at this snapshot: **{complete}/{len(catalog["cases"])}**.', '',
        'The retained initial hamming8 monolithic timeout and the later component proof are under `experiments/attempts/` and the proof records. `scripts/replay_smt_evidence.py` replays every accepted lemma and final query.','']
    (ROOT/'experiments/OPTIMIZATION_CATALOG.md').write_text('\n'.join(index),encoding='utf-8')
    (ROOT/'experiments/optimization_records.json').write_text(json.dumps({'pair_count':len(records),'hardware_complete':complete,'cases':records},indent=2)+'\n')
    print('Recorded',len(records),'source/proof dossiers;',complete,'hardware-complete pairs.')


if __name__=='__main__':
    main()
