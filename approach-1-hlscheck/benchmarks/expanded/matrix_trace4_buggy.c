#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int i=0;i<4;i++) sum+=a[i*5];return (sum)^1u;
}
