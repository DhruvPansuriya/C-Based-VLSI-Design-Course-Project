#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++) low=a[i]<low?a[i]:low;
    for(int j=1;j<8;j++) high=a[j]>high?a[j]:high;
    return high-low;
}
