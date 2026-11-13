#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Dynamic-programming summed-area table. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){
    uint32_t value=image[r*4+c];
    if(r>0) value+=out[(r-1)*4+c];
    if(c>0) value+=out[r*4+c-1];
    if(r>0 && c>0) value-=out[(r-1)*4+c-1];
    out[r*4+c]=value;}
}
