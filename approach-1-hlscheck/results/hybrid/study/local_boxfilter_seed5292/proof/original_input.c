#include <stdint.h>

/* Educational 3x3 box sum over the nine valid windows of a 5x5 image. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t sum = 0u;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    sum += image[(r + y) * 5 + c + x];
                }
            }
            out[r * 3 + c] = sum;
        }
    }
}
