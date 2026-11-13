#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]!=0u?1u:0u);return n;
}
