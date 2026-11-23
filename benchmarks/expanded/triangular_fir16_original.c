#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[14]) {
    for(int i=0;i<14;i++) out[i]=a[i]+2u*a[i+1]+a[i+2];
}
