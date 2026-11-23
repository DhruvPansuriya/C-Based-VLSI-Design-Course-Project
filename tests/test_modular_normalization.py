"""Nonlinear modular identities must preserve full-domain verdicts."""
from hlscheck import check_equivalence
import z3


def test_polynomial_reassociation_wraparound():
    a='unsigned f(unsigned x,unsigned y){return (x-y)*(x-y);}'
    b='unsigned f(unsigned x,unsigned y){return x*x+y*y-2u*x*y;}'
    assert check_equivalence(a,b)['status']=='equivalent'


def test_normalization_retains_nonzero_difference():
    a='unsigned f(unsigned x,unsigned y){return (x-y)*(x-y);}'
    b='unsigned f(unsigned x,unsigned y){return x*x+y*y-2u*x*y+1u;}'
    result=check_equivalence(a,b)
    assert result['status']=='not_equivalent'
    assert result['original_outputs']['return']!=result['candidate_outputs']['return']


def test_independent_component_proofs_are_replayable(tmp_path):
    a='''unsigned f(unsigned a,unsigned b){unsigned s=0u;
    for(int i=0;i<8;i++)s+=(a>>i)&1u;
    for(int j=0;j<8;j++)s+=(b>>j)&1u;return s;}'''
    b='''unsigned f(unsigned a,unsigned b){unsigned x=a&255u,y=b&255u;
    x-=((x>>1)&0x55u);x=(x&0x33u)+((x>>2)&0x33u);
    y-=((y>>1)&0x55u);y=(y&0x33u)+((y>>2)&0x33u);
    return ((x+(x>>4))&15u)+((y+(y>>4))&15u);}'''
    query=tmp_path/'components.smt2'
    result=check_equivalence(a,b,smt_path=query)
    assert result['status']=='equivalent'
    assert result['main_query_requires_component_lemmas']
    for lemma in result['component_lemmas']:
        if lemma['status']=='unsat':
            solver=z3.Solver();solver.from_file(lemma['smt_file']);assert solver.check()==z3.unsat
    solver=z3.Solver();solver.from_file(str(query));assert solver.check()==z3.unsat


def test_proved_component_does_not_hide_a_real_difference():
    a='''unsigned f(unsigned x,unsigned y){unsigned s=0u;
    for(int i=0;i<8;i++)s+=(x>>i)&1u;return s+y;}'''
    b='''unsigned f(unsigned x,unsigned y){unsigned v=x&255u;
    v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);
    return ((v+(v>>4))&15u)+y+1u;}'''
    result=check_equivalence(a,b)
    assert result['status']=='not_equivalent'
    assert result['main_query_requires_component_lemmas']
    assert result['original_outputs']['return']!=result['candidate_outputs']['return']
