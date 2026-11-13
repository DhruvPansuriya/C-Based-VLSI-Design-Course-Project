#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
uint32_t original(uint32_t x, uint32_t y){return x/2u+y/2u+((x&1u)+(y&1u))/2u;}

#include <stdint.h>
uint32_t optimized(uint32_t x, uint32_t y){return (x+y)/2u;}


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
uint32_t y_a=next_value(t);
uint32_t x_b=x_a;
uint32_t y_b=y_a;
uint32_t ret_a=original(x_a,y_a);
uint32_t ret_b=optimized(x_b,y_b);
if(ret_a!=ret_b){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t x_a=2408006928u;
uint32_t y_a=3270866349u;
uint32_t x_b=2408006928u;
uint32_t y_b=3270866349u;
uint32_t ret_a=original(x_a,y_a);
uint32_t ret_b=optimized(x_b,y_b);
witness_mismatch=(ret_a!=ret_b);
witness_agrees=1;
witness_agrees &= (ret_a==2839436638u && ret_b==691952990u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
