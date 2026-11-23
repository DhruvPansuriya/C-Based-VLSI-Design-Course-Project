#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

uint32_t original(uint32_t x, uint32_t y, uint32_t z) {
    return x * y + x * z;
}

#include <stdint.h>

/* LLM rewrite: distributive factoring, valid in the uint32_t ring. */
uint32_t optimized(uint32_t x, uint32_t y, uint32_t z) {
    return x * (y + z);
}

#include <stdint.h>

/* Seeded negative control: invalid factoring. */
uint32_t buggy(uint32_t x, uint32_t y, uint32_t z) {
    return x * y + z;
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
unsigned failures=0;
for(unsigned t=0;t<264;++t){
uint32_t x_a=next_value(t);
uint32_t y_a=next_value(t);
uint32_t z_a=next_value(t);
uint32_t x_b=x_a;
uint32_t y_b=y_a;
uint32_t z_b=z_a;
uint32_t ret_a=original(x_a,y_a,z_a);
uint32_t ret_b=optimized(x_b,y_b,z_b);
if(ret_a!=ret_b) ++failures;
}
{
uint32_t x_a=269051746u;
uint32_t y_a=0u;
uint32_t z_a=2998257497u;
uint32_t x_b=269051746u;
uint32_t y_b=0u;
uint32_t z_b=2998257497u;
uint32_t ret_a=original(x_a,y_a,z_a);
uint32_t ret_b=buggy(x_b,y_b,z_b);
unsigned witness_mismatch=(ret_a!=ret_b);
unsigned witness_agrees=1;
witness_agrees &= (ret_a==518790930u && ret_b==2998257497u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
