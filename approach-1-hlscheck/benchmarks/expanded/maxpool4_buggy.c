#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}
    out[0]^=1u;
}
