#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){uint32_t best=image[r*8+c*2];for(int i=0;i<2;i++) for(int j=0;j<2;j++){uint32_t v=image[(r*2+i)*4+c*2+j];best=v>best?v:best;}out[r*2+c]=best;}
}
