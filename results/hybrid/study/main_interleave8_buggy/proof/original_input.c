#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[8], uint32_t b[8], uint32_t out[16]) {
    for(int i=0;i<8;i++) out[2*i]=a[i];for(int j=0;j<8;j++) out[2*j+1]=b[j];
}
