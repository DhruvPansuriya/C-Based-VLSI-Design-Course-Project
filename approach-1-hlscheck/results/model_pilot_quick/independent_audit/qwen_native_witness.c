#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(uint32_t)==4,"uint32_t must be 32 bits");
#include <stdint.h>

/* Educational reference: recompute each prefix independently. */
void original(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        uint32_t sum = 0u;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        out[i] = sum;
    }
}

#include <stdint.h>

void candidate(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        out[i] = __builtin_add_overflow(a[i], 0u, &out[i]);
    }
}

int main(void) {
    uint32_t a_left[8]={1u,1u,1u,1u,1u,1u,1u,1u};
    uint32_t a_right[8]={1u,1u,1u,1u,1u,1u,1u,1u};
    uint32_t out_left[8]={0u}, out_right[8]={0u};
    original(a_left,out_left);
    candidate(a_right,out_right);
    unsigned mismatch=0u;
    printf("original:");
    for(int i=0;i<8;i++) {printf(" %u",out_left[i]); mismatch|=out_left[i]!=out_right[i];}
    printf("\ncandidate:");
    for(int i=0;i<8;i++) printf(" %u",out_right[i]);
    printf("\nmismatch: %u\n",mismatch);
    return mismatch?0:1;
}
