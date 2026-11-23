#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Expand squared distance into three reductions. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return aa+bb-ab;
}
