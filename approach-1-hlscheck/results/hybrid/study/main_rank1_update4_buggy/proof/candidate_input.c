#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16]) {
    for(int r=0;r<4;r++){uint32_t v=x[r];out[r*4]=a[r*4]+v*y[0];out[r*4+1]=a[r*4+1]+v*y[1];out[r*4+2]=a[r*4+2]+v*y[2];out[r*4+3]=a[r*4+3]+v*y[3];}
    out[0]^=1u;
}
