"""Live proof-level combination, including a spurious and a real counterexample."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))


from hlscheck import verify_equivalence
from hlscheck.evidence import verify_evidence,replay_native_witness

ROOT=Path(__file__).resolve().parents[1]


def main():
    source=ROOT/'benchmarks/hybrid'
    examples=[('matrix plus symbolic read','gemm_lookup_original.c','gemm_lookup_optimized.c','gemm_lookup','equivalent'),
              ('correlation requires refinement','refinement_original.c','refinement_equivalent.c','transform','equivalent'),
              ('real suffix mistake','refinement_original.c','refinement_incorrect.c','transform','not_equivalent')]
    for i,(label,a,b,function,expected) in enumerate(examples):
        folder=ROOT/'results/hybrid/live_demo'/str(i+1)
        print('\n'+label,flush=True)
        result=verify_equivalence((source/a).read_text(),(source/b).read_text(),function,
                                  output_dir=folder/'proof',timeout_ms=60000)
        for obligation in result['obligations']:
            print(' ',obligation['id'],obligation.get('abstraction','SMT lemma'),'->',obligation['status'],flush=True)
        print('Final:',result['status'],';',len(result['proof_dependencies']),'accepted lemma dependencies',flush=True)
        assert result['status']==expected
        assert verify_evidence(folder/'proof')['passed']
        if result['status']=='not_equivalent':
            native=replay_native_witness(folder/'proof',folder/'native')
            print('Actual original/candidate C reproduce the witness:',native.get('passed'),flush=True)
            assert native.get('passed')
    print('\nThe C residual proofs depend on the SMT summaries; no engine-answer router was used.',flush=True)
    return 0


if __name__=='__main__':
    raise SystemExit(main())
