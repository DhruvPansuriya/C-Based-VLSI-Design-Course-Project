#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[8]) {
    uint32_t value=a[0];for(int i=1;i<8;i++) value=a[i]>value?a[i]:value;return value;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Balanced comparison tree. */
uint32_t optimized(uint32_t a[8]) {
    uint32_t p0=a[0]>a[1]?a[0]:a[1];
    uint32_t p1=a[2]>a[3]?a[2]:a[3];
    uint32_t p2=a[4]>a[5]?a[4]:a[5];
    uint32_t p3=a[6]>a[7]?a[6]:a[7];
    uint32_t q0=p0>p1?p0:p1;uint32_t q1=p2>p3?p2:p3;return q0>q1?q0:q1;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[8]) {
    uint32_t p0=a[0]>a[1]?a[0]:a[1];
    uint32_t p1=a[2]>a[3]?a[2]:a[3];
    uint32_t p2=a[4]>a[5]?a[4]:a[5];
    uint32_t p3=a[6]>a[7]?a[6]:a[7];
    uint32_t q0=p0>p1?p0:p1;uint32_t q1=p2>p3?p2:p3;return (q0>q1?q0:q1)^1u;
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
a_a[0]=2353119400u;
a_a[1]=742506664u;
a_a[2]=3544301652u;
a_a[3]=2014323250u;
a_a[4]=2973876308u;
a_a[5]=690528258u;
a_a[6]=594073616u;
a_a[7]=2705967704u;
uint32_t a_b[8];
a_b[0]=2353119400u;
a_b[1]=742506664u;
a_b[2]=3544301652u;
a_b[3]=2014323250u;
a_b[4]=2973876308u;
a_b[5]=690528258u;
a_b[6]=594073616u;
a_b[7]=2705967704u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=buggy(a_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==2353119400u && a_b[0]==2353119400u);
witness_agrees &= (a_a[1]==742506664u && a_b[1]==742506664u);
witness_agrees &= (a_a[2]==3544301652u && a_b[2]==3544301652u);
witness_agrees &= (a_a[3]==2014323250u && a_b[3]==2014323250u);
witness_agrees &= (a_a[4]==2973876308u && a_b[4]==2973876308u);
witness_agrees &= (a_a[5]==690528258u && a_b[5]==690528258u);
witness_agrees &= (a_a[6]==594073616u && a_b[6]==594073616u);
witness_agrees &= (a_a[7]==2705967704u && a_b[7]==2705967704u);
witness_agrees &= (ret_a==3544301652u && ret_b==3544301653u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
