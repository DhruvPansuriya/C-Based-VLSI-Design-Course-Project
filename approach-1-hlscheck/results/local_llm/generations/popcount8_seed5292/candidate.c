#include <stdint.h>

/* Improved fixed-size uint32_t kernel, utilizing bit manipulation and loop unrolling for performance. */
uint32_t kernel(uint32_t x) {
    uint32_t count = 0u;
    for (int i = 0; i < 8; i += 2) {
        // Unroll loop by processing 2 bits at a time
        count += (x >> i) & 3u;
        count += (x >> (i + 1)) & 3u;
    }
    return count;
}
