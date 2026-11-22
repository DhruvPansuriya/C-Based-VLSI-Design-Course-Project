#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            uint32_t sum0 = 0u;
            uint32_t sum1 = 0u;
            uint32_t sum2 = 0u;
            for (int k = 0; k < 3; ++k) {
                int base = (r + k) * 5 + c;
                sum0 += filter[k * 3] * orig[base];
                sum1 += filter[k * 3 + 1] * orig[base + 1];
                sum2 += filter[k * 3 + 2] * orig[base + 2];
            }
            sol[r * 5 + c] = (sum0 + sum1) + sum2;
        }
    }
}
