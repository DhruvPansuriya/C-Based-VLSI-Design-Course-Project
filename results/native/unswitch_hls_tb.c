#include <stdint.h>
#include <assert.h>
void kernel(uint32_t x,uint32_t b[4],uint32_t c[4],uint32_t a[4]);
#include <stdint.h>

/* Adapted from the loop-unswitching example in CS5291 W10L2.
   Uses uint32_t, zero-based indexing, and a fixed dimension. */
void original(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    for (int i = 0; i < 4; i++) {
        if (x > 10u) {
            a[i] = b[i] + c[i];
        } else {
            a[i] = b[i] - c[i];
        }
    }
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
for(unsigned t=0;t<16;++t){
uint32_t x_a=next_value(t);
uint32_t b_a[4];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
uint32_t c_a[4];
c_a[0]=next_value(t);
c_a[1]=next_value(t);
c_a[2]=next_value(t);
c_a[3]=next_value(t);
uint32_t a_a[4];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
uint32_t x_b=x_a;
uint32_t b_b[4];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
uint32_t c_b[4];
c_b[0]=c_a[0];
c_b[1]=c_a[1];
c_b[2]=c_a[2];
c_b[3]=c_a[3];
uint32_t a_b[4];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
original(x_a,b_a,c_a,a_a);
kernel(x_b,b_b,c_b,a_b);
assert(!(b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || c_a[0]!=c_b[0] || c_a[1]!=c_b[1] || c_a[2]!=c_b[2] || c_a[3]!=c_b[3] || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3]));
}
return 0;}
