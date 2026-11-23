#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[16], uint32_t key) {
    uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]==key?1u:0u);return n;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Two independent equality-count lanes. */
uint32_t optimized(uint32_t a[16], uint32_t key) {
    uint32_t even=0u,odd=0u;for(int i=0;i<16;i+=2){even+=(a[i]==key?1u:0u);odd+=(a[i+1]==key?1u:0u);}return even+odd;
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t buggy(uint32_t a[16], uint32_t key) {
    uint32_t even=0u,odd=0u;for(int i=0;i<16;i+=2){even+=(a[i]==key?1u:0u);odd+=(a[i+1]==key?1u:0u);}return (even+odd)^1u;
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
uint32_t key_a=next_value(t);
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
uint32_t key_b=key_a;
uint32_t ret_a=original(a_a,key_a);
uint32_t ret_b=optimized(a_b,key_b);
if(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=4294967295u;
a_a[1]=4294967295u;
a_a[2]=4294967295u;
a_a[3]=4294967295u;
a_a[4]=4294967295u;
a_a[5]=4294967295u;
a_a[6]=4294967295u;
a_a[7]=4294967295u;
a_a[8]=4294967295u;
a_a[9]=4294967295u;
a_a[10]=4294967295u;
a_a[11]=4294967295u;
a_a[12]=4294967295u;
a_a[13]=4294967295u;
a_a[14]=4294967295u;
a_a[15]=4294967295u;
uint32_t key_a=0u;
uint32_t a_b[16];
a_b[0]=4294967295u;
a_b[1]=4294967295u;
a_b[2]=4294967295u;
a_b[3]=4294967295u;
a_b[4]=4294967295u;
a_b[5]=4294967295u;
a_b[6]=4294967295u;
a_b[7]=4294967295u;
a_b[8]=4294967295u;
a_b[9]=4294967295u;
a_b[10]=4294967295u;
a_b[11]=4294967295u;
a_b[12]=4294967295u;
a_b[13]=4294967295u;
a_b[14]=4294967295u;
a_b[15]=4294967295u;
uint32_t key_b=0u;
uint32_t ret_a=original(a_a,key_a);
uint32_t ret_b=buggy(a_b,key_b);
unsigned witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==4294967295u && a_b[0]==4294967295u);
witness_agrees &= (a_a[1]==4294967295u && a_b[1]==4294967295u);
witness_agrees &= (a_a[2]==4294967295u && a_b[2]==4294967295u);
witness_agrees &= (a_a[3]==4294967295u && a_b[3]==4294967295u);
witness_agrees &= (a_a[4]==4294967295u && a_b[4]==4294967295u);
witness_agrees &= (a_a[5]==4294967295u && a_b[5]==4294967295u);
witness_agrees &= (a_a[6]==4294967295u && a_b[6]==4294967295u);
witness_agrees &= (a_a[7]==4294967295u && a_b[7]==4294967295u);
witness_agrees &= (a_a[8]==4294967295u && a_b[8]==4294967295u);
witness_agrees &= (a_a[9]==4294967295u && a_b[9]==4294967295u);
witness_agrees &= (a_a[10]==4294967295u && a_b[10]==4294967295u);
witness_agrees &= (a_a[11]==4294967295u && a_b[11]==4294967295u);
witness_agrees &= (a_a[12]==4294967295u && a_b[12]==4294967295u);
witness_agrees &= (a_a[13]==4294967295u && a_b[13]==4294967295u);
witness_agrees &= (a_a[14]==4294967295u && a_b[14]==4294967295u);
witness_agrees &= (a_a[15]==4294967295u && a_b[15]==4294967295u);
witness_agrees &= (ret_a==0u && ret_b==1u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
