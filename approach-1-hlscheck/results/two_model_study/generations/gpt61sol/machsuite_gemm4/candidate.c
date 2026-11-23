#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; ++i) {
        const uint32_t a0 = m1[i * 4];
        const uint32_t a1 = m1[i * 4 + 1];
        const uint32_t a2 = m1[i * 4 + 2];
        const uint32_t a3 = m1[i * 4 + 3];

        for (int j = 0; j < 4; ++j) {
            prod[i * 4 + j] =
                (a0 * m2[j] + a1 * m2[4 + j]) +
                (a2 * m2[8 + j] + a3 * m2[12 + j]);
        }
    }
}
