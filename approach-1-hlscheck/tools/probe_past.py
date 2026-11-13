"""Inspect the authors' Linux PAST wheel without changing system Python."""

import sys
import re
from pathlib import Path

root = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(root / "tools" / "past-linux"))
import past

print("Module:", past.__file__)
print("Exports:", dir(past))
print("verify documentation:", getattr(past.verify, "__doc__", None))

if len(sys.argv) > 1:
    original = root / "benchmarks/demo/scale_original.c"
    candidate = root / "benchmarks/demo/scale_optimized.c"
    target = root / "results/past_calibration"
    target.mkdir(parents=True, exist_ok=True)
    for source, filename in ((original, "original.c"), (candidate, "candidate.c")):
        text = re.sub(r"^\s*#include[^\n]*", "", source.read_text(), flags=re.M)
        body = text[text.index("{") + 1:text.rindex("}")]
        # The published tests use global arrays and an annotated region, not
        # an ordinary function declaration.
        text = ('unsigned int a[8];\nunsigned int out[8];\n'
                '#pragma pocc-region-start\n{\n' + body + '\n}\n#pragma pocc-region-end\n')
        (target / filename).write_text(text)
    right = target / ("original.c" if sys.argv[1] == "self" else "candidate.c")
    verdict = past.verify(str(target / "original.c"), str(right), "out", is_verbose=1)
    print("PAST_RETURN_CODE:", verdict, flush=True)
    if sys.argv[1] == "self" and verdict != 1:
        raise SystemExit("Calibration failed: identical code was not accepted")
