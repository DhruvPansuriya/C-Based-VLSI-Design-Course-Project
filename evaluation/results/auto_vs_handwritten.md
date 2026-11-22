# Auto versus handwritten interpretations (examples 1, 2, 4)

**Generator:** authored mock fixtures (`tests/fixtures/llm/auto`), *not* a live model. The fixtures are derived from the handwritten readings, so agreement here only shows that generation, freezing and verification preserve verdicts. It is not evidence about model quality. No live provider was configured.

| task | candidate | handwritten | auto (mock fixtures) | |
|---|---|---|---|---|
| ex1_saturate | v1 | ACCEPT E2 | ACCEPT E2 | same |
| ex1_saturate | v2 | ACCEPT E2 | ACCEPT E2 | same |
| ex1_saturate | v3 | REJECT E1 | REJECT E1 | same |
| ex1_saturate | v4 | REJECT E2 | REJECT E2 | same |
| ex1_saturate | v5 | REJECT E2 | REJECT E2 | same |
| ex2_argmax | v1 | ACCEPT E2 | ACCEPT E2 | same |
| ex2_argmax | v2 | REJECT E1 | REJECT E1 | same |
| ex2_argmax | v3 | REJECT E0 | REJECT E0 | same |
| ex4_sum | v1 | ACCEPT E2 | ACCEPT E2 | same |
| ex4_sum | v2 | REJECT E0 | REJECT E0 | same |

Differences: 0 of 10.
