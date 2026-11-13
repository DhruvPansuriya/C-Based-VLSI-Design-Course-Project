"""Create a portable source/evidence ZIP with a per-file integrity manifest."""
import hashlib
import json
from pathlib import Path
import zipfile

ROOT=Path(__file__).resolve().parents[1]
DEST=ROOT/'output/Project3_Submission.zip'


def selected_files():
    selected=[]
    roots=['hlscheck','scripts','benchmarks','experiments','tests','docs','results']
    for folder in roots:
        selected.extend(p for p in (ROOT/folder).rglob('*') if p.is_file())
    selected.extend(p for p in ROOT.iterdir() if p.is_file() and (p.suffix in ('.py','.md','.MD','.txt','.ini','.c','.cpp') or p.name=='.gitignore'))
    selected.extend(p for p in (ROOT/'tools').glob('*.py'))
    selected.extend(p for p in (ROOT/'tools/nangate45').rglob('*') if p.is_file())
    for folder in ['pdf','figures','presentation']:
        selected.extend(p for p in (ROOT/'output'/folder).rglob('*') if p.is_file())
    return sorted(set(p for p in selected if '__pycache__' not in p.parts and p.suffix.lower() not in ('.exe','.out','.dll','.pyc','.pyd','.so','.zip')),key=lambda p:p.as_posix())


def main():
    files=selected_files()
    entries=[{'path':p.relative_to(ROOT).as_posix(),'bytes':p.stat().st_size,'sha256':hashlib.sha256(p.read_bytes()).hexdigest()} for p in files]
    manifest={'description':'CS5291 Project 3 portable source, report and recorded evidence. Large upstream binaries/repositories/PDF papers excluded.',
              'files':entries}
    manifest_path=ROOT/'output/SUBMISSION_MANIFEST.json'
    manifest_path.write_text(json.dumps(manifest,indent=2)+'\n')
    with zipfile.ZipFile(DEST,'w',compression=zipfile.ZIP_DEFLATED,compresslevel=7) as archive:
        for p in files:
            archive.write(p,'Project3/'+p.relative_to(ROOT).as_posix())
        archive.write(manifest_path,'Project3/SUBMISSION_MANIFEST.json')
    with zipfile.ZipFile(DEST) as archive:
        assert archive.testzip() is None
        for row in entries:
            assert hashlib.sha256(archive.read('Project3/'+row['path'])).hexdigest()==row['sha256']
    digest=hashlib.sha256(DEST.read_bytes()).hexdigest()
    (ROOT/'output/Project3_Submission.sha256').write_text(digest+'  Project3_Submission.zip\n')
    print('Packaged',len(entries),'files;',round(DEST.stat().st_size/2**20,2),'MiB; every entry verified.')


if __name__=='__main__':
    main()
