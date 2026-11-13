#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Direct traversal of two disjoint diagonals. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) sum+=a[r*4+r]+a[r*4+r];return sum;
}
