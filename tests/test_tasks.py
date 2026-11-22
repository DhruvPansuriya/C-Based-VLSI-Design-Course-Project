from __future__ import annotations
from dataclasses import FrozenInstanceError, fields, is_dataclass
from hashlib import sha256
import json
from pathlib import Path
import shutil
from collections.abc import Mapping
import pytest
from vwe.tasks import TaskError, load_full, load_pipeline_view

ROOT=Path(__file__).resolve().parent.parent
TASKS=ROOT/'examples/tasks'


def strings(value):
    if is_dataclass(value):
        for f in fields(value): yield from strings(getattr(value,f.name))
    elif isinstance(value,Mapping):
        for k,v in value.items(): yield from strings(k);yield from strings(v)
    elif isinstance(value,(tuple,list)):
        for x in value: yield from strings(x)
    elif isinstance(value,(str,Path)): yield str(value)


def copy_task(tmp_path,tid='ex2_argmax'):
    p=tmp_path/'task';shutil.copytree(TASKS/tid,p);return p


def edit_manifest(folder,change):
    p=folder/'task.json';d=json.loads(p.read_text());change(d);p.write_text(json.dumps(d))


@pytest.mark.parametrize('tid,count,readings',[
    ('ex1_saturate',5,2),('ex2_argmax',3,2),('ex3_avg_half_away',3,2),
    ('ex4_sum',2,3),('ex5_add32_ambiguous',3,3),('ex6_copy_overflow',2,1),
    ('ex7_build_views',2,1),
])
def test_tasks_validate_and_snapshots_are_complete(tid,count,readings):
    t=load_pipeline_view(TASKS/tid)
    assert t.task_id==tid and len(t.candidates)==count and len(t.interpretations)==readings
    assert len({r['provenance']['source'] for r in t.interpretations})==1
    assert t.p0.sha256==sha256((TASKS/tid/'p0.c').read_bytes()).hexdigest()
    assert 'p0_' not in t.p0.text and 'p1_' not in t.p0.text
    assert t.requests[0].text==(TASKS/tid/'request.txt').read_text()
    assert not hasattr(t,'eval_only') and not hasattr(t,'root')
    assert not any('eval/' in s for s in strings(t))


def test_pipeline_never_opens_evaluation_files(tmp_path,monkeypatch):
    folder=copy_task(tmp_path)
    original=Path.open
    def guarded(path,*a,**kw):
        if 'eval' in path.parts: raise AssertionError('pipeline accessed evaluation file')
        return original(path,*a,**kw)
    monkeypatch.setattr(Path,'open',guarded)
    assert load_pipeline_view(folder).function=='argmax'


def test_evaluation_metadata_does_not_leak(tmp_path):
    folder=copy_task(tmp_path)
    def change(d):
        d['eval_only']['true_shape']={'secret':'ORACLE_ONLY_METADATA_7f3a'}
        d['requests'][0]['acceptable_readings']=['ORACLE_ONLY_READING_7f3a']
    edit_manifest(folder,change)
    pipeline=load_pipeline_view(folder)
    assert not any('ORACLE_ONLY' in x for x in strings(pipeline))
    full=load_full(folder)
    assert full.eval_only.true_shape['secret']=='ORACLE_ONLY_METADATA_7f3a'
    assert full.eval_only.acceptable_readings['original']==('ORACLE_ONLY_READING_7f3a',)
    assert full.eval_only.p_ref.relative_path=='eval/p_ref.c'
    assert full.pipeline==pipeline


def test_missing_oracle_does_not_block_pipeline_but_full_loader_fails(tmp_path):
    folder=copy_task(tmp_path);shutil.rmtree(folder/'eval')
    assert load_pipeline_view(folder).function=='argmax'
    with pytest.raises(TaskError): load_full(folder)


def test_deep_immutability():
    t=load_pipeline_view(TASKS/'ex2_argmax')
    with pytest.raises(FrozenInstanceError): t.function='fake'
    with pytest.raises(TypeError): t.candidates['other']=t.candidates['v1']
    with pytest.raises(TypeError): t.caller_domain['buffers']['a']='8'
    with pytest.raises(TypeError): t.interpretations[0]['clauses'][0]['zone']='false'


@pytest.mark.parametrize('bad',['/tmp/outside.c','../outside.c','eval/p_ref.c','candidates/../../outside.c','C:\\outside.c'])
def test_path_escape_and_eval_alias_refused(tmp_path,bad):
    folder=copy_task(tmp_path)
    edit_manifest(folder,lambda d:d.__setitem__('p0',bad))
    with pytest.raises(TaskError): load_pipeline_view(folder)


@pytest.mark.parametrize('field',['candidate','request','interpretation'])
def test_symlink_into_evaluation_refused(tmp_path,field):
    folder=copy_task(tmp_path)
    if field=='candidate': p=folder/'candidates/v1.c'
    elif field=='request': p=folder/'request.txt'
    else: p=folder/'interpretations/strict.json'
    p.unlink();p.symlink_to(folder/'eval/p_ref.c')
    with pytest.raises(TaskError): load_pipeline_view(folder)


def test_outside_symlink_refused(tmp_path):
    folder=copy_task(tmp_path);outside=tmp_path/'outside.c';outside.write_text('outside')
    p=folder/'p0.c';p.unlink();p.symlink_to(outside)
    with pytest.raises(TaskError): load_pipeline_view(folder)


def test_duplicate_json_keys_and_request_ids_refused(tmp_path):
    folder=copy_task(tmp_path)
    p=folder/'task.json';s=p.read_text();p.write_text(s.replace('"function":','"function":"other", "function":',1))
    with pytest.raises(TaskError,match='Duplicate JSON key'): load_pipeline_view(folder)
    p.write_text(s)
    edit_manifest(folder,lambda d:d['requests'].append(d['requests'][0]))
    with pytest.raises(TaskError,match='Duplicate request id'): load_pipeline_view(folder)


def test_duplicate_interpretation_ids_refused(tmp_path):
    folder=copy_task(tmp_path)
    p=folder/'interpretations/permissive.json';d=json.loads(p.read_text())
    d['id']=json.loads((folder/'interpretations/strict.json').read_text())['id'];p.write_text(json.dumps(d))
    with pytest.raises(TaskError,match='Duplicate interpretation id'): load_pipeline_view(folder)


def test_invalid_n_minus_1_shape_is_retained_until_semantic_validation():
    t=load_pipeline_view(TASKS/'ex4_sum')
    assert any(i['shape']['buffers']['a']=='n - 1' for i in t.interpretations)
    assert t.caller_domain['buffers']['a']=='n'
    assert t.caller_domain['value_bounds']['a']==(-1000,1000)


def test_requests_cannot_have_text_and_file_together(tmp_path):
    folder=copy_task(tmp_path)
    edit_manifest(folder,lambda d:d['requests'][0].__setitem__('text','conflicting source'))
    with pytest.raises(TaskError): load_pipeline_view(folder)


@pytest.mark.parametrize('source',sorted(TASKS.glob('**/*.c')),ids=lambda p:str(p.relative_to(TASKS)))
def test_converted_c_sources_compile(source):
    import subprocess
    cc=shutil.which('cc')
    if cc is None: pytest.skip('native C compiler unavailable')
    r=subprocess.run([cc,'-std=c11','-Wall','-Wextra','-Werror','-fsyntax-only',str(source)],capture_output=True,text=True,timeout=10)
    assert r.returncode==0,r.stdout+r.stderr
