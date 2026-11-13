#include <stdint.h>

/* Feedback candidate: one new memory read per output after initialization. */
void kernel(uint32_t a[16], uint32_t out[13]) {
    uint32_t w0=a[0], w1=a[1], w2=a[2], w3=a[3];
    for(int i=0;i<13;i++) {
        out[i]=(w0+w1)+(w2+w3);
        if(i<12) {
            w0=w1;
            w1=w2;
            w2=w3;
            w3=a[i+4];
        }
    }
}
