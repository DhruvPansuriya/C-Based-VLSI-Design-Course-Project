#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Horner-form quadratic evaluation. */
uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return (a*x+b)*x+c;
}
