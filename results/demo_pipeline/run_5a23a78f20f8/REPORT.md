# File-to-file HLSCheck pipeline

Original: `C:\Users\ARYAN\Desktop\7th Semester\C-Based VLSI Design\Course_Project\matmul.cpp`
Candidate: `C:\Users\ARYAN\Desktop\7th Semester\C-Based VLSI Design\Course_Project\matmul_opti.cpp`

Equivalence: **equivalent**.
Native comparisons: 264 passed. RTL transactions: 32 passed.

| Metric | Original | Optimized | Improvement |
| --- | ---: | ---: | ---: |
| Cell area (um^2) | 4612.97 | 5004.26 | -8.48% |
| Execution latency (cycles) | 266 | 314 | -18.05% |
| Execution latency at 10 ns (ns) | 2660 | 3140 | -18.05% |
| Critical-path delay (ns) | 1.86574 | 1.83468 | +1.66% |
| Area x execution latency | 1.22705e+07 | 1.57134e+07 | -28.06% |

Improvement (%) = 100 x (original - optimized) / original; positive is better.

Area x execution latency outcome: **regressed**.

Mapped pre-layout Nangate45 ASIC estimates; no routed timing, FPGA or formal C-to-RTL claim

The .cpp extension uses C-compatible C11 semantics. HLS sources preserve the supplied code/pragmas; only a non-kernel top declarator is renamed and certified when needed.

See console.log, proof/, evidence_replay.json, native/, hls_inputs/, and hls/ for the complete evidence.
