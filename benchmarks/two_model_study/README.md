# Frozen originals for the two-model dataset study

Twelve originals: six small dataset-derived integer compute kernels and six type-preserving scalar leaves. Model outputs are generated and saved separately; no prewritten candidate is provided here.

The six adapted kernels are explicitly NEW INTEGER PROBLEMS: reduced dimensions, flattened arrays and unsigned32 modular arithmetic. A proof against a generated candidate does not validate the original upstream floating-point/signed application. Each provenance.json records the upstream path/hash and preparation. MVT retains incoming x values; ATAX exposes tmp; SYRK and stencil retain unwritten array elements.

The six leaf functions preserve original integer types/domains and required macros, with only the top function renamed to kernel. Their upstream function excerpts and whole source snapshots are retained. HLS-Eval binary64 helpers manipulate unsigned64 bit patterns, not arbitrary floating-point values.

MachSuite's complete license is retained in LICENSE.MachSuite. CHStone GSM notices remain in the extracted source; the referenced upstream COPYRIGHT file is absent from the downloaded snapshot, so no replacement license is invented. HLS-Eval sources are credited to their repository and originating benchmarks; no blanket license is asserted for files without a supplied notice. Preserve per-source attribution on redistribution.

The machine-readable inventory is experiments/two_model_study/manifest.json. All prepared C source files use LF bytes. Both models must receive the same source and contract, and every final parameter-array element is observable. Self-equivalence preflight only establishes current checker eligibility and safety under its model, not hardware synthesizability or broad checker soundness.
