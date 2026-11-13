#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) for(int j=0;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Reference implementation. */
void optimized(uint32_t a[16], uint32_t out[16]) {
    for(int i=0;i<4;i++) {
        uint32_t sum1 = 0u, sum2 = 0u, sum3 = 0u, sum4 = 0u;
        for(int j=0;j<4;j++) {
            sum1 += a[i*4+j] * a[j*4+0];
            sum2 += a[i*4+j] * a[j*4+1];
            sum3 += a[i*4+j] * a[j*4+2];
            sum4 += a[i*4+j] * a[j*4+3];
        }
        out[i*4+0] = sum1;
        out[i*4+1] = sum2;
        out[i*4+2] = sum3;
        out[i*4+3] = sum4;
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
uint32_t out_a[16];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
out_a[4]=next_value(t);
out_a[5]=next_value(t);
out_a[6]=next_value(t);
out_a[7]=next_value(t);
out_a[8]=next_value(t);
out_a[9]=next_value(t);
out_a[10]=next_value(t);
out_a[11]=next_value(t);
out_a[12]=next_value(t);
out_a[13]=next_value(t);
out_a[14]=next_value(t);
out_a[15]=next_value(t);
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
uint32_t out_b[16];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
out_b[4]=out_a[4];
out_b[5]=out_a[5];
out_b[6]=out_a[6];
out_b[7]=out_a[7];
out_b[8]=out_a[8];
out_b[9]=out_a[9];
out_b[10]=out_a[10];
out_b[11]=out_a[11];
out_b[12]=out_a[12];
out_b[13]=out_a[13];
out_b[14]=out_a[14];
out_b[15]=out_a[15];
original(a_a,out_a);
optimized(a_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
a_a[0]=1864073472u;
a_a[1]=236075935u;
a_a[2]=3846369280u;
a_a[3]=1958893584u;
a_a[4]=1117738495u;
a_a[5]=302937718u;
a_a[6]=1766859339u;
a_a[7]=2573805887u;
a_a[8]=71770206u;
a_a[9]=3492899072u;
a_a[10]=763492372u;
a_a[11]=1248381623u;
a_a[12]=4163545250u;
a_a[13]=597553u;
a_a[14]=3187670271u;
a_a[15]=968366415u;
uint32_t out_a[16];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
out_a[4]=0u;
out_a[5]=0u;
out_a[6]=0u;
out_a[7]=0u;
out_a[8]=0u;
out_a[9]=0u;
out_a[10]=0u;
out_a[11]=0u;
out_a[12]=0u;
out_a[13]=0u;
out_a[14]=0u;
out_a[15]=0u;
uint32_t a_b[16];
a_b[0]=1864073472u;
a_b[1]=236075935u;
a_b[2]=3846369280u;
a_b[3]=1958893584u;
a_b[4]=1117738495u;
a_b[5]=302937718u;
a_b[6]=1766859339u;
a_b[7]=2573805887u;
a_b[8]=71770206u;
a_b[9]=3492899072u;
a_b[10]=763492372u;
a_b[11]=1248381623u;
a_b[12]=4163545250u;
a_b[13]=597553u;
a_b[14]=3187670271u;
a_b[15]=968366415u;
uint32_t out_b[16];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
out_b[4]=0u;
out_b[5]=0u;
out_b[6]=0u;
out_b[7]=0u;
out_b[8]=0u;
out_b[9]=0u;
out_b[10]=0u;
out_b[11]=0u;
out_b[12]=0u;
out_b[13]=0u;
out_b[14]=0u;
out_b[15]=0u;
original(a_a,out_a);
optimized(a_b,out_b);
witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]);
witness_agrees=1;
witness_agrees &= (a_a[0]==1864073472u && a_b[0]==1864073472u);
witness_agrees &= (a_a[1]==236075935u && a_b[1]==236075935u);
witness_agrees &= (a_a[2]==3846369280u && a_b[2]==3846369280u);
witness_agrees &= (a_a[3]==1958893584u && a_b[3]==1958893584u);
witness_agrees &= (a_a[4]==1117738495u && a_b[4]==1117738495u);
witness_agrees &= (a_a[5]==302937718u && a_b[5]==302937718u);
witness_agrees &= (a_a[6]==1766859339u && a_b[6]==1766859339u);
witness_agrees &= (a_a[7]==2573805887u && a_b[7]==2573805887u);
witness_agrees &= (a_a[8]==71770206u && a_b[8]==71770206u);
witness_agrees &= (a_a[9]==3492899072u && a_b[9]==3492899072u);
witness_agrees &= (a_a[10]==763492372u && a_b[10]==763492372u);
witness_agrees &= (a_a[11]==1248381623u && a_b[11]==1248381623u);
witness_agrees &= (a_a[12]==4163545250u && a_b[12]==4163545250u);
witness_agrees &= (a_a[13]==597553u && a_b[13]==597553u);
witness_agrees &= (a_a[14]==3187670271u && a_b[14]==3187670271u);
witness_agrees &= (a_a[15]==968366415u && a_b[15]==968366415u);
witness_agrees &= (out_a[0]==46837185u && out_b[0]==179406977u);
witness_agrees &= (out_a[1]==3670659130u && out_b[1]==1542037338u);
witness_agrees &= (out_a[2]==4290832496u && out_b[2]==1154665861u);
witness_agrees &= (out_a[3]==2736814687u && out_b[3]==396132369u);
witness_agrees &= (out_a[4]==3670659130u && out_b[4]==4172813810u);
witness_agrees &= (out_a[5]==1395233247u && out_b[5]==1560819412u);
witness_agrees &= (out_a[6]==2696765831u && out_b[6]==2274811951u);
witness_agrees &= (out_a[7]==3337757210u && out_b[7]==3997411336u);
witness_agrees &= (out_a[8]==4290832496u && out_b[8]==2062806054u);
witness_agrees &= (out_a[9]==2696765831u && out_b[9]==2738789737u);
witness_agrees &= (out_a[10]==1662038757u && out_b[10]==3301291225u);
witness_agrees &= (out_a[11]==3752820193u && out_b[11]==1480243365u);
witness_agrees &= (out_a[12]==2736814687u && out_b[12]==3909327727u);
witness_agrees &= (out_a[13]==3337757210u && out_b[13]==505103443u);
witness_agrees &= (out_a[14]==3752820193u && out_b[14]==2272002040u);
witness_agrees &= (out_a[15]==3713538119u && out_b[15]==1641748441u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
