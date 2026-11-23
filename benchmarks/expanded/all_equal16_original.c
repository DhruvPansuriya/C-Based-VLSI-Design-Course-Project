#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t same=1u;for(int i=1;i<16;i++) same&=(a[i]==a[0]?1u:0u);return same;
}
