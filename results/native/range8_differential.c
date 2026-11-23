#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++) low=a[i]<low?a[i]:low;
    for(int j=1;j<8;j++) high=a[j]>high?a[j]:high;
    return high-low;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Fuse minimum and maximum scans. */
uint32_t optimized(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
    return high-low;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[8]) {
    uint32_t low=a[0],high=a[0];
    for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
    return (high-low)^1u;
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
a_a[0]=3182658064u;
a_a[1]=2894911466u;
a_a[2]=3368504813u;
a_a[3]=3297202162u;
a_a[4]=3100332446u;
a_a[5]=1637247901u;
a_a[6]=3544845245u;
a_a[7]=470557952u;
uint32_t a_b[8];
a_b[0]=3182658064u;
a_b[1]=2894911466u;
a_b[2]=3368504813u;
a_b[3]=3297202162u;
a_b[4]=3100332446u;
a_b[5]=1637247901u;
a_b[6]=3544845245u;
a_b[7]=470557952u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=buggy(a_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==3182658064u && a_b[0]==3182658064u);
witness_agrees &= (a_a[1]==2894911466u && a_b[1]==2894911466u);
witness_agrees &= (a_a[2]==3368504813u && a_b[2]==3368504813u);
witness_agrees &= (a_a[3]==3297202162u && a_b[3]==3297202162u);
witness_agrees &= (a_a[4]==3100332446u && a_b[4]==3100332446u);
witness_agrees &= (a_a[5]==1637247901u && a_b[5]==1637247901u);
witness_agrees &= (a_a[6]==3544845245u && a_b[6]==3544845245u);
witness_agrees &= (a_a[7]==470557952u && a_b[7]==470557952u);
witness_agrees &= (ret_a==3074287293u && ret_b==3074287292u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
