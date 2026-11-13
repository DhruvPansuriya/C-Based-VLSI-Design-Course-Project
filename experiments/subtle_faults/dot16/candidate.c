#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Four independent dot-product accumulators. */
uint32_t kernel(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+2]*b[i+3];}
    return (s0+s1)+(s2+s3);
}
