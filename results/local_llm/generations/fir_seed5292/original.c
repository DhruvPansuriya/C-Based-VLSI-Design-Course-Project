#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t sum = a[0] * 3u;
    sum += a[1] * 5u;
    sum += a[2] * 7u;
    sum += a[3] * 11u;
    sum += a[4] * 11u;
    sum += a[5] * 7u;
    sum += a[6] * 5u;
    sum += a[7] * 3u;
    return sum;
}
