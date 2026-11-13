# Running this handoff on another computer

Extract the ZIP completely. Run commands from `Project3_Team_Handoff/`.
Recorded Markdown/JSON/CSV results, C files, logs, PDFs and slides can be read
without installing any tool. All required project source code is included.

## Python and a first lightweight check

Use Python 3.12 and create a fresh environment; this ZIP does not copy `.venv`:

```powershell
py -3.12 -m venv .venv
.\.venv\Scripts\python.exe -m pip install -r requirements.txt
.\.venv\Scripts\python.exe -m hlscheck benchmarks/demo/scale_original.c benchmarks/demo/scale_optimized.c --backend symbolic --function kernel
```

That explicit standalone symbolic example uses the Python dependencies. The
default combined checker additionally needs Clang and ESBMC. The supplied
requirements pin Z3, pycparser and pytest. Optional figure/report regeneration
uses `requirements-report.txt`.

## Combined formal checking and compiled-C validation

The tested formal/native setup is Windows with Clang targeting ILP32 and
ESBMC 8.7. Install Clang with a compatible 32-bit C linker/runtime and put it
on PATH. The native harness asserts `short16/int32/long32/long-long64` and
32-bit pointers; a mismatched ABI fails rather than silently changing the
model. A generic 64-bit Linux native compiler is not a drop-in replacement.

Obtain ESBMC 8.7 from the release linked in
[the resource manifest](docs/RESOURCE_MANIFEST.md). Preserve its bundled
runtime libraries and license notices. Set its executable path, for example:

```powershell
$env:ESBMC_PATH = 'C:\path\to\esbmc\bin\esbmc.exe'
clang --version
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel --verify-only
```

Alternatively the adapter finds `esbmc` on PATH or the original bundled
location `tools/esbmc-v8.7/release/bin/esbmc.exe`. A missing dependency produces
an error or unproved outcome; it must not be described as a successful proof.

## Full hardware pipeline

The tested configuration uses WSL Ubuntu for Bambu/Verilator/Yosys/OpenSTA.
Install WSL Ubuntu and the Linux packages `libtcl8.6`, `verilator`, `gcc`,
`g++`, and `make`. Then, from PowerShell in this project root:

```powershell
wsl -d Ubuntu -- python3 tools/bootstrap_hls_linux.py --download
.\.venv\Scripts\python.exe run_demo.py matmul.cpp matmul_opti.cpp --function kernel
```

The bootstrap prints the pinned downloads and checks their recorded hashes:
Bambu 508.89 MiB and backend bundle 74.14 MiB. It installs under the Linux
home directory. The Nangate45 library and its license are included. No Vitis
license is required. See [REPRODUCE.md](docs/REPRODUCE.md) and
[FILE_PIPELINE.md](docs/FILE_PIPELINE.md) for the detailed configuration.

Large binary toolchains, model weights, virtual environments and whole upstream
repositories are excluded. Prepared benchmark extracts, notices/provenance,
raw model responses, generated candidates and recorded evidence are included.
New model generation is optional; `tools/setup_local_coder.py` and
`tools/serve_local_coder.py` support the original Qwen experiment. GPT candidates
are retained responses from actual Codex tasks; no cloud credentials are bundled.

Historical logs retain the original machine paths and percentage conventions.
They are evidence records, not portable commands to copy literally. `RESULTS.md`
recomputes all improvement percentages from recorded measurements; positive
means better. Its cohort counts must not be added into one independent sample.
The older PDF/slides predate the latest model study; use `RESULTS.md` for the
current combined overview.
