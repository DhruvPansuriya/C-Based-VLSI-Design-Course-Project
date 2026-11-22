#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) sum+=a[r*4+r]+a[r*4+3-r];return (sum)^1u;
}
