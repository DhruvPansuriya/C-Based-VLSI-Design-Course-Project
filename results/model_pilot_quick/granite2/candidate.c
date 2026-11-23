#include <stdint.h>

void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        uint32_t sum = 0u;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        out[i] = sum % (1ULL << 32);
    }
}
