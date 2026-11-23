// 4 x 4 matrix multiplication, original loop order: i -> j -> k.
// This .cpp file deliberately uses the C-compatible integer subset.
#include <stdint.h>

void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for (int p = 0; p < 16; p++) {
        out[p] = 0u;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                out[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
            }
        }
    }
}
