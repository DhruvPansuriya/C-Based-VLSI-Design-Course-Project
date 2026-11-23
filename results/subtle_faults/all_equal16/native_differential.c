#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   XOR/OR equality reduction. */
uint32_t original(uint32_t a[16]) {
    uint32_t difference=0u;uint32_t first=a[0];
    for(int i=1;i<16;i++) difference|=a[i]^first;
    return difference==0u?1u:0u;
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   XOR/OR equality reduction. */
uint32_t optimized(uint32_t a[16]) {
    uint32_t difference=0u;uint32_t first=a[0];
    for(int i=1;i<16;i++) difference^=a[i]^first;
    return difference==0u?1u:0u;
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
a_a[0]=23u;
a_a[1]=16u;
a_a[2]=4294967282u;
a_a[3]=4294967280u;
a_a[4]=4294967264u;
a_a[5]=4294967264u;
a_a[6]=2147483632u;
a_a[7]=4294967280u;
a_a[8]=3221225442u;
a_a[9]=1073741792u;
a_a[10]=4294967269u;
a_a[11]=4294967266u;
a_a[12]=4294967264u;
a_a[13]=4294967280u;
a_a[14]=4294967280u;
a_a[15]=4294967264u;
uint32_t a_b[16];
a_b[0]=23u;
a_b[1]=16u;
a_b[2]=4294967282u;
a_b[3]=4294967280u;
a_b[4]=4294967264u;
a_b[5]=4294967264u;
a_b[6]=2147483632u;
a_b[7]=4294967280u;
a_b[8]=3221225442u;
a_b[9]=1073741792u;
a_b[10]=4294967269u;
a_b[11]=4294967266u;
a_b[12]=4294967264u;
a_b[13]=4294967280u;
a_b[14]=4294967280u;
a_b[15]=4294967264u;
uint32_t ret_a=original(a_a);
uint32_t ret_b=optimized(a_b);
witness_mismatch=(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15]);
witness_agrees=1;
witness_agrees &= (a_a[0]==23u && a_b[0]==23u);
witness_agrees &= (a_a[1]==16u && a_b[1]==16u);
witness_agrees &= (a_a[2]==4294967282u && a_b[2]==4294967282u);
witness_agrees &= (a_a[3]==4294967280u && a_b[3]==4294967280u);
witness_agrees &= (a_a[4]==4294967264u && a_b[4]==4294967264u);
witness_agrees &= (a_a[5]==4294967264u && a_b[5]==4294967264u);
witness_agrees &= (a_a[6]==2147483632u && a_b[6]==2147483632u);
witness_agrees &= (a_a[7]==4294967280u && a_b[7]==4294967280u);
witness_agrees &= (a_a[8]==3221225442u && a_b[8]==3221225442u);
witness_agrees &= (a_a[9]==1073741792u && a_b[9]==1073741792u);
witness_agrees &= (a_a[10]==4294967269u && a_b[10]==4294967269u);
witness_agrees &= (a_a[11]==4294967266u && a_b[11]==4294967266u);
witness_agrees &= (a_a[12]==4294967264u && a_b[12]==4294967264u);
witness_agrees &= (a_a[13]==4294967280u && a_b[13]==4294967280u);
witness_agrees &= (a_a[14]==4294967280u && a_b[14]==4294967280u);
witness_agrees &= (a_a[15]==4294967264u && a_b[15]==4294967264u);
witness_agrees &= (ret_a==0u && ret_b==1u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
