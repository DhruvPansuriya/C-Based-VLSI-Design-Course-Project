#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

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

/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void optimized(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int p = 0; p < 16; p++) {
        prod[p] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            uint32_t a = m1[i * 4 + k];
            for (int j = 0; j < 4; j++) {
                prod[i * 4 + j] += a * m2[k * 4 + j];
            }
        }
    }
}

/* Deliberate negative control; see README.md and LICENSE. */
#include <stdint.h>

void buggy(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
    for (int p = 0; p < 16; p++) {
        prod[p] = 0u;
    }
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            uint32_t a = m1[i * 4 + k];
            for (int j = 0; j < 4; j++) {
                prod[i * 4 + j] += a * m2[j * 4 + k];
            }
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
m1_a[0]=686596121u;
m1_a[1]=3772911372u;
m1_a[2]=4102649573u;
m1_a[3]=1715655136u;
m1_a[4]=4111565191u;
m1_a[5]=1091414610u;
m1_a[6]=3746720213u;
m1_a[7]=275617691u;
m1_a[8]=1168499187u;
m1_a[9]=1272253884u;
m1_a[10]=2555834029u;
m1_a[11]=2070369235u;
m1_a[12]=2296595831u;
m1_a[13]=1741737932u;
m1_a[14]=2507817495u;
m1_a[15]=3975590831u;
uint32_t m2_a[16];
m2_a[0]=0u;
m2_a[1]=4209483506u;
m2_a[2]=3380699136u;
m2_a[3]=706404311u;
m2_a[4]=2916858135u;
m2_a[5]=0u;
m2_a[6]=793508638u;
m2_a[7]=176228506u;
m2_a[8]=3034841088u;
m2_a[9]=1659908298u;
m2_a[10]=0u;
m2_a[11]=2023092458u;
m2_a[12]=610643968u;
m2_a[13]=3523215360u;
m2_a[14]=1308748467u;
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
m1_b[0]=686596121u;
m1_b[1]=3772911372u;
m1_b[2]=4102649573u;
m1_b[3]=1715655136u;
m1_b[4]=4111565191u;
m1_b[5]=1091414610u;
m1_b[6]=3746720213u;
m1_b[7]=275617691u;
m1_b[8]=1168499187u;
m1_b[9]=1272253884u;
m1_b[10]=2555834029u;
m1_b[11]=2070369235u;
m1_b[12]=2296595831u;
m1_b[13]=1741737932u;
m1_b[14]=2507817495u;
m1_b[15]=3975590831u;
uint32_t m2_b[16];
m2_b[0]=0u;
m2_b[1]=4209483506u;
m2_b[2]=3380699136u;
m2_b[3]=706404311u;
m2_b[4]=2916858135u;
m2_b[5]=0u;
m2_b[6]=793508638u;
m2_b[7]=176228506u;
m2_b[8]=3034841088u;
m2_b[9]=1659908298u;
m2_b[10]=0u;
m2_b[11]=2023092458u;
m2_b[12]=610643968u;
m2_b[13]=3523215360u;
m2_b[14]=1308748467u;
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
witness_agrees &= (m1_a[0]==686596121u && m1_b[0]==686596121u);
witness_agrees &= (m1_a[1]==3772911372u && m1_b[1]==3772911372u);
witness_agrees &= (m1_a[2]==4102649573u && m1_b[2]==4102649573u);
witness_agrees &= (m1_a[3]==1715655136u && m1_b[3]==1715655136u);
witness_agrees &= (m1_a[4]==4111565191u && m1_b[4]==4111565191u);
witness_agrees &= (m1_a[5]==1091414610u && m1_b[5]==1091414610u);
witness_agrees &= (m1_a[6]==3746720213u && m1_b[6]==3746720213u);
witness_agrees &= (m1_a[7]==275617691u && m1_b[7]==275617691u);
witness_agrees &= (m1_a[8]==1168499187u && m1_b[8]==1168499187u);
witness_agrees &= (m1_a[9]==1272253884u && m1_b[9]==1272253884u);
witness_agrees &= (m1_a[10]==2555834029u && m1_b[10]==2555834029u);
witness_agrees &= (m1_a[11]==2070369235u && m1_b[11]==2070369235u);
witness_agrees &= (m1_a[12]==2296595831u && m1_b[12]==2296595831u);
witness_agrees &= (m1_a[13]==1741737932u && m1_b[13]==1741737932u);
witness_agrees &= (m1_a[14]==2507817495u && m1_b[14]==2507817495u);
witness_agrees &= (m1_a[15]==3975590831u && m1_b[15]==3975590831u);
witness_agrees &= (m2_a[0]==0u && m2_b[0]==0u);
witness_agrees &= (m2_a[1]==4209483506u && m2_b[1]==4209483506u);
witness_agrees &= (m2_a[2]==3380699136u && m2_b[2]==3380699136u);
witness_agrees &= (m2_a[3]==706404311u && m2_b[3]==706404311u);
witness_agrees &= (m2_a[4]==2916858135u && m2_b[4]==2916858135u);
witness_agrees &= (m2_a[5]==0u && m2_b[5]==0u);
witness_agrees &= (m2_a[6]==793508638u && m2_b[6]==793508638u);
witness_agrees &= (m2_a[7]==176228506u && m2_b[7]==176228506u);
witness_agrees &= (m2_a[8]==3034841088u && m2_b[8]==3034841088u);
witness_agrees &= (m2_a[9]==1659908298u && m2_b[9]==1659908298u);
witness_agrees &= (m2_a[10]==0u && m2_b[10]==0u);
witness_agrees &= (m2_a[11]==2023092458u && m2_b[11]==2023092458u);
witness_agrees &= (m2_a[12]==610643968u && m2_b[12]==610643968u);
witness_agrees &= (m2_a[13]==3523215360u && m2_b[13]==3523215360u);
witness_agrees &= (m2_a[14]==1308748467u && m2_b[14]==1308748467u);
witness_agrees &= (m2_a[15]==0u && m2_b[15]==0u);
witness_agrees &= (prod_a[0]==2987460116u && prod_b[0]==3514492024u);
witness_agrees &= (prod_a[1]==914392660u && prod_b[1]==4089326037u);
witness_agrees &= (prod_a[2]==1272211208u && prod_b[2]==4159436344u);
witness_agrees &= (prod_a[3]==815924873u && prod_b[3]==329163807u);
witness_agrees &= (prod_a[4]==3498778462u && prod_b[4]==1105515953u);
witness_agrees &= (prod_a[5]==3252565424u && prod_b[5]==2353167189u);
witness_agrees &= (prod_a[6]==1225239293u && prod_b[6]==3847792738u);
witness_agrees &= (prod_a[7]==3416314727u && prod_b[7]==780239343u);
witness_agrees &= (prod_a[8]==2430150628u && prod_b[8]==2775389933u);
witness_agrees &= (prod_a[9]==4228994616u && prod_b[9]==1544389641u);
witness_agrees &= (prod_a[10]==2254604945u && prod_b[10]==372475190u);
witness_agrees &= (prod_a[11]==453963087u && prod_b[11]==869668087u);
witness_agrees &= (prod_a[12]==4253050708u && prod_b[12]==3516157905u);
witness_agrees &= (prod_a[13]==3229913764u && prod_b[13]==4252833705u);
witness_agrees &= (prod_a[14]==459904837u && prod_b[14]==29721838u);
witness_agrees &= (prod_a[15]==2876791215u && prod_b[15]==1152453653u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
