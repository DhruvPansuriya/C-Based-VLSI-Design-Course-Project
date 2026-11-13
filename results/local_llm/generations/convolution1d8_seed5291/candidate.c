#include <stdint.h>

/* Improved fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[8], uint32_t out[6]) {
    for(int i=0;i<6;i++) {
        uint32_t sum = 3u*a[i] + 5u*a[i+1] + 3u*a[i+2];
        out[i] = sum;
    }
}
