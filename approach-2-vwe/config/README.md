# config/ - settings

| File | Used for |
|---|---|
| `default.toml` | normal runs: size bound K = 4, unwinding 9, 600 s solver limit |
| `demo.toml` | smaller bounds (K = 2, 60 s solver limit) so each demo case finishes quickly |
| `benchmark.toml` | the Chrysalis-HLS evaluation |
| `project3.toml` | the HLSCheck (Approach-1) cases |
| `llm.toml` | which model families to ask for readings and how |
| `whitelist.toml` | library functions VWE knows how to model |

API keys go in `config/secrets/` (for example `groq.key`). That folder is git-ignored and is never
committed. Without keys everything still runs with the handwritten readings.
