#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[16], uint32_t b[16]) {
    uint32_t sum=0u;
    for(int i=0;i<16;i++) sum+=a[i]*b[i];
    return sum;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Four independent dot-product accumulators. */
uint32_t optimized(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
    return (s0+s1)+(s2+s3);
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
    return ((s0+s1)+(s2+s3))^1u;
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
uint32_t b_a[16];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
b_a[4]=next_value(t);
b_a[5]=next_value(t);
b_a[6]=next_value(t);
b_a[7]=next_value(t);
b_a[8]=next_value(t);
b_a[9]=next_value(t);
b_a[10]=next_value(t);
b_a[11]=next_value(t);
b_a[12]=next_value(t);
b_a[13]=next_value(t);
b_a[14]=next_value(t);
b_a[15]=next_value(t);
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
uint32_t b_b[16];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
b_b[4]=b_a[4];
b_b[5]=b_a[5];
b_b[6]=b_a[6];
b_b[7]=b_a[7];
b_b[8]=b_a[8];
b_b[9]=b_a[9];
b_b[10]=b_a[10];
b_b[11]=b_a[11];
b_b[12]=b_a[12];
b_b[13]=b_a[13];
b_b[14]=b_a[14];
b_b[15]=b_a[15];
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=optimized(a_b,b_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=3311957638u;
a_a[1]=289112064u;
a_a[2]=1124330150u;
a_a[3]=2774958080u;
a_a[4]=19415065u;
a_a[5]=470602419u;
a_a[6]=8705609u;
a_a[7]=3379867804u;
a_a[8]=4095804539u;
a_a[9]=269771919u;
a_a[10]=101017728u;
a_a[11]=24184994u;
a_a[12]=200606906u;
a_a[13]=3234801505u;
a_a[14]=606077938u;
a_a[15]=475025894u;
uint32_t b_a[16];
b_a[0]=1511939119u;
b_a[1]=71509888u;
b_a[2]=327638886u;
b_a[3]=409950783u;
b_a[4]=287585600u;
b_a[5]=1591394112u;
b_a[6]=2764771328u;
b_a[7]=624671381u;
b_a[8]=927124663u;
b_a[9]=2562719744u;
b_a[10]=105900451u;
b_a[11]=2089637956u;
b_a[12]=359652480u;
b_a[13]=1349075243u;
b_a[14]=1442896283u;
b_a[15]=1149665280u;
uint32_t a_b[16];
a_b[0]=3311957638u;
a_b[1]=289112064u;
a_b[2]=1124330150u;
a_b[3]=2774958080u;
a_b[4]=19415065u;
a_b[5]=470602419u;
a_b[6]=8705609u;
a_b[7]=3379867804u;
a_b[8]=4095804539u;
a_b[9]=269771919u;
a_b[10]=101017728u;
a_b[11]=24184994u;
a_b[12]=200606906u;
a_b[13]=3234801505u;
a_b[14]=606077938u;
a_b[15]=475025894u;
uint32_t b_b[16];
b_b[0]=1511939119u;
b_b[1]=71509888u;
b_b[2]=327638886u;
b_b[3]=409950783u;
b_b[4]=287585600u;
b_b[5]=1591394112u;
b_b[6]=2764771328u;
b_b[7]=624671381u;
b_b[8]=927124663u;
b_b[9]=2562719744u;
b_b[10]=105900451u;
b_b[11]=2089637956u;
b_b[12]=359652480u;
b_b[13]=1349075243u;
b_b[14]=1442896283u;
b_b[15]=1149665280u;
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=buggy(a_b,b_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==3311957638u && a_b[0]==3311957638u);
witness_agrees &= (a_a[1]==289112064u && a_b[1]==289112064u);
witness_agrees &= (a_a[2]==1124330150u && a_b[2]==1124330150u);
witness_agrees &= (a_a[3]==2774958080u && a_b[3]==2774958080u);
witness_agrees &= (a_a[4]==19415065u && a_b[4]==19415065u);
witness_agrees &= (a_a[5]==470602419u && a_b[5]==470602419u);
witness_agrees &= (a_a[6]==8705609u && a_b[6]==8705609u);
witness_agrees &= (a_a[7]==3379867804u && a_b[7]==3379867804u);
witness_agrees &= (a_a[8]==4095804539u && a_b[8]==4095804539u);
witness_agrees &= (a_a[9]==269771919u && a_b[9]==269771919u);
witness_agrees &= (a_a[10]==101017728u && a_b[10]==101017728u);
witness_agrees &= (a_a[11]==24184994u && a_b[11]==24184994u);
witness_agrees &= (a_a[12]==200606906u && a_b[12]==200606906u);
witness_agrees &= (a_a[13]==3234801505u && a_b[13]==3234801505u);
witness_agrees &= (a_a[14]==606077938u && a_b[14]==606077938u);
witness_agrees &= (a_a[15]==475025894u && a_b[15]==475025894u);
witness_agrees &= (b_a[0]==1511939119u && b_b[0]==1511939119u);
witness_agrees &= (b_a[1]==71509888u && b_b[1]==71509888u);
witness_agrees &= (b_a[2]==327638886u && b_b[2]==327638886u);
witness_agrees &= (b_a[3]==409950783u && b_b[3]==409950783u);
witness_agrees &= (b_a[4]==287585600u && b_b[4]==287585600u);
witness_agrees &= (b_a[5]==1591394112u && b_b[5]==1591394112u);
witness_agrees &= (b_a[6]==2764771328u && b_b[6]==2764771328u);
witness_agrees &= (b_a[7]==624671381u && b_b[7]==624671381u);
witness_agrees &= (b_a[8]==927124663u && b_b[8]==927124663u);
witness_agrees &= (b_a[9]==2562719744u && b_b[9]==2562719744u);
witness_agrees &= (b_a[10]==105900451u && b_b[10]==105900451u);
witness_agrees &= (b_a[11]==2089637956u && b_b[11]==2089637956u);
witness_agrees &= (b_a[12]==359652480u && b_b[12]==359652480u);
witness_agrees &= (b_a[13]==1349075243u && b_b[13]==1349075243u);
witness_agrees &= (b_a[14]==1442896283u && b_b[14]==1442896283u);
witness_agrees &= (b_a[15]==1149665280u && b_b[15]==1149665280u);
witness_agrees &= (ret_a==2760759248u && ret_b==2760759249u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
