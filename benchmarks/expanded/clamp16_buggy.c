#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t v=a[i];out[i]=(v>>8)!=0u?255u:v;}
    out[0]^=1u;
}
