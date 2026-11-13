#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational reference: recompute each prefix independently. */
void original(uint32_t a[8], uint32_t out[8]) {
    for (int i = 0; i < 8; i++) {
        uint32_t sum = 0u;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        out[i] = sum;
    }
}

#include <stdint.h>

/* LLM rewrite: reuse the preceding prefix instead of recomputing it. */
void optimized(uint32_t a[8], uint32_t out[8]) {
    uint32_t running = 0u;
    for (int i = 0; i < 8; i++) {
        running += a[i];
        out[i] = running;
    }
}

#include <stdint.h>

/* Seeded negative control: misses the last output. */
void buggy(uint32_t a[8], uint32_t out[8]) {
    uint32_t running = 0u;
    for (int i = 0; i < 7; i++) {
        running += a[i];
        out[i] = running;
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
a_a[0]=4294967295u;
a_a[1]=0u;
a_a[2]=0u;
a_a[3]=0u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
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
a_b[0]=4294967295u;
a_b[1]=0u;
a_b[2]=0u;
a_b[3]=0u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
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
witness_agrees &= (a_a[0]==4294967295u && a_b[0]==4294967295u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (out_a[0]==4294967295u && out_b[0]==4294967295u);
witness_agrees &= (out_a[1]==4294967295u && out_b[1]==4294967295u);
witness_agrees &= (out_a[2]==4294967295u && out_b[2]==4294967295u);
witness_agrees &= (out_a[3]==4294967295u && out_b[3]==4294967295u);
witness_agrees &= (out_a[4]==4294967295u && out_b[4]==4294967295u);
witness_agrees &= (out_a[5]==4294967295u && out_b[5]==4294967295u);
witness_agrees &= (out_a[6]==4294967295u && out_b[6]==4294967295u);
witness_agrees &= (out_a[7]==4294967295u && out_b[7]==0u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
