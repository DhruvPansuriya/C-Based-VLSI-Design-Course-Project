from hashlib import sha256
import json
from pathlib import Path
from types import MappingProxyType
import pytest
from vwe.admission import admit
from vwe.tasks import Candidate,PipelineTask,Request,SourceFile,load_pipeline_view
from vwe.tools import frontend,cbmc


def source(text): return SourceFile('input.c',text,sha256(text.encode()).hexdigest())


def task(p1='int f(int x){return x;}',p0='int f(int x){return x;}'):
    return PipelineTask('unit','f',source(p0),(Request('r','fix the function','brief_author'),),
        MappingProxyType({'v1':Candidate('v1',source(p1))}),(),
        MappingProxyType({'buffers':{},'alias':'disjoint','bounds':{}}))


@pytest.fixture
def unit_frontend(monkeypatch):
    def preprocess(src,*,synth,timeout_s,fallback_cc):
        text=src.read_text().split('#line 1 "input.c"\n',1)[1]
        r=frontend.CommandResult(('mock-preprocess',),str(src.parent),0,text,'',0)
        return text,(r,),'cbmc'
    monkeypatch.setattr(frontend,'preprocess',preprocess)
    monkeypatch.setattr(frontend,'list_undefined',lambda *a,**kw: frontend.UndefinedFunctions(True,('__CPROVER_initialize',),()))


def test_structural_admission_is_not_a_correctness_verdict(unit_frontend,tmp_path):
    r=admit(task('int f(int x){return x+1;}'),'v1',out_dir=tmp_path)
    assert r.decision=='ok' and r.verdict is None
    report=json.loads((tmp_path/'admission.json').read_text())
    assert report['functional_proof']=='NOT_RUN' and report['build_view_equivalence']=='NOT_RUN'
    assert r.p0_views.sim.entry_point=='p0_f' and r.p1_views.sim.entry_point=='p1_f'


@pytest.mark.parametrize('code,expected',[
 ('int f(int x){__CPROVER_assume(x>0);return x;}','VERIFIER_IDENTIFIER'),
 ('int f(int x){__ESBMC_assume(x>0);return x;}','VERIFIER_IDENTIFIER'),
 ('int f(int x){__VERIFIER_assume(x>0);return x;}','VERIFIER_IDENTIFIER'),
 ('int f(int x){__builtin_unreachable();return x;}','PATH_CUT'),
 ('int f(int x){longjmp(x,1);return x;}','PATH_CUT'),
 ('int f(int x){volatile int y=x;return y;}','VOLATILE'),
 ('typedef volatile int V;int f(int x){V y=x;return y;}','VOLATILE'),
 ('int f(int x){goto L; L:return x;}','GOTO'),
 ('int f(int x){switch(x){case 1:; int y=2;return y;}return x;}','SWITCH_DECLARATION'),
 ('int f(int x){return x ? f(x-1) : 0;}','RECURSION'),
 ('int h(int);int f(int x){return h(x);}int h(int x){return f(x);}','RECURSION'),
 ('int f(int x){static int y;return y+x;}','PERSISTENT_LOCAL'),
 ('int f(int x){return malloc(x)!=0;}','DESIGN_HEAP'),
])
def test_candidate_forbidden_construct_is_policy_e0(unit_frontend,tmp_path,code,expected):
    r=admit(task(code),'v1',out_dir=tmp_path)
    assert r.decision=='reject' and r.verdict.evidence_class=='E0'
    assert r.verdict.claim_target=='admission_policy'
    assert expected in {f.code for f in r.findings}


def test_bad_reference_is_not_a_candidate_refutation(unit_frontend,tmp_path):
    r=admit(task(p0='int f(int x){return f(x);}'),'v1',out_dir=tmp_path)
    assert r.decision=='undecided' and r.verdict.evidence_class=='-'


@pytest.mark.parametrize('code',[
 'float f(float x){return x;}',
 'int f(int x){float y=x;return y;}',
 'typedef float F; int f(int x){F y=x;return y;}',
 'float helper(int x){return x;}int f(int x){return helper(x);}',
 'int f(int x){return (double)x;}',
 'int f(int x){int a[x];return a[0];}',
])
def test_unsupported_fragment_is_undecided(unit_frontend,tmp_path,code):
    r=admit(task(code),'v1',out_dir=tmp_path)
    assert r.decision=='undecided'


def test_missing_body_refusal_and_interface_change(unit_frontend,tmp_path):
    r=admit(task('int f(int x){return helper(x);}'),'v1',out_dir=tmp_path/'call')
    assert r.decision=='reject' and r.undefined_functions==('helper',)
    r=admit(task('long f(long x){return x;}'),'v1',out_dir=tmp_path/'sig')
    assert r.decision=='undecided' and 'interface change' in r.reason


def test_parameter_names_and_integer_spelling_do_not_change_signature(unit_frontend,tmp_path):
    r=admit(task('signed int f(signed int y){return y;}'),'v1',out_dir=tmp_path)
    assert r.decision=='ok'


def test_typedef_signature_equivalence(unit_frontend,tmp_path):
    r=admit(task('typedef int I; I f(I x){return x;}'),'v1',out_dir=tmp_path)
    assert r.decision=='ok'


def test_pointer_pointee_qualifiers_matter(unit_frontend,tmp_path):
    r=admit(task('int f(int *x){return *x;}','int f(const int *x){return *x;}'),'v1',out_dir=tmp_path)
    assert r.decision=='undecided'


def test_globals_are_classified_and_new_storage_refused(unit_frontend,tmp_path):
    code='const int limit=4;int count;int f(int x){count+=x;return count+limit;}'
    r=admit(task(code,code),'v1',out_dir=tmp_path/'same')
    assert dict(r.globals)=={'count':'input_output','limit':'const_program'}
    r=admit(task('static int hidden;int f(int x){return x+hidden;}'),'v1',out_dir=tmp_path/'new')
    assert r.decision=='reject' and {f.code for f in r.findings}=={'NEW_GLOBAL'}


def test_shadowed_global_is_not_an_input_or_output(unit_frontend,tmp_path):
    code='int g;int f(int x){int g=x;return g;}'
    r=admit(task(code,code),'v1',out_dir=tmp_path)
    assert not r.globals


def test_existing_global_removal_and_type_change_are_interface_changes(unit_frontend,tmp_path):
    old='int g;int f(int x){return x+g;}'
    for i,new in enumerate(['int f(int x){return x;}','long g;int f(int x){return x+g;}']):
        assert admit(task(new,old),'v1',out_dir=tmp_path/str(i)).status=='interface_change'


def test_pragmas_are_logged_per_program_and_view(unit_frontend,tmp_path):
    code='''int f(int x){
#pragma HLS PIPELINE II=1
#pragma HLS SOMETHING key=value
return x;
}'''
    r=admit(task(code),'v1',out_dir=tmp_path)
    assert r.decision=='ok' and {p.name for p in r.pragmas}=={'PIPELINE','SOMETHING'}
    report=json.loads((tmp_path/'admission.json').read_text())
    assert report['pragma_policy']=='NOT_RUN'
    assert {p['program'] for p in report['pragmas']}=={'p1'}
    assert {p['mode'] for p in report['pragmas']}=={'sim','synth'}


def test_library_model_signature_is_checked_and_requirement_recorded(unit_frontend,tmp_path):
    r=admit(task('int abs(int x);int f(int x){return abs(x);}'),'v1',out_dir=tmp_path/'good')
    assert r.decision=='ok' and r.required_library_models==('abs',)
    r=admit(task('long abs(long x);int f(int x){return abs(x);}'),'v1',out_dir=tmp_path/'bad')
    assert r.decision=='reject' and 'library signature' in r.reason


def test_unqualified_preprocessing_and_failed_listing_never_admit(unit_frontend,monkeypatch,tmp_path):
    base=frontend.preprocess
    def provisional(*a,**kw):
        text,commands,_=base(*a,**kw);return text,commands,'gcc-fallback-unqualified'
    monkeypatch.setattr(frontend,'preprocess',provisional)
    assert admit(task(),'v1',out_dir=tmp_path/'cpp').status=='inconclusive'
    monkeypatch.setattr(frontend,'preprocess',base)
    monkeypatch.setattr(frontend,'list_undefined',lambda *a,**kw:frontend.UndefinedFunctions(False,(),(),'listing error'))
    assert admit(task(),'v1',out_dir=tmp_path/'goto').status=='inconclusive'


@pytest.mark.skipif(not cbmc.cbmc_available(),reason='CBMC unavailable')
@pytest.mark.integration
@pytest.mark.parametrize('name',['ex1_saturate','ex2_argmax','ex4_sum'])
def test_real_example_tasks_are_admitted(tmp_path,name):
    root=Path(__file__).resolve().parent.parent
    r=admit(load_pipeline_view(root/'examples/tasks'/name),'v1',out_dir=tmp_path/name)
    assert r.decision=='ok',r.reason
    assert len(r.commands)==12  # four preprocess + four compile/list pairs


@pytest.mark.skipif(not cbmc.cbmc_available(),reason='CBMC unavailable')
@pytest.mark.integration
def test_real_synthesis_branch_is_detected(tmp_path):
    code='''int f(int x){
#ifdef __SYNTHESIS__
return x+1;
#else
return x;
#endif
}'''
    r=admit(task(code),'v1',out_dir=tmp_path)
    assert r.decision=='ok' and r.views_differ


@pytest.mark.skipif(not cbmc.cbmc_available(),reason='CBMC unavailable')
@pytest.mark.integration
def test_real_missing_body_is_policy_refusal(tmp_path):
    r=admit(task('int helper(int);int f(int x){return helper(x);}'),'v1',out_dir=tmp_path)
    assert r.decision=='reject' and r.undefined_functions==('helper',)


def test_unused_reserved_declaration_still_refused(unit_frontend,tmp_path):
    r=admit(task('void __CPROVER_assume(int);int f(int x){return x;}'),'v1',out_dir=tmp_path)
    assert r.decision=='reject' and r.findings[0].code=='VERIFIER_IDENTIFIER'


def test_pointer_address_cast_refused_but_sizeof_pointer_allowed(unit_frontend,tmp_path):
    r=admit(task('long f(int *p){return (long)p;}','long f(int *p){return *p;}'),'v1',out_dir=tmp_path/'cast')
    assert r.decision=='undecided'
    code='int f(int x){return x+sizeof(int*);}'
    assert admit(task(code,code),'v1',out_dir=tmp_path/'sizeof').decision=='ok'


def test_field_names_do_not_become_type_qualifiers(unit_frontend,tmp_path):
    code='struct S {int volatile_count;};int f(int x){struct S s={x};return s.volatile_count;}'
    assert admit(task(code,code),'v1',out_dir=tmp_path).decision=='ok'


def test_inline_assembly_refused_even_when_parser_cannot_parse_it(unit_frontend,tmp_path):
    r=admit(task('int f(int x){__asm__ volatile("nop");return x;}'),'v1',out_dir=tmp_path)
    assert r.decision=='reject' and r.findings[0].code=='INLINE_ASSEMBLY'


def test_reserved_words_inside_string_are_not_policy_findings(unit_frontend,tmp_path):
    code='int f(int x){return x+"__CPROVER_assume asm"[0];}'
    assert admit(task(code,code),'v1',out_dir=tmp_path).decision=='ok'


def test_typedef_const_global_classification(unit_frontend,tmp_path):
    code='typedef const int C;C limit=4;int f(int x){return limit+x;}'
    r=admit(task(code,code),'v1',out_dir=tmp_path)
    assert r.decision=='ok' and r.globals['limit']=='const_program'


def test_global_pointer_requires_an_alias_model(unit_frontend,tmp_path):
    code='int data[4];int *p=data;int f(int x){return p[x];}'
    r=admit(task(code,code),'v1',out_dir=tmp_path)
    assert r.decision=='undecided' and any(f.code=='GLOBAL_POINTER' for f in r.findings)


def test_atomic_type_is_unsupported(unit_frontend,tmp_path):
    r=admit(task('int f(int x){_Atomic int y=x;return y;}'),'v1',out_dir=tmp_path)
    assert r.decision=='undecided'


def test_global_struct_pointer_field_requires_alias_model(unit_frontend,tmp_path):
    code='struct S {int *p;};struct S state;int f(int x){return state.p[x];}'
    r=admit(task(code,code),'v1',out_dir=tmp_path)
    assert r.decision=='undecided' and any(f.code=='GLOBAL_POINTER' for f in r.findings)


def test_source_snapshot_hash_is_checked_before_compilation(unit_frontend,monkeypatch,tmp_path):
    from dataclasses import replace
    t=task();t=replace(t,p0=replace(t.p0,sha256='0'*64))
    monkeypatch.setattr(frontend,'preprocess',lambda *a,**kw:pytest.fail('must not compile a changed snapshot'))
    assert admit(t,'v1',out_dir=tmp_path).status=='inconclusive'
