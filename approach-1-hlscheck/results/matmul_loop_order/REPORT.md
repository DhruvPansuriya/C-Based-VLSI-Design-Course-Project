# Matrix multiplication: i-j-k versus k-i-j

The candidate moves k to the outermost loop. No other source optimization or pragma is added.

- Source: [i-j-k](../../benchmarks/matmul_loop_order/matmul_ijk.cpp), [k-i-j](../../benchmarks/matmul_loop_order/matmul_kij.cpp).
- Integrated equivalence proof: **equivalent**; all 32-bit unsigned inputs, with valid nonoverlapping arrays.
- Native C++17: 264 directed/random comparisons passed.
- Fresh Bambu runs: 16 passing RTL transactions per implementation.
- Target: Nangate45 typical, 10 ns clock; pre-layout mapped ASIC estimates.

| Metric | Original i-j-k | Candidate k-i-j | Change |
| --- | ---: | ---: | ---: |
| Cell area (um^2) | 4612.97 | 5004.26 | +8.48% |
| Latency (cycles) | 266 | 314 | +18.05% |
| Latency at 10 ns clock (ns) | 2660 | 3140 | +18.05% |
| Mapped critical-path delay (ns) | 1.86574 | 1.83468 | -1.66% |
| Area x latency (um^2 ns) | 1.22705e+07 | 1.57134e+07 | +28.06% |

Under this configuration, moving k outermost **regresses** area x latency (+28.06%).

A functional proof establishes equal results, not better hardware. Loop order changes memory traffic, reuse opportunities, scheduling and accumulation dependencies; the HLS compiler determines the resulting hardware.

The .cpp sources use the C-compatible subset. Our checker models C semantics; Bambu compiles byte-identical C11 copies. The native test separately compiles as C++17. This does not establish support for general C++.

Critical-path delay is distinct from total execution latency. These results are a new isolated demonstration and do not modify the main 50-pair experiment counts.

Reproduce: `python scripts/run_matmul_demo.py` from the project root. Formal obligations are under `proof/`; all synthesis, simulation, mapping and timing logs are under `hls/`.
