#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Paired reverse-copy staging. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<8;i++){uint32_t x=a[i],y=a[15-i];out[i]=y;out[15-i]=y;}
}
