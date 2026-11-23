# Part 1 — Technical review of the research draft

**Reviewed document:** `docs/research/Verdicts_with_Evidence_Final_Draft.pdf`, the research draft "Verdicts with Evidence".

**Point of view:** an implementer. The question is not "is the idea good?" but "can each stage be built with the named tools, and does each tool actually behave the way the draft assumes?"

**How claims were checked.** Every tool claim the design depends on was checked in three ways:

1. against the tool's own `--help` output;
2. against official documentation;
3. where possible, **by running the tool**.

The tools used were:

- CBMC **6.11.0** (release package `ubuntu-24.04-cbmc-6.11.0-Linux.deb` from the diffblue/cbmc GitHub releases);
- ESBMC **8.7.0** (`esbmc-linux.zip` from the esbmc/esbmc v8.7 release);
- Z3 **5.4.1** (PyPI `z3-solver`);
- GCC **13.3.0** with AddressSanitizer and UndefinedBehaviorSanitizer;
- all on Ubuntu 24.04.

The runnable experiments live in `spikes/`. Their raw logs are in `results/tool_behaviour/` and `results/golden/`.

**Status values.** *confirmed (run)* means we executed it and observed the behaviour. *confirmed (docs)* means we found it in official documentation or help text. *needs verification* means not yet checked.

## A. Review table

| # | Issue in the draft | Concrete scenario / evidence | Impact | Fix (adopted in the TDD) | Status |
|---|---|---|---|---|---|
| R1 | The draft could not confirm how `abort()` is modelled. | Spike T03: a candidate that calls `abort()` on overflow inputs gets **VERIFICATION SUCCESSFUL** for a false requirement in both CBMC 6.11.0 and ESBMC 8.7.0. | Vacuous ACCEPT. | After `goto-cc`, run `goto-instrument --generate-function-body '(abort\|exit\|_Exit)' --generate-function-body-options assert-false-assume-false`. In T03 this turns the silent pass into a failure (`undefined function should be unreachable: FAILURE`). | confirmed (run) |
| R2 | The draft did not name the flag that keeps `while(1){}` as a loop. | `cbmc --help` (6.11.0) lists `--no-self-loops-to-assumptions`. In T01, without the flag CBMC prints "no unwinding assertion will be generated for self-loop" and passes. With `--unwinding-assertions --no-self-loops-to-assumptions`, the unwinding assertion fails. | Vacuous ACCEPT. | Both flags are in `vwe.tools.cbmc.BASE_FLAGS`. | confirmed (run) |
| R3 | ESBMC is also vacuous on `while(1)` and `abort()` (T01, T03), and its `--help` shows no equivalent of `--no-self-loops-to-assumptions`. | T01 and T03 both report VERIFICATION SUCCESSFUL in ESBMC 8.7.0. | ESBMC on its own cannot be trusted for ACCEPT. | ESBMC is **confirmation-only**: ACCEPT requires CBMC (with R1/R2 defences) **and** ESBMC to agree, so ESBMC's blind spot cannot create an ACCEPT. Source-level neutralisation (R1) is applied before ESBMC as well. | confirmed (run) |
| R4 | The draft says missing function bodies are modelled silently, with no side effects. That matches older CBMC training material, not CBMC 6.11.0. | T02: CBMC 6.11.0 reports a property `p1.no-body.helper ... no body for callee helper: FAILURE` by default. `goto-instrument --list-undefined-functions` lists `helper`. | Not vacuous in 6.11, but the failure must be classified as an *admission* problem, not as a requirement violation. | Admission (Stage 1) runs `--list-undefined-functions`. Any `*.no-body.*` property is reported as REJECTED (for $P_1$) or UNDECIDED (for $P_0$), never as E0/E1/E2. Whitelisted C-library functions must come with CBMC library bodies. | confirmed (run) |
| R5 | The draft says malloc failure is disabled in CBMC's default model. **This is false for CBMC 6.11.0.** | T04 without `--no-malloc-may-fail`: `pointer NULL in a[...]: FAILURE` appears in both harness and candidate. The cbmc(1) page lists malloc-may-fail among the standard checks. | Spurious E0 rejects on every harness that allocates buffers. | `--no-malloc-may-fail` is always passed. Justification: harness buffers model caller-owned memory that already exists. | confirmed (run) |
| R6 | Exact-size buffers vs fixed-size arrays. | T04: an off-by-one read `a[n]` with a fixed `int a[8]` (n ≤ 7) gives SUCCESS (bug hidden). With `malloc(n*sizeof(int))` it gives `pointer outside object bounds: FAILURE`. | Missed bugs. | The harness generator always uses exact-size malloc. | confirmed (run) |
| R7 | Detecting a nondeterministic $P_0$ by self-composition. | T05: two runs of a $P_0$ with an uninitialised local disagree (`P0 deterministic at x: FAILURE`). The same run also exposes signed overflow in `k + x`. | Without it, preservation is ill-defined. | Implement $B_{nd}$ by self-composition. The overflow it reveals goes into $B_{ub}$ (computed). | confirmed (run) |
| R8 | Build views. | T06: the same requirement passes without `-D__SYNTHESIS__` and fails with it. | Verifying code that is never synthesised. | Two preprocessing runs; the views are compared in an equivalence harness. | confirmed (run) |
| R9 | The draft does not say how witnesses are extracted. | The CBMC JSON trace contains several assignments per input (zero-initialisation, then the nondeterministic value). Array elements appear as indexed assignments. | Wrong witness values in reports. | Take the **last** assignment of each watched input (implemented in `vwe.tools.cbmc._witness`). The generator also copies every nondeterministic input into a named scalar `__vwe_in_<k>`, so array witnesses can be extracted by name. | confirmed (run) for scalars; array naming is a design rule |
| R10 | "Every $\mathit{Ext}$ rejects" is not obviously one CBMC query. | Encoding: `assert(y1 == y0 \|\| Ext_1(x,y1) \|\| … \|\| Ext_m(x,y1))` in the keep region. A failure means every Ext rejects. Example 1 v3 and Example 2 v2 produce the expected E1 rejects. | — | The E1 harness template uses this disjunction. If any $\mathit{Ext}_k$ is `unknown`, E1 is never emitted (verdict rule). | confirmed (run) |
| R11 | The draft's E0 condition ("P0 safe at $x$ under $\sigma_{\min}$") cannot be checked by simply calling $P_0$ before $P_1$, because $P_0$'s own UB checks would fire. | Example 2: $P_0$ reads `a[0]` when $n=0$. | Mis-attributed failures. | Generate a **total instrumented copy** $P_0^\sharp$ that returns a UB flag instead of executing UB. The core harness does `assume(!ub0 \|\| B_max(x))` and then checks $P_1$. In the first prototype this is approximated for Examples 1, 2 and 4 by restricting $P_0$ calls to the keep region (correct there, because $B_{ub} \subseteq B_{\max}$). | design; prototype approximation confirmed (run) |
| R12 | Contract arithmetic can itself overflow. | Example 4 with unbounded element values: `main.overflow` fires in the contract expression. | Interpretations discarded for the wrong reason, or UB inside the oracle. | Compute contract arithmetic in a wider type (`long long`, or `__int128` where supported). Use `value_bounds` only when widening is impossible, and print them in the verdict scope. | confirmed (run) |
| R13 | Shape sanity via the contract (V-G). | Example 4: under the shape "$n-1$ elements", the contract `sum_{i<n} a[i]` raises `main.pointer_dereference` inside the harness. | — | The rule works as designed: a failure located in `main.*` (contract) rather than `p1_*` means V-G discards that interpretation. | confirmed (run) |
| R14 | Solver diversity is weaker than it looks. | PyPI Z3 is 5.4.1; ESBMC 8.7.0 reports "Solving with solver Z3 v4.13.3". | Two Z3 versions, but both are Z3. | Diversity is CBMC-SAT + CBMC-Z3 + ESBMC-Z3(4.13.3), plus native replay. Optionally add `--cvc5` or `--bitwuzla` (both listed in `cbmc --help`) as a non-Z3 SMT check if installed. | confirmed (docs/run) |
| R15 | Sanitizer replay depends on the runtime being installed. | Clang 18 here lacks `libclang_rt.asan`; GCC 13.3 ASan+UBSan works: the Example 2 v3 witness (`n = 3`) reproduces as `heap-buffer-overflow`. | Replay unavailable in some setups. | GCC is the default replay compiler; the Docker image installs GCC with sanitizer runtimes. | confirmed (run) |
| R16 | The draft lists the Mastora–Sullivan executable HLS repair benchmark as a source. | Its arXiv page links no code or data artifact. | Cannot rely on it. | Use Chrysalis-HLS directly (bug specifications + correct sources) with our own injection and oracles. Contact the authors for the artifact as an optional extra. | confirmed (docs) |
| R17 | The form of Chrysalis "bug specifications". | Each `Bugs/bug_<TYPE>.txt` is JSON: `Error Size`, and a list of `{Error Type, Original Code, Faulty Code}`. It contains no natural-language request. | $N$ must be authored by us. | Requests are written per the draft's protocol (§11.2). Chrysalis supplies $P_{ref}$ (`Source_Code`) and an exact edit to create $P_0$. | confirmed (run) |
| R18 | Quantifiers in contracts. | CBMC has `__CPROVER_forall`/`__CPROVER_exists`, but solver support varies (needs verification per backend). | Possible spurious INCONCLUSIVE. | Translate bounded quantifiers to loops that compute a Boolean (as in Example 4), covered by the unwinding bound. `__CPROVER_forall` is an optional optimisation. | needs verification (forall per backend) |
| R19 | Shared harness intrinsics. | ESBMC 8.7.0 accepted the CBMC-style spikes using `nondet_*` functions and `__CPROVER_assert` (T01, T03, T04 parsed and ran). | Less need for per-tool code than the draft feared. | Keep the thin intrinsic layer (`vwe_assume`, `vwe_assert`, `vwe_nondet_*` macros) but default it to the shared subset. Per-tool overrides only where a test shows a difference. | confirmed (run) for the subset used |
| R20 | The verdict rule implementation. | `vwe.verdict.decide` encodes §5.2. Unit tests include an exhaustive check of Lemma 5 (adding an interpretation never creates a new decision). | — | Keep as the single source of truth for verdicts. | confirmed (run: 7 unit tests pass) |
| R21 | End-to-end feasibility of the worked examples. | Examples 1 (5 variants), 2 (3 variants) and 4 (2 variants) as hand-written harnesses give **10/10 verdicts equal to the draft**, each obligation agreeing on SAT and Z3. Side checks confirm $B_{ub}$ for Example 2 is exactly $n = 0$, and the $(n-1)$ shape is discarded by V-G. | Confirms the theory maps onto CBMC queries. | `scripts/run_golden_examples.py` becomes the golden end-to-end test. | confirmed (run) |
| R22 | Benchmark download paths. | Codeflaws data is served from an `http://` (not https) NUS URL. The IntroClass repository is about 2.2 GB. CHStone is available from the `ferrandi/CHStone` GitHub mirror (README "CHStone v1.11", per-program copyright). | Docker builds may fail; licensing must be tracked per program. | Datasets are fetched by a separate script with SHA-256 pinning, outside the image. Licenses are recorded per task (`task.schema.json`). | confirmed (run/docs) |
| R23 | The Vitis HLS command line for 2026.1 is not specified in the draft. | UG1399 pages show the `syn.*` configuration keys (e.g. `syn.rtl.reset`, `syn.directive.reset`). The exact batch command (`v++ -c --mode hls` vs other front ends) has not been checked for 2026.1. | Gate-B scripts may not run as written. | The TDD gives a config-file-based flow and marks the exact CLI as *needs verification on the installed version*. | needs verification |
| R24 | LLM model choice is unspecified. | — | Irreproducible results. | The TDD defines a provider-neutral client. Exact model IDs and dates are pinned at setup and stored in every run manifest. No model is named as "best" without evidence. | design |
| R25 | Cost of "one check per equivalence class". | Each class needs its own harness. Computing classes needs pairwise relation-equality queries with a free output $y$, which is $O(m^2)$ CBMC runs. | Time. | Cap $m$ by deduplicating syntactically identical clause sets first. Run equivalence queries in parallel with a per-query timeout. An unresolved pair is treated as non-equivalent (safe direction by Lemma 5). | design |
| R26 | The draft's invariant "no LLM ever reads $P_1$" conflicts with the FIFO track's need for a per-candidate coupling invariant. | A circular-buffer FIFO's invariant must mention the candidate's own state variables. | Either the invariant breaks or unbounded FIFO proofs are impossible. | Narrow, logged exception: the LLM may see only a *structural summary* of $P_1$'s state (names and types of `static` variables), never its code. The proposed invariant is checked by base case and inductive step. A wrong invariant can only give INCONCLUSIVE, never ACCEPT. Preferred route: template invariants for circular buffers plus ESBMC `--k-induction`, with no LLM. | design |

## B. Conclusions of the review

1. **The design is implementable with the named tools.** Every core mechanism that matters for soundness was demonstrated on a real run:
   - exact-size buffers;
   - the while(1) and abort defences;
   - build views;
   - self-composition;
   - SAT/Z3 agreement;
   - sanitizer replay;
   - the verdict rules.
2. **Three statements in the draft must be corrected for CBMC 6.11.0:**
   - malloc *can* fail by default (R5);
   - missing bodies are *reported*, not silently ignored (R4);
   - `abort()` *is* a silent path cut, in both CBMC and ESBMC (R1, R3).

   The TDD uses the corrected facts.
3. **ESBMC is confirmation-only** (R3). This keeps "ACCEPT requires CBMC + ESBMC agreement" sound, because ESBMC alone never decides.
4. **Two items need verification on the target machine:** solver support for CBMC quantifiers (R18) and the exact Vitis HLS 2026.1 batch command (R23).
