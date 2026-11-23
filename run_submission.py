"""Reproduce core verification and summaries; optional real synthesis rerun."""
import argparse
from pathlib import Path
import subprocess
import sys
import json
import time


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--synthesize',action='store_true',help='Run real Bambu/Verilator/Yosys/STA experiments in WSL, reusing exact-source cached results')
    parser.add_argument('--force-hls',action='store_true',help='Regenerate all hardware even if cached')
    parser.add_argument('--tests',action='store_true',help='Also run the full pytest suite')
    parser.add_argument('--jobs',type=int,default=2,help='Parallel hardware designs')
    args=parser.parse_args()
    root=Path(__file__).resolve().parent
    commands=[[sys.executable,'scripts/verify_submission.py'],[sys.executable,'scripts/replay_smt_evidence.py'],[sys.executable,'scripts/validate_native.py'],[sys.executable,'scripts/run_rare_bug_demo.py']]
    if args.synthesize:
        commands.append(['wsl','-d','Ubuntu','--','python3','-u','tools/run_hls_linux.py','--jobs',str(args.jobs)]+(['--force'] if args.force_hls else []))
    commands.append([sys.executable,'scripts/analyze_results.py'])
    if args.tests:
        commands.append([sys.executable,'-m','pytest','-q','--junitxml=results/submission/pytest.xml'])
    evidence=root/'results/submission/reproduction'
    evidence.mkdir(exist_ok=True,parents=True)
    journal=[]
    for index,command in enumerate(commands):
        print('\nRUN',subprocess.list2cmdline(command),flush=True)
        start=time.perf_counter()
        log=evidence/f'{index+1:02d}_{Path(command[1]).stem}.log'
        with log.open('w',encoding='utf-8') as stream:
            process=subprocess.Popen(command,cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,encoding='utf-8',errors='replace')
            for line in process.stdout:
                print(line,end='',flush=True)
                stream.write(line)
                stream.flush()
            code=process.wait()
        journal.append({'command':command,'exit_code':code,'elapsed_seconds':round(time.perf_counter()-start,3),'log':str(log.relative_to(root))})
        (evidence/'summary.json').write_text(json.dumps({'passed':all(r['exit_code']==0 for r in journal),'steps':journal},indent=2)+'\n')
        if code:
            raise SystemExit(code)
    print('\nCore submission checks passed. Hardware summaries use recorded results unless --synthesize is supplied.')


if __name__=='__main__':
    main()
