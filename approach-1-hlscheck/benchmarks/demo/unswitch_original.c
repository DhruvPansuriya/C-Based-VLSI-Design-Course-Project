#include <stdint.h>

/* Adapted from the loop-unswitching example in CS5291 W10L2.
   Uses uint32_t, zero-based indexing, and a fixed dimension. */
void kernel(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    for (int i = 0; i < 4; i++) {
        if (x > 10u) {
            a[i] = b[i] + c[i];
        } else {
            a[i] = b[i] - c[i];
        }
    }
}
