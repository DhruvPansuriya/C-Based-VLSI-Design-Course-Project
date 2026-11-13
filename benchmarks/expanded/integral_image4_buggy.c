#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){
    uint32_t value=image[r*4+c];
    if(r>0) value+=out[(r-1)*4+c];
    if(c>0) value+=out[r*4+c-1];
    if(r>0 && c>0) value-=out[(r-1)*4+c-1];
    out[r*4+c]=value;}
    out[0]^=1u;
}
