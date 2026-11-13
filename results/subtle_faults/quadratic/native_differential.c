#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Horner-form quadratic evaluation. */
uint32_t original(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return (a*x+b)*x+c;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Horner-form quadratic evaluation. */
uint32_t optimized(uint32_t x, uint32_t a, uint32_t b, uint32_t c) {
    return a*x+b*x+c;
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
unsigned failures=0, first=0;
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
if(ret_a!=ret_b){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t x_a=1445986302u;
uint32_t a_a=201698171u;
uint32_t b_a=0u;
uint32_t c_a=0u;
uint32_t x_b=1445986302u;
uint32_t a_b=201698171u;
uint32_t b_b=0u;
uint32_t c_b=0u;
uint32_t ret_a=original(x_a,a_a,b_a,c_a);
uint32_t ret_b=optimized(x_b,a_b,b_b,c_b);
witness_mismatch=(ret_a!=ret_b);
witness_agrees=1;
witness_agrees &= (ret_a==1272360428u && ret_b==1627695370u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
