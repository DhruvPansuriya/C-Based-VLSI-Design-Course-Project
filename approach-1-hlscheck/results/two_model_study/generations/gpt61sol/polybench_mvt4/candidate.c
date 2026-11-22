#include <stdint.h>

void kernel(uint32_t x1[4], uint32_t x2[4], uint32_t y_1[4], uint32_t y_2[4], uint32_t a[16]) {
    for (int i = 0; i < 4; ++i) {
        uint32_t p0 = a[4 * i] * y_1[0];
        uint32_t p1 = a[4 * i + 1] * y_1[1];
        uint32_t p2 = a[4 * i + 2] * y_1[2];
        uint32_t p3 = a[4 * i + 3] * y_1[3];
        uint32_t q0 = a[i] * y_2[0];
        uint32_t q1 = a[4 + i] * y_2[1];
        uint32_t q2 = a[8 + i] * y_2[2];
        uint32_t q3 = a[12 + i] * y_2[3];

        x1[i] += (p0 + p1) + (p2 + p3);
        x2[i] += (q0 + q1) + (q2 + q3);
    }
}
