#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Two-stage byte permutation. */
uint32_t kernel(uint32_t x) {
    uint32_t t=((x&0x00ff00ffu)<<8)|((x>>8)&0x00ff00ffu);return (t<<16)|(t>>15);
}
