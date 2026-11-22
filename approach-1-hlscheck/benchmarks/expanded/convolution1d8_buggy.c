#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[8], uint32_t out[6]) {
    for(int i=0;i<6;i++) out[i]=3u*(a[i]+a[i+2])+5u*a[i+1];
    out[0]^=1u;
}
