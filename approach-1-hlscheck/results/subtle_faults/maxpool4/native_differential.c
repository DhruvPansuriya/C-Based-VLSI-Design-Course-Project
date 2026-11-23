#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Balanced two-by-two max pooling. */
void original(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Balanced two-by-two max pooling. */
void optimized(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m1:m0;}
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
uint32_t out_a[4];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
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
uint32_t out_b[4];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
original(image_a,out_a);
optimized(image_b,out_b);
if(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t image_a[16];
image_a[0]=2875594563u;
image_a[1]=0u;
image_a[2]=4246527479u;
image_a[3]=0u;
image_a[4]=1419372732u;
image_a[5]=2u;
image_a[6]=48439816u;
image_a[7]=6u;
image_a[8]=3882678457u;
image_a[9]=16777215u;
image_a[10]=1695139739u;
image_a[11]=0u;
image_a[12]=412288838u;
image_a[13]=0u;
image_a[14]=2599827556u;
image_a[15]=2u;
uint32_t out_a[4];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
uint32_t image_b[16];
image_b[0]=2875594563u;
image_b[1]=0u;
image_b[2]=4246527479u;
image_b[3]=0u;
image_b[4]=1419372732u;
image_b[5]=2u;
image_b[6]=48439816u;
image_b[7]=6u;
image_b[8]=3882678457u;
image_b[9]=16777215u;
image_b[10]=1695139739u;
image_b[11]=0u;
image_b[12]=412288838u;
image_b[13]=0u;
image_b[14]=2599827556u;
image_b[15]=2u;
uint32_t out_b[4];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
original(image_a,out_a);
optimized(image_b,out_b);
witness_mismatch=(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]);
witness_agrees=1;
witness_agrees &= (image_a[0]==2875594563u && image_b[0]==2875594563u);
witness_agrees &= (image_a[1]==0u && image_b[1]==0u);
witness_agrees &= (image_a[2]==4246527479u && image_b[2]==4246527479u);
witness_agrees &= (image_a[3]==0u && image_b[3]==0u);
witness_agrees &= (image_a[4]==1419372732u && image_b[4]==1419372732u);
witness_agrees &= (image_a[5]==2u && image_b[5]==2u);
witness_agrees &= (image_a[6]==48439816u && image_b[6]==48439816u);
witness_agrees &= (image_a[7]==6u && image_b[7]==6u);
witness_agrees &= (image_a[8]==3882678457u && image_b[8]==3882678457u);
witness_agrees &= (image_a[9]==16777215u && image_b[9]==16777215u);
witness_agrees &= (image_a[10]==1695139739u && image_b[10]==1695139739u);
witness_agrees &= (image_a[11]==0u && image_b[11]==0u);
witness_agrees &= (image_a[12]==412288838u && image_b[12]==412288838u);
witness_agrees &= (image_a[13]==0u && image_b[13]==0u);
witness_agrees &= (image_a[14]==2599827556u && image_b[14]==2599827556u);
witness_agrees &= (image_a[15]==2u && image_b[15]==2u);
witness_agrees &= (out_a[0]==2875594563u && out_b[0]==1419372732u);
witness_agrees &= (out_a[1]==4246527479u && out_b[1]==48439816u);
witness_agrees &= (out_a[2]==3882678457u && out_b[2]==412288838u);
witness_agrees &= (out_a[3]==2599827556u && out_b[3]==1695139739u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
