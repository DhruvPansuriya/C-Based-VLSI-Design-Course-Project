import pytest
from vwe.obligations import classify
from vwe.tools.cbmc import CbmcRun,PropertyResult
from vwe.verdict import Outcome


def run(props,status=None):
    status=status or ('failure' if any(p.status=='FAILURE' for p in props) else 'success')
    return CbmcRun(True,status,props,0,[])


def pair(props): return {'sat':run(props),'z3':run(props)}
def assertion(p): return p.property_id.startswith('main.assertion.')
def safety(p): return p.property_id.startswith('p1_')


def test_contract_ub_never_becomes_proved():
    props=[PropertyResult('main.pointer_dereference.1','FAILURE','contract UB')]
    out,_=classify(pair(props),assertion,'I')
    assert out.outcome is Outcome.INCONCLUSIVE and 'unselected failure' in out.note


def test_missing_selected_assertion_is_inconclusive_even_if_other_checks_pass():
    out,_=classify(pair([PropertyResult('p1_fn.overflow.1','SUCCESS','safe')]),assertion,'I')
    assert out.outcome is Outcome.INCONCLUSIVE and 'no selected' in out.note


def test_selected_failure_is_violated_and_proof_is_proved():
    p=PropertyResult('main.assertion.1','FAILURE','bad',{'x':'3'})
    out,_=classify(pair([p]),assertion,'I')
    assert out.outcome is Outcome.VIOLATED and out.witness=={'x':'3'}
    p=PropertyResult('main.assertion.1','SUCCESS','good')
    assert classify(pair([p]),assertion,'I')[0].outcome is Outcome.PROVED


def test_e0_can_leave_output_assertions_for_e1_without_ignoring_contract_ub():
    props=[PropertyResult('main.assertion.1','FAILURE','E1 mismatch')]
    kw=dict(allow_empty=True,ignore_unselected_assertions=True)
    assert classify(pair(props),safety,'E0',**kw)[0].outcome is Outcome.PROVED
    props.append(PropertyResult('main.pointer_dereference.1','FAILURE','wrapper UB'))
    assert classify(pair(props),safety,'E0',**kw)[0].outcome is Outcome.INCONCLUSIVE


@pytest.mark.parametrize('prop',['p1_fn.unwind.0','p1_fn.no-body.helper'])
def test_unwind_and_missing_body_are_not_semantic_violations(prop):
    out,_=classify(pair([PropertyResult(prop,'FAILURE','setup')]),safety,'E0')
    assert out.outcome is Outcome.INCONCLUSIVE


def test_all_property_statuses_must_agree_not_just_failure_boolean():
    a=[PropertyResult('main.assertion.1','FAILURE','one'),PropertyResult('main.assertion.2','SUCCESS','two')]
    b=[PropertyResult('main.assertion.1','SUCCESS','one'),PropertyResult('main.assertion.2','FAILURE','two')]
    assert classify({'sat':run(a),'z3':run(b)},assertion,'I')[0].outcome is Outcome.INCONCLUSIVE


@pytest.mark.parametrize('case',['one_backend','duplicate','unchecked','inconsistent','error'])
def test_incomplete_and_malformed_result_sets(case):
    p=PropertyResult('main.assertion.1','SUCCESS','ok')
    runs=pair([p])
    if case=='one_backend': del runs['z3']
    elif case=='duplicate': runs=pair([p,p])
    elif case=='unchecked': runs=pair([PropertyResult(p.property_id,'NOT_CHECKED','')])
    elif case=='inconsistent': runs['sat']=run([p],'failure')
    elif case=='error': runs['sat'].ok=False
    assert classify(runs,assertion,'I')[0].outcome is Outcome.INCONCLUSIVE


def test_independent_safety_counterexample_does_not_need_other_ub_checks_proved():
    # CBMC can leave subsequent checks UNKNOWN after finding a bounds fault.
    props=[PropertyResult('p1_fn.pointer_dereference.1','FAILURE','real bounds fault'),
           PropertyResult('p1_fn.overflow.1','UNKNOWN','not needed for this refutation')]
    assert classify(pair(props),safety,'E0')[0].outcome is Outcome.INCONCLUSIVE
    assert classify(pair(props),safety,'E0',independent_safety_refutation=True)[0].outcome is Outcome.VIOLATED


def test_unknown_wrapper_property_blocks_partial_safety_refutation():
    props=[PropertyResult('p1_fn.pointer_dereference.1','FAILURE','bounds fault'),
           PropertyResult('main.pointer_dereference.1','UNKNOWN','wrapper validity unknown')]
    assert classify(pair(props),safety,'E0',independent_safety_refutation=True)[0].outcome is Outcome.INCONCLUSIVE
