#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-lane SAXPY source unrolling. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t k, uint32_t out[16]) {
    for(int i=0;i<16;i+=2){out[i]=a[i]*k+b[i];out[i+1]=a[i+1]*k+b[i];}
}
