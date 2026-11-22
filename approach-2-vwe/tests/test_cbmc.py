import json
import subprocess
import pytest
from vwe.tools import cbmc


def install_process(monkeypatch,messages,returncode=0):
    def execute(cmd,**kw):
        return subprocess.CompletedProcess(cmd,returncode,json.dumps(messages),'')
    monkeypatch.setattr(cbmc.subprocess,'run',execute)


def messages(status='success',propstatus='SUCCESS'):
    return [{'result':[{'property':'main.assertion.1','status':propstatus,'description':'test'}]},
            {'cProverStatus':status}]


def test_checked_process_status_and_raw_log(monkeypatch):
    install_process(monkeypatch,messages())
    r=cbmc.run(['harness.c'],unwind=4)
    assert r.ok and r.returncode==0 and r.stdout and '--trace' in r.command
    assert all(f in r.command for f in cbmc.BASE_FLAGS)


def test_property_failure_exit_code(monkeypatch):
    install_process(monkeypatch,messages('failure','FAILURE'),10)
    r=cbmc.run(['harness.c'])
    assert r.ok and len(r.failed())==1


@pytest.mark.parametrize('data',[{},[None],[{'result':{}}],[{'result':[{}]}],
    [{'result':[{'property':1,'status':'SUCCESS'}]}],
    [{'cProverStatus':'success'},{'cProverStatus':'failure'}],
    [{'cProverStatus':'error'},{'cProverStatus':'success'}],
    [{'cProverStatus':[]}],
    [{'messageType':'ERROR'},{'cProverStatus':'success'}]])
def test_malformed_json_structure_returns_error(monkeypatch,data):
    install_process(monkeypatch,data)
    assert not cbmc.run(['harness.c']).ok


def test_nonzero_tool_error_cannot_use_a_success_log(monkeypatch):
    install_process(monkeypatch,messages(),6)
    assert not cbmc.run(['harness.c']).ok


@pytest.mark.parametrize('exception',[FileNotFoundError('missing'),PermissionError('denied'),subprocess.TimeoutExpired('cbmc',1)])
def test_tool_launch_and_timeout_errors_are_structured(monkeypatch,exception):
    def execute(*a,**kw): raise exception
    monkeypatch.setattr(cbmc.subprocess,'run',execute)
    r=cbmc.run(['harness.c'])
    assert not r.ok and r.status=='error'


@pytest.mark.parametrize('flag',['--no-standard-checks','--partial-loops','--no-unwinding-assertions','--no-assertions','--assert-to-assume'])
def test_callers_cannot_disable_mandatory_checks(flag):
    with pytest.raises(ValueError): cbmc.run(['harness.c'],extra=[flag])


def test_invalid_options_rejected_before_launch():
    with pytest.raises(ValueError): cbmc.run(['harness.c'],backend='unknown')
    with pytest.raises(ValueError): cbmc.run(['harness.c'],timeout_s=0)


def test_witness_uses_last_watched_assignment(monkeypatch):
    data=messages('failure','FAILURE')
    data[0]['result'][0]['trace']=[{'stepType':'assignment','lhs':'n','value':{'data':'0'}},
                                {'stepType':'assignment','lhs':'n','value':{'data':'3'}}]
    install_process(monkeypatch,data,10)
    assert cbmc.run(['harness.c'],watch=['n']).failed()[0].witness=={'n':'3'}
