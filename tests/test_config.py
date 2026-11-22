from dataclasses import FrozenInstanceError
import pytest
from vwe.config import ConfigError, load_config


def test_defaults():
    c=load_config()
    assert (c.bounds.K,c.bounds.max_unwind)==(4,9)
    assert c.backends.primary==("sat","z3")
    assert c.timeouts.cbmc_s==600
    with pytest.raises(FrozenInstanceError): c.bounds.K=5
    with pytest.raises(TypeError): c.llm["model"]="untracked"


@pytest.mark.parametrize("text",[
    "[bounds]\nK=0", "[bounds]\nK=true", "[bounds]\nK=9\nmax_unwind=9",
    "[bounds]\nunknown=1", "[other]\nx=1", "[timeouts]\ncbmc_s=-1",
    '[backends]\nprimary=["sat","sat"]', '[backends]\nprimary=["z3-incremental"]',
    '[native]\nsanitize=""', 'llm="not a table"',
])
def test_invalid_config_is_rejected(tmp_path,text):
    p=tmp_path/"bad.toml";p.write_text(text)
    with pytest.raises(ConfigError): load_config(p)


def test_explicit_overrides_and_deep_freeze(tmp_path):
    p=tmp_path/"config.toml"
    p.write_text('[bounds]\nK=2\n[llm]\nmodels=["fixture"]\n[llm.options]\nseed=42\n')
    c=load_config(p)
    assert c.bounds.K==2 and c.timeouts.cbmc_s==600 and c.llm['models']==('fixture',)
    with pytest.raises(TypeError): c.llm['options']['seed']=0


def test_missing_file(tmp_path):
    with pytest.raises(ConfigError): load_config(tmp_path/'missing.toml')
