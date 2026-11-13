#include <stdint.h>

/* Improved fixed-size uint32_t kernel, utilizing loop unrolling for better hardware area or function latency.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t y=0u;for(int i=0;i<32;i+=4){y=(y<<16)|(x&3u);y=(y<<16)|(x>>2);y=(y<<16)|(x>>4);x>>=8;}return y;
}
