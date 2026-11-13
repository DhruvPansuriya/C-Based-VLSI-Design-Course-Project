#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Share comparison before subtraction. */
void original(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?y:x;out[i]=high-low;}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Share comparison before subtraction. */
void optimized(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?x:y;out[i]=high-low;}
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
uint32_t b_a[16];
b_a[0]=next_value(t);
b_a[1]=next_value(t);
b_a[2]=next_value(t);
b_a[3]=next_value(t);
b_a[4]=next_value(t);
b_a[5]=next_value(t);
b_a[6]=next_value(t);
b_a[7]=next_value(t);
b_a[8]=next_value(t);
b_a[9]=next_value(t);
b_a[10]=next_value(t);
b_a[11]=next_value(t);
b_a[12]=next_value(t);
b_a[13]=next_value(t);
b_a[14]=next_value(t);
b_a[15]=next_value(t);
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
uint32_t b_b[16];
b_b[0]=b_a[0];
b_b[1]=b_a[1];
b_b[2]=b_a[2];
b_b[3]=b_a[3];
b_b[4]=b_a[4];
b_b[5]=b_a[5];
b_b[6]=b_a[6];
b_b[7]=b_a[7];
b_b[8]=b_a[8];
b_b[9]=b_a[9];
b_b[10]=b_a[10];
b_b[11]=b_a[11];
b_b[12]=b_a[12];
b_b[13]=b_a[13];
b_b[14]=b_a[14];
b_b[15]=b_a[15];
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
optimized(a_b,b_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
a_a[0]=4294967294u;
a_a[1]=4294967294u;
a_a[2]=4294967294u;
a_a[3]=4294967295u;
a_a[4]=4294965247u;
a_a[5]=4294967295u;
a_a[6]=4294967295u;
a_a[7]=4294967295u;
a_a[8]=4293918718u;
a_a[9]=4294967295u;
a_a[10]=4294967295u;
a_a[11]=4294967294u;
a_a[12]=4294967295u;
a_a[13]=4294967295u;
a_a[14]=4294967231u;
a_a[15]=4294967294u;
uint32_t b_a[16];
b_a[0]=1u;
b_a[1]=1u;
b_a[2]=1u;
b_a[3]=0u;
b_a[4]=2048u;
b_a[5]=0u;
b_a[6]=0u;
b_a[7]=0u;
b_a[8]=1048577u;
b_a[9]=0u;
b_a[10]=0u;
b_a[11]=1u;
b_a[12]=0u;
b_a[13]=0u;
b_a[14]=64u;
b_a[15]=1u;
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
uint32_t a_b[16];
a_b[0]=4294967294u;
a_b[1]=4294967294u;
a_b[2]=4294967294u;
a_b[3]=4294967295u;
a_b[4]=4294965247u;
a_b[5]=4294967295u;
a_b[6]=4294967295u;
a_b[7]=4294967295u;
a_b[8]=4293918718u;
a_b[9]=4294967295u;
a_b[10]=4294967295u;
a_b[11]=4294967294u;
a_b[12]=4294967295u;
a_b[13]=4294967295u;
a_b[14]=4294967231u;
a_b[15]=4294967294u;
uint32_t b_b[16];
b_b[0]=1u;
b_b[1]=1u;
b_b[2]=1u;
b_b[3]=0u;
b_b[4]=2048u;
b_b[5]=0u;
b_b[6]=0u;
b_b[7]=0u;
b_b[8]=1048577u;
b_b[9]=0u;
b_b[10]=0u;
b_b[11]=1u;
b_b[12]=0u;
b_b[13]=0u;
b_b[14]=64u;
b_b[15]=1u;
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
original(a_a,b_a,out_a);
optimized(a_b,b_b,out_b);
witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]);
witness_agrees=1;
witness_agrees &= (a_a[0]==4294967294u && a_b[0]==4294967294u);
witness_agrees &= (a_a[1]==4294967294u && a_b[1]==4294967294u);
witness_agrees &= (a_a[2]==4294967294u && a_b[2]==4294967294u);
witness_agrees &= (a_a[3]==4294967295u && a_b[3]==4294967295u);
witness_agrees &= (a_a[4]==4294965247u && a_b[4]==4294965247u);
witness_agrees &= (a_a[5]==4294967295u && a_b[5]==4294967295u);
witness_agrees &= (a_a[6]==4294967295u && a_b[6]==4294967295u);
witness_agrees &= (a_a[7]==4294967295u && a_b[7]==4294967295u);
witness_agrees &= (a_a[8]==4293918718u && a_b[8]==4293918718u);
witness_agrees &= (a_a[9]==4294967295u && a_b[9]==4294967295u);
witness_agrees &= (a_a[10]==4294967295u && a_b[10]==4294967295u);
witness_agrees &= (a_a[11]==4294967294u && a_b[11]==4294967294u);
witness_agrees &= (a_a[12]==4294967295u && a_b[12]==4294967295u);
witness_agrees &= (a_a[13]==4294967295u && a_b[13]==4294967295u);
witness_agrees &= (a_a[14]==4294967231u && a_b[14]==4294967231u);
witness_agrees &= (a_a[15]==4294967294u && a_b[15]==4294967294u);
witness_agrees &= (b_a[0]==1u && b_b[0]==1u);
witness_agrees &= (b_a[1]==1u && b_b[1]==1u);
witness_agrees &= (b_a[2]==1u && b_b[2]==1u);
witness_agrees &= (b_a[3]==0u && b_b[3]==0u);
witness_agrees &= (b_a[4]==2048u && b_b[4]==2048u);
witness_agrees &= (b_a[5]==0u && b_b[5]==0u);
witness_agrees &= (b_a[6]==0u && b_b[6]==0u);
witness_agrees &= (b_a[7]==0u && b_b[7]==0u);
witness_agrees &= (b_a[8]==1048577u && b_b[8]==1048577u);
witness_agrees &= (b_a[9]==0u && b_b[9]==0u);
witness_agrees &= (b_a[10]==0u && b_b[10]==0u);
witness_agrees &= (b_a[11]==1u && b_b[11]==1u);
witness_agrees &= (b_a[12]==0u && b_b[12]==0u);
witness_agrees &= (b_a[13]==0u && b_b[13]==0u);
witness_agrees &= (b_a[14]==64u && b_b[14]==64u);
witness_agrees &= (b_a[15]==1u && b_b[15]==1u);
witness_agrees &= (out_a[0]==4294967293u && out_b[0]==0u);
witness_agrees &= (out_a[1]==4294967293u && out_b[1]==0u);
witness_agrees &= (out_a[2]==4294967293u && out_b[2]==0u);
witness_agrees &= (out_a[3]==4294967295u && out_b[3]==0u);
witness_agrees &= (out_a[4]==4294963199u && out_b[4]==0u);
witness_agrees &= (out_a[5]==4294967295u && out_b[5]==0u);
witness_agrees &= (out_a[6]==4294967295u && out_b[6]==0u);
witness_agrees &= (out_a[7]==4294967295u && out_b[7]==0u);
witness_agrees &= (out_a[8]==4292870141u && out_b[8]==0u);
witness_agrees &= (out_a[9]==4294967295u && out_b[9]==0u);
witness_agrees &= (out_a[10]==4294967295u && out_b[10]==0u);
witness_agrees &= (out_a[11]==4294967293u && out_b[11]==0u);
witness_agrees &= (out_a[12]==4294967295u && out_b[12]==0u);
witness_agrees &= (out_a[13]==4294967295u && out_b[13]==0u);
witness_agrees &= (out_a[14]==4294967167u && out_b[14]==0u);
witness_agrees &= (out_a[15]==4294967293u && out_b[15]==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
