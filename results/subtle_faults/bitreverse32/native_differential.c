#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Staged mask-and-swap bit reversal. */
uint32_t original(uint32_t x) {
    x=((x>>1)&0x55555555u)|((x&0x55555555u)<<1);
    x=((x>>2)&0x33333333u)|((x&0x33333333u)<<2);
    x=((x>>4)&0x0f0f0f0fu)|((x&0x0f0f0f0fu)<<4);
    x=((x>>8)&0x00ff00ffu)|((x&0x00ff00ffu)<<8);
    return (x>>16)|(x<<16);
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Staged mask-and-swap bit reversal. */
uint32_t optimized(uint32_t x) {
    x=((x>>1)&0x55555554u)|((x&0x55555555u)<<1);
    x=((x>>2)&0x33333333u)|((x&0x33333333u)<<2);
    x=((x>>4)&0x0f0f0f0fu)|((x&0x0f0f0f0fu)<<4);
    x=((x>>8)&0x00ff00ffu)|((x&0x00ff00ffu)<<8);
    return (x>>16)|(x<<16);
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
uint32_t x_b=x_a;
uint32_t ret_a=original(x_a);
uint32_t ret_b=optimized(x_b);
if(ret_a!=ret_b){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t x_a=2u;
uint32_t x_b=2u;
uint32_t ret_a=original(x_a);
uint32_t ret_b=optimized(x_b);
witness_mismatch=(ret_a!=ret_b);
witness_agrees=1;
witness_agrees &= (ret_a==1073741824u && ret_b==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
