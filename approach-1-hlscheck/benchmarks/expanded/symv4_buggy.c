#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++) out[r]=0u;
    for(int r=0;r<4;r++) for(int c=0;c<=r;c++){uint32_t value=a[r*4+c];out[r]+=value*x[c];if(c!=r) out[c]+=value*x[r];}
    out[0]^=1u;
}
