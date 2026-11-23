#include <stdint.h>

void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t tmp[4]) {
    const uint32_t x0 = x[0];
    const uint32_t x1 = x[1];
    const uint32_t x2 = x[2];
    const uint32_t x3 = x[3];
    uint32_t y0 = 0u;
    uint32_t y1 = 0u;
    uint32_t y2 = 0u;
    uint32_t y3 = 0u;

    for (int i = 0; i < 4; ++i) {
        const uint32_t a0 = a[4 * i];
        const uint32_t a1 = a[4 * i + 1];
        const uint32_t a2 = a[4 * i + 2];
        const uint32_t a3 = a[4 * i + 3];
        const uint32_t t = (a0 * x0 + a1 * x1)
                         + (a2 * x2 + a3 * x3);
        tmp[i] = t;
        y0 += a0 * t;
        y1 += a1 * t;
        y2 += a2 * t;
        y3 += a3 * t;
    }

    y[0] = y0;
    y[1] = y1;
    y[2] = y2;
    y[3] = y3;
}
