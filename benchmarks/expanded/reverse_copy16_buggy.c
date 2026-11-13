#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<8;i++){uint32_t x=a[i],y=a[15-i];out[i]=y;out[15-i]=x;}
    out[0]^=1u;
}
