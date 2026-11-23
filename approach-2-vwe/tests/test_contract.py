from __future__ import annotations
from dataclasses import replace
from pathlib import Path
from types import MappingProxyType
import json,random,shutil,subprocess,sys
import pytest
from vwe.contract import parse,ContractParser
from vwe.contract.ast import GrammarError,ContractTypeError,ContractUnsupported,ContractUndefined,Sort,Literal,Binary,Interval
from vwe.contract.env import TypeEnv,Symbol,ScalarType,I64_MIN,I64_MAX
from vwe.contract.typecheck import typecheck
from vwe.contract.emit import emit_c,emit_function
from vwe.contract.evaluate import evaluate
from vwe.tasks import load_pipeline_view
from vwe.tools import frontend,cbmc

ROOT=Path(__file__).resolve().parent.parent


@pytest.fixture
def env():
    task=load_pipeline_view(ROOT/'examples/tasks/ex2_argmax')
    return TypeEnv.from_task(task,allow_old=True)


def test_all_stored_contracts_parse_type_and_emit():
    p=ContractParser();count=0
    for task_dir in sorted((ROOT/'examples/tasks').iterdir()):
        t=load_pipeline_view(task_dir)
        for reading in t.interpretations:
            e=TypeEnv.from_task(t,reading['shape'],allow_old=True)
            texts=[reading['reach'],*([reading['ext']] if reading['ext']!='unknown' else [])]
            texts += [expr for c in reading['clauses'] for expr in (c['zone'],c['behaviour'])]
            for text in texts:
                ast=p.parse(text);typed=typecheck(ast,e,expected=Sort.BOOL)
                generated=emit_function(typed)
                assert generated.source and generated.vg_required
                count+=1
    assert count>=28


@pytest.mark.parametrize('text',[
 'out_ret = 0','++n','n--','n; abort()','__CPROVER_assume(n)','system(n)',
 '(int*)n','*(a+1)','a.field','a->field','n += 1','n, out_ret','"text"','/*hide*/true',
 'sum(i,0,n)','forall(1,0,n,true)',
])
def test_injection_and_unrestricted_c_rejected(text):
    with pytest.raises(GrammarError): parse(text)


@pytest.mark.parametrize('text',[
 'missing == 0','n && true','a + 1 == 0','n[0] == 0','a == a','true == 1',
 'min(n) == 0','abs(n,n) == 0','sum(i,0,n,true) == 0','forall(i,0,n,a[i])',
 'forall(n,0,n,true)','forall(i,0,out_ret,true)','__CPROVER_hidden == 0',
])
def test_bad_types_and_bindings_rejected(env,text):
    with pytest.raises(ContractTypeError): typecheck(text,env)


def test_old_output_requires_explicit_permission(env):
    with pytest.raises(ContractTypeError): typecheck('out_ret == old_ret',env.with_old(False))
    typed=typecheck('n == 0 || out_ret == old_ret',env)
    assert typed.old_symbols==('old_ret',)


def test_numeric_and_boolean_roots_are_distinct(env):
    with pytest.raises(ContractTypeError): emit_c('n + 1',env)
    assert 'long long vwe_clause' in emit_function('n+1',env,boolean=False).source


def test_parser_complexity_and_observer_limits_are_explicit(env):
    with pytest.raises(ContractUnsupported): ContractParser(max_length=10).parse('n == 0 || n == 1')
    with pytest.raises((GrammarError,ContractUnsupported)): ContractParser(max_depth=4).parse('!'*20+'true')
    with pytest.raises(ContractUnsupported): typecheck('sum(i,0,1000,i)==0',env)
    with pytest.raises(ContractUnsupported): typecheck('9223372036854775808 == 0',env)
    with pytest.raises(ContractUnsupported): emit_c('true',env,wide='__int128')


def test_forged_ast_operator_does_not_bypass_the_parser(env):
    with pytest.raises(ContractTypeError): typecheck(Binary(');abort();(',Literal(1),Literal(2)),env)


def test_guarded_array_access_and_old_output_are_lazy(env):
    typed=typecheck('n == 0 ? out_idx[0] == -1 : out_ret == old_ret',env)
    assert evaluate(typed,{'n':0,'out_idx':[-1]}) is True
    assert evaluate(typecheck('n==0 || a[0] > 0',env),{'n':0,'a':[]}) is True
    assert evaluate(typecheck('n==0 || sum(i,0,1,a[i]) > 0',env),{'n':0,'a':[]}) is True


def test_eager_quantifiers_do_not_conceal_an_invalid_later_index(env):
    typed=typecheck('exists(i,0,2,a[i] == 0)',env)
    with pytest.raises(ContractUndefined): evaluate(typed,{'a':[0]})
    with pytest.raises(ContractUndefined): evaluate(typecheck('a[-1] == 0',env),{'a':[0]})


def test_empty_quantifiers_and_reductions(env):
    vals={'n':0,'a':[]}
    assert evaluate(typecheck('forall(i,0,n,a[i] > 0)',env),vals) is True
    assert evaluate(typecheck('exists(i,0,n,a[i] > 0)',env),vals) is False
    assert evaluate(typecheck('sum(i,0,n,a[i])',env),vals)==0
    assert evaluate(typecheck('count(i,0,n,a[i] > 0)',env),vals)==0


def test_signed_division_remainder_overflow_and_minimum_literal(env):
    assert evaluate(typecheck('-7 / 3 == -2 && -7 % 3 == -1',env),{}) is True
    assert evaluate(typecheck('-9223372036854775808 == LLONG_MIN',env),{}) is True
    with pytest.raises(ContractUndefined): evaluate(typecheck('1/n==0',env),{'n':0})
    with pytest.raises(ContractUndefined): evaluate(typecheck('LLONG_MAX+1==0',env),{})
    with pytest.raises(ContractUndefined): evaluate(typecheck('abs(LLONG_MIN)==0',env),{})


def test_safe_shifts_and_unsupported_shift_ranges(env):
    assert evaluate(typecheck('1 << n',env),{'n':4})==16
    with pytest.raises(ContractUnsupported): typecheck('1 << out_ret',env)


def test_output_ranges_are_not_narrowed_by_input_bounds():
    t=load_pipeline_view(ROOT/'examples/tasks/ex4_sum');e=TypeEnv.from_task(t)
    assert e.symbols['a'].values==Interval(-1000,1000)
    assert e.symbols['out_a'].values.low==-(1<<31)
    assert e.symbols['old_a'].values.high==(1<<31)-1


def test_emission_and_symbol_order_are_deterministic(env):
    expr='out_ret == sum(i,0,n,a[i])'
    a=emit_function(expr,env);b=emit_function(parse(expr),env)
    assert a==b and a.parameters==('a','n','out_ret')


def test_exact_cli_example_runs_without_a_verifier():
    r=subprocess.run([sys.executable,'-m','vwe.contract.emit',
        'n == 0 ? (out_ret == INT_MIN && out_idx[0] == -1) : (out_ret == old_ret)',
        '--task',str(ROOT/'examples/tasks/ex2_argmax')],capture_output=True,text=True,timeout=15)
    assert r.returncode==0 and 'static inline int vwe_clause' in r.stdout,r.stderr


@pytest.mark.skipif(shutil.which('cc') is None,reason='C compiler unavailable')
def test_generated_observers_match_independent_semantics(env,tmp_path):
    expressions=[
      'n == 0 || a[n-1] >= -10',
      'n == 0 || sum(i,0,1,a[i]) >= -10',
      'n == 0 ? true : forall(i,0,1,a[i] != 1234)',
      'n == 0 || 20/n >= 1',
      'n == 0 || out_ret == min(a[0],max(a[0]+1,-2))',
      'out_ret == (n==0 ? 0 : sum(i,0,n,a[i]))',
      'out_ret == sum(i,0,n,a[i])',
      'count(i,0,n,a[i] >= 0) <= n',
      'n == 0 || out_ret == a[0] / n',
      'n == 0 || out_ret == a[0] % n',
      '(1 << n) >= 1',
      'forall(i,0,n,exists(j,0,n,a[i] == a[j]))',
      'forall(i,0,n,a[i]>=-10) && (n==0 || exists(i,0,n,a[i]<20))',
      'n==0 || ((a[0] & 3) >= 0)',
      'n==0 ? (out_ret == INT_MIN && out_idx[0] == -1) : out_ret == old_ret',
    ]
    rng=random.Random(42);code=['#include <stddef.h>','#include <stdio.h>'];body=[];checks=0
    for i,expr in enumerate(expressions):
        typed=typecheck(expr,env);generated=emit_function(typed,name=f've_case_{i}');code.append(generated.source)
        for j in range(35):
            n=j%5;array=[rng.randint(-10,10) for _ in range(n)]
            vals={'n':n,'a':array,'out_ret':(-(1<<31) if n==0 else rng.randint(-20,20)),
                  'old_ret':rng.randint(-20,20),'out_idx':[-1]}
            expected=int(evaluate(typed,vals));arguments=[]
            for k,name in enumerate(generated.parameters):
                s=env.symbols[name];value=vals[name]
                if s.sort is Sort.BUFFER:
                    ident=f'v_{i}_{j}_{k}'
                    if value: body.append(f'const {s.scalar.c_name} {ident}[]={{'+','.join(map(str,value))+'};')
                    else: body.append(f'const {s.scalar.c_name} *{ident}=NULL;')
                    arguments.append(ident)
                else: arguments.append(str(value))
            body.append(f'if (ve_case_{i}('+','.join(arguments)+f') != {expected}) {{printf("case {i} row {j} failed\\n");return 1;}}')
            checks+=1
    code.append('int main(void){\n'+'\n'.join(body)+'\nreturn 0;\n}')
    p=tmp_path/'observers.c';p.write_text('\n'.join(code))
    built=frontend.execute(['cc','-std=c11','-Wall','-Werror',p.name,'-o','observers'],cwd=tmp_path,timeout_s=30)
    assert built.ok,built.stderr
    ran=frontend.execute([str(tmp_path/'observers')],cwd=tmp_path,timeout_s=10)
    assert ran.ok,ran.stdout+ran.stderr
    assert checks==525


@pytest.mark.skipif(not cbmc.cbmc_available(),reason='CBMC unavailable')
@pytest.mark.integration
def test_vg_detects_eager_quantifier_oob_even_after_a_true_witness(env,tmp_path):
    generated=emit_function('exists(i,0,2,a[i] == 0)',env)
    text='#include <stdlib.h>\n'+generated.source+'''\nint main(void){
 int *a=malloc(sizeof(int));a[0]=0;
 __CPROVER_assert(vwe_clause(a),"exists predicate");
 free(a);return 0;
}'''
    p=tmp_path/'harness.c';p.write_text(text)
    run=cbmc.run([str(p)],unwind=3,timeout_s=30)
    assert run.ok and any('pointer_dereference' in p.property_id for p in run.failed()),run.stderr_tail


def test_overlapping_scalar_bounds_are_intersected():
    t=load_pipeline_view(ROOT/'examples/tasks/ex2_argmax')
    shape={**t.caller_domain,'value_bounds':{'n':[1,2]}}
    e=TypeEnv.from_task(t,shape)
    assert e.symbols['n'].values==Interval(1,2)
    with pytest.raises(ContractTypeError):
        TypeEnv.from_task(t,{**shape,'value_bounds':{'n':[8,9]}})


def test_loop_limits_are_reported_for_harness_unwinding(env):
    emitted=emit_function('forall(i,0,n,a[i]>=0)',env)
    assert len(emitted.loop_limits)==1 and emitted.loop_limits[0][1]==4


@pytest.mark.parametrize('text,expected',[
 ('1+2*3==7',True),('(1|2)==3 && (8>>2)==2',True),
 ('-7/3==-2 && -7%3==-1',True),('true ? false : true',False),
])
def test_operator_precedence_and_signed_semantics(env,text,expected):
    assert evaluate(typecheck(text,env),{}) is expected


def test_null_snapshot_is_a_contract_error_not_an_interpreter_crash(env):
    with pytest.raises(ContractUndefined): evaluate(typecheck('a[0]==0',env),{'a':None})
    assert evaluate(typecheck('n==0 || a[0]==0',env),{'n':0,'a':None}) is True


def test_bool_parameters_are_typed_without_integer_truthiness():
    from vwe.c_frontend import analyze
    e=TypeEnv.from_analysis(analyze('_Bool f(_Bool flag){return flag;}','f'),{'buffers':{},'bounds':{}})
    typed=typecheck('out_ret == flag',e)
    assert evaluate(typed,{'out_ret':True,'flag':True}) is True
    assert '_Bool' in emit_c(typed)
