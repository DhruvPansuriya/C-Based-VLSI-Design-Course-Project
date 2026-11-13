#include <stdint.h>

/* LLM rewrite: separable filtering, reusing horizontal sums across rows. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for (int r = 0; r < 5; r++) {
        uint32_t sum = image[r * 5] + image[r * 5 + 1] + image[r * 5 + 2];
        horizontal[r * 3] = sum;
        for (int c = 1; c < 3; c++) {
            sum = sum - image[r * 5 + c - 1] + image[r * 5 + c + 1];
            horizontal[r * 3 + c] = sum;
        }
    }
    for (int r2 = 0; r2 < 3; r2++) {
        for (int c2 = 0; c2 < 3; c2++) {
            out[r2 * 3 + c2] = horizontal[r2 * 3 + c2]
                + horizontal[(r2 + 1) * 3 + c2] + horizontal[(r2 + 2) * 3 + c2];
        }
    }
}
