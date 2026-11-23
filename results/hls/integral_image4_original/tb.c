#include <stdint.h>
#include <assert.h>
void kernel(uint32_t image[16],uint32_t out[16]);
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){uint32_t sum=0u;for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) sum+=image[i*4+j];out[r*4+c]=sum;}
}


static uint32_t state=0x5291abcdU;
static uint32_t next_value(unsigned t) {
    static const uint32_t edge[]={0u,1u,0xffffffffu,0x80000000u,0x7fffffffu,10u,11u,0xfffffffeu};
    if(t<8) return edge[t];
    state^=state<<13; state^=state>>17; state^=state<<5; return state;
}

int main(void){
for(unsigned t=0;t<16;++t){
uint32_t image_a[16];
image_a[0]=next_value(t);
image_a[1]=next_value(t);
image_a[2]=next_value(t);
image_a[3]=next_value(t);
image_a[4]=next_value(t);
image_a[5]=next_value(t);
image_a[6]=next_value(t);
image_a[7]=next_value(t);
image_a[8]=next_value(t);
image_a[9]=next_value(t);
image_a[10]=next_value(t);
image_a[11]=next_value(t);
image_a[12]=next_value(t);
image_a[13]=next_value(t);
image_a[14]=next_value(t);
image_a[15]=next_value(t);
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
uint32_t image_b[16];
image_b[0]=image_a[0];
image_b[1]=image_a[1];
image_b[2]=image_a[2];
image_b[3]=image_a[3];
image_b[4]=image_a[4];
image_b[5]=image_a[5];
image_b[6]=image_a[6];
image_b[7]=image_a[7];
image_b[8]=image_a[8];
image_b[9]=image_a[9];
image_b[10]=image_a[10];
image_b[11]=image_a[11];
image_b[12]=image_a[12];
image_b[13]=image_a[13];
image_b[14]=image_a[14];
image_b[15]=image_a[15];
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
original(image_a,out_a);
kernel(image_b,out_b);
assert(!(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]));
}
return 0;}
