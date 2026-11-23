import subprocess
import sys
from vwe import __version__


def test_module_version():
    r=subprocess.run([sys.executable,'-m','vwe','--version'],capture_output=True,text=True,timeout=10)
    assert r.returncode==0 and r.stdout.strip()==__version__


def test_missing_verify_is_not_a_fake_verdict():
    r=subprocess.run([sys.executable,'-m','vwe','verify'],capture_output=True,text=True,timeout=10)
    assert r.returncode==2 and 'ACCEPT' not in r.stdout
