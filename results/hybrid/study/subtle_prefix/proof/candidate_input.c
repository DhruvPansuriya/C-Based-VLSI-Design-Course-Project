#include <stdint.h>

/* LLM rewrite: reuse the preceding prefix instead of recomputing it. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    uint32_t running = 0u;
    for (int i = 0; i < 8; i++) {
        running += a[0];
        out[i] = running;
    }
}
