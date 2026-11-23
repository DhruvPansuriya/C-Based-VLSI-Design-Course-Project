#include <stdint.h>
#include <assert.h>
uint32_t kernel(uint32_t x,uint32_t a,uint32_t b,uint32_t c);
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return a*x*x+b*x+c;
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
uint32_t a_a=next_value(t);
uint32_t b_a=next_value(t);
uint32_t c_a=next_value(t);
uint32_t x_b=x_a;
uint32_t a_b=a_a;
uint32_t b_b=b_a;
uint32_t c_b=c_a;
uint32_t ret_a=original(x_a,a_a,b_a,c_a);
uint32_t ret_b=kernel(x_b,a_b,b_b,c_b);
assert(!(ret_a!=ret_b));
}
return 0;}
