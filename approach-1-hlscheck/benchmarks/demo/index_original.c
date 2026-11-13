#include <stdint.h>

uint32_t kernel(uint32_t a[8], uint32_t index) {
    return a[index & 7u];
}
