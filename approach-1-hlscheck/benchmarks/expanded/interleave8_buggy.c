#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[8], uint32_t b[8], uint32_t out[16]) {
    for(int i=0;i<8;i++){out[2*i]=a[i];out[2*i+1]=b[i];}
    out[0]^=1u;
}
