#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t k, uint32_t out[16]) {
    for(int i=0;i<16;i+=2){out[i]=a[i]*k+b[i];out[i+1]=a[i+1]*k+b[i+1];}
    out[0]^=1u;
}
