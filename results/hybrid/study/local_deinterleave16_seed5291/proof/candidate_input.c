#include <stdint.h>

/* Optimized fixed-size uint32_t kernel for high-level synthesis.
   Reference implementation. */
void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++) even[i]=a[2*i];for(int j=0;j<8;j++) odd[j]=a[2*j+1];
}
