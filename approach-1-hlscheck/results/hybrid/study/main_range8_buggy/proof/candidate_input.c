#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
    return (high-low)^1u;
}
