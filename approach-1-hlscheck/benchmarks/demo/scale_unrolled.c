#include <stdint.h>

/* Structural control: unroll by two while retaining the original arithmetic. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = a[i] * 8u + 3u;
        out[i + 1] = a[i + 1] * 8u + 3u;
    }
}
