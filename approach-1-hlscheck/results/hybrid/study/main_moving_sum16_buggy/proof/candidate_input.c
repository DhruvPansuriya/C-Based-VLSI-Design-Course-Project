#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t sum=a[0]+a[1]+a[2]+a[3];out[0]=sum;for(int i=1;i<13;i++){sum=sum-a[i-1]+a[i+3];out[i]=sum;}
    out[0]^=1u;
}
