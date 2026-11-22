#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;for(int bit=0;bit<8;bit++) total+=(v>>bit)&1u;}return total;
}
