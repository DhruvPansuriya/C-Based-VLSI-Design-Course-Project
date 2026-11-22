#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
void kernel(uint32_t image[25], uint32_t out[9]) {
    for(int r=0;r<3;r++) for(int c=0;c<3;c++){
    uint32_t sum=0u;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){uint32_t wi=i==1?2u:1u;uint32_t wj=j==1?2u:1u;sum+=wi*wj*image[(r+i)*5+c+j];}
    out[r*3+c]=sum;}
}
