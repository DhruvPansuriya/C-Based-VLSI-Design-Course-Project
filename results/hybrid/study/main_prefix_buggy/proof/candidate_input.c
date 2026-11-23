#include <stdint.h>

/* Seeded negative control: misses the last output. */
void kernel(uint32_t a[8], uint32_t out[8]) {
    uint32_t running = 0u;
    for (int i = 0; i < 7; i++) {
        running += a[i];
        out[i] = running;
    }
}
