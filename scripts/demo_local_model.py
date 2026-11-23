"""Live detection and native replay of a saved, genuine local-model mistake."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json

from scripts.evaluate_local_candidates import digest, evaluate_pair

ROOT = Path(__file__).resolve().parents[1]


def main():
    identifier = 'popcount8_seed5292'
    source = ROOT/'results/local_llm/generations'/identifier
    generation = json.loads((source/'generation.json').read_text())
    assert generation['candidate_sha256'] == digest(source/'candidate.c')
    assert generation['source_sha256'] == digest(source/'original.c')
    print('Saved actual model attempt:', identifier, flush=True)
    print('Model:', generation['model_repository'], 'Q4_K_M; API charge $0', flush=True)
    print('Candidate was not manually repaired. Rechecking and compiling now.', flush=True)
    result = evaluate_pair(source/'original.c', source/'candidate.c',
        ROOT/'results/local_llm/live_demo', index=999, timeout_ms=10000, force=True)
    verification = result['verification']
    print('Live verdict:', result['status'], flush=True)
    print('Input:', verification.get('counterexample'), flush=True)
    print('Original output:', verification.get('original_outputs'), flush=True)
    print('Model output:', verification.get('candidate_outputs'), flush=True)
    print('Exact witness reproduced in compiled C:', result['native']['witness_replayed'], flush=True)
    print('Compiled outputs match solver:', result['native']['witness_outputs_agree'], flush=True)
    assert result['status'] == 'not_equivalent' and result['native']['passed'] and result['smt_replay']['passed']
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
