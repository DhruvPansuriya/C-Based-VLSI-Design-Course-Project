#include <stdint.h>

/* Optimized fixed-size uint32_t kernel for high-level synthesis.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t packed=0u;for(int i=0;i<8;i++) packed|=(a[i]>128u?1u:0u)<<i;return packed;
}
