#include <stdint.h>

/* Optimized fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t parity=0u;for(int i=0;i<32;i++) parity^=(x>>i)&1u;return parity;
}
