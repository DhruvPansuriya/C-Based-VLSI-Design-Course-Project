"""Smoke-test the packaged sources, rather than relying on the live checkout."""
from html.parser import HTMLParser
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import zipfile

ROOT=Path(__file__).resolve().parents[1]


class Assets(HTMLParser):
    def __init__(self):
        super().__init__()
        self.sources=[]
    def handle_starttag(self,tag,attrs):
        if tag=='img':
            self.sources.extend(v for k,v in attrs if k=='src')


def main():
    destination=ROOT/'tmp/package-check'
    destination.mkdir(parents=True,exist_ok=True)
    with zipfile.ZipFile(ROOT/'output/Project3_Submission.zip') as archive:
        for name in archive.namelist():
            assert '..' not in Path(name).parts and not Path(name).is_absolute()
        manifest=json.loads(archive.read('Project3/SUBMISSION_MANIFEST.json'))
        for row in manifest['files']:
            assert hashlib.sha256(archive.read('Project3/'+row['path'])).hexdigest()==row['sha256']
        archive.extractall(destination)
    packaged=destination/'Project3'
    interpreter=ROOT/'.venv/Scripts/python.exe'
    if not interpreter.exists():
        interpreter=Path(sys.executable)
    for filename in ('scripts/verify_submission.py','scripts/replay_smt_evidence.py','scripts/demo.py','scripts/validate_reliability_evidence.py','scripts/validate_hybrid_evidence.py','scripts/validate_large_evidence.py'):
        result=subprocess.run([str(interpreter),str(packaged/filename)],cwd=packaged,capture_output=True,text=True,timeout=90)
        print(filename,'exit',result.returncode,flush=True)
        if result.returncode:
            raise RuntimeError(result.stdout+result.stderr)
    deck=packaged/'output/presentation/project3_slides.html'
    parser=Assets()
    parser.feed(deck.read_text(encoding='utf-8'))
    assert all((deck.parent/name).exists() for name in parser.sources)
    evidence={'passed':True,'archive_entry_hashes_verified':True,'packaged_formal_checks_passed':True,'packaged_smt_dependencies_replayed':True,
              'packaged_live_demo_passed':True,'packaged_reliability_evidence_checked':True,
              'packaged_hybrid_evidence_checked':True,'all_html_images_resolve':True,
              'scope':'Source/evidence ZIP smoke test using the installed project Python dependencies; no in-browser visual preview'}
    (ROOT/'results/submission/package_validation.json').write_text(json.dumps(evidence,indent=2)+'\n')
    print('Packaged proof/demo checks and all image links passed.',flush=True)


if __name__=='__main__':
    main()
