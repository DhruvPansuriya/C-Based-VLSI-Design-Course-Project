#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){uint32_t sum=0u;for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) sum+=image[i*4+j];out[r*4+c]=sum;}
}
