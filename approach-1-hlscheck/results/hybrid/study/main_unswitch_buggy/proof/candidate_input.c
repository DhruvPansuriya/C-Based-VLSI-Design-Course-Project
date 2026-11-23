#include <stdint.h>

/* Deliberate negative control: a subtle boundary error at x == 10. */
void kernel(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    if (x >= 10u) {
        for (int i = 0; i < 4; i++) {
            a[i] = b[i] + c[i];
        }
    } else {
        for (int j = 0; j < 4; j++) {
            a[j] = b[j] - c[j];
        }
    }
}
