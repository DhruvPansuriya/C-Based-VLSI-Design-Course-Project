#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t original(uint32_t a[8]) {
    uint32_t sum = a[0] * 3u;
    sum += a[1] * 5u;
    sum += a[2] * 7u;
    sum += a[3] * 11u;
    sum += a[4] * 11u;
    sum += a[5] * 7u;
    sum += a[6] * 5u;
    sum += a[7] * 3u;
    return sum;
}

#include <stdint.h>

/* LLM rewrite: exploit coefficient symmetry through pre-addition. */
uint32_t optimized(uint32_t a[8]) {
    return (a[0] + a[7]) * 3u + (a[1] + a[6]) * 5u
         + (a[2] + a[5]) * 7u + (a[3] + a[4]) * 11u;
}

#include <stdint.h>

/* Seeded negative control: wrong symmetric coefficient. */
uint32_t buggy(uint32_t a[8]) {
    return (a[0] + a[7]) * 3u + (a[1] + a[6]) * 5u
         + (a[2] + a[5]) * 8u + (a[3] + a[4]) * 11u;
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
uint32_t a_a[8];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
a_a[4]=next_value(t);
a_a[5]=next_value(t);
a_a[6]=next_value(t);
a_a[7]=next_value(t);
uint32_t a_b[8];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]) ++failures;
}
{
uint32_t a_a[8];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=4294967295u;
a_a[3]=0u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
uint32_t a_b[8];
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=4294967295u;
a_b[3]=0u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=buggy(a_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==0u && a_b[0]==0u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==4294967295u && a_b[2]==4294967295u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (ret_a==4294967289u && ret_b==4294967288u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
