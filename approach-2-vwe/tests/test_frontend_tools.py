from pathlib import Path
import subprocess
import pytest
from vwe.tools import frontend


def result(argv=('tool',),*,ok=True,stdout='',stderr=''):
    return frontend.CommandResult(tuple(argv),'/tmp',0 if ok else 1,stdout,stderr,0)


@pytest.mark.parametrize('failure',[FileNotFoundError('absent'),PermissionError('denied'),subprocess.TimeoutExpired('tool',1,output=b'partial')])
def test_commands_fail_structurally(monkeypatch,tmp_path,failure):
    def fail(*a,**kw): raise failure
    monkeypatch.setattr(frontend.subprocess,'run',fail)
    r=frontend.execute(['tool'],cwd=tmp_path,timeout_s=1)
    assert not r.ok and r.error and r.returncode is None
    if isinstance(failure,subprocess.TimeoutExpired): assert r.stdout=='partial'


def test_commands_record_output_and_deadline(monkeypatch,tmp_path):
    def execute(argv,**kw):
        assert kw['timeout']==7 and kw['cwd']==tmp_path
        return subprocess.CompletedProcess(argv,0,'out','err')
    monkeypatch.setattr(frontend.subprocess,'run',execute)
    r=frontend.execute(['tool','arg'],cwd=tmp_path,timeout_s=7)
    assert r.ok and r.stdout=='out' and r.stderr=='err' and r.record()['argv']==('tool','arg')


def test_preprocess_uses_pinned_flags_and_labels_fallback(monkeypatch,tmp_path):
    calls=[]
    def execute(argv,**kw):
        calls.append(argv);return result(argv,ok=argv[0]!='cbmc',stdout='int f(void){return 0;}')
    monkeypatch.setattr(frontend,'execute',execute)
    text,commands,provider=frontend.preprocess(tmp_path/'unit.c',synth=True,timeout_s=1)
    assert provider=='gcc-fallback-unqualified' and len(commands)==2
    assert '-D__SYNTHESIS__=1' in calls[0]
    assert all(f in calls[0] for f in frontend.BASE_FLAGS)
    assert calls[0][calls[0].index('--verbosity')+1]=='0'


@pytest.mark.parametrize('listing,ok',[('__CPROVER_initialize\nhelper\n',True),('tool banner\nhelper\n',False)])
def test_undefined_listing_format_is_checked(monkeypatch,tmp_path,listing,ok):
    results=iter([result(),result(stdout=listing)])
    monkeypatch.setattr(frontend,'execute',lambda *a,**kw:next(results))
    r=frontend.list_undefined(tmp_path/'unit.c',timeout_s=2)
    assert r.ok==ok
    if ok: assert 'helper' in r.names


def test_compile_error_prevents_listing(monkeypatch,tmp_path):
    calls=[]
    def execute(argv,**kw): calls.append(argv);return result(ok=False)
    monkeypatch.setattr(frontend,'execute',execute)
    assert not frontend.list_undefined(tmp_path/'unit.c',timeout_s=1).ok
    assert len(calls)==1
