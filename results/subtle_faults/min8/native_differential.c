#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Balanced comparison tree. */
uint32_t original(uint32_t a[8]) {
    uint32_t p0=a[0]<a[1]?a[0]:a[1];
    uint32_t p1=a[2]<a[3]?a[2]:a[3];
    uint32_t p2=a[4]<a[5]?a[4]:a[5];
    uint32_t p3=a[6]<a[7]?a[6]:a[7];
    uint32_t q0=p0<p1?p0:p1;uint32_t q1=p2<p3?p2:p3;return q0<q1?q0:q1;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Balanced comparison tree. */
uint32_t optimized(uint32_t a[8]) {
    uint32_t p0=a[0]<a[1]?a[0]:a[1];
    uint32_t p1=a[2]<a[3]?a[2]:a[3];
    uint32_t p2=a[4]<a[5]?a[4]:a[5];
    uint32_t p3=a[6]<a[7]?a[6]:a[7];
    uint32_t q0=p0<p1?p0:p1;uint32_t q1=p2<p3?p2:p3;return q0>q1?q0:q1;
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
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[8];
a_a[0]=4267524608u;
a_a[1]=4160748543u;
a_a[2]=4278190079u;
a_a[3]=2147483649u;
a_a[4]=2147483646u;
a_a[5]=2147483648u;
a_a[6]=2147483647u;
a_a[7]=2147483648u;
uint32_t a_b[8];
a_b[0]=4267524608u;
a_b[1]=4160748543u;
a_b[2]=4278190079u;
a_b[3]=2147483649u;
a_b[4]=2147483646u;
a_b[5]=2147483648u;
a_b[6]=2147483647u;
a_b[7]=2147483648u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]);
witness_agrees=1;
witness_agrees &= (a_a[0]==4267524608u && a_b[0]==4267524608u);
witness_agrees &= (a_a[1]==4160748543u && a_b[1]==4160748543u);
witness_agrees &= (a_a[2]==4278190079u && a_b[2]==4278190079u);
witness_agrees &= (a_a[3]==2147483649u && a_b[3]==2147483649u);
witness_agrees &= (a_a[4]==2147483646u && a_b[4]==2147483646u);
witness_agrees &= (a_a[5]==2147483648u && a_b[5]==2147483648u);
witness_agrees &= (a_a[6]==2147483647u && a_b[6]==2147483647u);
witness_agrees &= (a_a[7]==2147483648u && a_b[7]==2147483648u);
witness_agrees &= (ret_a==2147483646u && ret_b==2147483649u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
