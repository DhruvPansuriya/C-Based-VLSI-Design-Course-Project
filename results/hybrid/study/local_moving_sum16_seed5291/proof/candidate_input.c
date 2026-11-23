#include <stdint.h>

/* Improved fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    for(int i=0;i<13;i++){
        uint32_t sum=0u;
        for(int j=0;j<4;j++) sum+=a[i+j];
        out[i]=sum;
    }
}
