#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t x) {
    uint32_t crc=x&255u;for(int i=0;i<4;i++){crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;}return (crc)^1u;
}
