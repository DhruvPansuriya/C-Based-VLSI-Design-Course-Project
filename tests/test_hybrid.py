"""Safety regressions for proof-level composition, not just engine dispatch."""
from pathlib import Path
import shutil

import pytest

from hlscheck import verify_equivalence
from hlscheck.frontend import compile_pair, Unsupported, InvalidC

ROOT=Path(__file__).resolve().parents[1]
EXE=ROOT/'tools/esbmc-v8.7/release/bin/esbmc.exe'
requires_tools=pytest.mark.skipif(not EXE.exists() or not shutil.which('clang'), reason='Clang/ESBMC unavailable')


def test_frontend_preserves_64_bit_nondeterminism():
    left,right,contract=compile_pair('typedef unsigned long long U; U f(U x){return x>>63;}',
                                    'unsigned long long f(unsigned long long y){return (y>>63)&1ULL;}')
    from hlscheck.miter import make_miter
    text=make_miter(left,right,contract)
    assert 'extern unsigned long long int __hlscheck_nondet_0(void)' in text
    assert contract['parameters'][0]['bits']==64


@pytest.mark.parametrize('source',[
    '#include <stdio.h>\nunsigned f(unsigned x){return x;}',
    '#inc\\\nlude "secret.h"\nunsigned f(unsigned x){return x;}',
    '#/**/include "secret.h"\nunsigned f(unsigned x){return x;}',
])
def test_unmodelled_headers_do_not_enter_frontend(source):
    with pytest.raises(Unsupported): compile_pair(source,source)


def test_const_typedef_is_not_silently_unqualified():
    with pytest.raises(Unsupported):
        compile_pair('typedef const unsigned U;unsigned f(unsigned x){U y=x;return y;}',
                     'unsigned f(unsigned x){return x;}')


def test_missing_return_does_not_become_a_shared_nondet_summary():
    with pytest.raises(InvalidC): compile_pair('unsigned f(unsigned x){}','unsigned f(unsigned x){}')


@pytest.mark.parametrize('kind',['unsigned unsigned int','long long long','signed signed int'])
def test_invalid_type_is_not_normalized_to_a_valid_program(kind):
    with pytest.raises((InvalidC,Unsupported)):
        compile_pair(f'{kind} f({kind} x){{return x;}}',f'{kind} f({kind} x){{return x;}}')


@pytest.mark.parametrize('expression',['__LINE__','__COUNTER__','(unsigned)sizeof(__FILE__)','(unsigned)1.5','sizeof("hello")'])
def test_unmodelled_context_and_storage_are_rejected(expression):
    source=f'unsigned f(void){{return {expression};}}'
    with pytest.raises(Unsupported): compile_pair(source,source)


@pytest.mark.parametrize('source',[
    'unsigned f(unsigned a[1]){return (unsigned)&a[0];}',
    'unsigned f(unsigned a[1]){return (unsigned)a;}',
    'void f(unsigned a[1],unsigned b[1]){a=b;}',
])
def test_array_identity_is_not_confused_with_value_equivalence(source):
    with pytest.raises(Unsupported): compile_pair(source,source)


@requires_tools
def test_abstract_counterexample_requires_certified_refinement(tmp_path):
    a='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int i=0;i<4;i++)out[i]=a[i]*13u;return out[k&3u];}'
    b='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int j=3;j>=0;j--)out[j]=(a[j]<<3)+(a[j]<<2)+a[j];return a[k%4u]*13u;}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='equivalent'
    assert r['obligations'][1]['status']=='not_equivalent'  # spurious coarse trace
    assert r['residual_proof']['abstraction']=='exact'
    assert {p['id'] for p in r['proof_dependencies']}=={'region_equality','summary_encoding'}


@requires_tools
def test_proved_regions_feed_one_residual_problem(tmp_path):
    a='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int i=0;i<4;i++)out[i]=a[i]*8u;return out[k&3u];}'
    b='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int i=0;i<4;i++)out[i]=a[i]<<3;return out[k%4u];}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='equivalent' and r['proof_dependencies']
    assert r['residual_proof']['abstraction']=='shared_havoc'
    assert not r['refinements']


@requires_tools
def test_region_mismatch_is_not_whole_program_mismatch(tmp_path):
    a='void f(unsigned a[1]){for(int i=0;i<1;i++)a[i]=1u;a[0]=0u;}'
    b='void f(unsigned a[1]){for(int i=0;i<1;i++)a[i]=2u;a[0]=0u;}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['region_analysis']['proof_status']=='not_equivalent'
    assert r['status']=='equivalent' and not r['proof_dependencies']


@requires_tools
def test_live_local_state_is_not_dropped_at_a_cut(tmp_path):
    a='unsigned f(unsigned a[4]){unsigned s=0u;for(int i=0;i<4;i++)s+=a[i];return s;}'
    b='unsigned f(unsigned a[4]){return a[0]+a[1]+a[2]+a[3];}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='equivalent' and r['region_analysis']['whole_function']


@requires_tools
def test_smt_witness_is_validated_in_actual_c(tmp_path):
    r=verify_equivalence('unsigned f(unsigned x){return x*13u;}',
                         'unsigned f(unsigned x){return x*11u;}',output_dir=tmp_path)
    assert r['status']=='not_equivalent' and 'counterexample' in r
    assert r['obligations'][-1]['input_domain']=='proposed counterexample only'
    assert r['residual_proof']['abstraction']=='none'


@requires_tools
def test_success_at_a_bad_proposed_witness_is_not_universal_proof(tmp_path,monkeypatch):
    import hlscheck.hybrid as hybrid
    real=hybrid.check_equivalence
    def wrong_witness(*args,**kwargs):
        r=real(*args,**kwargs)
        if r['status']=='not_equivalent': r['counterexample']={'x':0}
        return r
    monkeypatch.setattr(hybrid,'check_equivalence',wrong_witness)
    r=verify_equivalence('unsigned f(unsigned x){return x*13u;}',
                         'unsigned f(unsigned x){return x*11u;}',output_dir=tmp_path)
    assert r['status']=='not_equivalent'
    assert r['obligations'][1]['status']=='equivalent'  # x=0 agrees
    assert r['refinements'][0]['action'].startswith('Discard')
    assert r['obligations'][-1]['input_domain']=='full stated domain'


@requires_tools
def test_faulty_generated_summary_is_not_trusted(tmp_path,monkeypatch):
    import hlscheck.hybrid as hybrid
    monkeypatch.setattr(hybrid,'exact_summary',lambda *a,**k:'void f(unsigned a[1],unsigned k,unsigned out[1]){out[0]=a[0]*11u;}')
    a='unsigned f(unsigned a[1],unsigned k,unsigned out[1]){for(int i=0;i<1;i++)out[i]=a[i]*13u;return out[k&0u];}'
    b='unsigned f(unsigned a[1],unsigned k,unsigned out[1]){for(int i=0;i<1;i++)out[i]=a[i]*13u;return a[k&0u]*13u;}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='equivalent' and not r['proof_dependencies']
    assert r['residual_proof']['abstraction']=='none'


@requires_tools
def test_unwinding_exhaustion_is_inconclusive(tmp_path):
    a='unsigned f(unsigned a[4],unsigned n){unsigned s=0u;for(unsigned i=0u;i<n;i++)s+=a[i];return s;}'
    r=verify_equivalence(a,a,scalar_ranges={'n':[0,4]},max_unroll=1,output_dir=tmp_path)
    assert r['status']=='inconclusive'


@requires_tools
def test_u64_high_bit_fault_is_visible(tmp_path):
    a='unsigned long long f(unsigned long long x){return x>>63;}'
    b='unsigned long long f(unsigned long long x){return 0ULL;}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='not_equivalent'
    assert r['counterexample']['x'] >= 1<<63


@requires_tools
def test_signed_boundary_preserved(tmp_path):
    a='short f(short x){return x<0?(x==-32768?32767:-x):x;}'
    b='short f(short x){return x<0?-x:x;}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='not_equivalent' and r['counterexample']['x']==-32768


@requires_tools
def test_undefined_suffix_is_not_accepted_as_an_abstract_counterexample(tmp_path):
    a='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int i=0;i<4;i++)out[i]=a[i];return out[k&3u];}'
    b='unsigned f(unsigned a[4],unsigned k,unsigned out[4]){for(int i=0;i<4;i++)out[i]=a[i];return out[k&7u];}'
    r=verify_equivalence(a,b,output_dir=tmp_path)
    assert r['status']=='undefined_behavior' and r['refinements']
    assert r['residual_proof']['abstraction']!='shared_havoc'
