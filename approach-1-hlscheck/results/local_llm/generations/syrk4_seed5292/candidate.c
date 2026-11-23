#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) {
        uint32_t sum1 = 0u, sum2 = 0u, sum3 = 0u, sum4 = 0u;
        for(int j=0;j<4;j++) {
            sum1 += a[i*4+j] * a[j*4+0];
            sum2 += a[i*4+j] * a[j*4+1];
            sum3 += a[i*4+j] * a[j*4+2];
            sum4 += a[i*4+j] * a[j*4+3];
        }
        out[i*4+0] = sum1;
        out[i*4+1] = sum2;
        out[i*4+2] = sum3;
        out[i*4+3] = sum4;
    }
}
