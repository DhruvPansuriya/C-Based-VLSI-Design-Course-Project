#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* MachSuite-derived reference algorithm; LICENSE.MachSuite is retained.
   Feedback candidate: two local accumulators rather than four. */
void original(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j+=2) {
            uint32_t s0=0u, s1=0u;
            for(int k=0;k<4;k++) {
                uint32_t value=m1[i*4+k];
                s0+=value*m2[k*4+j];
                s1+=value*m2[k*4+j+1];
            }
            prod[i*4+j]=s0;
            prod[i*4+j+1]=s1;
        }
    }
}

#include <stdint.h>

/* MachSuite-derived reference algorithm; LICENSE.MachSuite is retained.
   Feedback candidate: two local accumulators rather than four. */
void optimized(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j+=2) {
            uint32_t s0=0u, s1=0u;
            for(int k=0;k<4;k++) {
                uint32_t value=m1[i*4+k];
                s0+=value*m2[k*4+j];
                s1+=value*m2[k*4+j];
            }
            prod[i*4+j]=s0;
            prod[i*4+j+1]=s1;
        }
    }
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
if(m1_a[0]!=m1_b[0] || m1_a[1]!=m1_b[1] || m1_a[2]!=m1_b[2] || m1_a[3]!=m1_b[3] || m1_a[4]!=m1_b[4] || m1_a[5]!=m1_b[5] || m1_a[6]!=m1_b[6] || m1_a[7]!=m1_b[7] || m1_a[8]!=m1_b[8] || m1_a[9]!=m1_b[9] || m1_a[10]!=m1_b[10] || m1_a[11]!=m1_b[11] || m1_a[12]!=m1_b[12] || m1_a[13]!=m1_b[13] || m1_a[14]!=m1_b[14] || m1_a[15]!=m1_b[15] || m2_a[0]!=m2_b[0] || m2_a[1]!=m2_b[1] || m2_a[2]!=m2_b[2] || m2_a[3]!=m2_b[3] || m2_a[4]!=m2_b[4] || m2_a[5]!=m2_b[5] || m2_a[6]!=m2_b[6] || m2_a[7]!=m2_b[7] || m2_a[8]!=m2_b[8] || m2_a[9]!=m2_b[9] || m2_a[10]!=m2_b[10] || m2_a[11]!=m2_b[11] || m2_a[12]!=m2_b[12] || m2_a[13]!=m2_b[13] || m2_a[14]!=m2_b[14] || m2_a[15]!=m2_b[15] || prod_a[0]!=prod_b[0] || prod_a[1]!=prod_b[1] || prod_a[2]!=prod_b[2] || prod_a[3]!=prod_b[3] || prod_a[4]!=prod_b[4] || prod_a[5]!=prod_b[5] || prod_a[6]!=prod_b[6] || prod_a[7]!=prod_b[7] || prod_a[8]!=prod_b[8] || prod_a[9]!=prod_b[9] || prod_a[10]!=prod_b[10] || prod_a[11]!=prod_b[11] || prod_a[12]!=prod_b[12] || prod_a[13]!=prod_b[13] || prod_a[14]!=prod_b[14] || prod_a[15]!=prod_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t m1_a[16];
m1_a[0]=4246662907u;
m1_a[1]=3185220682u;
m1_a[2]=929054280u;
m1_a[3]=2247998185u;
m1_a[4]=2834242983u;
m1_a[5]=1439777430u;
m1_a[6]=1056618739u;
m1_a[7]=3842295699u;
m1_a[8]=402885697u;
m1_a[9]=2997751519u;
m1_a[10]=3645121138u;
m1_a[11]=4143625783u;
m1_a[12]=788969819u;
m1_a[13]=615806677u;
m1_a[14]=1002479146u;
m1_a[15]=2557354677u;
uint32_t m2_a[16];
m2_a[0]=2664756394u;
m2_a[1]=4111444384u;
m2_a[2]=468875873u;
m2_a[3]=3018652427u;
m2_a[4]=1077303283u;
m2_a[5]=1866465280u;
m2_a[6]=98594807u;
m2_a[7]=1744830464u;
m2_a[8]=686393875u;
m2_a[9]=1586377592u;
m2_a[10]=3271072671u;
m2_a[11]=590913470u;
m2_a[12]=2795874271u;
m2_a[13]=2147483648u;
m2_a[14]=3270458855u;
m2_a[15]=1811939328u;
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
m1_b[0]=4246662907u;
m1_b[1]=3185220682u;
m1_b[2]=929054280u;
m1_b[3]=2247998185u;
m1_b[4]=2834242983u;
m1_b[5]=1439777430u;
m1_b[6]=1056618739u;
m1_b[7]=3842295699u;
m1_b[8]=402885697u;
m1_b[9]=2997751519u;
m1_b[10]=3645121138u;
m1_b[11]=4143625783u;
m1_b[12]=788969819u;
m1_b[13]=615806677u;
m1_b[14]=1002479146u;
m1_b[15]=2557354677u;
uint32_t m2_b[16];
m2_b[0]=2664756394u;
m2_b[1]=4111444384u;
m2_b[2]=468875873u;
m2_b[3]=3018652427u;
m2_b[4]=1077303283u;
m2_b[5]=1866465280u;
m2_b[6]=98594807u;
m2_b[7]=1744830464u;
m2_b[8]=686393875u;
m2_b[9]=1586377592u;
m2_b[10]=3271072671u;
m2_b[11]=590913470u;
m2_b[12]=2795874271u;
m2_b[13]=2147483648u;
m2_b[14]=3270458855u;
m2_b[15]=1811939328u;
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
optimized(m1_b,m2_b,prod_b);
witness_mismatch=(m1_a[0]!=m1_b[0] || m1_a[1]!=m1_b[1] || m1_a[2]!=m1_b[2] || m1_a[3]!=m1_b[3] || m1_a[4]!=m1_b[4] || m1_a[5]!=m1_b[5] || m1_a[6]!=m1_b[6] || m1_a[7]!=m1_b[7] || m1_a[8]!=m1_b[8] || m1_a[9]!=m1_b[9] || m1_a[10]!=m1_b[10] || m1_a[11]!=m1_b[11] || m1_a[12]!=m1_b[12] || m1_a[13]!=m1_b[13] || m1_a[14]!=m1_b[14] || m1_a[15]!=m1_b[15] || m2_a[0]!=m2_b[0] || m2_a[1]!=m2_b[1] || m2_a[2]!=m2_b[2] || m2_a[3]!=m2_b[3] || m2_a[4]!=m2_b[4] || m2_a[5]!=m2_b[5] || m2_a[6]!=m2_b[6] || m2_a[7]!=m2_b[7] || m2_a[8]!=m2_b[8] || m2_a[9]!=m2_b[9] || m2_a[10]!=m2_b[10] || m2_a[11]!=m2_b[11] || m2_a[12]!=m2_b[12] || m2_a[13]!=m2_b[13] || m2_a[14]!=m2_b[14] || m2_a[15]!=m2_b[15] || prod_a[0]!=prod_b[0] || prod_a[1]!=prod_b[1] || prod_a[2]!=prod_b[2] || prod_a[3]!=prod_b[3] || prod_a[4]!=prod_b[4] || prod_a[5]!=prod_b[5] || prod_a[6]!=prod_b[6] || prod_a[7]!=prod_b[7] || prod_a[8]!=prod_b[8] || prod_a[9]!=prod_b[9] || prod_a[10]!=prod_b[10] || prod_a[11]!=prod_b[11] || prod_a[12]!=prod_b[12] || prod_a[13]!=prod_b[13] || prod_a[14]!=prod_b[14] || prod_a[15]!=prod_b[15]);
witness_agrees=1;
witness_agrees &= (m1_a[0]==4246662907u && m1_b[0]==4246662907u);
witness_agrees &= (m1_a[1]==3185220682u && m1_b[1]==3185220682u);
witness_agrees &= (m1_a[2]==929054280u && m1_b[2]==929054280u);
witness_agrees &= (m1_a[3]==2247998185u && m1_b[3]==2247998185u);
witness_agrees &= (m1_a[4]==2834242983u && m1_b[4]==2834242983u);
witness_agrees &= (m1_a[5]==1439777430u && m1_b[5]==1439777430u);
witness_agrees &= (m1_a[6]==1056618739u && m1_b[6]==1056618739u);
witness_agrees &= (m1_a[7]==3842295699u && m1_b[7]==3842295699u);
witness_agrees &= (m1_a[8]==402885697u && m1_b[8]==402885697u);
witness_agrees &= (m1_a[9]==2997751519u && m1_b[9]==2997751519u);
witness_agrees &= (m1_a[10]==3645121138u && m1_b[10]==3645121138u);
witness_agrees &= (m1_a[11]==4143625783u && m1_b[11]==4143625783u);
witness_agrees &= (m1_a[12]==788969819u && m1_b[12]==788969819u);
witness_agrees &= (m1_a[13]==615806677u && m1_b[13]==615806677u);
witness_agrees &= (m1_a[14]==1002479146u && m1_b[14]==1002479146u);
witness_agrees &= (m1_a[15]==2557354677u && m1_b[15]==2557354677u);
witness_agrees &= (m2_a[0]==2664756394u && m2_b[0]==2664756394u);
witness_agrees &= (m2_a[1]==4111444384u && m2_b[1]==4111444384u);
witness_agrees &= (m2_a[2]==468875873u && m2_b[2]==468875873u);
witness_agrees &= (m2_a[3]==3018652427u && m2_b[3]==3018652427u);
witness_agrees &= (m2_a[4]==1077303283u && m2_b[4]==1077303283u);
witness_agrees &= (m2_a[5]==1866465280u && m2_b[5]==1866465280u);
witness_agrees &= (m2_a[6]==98594807u && m2_b[6]==98594807u);
witness_agrees &= (m2_a[7]==1744830464u && m2_b[7]==1744830464u);
witness_agrees &= (m2_a[8]==686393875u && m2_b[8]==686393875u);
witness_agrees &= (m2_a[9]==1586377592u && m2_b[9]==1586377592u);
witness_agrees &= (m2_a[10]==3271072671u && m2_b[10]==3271072671u);
witness_agrees &= (m2_a[11]==590913470u && m2_b[11]==590913470u);
witness_agrees &= (m2_a[12]==2795874271u && m2_b[12]==2795874271u);
witness_agrees &= (m2_a[13]==2147483648u && m2_b[13]==2147483648u);
witness_agrees &= (m2_a[14]==3270458855u && m2_b[14]==3270458855u);
witness_agrees &= (m2_a[15]==1811939328u && m2_b[15]==1811939328u);
witness_agrees &= (prod_a[0]==365538875u && prod_b[0]==365538875u);
witness_agrees &= (prod_a[1]==2630064544u && prod_b[1]==365538875u);
witness_agrees &= (prod_a[2]==848527480u && prod_b[2]==848527480u);
witness_agrees &= (prod_a[3]==3102035769u && prod_b[3]==848527480u);
witness_agrees &= (prod_a[4]==2295562590u && prod_b[4]==2295562590u);
witness_agrees &= (prod_a[5]==2021122632u && prod_b[5]==2295562590u);
witness_agrees &= (prod_a[6]==366426003u && prod_b[6]==366426003u);
witness_agrees &= (prod_a[7]==3899208839u && prod_b[7]==366426003u);
witness_agrees &= (prod_a[8]==239377206u && prod_b[8]==239377206u);
witness_agrees &= (prod_a[9]==291925264u && prod_b[9]==239377206u);
witness_agrees &= (prod_a[10]==3502185017u && prod_b[10]==3502185017u);
witness_agrees &= (prod_a[11]==3195871335u && prod_b[11]==3502185017u);
witness_agrees &= (prod_a[12]==4011897190u && prod_b[12]==4011897190u);
witness_agrees &= (prod_a[13]==3778964880u && prod_b[13]==4011897190u);
witness_agrees &= (prod_a[14]==3349395559u && prod_b[14]==3349395559u);
witness_agrees &= (prod_a[15]==1414244629u && prod_b[15]==3349395559u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
