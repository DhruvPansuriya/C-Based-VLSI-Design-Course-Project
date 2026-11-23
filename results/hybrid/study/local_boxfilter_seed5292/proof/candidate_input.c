#include <stdint.h>

/* Educational 3x3 box sum over the nine valid windows of a 5x5 image. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    // Reuse the image array to store intermediate sums for parallel computation
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            out[r * 3 + c] = 0u;
        }
    }
    // Calculate the sums in parallel using the image array
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    out[r * 3 + c] += image[(r + y) * 5 + c + x];
                }
            }
        }
    }
}
