"""The demo's reduced profiles must stay explicit and isolated from source tasks."""
import importlib.util
import json
from pathlib import Path
import shutil

import pytest

ROOT = Path(__file__).resolve().parents[1]


def demo_module():
    spec = importlib.util.spec_from_file_location('vwe_professor_demo', ROOT / 'scripts/demo.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_demo_reduces_caller_and_reading_bounds_without_changing_originals(tmp_path):
    module = demo_module()
    original = ROOT / 'examples/tasks/ex4_sum'
    before = {p.relative_to(original): p.read_bytes() for p in original.rglob('*') if p.is_file()}
    destination = tmp_path / 'demo_task'
    shape = module.prepare_task('ex4_sum', destination, 2)
    assert shape['bounds']['n'] == [1, 2]
    manifest = json.loads((destination / 'task.json').read_text())
    readings = [json.loads((destination / p).read_text()) for p in manifest['interpretations']]
    assert all(i['shape']['bounds']['n'] == [1, 2] for i in readings)
    assert any(i['shape']['buffers']['a'] == 'n - 1' for i in readings)
    assert 'Demo-only size bounds capped to K=2.' in manifest['source']['adaptations']
    assert before == {p.relative_to(original): p.read_bytes() for p in original.rglob('*') if p.is_file()}


def test_demo_refuses_to_reduce_below_a_caller_minimum(tmp_path, monkeypatch):
    module = demo_module()
    source = tmp_path / 'source/examples/tasks/ex4_sum'
    shutil.copytree(ROOT / 'examples/tasks/ex4_sum', source)
    manifest = source / 'task.json'
    data = json.loads(manifest.read_text())
    data['caller_domain']['bounds']['n'] = [3, 4]
    manifest.write_text(json.dumps(data))
    monkeypatch.setattr(module, 'ROOT', tmp_path / 'source')
    with pytest.raises(ValueError, match='minimum n exceeds demo K'):
        module.prepare_task('ex4_sum', tmp_path / 'demo', 2)
