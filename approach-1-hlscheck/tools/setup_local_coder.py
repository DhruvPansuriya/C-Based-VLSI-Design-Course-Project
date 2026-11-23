"""Download a pinned official small model and portable inference runtime."""
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import shutil
import time
import urllib.request
import zipfile

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'tools/local_llm'
REPO='Qwen/Qwen2.5-Coder-1.5B-Instruct-GGUF'
MODEL='qwen2.5-coder-1.5b-instruct-q4_k_m.gguf'
MODEL_SIZE=1117320768
MODEL_HASH='cc324af070c2ecbfd324a30884d2f951a7ff756aba85cb811a6ec436933bb046'
RUNTIME='llama-b12619-bin-win-vulkan-x64.zip'
RUNTIME_URL='https://github.com/ggml-org/llama.cpp/releases/download/b12619/'+RUNTIME
RUNTIME_HASH='175d9013769997ab9145cc932f0dd2d89ab3cb6123aecbd83a9645e1cf5e5b9d'


def fetch(url,path,size):
    if path.exists() and path.stat().st_size==size:return
    print('Downloading',path.name,f'{size/2**20:.2f} MiB',flush=True)
    request=urllib.request.Request(url,headers={'User-Agent':'CS5291-course-project'})
    with urllib.request.urlopen(request,timeout=90) as response,path.open('wb') as stream:
        shutil.copyfileobj(response,stream,length=1024*1024)
    if path.stat().st_size!=size:raise RuntimeError('Incomplete download: '+str(path))


def verify(path,digest):
    actual=hashlib.file_digest(path.open('rb'),'sha256').hexdigest()
    if actual!=digest:raise RuntimeError('Checksum mismatch: '+str(path))


def main():
    OUT.mkdir(exist_ok=True)
    info=json.load(urllib.request.urlopen('https://huggingface.co/api/models/'+REPO))
    revision=info['sha']
    model_url=f'https://huggingface.co/{REPO}/resolve/{revision}/{MODEL}?download=true'
    jobs=[(RUNTIME_URL,OUT/RUNTIME,38863716,RUNTIME_HASH),(model_url,OUT/MODEL,MODEL_SIZE,MODEL_HASH)]
    def task(job):
        url,path,size,digest=job
        fetch(url,path,size);verify(path,digest)
        print('Verified',path.name,flush=True)
    with ThreadPoolExecutor(max_workers=2) as pool:list(pool.map(task,jobs))
    with zipfile.ZipFile(OUT/RUNTIME) as archive:
        archive.extractall(OUT/'runtime')
    for name in ('LICENSE','README.md'):
        url=f'https://huggingface.co/{REPO}/resolve/{revision}/{name}'
        try:(OUT/('MODEL_'+name)).write_bytes(urllib.request.urlopen(url,timeout=30).read())
        except Exception as error:print('Optional notice download:',name,type(error).__name__,flush=True)
    metadata={'model_repository':REPO,'model_revision':revision,'model_file':MODEL,'model_bytes':MODEL_SIZE,
        'model_sha256':MODEL_HASH,'model_quantization':'Q4_K_M','runtime_release':'b12619',
        'runtime_url':RUNTIME_URL,'runtime_sha256':RUNTIME_HASH,
        'billing':'Local inference only. No external paid inference API calls.'}
    (OUT/'PROVENANCE.json').write_text(json.dumps(metadata,indent=2)+'\n')
    print('Local runtime/model ready.',flush=True)


if __name__=='__main__':
    main()
