#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t sum=0u;for(int i=0;i<8;i++){uint32_t d=a[i]-b[i];sum+=d*d;}return sum;
}
