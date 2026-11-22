#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[8], uint32_t b[8]) {
    uint32_t sum=0u;for(int i=0;i<8;i++){uint32_t d=a[i]-b[i];sum+=d*d;}return sum;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Expand squared distance into three reductions. */
uint32_t optimized(uint32_t a[8], uint32_t b[8]) {
    uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return aa+bb-2u*ab;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[8], uint32_t b[8]) {
    uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return (aa+bb-2u*ab)^1u;
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
uint32_t b_a[8];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
b_a[4]=next_value(t);
b_a[5]=next_value(t);
b_a[6]=next_value(t);
b_a[7]=next_value(t);
uint32_t a_b[8];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
uint32_t b_b[8];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
b_b[4]=b_a[4];
b_b[5]=b_a[5];
b_b[6]=b_a[6];
b_b[7]=b_a[7];
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=optimized(a_b,b_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7]) ++failures;
}
{
uint32_t a_a[8];
a_a[0]=774896051u;
a_a[1]=3391947921u;
a_a[2]=1896672033u;
a_a[3]=1566365056u;
a_a[4]=1538420970u;
a_a[5]=630374898u;
a_a[6]=957560520u;
a_a[7]=3489669143u;
uint32_t b_a[8];
b_a[0]=520657847u;
b_a[1]=1040961964u;
b_a[2]=330055802u;
b_a[3]=4238291459u;
b_a[4]=1231134529u;
b_a[5]=1006659827u;
b_a[6]=955844963u;
b_a[7]=1903249673u;
uint32_t a_b[8];
a_b[0]=774896051u;
a_b[1]=3391947921u;
a_b[2]=1896672033u;
a_b[3]=1566365056u;
a_b[4]=1538420970u;
a_b[5]=630374898u;
a_b[6]=957560520u;
a_b[7]=3489669143u;
uint32_t b_b[8];
b_b[0]=520657847u;
b_b[1]=1040961964u;
b_b[2]=330055802u;
b_b[3]=4238291459u;
b_b[4]=1231134529u;
b_b[5]=1006659827u;
b_b[6]=955844963u;
b_b[7]=1903249673u;
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=buggy(a_b,b_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==774896051u && a_b[0]==774896051u);
witness_agrees &= (a_a[1]==3391947921u && a_b[1]==3391947921u);
witness_agrees &= (a_a[2]==1896672033u && a_b[2]==1896672033u);
witness_agrees &= (a_a[3]==1566365056u && a_b[3]==1566365056u);
witness_agrees &= (a_a[4]==1538420970u && a_b[4]==1538420970u);
witness_agrees &= (a_a[5]==630374898u && a_b[5]==630374898u);
witness_agrees &= (a_a[6]==957560520u && a_b[6]==957560520u);
witness_agrees &= (a_a[7]==3489669143u && a_b[7]==3489669143u);
witness_agrees &= (b_a[0]==520657847u && b_b[0]==520657847u);
witness_agrees &= (b_a[1]==1040961964u && b_b[1]==1040961964u);
witness_agrees &= (b_a[2]==330055802u && b_b[2]==330055802u);
witness_agrees &= (b_a[3]==4238291459u && b_b[3]==4238291459u);
witness_agrees &= (b_a[4]==1231134529u && b_b[4]==1231134529u);
witness_agrees &= (b_a[5]==1006659827u && b_b[5]==1006659827u);
witness_agrees &= (b_a[6]==955844963u && b_b[6]==955844963u);
witness_agrees &= (b_a[7]==1903249673u && b_b[7]==1903249673u);
witness_agrees &= (ret_a==1548800786u && ret_b==1548800787u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
