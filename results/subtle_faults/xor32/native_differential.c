#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Four-way XOR reduction. */
uint32_t original(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
    return (s0^s1)^(s2^s3);
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Four-way XOR reduction. */
uint32_t optimized(uint32_t a[32]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
    return (s0^s1)^(s2|s3);
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
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || a_a[16]!=a_b[16] || a_a[17]!=a_b[17] || a_a[18]!=a_b[18] || a_a[19]!=a_b[19] || a_a[20]!=a_b[20] || a_a[21]!=a_b[21] || a_a[22]!=a_b[22] || a_a[23]!=a_b[23] || a_a[24]!=a_b[24] || a_a[25]!=a_b[25] || a_a[26]!=a_b[26] || a_a[27]!=a_b[27] || a_a[28]!=a_b[28] || a_a[29]!=a_b[29] || a_a[30]!=a_b[30] || a_a[31]!=a_b[31]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[32];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=4294967295u;
a_a[3]=2684354559u;
a_a[4]=536870912u;
a_a[5]=1610612736u;
a_a[6]=0u;
a_a[7]=1610612736u;
a_a[8]=1073741824u;
a_a[9]=0u;
a_a[10]=536870912u;
a_a[11]=536870912u;
a_a[12]=0u;
a_a[13]=4294967295u;
a_a[14]=3758096383u;
a_a[15]=3758096383u;
a_a[16]=2684354560u;
a_a[17]=2147483648u;
a_a[18]=3758096383u;
a_a[19]=3758096383u;
a_a[20]=0u;
a_a[21]=0u;
a_a[22]=3758096383u;
a_a[23]=4294967295u;
a_a[24]=1610612736u;
a_a[25]=536870912u;
a_a[26]=3221225471u;
a_a[27]=2684354559u;
a_a[28]=2684354560u;
a_a[29]=2147483648u;
a_a[30]=2684354559u;
a_a[31]=2684354559u;
uint32_t a_b[32];
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=4294967295u;
a_b[3]=2684354559u;
a_b[4]=536870912u;
a_b[5]=1610612736u;
a_b[6]=0u;
a_b[7]=1610612736u;
a_b[8]=1073741824u;
a_b[9]=0u;
a_b[10]=536870912u;
a_b[11]=536870912u;
a_b[12]=0u;
a_b[13]=4294967295u;
a_b[14]=3758096383u;
a_b[15]=3758096383u;
a_b[16]=2684354560u;
a_b[17]=2147483648u;
a_b[18]=3758096383u;
a_b[19]=3758096383u;
a_b[20]=0u;
a_b[21]=0u;
a_b[22]=3758096383u;
a_b[23]=4294967295u;
a_b[24]=1610612736u;
a_b[25]=536870912u;
a_b[26]=3221225471u;
a_b[27]=2684354559u;
a_b[28]=2684354560u;
a_b[29]=2147483648u;
a_b[30]=2684354559u;
a_b[31]=2684354559u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || a_a[16]!=a_b[16] || a_a[17]!=a_b[17] || a_a[18]!=a_b[18] || a_a[19]!=a_b[19] || a_a[20]!=a_b[20] || a_a[21]!=a_b[21] || a_a[22]!=a_b[22] || a_a[23]!=a_b[23] || a_a[24]!=a_b[24] || a_a[25]!=a_b[25] || a_a[26]!=a_b[26] || a_a[27]!=a_b[27] || a_a[28]!=a_b[28] || a_a[29]!=a_b[29] || a_a[30]!=a_b[30] || a_a[31]!=a_b[31]);
witness_agrees=1;
witness_agrees &= (a_a[0]==0u && a_b[0]==0u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==4294967295u && a_b[2]==4294967295u);
witness_agrees &= (a_a[3]==2684354559u && a_b[3]==2684354559u);
witness_agrees &= (a_a[4]==536870912u && a_b[4]==536870912u);
witness_agrees &= (a_a[5]==1610612736u && a_b[5]==1610612736u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==1610612736u && a_b[7]==1610612736u);
witness_agrees &= (a_a[8]==1073741824u && a_b[8]==1073741824u);
witness_agrees &= (a_a[9]==0u && a_b[9]==0u);
witness_agrees &= (a_a[10]==536870912u && a_b[10]==536870912u);
witness_agrees &= (a_a[11]==536870912u && a_b[11]==536870912u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==4294967295u && a_b[13]==4294967295u);
witness_agrees &= (a_a[14]==3758096383u && a_b[14]==3758096383u);
witness_agrees &= (a_a[15]==3758096383u && a_b[15]==3758096383u);
witness_agrees &= (a_a[16]==2684354560u && a_b[16]==2684354560u);
witness_agrees &= (a_a[17]==2147483648u && a_b[17]==2147483648u);
witness_agrees &= (a_a[18]==3758096383u && a_b[18]==3758096383u);
witness_agrees &= (a_a[19]==3758096383u && a_b[19]==3758096383u);
witness_agrees &= (a_a[20]==0u && a_b[20]==0u);
witness_agrees &= (a_a[21]==0u && a_b[21]==0u);
witness_agrees &= (a_a[22]==3758096383u && a_b[22]==3758096383u);
witness_agrees &= (a_a[23]==4294967295u && a_b[23]==4294967295u);
witness_agrees &= (a_a[24]==1610612736u && a_b[24]==1610612736u);
witness_agrees &= (a_a[25]==536870912u && a_b[25]==536870912u);
witness_agrees &= (a_a[26]==3221225471u && a_b[26]==3221225471u);
witness_agrees &= (a_a[27]==2684354559u && a_b[27]==2684354559u);
witness_agrees &= (a_a[28]==2684354560u && a_b[28]==2684354560u);
witness_agrees &= (a_a[29]==2147483648u && a_b[29]==2147483648u);
witness_agrees &= (a_a[30]==2684354559u && a_b[30]==2684354559u);
witness_agrees &= (a_a[31]==2684354559u && a_b[31]==2684354559u);
witness_agrees &= (ret_a==3221225471u && ret_b==2684354559u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
