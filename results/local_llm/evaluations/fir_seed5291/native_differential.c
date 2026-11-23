#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t original(uint32_t a[8]) {
    uint32_t sum = a[0] * 3u;
    sum += a[1] * 5u;
    sum += a[2] * 7u;
    sum += a[3] * 11u;
    sum += a[4] * 11u;
    sum += a[5] * 7u;
    sum += a[6] * 5u;
    sum += a[7] * 3u;
    return sum;
}

#include <stdint.h>

/* Eight-tap symmetric integer FIR; unsigned arithmetic is modulo 2^32. */
uint32_t optimized(uint32_t a[8]) {
    uint32_t sum = 0u;
    for (int i = 0; i < 8; i++) {
        sum += a[i] * (2 * i + 1);
    }
    return sum;
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
uint32_t a_a[8];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
a_a[4]=next_value(t);
a_a[5]=next_value(t);
a_a[6]=next_value(t);
a_a[7]=next_value(t);
uint32_t a_b[8];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[8];
a_a[0]=103809024u;
a_a[1]=1270825109u;
a_a[2]=939524096u;
a_a[3]=709837824u;
a_a[4]=1104584093u;
a_a[5]=768963455u;
a_a[6]=139142276u;
a_a[7]=42356097u;
uint32_t a_b[8];
a_b[0]=103809024u;
a_b[1]=1270825109u;
a_b[2]=939524096u;
a_b[3]=709837824u;
a_b[4]=1104584093u;
a_b[5]=768963455u;
a_b[6]=139142276u;
a_b[7]=42356097u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7]);
witness_agrees=1;
witness_agrees &= (a_a[0]==103809024u && a_b[0]==103809024u);
witness_agrees &= (a_a[1]==1270825109u && a_b[1]==1270825109u);
witness_agrees &= (a_a[2]==939524096u && a_b[2]==939524096u);
witness_agrees &= (a_a[3]==709837824u && a_b[3]==709837824u);
witness_agrees &= (a_a[4]==1104584093u && a_b[4]==1104584093u);
witness_agrees &= (a_a[5]==768963455u && a_b[5]==768963455u);
witness_agrees &= (a_a[6]==139142276u && a_b[6]==139142276u);
witness_agrees &= (a_a[7]==42356097u && a_b[7]==42356097u);
witness_agrees &= (ret_a==751680568u && ret_b==67077116u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
