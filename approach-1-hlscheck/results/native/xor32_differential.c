#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[32]) {
    uint32_t sum=0u;for(int i=0;i<32;i++) sum^=a[i];return sum;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Four-way XOR reduction. */
uint32_t optimized(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
    return (s0^s1)^(s2^s3);
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
    return ((s0^s1)^(s2^s3))^1u;
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
uint32_t a_a[32];
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
a_a[16]=next_value(t);
a_a[17]=next_value(t);
a_a[18]=next_value(t);
a_a[19]=next_value(t);
a_a[20]=next_value(t);
a_a[21]=next_value(t);
a_a[22]=next_value(t);
a_a[23]=next_value(t);
a_a[24]=next_value(t);
a_a[25]=next_value(t);
a_a[26]=next_value(t);
a_a[27]=next_value(t);
a_a[28]=next_value(t);
a_a[29]=next_value(t);
a_a[30]=next_value(t);
a_a[31]=next_value(t);
uint32_t a_b[32];
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
a_b[16]=a_a[16];
a_b[17]=a_a[17];
a_b[18]=a_a[18];
a_b[19]=a_a[19];
a_b[20]=a_a[20];
a_b[21]=a_a[21];
a_b[22]=a_a[22];
a_b[23]=a_a[23];
a_b[24]=a_a[24];
a_b[25]=a_a[25];
a_b[26]=a_a[26];
a_b[27]=a_a[27];
a_b[28]=a_a[28];
a_b[29]=a_a[29];
a_b[30]=a_a[30];
a_b[31]=a_a[31];
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || a_a[16]!=a_b[16] || a_a[17]!=a_b[17] || a_a[18]!=a_b[18] || a_a[19]!=a_b[19] || a_a[20]!=a_b[20] || a_a[21]!=a_b[21] || a_a[22]!=a_b[22] || a_a[23]!=a_b[23] || a_a[24]!=a_b[24] || a_a[25]!=a_b[25] || a_a[26]!=a_b[26] || a_a[27]!=a_b[27] || a_a[28]!=a_b[28] || a_a[29]!=a_b[29] || a_a[30]!=a_b[30] || a_a[31]!=a_b[31]) ++failures;
}
{
uint32_t a_a[32];
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
a_a[16]=0u;
a_a[17]=0u;
a_a[18]=0u;
a_a[19]=0u;
a_a[20]=0u;
a_a[21]=0u;
a_a[22]=0u;
a_a[23]=0u;
a_a[24]=0u;
a_a[25]=0u;
a_a[26]=0u;
a_a[27]=0u;
a_a[28]=0u;
a_a[29]=0u;
a_a[30]=0u;
a_a[31]=0u;
uint32_t a_b[32];
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
a_b[16]=0u;
a_b[17]=0u;
a_b[18]=0u;
a_b[19]=0u;
a_b[20]=0u;
a_b[21]=0u;
a_b[22]=0u;
a_b[23]=0u;
a_b[24]=0u;
a_b[25]=0u;
a_b[26]=0u;
a_b[27]=0u;
a_b[28]=0u;
a_b[29]=0u;
a_b[30]=0u;
a_b[31]=0u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=buggy(a_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || a_a[16]!=a_b[16] || a_a[17]!=a_b[17] || a_a[18]!=a_b[18] || a_a[19]!=a_b[19] || a_a[20]!=a_b[20] || a_a[21]!=a_b[21] || a_a[22]!=a_b[22] || a_a[23]!=a_b[23] || a_a[24]!=a_b[24] || a_a[25]!=a_b[25] || a_a[26]!=a_b[26] || a_a[27]!=a_b[27] || a_a[28]!=a_b[28] || a_a[29]!=a_b[29] || a_a[30]!=a_b[30] || a_a[31]!=a_b[31]);
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
witness_agrees &= (a_a[16]==0u && a_b[16]==0u);
witness_agrees &= (a_a[17]==0u && a_b[17]==0u);
witness_agrees &= (a_a[18]==0u && a_b[18]==0u);
witness_agrees &= (a_a[19]==0u && a_b[19]==0u);
witness_agrees &= (a_a[20]==0u && a_b[20]==0u);
witness_agrees &= (a_a[21]==0u && a_b[21]==0u);
witness_agrees &= (a_a[22]==0u && a_b[22]==0u);
witness_agrees &= (a_a[23]==0u && a_b[23]==0u);
witness_agrees &= (a_a[24]==0u && a_b[24]==0u);
witness_agrees &= (a_a[25]==0u && a_b[25]==0u);
witness_agrees &= (a_a[26]==0u && a_b[26]==0u);
witness_agrees &= (a_a[27]==0u && a_b[27]==0u);
witness_agrees &= (a_a[28]==0u && a_b[28]==0u);
witness_agrees &= (a_a[29]==0u && a_b[29]==0u);
witness_agrees &= (a_a[30]==0u && a_b[30]==0u);
witness_agrees &= (a_a[31]==0u && a_b[31]==0u);
witness_agrees &= (ret_a==0u && ret_b==1u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
