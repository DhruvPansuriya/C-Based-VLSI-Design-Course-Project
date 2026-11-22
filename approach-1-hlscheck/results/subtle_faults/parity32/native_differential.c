#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   XOR-fold parity. */
uint32_t original(uint32_t x) {
    x^=x>>16;x^=x>>8;x^=x>>4;x^=x>>2;x^=x>>1;return x&1u;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   XOR-fold parity. */
uint32_t optimized(uint32_t x) {
    x^=x>>16;x^=x>>7;x^=x>>4;x^=x>>2;x^=x>>1;return x&1u;
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
uint32_t x_a=1602027391u;
uint32_t x_b=1602027391u;
uint32_t ret_a=original(x_a);
uint32_t ret_b=optimized(x_b);
witness_mismatch=(ret_a!=ret_b);
witness_agrees=1;
witness_agrees &= (ret_a==0u && ret_b==1u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
