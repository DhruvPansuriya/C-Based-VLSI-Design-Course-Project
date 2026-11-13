#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16], uint32_t b[16]) {
    uint32_t sum=0u;
    for(int i=0;i<16;i++) sum+=a[i]*b[i];
    return sum;
}
