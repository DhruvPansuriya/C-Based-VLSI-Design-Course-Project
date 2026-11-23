#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Four independent dot-product accumulators. */
uint32_t original(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
    return (s0+s1)+(s2+s3);
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Four independent dot-product accumulators. */
uint32_t optimized(uint32_t a[16], uint32_t b[16]) {
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+2]*b[i+3];}
    return (s0+s1)+(s2+s3);
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
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=537133084u;
a_a[3]=1698250832u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=4057975007u;
a_a[7]=1677721600u;
a_a[8]=0u;
a_a[9]=0u;
a_a[10]=179189113u;
a_a[11]=1322427615u;
a_a[12]=0u;
a_a[13]=0u;
a_a[14]=1962933009u;
a_a[15]=1879048192u;
uint32_t b_a[16];
b_a[0]=0u;
b_a[1]=0u;
b_a[2]=0u;
b_a[3]=125552782u;
b_a[4]=0u;
b_a[5]=0u;
b_a[6]=0u;
b_a[7]=3346494793u;
b_a[8]=0u;
b_a[9]=0u;
b_a[10]=0u;
b_a[11]=1537867734u;
b_a[12]=0u;
b_a[13]=0u;
b_a[14]=0u;
b_a[15]=2747923677u;
uint32_t a_b[16];
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=537133084u;
a_b[3]=1698250832u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=4057975007u;
a_b[7]=1677721600u;
a_b[8]=0u;
a_b[9]=0u;
a_b[10]=179189113u;
a_b[11]=1322427615u;
a_b[12]=0u;
a_b[13]=0u;
a_b[14]=1962933009u;
a_b[15]=1879048192u;
uint32_t b_b[16];
b_b[0]=0u;
b_b[1]=0u;
b_b[2]=0u;
b_b[3]=125552782u;
b_b[4]=0u;
b_b[5]=0u;
b_b[6]=0u;
b_b[7]=3346494793u;
b_b[8]=0u;
b_b[9]=0u;
b_b[10]=0u;
b_b[11]=1537867734u;
b_b[12]=0u;
b_b[13]=0u;
b_b[14]=0u;
b_b[15]=2747923677u;
uint32_t ret_a=original(a_a,b_a);
uint32_t ret_b=optimized(a_b,b_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15]);
witness_agrees=1;
witness_agrees &= (a_a[0]==0u && a_b[0]==0u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==537133084u && a_b[2]==537133084u);
witness_agrees &= (a_a[3]==1698250832u && a_b[3]==1698250832u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==4057975007u && a_b[6]==4057975007u);
witness_agrees &= (a_a[7]==1677721600u && a_b[7]==1677721600u);
witness_agrees &= (a_a[8]==0u && a_b[8]==0u);
witness_agrees &= (a_a[9]==0u && a_b[9]==0u);
witness_agrees &= (a_a[10]==179189113u && a_b[10]==179189113u);
witness_agrees &= (a_a[11]==1322427615u && a_b[11]==1322427615u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==0u && a_b[13]==0u);
witness_agrees &= (a_a[14]==1962933009u && a_b[14]==1962933009u);
witness_agrees &= (a_a[15]==1879048192u && a_b[15]==1879048192u);
witness_agrees &= (b_a[0]==0u && b_b[0]==0u);
witness_agrees &= (b_a[1]==0u && b_b[1]==0u);
witness_agrees &= (b_a[2]==0u && b_b[2]==0u);
witness_agrees &= (b_a[3]==125552782u && b_b[3]==125552782u);
witness_agrees &= (b_a[4]==0u && b_b[4]==0u);
witness_agrees &= (b_a[5]==0u && b_b[5]==0u);
witness_agrees &= (b_a[6]==0u && b_b[6]==0u);
witness_agrees &= (b_a[7]==3346494793u && b_b[7]==3346494793u);
witness_agrees &= (b_a[8]==0u && b_b[8]==0u);
witness_agrees &= (b_a[9]==0u && b_b[9]==0u);
witness_agrees &= (b_a[10]==0u && b_b[10]==0u);
witness_agrees &= (b_a[11]==1537867734u && b_b[11]==1537867734u);
witness_agrees &= (b_a[12]==0u && b_b[12]==0u);
witness_agrees &= (b_a[13]==0u && b_b[13]==0u);
witness_agrees &= (b_a[14]==0u && b_b[14]==0u);
witness_agrees &= (b_a[15]==2747923677u && b_b[15]==2747923677u);
witness_agrees &= (ret_a==4244053962u && ret_b==1615320562u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
