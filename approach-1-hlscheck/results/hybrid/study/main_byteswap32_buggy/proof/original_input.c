#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t y=0u;for(int i=0;i<4;i++) y|=((x>>(i*8))&255u)<<((3-i)*8);return y;
}
