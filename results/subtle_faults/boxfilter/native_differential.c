#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* LLM rewrite: separable filtering, reusing horizontal sums across rows. */
void original(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for (int r = 0; r < 5; r++) {
        uint32_t sum = image[r * 5] + image[r * 5 + 1] + image[r * 5 + 2];
        horizontal[r * 3] = sum;
        for (int c = 1; c < 3; c++) {
            sum = sum - image[r * 5 + c - 1] + image[r * 5 + c + 2];
            horizontal[r * 3 + c] = sum;
        }
    }
    for (int r2 = 0; r2 < 3; r2++) {
        for (int c2 = 0; c2 < 3; c2++) {
            out[r2 * 3 + c2] = horizontal[r2 * 3 + c2]
                + horizontal[(r2 + 1) * 3 + c2] + horizontal[(r2 + 2) * 3 + c2];
        }
    }
}

#include <stdint.h>

/* LLM rewrite: separable filtering, reusing horizontal sums across rows. */
void optimized(uint32_t image[25], uint32_t out[9]) {
    uint32_t horizontal[15];
    for (int r = 0; r < 5; r++) {
        uint32_t sum = image[r * 5] + image[r * 5 + 1] + image[r * 5 + 2];
        horizontal[r * 3] = sum;
        for (int c = 1; c < 3; c++) {
            sum = sum - image[r * 5 + c - 1] + image[r * 5 + c + 1];
            horizontal[r * 3 + c] = sum;
        }
    }
    for (int r2 = 0; r2 < 3; r2++) {
        for (int c2 = 0; c2 < 3; c2++) {
            out[r2 * 3 + c2] = horizontal[r2 * 3 + c2]
                + horizontal[(r2 + 1) * 3 + c2] + horizontal[(r2 + 2) * 3 + c2];
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
optimized(image_b,out_b);
if(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || image_a[16]!=image_b[16] || image_a[17]!=image_b[17] || image_a[18]!=image_b[18] || image_a[19]!=image_b[19] || image_a[20]!=image_b[20] || image_a[21]!=image_b[21] || image_a[22]!=image_b[22] || image_a[23]!=image_b[23] || image_a[24]!=image_b[24] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t image_a[25];
image_a[0]=0u;
image_a[1]=0u;
image_a[2]=0u;
image_a[3]=1u;
image_a[4]=0u;
image_a[5]=0u;
image_a[6]=0u;
image_a[7]=0u;
image_a[8]=0u;
image_a[9]=0u;
image_a[10]=0u;
image_a[11]=0u;
image_a[12]=0u;
image_a[13]=0u;
image_a[14]=0u;
image_a[15]=0u;
image_a[16]=0u;
image_a[17]=0u;
image_a[18]=0u;
image_a[19]=0u;
image_a[20]=0u;
image_a[21]=0u;
image_a[22]=0u;
image_a[23]=0u;
image_a[24]=0u;
uint32_t out_a[9];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
out_a[4]=0u;
out_a[5]=0u;
out_a[6]=0u;
out_a[7]=0u;
out_a[8]=0u;
uint32_t image_b[25];
image_b[0]=0u;
image_b[1]=0u;
image_b[2]=0u;
image_b[3]=1u;
image_b[4]=0u;
image_b[5]=0u;
image_b[6]=0u;
image_b[7]=0u;
image_b[8]=0u;
image_b[9]=0u;
image_b[10]=0u;
image_b[11]=0u;
image_b[12]=0u;
image_b[13]=0u;
image_b[14]=0u;
image_b[15]=0u;
image_b[16]=0u;
image_b[17]=0u;
image_b[18]=0u;
image_b[19]=0u;
image_b[20]=0u;
image_b[21]=0u;
image_b[22]=0u;
image_b[23]=0u;
image_b[24]=0u;
uint32_t out_b[9];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
out_b[4]=0u;
out_b[5]=0u;
out_b[6]=0u;
out_b[7]=0u;
out_b[8]=0u;
original(image_a,out_a);
optimized(image_b,out_b);
witness_mismatch=(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || image_a[16]!=image_b[16] || image_a[17]!=image_b[17] || image_a[18]!=image_b[18] || image_a[19]!=image_b[19] || image_a[20]!=image_b[20] || image_a[21]!=image_b[21] || image_a[22]!=image_b[22] || image_a[23]!=image_b[23] || image_a[24]!=image_b[24] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8]);
witness_agrees=1;
witness_agrees &= (image_a[0]==0u && image_b[0]==0u);
witness_agrees &= (image_a[1]==0u && image_b[1]==0u);
witness_agrees &= (image_a[2]==0u && image_b[2]==0u);
witness_agrees &= (image_a[3]==1u && image_b[3]==1u);
witness_agrees &= (image_a[4]==0u && image_b[4]==0u);
witness_agrees &= (image_a[5]==0u && image_b[5]==0u);
witness_agrees &= (image_a[6]==0u && image_b[6]==0u);
witness_agrees &= (image_a[7]==0u && image_b[7]==0u);
witness_agrees &= (image_a[8]==0u && image_b[8]==0u);
witness_agrees &= (image_a[9]==0u && image_b[9]==0u);
witness_agrees &= (image_a[10]==0u && image_b[10]==0u);
witness_agrees &= (image_a[11]==0u && image_b[11]==0u);
witness_agrees &= (image_a[12]==0u && image_b[12]==0u);
witness_agrees &= (image_a[13]==0u && image_b[13]==0u);
witness_agrees &= (image_a[14]==0u && image_b[14]==0u);
witness_agrees &= (image_a[15]==0u && image_b[15]==0u);
witness_agrees &= (image_a[16]==0u && image_b[16]==0u);
witness_agrees &= (image_a[17]==0u && image_b[17]==0u);
witness_agrees &= (image_a[18]==0u && image_b[18]==0u);
witness_agrees &= (image_a[19]==0u && image_b[19]==0u);
witness_agrees &= (image_a[20]==0u && image_b[20]==0u);
witness_agrees &= (image_a[21]==0u && image_b[21]==0u);
witness_agrees &= (image_a[22]==0u && image_b[22]==0u);
witness_agrees &= (image_a[23]==0u && image_b[23]==0u);
witness_agrees &= (image_a[24]==0u && image_b[24]==0u);
witness_agrees &= (out_a[0]==0u && out_b[0]==0u);
witness_agrees &= (out_a[1]==1u && out_b[1]==0u);
witness_agrees &= (out_a[2]==1u && out_b[2]==1u);
witness_agrees &= (out_a[3]==0u && out_b[3]==0u);
witness_agrees &= (out_a[4]==0u && out_b[4]==0u);
witness_agrees &= (out_a[5]==0u && out_b[5]==0u);
witness_agrees &= (out_a[6]==0u && out_b[6]==0u);
witness_agrees &= (out_a[7]==0u && out_b[7]==0u);
witness_agrees &= (out_a[8]==0u && out_b[8]==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
