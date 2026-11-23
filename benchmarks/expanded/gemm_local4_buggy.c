#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++){
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int k=0;k<4;k++){uint32_t v=m1[i*4+k];s0+=v*m2[k*4];s1+=v*m2[k*4+1];s2+=v*m2[k*4+2];s3+=v*m2[k*4+3];}
    prod[i*4]=s0;prod[i*4+1]=s1;prod[i*4+2]=s2;prod[i*4+3]=s3;}
    prod[0]^=1u;
}
