#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Exploit three-tap coefficient symmetry. */
void kernel(uint32_t a[8], uint32_t out[6]) {
    for(int i=0;i<6;i++) out[i]=3u*(a[i]+a[i+1])+5u*a[i+1];
}
