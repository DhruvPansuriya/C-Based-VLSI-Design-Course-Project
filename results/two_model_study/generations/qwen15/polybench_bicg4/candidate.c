#include <stdint.h>

void kernel(uint32_t a[16], uint32_t s[4], uint32_t q[4], uint32_t p[4], uint32_t r[4]) {
    for (int i = 0; i < 4; i++) {
        s[i] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        q[i] = 0u;
        for (int j = 0; j < 4; j++) {
            s[j] = s[j] + r[i] * a[i * 4 + j];
            q[i] = q[i] + a[i * 4 + j] * p[j];
        }
    }
}
