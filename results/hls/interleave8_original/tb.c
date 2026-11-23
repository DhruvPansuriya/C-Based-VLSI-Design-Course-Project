#include <stdint.h>
#include <assert.h>
void kernel(uint32_t a[8],uint32_t b[8],uint32_t out[16]);
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[8], uint32_t b[8], uint32_t out[16]) {
    for(int i=0;i<8;i++) out[2*i]=a[i];for(int j=0;j<8;j++) out[2*j+1]=b[j];
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
for(unsigned t=0;t<16;++t){
uint32_t a_a[8];
a_a[0]=next_value(t);
a_a[1]=next_value(t);
a_a[2]=next_value(t);
a_a[3]=next_value(t);
a_a[4]=next_value(t);
a_a[5]=next_value(t);
a_a[6]=next_value(t);
a_a[7]=next_value(t);
uint32_t b_a[8];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
b_a[4]=next_value(t);
b_a[5]=next_value(t);
b_a[6]=next_value(t);
b_a[7]=next_value(t);
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
uint32_t a_b[8];
a_b[0]=a_a[0];
a_b[1]=a_a[1];
a_b[2]=a_a[2];
a_b[3]=a_a[3];
a_b[4]=a_a[4];
a_b[5]=a_a[5];
a_b[6]=a_a[6];
a_b[7]=a_a[7];
uint32_t b_b[8];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
b_b[4]=b_a[4];
b_b[5]=b_a[5];
b_b[6]=b_a[6];
b_b[7]=b_a[7];
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
original(a_a,b_a,out_a);
kernel(a_b,b_b,out_b);
assert(!(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]));
}
return 0;}
