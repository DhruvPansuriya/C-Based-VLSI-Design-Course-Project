# Computed reference regions

`compute_regions(P0, shape, out)` uses the admitted original program exclusively.
Its reports bind results to the program and the exact caller profile. The caller
can propose a predicate. For a supported unconditional first read `a[i]`, the
tool can propose `length(a) <= i` automatically. Other cases begin with an empty
proposal and report whether an unsafe input lies outside it.

The report records reachability inside and outside the predicate, safety
outside, a safety witness inside when one exists, and a proof of deterministic
observations outside the predicate when possible. A witnessed failure inside a
predicate does not mean every input in it fails. To claim an exact UB region, the
tool also proves that the entire proposed region is empty or that every input
in it triggers a recognized unconditional first fault. The prototype recognizes
only a direct buffer read with a literal subscript in the first local initializer.
Other faults can supply evidence and leave the exact region unresolved.

For argmax, an exact-size buffer with length zero cannot supply the first read
`a[0]`, regardless of its pointer representation. The tool proves safety and
determinism for nonempty inputs, then establishes exactness for `n == 0`. For
`n <= 1`, it refutes exactness with `n == 1` while still supplying the narrower
safe guard `n > 1`. E0 can refute a candidate on a certified sufficient safe
guard. To use a successful guard check in a universal verdict the orchestrator
must separately show coverage of the relevant obligation domain.

Reading an uninitialized local is treated as a safety issue. A different result
between two CBMC executions of such a path does not establish defined C
nondeterminism. The tool currently certifies an empty defined-nondeterminism
region when the exact UB region and deterministic exterior are both established.
General exact nonempty regions and a broader uninitialized-read qualification
remain open. All results are relative to the instrumented C subset and bounds.
