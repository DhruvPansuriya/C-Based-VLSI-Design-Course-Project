#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++) out[c*4+r]=a[r*4+c];
}
