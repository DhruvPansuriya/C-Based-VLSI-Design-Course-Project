// Candidate transformation: make k the outermost loop, then i, then j.
// Initializing out before accumulation is required in both versions.
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for (int p = 0; p < 16; p++) {
        out[p] = 0u;
    }

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                out[i * 4 + j] += a[i * 4 + k] + b[k * 4 + j];
            }
        }
    }
}
