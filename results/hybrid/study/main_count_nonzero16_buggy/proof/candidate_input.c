#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t n0=0u,n1=0u,n2=0u,n3=0u;
    for(int i=0;i<16;i+=4){n0+=(a[i]!=0u?1u:0u);n1+=(a[i+1]!=0u?1u:0u);n2+=(a[i+2]!=0u?1u:0u);n3+=(a[i+3]!=0u?1u:0u);}
    return ((n0+n1)+(n2+n3))^1u;
}
