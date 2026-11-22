#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t lo=0u,hi=0u;for(int i=0;i<4;i++){lo|=(a[i]>128u?1u:0u)<<i;hi|=(a[i+4]>128u?1u:0u)<<i;}return (lo|(hi<<4))^1u;
}
