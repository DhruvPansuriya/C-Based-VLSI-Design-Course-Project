"""Small Linux-side installation probe; retained for setup reproducibility."""
import os
from pathlib import Path
import subprocess

root = Path(__file__).resolve().parents[1]
tools = Path.home() / "cs5291_hls_tools"
usr = tools / "squashfs-root/usr"
env = dict(os.environ)
env["BAMBU_HLS"] = str(usr)
env["BAMBU_HLS_BACKEND_PATH"] = ":".join([str(tools / "opt/yosys/bin"), str(tools / "opt/openroad/bin"), env["PATH"]])
env["PATH"] = ":".join([str(usr / "bin"), str(usr / "compilers/clang-16/bin"), str(usr / "compilers/clang-13/bin"), env["BAMBU_HLS_BACKEND_PATH"]])
work = Path.home() / "cs5291_hls_probe"
work.mkdir(exist_ok=True)
(work / "kernel.c").write_text((root / "benchmarks/submission/factor_original.c").read_text())
(work / "tb.c").write_text((root / "results/native/factor_hls_tb.c").read_text())
command = [str(usr / "bin/bambu"), str(work / "kernel.c"), "--top-fname=kernel", "--device-name=nangate45", "--clock-period=10", "--compiler=I386_CLANG16", "--generate-tb=" + str(work / "tb.c"), "--simulate", "--simulator=VERILATOR"]
print(command, flush=True)
with (root / "tools/bambu-probe.log").open("w") as log:
    result = subprocess.run(command, cwd=work, env=env, stdout=log, stderr=subprocess.STDOUT)
print("exit", result.returncode, flush=True)
print((root / "tools/bambu-probe.log").read_text()[-5000:])
