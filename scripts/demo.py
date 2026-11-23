"""Short live demonstration: proof, counterexample, fallback and measured QoR."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json
from hlscheck import check_equivalence


def main():
    root=Path(__file__).resolve().parents[1]
    print('HLSCheck: CS5291 Project 3 live demonstration\n')
    folder=root/'benchmarks/submission'
    original=(folder/'prefix_original.c').read_text()
    for variant in ('optimized','buggy'):
        result=check_equivalence(original,(folder/f'prefix_{variant}.c').read_text(),'kernel')
        print('LIVE prefix_'+variant+':',result['status'],f"({result['elapsed_seconds']:.3f}s)")
        if result['status']=='not_equivalent':
            print('  witness a =',result['counterexample']['a'])
            print('  original out =',result['original_outputs']['out'])
            print('  faulty out   =',result['candidate_outputs']['out'])
    rare=root/'benchmarks/semantic_traps'
    result=check_equivalence((rare/'rare_original.c').read_text(),(rare/'rare_buggy.c').read_text(),'kernel')
    print('\nLIVE rare-input mutation:',result['status'],'at x =',hex(result['counterexample']['x']))
    print('The recorded compiled-C experiment missed this seeded mutation in 10,000 random trials.')
    print('\nRECORDED hardware measurements (not a synthesis run in this demo):')
    measured=json.loads((root/'results/submission/summary.json').read_text())
    prefix=next(r for r in measured['comparisons'] if r['case']=='prefix')
    a,b=prefix['original'],prefix['optimized']
    print(f"  Prefix area: {a['area_um2']:.2f} -> {b['area_um2']:.2f} um^2")
    print(f"  Prefix cycles: {a['cycles']:g} -> {b['cycles']:g}; common clock 10 ns")
    print(f"  Mapped delay: {a['delay_ns']:.3f} -> {b['delay_ns']:.3f} ns (pre-layout)")
    print(f"  {measured['proved_optimized_pairs']} candidates proved; {measured['selected_optimized']} improve area x latency under this configuration.")
    print('\nOptional live fallback: python -m hlscheck benchmarks/demo/index_original.c benchmarks/demo/index_optimized.c --function kernel --backend auto --timeout-ms 30000 --output-dir results/live_fallback')
    print('Open output/presentation/project3_slides.html for the presentation.')


if __name__=='__main__':
    main()
