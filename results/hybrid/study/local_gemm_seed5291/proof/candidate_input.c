#include <stdint.h>

void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            uint32_t sum = 0u;
            for (int k = 0; k < 4; k++) {
                sum += m1[i * 4 + k] * m2[k * 4 + j];
            }
            prod[i * 4 + j] = sum;
        }
    }
}
