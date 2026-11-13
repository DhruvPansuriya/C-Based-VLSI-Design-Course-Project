#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

void original(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        out[i] = a[i] * 8u + 3u;
    }
}

#include <stdint.h>

/* LLM-authored candidate: strength reduction and two-way source unrolling.
   Candidate status is determined independently by hlscheck. */
void optimized(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = (a[i] << 3) + 3u;
        out[i + 1] = (a[i + 1] << 3) + 3u;
    }
}

#include <stdint.h>

/* Deliberate negative control: second lane uses the wrong shift amount. */
void buggy(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i += 2) {
        out[i] = (a[i] << 3) + 3u;
        out[i + 1] = (a[i + 1] << 2) + 3u;
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
uint32_t a_a[8];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
a_a[4]=next_value(t);
a_a[5]=next_value(t);
a_a[6]=next_value(t);
a_a[7]=next_value(t);
uint32_t out_a[8];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
out_a[4]=next_value(t);
out_a[5]=next_value(t);
out_a[6]=next_value(t);
out_a[7]=next_value(t);
uint32_t a_b[8];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
uint32_t out_b[8];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
out_b[4]=out_a[4];
out_b[5]=out_a[5];
out_b[6]=out_a[6];
out_b[7]=out_a[7];
original(a_a,out_a);
optimized(a_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7]) ++failures;
}
{
uint32_t a_a[8];
a_a[0]=471859202u;
a_a[1]=626009362u;
a_a[2]=151027712u;
a_a[3]=554008576u;
a_a[4]=335560705u;
a_a[5]=570449920u;
a_a[6]=67108864u;
a_a[7]=612368386u;
uint32_t out_a[8];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
out_a[4]=0u;
out_a[5]=0u;
out_a[6]=0u;
out_a[7]=0u;
uint32_t a_b[8];
a_b[0]=471859202u;
a_b[1]=626009362u;
a_b[2]=151027712u;
a_b[3]=554008576u;
a_b[4]=335560705u;
a_b[5]=570449920u;
a_b[6]=67108864u;
a_b[7]=612368386u;
uint32_t out_b[8];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
out_b[4]=0u;
out_b[5]=0u;
out_b[6]=0u;
out_b[7]=0u;
original(a_a,out_a);
buggy(a_b,out_b);
unsigned witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==471859202u && a_b[0]==471859202u);
witness_agrees &= (a_a[1]==626009362u && a_b[1]==626009362u);
witness_agrees &= (a_a[2]==151027712u && a_b[2]==151027712u);
witness_agrees &= (a_a[3]==554008576u && a_b[3]==554008576u);
witness_agrees &= (a_a[4]==335560705u && a_b[4]==335560705u);
witness_agrees &= (a_a[5]==570449920u && a_b[5]==570449920u);
witness_agrees &= (a_a[6]==67108864u && a_b[6]==67108864u);
witness_agrees &= (a_a[7]==612368386u && a_b[7]==612368386u);
witness_agrees &= (out_a[0]==3774873619u && out_b[0]==3774873619u);
witness_agrees &= (out_a[1]==713107603u && out_b[1]==2504037451u);
witness_agrees &= (out_a[2]==1208221699u && out_b[2]==1208221699u);
witness_agrees &= (out_a[3]==137101315u && out_b[3]==2216034307u);
witness_agrees &= (out_a[4]==2684485643u && out_b[4]==2684485643u);
witness_agrees &= (out_a[5]==268632067u && out_b[5]==2281799683u);
witness_agrees &= (out_a[6]==536870915u && out_b[6]==536870915u);
witness_agrees &= (out_a[7]==603979795u && out_b[7]==2449473547u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
