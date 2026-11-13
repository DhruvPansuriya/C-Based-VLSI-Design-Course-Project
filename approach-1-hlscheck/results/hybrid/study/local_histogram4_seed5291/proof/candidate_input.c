#include <stdint.h>

/* Improved fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[4]) {
    for(int bin=0;bin<4;bin++){uint32_t count=0u;for(int i=0;i<16;i++) count+=((a[i]&3u)==(uint32_t)bin?1u:0u);out[bin]=count;}
}
