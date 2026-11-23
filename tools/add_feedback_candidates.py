"""Record two follow-ups against existing baselines; do not inflate uniqueness."""
from pathlib import Path
import json
import shutil

ROOT=Path(__file__).resolve().parents[1]


def main():
    folder=ROOT/'benchmarks/feedback';folder.mkdir(exist_ok=True)
    cases=[{
        'name':'moving_sum_register16','baseline':'benchmarks/expanded/moving_sum16_original.c','output':'out',
        'transformation':'Keep the four-element moving window in scalar registers',
        'rationale':'Follow up the sliding-sum area regression: load only one new input per output, with explicit local window state instead of rereading the outgoing array element.',
        'parents':['moving_sum16'],
        'code':'''#include <stdint.h>

/* Feedback candidate: one new memory read per output after initialization. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t w0=a[0], w1=a[1], w2=a[2], w3=a[3];
    for(int i=0;i<13;i++) {
        out[i]=(w0+w1)+(w2+w3);
        if(i<12) {
            w0=w1;
            w1=w2;
            w2=w3;
            w3=a[i+4];
        }
    }
}
'''}, {
        'name':'gemm_tile2','baseline':'benchmarks/machsuite_u32/gemm_original.c','output':'prod',
        'transformation':'Tile GEMM columns by two with local accumulators',
        'rationale':'Follow up the four-accumulator design: test whether two simultaneous output accumulators reduce mapped area while retaining some row-input reuse. Improvement is determined by measurements.',
        'parents':['gemm','gemm_local4'],
        'code':'''#include <stdint.h>

/* MachSuite-derived reference algorithm; LICENSE.MachSuite is retained.
   Feedback candidate: two local accumulators rather than four. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j+=2) {
            uint32_t s0=0u, s1=0u;
            for(int k=0;k<4;k++) {
                uint32_t value=m1[i*4+k];
                s0+=value*m2[k*4+j];
                s1+=value*m2[k*4+j+1];
            }
            prod[i*4+j]=s0;
            prod[i*4+j+1]=s1;
        }
    }
}
'''}]
    catalog=json.loads((ROOT/'experiments/catalog.json').read_text())
    mapping={c['name']:c for c in catalog['cases']}
    for c in cases:
        shutil.copyfile(ROOT/c['baseline'],folder/(c['name']+'_original.c'))
        (folder/(c['name']+'_optimized.c')).write_text(c['code'])
        bad=c['code'].rsplit('}',1)[0]+'    /* Seeded output-bit fault; not a spontaneous LLM error. */\n    '+c['output']+'[0]^=1u;\n}\n'
        (folder/(c['name']+'_buggy.c')).write_text(bad)
        mapping[c['name']]={'name':c['name'],'directory':'benchmarks/feedback',
            'origin':'Explicit follow-up against the existing '+c['baseline']+' reference; not a new independent original algorithm',
            'transformation':c['transformation'],'rationale':c['rationale'],'algorithm_group':'feedback variants',
            'comparison_parent_pairs':c['parents'],'generation_round':3,
            'negative_control':'Flip bit zero of the first output element after the full candidate computation'}
    catalog.update(case_count=len(mapping),source_design_count=2*len(mapping));catalog['cases']=list(mapping.values())
    (ROOT/'experiments/catalog.json').write_text(json.dumps(catalog,indent=2)+'\n')
    shutil.copyfile(ROOT/'benchmarks/machsuite_u32/LICENSE',folder/'LICENSE.MachSuite')
    (folder/'README.md').write_text('''# Two feedback-driven follow-ups

These pairs reuse the existing moving_sum16 and GEMM original references.
They extend the study from 48 to 50 pairs / 100 implementations, while the
number of distinct original C ASTs remains 47. They are additional candidates,
not additional independent algorithms.

The register-window sum follows an earlier area-regressing sliding recurrence.
The two-column GEMM tile follows the four-accumulator candidate, testing a
different area/latency balance. Both earlier candidates and all raw evidence
are retained. Outcomes are measured, not assumed. GEMM's MachSuite license is
preserved as LICENSE.MachSuite; dimensions and uint32_t adaptations remain the
same. Faulty versions are explicitly seeded one-bit output mutations.
''')
    print('Recorded',len(cases),'feedback candidates;',len(mapping),'pairs total.')


if __name__=='__main__':
    main()
