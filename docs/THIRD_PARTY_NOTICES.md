# Attribution and third-party resources

The checker under `hlscheck/` is a course-project implementation of standard
symbolic interpretation and SMT equivalence techniques. ESBMC, PAST, Bambu,
Yosys and OpenSTA are existing implementations; their code is not relabeled
as our own. `hlscheck/esbmc_backend.py` generates the verification harness;
it does not implement ESBMC.

- MachSuite-derived C is under `benchmarks/machsuite_u32`. The upstream
  BSD-style `LICENSE`, copyright and adaptation README are preserved there.
  Only the changed dimensions/types are proved within our pairs.
- The expanded `gemm_local4` reference reuses that same reduced MachSuite GEMM
  adaptation. `benchmarks/expanded/LICENSE.MachSuite` preserves the license.
  Other expanded educational implementations are assistant-authored examples,
  not copied or renamed standard-suite benchmark checkouts.
  The later gemm_tile2 follow-up also retains the same MachSuite notice at
  `benchmarks/feedback/LICENSE.MachSuite`.
- EqBench is MIT-licensed. Its pinned checkout retains `datasets/EqBench/LICENSE.md`.
  A copy accompanies the public-data evidence in `results/eqbench/LICENSE`.
  Generated verifier harnesses in that evidence can contain upstream C.
- Nangate45's Liberty header and the upstream platform `LICENSE` are retained
  in `tools/nangate45`. The library is used for research synthesis estimates;
  no foundry sign-off or commercial process implementation is claimed.
- Generated Bambu RTL retains the original source notices and the bundled
  PandA IP notices. `panda_libtech.v` identifies MIT-licensed IP components;
  source-derived RTL includes the tool's own provenance comments.
- ESBMC 8.7 Windows binaries and bundled dependencies retain their upstream
  license directory under `tools/esbmc-v8.7/release`. PAST's downloaded wheel
  retains its `.dist-info` license notices, including LGPLv3 notices.
- Bambu, Yosys and OpenSTA binary archives are from the official Bambu release
  host. Their upstream notices remain in the installed distributions. These
  large binaries are excluded from the portable source submission; the
  bootstrap gives download URLs and verifies the experiment's recorded hashes.
- Z3 is MIT-licensed; pycparser is BSD-licensed; pytest is MIT-licensed. Python
  packages keep their installed notices. ReportLab, matplotlib and PyMuPDF are
  optional report-generation dependencies; their binaries are not included in
  the source package. Use their upstream licenses when installing them.
- Downloaded research PDFs are reading materials, not project-authored
  publications. They remain in the workspace with their original notices and
  are excluded from the portable source ZIP. The report cites primary links.

The portable ZIP includes project sources, documented benchmark adaptations,
recorded evidence, reports/slides, the licensed Nangate45 input library and
resource instructions. It excludes virtual environments, Git metadata,
downloaded upstream repositories, downloaded research PDFs, large tool
archives, executables and temporary build/render files.

The supplementary local inference experiment uses the official Qwen2.5-Coder-
1.5B-Instruct GGUF (Apache-2.0). Its model license, model card and exact revision
are preserved in `experiments/local_model/`. llama.cpp's official Vulkan runtime
is recorded by release URL and SHA-256; runtime binaries are not redistributed
in the submission. Raw model output comments may repeat input authorship text;
the generation ledger, rather than those comments, identifies the actual origin.

Type-preserving dataset extracts live in `experiments/dataset_leaves/`.
MachSuite's complete license accompanies them. CHStone GSM source copyright
comments are retained; their referenced `COPYRIGHT` file is absent from this
downloaded snapshot, so no replacement license is asserted. HLS-Eval functions
retain their source paths, header hashes and exact extracted function text;
credit Stefan Abi-Karam and Cong Hao, ICLAD 2025, DOI
10.1109/ICLAD65226.2025.00021. These extracts are not claimed as independently
authored baseline functions. Candidate rewrites and deliberate bugs are labelled
separately in their manifest.
