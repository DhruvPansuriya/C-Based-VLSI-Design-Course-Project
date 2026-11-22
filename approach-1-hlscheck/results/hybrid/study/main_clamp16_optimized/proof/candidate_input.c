#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Upper-bit saturation test. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t v=a[i];out[i]=(v>>8)!=0u?255u:v;}
}
