"""Validate all saved integrated-algorithm artifacts without rerunning ESBMC."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import hashlib
import json

from hlscheck.evidence import verify_evidence

ROOT=Path(__file__).resolve().parents[1]


def main():
    summary=json.loads((ROOT/'results/hybrid/study/summary.json').read_text())
    assert summary['total']==239
    queries=0;witnesses=0
    for row in summary['cases']:
        folder=ROOT/'results/hybrid/study'/row['id']
        for filename,expected in zip(('original','candidate'),row['fingerprint']['sources']):
            assert hashlib.sha256((ROOT/row[filename]).read_bytes()).hexdigest()==expected
        checked=verify_evidence(folder/'proof')
        assert checked['passed'],row['id']
        queries+=len(checked['queries'])
        if row['native_witness']['available']:
            assert row['native_witness']['passed'],row['id']
            assert hashlib.sha256((folder/'native/witness.c').read_bytes()).hexdigest()==row['native_witness']['harness_sha256']
            witnesses+=1
        if row['matched_expected'] is False:
            assert row['status'] in ('inconclusive','unsupported','error'),row['id']
    record={'passed':True,'pairs':summary['total'],'accepted_smt_queries_replayed':queries,
            'native_witness_harnesses_checked':witnesses,'known_labels_matched':summary['matched_known_labels'],
            'known_labels':summary['known_labels'],
            'unresolved_known_labels':sum(r['matched_expected'] is False for r in summary['cases']),
            'contradictory_conclusive_verdicts':0,
            'scope':'Current implementation/artifact/source hashes and accepted SMT dependencies. Native executions and ESBMC residual proofs are recorded runs; no model, HLS synthesis or external C verifier rerun.'}
    (ROOT/'results/hybrid/evidence_validation.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record,indent=2),flush=True)


if __name__=='__main__':
    main()
