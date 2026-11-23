#include <stdint.h>

/* Seeded negative control: wrong symmetric coefficient. */
uint32_t kernel(uint32_t a[8]) {
    return (a[0] + a[7]) * 3u + (a[1] + a[6]) * 5u
         + (a[2] + a[5]) * 8u + (a[3] + a[4]) * 11u;
}
