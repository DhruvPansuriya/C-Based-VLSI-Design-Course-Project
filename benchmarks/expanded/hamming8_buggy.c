#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);total+=(v+(v>>4))&15u;}return (total)^1u;
}
