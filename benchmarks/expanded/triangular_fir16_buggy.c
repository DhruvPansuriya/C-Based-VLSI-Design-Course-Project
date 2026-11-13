#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t out[14]) {
    uint32_t previous=a[0]+a[1];for(int i=0;i<14;i++){uint32_t next=a[i+1]+a[i+2];out[i]=previous+next;previous=next;}
    out[0]^=1u;
}
