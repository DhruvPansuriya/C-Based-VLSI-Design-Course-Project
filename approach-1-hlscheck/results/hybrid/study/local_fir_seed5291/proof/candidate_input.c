#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t sum = 0u;
    for (int i = 0; i < 8; i++) {
        sum += a[i] * (2 * i + 1);
    }
    return sum;
}
