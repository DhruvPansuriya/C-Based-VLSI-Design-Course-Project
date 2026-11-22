#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return a*x*x+b*x+c;
}
