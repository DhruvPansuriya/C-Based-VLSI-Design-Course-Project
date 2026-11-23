#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Dynamic-programming summed-area table. */
void original(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){
    uint32_t value=image[r*4+c];
    if(r>0) value+=out[(r-1)*4+c];
    if(c>0) value+=out[r*4+c-1];
    if(r>0 && c>0) value-=out[(r-1)*4+c-1];
    out[r*4+c]=value;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Dynamic-programming summed-area table. */
void optimized(uint32_t image[16], uint32_t out[16]) {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++){
    uint32_t value=image[r*4+c];
    if(r>0) value+=out[(r-1)*4+c];
    if(c>0) value+=out[r*4+c-1];
    if(r>0 && c>0) value+=out[(r-1)*4+c-1];
    out[r*4+c]=value;}
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
optimized(image_b,out_b);
if(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t image_a[16];
image_a[0]=39994582u;
image_a[1]=963646901u;
image_a[2]=11301079u;
image_a[3]=0u;
image_a[4]=410704223u;
image_a[5]=173650221u;
image_a[6]=1628692517u;
image_a[7]=0u;
image_a[8]=2110700478u;
image_a[9]=1346815165u;
image_a[10]=168096260u;
image_a[11]=0u;
image_a[12]=0u;
image_a[13]=0u;
image_a[14]=0u;
image_a[15]=0u;
uint32_t out_a[16];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
out_a[4]=0u;
out_a[5]=0u;
out_a[6]=0u;
out_a[7]=0u;
out_a[8]=0u;
out_a[9]=0u;
out_a[10]=0u;
out_a[11]=0u;
out_a[12]=0u;
out_a[13]=0u;
out_a[14]=0u;
out_a[15]=0u;
uint32_t image_b[16];
image_b[0]=39994582u;
image_b[1]=963646901u;
image_b[2]=11301079u;
image_b[3]=0u;
image_b[4]=410704223u;
image_b[5]=173650221u;
image_b[6]=1628692517u;
image_b[7]=0u;
image_b[8]=2110700478u;
image_b[9]=1346815165u;
image_b[10]=168096260u;
image_b[11]=0u;
image_b[12]=0u;
image_b[13]=0u;
image_b[14]=0u;
image_b[15]=0u;
uint32_t out_b[16];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
out_b[4]=0u;
out_b[5]=0u;
out_b[6]=0u;
out_b[7]=0u;
out_b[8]=0u;
out_b[9]=0u;
out_b[10]=0u;
out_b[11]=0u;
out_b[12]=0u;
out_b[13]=0u;
out_b[14]=0u;
out_b[15]=0u;
original(image_a,out_a);
optimized(image_b,out_b);
witness_mismatch=(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]);
witness_agrees=1;
witness_agrees &= (image_a[0]==39994582u && image_b[0]==39994582u);
witness_agrees &= (image_a[1]==963646901u && image_b[1]==963646901u);
witness_agrees &= (image_a[2]==11301079u && image_b[2]==11301079u);
witness_agrees &= (image_a[3]==0u && image_b[3]==0u);
witness_agrees &= (image_a[4]==410704223u && image_b[4]==410704223u);
witness_agrees &= (image_a[5]==173650221u && image_b[5]==173650221u);
witness_agrees &= (image_a[6]==1628692517u && image_b[6]==1628692517u);
witness_agrees &= (image_a[7]==0u && image_b[7]==0u);
witness_agrees &= (image_a[8]==2110700478u && image_b[8]==2110700478u);
witness_agrees &= (image_a[9]==1346815165u && image_b[9]==1346815165u);
witness_agrees &= (image_a[10]==168096260u && image_b[10]==168096260u);
witness_agrees &= (image_a[11]==0u && image_b[11]==0u);
witness_agrees &= (image_a[12]==0u && image_b[12]==0u);
witness_agrees &= (image_a[13]==0u && image_b[13]==0u);
witness_agrees &= (image_a[14]==0u && image_b[14]==0u);
witness_agrees &= (image_a[15]==0u && image_b[15]==0u);
witness_agrees &= (out_a[0]==39994582u && out_b[0]==39994582u);
witness_agrees &= (out_a[1]==1003641483u && out_b[1]==1003641483u);
witness_agrees &= (out_a[2]==1014942562u && out_b[2]==1014942562u);
witness_agrees &= (out_a[3]==1014942562u && out_b[3]==1014942562u);
witness_agrees &= (out_a[4]==450698805u && out_b[4]==450698805u);
witness_agrees &= (out_a[5]==1587995927u && out_b[5]==1667985091u);
witness_agrees &= (out_a[6]==3227989523u && out_b[6]==1020294357u);
witness_agrees &= (out_a[7]==3227989523u && out_b[7]==3050179481u);
witness_agrees &= (out_a[8]==2561399283u && out_b[8]==2561399283u);
witness_agrees &= (out_a[9]==750544274u && out_b[9]==1731931048u);
witness_agrees &= (out_a[10]==2558634130u && out_b[10]==293339460u);
witness_agrees &= (out_a[11]==2558634130u && out_b[11]==68846002u);
witness_agrees &= (out_a[12]==2561399283u && out_b[12]==2561399283u);
witness_agrees &= (out_a[13]==750544274u && out_b[13]==2559762318u);
witness_agrees &= (out_a[14]==2558634130u && out_b[14]==290065530u);
witness_agrees &= (out_a[15]==2558634130u && out_b[15]==652250992u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
