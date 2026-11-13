#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained.
   Reference implementation. */
void original(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                uint32_t sum = 0u;
                for (int k = 0; k < 4; k++) {
                    sum += m1[i * 4 + k] * m2[k * 4 + j];
                }
                prod[i * 4 + j] = sum;
            }
        }
}

#include <stdint.h>

/* MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained.
   Keep four row accumulators local during GEMM interchange. */
void optimized(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++){
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int k=0;k<4;k++){uint32_t v=m1[i*4+k];s0+=v*m2[k*4];s1+=v*m2[k*4+1];s2+=v*m2[k*4+2];s3+=v*m2[k*4+3];}
    prod[i*4]=s0;prod[i*4+1]=s1;prod[i*4+2]=s2;prod[i*4+3]=s3;}
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++){
    uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
    for(int k=0;k<4;k++){uint32_t v=m1[i*4+k];s0+=v*m2[k*4];s1+=v*m2[k*4+1];s2+=v*m2[k*4+2];s3+=v*m2[k*4+3];}
    prod[i*4]=s0;prod[i*4+1]=s1;prod[i*4+2]=s2;prod[i*4+3]=s3;}
    prod[0]^=1u;
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
uint32_t m1_a[16];
m1_a[0]=next_value(t);
m1_a[1]=next_value(t);
m1_a[2]=next_value(t);
m1_a[3]=next_value(t);
m1_a[4]=next_value(t);
m1_a[5]=next_value(t);
m1_a[6]=next_value(t);
m1_a[7]=next_value(t);
m1_a[8]=next_value(t);
m1_a[9]=next_value(t);
m1_a[10]=next_value(t);
m1_a[11]=next_value(t);
m1_a[12]=next_value(t);
m1_a[13]=next_value(t);
m1_a[14]=next_value(t);
m1_a[15]=next_value(t);
uint32_t m2_a[16];
m2_a[0]=next_value(t);
m2_a[1]=next_value(t);
m2_a[2]=next_value(t);
m2_a[3]=next_value(t);
m2_a[4]=next_value(t);
m2_a[5]=next_value(t);
m2_a[6]=next_value(t);
m2_a[7]=next_value(t);
m2_a[8]=next_value(t);
m2_a[9]=next_value(t);
m2_a[10]=next_value(t);
m2_a[11]=next_value(t);
m2_a[12]=next_value(t);
m2_a[13]=next_value(t);
m2_a[14]=next_value(t);
m2_a[15]=next_value(t);
uint32_t prod_a[16];
prod_a[0]=next_value(t);
prod_a[1]=next_value(t);
prod_a[2]=next_value(t);
prod_a[3]=next_value(t);
prod_a[4]=next_value(t);
prod_a[5]=next_value(t);
prod_a[6]=next_value(t);
prod_a[7]=next_value(t);
prod_a[8]=next_value(t);
prod_a[9]=next_value(t);
prod_a[10]=next_value(t);
prod_a[11]=next_value(t);
prod_a[12]=next_value(t);
prod_a[13]=next_value(t);
prod_a[14]=next_value(t);
prod_a[15]=next_value(t);
uint32_t m1_b[16];
m1_b[0]=m1_a[0];
m1_b[1]=m1_a[1];
m1_b[2]=m1_a[2];
m1_b[3]=m1_a[3];
m1_b[4]=m1_a[4];
m1_b[5]=m1_a[5];
m1_b[6]=m1_a[6];
m1_b[7]=m1_a[7];
m1_b[8]=m1_a[8];
m1_b[9]=m1_a[9];
m1_b[10]=m1_a[10];
m1_b[11]=m1_a[11];
m1_b[12]=m1_a[12];
m1_b[13]=m1_a[13];
m1_b[14]=m1_a[14];
m1_b[15]=m1_a[15];
uint32_t m2_b[16];
m2_b[0]=m2_a[0];
m2_b[1]=m2_a[1];
m2_b[2]=m2_a[2];
m2_b[3]=m2_a[3];
m2_b[4]=m2_a[4];
m2_b[5]=m2_a[5];
m2_b[6]=m2_a[6];
m2_b[7]=m2_a[7];
m2_b[8]=m2_a[8];
m2_b[9]=m2_a[9];
m2_b[10]=m2_a[10];
m2_b[11]=m2_a[11];
m2_b[12]=m2_a[12];
m2_b[13]=m2_a[13];
m2_b[14]=m2_a[14];
m2_b[15]=m2_a[15];
uint32_t prod_b[16];
prod_b[0]=prod_a[0];
prod_b[1]=prod_a[1];
prod_b[2]=prod_a[2];
prod_b[3]=prod_a[3];
prod_b[4]=prod_a[4];
prod_b[5]=prod_a[5];
prod_b[6]=prod_a[6];
prod_b[7]=prod_a[7];
prod_b[8]=prod_a[8];
prod_b[9]=prod_a[9];
prod_b[10]=prod_a[10];
prod_b[11]=prod_a[11];
prod_b[12]=prod_a[12];
prod_b[13]=prod_a[13];
prod_b[14]=prod_a[14];
prod_b[15]=prod_a[15];
original(m1_a,m2_a,prod_a);
optimized(m1_b,m2_b,prod_b);
if(m1_a[0]!=m1_b[0] || m1_a[1]!=m1_b[1] || m1_a[2]!=m1_b[2] || m1_a[3]!=m1_b[3] || m1_a[4]!=m1_b[4] || m1_a[5]!=m1_b[5] || m1_a[6]!=m1_b[6] || m1_a[7]!=m1_b[7] || m1_a[8]!=m1_b[8] || m1_a[9]!=m1_b[9] || m1_a[10]!=m1_b[10] || m1_a[11]!=m1_b[11] || m1_a[12]!=m1_b[12] || m1_a[13]!=m1_b[13] || m1_a[14]!=m1_b[14] || m1_a[15]!=m1_b[15] || m2_a[0]!=m2_b[0] || m2_a[1]!=m2_b[1] || m2_a[2]!=m2_b[2] || m2_a[3]!=m2_b[3] || m2_a[4]!=m2_b[4] || m2_a[5]!=m2_b[5] || m2_a[6]!=m2_b[6] || m2_a[7]!=m2_b[7] || m2_a[8]!=m2_b[8] || m2_a[9]!=m2_b[9] || m2_a[10]!=m2_b[10] || m2_a[11]!=m2_b[11] || m2_a[12]!=m2_b[12] || m2_a[13]!=m2_b[13] || m2_a[14]!=m2_b[14] || m2_a[15]!=m2_b[15] || prod_a[0]!=prod_b[0] || prod_a[1]!=prod_b[1] || prod_a[2]!=prod_b[2] || prod_a[3]!=prod_b[3] || prod_a[4]!=prod_b[4] || prod_a[5]!=prod_b[5] || prod_a[6]!=prod_b[6] || prod_a[7]!=prod_b[7] || prod_a[8]!=prod_b[8] || prod_a[9]!=prod_b[9] || prod_a[10]!=prod_b[10] || prod_a[11]!=prod_b[11] || prod_a[12]!=prod_b[12] || prod_a[13]!=prod_b[13] || prod_a[14]!=prod_b[14] || prod_a[15]!=prod_b[15]) ++failures;
}
{
uint32_t m1_a[16];
m1_a[0]=1552422845u;
m1_a[1]=1584889247u;
m1_a[2]=3718048245u;
m1_a[3]=562472799u;
m1_a[4]=0u;
m1_a[5]=0u;
m1_a[6]=0u;
m1_a[7]=0u;
m1_a[8]=0u;
m1_a[9]=0u;
m1_a[10]=0u;
m1_a[11]=0u;
m1_a[12]=0u;
m1_a[13]=0u;
m1_a[14]=0u;
m1_a[15]=0u;
uint32_t m2_a[16];
m2_a[0]=4092420497u;
m2_a[1]=0u;
m2_a[2]=0u;
m2_a[3]=0u;
m2_a[4]=477511231u;
m2_a[5]=0u;
m2_a[6]=0u;
m2_a[7]=0u;
m2_a[8]=4192112559u;
m2_a[9]=0u;
m2_a[10]=0u;
m2_a[11]=0u;
m2_a[12]=942078502u;
m2_a[13]=0u;
m2_a[14]=0u;
m2_a[15]=0u;
uint32_t prod_a[16];
prod_a[0]=0u;
prod_a[1]=0u;
prod_a[2]=0u;
prod_a[3]=0u;
prod_a[4]=0u;
prod_a[5]=0u;
prod_a[6]=0u;
prod_a[7]=0u;
prod_a[8]=0u;
prod_a[9]=0u;
prod_a[10]=0u;
prod_a[11]=0u;
prod_a[12]=0u;
prod_a[13]=0u;
prod_a[14]=0u;
prod_a[15]=0u;
uint32_t m1_b[16];
m1_b[0]=1552422845u;
m1_b[1]=1584889247u;
m1_b[2]=3718048245u;
m1_b[3]=562472799u;
m1_b[4]=0u;
m1_b[5]=0u;
m1_b[6]=0u;
m1_b[7]=0u;
m1_b[8]=0u;
m1_b[9]=0u;
m1_b[10]=0u;
m1_b[11]=0u;
m1_b[12]=0u;
m1_b[13]=0u;
m1_b[14]=0u;
m1_b[15]=0u;
uint32_t m2_b[16];
m2_b[0]=4092420497u;
m2_b[1]=0u;
m2_b[2]=0u;
m2_b[3]=0u;
m2_b[4]=477511231u;
m2_b[5]=0u;
m2_b[6]=0u;
m2_b[7]=0u;
m2_b[8]=4192112559u;
m2_b[9]=0u;
m2_b[10]=0u;
m2_b[11]=0u;
m2_b[12]=942078502u;
m2_b[13]=0u;
m2_b[14]=0u;
m2_b[15]=0u;
uint32_t prod_b[16];
prod_b[0]=0u;
prod_b[1]=0u;
prod_b[2]=0u;
prod_b[3]=0u;
prod_b[4]=0u;
prod_b[5]=0u;
prod_b[6]=0u;
prod_b[7]=0u;
prod_b[8]=0u;
prod_b[9]=0u;
prod_b[10]=0u;
prod_b[11]=0u;
prod_b[12]=0u;
prod_b[13]=0u;
prod_b[14]=0u;
prod_b[15]=0u;
original(m1_a,m2_a,prod_a);
buggy(m1_b,m2_b,prod_b);
unsigned witness_mismatch=(m1_a[0]!=m1_b[0] || m1_a[1]!=m1_b[1] || m1_a[2]!=m1_b[2] || m1_a[3]!=m1_b[3] || m1_a[4]!=m1_b[4] || m1_a[5]!=m1_b[5] || m1_a[6]!=m1_b[6] || m1_a[7]!=m1_b[7] || m1_a[8]!=m1_b[8] || m1_a[9]!=m1_b[9] || m1_a[10]!=m1_b[10] || m1_a[11]!=m1_b[11] || m1_a[12]!=m1_b[12] || m1_a[13]!=m1_b[13] || m1_a[14]!=m1_b[14] || m1_a[15]!=m1_b[15] || m2_a[0]!=m2_b[0] || m2_a[1]!=m2_b[1] || m2_a[2]!=m2_b[2] || m2_a[3]!=m2_b[3] || m2_a[4]!=m2_b[4] || m2_a[5]!=m2_b[5] || m2_a[6]!=m2_b[6] || m2_a[7]!=m2_b[7] || m2_a[8]!=m2_b[8] || m2_a[9]!=m2_b[9] || m2_a[10]!=m2_b[10] || m2_a[11]!=m2_b[11] || m2_a[12]!=m2_b[12] || m2_a[13]!=m2_b[13] || m2_a[14]!=m2_b[14] || m2_a[15]!=m2_b[15] || prod_a[0]!=prod_b[0] || prod_a[1]!=prod_b[1] || prod_a[2]!=prod_b[2] || prod_a[3]!=prod_b[3] || prod_a[4]!=prod_b[4] || prod_a[5]!=prod_b[5] || prod_a[6]!=prod_b[6] || prod_a[7]!=prod_b[7] || prod_a[8]!=prod_b[8] || prod_a[9]!=prod_b[9] || prod_a[10]!=prod_b[10] || prod_a[11]!=prod_b[11] || prod_a[12]!=prod_b[12] || prod_a[13]!=prod_b[13] || prod_a[14]!=prod_b[14] || prod_a[15]!=prod_b[15]);
unsigned witness_agrees=1;
witness_agrees &= (m1_a[0]==1552422845u && m1_b[0]==1552422845u);
witness_agrees &= (m1_a[1]==1584889247u && m1_b[1]==1584889247u);
witness_agrees &= (m1_a[2]==3718048245u && m1_b[2]==3718048245u);
witness_agrees &= (m1_a[3]==562472799u && m1_b[3]==562472799u);
witness_agrees &= (m1_a[4]==0u && m1_b[4]==0u);
witness_agrees &= (m1_a[5]==0u && m1_b[5]==0u);
witness_agrees &= (m1_a[6]==0u && m1_b[6]==0u);
witness_agrees &= (m1_a[7]==0u && m1_b[7]==0u);
witness_agrees &= (m1_a[8]==0u && m1_b[8]==0u);
witness_agrees &= (m1_a[9]==0u && m1_b[9]==0u);
witness_agrees &= (m1_a[10]==0u && m1_b[10]==0u);
witness_agrees &= (m1_a[11]==0u && m1_b[11]==0u);
witness_agrees &= (m1_a[12]==0u && m1_b[12]==0u);
witness_agrees &= (m1_a[13]==0u && m1_b[13]==0u);
witness_agrees &= (m1_a[14]==0u && m1_b[14]==0u);
witness_agrees &= (m1_a[15]==0u && m1_b[15]==0u);
witness_agrees &= (m2_a[0]==4092420497u && m2_b[0]==4092420497u);
witness_agrees &= (m2_a[1]==0u && m2_b[1]==0u);
witness_agrees &= (m2_a[2]==0u && m2_b[2]==0u);
witness_agrees &= (m2_a[3]==0u && m2_b[3]==0u);
witness_agrees &= (m2_a[4]==477511231u && m2_b[4]==477511231u);
witness_agrees &= (m2_a[5]==0u && m2_b[5]==0u);
witness_agrees &= (m2_a[6]==0u && m2_b[6]==0u);
witness_agrees &= (m2_a[7]==0u && m2_b[7]==0u);
witness_agrees &= (m2_a[8]==4192112559u && m2_b[8]==4192112559u);
witness_agrees &= (m2_a[9]==0u && m2_b[9]==0u);
witness_agrees &= (m2_a[10]==0u && m2_b[10]==0u);
witness_agrees &= (m2_a[11]==0u && m2_b[11]==0u);
witness_agrees &= (m2_a[12]==942078502u && m2_b[12]==942078502u);
witness_agrees &= (m2_a[13]==0u && m2_b[13]==0u);
witness_agrees &= (m2_a[14]==0u && m2_b[14]==0u);
witness_agrees &= (m2_a[15]==0u && m2_b[15]==0u);
witness_agrees &= (prod_a[0]==1142874819u && prod_b[0]==1142874818u);
witness_agrees &= (prod_a[1]==0u && prod_b[1]==0u);
witness_agrees &= (prod_a[2]==0u && prod_b[2]==0u);
witness_agrees &= (prod_a[3]==0u && prod_b[3]==0u);
witness_agrees &= (prod_a[4]==0u && prod_b[4]==0u);
witness_agrees &= (prod_a[5]==0u && prod_b[5]==0u);
witness_agrees &= (prod_a[6]==0u && prod_b[6]==0u);
witness_agrees &= (prod_a[7]==0u && prod_b[7]==0u);
witness_agrees &= (prod_a[8]==0u && prod_b[8]==0u);
witness_agrees &= (prod_a[9]==0u && prod_b[9]==0u);
witness_agrees &= (prod_a[10]==0u && prod_b[10]==0u);
witness_agrees &= (prod_a[11]==0u && prod_b[11]==0u);
witness_agrees &= (prod_a[12]==0u && prod_b[12]==0u);
witness_agrees &= (prod_a[13]==0u && prod_b[13]==0u);
witness_agrees &= (prod_a[14]==0u && prod_b[14]==0u);
witness_agrees &= (prod_a[15]==0u && prod_b[15]==0u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
