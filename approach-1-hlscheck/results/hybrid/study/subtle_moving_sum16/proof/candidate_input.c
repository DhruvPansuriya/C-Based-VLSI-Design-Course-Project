#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Sliding four-element window sum. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t sum=a[0]+a[1]+a[2]+a[3];out[0]=sum;for(int i=1;i<13;i++){sum=sum-a[i]+a[i+3];out[i]=sum;}
}
