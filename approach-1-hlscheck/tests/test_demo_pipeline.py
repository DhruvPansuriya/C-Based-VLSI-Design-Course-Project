"""The demo must never turn failed/stale prerequisites into hardware success."""
import json
from pathlib import Path
import shutil

import pytest

from scripts import design_pipeline as pipeline
from scripts.design_testbench import make_testbench, value_at

ROOT = Path(__file__).resolve().parents[1]
requires_tools = pytest.mark.skipif(not shutil.which('clang') or
    not (ROOT / 'tools/esbmc-v8.7/release/bin/esbmc.exe').exists(), reason='Clang/ESBMC required')


def inputs(tmp_path, original='unsigned kernel(unsigned x){return x*8u;}', candidate=None):
    a,b=tmp_path/'original.c',tmp_path/'optimized.c'
    a.write_text(original)
    b.write_text(candidate if candidate is not None else original)
    return a,b,tmp_path/'results'


def latest(output):
    pointer=json.loads((output/'latest.json').read_text())
    return Path(pointer['run_directory']),json.loads(Path(pointer['summary']).read_text())


def forbid_hardware(monkeypatch):
    calls=[]
    def forbidden(*args,**kwargs):
        calls.append(True)
        raise AssertionError('Hardware must not run')
    monkeypatch.setattr(pipeline,'run_hardware',forbidden)
    return calls


@requires_tools
def test_real_mismatch_stops_before_hls(tmp_path,monkeypatch):
    a,b,out=inputs(tmp_path,candidate='unsigned kernel(unsigned x){return x*4u;}')
    calls=forbid_hardware(monkeypatch)
    assert pipeline.main([str(a),str(b),'--output-dir',str(out)])==1
    folder,result=latest(out)
    assert result['status']=='not_equivalent' and result['native_witness']['passed']
    assert not calls and not (folder/'hls_gate.json').exists()


@requires_tools
def test_inconclusive_stops_before_native_or_hls(tmp_path,monkeypatch):
    import hlscheck
    a,b,out=inputs(tmp_path)
    calls=forbid_hardware(monkeypatch)
    monkeypatch.setattr(hlscheck,'verify_equivalence',lambda *args,**kwargs:
        {'status':'inconclusive','elapsed_seconds':0.01,'obligations':[]})
    monkeypatch.setattr(pipeline,'compile_native',lambda *args,**kwargs:pytest.fail('Native execution must not run'))
    assert pipeline.main([str(a),str(b),'--output-dir',str(out)])==2
    folder,result=latest(out)
    assert result['status']=='inconclusive' and not calls
    assert not (folder/'hls_gate.json').exists()


@requires_tools
def test_source_edit_cannot_reuse_an_old_success(tmp_path,monkeypatch):
    a,b,out=inputs(tmp_path)
    calls=forbid_hardware(monkeypatch)
    command=[str(a),str(b),'--output-dir',str(out),'--verify-only']
    assert pipeline.main(command)==0
    first,_=latest(out)
    b.write_text('unsigned kernel(unsigned x){return x*4u;}')
    assert pipeline.main(command)==1
    second,result=latest(out)
    assert first!=second and result['status']=='not_equivalent'
    assert json.loads((first/'summary.json').read_text())['status']=='equivalent_verified_only'
    assert not calls


@requires_tools
def test_native_failure_blocks_hls_after_formal_success(tmp_path,monkeypatch):
    a,b,out=inputs(tmp_path)
    calls=forbid_hardware(monkeypatch)
    def failed(*args,**kwargs):raise RuntimeError('Native oracle failed')
    monkeypatch.setattr(pipeline,'compile_native',failed)
    assert pipeline.main([str(a),str(b),'--output-dir',str(out)])==3
    folder,result=latest(out)
    assert result['verification']['status']=='equivalent'
    assert result['status']=='pipeline_error' and not calls
    assert not (folder/'hls_gate.json').exists()


@requires_tools
def test_changed_hls_input_is_rejected_at_worker_gate(tmp_path):
    a,b,out=inputs(tmp_path)
    assert pipeline.main([str(a),str(b),'--output-dir',str(out),'--verify-only'])==0
    folder,result=latest(out)
    proof=json.loads((folder/'proof/result.json').read_text())
    pipeline.write(folder/'hls_inputs/tb.c',make_testbench(a.read_text(),trials=16,hls=True))
    pipeline.save(folder/'hls_gate.json',{'verification':{'status':'equivalent'},
        'original_sha256':result['inputs']['original']['hls_sha256'],
        'candidate_sha256':result['inputs']['optimized']['hls_sha256']})
    manifest={'run_directory':str(folder),'inputs':result['inputs'],
        'proof_requirements':[{'folder':'proof','result_sha256':pipeline.sha(folder/'proof/result.json'),
            'source_sha256':proof['source_sha256']}],
        'native_result_sha256':pipeline.sha(folder/'native/result.json'),
        'testbench_sha256':pipeline.sha(folder/'hls_inputs/tb.c')}
    pipeline.validate_hardware_gate(manifest)
    pipeline.write(folder/result['inputs']['optimized']['hls_source'],'unsigned kernel(unsigned x){return 0;}')
    with pytest.raises(ValueError,match='HLS input changed'):
        pipeline.validate_hardware_gate(manifest)


def test_samples_obey_ranges_and_keep_full_width_independent_values():
    spec={'bits':64,'signed':False,'position':0,'length':None,'name':'n'}
    values=[value_at(spec,t,0,{}) for t in range(64)]
    assert any(v>0xffffffff for v in values)
    restricted=[value_at(spec,t,0,{'n':[3,5]}) for t in range(64)]
    assert min(restricted)==3 and max(restricted)==5
    other={**spec,'position':1,'name':'m'}
    assert any(value_at(spec,t,0,{})!=value_at(other,t,0,{}) for t in range(8,64))
