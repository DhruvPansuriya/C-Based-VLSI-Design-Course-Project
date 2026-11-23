#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Share comparison before subtraction. */
void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?x:y;out[i]=high-low;}
}
