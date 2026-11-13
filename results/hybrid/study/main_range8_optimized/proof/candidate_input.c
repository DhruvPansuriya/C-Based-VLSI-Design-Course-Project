#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse minimum and maximum scans. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
    return high-low;
}
