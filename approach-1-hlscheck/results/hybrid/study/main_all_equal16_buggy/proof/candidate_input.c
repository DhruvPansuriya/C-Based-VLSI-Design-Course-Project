#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t difference=0u;uint32_t first=a[0];
    for(int i=1;i<16;i++) difference|=a[i]^first;
    return (difference==0u?1u:0u)^1u;
}
