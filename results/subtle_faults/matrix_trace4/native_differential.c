#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Traverse only diagonal indices. */
uint32_t original(uint32_t a[16]) {
    uint32_t sum=0u;for(int i=0;i<4;i++) sum+=a[i*5];return sum;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Traverse only diagonal indices. */
uint32_t optimized(uint32_t a[16]) {
    uint32_t sum=0u;for(int i=0;i<4;i++) sum+=a[i*4];return sum;
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
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
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
a_a[10]=4294967295u;
a_a[11]=0u;
a_a[12]=0u;
a_a[13]=0u;
a_a[14]=0u;
a_a[15]=0u;
uint32_t a_b[16];
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
a_b[10]=4294967295u;
a_b[11]=0u;
a_b[12]=0u;
a_b[13]=0u;
a_b[14]=0u;
a_b[15]=0u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15]);
witness_agrees=1;
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
witness_agrees &= (a_a[10]==4294967295u && a_b[10]==4294967295u);
witness_agrees &= (a_a[11]==0u && a_b[11]==0u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==0u && a_b[13]==0u);
witness_agrees &= (a_a[14]==0u && a_b[14]==0u);
witness_agrees &= (a_a[15]==0u && a_b[15]==0u);
witness_agrees &= (ret_a==4294967295u && ret_b==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
