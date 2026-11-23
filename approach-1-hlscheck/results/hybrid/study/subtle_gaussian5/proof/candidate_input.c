#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Separable integer Gaussian filter. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for(int r=0;r<5;r++) for(int c=0;c<3;c++) horizontal[r*3+c]=image[r*5+c]+2u*image[r*5+c+1]+image[r*5+c+2];
    for(int r=0;r<3;r++) for(int c=0;c<3;c++) out[r*3+c]=horizontal[r*3+c]+1u*horizontal[(r+1)*3+c]+horizontal[(r+2)*3+c];
}
