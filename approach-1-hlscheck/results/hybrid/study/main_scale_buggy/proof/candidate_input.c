#include <stdint.h>

/* Deliberate negative control: second lane uses the wrong shift amount. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = (a[i] << 3) + 3u;
        out[i + 1] = (a[i + 1] << 2) + 3u;
    }
}
