#include <stdint.h>

void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        out[i] = a[i] * 8u + 3u;
    }
}
