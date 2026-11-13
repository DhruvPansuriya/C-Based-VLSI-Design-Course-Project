#include <stdint.h>
#include <stdio.h>
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Hoist the row scalar and expand a rank-one update. */
void original(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16]) {
    for(int r=0;r<4;r++){uint32_t v=x[r];out[r*4]=a[r*4]+v*y[0];out[r*4+1]=a[r*4+1]+v*y[1];out[r*4+2]=a[r*4+2]+v*y[2];out[r*4+3]=a[r*4+3]+v*y[3];}
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Hoist the row scalar and expand a rank-one update. */
void optimized(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16]) {
    for(int r=0;r<4;r++){uint32_t v=x[r];out[r*4]=a[r*4]+v*y[0];out[r*4+1]=a[r*4+1]+v*y[1];out[r*4+2]=a[r*4+2]+v*y[2];out[r*4+3]=a[r*4+3]+v*y[2];}
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
uint32_t x_a[4];
x_a[0]=next_value(t);
x_a[1]=next_value(t);
x_a[2]=next_value(t);
x_a[3]=next_value(t);
uint32_t y_a[4];
y_a[0]=next_value(t);
y_a[1]=next_value(t);
y_a[2]=next_value(t);
y_a[3]=next_value(t);
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
uint32_t x_b[4];
x_b[0]=x_a[0];
x_b[1]=x_a[1];
x_b[2]=x_a[2];
x_b[3]=x_a[3];
uint32_t y_b[4];
y_b[0]=y_a[0];
y_b[1]=y_a[1];
y_b[2]=y_a[2];
y_b[3]=y_a[3];
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
original(a_a,x_a,y_a,out_a);
optimized(a_b,x_b,y_b,out_b);
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || x_a[0]!=x_b[0] || x_a[1]!=x_b[1] || x_a[2]!=x_b[2] || x_a[3]!=x_b[3] || y_a[0]!=y_b[0] || y_a[1]!=y_b[1] || y_a[2]!=y_b[2] || y_a[3]!=y_b[3] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t a_a[16];
a_a[0]=0u;
a_a[1]=0u;
a_a[2]=0u;
a_a[3]=0u;
a_a[4]=0u;
a_a[5]=0u;
a_a[6]=0u;
a_a[7]=0u;
a_a[8]=0u;
a_a[9]=0u;
a_a[10]=0u;
a_a[11]=0u;
a_a[12]=0u;
a_a[13]=0u;
a_a[14]=0u;
a_a[15]=0u;
uint32_t x_a[4];
x_a[0]=225276076u;
x_a[1]=1148970730u;
x_a[2]=3995441905u;
x_a[3]=3405511665u;
uint32_t y_a[4];
y_a[0]=0u;
y_a[1]=0u;
y_a[2]=848033791u;
y_a[3]=1984164336u;
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
a_b[0]=0u;
a_b[1]=0u;
a_b[2]=0u;
a_b[3]=0u;
a_b[4]=0u;
a_b[5]=0u;
a_b[6]=0u;
a_b[7]=0u;
a_b[8]=0u;
a_b[9]=0u;
a_b[10]=0u;
a_b[11]=0u;
a_b[12]=0u;
a_b[13]=0u;
a_b[14]=0u;
a_b[15]=0u;
uint32_t x_b[4];
x_b[0]=225276076u;
x_b[1]=1148970730u;
x_b[2]=3995441905u;
x_b[3]=3405511665u;
uint32_t y_b[4];
y_b[0]=0u;
y_b[1]=0u;
y_b[2]=848033791u;
y_b[3]=1984164336u;
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
original(a_a,x_a,y_a,out_a);
optimized(a_b,x_b,y_b,out_b);
witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || x_a[0]!=x_b[0] || x_a[1]!=x_b[1] || x_a[2]!=x_b[2] || x_a[3]!=x_b[3] || y_a[0]!=y_b[0] || y_a[1]!=y_b[1] || y_a[2]!=y_b[2] || y_a[3]!=y_b[3] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]);
witness_agrees=1;
witness_agrees &= (a_a[0]==0u && a_b[0]==0u);
witness_agrees &= (a_a[1]==0u && a_b[1]==0u);
witness_agrees &= (a_a[2]==0u && a_b[2]==0u);
witness_agrees &= (a_a[3]==0u && a_b[3]==0u);
witness_agrees &= (a_a[4]==0u && a_b[4]==0u);
witness_agrees &= (a_a[5]==0u && a_b[5]==0u);
witness_agrees &= (a_a[6]==0u && a_b[6]==0u);
witness_agrees &= (a_a[7]==0u && a_b[7]==0u);
witness_agrees &= (a_a[8]==0u && a_b[8]==0u);
witness_agrees &= (a_a[9]==0u && a_b[9]==0u);
witness_agrees &= (a_a[10]==0u && a_b[10]==0u);
witness_agrees &= (a_a[11]==0u && a_b[11]==0u);
witness_agrees &= (a_a[12]==0u && a_b[12]==0u);
witness_agrees &= (a_a[13]==0u && a_b[13]==0u);
witness_agrees &= (a_a[14]==0u && a_b[14]==0u);
witness_agrees &= (a_a[15]==0u && a_b[15]==0u);
witness_agrees &= (x_a[0]==225276076u && x_b[0]==225276076u);
witness_agrees &= (x_a[1]==1148970730u && x_b[1]==1148970730u);
witness_agrees &= (x_a[2]==3995441905u && x_b[2]==3995441905u);
witness_agrees &= (x_a[3]==3405511665u && x_b[3]==3405511665u);
witness_agrees &= (y_a[0]==0u && y_b[0]==0u);
witness_agrees &= (y_a[1]==0u && y_b[1]==0u);
witness_agrees &= (y_a[2]==848033791u && y_b[2]==848033791u);
witness_agrees &= (y_a[3]==1984164336u && y_b[3]==1984164336u);
witness_agrees &= (out_a[0]==0u && out_b[0]==0u);
witness_agrees &= (out_a[1]==0u && out_b[1]==0u);
witness_agrees &= (out_a[2]==3172806484u && out_b[2]==3172806484u);
witness_agrees &= (out_a[3]==1655672128u && out_b[3]==3172806484u);
witness_agrees &= (out_a[4]==0u && out_b[4]==0u);
witness_agrees &= (out_a[5]==0u && out_b[5]==0u);
witness_agrees &= (out_a[6]==3628386582u && out_b[6]==3628386582u);
witness_agrees &= (out_a[7]==600360288u && out_b[7]==3628386582u);
witness_agrees &= (out_a[8]==0u && out_b[8]==0u);
witness_agrees &= (out_a[9]==0u && out_b[9]==0u);
witness_agrees &= (out_a[10]==2999901455u && out_b[10]==2999901455u);
witness_agrees &= (out_a[11]==1295065840u && out_b[11]==2999901455u);
witness_agrees &= (out_a[12]==0u && out_b[12]==0u);
witness_agrees &= (out_a[13]==0u && out_b[13]==0u);
witness_agrees &= (out_a[14]==787512335u && out_b[14]==787512335u);
witness_agrees &= (out_a[15]==2323452656u && out_b[15]==787512335u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
