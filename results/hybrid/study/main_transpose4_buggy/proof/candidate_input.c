#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c+=2){uint32_t x=a[r*4+c],y=a[r*4+c+1];out[c*4+r]=x;out[(c+1)*4+r]=y;}
    out[0]^=1u;
}
