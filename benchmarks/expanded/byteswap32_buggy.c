#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t x) {
    uint32_t t=((x&0x00ff00ffu)<<8)|((x>>8)&0x00ff00ffu);return ((t<<16)|(t>>16))^1u;
}
