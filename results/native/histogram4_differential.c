#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[16], uint32_t out[4]) {
    for(int bin=0;bin<4;bin++){uint32_t count=0u;for(int i=0;i<16;i++) count+=((a[i]&3u)==(uint32_t)bin?1u:0u);out[bin]=count;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Fuse four fixed-bin histogram scans. */
void optimized(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
    out[0]^=1u;
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
uint32_t out_a[4];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
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
uint32_t out_b[4];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
original(a_a,out_a);
optimized(a_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=3u;
a_a[1]=3u;
a_a[2]=3u;
a_a[3]=3u;
a_a[4]=3u;
a_a[5]=3u;
a_a[6]=3u;
a_a[7]=3u;
a_a[8]=3u;
a_a[9]=3u;
a_a[10]=3u;
a_a[11]=3u;
a_a[12]=3u;
a_a[13]=3u;
a_a[14]=3u;
a_a[15]=3u;
uint32_t out_a[4];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
uint32_t a_b[16];
a_b[0]=3u;
a_b[1]=3u;
a_b[2]=3u;
a_b[3]=3u;
a_b[4]=3u;
a_b[5]=3u;
a_b[6]=3u;
a_b[7]=3u;
a_b[8]=3u;
a_b[9]=3u;
a_b[10]=3u;
a_b[11]=3u;
a_b[12]=3u;
a_b[13]=3u;
a_b[14]=3u;
a_b[15]=3u;
uint32_t out_b[4];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
original(a_a,out_a);
buggy(a_b,out_b);
unsigned witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==3u && a_b[0]==3u);
witness_agrees &= (a_a[1]==3u && a_b[1]==3u);
witness_agrees &= (a_a[2]==3u && a_b[2]==3u);
witness_agrees &= (a_a[3]==3u && a_b[3]==3u);
witness_agrees &= (a_a[4]==3u && a_b[4]==3u);
witness_agrees &= (a_a[5]==3u && a_b[5]==3u);
witness_agrees &= (a_a[6]==3u && a_b[6]==3u);
witness_agrees &= (a_a[7]==3u && a_b[7]==3u);
witness_agrees &= (a_a[8]==3u && a_b[8]==3u);
witness_agrees &= (a_a[9]==3u && a_b[9]==3u);
witness_agrees &= (a_a[10]==3u && a_b[10]==3u);
witness_agrees &= (a_a[11]==3u && a_b[11]==3u);
witness_agrees &= (a_a[12]==3u && a_b[12]==3u);
witness_agrees &= (a_a[13]==3u && a_b[13]==3u);
witness_agrees &= (a_a[14]==3u && a_b[14]==3u);
witness_agrees &= (a_a[15]==3u && a_b[15]==3u);
witness_agrees &= (out_a[0]==0u && out_b[0]==1u);
witness_agrees &= (out_a[1]==0u && out_b[1]==0u);
witness_agrees &= (out_a[2]==0u && out_b[2]==0u);
witness_agrees &= (out_a[3]==16u && out_b[3]==16u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
