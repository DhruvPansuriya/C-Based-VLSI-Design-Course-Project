#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++){int hi=r>c?r:c;int lo=r>c?c:r;sum+=a[hi*4+lo]*x[c];}out[r]=sum;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Reuse stored triangular matrix elements. */
void optimized(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++) out[r]=0u;
    for(int r=0;r<4;r++) for(int c=0;c<=r;c++){uint32_t value=a[r*4+c];out[r]+=value*x[c];if(c!=r) out[c]+=value*x[r];}
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t a[16], uint32_t x[4], uint32_t out[4]) {
    for(int r=0;r<4;r++) out[r]=0u;
    for(int r=0;r<4;r++) for(int c=0;c<=r;c++){uint32_t value=a[r*4+c];out[r]+=value*x[c];if(c!=r) out[c]+=value*x[r];}
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
uint32_t x_a[4];
x_a[0]=next_value(t);
x_a[1]=next_value(t);
x_a[2]=next_value(t);
x_a[3]=next_value(t);
uint32_t out_a[4];
out_a[0]=next_value(t);
out_a[1]=next_value(t);
out_a[2]=next_value(t);
out_a[3]=next_value(t);
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
uint32_t x_b[4];
x_b[0]=x_a[0];
x_b[1]=x_a[1];
x_b[2]=x_a[2];
x_b[3]=x_a[3];
uint32_t out_b[4];
out_b[0]=out_a[0];
out_b[1]=out_a[1];
out_b[2]=out_a[2];
out_b[3]=out_a[3];
original(a_a,x_a,out_a);
optimized(a_b,x_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || x_a[0]!=x_b[0] || x_a[1]!=x_b[1] || x_a[2]!=x_b[2] || x_a[3]!=x_b[3] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=3107020605u;
a_a[1]=0u;
a_a[2]=0u;
a_a[3]=0u;
a_a[4]=1879307967u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
a_a[8]=3303014143u;
a_a[9]=0u;
a_a[10]=0u;
a_a[11]=0u;
a_a[12]=3217012700u;
a_a[13]=0u;
a_a[14]=0u;
a_a[15]=0u;
uint32_t x_a[4];
x_a[0]=679043583u;
x_a[1]=3885891582u;
x_a[2]=4228583647u;
x_a[3]=507292001u;
uint32_t out_a[4];
out_a[0]=0u;
out_a[1]=0u;
out_a[2]=0u;
out_a[3]=0u;
uint32_t a_b[16];
a_b[0]=3107020605u;
a_b[1]=0u;
a_b[2]=0u;
a_b[3]=0u;
a_b[4]=1879307967u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
a_b[8]=3303014143u;
a_b[9]=0u;
a_b[10]=0u;
a_b[11]=0u;
a_b[12]=3217012700u;
a_b[13]=0u;
a_b[14]=0u;
a_b[15]=0u;
uint32_t x_b[4];
x_b[0]=679043583u;
x_b[1]=3885891582u;
x_b[2]=4228583647u;
x_b[3]=507292001u;
uint32_t out_b[4];
out_b[0]=0u;
out_b[1]=0u;
out_b[2]=0u;
out_b[3]=0u;
original(a_a,x_a,out_a);
buggy(a_b,x_b,out_b);
unsigned witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || x_a[0]!=x_b[0] || x_a[1]!=x_b[1] || x_a[2]!=x_b[2] || x_a[3]!=x_b[3] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==3107020605u && a_b[0]==3107020605u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==1879307967u && a_b[4]==1879307967u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (a_a[8]==3303014143u && a_b[8]==3303014143u);
witness_agrees &= (a_a[9]==0u && a_b[9]==0u);
witness_agrees &= (a_a[10]==0u && a_b[10]==0u);
witness_agrees &= (a_a[11]==0u && a_b[11]==0u);
witness_agrees &= (a_a[12]==3217012700u && a_b[12]==3217012700u);
witness_agrees &= (a_a[13]==0u && a_b[13]==0u);
witness_agrees &= (a_a[14]==0u && a_b[14]==0u);
witness_agrees &= (a_a[15]==0u && a_b[15]==0u);
witness_agrees &= (x_a[0]==679043583u && x_b[0]==679043583u);
witness_agrees &= (x_a[1]==3885891582u && x_b[1]==3885891582u);
witness_agrees &= (x_a[2]==4228583647u && x_b[2]==4228583647u);
witness_agrees &= (x_a[3]==507292001u && x_b[3]==507292001u);
witness_agrees &= (out_a[0]==193725378u && out_b[0]==193725379u);
witness_agrees &= (out_a[1]==2360878913u && out_b[1]==2360878913u);
witness_agrees &= (out_a[2]==1497669377u && out_b[2]==1497669377u);
witness_agrees &= (out_a[3]==3953033252u && out_b[3]==3953033252u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
