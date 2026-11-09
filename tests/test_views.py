from pathlib import Path
import shutil
import re
import subprocess
import pytest
from vwe.c_frontend import UnsupportedC,analyze,renamed,source_policy
from vwe.tools import frontend,cbmc
from vwe.views import ViewError,make_views


@pytest.fixture
def fake_preprocessor(monkeypatch):
    def preprocess(src,*,synth,timeout_s,fallback_cc):
        # Unit tests use C without headers/macros; actual macro behavior is an
        # installed-tool integration test, not an imitation of a preprocessor.
        text=src.read_text().split('#line 1 "input.c"\n',1)[1]
        r=frontend.CommandResult(('mock-preprocess',),str(src.parent),0,text,'',0)
        return text,(r,),'cbmc'
    monkeypatch.setattr(frontend,'preprocess',preprocess)


def test_view_hashes_stable_and_namespaces_separate(fake_preprocessor,tmp_path):
    p=tmp_path/'source.c';p.write_text('int f(int x){return x+1;}')
    a=make_views(p,'f',tmp_path/'a',prefix='p0')
    b=make_views(p,'f',tmp_path/'b',prefix='p0')
    assert a.sim.sha256==b.sim.sha256 and a.sim.renamed_sha256==b.sim.renamed_sha256
    assert a.sim.entry_point=='p0_f' and not a.views_differ
    assert (tmp_path/'a/views.json').exists()
    assert 'p0_f' in a.sim.renamed.read_text()


def test_namespace_keeps_literals_fields_parameters_and_local_shadows():
    source='''struct S {int g;}; int g; int h(int x){return x+g;}
    int f(int x){struct S s={.g=2}; {int g=3; x+=g;} return h(x)+g+s.g+"g h f"[0];}'''
    a=analyze(source,'f');text,names=renamed(a,'p1')
    assert dict(names)=={'f':'p1_f','g':'p1_g','h':'p1_h'}
    assert '"g h f"' in text and 's.g' in text and '.g = 2' in text
    assert 'int g = 3' in text and 'x += g' in text and 'p1_h(x) + p1_g' in text


def test_namespace_block_extern_prototype_and_global_reference():
    source='int g; int h(int x){return x;} int f(int x){extern int g; int h(int); return h(x)+g;}'
    text,_=renamed(analyze(source,'f'),'p1')
    assert 'extern int p1_g' in text and 'int p1_h(int)' in text and 'p1_h(x) + p1_g' in text


def test_namespace_capture_is_refused():
    with pytest.raises(UnsupportedC,match='collision'):
        renamed(analyze('int g;int f(int x){int p1_g=1;return g+x+p1_g;}','f'),'p1')


@pytest.mark.parametrize('source',[
 '#include "../eval/p_ref.c"\nint f(void){return 0;}',
 '#include "/tmp/secret.h"\nint f(void){return 0;}',
 '#define H "secret.h"\n#include H\nint f(void){return 0;}',
 '#include_next <limits.h>\nint f(void){return 0;}',
 '#line 999 "trusted.c"\nint f(void){return 0;}',
 'char *f(void){return __FILE__;}',
])
def test_unsafe_dependency_and_environment_inputs_refused(source):
    assert source_policy(source)


def test_comments_literals_and_spliced_comments_do_not_fake_includes():
    assert not source_policy('/* #include "/secret.h" */\nint f(void){return "__FILE__"[0];}')
    assert not source_policy('// continued\\\n#include "hidden.h"\nint f(void){return 0;}')


def test_source_policy_stops_preprocessing(monkeypatch,tmp_path):
    p=tmp_path/'bad.c';p.write_text('#include "../eval/p_ref.c"\nint f(void){return 0;}')
    monkeypatch.setattr(frontend,'preprocess',lambda *a,**kw:pytest.fail('must not invoke a compiler'))
    with pytest.raises(ViewError,match='INCLUDE'): make_views(p,'f',tmp_path/'out')


@pytest.mark.skipif(not cbmc.cbmc_available(),reason='CBMC unavailable')
@pytest.mark.integration
def test_real_preprocessing_macro_control_and_hash_stability(tmp_path):
    p=tmp_path/'source.c';p.write_text('''int f(int x) {
#ifdef __SYNTHESIS__
 return x+1;
#else
 return x;
#endif
}''')
    a=make_views(p,'f',tmp_path/'a');b=make_views(p,'f',tmp_path/'b')
    assert a.views_differ and a.sim.sha256==b.sim.sha256 and a.synth.sha256==b.synth.sha256
    assert 'x + 1' in a.synth.renamed.read_text() and 'x + 1' not in a.sim.renamed.read_text()
    assert 'CBMC version' not in a.sim.preprocessed.read_text()


@pytest.mark.parametrize('source',[
 '%:include "../eval/p_ref.c"\nint f(void){return 0;}',
 '??=include "../eval/p_ref.c"\nint f(void){return 0;}',
 '\ufeff#include "../eval/p_ref.c"\nint f(void){return 0;}',
 '#inc\\\rlude "../eval/p_ref.c"\rint f(void){return 0;}',
 'int f(void){return __has_include("../eval/p_ref.c");}',
 '_Pragma("GCC dependency ../eval/p_ref.c") int f(void){return 0;}',
])
def test_alternative_preprocessor_spellings_cannot_escape_snapshot(source):
    assert source_policy(source)


def test_local_struct_field_does_not_shadow_a_global():
    code='int g;int f(int x){struct S {int g;} s={x};return g+s.g;}'
    a=analyze(code,'f');text,_=renamed(a,'p1')
    assert a.globals==(('g','input_output'),)
    assert 'return p1_g + s.g' in text


@pytest.mark.skipif(shutil.which('cc') is None,reason='native compiler unavailable')
def test_namespace_preserves_native_behavior_and_global_state(tmp_path):
    code='''struct S {int g;}; int g=7;
static int h(int x){return x+g;}
int f(int x){
 struct S s={.g=2}; int result=h(x);
 for(int g=0;g<3;g++) result+=g;
 {int g=x;result+=g;}
 g+=1;return result+g+s.g+"g"[0];
}'''
    text,_=renamed(analyze(code,'f'),'p1')
    (tmp_path/'old.c').write_text(code);(tmp_path/'new.c').write_text(text)
    (tmp_path/'driver.c').write_text('''#include <assert.h>
extern int g,p1_g;int f(int);int p1_f(int);
int main(void){for(int x=-8;x<=8;x++){g=p1_g=5;assert(f(x)==p1_f(x));assert(g==p1_g);}return 0;}''')
    r=frontend.execute(['cc','-std=c11','-Wall','-Wextra','-Werror','old.c','new.c','driver.c','-o','check'],cwd=tmp_path,timeout_s=15)
    assert r.ok,r.stderr
    assert frontend.execute([str(tmp_path/'check')],cwd=tmp_path,timeout_s=5).ok


def test_function_name_introspection_cannot_be_alpha_renamed_silently():
    assert source_policy('int f(void){return __func__[0];}')
    assert source_policy('int f(void){return __FUNCTION__[0];}')
