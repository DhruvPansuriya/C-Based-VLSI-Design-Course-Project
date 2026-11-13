#include <stdint.h>

void kernel(uint32_t a[8], uint32_t out[8]) {
    uint32_t sum = 0u;
    for (int i = 0; i < 8; i++) {
        sum += a[i];
        out[i] = sum;
    }
}
