"""A controlled example of a rare mutation missed by finite random testing."""

import sys
from pathlib import Path

# Support both python scripts/<name>.py and python -m scripts.<name>.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

import json
import shutil
import subprocess
from hlscheck import check_equivalence
from scripts.validate_native import renamed


def main():
    root = Path(__file__).resolve().parents[1]
    folder = root / "benchmarks/semantic_traps"
    original, candidate = [(folder / f"rare_{v}.c").read_text() for v in ("original","buggy")]
    out = root / "results/rare_bug"
    out.mkdir(parents=True,exist_ok=True)
    result = check_equivalence(original,candidate,"kernel",smt_path=out/"mismatch.smt2")
    assert result["status"] == "not_equivalent"
    witness = result["counterexample"]["x"]
    harness = "\n".join(["#include <stdint.h>","#include <stdio.h>",renamed(original,"original"),renamed(candidate,"candidate"),
        "int main(void){uint32_t s=0x5291abcdu;unsigned found=0;",
        "for(unsigned t=0;t<10000;++t){s^=s<<13;s^=s>>17;s^=s<<5;found+=(original(s)!=candidate(s));}",
        f"unsigned replay=(original({witness}u)!=candidate({witness}u));",
        'printf("%u %u\\n",found,replay);return !replay;}',""])
    source = out/"replay.c"
    source.write_text(harness)
    executable = out/("replay.exe" if __import__('os').name=='nt' else 'replay.out')
    compiler = shutil.which("clang") or shutil.which("gcc")
    subprocess.run([compiler,'-std=c11','-O2',str(source),'-o',str(executable)],check=True,capture_output=True,timeout=60)
    run = subprocess.run([str(executable)],check=True,capture_output=True,text=True,timeout=30)
    found,replay = map(int,run.stdout.split())
    summary = {"mutation":"Deliberately inserted extra increment at x=0xdeadbeef", "random_trials":10000,
               "seed":"0x5291abcd", "random_mismatches":found,"formal":result,"compiled_witness_replayed":bool(replay),
               "interpretation":"One artificial controlled example; not a statistical estimate of testing effectiveness or LLM bug rate"}
    (out/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    print(f"Random tests: {found}/10000 found the mutation; SMT: x={witness:#x}; compiled replay: {bool(replay)}")


if __name__ == '__main__':
    main()
