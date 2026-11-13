#include <stdint.h>

void kernel(uint32_t a[16], uint32_t s[4], uint32_t q[4], uint32_t p[4], uint32_t r[4]) {
    uint32_t s0 = 0u, s1 = 0u, s2 = 0u, s3 = 0u;
    const uint32_t p0 = p[0], p1 = p[1], p2 = p[2], p3 = p[3];

    for (int i = 0; i < 4; ++i) {
        const uint32_t ri = r[i];
        const uint32_t a0 = a[4 * i];
        const uint32_t a1 = a[4 * i + 1];
        const uint32_t a2 = a[4 * i + 2];
        const uint32_t a3 = a[4 * i + 3];

        s0 += ri * a0;
        s1 += ri * a1;
        s2 += ri * a2;
        s3 += ri * a3;
        q[i] = (a0 * p0 + a1 * p1) + (a2 * p2 + a3 * p3);
    }

    s[0] = s0;
    s[1] = s1;
    s[2] = s2;
    s[3] = s3;
}
