/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

void kernel(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    temp += filter[k1 * 3 + k2] * orig[(r + k1) * 5 + c + k2];
                }
            }
            sol[r * 5 + c] = temp;
        }
    }
}
