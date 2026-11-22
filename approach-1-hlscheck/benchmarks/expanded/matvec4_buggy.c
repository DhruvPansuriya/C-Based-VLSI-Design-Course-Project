#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t p0=a[r*4]*x[0],p1=a[r*4+1]*x[1],p2=a[r*4+2]*x[2],p3=a[r*4+3]*x[3];out[r]=(p0+p1)+(p2+p3);}
    out[0]^=1u;
}
