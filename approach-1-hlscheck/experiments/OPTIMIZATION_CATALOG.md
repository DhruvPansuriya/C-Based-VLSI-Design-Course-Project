# Recorded C optimizations and formal / HLS evidence

Study unit: **50 original/candidate pairs**, or **100 synthesized implementations** when complete. Related kernels and repeated original algorithms are identified; this is not a claim of independent application samples.

Each pair preserves its signature, uint32_t modular semantics and final contents of every parameter array under valid, nonaliasing array assumptions. Candidates were authored by the Codex assistant in this conversation. No external API model/response/temperature metadata is invented.

| Pair / source record | Transformation | C-to-C proof | Hardware status | ADP ratio |
|---|---|---|---|---:|
| [scale](optimizations/scale.md) | strength reduction and two-way unrolling | equivalent | complete | 2.952 |
| [unswitch](optimizations/unswitch.md) | loop unswitching | equivalent | complete | 1.655 |
| [gemm](optimizations/gemm.md) | loop interchange and scalar reuse | equivalent | complete | 2.303 |
| [stencil](optimizations/stencil.md) | filter-column source unrolling | equivalent | complete | 1.086 |
| [prefix](optimizations/prefix.md) | incremental prefix accumulation | equivalent | complete | 0.2062 |
| [fir](optimizations/fir.md) | symmetric pre-addition | equivalent | complete | 0.9162 |
| [boxfilter](optimizations/boxfilter.md) | separable sliding-window reuse | equivalent | complete | 4.709 |
| [factor](optimizations/factor.md) | distributive factoring | equivalent | complete | 1 |
| [dot16](optimizations/dot16.md) | Four independent dot-product accumulators | equivalent | complete | 2.194 |
| [sum32](optimizations/sum32.md) | Four-way partial-sum reduction | equivalent | complete | 3.783 |
| [xor32](optimizations/xor32.md) | Four-way XOR reduction | equivalent | complete | 3.077 |
| [min8](optimizations/min8.md) | Balanced comparison tree | equivalent | complete | 2.346 |
| [max8](optimizations/max8.md) | Balanced comparison tree | equivalent | complete | 2.464 |
| [range8](optimizations/range8.md) | Fuse minimum and maximum scans | equivalent | complete | 0.7358 |
| [count_nonzero16](optimizations/count_nonzero16.md) | Parallel predicate counters | equivalent | complete | 4.75 |
| [all_equal16](optimizations/all_equal16.md) | XOR/OR equality reduction | equivalent | complete | 1.421 |
| [parity32](optimizations/parity32.md) | XOR-fold parity | equivalent | complete | 0.01128 |
| [popcount8](optimizations/popcount8.md) | Byte-wide SWAR population count | equivalent | complete | 0.008885 |
| [bitreverse32](optimizations/bitreverse32.md) | Staged mask-and-swap bit reversal | equivalent | complete | 3.035e-05 |
| [byteswap32](optimizations/byteswap32.md) | Two-stage byte permutation | equivalent | complete | 0.0002871 |
| [crc8_byte](optimizations/crc8_byte.md) | Two-step CRC recurrence unrolling | equivalent | complete | 0.6027 |
| [hamming8](optimizations/hamming8.md) | Replace nested bit scans with byte SWAR | equivalent | complete | 0.1104 |
| [clamp16](optimizations/clamp16.md) | Upper-bit saturation test | equivalent | complete | 1 |
| [threshold_pack8](optimizations/threshold_pack8.md) | Split threshold packing into two independent lanes | equivalent | complete | 0.8287 |
| [absdiff16](optimizations/absdiff16.md) | Share comparison before subtraction | equivalent | complete | 0.9973 |
| [squared_distance8](optimizations/squared_distance8.md) | Expand squared distance into three reductions | equivalent | complete | 2.73 |
| [saxpy16](optimizations/saxpy16.md) | Two-lane SAXPY source unrolling | equivalent | complete | 1.354 |
| [quadratic](optimizations/quadratic.md) | Horner-form quadratic evaluation | equivalent | complete | 1 |
| [convolution1d8](optimizations/convolution1d8.md) | Exploit three-tap coefficient symmetry | equivalent | complete | 0.9198 |
| [moving_sum16](optimizations/moving_sum16.md) | Sliding four-element window sum | equivalent | complete | 1.505 |
| [triangular_fir16](optimizations/triangular_fir16.md) | Reuse adjacent pair sums | equivalent | complete | 0.5986 |
| [gaussian5](optimizations/gaussian5.md) | Separable integer Gaussian filter | equivalent | complete | 3.197 |
| [integral_image4](optimizations/integral_image4.md) | Dynamic-programming summed-area table | equivalent | complete | 0.3834 |
| [transpose4](optimizations/transpose4.md) | Two-element transpose staging | equivalent | complete | 1.013 |
| [matvec4](optimizations/matvec4.md) | Expand matrix-vector inner product with balanced sums | equivalent | complete | 2.274 |
| [gemm_local4](optimizations/gemm_local4.md) | Keep four row accumulators local during GEMM interchange | equivalent | complete | 1.349 |
| [syrk4](optimizations/syrk4.md) | Compute one triangle of a Gram matrix | equivalent | complete | 0.7304 |
| [rank1_update4](optimizations/rank1_update4.md) | Hoist the row scalar and expand a rank-one update | equivalent | complete | 1.186 |
| [triangular_matvec4](optimizations/triangular_matvec4.md) | Tighten triangular loop bounds | equivalent | complete | 0.4175 |
| [symv4](optimizations/symv4.md) | Reuse stored triangular matrix elements | equivalent | complete | 4.86 |
| [matrix_trace4](optimizations/matrix_trace4.md) | Traverse only diagonal indices | equivalent | complete | 0.08958 |
| [matrix_diagsum4](optimizations/matrix_diagsum4.md) | Direct traversal of two disjoint diagonals | equivalent | complete | 0.1125 |
| [histogram4](optimizations/histogram4.md) | Fuse four fixed-bin histogram scans | equivalent | complete | 0.7365 |
| [search_count16](optimizations/search_count16.md) | Two independent equality-count lanes | equivalent | complete | 1.685 |
| [reverse_copy16](optimizations/reverse_copy16.md) | Paired reverse-copy staging | equivalent | complete | 1.224 |
| [deinterleave16](optimizations/deinterleave16.md) | Fuse even/odd extraction loops | equivalent | complete | 0.8314 |
| [interleave8](optimizations/interleave8.md) | Fuse interleaving output loops | equivalent | complete | 1.11 |
| [maxpool4](optimizations/maxpool4.md) | Balanced two-by-two max pooling | equivalent | complete | 0.8415 |
| [moving_sum_register16](optimizations/moving_sum_register16.md) | Keep the four-element moving window in scalar registers | equivalent | complete | 1.853 |
| [gemm_tile2](optimizations/gemm_tile2.md) | Tile GEMM columns by two with local accumulators | equivalent | complete | 0.9866 |

Hardware-complete pairs at this snapshot: **50/50**.

The retained initial hamming8 monolithic timeout and the later component proof are under `experiments/attempts/` and the proof records. `replay_smt_evidence.py` replays every accepted lemma and final query.
