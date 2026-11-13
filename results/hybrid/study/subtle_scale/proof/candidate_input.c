#include <stdint.h>

/* LLM-authored candidate: strength reduction and two-way source unrolling.
   Candidate status is determined independently by hlscheck. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = (a[i] << 3) + 3u;
        out[i + 1] = (a[i] << 3) + 3u;
    }
}
