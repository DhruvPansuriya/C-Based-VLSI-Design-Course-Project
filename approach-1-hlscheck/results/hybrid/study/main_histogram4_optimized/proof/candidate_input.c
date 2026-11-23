#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Fuse four fixed-bin histogram scans. */
void kernel(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
}
