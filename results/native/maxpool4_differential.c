#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){uint32_t best=image[r*8+c*2];for(int i=0;i<2;i++) for(int j=0;j<2;j++){uint32_t v=image[(r*2+i)*4+c*2+j];best=v>best?v:best;}out[r*2+c]=best;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Balanced two-by-two max pooling. */
void optimized(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t image[16], uint32_t out[4]) {
    for(int r=0;r<2;r++) for(int c=0;c<2;c++){
    uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
    uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}
    out[0]^=1u;
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
if(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]) ++failures;
}
{
uint32_t image_a[16];
image_a[0]=491389968u;
image_a[1]=2237157422u;
image_a[2]=542381123u;
image_a[3]=268439616u;
image_a[4]=2270209038u;
image_a[5]=220825612u;
image_a[6]=541746140u;
image_a[7]=21627400u;
image_a[8]=1080576008u;
image_a[9]=13702476u;
image_a[10]=2726609296u;
image_a[11]=2227269700u;
image_a[12]=7864320u;
image_a[13]=6848512u;
image_a[14]=2730521096u;
image_a[15]=3931514115u;
uint32_t out_a[4];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
uint32_t image_b[16];
image_b[0]=491389968u;
image_b[1]=2237157422u;
image_b[2]=542381123u;
image_b[3]=268439616u;
image_b[4]=2270209038u;
image_b[5]=220825612u;
image_b[6]=541746140u;
image_b[7]=21627400u;
image_b[8]=1080576008u;
image_b[9]=13702476u;
image_b[10]=2726609296u;
image_b[11]=2227269700u;
image_b[12]=7864320u;
image_b[13]=6848512u;
image_b[14]=2730521096u;
image_b[15]=3931514115u;
uint32_t out_b[4];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
original(image_a,out_a);
buggy(image_b,out_b);
unsigned witness_mismatch=(image_a[0]!=image_b[0] || image_a[1]!=image_b[1] || image_a[2]!=image_b[2] || image_a[3]!=image_b[3] || image_a[4]!=image_b[4] || image_a[5]!=image_b[5] || image_a[6]!=image_b[6] || image_a[7]!=image_b[7] || image_a[8]!=image_b[8] || image_a[9]!=image_b[9] || image_a[10]!=image_b[10] || image_a[11]!=image_b[11] || image_a[12]!=image_b[12] || image_a[13]!=image_b[13] || image_a[14]!=image_b[14] || image_a[15]!=image_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]);
unsigned witness_agrees=1;
witness_agrees &= (image_a[0]==491389968u && image_b[0]==491389968u);
witness_agrees &= (image_a[1]==2237157422u && image_b[1]==2237157422u);
witness_agrees &= (image_a[2]==542381123u && image_b[2]==542381123u);
witness_agrees &= (image_a[3]==268439616u && image_b[3]==268439616u);
witness_agrees &= (image_a[4]==2270209038u && image_b[4]==2270209038u);
witness_agrees &= (image_a[5]==220825612u && image_b[5]==220825612u);
witness_agrees &= (image_a[6]==541746140u && image_b[6]==541746140u);
witness_agrees &= (image_a[7]==21627400u && image_b[7]==21627400u);
witness_agrees &= (image_a[8]==1080576008u && image_b[8]==1080576008u);
witness_agrees &= (image_a[9]==13702476u && image_b[9]==13702476u);
witness_agrees &= (image_a[10]==2726609296u && image_b[10]==2726609296u);
witness_agrees &= (image_a[11]==2227269700u && image_b[11]==2227269700u);
witness_agrees &= (image_a[12]==7864320u && image_b[12]==7864320u);
witness_agrees &= (image_a[13]==6848512u && image_b[13]==6848512u);
witness_agrees &= (image_a[14]==2730521096u && image_b[14]==2730521096u);
witness_agrees &= (image_a[15]==3931514115u && image_b[15]==3931514115u);
witness_agrees &= (out_a[0]==2270209038u && out_b[0]==2270209039u);
witness_agrees &= (out_a[1]==542381123u && out_b[1]==542381123u);
witness_agrees &= (out_a[2]==1080576008u && out_b[2]==1080576008u);
witness_agrees &= (out_a[3]==3931514115u && out_b[3]==3931514115u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
