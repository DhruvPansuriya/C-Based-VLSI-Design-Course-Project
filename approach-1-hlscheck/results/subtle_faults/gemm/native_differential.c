#include <stdint.h>
#include <stdio.h>
/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void original(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16]) {
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
m1_a[0]=1286288037u;
m1_a[1]=3813651313u;
m1_a[2]=1193192559u;
m1_a[3]=27045738u;
m1_a[4]=1861245184u;
m1_a[5]=67000169u;
m1_a[6]=3271928058u;
m1_a[7]=1318084504u;
m1_a[8]=3296749597u;
m1_a[9]=2300621481u;
m1_a[10]=2963727016u;
m1_a[11]=1185950683u;
m1_a[12]=2720534758u;
m1_a[13]=2789269877u;
m1_a[14]=3332304034u;
m1_a[15]=1302276553u;
uint32_t m2_a[16];
m2_a[0]=0u;
m2_a[1]=3355547151u;
m2_a[2]=2820779004u;
m2_a[3]=2822684721u;
m2_a[4]=3086967468u;
m2_a[5]=0u;
m2_a[6]=399867904u;
m2_a[7]=38633764u;
m2_a[8]=1000494079u;
m2_a[9]=1553865695u;
m2_a[10]=0u;
m2_a[11]=2401382144u;
m2_a[12]=213303351u;
m2_a[13]=1286758400u;
m2_a[14]=670931700u;
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
m1_b[0]=1286288037u;
m1_b[1]=3813651313u;
m1_b[2]=1193192559u;
m1_b[3]=27045738u;
m1_b[4]=1861245184u;
m1_b[5]=67000169u;
m1_b[6]=3271928058u;
m1_b[7]=1318084504u;
m1_b[8]=3296749597u;
m1_b[9]=2300621481u;
m1_b[10]=2963727016u;
m1_b[11]=1185950683u;
m1_b[12]=2720534758u;
m1_b[13]=2789269877u;
m1_b[14]=3332304034u;
m1_b[15]=1302276553u;
uint32_t m2_b[16];
m2_b[0]=0u;
m2_b[1]=3355547151u;
m2_b[2]=2820779004u;
m2_b[3]=2822684721u;
m2_b[4]=3086967468u;
m2_b[5]=0u;
m2_b[6]=399867904u;
m2_b[7]=38633764u;
m2_b[8]=1000494079u;
m2_b[9]=1553865695u;
m2_b[10]=0u;
m2_b[11]=2401382144u;
m2_b[12]=213303351u;
m2_b[13]=1286758400u;
m2_b[14]=670931700u;
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
optimized(m1_b,m2_b,prod_b);
witness_mismatch=(m1_a[0]!=m1_b[0] || m1_a[1]!=m1_b[1] || m1_a[2]!=m1_b[2] || m1_a[3]!=m1_b[3] || m1_a[4]!=m1_b[4] || m1_a[5]!=m1_b[5] || m1_a[6]!=m1_b[6] || m1_a[7]!=m1_b[7] || m1_a[8]!=m1_b[8] || m1_a[9]!=m1_b[9] || m1_a[10]!=m1_b[10] || m1_a[11]!=m1_b[11] || m1_a[12]!=m1_b[12] || m1_a[13]!=m1_b[13] || m1_a[14]!=m1_b[14] || m1_a[15]!=m1_b[15] || m2_a[0]!=m2_b[0] || m2_a[1]!=m2_b[1] || m2_a[2]!=m2_b[2] || m2_a[3]!=m2_b[3] || m2_a[4]!=m2_b[4] || m2_a[5]!=m2_b[5] || m2_a[6]!=m2_b[6] || m2_a[7]!=m2_b[7] || m2_a[8]!=m2_b[8] || m2_a[9]!=m2_b[9] || m2_a[10]!=m2_b[10] || m2_a[11]!=m2_b[11] || m2_a[12]!=m2_b[12] || m2_a[13]!=m2_b[13] || m2_a[14]!=m2_b[14] || m2_a[15]!=m2_b[15] || prod_a[0]!=prod_b[0] || prod_a[1]!=prod_b[1] || prod_a[2]!=prod_b[2] || prod_a[3]!=prod_b[3] || prod_a[4]!=prod_b[4] || prod_a[5]!=prod_b[5] || prod_a[6]!=prod_b[6] || prod_a[7]!=prod_b[7] || prod_a[8]!=prod_b[8] || prod_a[9]!=prod_b[9] || prod_a[10]!=prod_b[10] || prod_a[11]!=prod_b[11] || prod_a[12]!=prod_b[12] || prod_a[13]!=prod_b[13] || prod_a[14]!=prod_b[14] || prod_a[15]!=prod_b[15]);
witness_agrees=1;
witness_agrees &= (m1_a[0]==1286288037u && m1_b[0]==1286288037u);
witness_agrees &= (m1_a[1]==3813651313u && m1_b[1]==3813651313u);
witness_agrees &= (m1_a[2]==1193192559u && m1_b[2]==1193192559u);
witness_agrees &= (m1_a[3]==27045738u && m1_b[3]==27045738u);
witness_agrees &= (m1_a[4]==1861245184u && m1_b[4]==1861245184u);
witness_agrees &= (m1_a[5]==67000169u && m1_b[5]==67000169u);
witness_agrees &= (m1_a[6]==3271928058u && m1_b[6]==3271928058u);
witness_agrees &= (m1_a[7]==1318084504u && m1_b[7]==1318084504u);
witness_agrees &= (m1_a[8]==3296749597u && m1_b[8]==3296749597u);
witness_agrees &= (m1_a[9]==2300621481u && m1_b[9]==2300621481u);
witness_agrees &= (m1_a[10]==2963727016u && m1_b[10]==2963727016u);
witness_agrees &= (m1_a[11]==1185950683u && m1_b[11]==1185950683u);
witness_agrees &= (m1_a[12]==2720534758u && m1_b[12]==2720534758u);
witness_agrees &= (m1_a[13]==2789269877u && m1_b[13]==2789269877u);
witness_agrees &= (m1_a[14]==3332304034u && m1_b[14]==3332304034u);
witness_agrees &= (m1_a[15]==1302276553u && m1_b[15]==1302276553u);
witness_agrees &= (m2_a[0]==0u && m2_b[0]==0u);
witness_agrees &= (m2_a[1]==3355547151u && m2_b[1]==3355547151u);
witness_agrees &= (m2_a[2]==2820779004u && m2_b[2]==2820779004u);
witness_agrees &= (m2_a[3]==2822684721u && m2_b[3]==2822684721u);
witness_agrees &= (m2_a[4]==3086967468u && m2_b[4]==3086967468u);
witness_agrees &= (m2_a[5]==0u && m2_b[5]==0u);
witness_agrees &= (m2_a[6]==399867904u && m2_b[6]==399867904u);
witness_agrees &= (m2_a[7]==38633764u && m2_b[7]==38633764u);
witness_agrees &= (m2_a[8]==1000494079u && m2_b[8]==1000494079u);
witness_agrees &= (m2_a[9]==1553865695u && m2_b[9]==1553865695u);
witness_agrees &= (m2_a[10]==0u && m2_b[10]==0u);
witness_agrees &= (m2_a[11]==2401382144u && m2_b[11]==2401382144u);
witness_agrees &= (m2_a[12]==213303351u && m2_b[12]==213303351u);
witness_agrees &= (m2_a[13]==1286758400u && m2_b[13]==1286758400u);
witness_agrees &= (m2_a[14]==670931700u && m2_b[14]==670931700u);
witness_agrees &= (m2_a[15]==0u && m2_b[15]==0u);
witness_agrees &= (prod_a[0]==3340091715u && prod_b[0]==1881714477u);
witness_agrees &= (prod_a[1]==2587840348u && prod_b[1]==4272276932u);
witness_agrees &= (prod_a[2]==1023116916u && prod_b[2]==4290617802u);
witness_agrees &= (prod_a[3]==599457657u && prod_b[3]==1603805503u);
witness_agrees &= (prod_a[4]==274126138u && prod_b[4]==1951876439u);
witness_agrees &= (prod_a[5]==97568454u && prod_b[5]==3527267680u);
witness_agrees &= (prod_a[6]==3933251808u && prod_b[6]==3633628791u);
witness_agrees &= (prod_a[7]==73409220u && prod_b[7]==273281352u);
witness_agrees &= (prod_a[8]==1714136305u && prod_b[8]==3242096690u);
witness_agrees &= (prod_a[9]==575889419u && prod_b[9]==1524536136u);
witness_agrees &= (prod_a[10]==3847939656u && prod_b[10]==1439155482u);
witness_agrees &= (prod_a[11]==2433863249u && prod_b[11]==3929839195u);
witness_agrees &= (prod_a[12]==1634351657u && prod_b[12]==3392907468u);
witness_agrees &= (prod_a[13]==804542616u && prod_b[13]==2977796044u);
witness_agrees &= (prod_a[14]==2951709180u && prod_b[14]==533662213u);
witness_agrees &= (prod_a[15]==65938298u && prod_b[15]==4137615314u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
