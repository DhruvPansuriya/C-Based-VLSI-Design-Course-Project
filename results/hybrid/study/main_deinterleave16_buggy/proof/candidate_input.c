#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}
    even[0]^=1u;
}
