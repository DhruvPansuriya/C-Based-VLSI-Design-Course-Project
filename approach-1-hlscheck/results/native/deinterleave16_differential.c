#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++) even[i]=a[2*i];for(int j=0;j<8;j++) odd[j]=a[2*j+1];
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Fuse even/odd extraction loops. */
void optimized(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t a[16], uint32_t even[8], uint32_t odd[8]) {
    for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}
    even[0]^=1u;
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
uint32_t a_a[16];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
a_a[4]=next_value(t);
a_a[5]=next_value(t);
a_a[6]=next_value(t);
a_a[7]=next_value(t);
a_a[8]=next_value(t);
a_a[9]=next_value(t);
a_a[10]=next_value(t);
a_a[11]=next_value(t);
a_a[12]=next_value(t);
a_a[13]=next_value(t);
a_a[14]=next_value(t);
a_a[15]=next_value(t);
uint32_t even_a[8];
even_a[0]=next_value(t);
even_a[1]=next_value(t);
even_a[2]=next_value(t);
even_a[3]=next_value(t);
even_a[4]=next_value(t);
even_a[5]=next_value(t);
even_a[6]=next_value(t);
even_a[7]=next_value(t);
uint32_t odd_a[8];
odd_a[0]=next_value(t);
odd_a[1]=next_value(t);
odd_a[2]=next_value(t);
odd_a[3]=next_value(t);
odd_a[4]=next_value(t);
odd_a[5]=next_value(t);
odd_a[6]=next_value(t);
odd_a[7]=next_value(t);
uint32_t a_b[16];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
a_b[8]=a_a[8];
a_b[9]=a_a[9];
a_b[10]=a_a[10];
a_b[11]=a_a[11];
a_b[12]=a_a[12];
a_b[13]=a_a[13];
a_b[14]=a_a[14];
a_b[15]=a_a[15];
uint32_t even_b[8];
even_b[0]=even_a[0];
even_b[1]=even_a[1];
even_b[2]=even_a[2];
even_b[3]=even_a[3];
even_b[4]=even_a[4];
even_b[5]=even_a[5];
even_b[6]=even_a[6];
even_b[7]=even_a[7];
uint32_t odd_b[8];
odd_b[0]=odd_a[0];
odd_b[1]=odd_a[1];
odd_b[2]=odd_a[2];
odd_b[3]=odd_a[3];
odd_b[4]=odd_a[4];
odd_b[5]=odd_a[5];
odd_b[6]=odd_a[6];
odd_b[7]=odd_a[7];
original(a_a,even_a,odd_a);
optimized(a_b,even_b,odd_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || even_a[0]!=even_b[0] || even_a[1]!=even_b[1] || even_a[2]!=even_b[2] || even_a[3]!=even_b[3] || even_a[4]!=even_b[4] || even_a[5]!=even_b[5] || even_a[6]!=even_b[6] || even_a[7]!=even_b[7] || odd_a[0]!=odd_b[0] || odd_a[1]!=odd_b[1] || odd_a[2]!=odd_b[2] || odd_a[3]!=odd_b[3] || odd_a[4]!=odd_b[4] || odd_a[5]!=odd_b[5] || odd_a[6]!=odd_b[6] || odd_a[7]!=odd_b[7]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=0u;
a_a[3]=0u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
a_a[8]=0u;
a_a[9]=0u;
a_a[10]=0u;
a_a[11]=0u;
a_a[12]=0u;
a_a[13]=0u;
a_a[14]=0u;
a_a[15]=0u;
uint32_t even_a[8];
even_a[0]=0u;
even_a[1]=0u;
even_a[2]=0u;
even_a[3]=0u;
even_a[4]=0u;
even_a[5]=0u;
even_a[6]=0u;
even_a[7]=0u;
uint32_t odd_a[8];
odd_a[0]=0u;
odd_a[1]=0u;
odd_a[2]=0u;
odd_a[3]=0u;
odd_a[4]=0u;
odd_a[5]=0u;
odd_a[6]=0u;
odd_a[7]=0u;
uint32_t a_b[16];
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=0u;
a_b[3]=0u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
a_b[8]=0u;
a_b[9]=0u;
a_b[10]=0u;
a_b[11]=0u;
a_b[12]=0u;
a_b[13]=0u;
a_b[14]=0u;
a_b[15]=0u;
uint32_t even_b[8];
even_b[0]=0u;
even_b[1]=0u;
even_b[2]=0u;
even_b[3]=0u;
even_b[4]=0u;
even_b[5]=0u;
even_b[6]=0u;
even_b[7]=0u;
uint32_t odd_b[8];
odd_b[0]=0u;
odd_b[1]=0u;
odd_b[2]=0u;
odd_b[3]=0u;
odd_b[4]=0u;
odd_b[5]=0u;
odd_b[6]=0u;
odd_b[7]=0u;
original(a_a,even_a,odd_a);
buggy(a_b,even_b,odd_b);
unsigned witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || even_a[0]!=even_b[0] || even_a[1]!=even_b[1] || even_a[2]!=even_b[2] || even_a[3]!=even_b[3] || even_a[4]!=even_b[4] || even_a[5]!=even_b[5] || even_a[6]!=even_b[6] || even_a[7]!=even_b[7] || odd_a[0]!=odd_b[0] || odd_a[1]!=odd_b[1] || odd_a[2]!=odd_b[2] || odd_a[3]!=odd_b[3] || odd_a[4]!=odd_b[4] || odd_a[5]!=odd_b[5] || odd_a[6]!=odd_b[6] || odd_a[7]!=odd_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==0u && a_b[0]==0u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (a_a[8]==0u && a_b[8]==0u);
witness_agrees &= (a_a[9]==0u && a_b[9]==0u);
witness_agrees &= (a_a[10]==0u && a_b[10]==0u);
witness_agrees &= (a_a[11]==0u && a_b[11]==0u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==0u && a_b[13]==0u);
witness_agrees &= (a_a[14]==0u && a_b[14]==0u);
witness_agrees &= (a_a[15]==0u && a_b[15]==0u);
witness_agrees &= (even_a[0]==0u && even_b[0]==1u);
witness_agrees &= (even_a[1]==0u && even_b[1]==0u);
witness_agrees &= (even_a[2]==0u && even_b[2]==0u);
witness_agrees &= (even_a[3]==0u && even_b[3]==0u);
witness_agrees &= (even_a[4]==0u && even_b[4]==0u);
witness_agrees &= (even_a[5]==0u && even_b[5]==0u);
witness_agrees &= (even_a[6]==0u && even_b[6]==0u);
witness_agrees &= (even_a[7]==0u && even_b[7]==0u);
witness_agrees &= (odd_a[0]==0u && odd_b[0]==0u);
witness_agrees &= (odd_a[1]==0u && odd_b[1]==0u);
witness_agrees &= (odd_a[2]==0u && odd_b[2]==0u);
witness_agrees &= (odd_a[3]==0u && odd_b[3]==0u);
witness_agrees &= (odd_a[4]==0u && odd_b[4]==0u);
witness_agrees &= (odd_a[5]==0u && odd_b[5]==0u);
witness_agrees &= (odd_a[6]==0u && odd_b[6]==0u);
witness_agrees &= (odd_a[7]==0u && odd_b[7]==0u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
