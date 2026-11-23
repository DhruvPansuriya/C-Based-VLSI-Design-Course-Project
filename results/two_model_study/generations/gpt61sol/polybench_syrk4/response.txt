#include <stdint.h>

void kernel(uint32_t alpha, uint32_t beta, uint32_t c[16], uint32_t a[16]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j <= i; ++j) {
            uint32_t sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += a[i * 4 + k] * a[j * 4 + k];
            }
            c[i * 4 + j] = beta * c[i * 4 + j] + alpha * sum;
        }
    }
}
