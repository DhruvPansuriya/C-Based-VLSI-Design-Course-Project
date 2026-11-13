# Small fixed-size unsigned adaptations of MachSuite kernels

Upstream: `datasets/MachSuite`, commit
`6236e593012cb86b0d2f08d9fb9ba0411ff989b4`.
Retained license: `LICENSE` in this directory.

These are derived variants, not untouched upstream programs:

- GEMM: derived from `gemm/ncubed/gemm.c`. Changed 64x64 double matrices to 4x4
  uint32_t matrices, expanded dimensions explicitly and removed host harness
  code. The optimized version interchanges the inner loops and accumulates
  directly into the output array. The negative control uses a transposed
  second-matrix index.
- Stencil: derived from `stencil/stencil2d/stencil.c`. Changed a 128x64 signed
  int32_t input to a 5x5 uint32_t input, preserved the 3x3 filter and a 5x5 output
  with untouched boundary elements. The optimized version explicitly expands
  the three filter-column operations. The negative control uses the wrong
  filter coefficient in the center column.

All arithmetic is modulo 2^32. A proof between these original/optimized pairs
does not establish equivalence between double/signed upstream versions and our
unsigned adaptations. Dimensions and types are identical within each pair.

Optimized source was authored by the current Codex session; buggy variants
are deliberately seeded controls. They must be reported separately from
spontaneous errors in later LLM-generation experiments. No QoR improvement is
claimed before hardware synthesis.
