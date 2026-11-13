#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;for(int bit=0;bit<8;bit++) total+=(v>>bit)&1u;}return total;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Replace nested bit scans with byte SWAR. */
uint32_t optimized(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);total+=(v+(v>>4))&15u;}return total;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[8], uint32_t b[8]) {
    uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);total+=(v+(v>>4))&15u;}return (total)^1u;
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
a_a[0]=136u;
a_a[1]=1u;
a_a[2]=50u;
a_a[3]=192u;
a_a[4]=0u;
a_a[5]=233u;
a_a[6]=64u;
a_a[7]=12u;
uint32_t b_a[8];
b_a[0]=49u;
b_a[1]=193u;
b_a[2]=72u;
b_a[3]=18u;
b_a[4]=10u;
b_a[5]=18u;
b_a[6]=0u;
b_a[7]=193u;
uint32_t a_b[8];
a_b[0]=136u;
a_b[1]=1u;
a_b[2]=50u;
a_b[3]=192u;
a_b[4]=0u;
a_b[5]=233u;
a_b[6]=64u;
a_b[7]=12u;
uint32_t b_b[8];
b_b[0]=49u;
b_b[1]=193u;
b_b[2]=72u;
b_b[3]=18u;
b_b[4]=10u;
b_b[5]=18u;
b_b[6]=0u;
b_b[7]=193u;
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=buggy(a_b,b_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==136u && a_b[0]==136u);
witness_agrees &= (a_a[1]==1u && a_b[1]==1u);
witness_agrees &= (a_a[2]==50u && a_b[2]==50u);
witness_agrees &= (a_a[3]==192u && a_b[3]==192u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==233u && a_b[5]==233u);
witness_agrees &= (a_a[6]==64u && a_b[6]==64u);
witness_agrees &= (a_a[7]==12u && a_b[7]==12u);
witness_agrees &= (b_a[0]==49u && b_b[0]==49u);
witness_agrees &= (b_a[1]==193u && b_b[1]==193u);
witness_agrees &= (b_a[2]==72u && b_b[2]==72u);
witness_agrees &= (b_a[3]==18u && b_b[3]==18u);
witness_agrees &= (b_a[4]==10u && b_b[4]==10u);
witness_agrees &= (b_a[5]==18u && b_b[5]==18u);
witness_agrees &= (b_a[6]==0u && b_b[6]==0u);
witness_agrees &= (b_a[7]==193u && b_b[7]==193u);
witness_agrees &= (ret_a==31u && ret_b==30u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
