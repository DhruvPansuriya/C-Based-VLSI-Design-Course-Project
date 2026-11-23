#include <stdint.h>

void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t tmp[4]) {
    for (int i = 0; i < 4; i++) {
        y[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        tmp[i] = 0u;
        for (int j = 0; j < 4; j++) {
            tmp[i] = tmp[i] + a[i * 4 + j] * x[j];
        }
        for (int j = 0; j < 4; j++) {
            y[j] = y[j] + a[i * 4 + j] * tmp[i];
        }
    }
}
