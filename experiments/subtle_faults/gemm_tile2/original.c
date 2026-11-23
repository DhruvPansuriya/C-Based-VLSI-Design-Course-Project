#include <stdint.h>

/* MachSuite-derived reference algorithm; LICENSE.MachSuite is retained.
   Feedback candidate: two local accumulators rather than four. */
void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j+=2) {
            uint32_t s0=0u, s1=0u;
            for(int k=0;k<4;k++) {
                uint32_t value=m1[i*4+k];
                s0+=value*m2[k*4+j];
                s1+=value*m2[k*4+j+1];
            }
            prod[i*4+j]=s0;
            prod[i*4+j+1]=s1;
        }
    }
}
