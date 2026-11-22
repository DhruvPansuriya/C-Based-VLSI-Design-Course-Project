#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return a*x*x+b*x+c;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Horner-form quadratic evaluation. */
uint32_t optimized(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return (a*x+b)*x+c;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return ((a*x+b)*x+c)^1u;
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
uint32_t a_a=next_value(t);
uint32_t b_a=next_value(t);
uint32_t c_a=next_value(t);
uint32_t x_b=x_a;
uint32_t a_b=a_a;
uint32_t b_b=b_a;
uint32_t c_b=c_a;
uint32_t ret_a=original(x_a,a_a,b_a,c_a);
uint32_t ret_b=optimized(x_b,a_b,b_b,c_b);
if(ret_a!=ret_b) ++failures;
}
{
uint32_t x_a=3871326207u;
uint32_t a_a=1639317501u;
uint32_t b_a=223437116u;
uint32_t c_a=235403202u;
uint32_t x_b=3871326207u;
uint32_t a_b=1639317501u;
uint32_t b_b=223437116u;
uint32_t c_b=235403202u;
uint32_t ret_a=original(x_a,a_a,b_a,c_a);
uint32_t ret_b=buggy(x_b,a_b,b_b,c_b);
unsigned witness_mismatch=(ret_a!=ret_b);
unsigned witness_agrees=1;
witness_agrees &= (ret_a==396105347u && ret_b==396105346u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
