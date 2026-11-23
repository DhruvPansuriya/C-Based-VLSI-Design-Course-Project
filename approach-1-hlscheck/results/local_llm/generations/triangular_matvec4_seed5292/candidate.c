#include <stdint.h>

/* Optimized fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    uint32_t sum[4];

    for(int r=0;r<4;r++) {
        sum[r] = 0u;
        for(int c=0;c<=r;c++) {
            sum[r] += a[r*4 + c] * x[c];
        }
        out[r] = sum[r];
    }
}
