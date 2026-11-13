#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t x) {
    uint32_t crc=x&255u;for(int i=0;i<8;i++){crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;}return crc;
}
