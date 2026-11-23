"""Run the pinned model on the local NVIDIA Vulkan device, loopback only."""
import json
import os
from pathlib import Path
import subprocess
import time
import urllib.request

ROOT=Path(__file__).resolve().parents[1]


def main():
    output=ROOT/'results/local_llm';output.mkdir(exist_ok=True,parents=True)
    binary=ROOT/'tools/local_llm/runtime/llama-server.exe'
    model=ROOT/'tools/local_llm/qwen2.5-coder-1.5b-instruct-q4_k_m.gguf'
    command=[str(binary),'-m',str(model),'--device','Vulkan1','--n-gpu-layers','all',
             '--ctx-size','4096','--parallel','1','--threads','8','--host','127.0.0.1','--port','8089']
    with (output/'server.log').open('w',encoding='utf-8') as log:
        process=subprocess.Popen(command,cwd=binary.parent,stdout=log,stderr=subprocess.STDOUT,
            creationflags=subprocess.CREATE_NO_WINDOW if os.name=='nt' else 0)
        (output/'server_process.json').write_text(json.dumps({'pid':process.pid,'command':command,'endpoint':'http://127.0.0.1:8089'},indent=2)+'\n')
        try:
            start=time.time()
            while time.time()-start<180:
                if process.poll() is not None:raise RuntimeError('Server exited: see server.log')
                try:
                    with urllib.request.urlopen('http://127.0.0.1:8089/health',timeout=2) as response:
                        if response.status==200:break
                except Exception:time.sleep(.5)
            else:raise RuntimeError('Server startup timeout')
            print('Local coder ready at 127.0.0.1:8089; PID',process.pid,flush=True)
            process.wait()
        finally:
            if process.poll() is None:
                process.terminate()
                process.wait(timeout=30)


if __name__=='__main__':
    main()
