#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* LLM-authored adaptation: hoist the invariant branch outside the loop. */
void original(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    if (x > 10u) {
        for (int i = 0; i < 4; i++) {
            a[i] = b[i] + c[i];
        }
    } else {
        for (int j = 0; j < 4; j++) {
            a[j] = b[j] - c[j];
        }
    }
}

#include <stdint.h>

/* LLM-authored adaptation: hoist the invariant branch outside the loop. */
void optimized(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4]) {
    if (x >= 10u) {
        for (int i = 0; i < 4; i++) {
            a[i] = b[i] + c[i];
        }
    } else {
        for (int j = 0; j < 4; j++) {
            a[j] = b[j] - c[j];
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
uint32_t x_a=next_value(t);
uint32_t b_a[4];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
uint32_t c_a[4];
c_a[0]=next_value(t);
c_a[1]=next_value(t);
c_a[2]=next_value(t);
c_a[3]=next_value(t);
uint32_t a_a[4];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
uint32_t x_b=x_a;
uint32_t b_b[4];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
uint32_t c_b[4];
c_b[0]=c_a[0];
c_b[1]=c_a[1];
c_b[2]=c_a[2];
c_b[3]=c_a[3];
uint32_t a_b[4];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
original(x_a,b_a,c_a,a_a);
optimized(x_b,b_b,c_b,a_b);
if(b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || c_a[0]!=c_b[0] || c_a[1]!=c_b[1] || c_a[2]!=c_b[2] || c_a[3]!=c_b[3] || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t x_a=10u;
uint32_t b_a[4];
b_a[0]=0u;
b_a[1]=0u;
b_a[2]=0u;
b_a[3]=0u;
uint32_t c_a[4];
c_a[0]=1073741828u;
c_a[1]=1080687888u;
c_a[2]=0u;
c_a[3]=0u;
uint32_t a_a[4];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=0u;
a_a[3]=0u;
uint32_t x_b=10u;
uint32_t b_b[4];
b_b[0]=0u;
b_b[1]=0u;
b_b[2]=0u;
b_b[3]=0u;
uint32_t c_b[4];
c_b[0]=1073741828u;
c_b[1]=1080687888u;
c_b[2]=0u;
c_b[3]=0u;
uint32_t a_b[4];
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=0u;
a_b[3]=0u;
original(x_a,b_a,c_a,a_a);
optimized(x_b,b_b,c_b,a_b);
witness_mismatch=(b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || c_a[0]!=c_b[0] || c_a[1]!=c_b[1] || c_a[2]!=c_b[2] || c_a[3]!=c_b[3] || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3]);
witness_agrees=1;
witness_agrees &= (b_a[0]==0u && b_b[0]==0u);
witness_agrees &= (b_a[1]==0u && b_b[1]==0u);
witness_agrees &= (b_a[2]==0u && b_b[2]==0u);
witness_agrees &= (b_a[3]==0u && b_b[3]==0u);
witness_agrees &= (c_a[0]==1073741828u && c_b[0]==1073741828u);
witness_agrees &= (c_a[1]==1080687888u && c_b[1]==1080687888u);
witness_agrees &= (c_a[2]==0u && c_b[2]==0u);
witness_agrees &= (c_a[3]==0u && c_b[3]==0u);
witness_agrees &= (a_a[0]==3221225468u && a_b[0]==1073741828u);
witness_agrees &= (a_a[1]==3214279408u && a_b[1]==1080687888u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
