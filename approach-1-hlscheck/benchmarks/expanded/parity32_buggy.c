#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t x) {
    x^=x>>16;x^=x>>8;x^=x>>4;x^=x>>2;x^=x>>1;return (x&1u)^1u;
}
