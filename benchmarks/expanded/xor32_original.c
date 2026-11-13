#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[32]) {
    uint32_t sum=0u;for(int i=0;i<32;i++) sum^=a[i];return sum;
}
