#include <stdint.h>
#include <assert.h>
void kernel(uint32_t image[25],uint32_t out[9]);
#include <stdint.h>

/* Educational 3x3 box sum over the nine valid windows of a 5x5 image. */
void original(uint32_t image[25], uint32_t out[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t sum = 0u;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    sum += image[(r + y) * 5 + c + x];
                }
            }
            out[r * 3 + c] = sum;
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
for(unsigned t=0;t<16;++t){
uint32_t image_a[25];
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
image_a[16]=next_value(t);
image_a[17]=next_value(t);
image_a[18]=next_value(t);
image_a[19]=next_value(t);
image_a[20]=next_value(t);
image_a[21]=next_value(t);
image_a[22]=next_value(t);
image_a[23]=next_value(t);
image_a[24]=next_value(t);
uint32_t out_a[9];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
out_a[4]=next_value(t);
out_a[5]=next_value(t);
out_a[6]=next_value(t);
out_a[7]=next_value(t);
out_a[8]=next_value(t);
uint32_t image_b[25];
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
image_b[16]=image_a[16];
image_b[17]=image_a[17];
image_b[18]=image_a[18];
image_b[19]=image_a[19];
image_b[20]=image_a[20];
image_b[21]=image_a[21];
image_b[22]=image_a[22];
image_b[23]=image_a[23];
image_b[24]=image_a[24];
uint32_t out_b[9];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
out_b[4]=out_a[4];
out_b[5]=out_a[5];
out_b[6]=out_a[6];
out_b[7]=out_a[7];
out_b[8]=out_a[8];
original(image_a,out_a);
kernel(image_b,out_b);
assert(!(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || image_a[16]!=image_b[16] || image_a[17]!=image_b[17] || image_a[18]!=image_b[18] || image_a[19]!=image_b[19] || image_a[20]!=image_b[20] || image_a[21]!=image_b[21] || image_a[22]!=image_b[22] || image_a[23]!=image_b[23] || image_a[24]!=image_b[24] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8]));
}
return 0;}
