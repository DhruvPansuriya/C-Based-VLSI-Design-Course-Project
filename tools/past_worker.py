"""Linux-only isolated runner for the authors' prebuilt PAST implementation.

Run in WSL: python3 tools/past_worker.py results/past/request.json
Each library invocation runs in its own process: parser errors can call exit().
"""

import json
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def one(request_path, index):
    sys.path.insert(0, str(ROOT / "tools/past-linux"))
    import past
    case = json.loads(request_path.read_text())["cases"][index]
    result = past.verify(str(ROOT / case["original"]), str(ROOT / case["candidate"]),
                         case["liveouts"], is_verbose=0,
                         is_cdag_all_normalizations=case.get("all_normalizations", 0))
    print("\nHLSCHECK_PAST_CODE=" + str(result), flush=True)


def main():
    if sys.argv[1] == "--one":
        one(Path(sys.argv[2]), int(sys.argv[3]))
        return
    request_path = Path(sys.argv[1]).resolve()
    request = json.loads(request_path.read_text())
    outputs = []
    for index, case in enumerate(request["cases"]):
        start = time.perf_counter()
        try:
            process = subprocess.run([sys.executable, str(Path(__file__).resolve()), "--one", str(request_path), str(index)],
                                     capture_output=True, timeout=30)
            text = (process.stdout + process.stderr).decode("utf-8", errors="replace")
            marker = "HLSCHECK_PAST_CODE="
            code = int(text.split(marker)[-1].splitlines()[0]) if marker in text else None
            status = "equivalent_reported" if process.returncode == 0 and code == 1 else "not_proved" if process.returncode == 0 and code == 0 else "error"
        except subprocess.TimeoutExpired:
            text, code, status = "PAST worker timeout", None, "unknown"
        (request_path.parent / (case["name"] + ".log")).write_text(text, encoding="utf-8")
        row = {**case, "past_status": status, "past_code": code,
               "elapsed_seconds": round(time.perf_counter() - start, 6)}
        outputs.append(row)
        print(case["name"], status, flush=True)
    (request_path.parent / "summary.json").write_text(json.dumps({"cases": outputs}, indent=2) + "\n")


if __name__ == "__main__":
    main()
