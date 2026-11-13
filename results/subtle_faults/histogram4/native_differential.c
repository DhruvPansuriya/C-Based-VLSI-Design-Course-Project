#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Fuse four fixed-bin histogram scans. */
void original(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Fuse four fixed-bin histogram scans. */
void optimized(uint32_t a[16], uint32_t out[4]) {
    uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
    for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==2u?1u:0u);}
    out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;
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
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
a_a[0]=2u;
a_a[1]=3u;
a_a[2]=0u;
a_a[3]=0u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
a_a[8]=0u;
a_a[9]=3u;
a_a[10]=0u;
a_a[11]=0u;
a_a[12]=0u;
a_a[13]=1u;
a_a[14]=0u;
a_a[15]=0u;
uint32_t out_a[4];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
uint32_t a_b[16];
a_b[0]=2u;
a_b[1]=3u;
a_b[2]=0u;
a_b[3]=0u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
a_b[8]=0u;
a_b[9]=3u;
a_b[10]=0u;
a_b[11]=0u;
a_b[12]=0u;
a_b[13]=1u;
a_b[14]=0u;
a_b[15]=0u;
uint32_t out_b[4];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
original(a_a,out_a);
optimized(a_b,out_b);
witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]);
witness_agrees=1;
witness_agrees &= (a_a[0]==2u && a_b[0]==2u);
witness_agrees &= (a_a[1]==3u && a_b[1]==3u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (a_a[8]==0u && a_b[8]==0u);
witness_agrees &= (a_a[9]==3u && a_b[9]==3u);
witness_agrees &= (a_a[10]==0u && a_b[10]==0u);
witness_agrees &= (a_a[11]==0u && a_b[11]==0u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==1u && a_b[13]==1u);
witness_agrees &= (a_a[14]==0u && a_b[14]==0u);
witness_agrees &= (a_a[15]==0u && a_b[15]==0u);
witness_agrees &= (out_a[0]==12u && out_b[0]==12u);
witness_agrees &= (out_a[1]==1u && out_b[1]==1u);
witness_agrees &= (out_a[2]==1u && out_b[2]==1u);
witness_agrees &= (out_a[3]==2u && out_b[3]==1u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
