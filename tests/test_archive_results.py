"""Packaging evidence must preserve successful observations and their integrity."""
import argparse
from hashlib import sha256
import importlib.util
import json
from pathlib import Path
import tarfile

import pytest

from vwe.schemas import validate

ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location('archive_results', ROOT / 'scripts/archive_results.py')
ARCHIVER = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(ARCHIVER)
CHECKPOINT = ROOT / 'evaluation/results/checkpoints/2026-11-23-t11'


@pytest.mark.parametrize('text,passed,skipped', [
    ('....\n325 passed, 1 skipped in 358.89s (0:05:58)\n', 325, 1),
    ('2 passed in 0.23s\n', 2, 0),
])
def test_pytest_summary_preserves_counts(tmp_path, text, passed, skipped):
    path = tmp_path / 'tests.log'
    path.write_text(text)
    result = ARCHIVER.pytest_summary(path)
    assert result['passed'] == passed and result['skipped'] == skipped


@pytest.mark.parametrize('text', ['...still running', '1 failed, 2 passed in 1.0s', '2 passed, 1 error in 1.0s'])
def test_incomplete_or_failed_logs_are_not_success(tmp_path, text):
    path = tmp_path / 'tests.log'
    path.write_text(text)
    with pytest.raises(ValueError):
        ARCHIVER.pytest_summary(path)


def test_existing_checkpoint_is_never_overwritten(tmp_path):
    folder = tmp_path / 'checkpoint'
    folder.mkdir()
    sentinel = folder / 'evidence.json'
    sentinel.write_text('preserve me')
    with pytest.raises(ValueError, match='already exists'):
        ARCHIVER.archive(argparse.Namespace(out=tmp_path, label='checkpoint'))
    assert sentinel.read_text() == 'preserve me'


@pytest.mark.parametrize('label', ['../escape', '.', '/absolute', 'a/b'])
def test_checkpoint_label_cannot_escape(tmp_path, label):
    with pytest.raises(ValueError, match='safe directory'):
        ARCHIVER.archive(argparse.Namespace(out=tmp_path, label=label))


def test_archived_payload_hashes_and_portable_reports():
    hashes = json.loads((CHECKPOINT / 'checksums.json').read_text())
    for name, expected in hashes.items():
        path = (CHECKPOINT / name).resolve()
        assert path.is_relative_to(CHECKPOINT.resolve()) and path.is_file()
        assert sha256(path.read_bytes()).hexdigest() == expected, name
    rows = json.loads((CHECKPOINT / 'golden.json').read_text())['rows']
    assert len(rows) == 20 and all(row['match'] for row in rows)
    for row in rows:
        assert not Path(row['report']).is_absolute()
        report = json.loads((CHECKPOINT / row['report']).read_text())
        validate('verdict_report', report)
        assert [report['decision'], report['evidence_class']] == row['got'] == row['expected']


def test_raw_archive_contains_deciding_evidence_without_binaries():
    with tarfile.open(CHECKPOINT / 'raw-evidence.tar.gz', 'r:gz') as tar:
        members = tar.getmembers()
    names = {member.name for member in members}
    assert 'golden/ex2_argmax/v3/native/witness-0.json' in names
    assert 'demo/path_cut/sat.json' in names
    assert any('/fixed/0/' in name and name.endswith('/sat.json') for name in names)
    assert all(member.isfile() and not Path(member.name).is_absolute()
               and '..' not in Path(member.name).parts for member in members)
    assert not any(name.endswith('.goto') or Path(name).name == 'driver' for name in names)
