#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[16]) {
    uint32_t sum=0u;for(int r=0;r<4;r++) for(int c=0;c<4;c++) if(r==c || r+c==3) sum+=a[r*4+c];return sum;
}
