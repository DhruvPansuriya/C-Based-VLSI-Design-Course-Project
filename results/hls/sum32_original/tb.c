#include <stdint.h>
#include <assert.h>
uint32_t kernel(uint32_t a[32]);
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
uint32_t original(uint32_t a[32]) {
    uint32_t sum=0u;for(int i=0;i<32;i++) sum+=a[i];return sum;
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
for(unsigned t=0;t<16;++t){
uint32_t a_a[32];
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
a_a[16]=next_value(t);
a_a[17]=next_value(t);
a_a[18]=next_value(t);
a_a[19]=next_value(t);
a_a[20]=next_value(t);
a_a[21]=next_value(t);
a_a[22]=next_value(t);
a_a[23]=next_value(t);
a_a[24]=next_value(t);
a_a[25]=next_value(t);
a_a[26]=next_value(t);
a_a[27]=next_value(t);
a_a[28]=next_value(t);
a_a[29]=next_value(t);
a_a[30]=next_value(t);
a_a[31]=next_value(t);
uint32_t a_b[32];
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
a_b[16]=a_a[16];
a_b[17]=a_a[17];
a_b[18]=a_a[18];
a_b[19]=a_a[19];
a_b[20]=a_a[20];
a_b[21]=a_a[21];
a_b[22]=a_a[22];
a_b[23]=a_a[23];
a_b[24]=a_a[24];
a_b[25]=a_a[25];
a_b[26]=a_a[26];
a_b[27]=a_a[27];
a_b[28]=a_a[28];
a_b[29]=a_a[29];
a_b[30]=a_a[30];
a_b[31]=a_a[31];
uint32_t ret_a=original(a_a);
uint32_t ret_b=kernel(a_b);
assert(!(ret_a!=ret_b || a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || a_a[16]!=a_b[16] || a_a[17]!=a_b[17] || a_a[18]!=a_b[18] || a_a[19]!=a_b[19] || a_a[20]!=a_b[20] || a_a[21]!=a_b[21] || a_a[22]!=a_b[22] || a_a[23]!=a_b[23] || a_a[24]!=a_b[24] || a_a[25]!=a_b[25] || a_a[26]!=a_b[26] || a_a[27]!=a_b[27] || a_a[28]!=a_b[28] || a_a[29]!=a_b[29] || a_a[30]!=a_b[30] || a_a[31]!=a_b[31]));
}
return 0;}
