#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Four-way partial-sum reduction. */
uint32_t kernel(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0+=a[i];s1+=a[i+1];s2+=a[i+2];s3+=a[i+3];}
    return (s0+s1)+(s2+s3);
}
