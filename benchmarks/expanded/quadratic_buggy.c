#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return ((a*x+b)*x+c)^1u;
}
