"""Check the 60-second experiment's source, version and proof evidence."""

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
    summary=json.loads((ROOT/'results/large/summary.json').read_text())
    assert summary['total']==29 and summary['timeout_ms_per_obligation']==60000
    queries=0;native=0
    for row in summary['cases']:
        for label,expected in zip(('original','candidate'),row['fingerprint']['source_sha256']):
            assert hashlib.sha256((ROOT/row[label]).read_bytes()).hexdigest()==expected
        folder=ROOT/'results/large'/row['id']
        replay=verify_evidence(folder/'proof',timeout_ms=60000);assert replay['passed'],row['id']
        queries+=len(replay['queries'])
        if row['native_witness']['available']:
            assert row['native_witness']['passed']
            assert hashlib.sha256((folder/'native/witness.c').read_bytes()).hexdigest()==row['native_witness']['harness_sha256']
            native+=1
        if row['matched_expected'] is False:
            assert row['status'] in ('inconclusive','unsupported','error')
    loop=json.loads((ROOT/'results/loop_budget/summary.json').read_text())
    for row in loop['cases']:
        assert verify_evidence(ROOT/'results/loop_budget'/row['id']/'proof',timeout_ms=60000)['passed']
    record={'passed':True,'size_and_retry_pairs':29,'loop_resource_retries':len(loop['cases']),
            'accepted_smt_queries_replayed':queries,'native_mismatch_harnesses_checked':native,
            'scope':'Matching current/archived generator versions, source/artifact hashes, accepted SMT replay and recorded native harness hashes. External C verifier and hardware synthesis not rerun.'}
    (ROOT/'results/large/evidence_validation.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(record,indent=2),flush=True)


if __name__=='__main__':main()
