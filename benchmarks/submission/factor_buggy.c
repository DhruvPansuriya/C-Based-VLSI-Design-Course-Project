#include <stdint.h>

/* Seeded negative control: invalid factoring. */
uint32_t kernel(uint32_t x, uint32_t y, uint32_t z) {
    return x * y + z;
}
