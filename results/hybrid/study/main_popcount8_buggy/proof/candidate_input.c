#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t x) {
    uint32_t v=x&255u;v=v-((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);return ((v+(v>>4))&15u)^1u;
}
