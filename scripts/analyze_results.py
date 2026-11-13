"""Check provenance and summarize the complete, measured project experiment."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import hashlib
import json
from collections import Counter

ROOT = Path(__file__).resolve().parents[1]


def main():
    proof = json.loads((ROOT/'results/submission_verification/summary.json').read_text())
    native = json.loads((ROOT/'results/native/summary.json').read_text())
    hls = json.loads((ROOT/'results/hls/summary.json').read_text())
    catalog = json.loads((ROOT/'experiments/catalog.json').read_text())
    assert proof['passed'] and native['passed'] and hls['passed']
    count=len(catalog['cases'])
    assert len(proof['cases'])==2*count and len(hls['cases'])==2*count
    for row in proof['cases']:
        for path,key in [('original','original_sha256'),('candidate','candidate_sha256')]:
            assert hashlib.sha256((ROOT/row[path]).read_bytes()).hexdigest()==row[key],f"Stale proof: {row[path]}"
    assert len(native['cases'])==count
    assert {r['case'] for r in native['cases']}=={c['name'] for c in catalog['cases']}
    case_by_name={c['name']:c for c in catalog['cases']}
    for row in native['cases']:
        folder=ROOT/case_by_name[row['case']]['directory']
        for variant in ('original','optimized','buggy'):
            assert row['source_sha256'][variant]==hashlib.sha256((folder/(row['case']+'_'+variant+'.c')).read_bytes()).hexdigest()
    assert {(r['case'],r['variant']) for r in hls['cases']}=={(c['name'],v) for c in catalog['cases'] for v in ('original','optimized')}
    for row in hls['cases']:
        assert row['status']=='complete' and row['rtl_simulation_passed']
        assert row['timing_coverage']['all_are_constant_outputs']
        assert hashlib.sha256((ROOT/row['source']).read_bytes()).hexdigest()==row['source_sha256']
    by_key={(r['case'],r['variant']):r for r in hls['cases']}
    comparisons=[]
    for case in catalog['cases']:
        name=case['name']
        a,b=[by_key[name,v] for v in ('original','optimized')]
        ratios={key:b[key]/a[key] for key in ('area_um2','delay_ns','cycles','area_latency_product_um2_ns')}
        choice='optimized' if b['meets_10ns'] and ratios['area_latency_product_um2_ns']<0.999 else 'original'
        comparisons.append({'case':name,'transformation':case['transformation'],'original':a,'optimized':b,
            'ratios':ratios,'selected_for_area_latency':choice,
            'selection_reason':'Lower area x latency at the common feasible 10 ns clock' if choice=='optimized' else 'Retain original: no area x latency improvement at the common clock'})
    summary={'passed':True,'benchmark_families':count,'design_pairs':count,'synthesized_implementations':2*count,
        'proved_optimized_pairs':sum(r['variant']=='optimized' and r['verification']['status']=='equivalent' for r in proof['cases']),
        'rejected_seeded_mutants':sum(r['variant']=='buggy' and r['verification']['status']=='not_equivalent' for r in proof['cases']),
        'native_optimized_trials':sum(r['trials'] for r in native['cases']),
        'native_witnesses_replayed':sum(r['bug_witness_replayed'] and r['concrete_outputs_match_solver'] for r in native['cases']),
        'rtl_simulation_calls':sum(r['rtl_simulation_calls'] for r in hls['cases']),
        'selected_optimized':sum(r['selected_for_area_latency']=='optimized' for r in comparisons),'comparisons':comparisons}
    summary['qor_outcomes']={
        'area_improved':sum(r['ratios']['area_um2']<.999 for r in comparisons),
        'cycles_improved':sum(r['ratios']['cycles']<.999 for r in comparisons),
        'delay_improved':sum(r['ratios']['delay_ns']<.999 for r in comparisons),
        'area_latency_improved':sum(r['ratios']['area_latency_product_um2_ns']<.999 for r in comparisons),
        'area_latency_regressed':sum(r['ratios']['area_latency_product_um2_ns']>1.001 for r in comparisons),
        'area_latency_unchanged':sum(.999<=r['ratios']['area_latency_product_um2_ns']<=1.001 for r in comparisons)}
    summary['group_counts']=dict(Counter(c.get('algorithm_group','initial cohort') for c in catalog['cases']))
    from hlscheck.checker import parse
    from pycparser.c_generator import CGenerator
    canonical=set()
    for c in catalog['cases']:
        path=ROOT/c['directory']/(c['name']+'_original.c')
        canonical.add(CGenerator().visit(parse(path.read_text(),'kernel')))
    summary['unique_original_c_asts']=len(canonical)
    summary['sampling_note']='LLM-authored educational variants and feedback candidates sharing original baselines; not independently sampled applications or an LLM success-rate estimate'
    summary['timing_met_implementations']=sum(r['meets_10ns'] for r in hls['cases'])
    out=ROOT/'results/submission'
    out.mkdir(exist_ok=True,parents=True)
    (out/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    lines=['# Measured HLS results','',
        'Bambu 2026.11 / Clang 16, BAMBU-BALANCED-MP (-O2), seed 0; Yosys 0.36; OpenSTA 2.0.18.',
        'Nangate45 typical (1.1 V, 25 C), common 10 ns clock. Cell area includes the mapped accelerator; external host/memory is excluded.',
        'Delay is 10 ns minus worst max-path slack: ideal clocks, zero input/output delays, 50 ps input transition, 10 fF output load, no extracted interconnect.',
        f"These are pre-layout synthesis estimates, not FPGA LUT counts or routed timing. {summary['timing_met_implementations']}/{2*count} implementations meet the chosen clock in this model.",'',
        '| Kernel | Area original → candidate (um²) | Delay original → candidate (ns) | Cycles original → candidate | ADP ratio | ADP choice |',
        '|---|---:|---:|---:|---:|---|']
    for r in comparisons:
        a,b=r['original'],r['optimized']
        lines.append(f"| {r['case']} | {a['area_um2']:.2f} → {b['area_um2']:.2f} | {a['delay_ns']:.3f} → {b['delay_ns']:.3f} | {a['cycles']:g} → {b['cycles']:g} | {r['ratios']['area_latency_product_um2_ns']:.4g} | {r['selected_for_area_latency']} |")
    lines += ['','ADP = mapped area × cycles × 10 ns; a ratio below 1 is better. The choice is objective-specific: a latency-first objective can choose stencil or boxfilter despite their area cost.',
        f"All {count} candidates are formally equivalent; correctness alone does not establish hardware benefit. Related kernels are grouped in the catalog; this is not a claim of {count} independent applications. Seeded mutants are excluded from QoR acceptance.",
        '',f"Evidence: {summary['native_optimized_trials']} compiled-C candidate tests, {summary['native_witnesses_replayed']} compiled witness replays, {summary['rtl_simulation_calls']} RTL calls, and {len(proof['cases'])} formal verdicts.",
        '', 'Raw logs, RTL, mapped netlists, constraints, exact commands, source hashes and timing-coverage audits are retained under `results/hls/`. Reported unconstrained endpoints were checked against mapped-netlist constants; no nonconstant endpoint was silently ignored.','']
    (out/'HLS_RESULTS.md').write_text('\n'.join(lines),encoding='utf-8')
    print('Complete:',{k:v for k,v in summary.items() if k!='comparisons'})
    return 0


if __name__=='__main__':
    raise SystemExit(main())
