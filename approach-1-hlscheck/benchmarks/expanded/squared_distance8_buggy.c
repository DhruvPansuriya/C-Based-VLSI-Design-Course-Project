#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return (aa+bb-2u*ab)^1u;
}
