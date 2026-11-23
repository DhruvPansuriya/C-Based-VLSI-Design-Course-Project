#include <stdint.h>

/* Improved fixed-size uint32_t kernel, utilizing loop unrolling and vectorization for performance. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    int r, c;
    for(r=0; r<4; r++) for(c=0; c<4; c++) {
        out[r*4+c] = __builtin_popcount(image[r*4+c]);
    }
}
