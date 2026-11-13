#include <stdint.h>

/* Improved fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) for(int j=0;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;}
}
