#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse even/odd extraction loops. */
void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}
}
