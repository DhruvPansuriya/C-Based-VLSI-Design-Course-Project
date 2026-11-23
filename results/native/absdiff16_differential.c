#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
#include <stdint.h>

/* Educational fixed-size uint32_t original, authored independently in this Codex session.
   Reference implementation. */
void original(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++) out[i]=a[i]>b[i]?a[i]-b[i]:b[i]-a[i];
}

#include <stdint.h>

/* Educational fixed-size uint32_t optimized, authored independently in this Codex session.
   Share comparison before subtraction. */
void optimized(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?y:x;out[i]=high-low;}
}

#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
void buggy(uint32_t a[16], uint32_t b[16], uint32_t out[16]) {
    for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?y:x;out[i]=high-low;}
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
if(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]) ++failures;
}
{
uint32_t a_a[16];
a_a[0]=3766616085u;
a_a[1]=2147483648u;
a_a[2]=67108864u;
a_a[3]=134217728u;
a_a[4]=2172658320u;
a_a[5]=1288241160u;
a_a[6]=3120562176u;
a_a[7]=1342525952u;
a_a[8]=2751463424u;
a_a[9]=1077936128u;
a_a[10]=1073741824u;
a_a[11]=1073776640u;
a_a[12]=1182894503u;
a_a[13]=1219717120u;
a_a[14]=1081888769u;
a_a[15]=2160353368u;
uint32_t b_a[16];
b_a[0]=2756186129u;
b_a[1]=72u;
b_a[2]=218103808u;
b_a[3]=3007381504u;
b_a[4]=67126586u;
b_a[5]=895975424u;
b_a[6]=0u;
b_a[7]=269659399u;
b_a[8]=1477888000u;
b_a[9]=488751104u;
b_a[10]=100663296u;
b_a[11]=8394752u;
b_a[12]=1631601281u;
b_a[13]=56213504u;
b_a[14]=268480512u;
b_a[15]=1360753684u;
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
a_b[0]=3766616085u;
a_b[1]=2147483648u;
a_b[2]=67108864u;
a_b[3]=134217728u;
a_b[4]=2172658320u;
a_b[5]=1288241160u;
a_b[6]=3120562176u;
a_b[7]=1342525952u;
a_b[8]=2751463424u;
a_b[9]=1077936128u;
a_b[10]=1073741824u;
a_b[11]=1073776640u;
a_b[12]=1182894503u;
a_b[13]=1219717120u;
a_b[14]=1081888769u;
a_b[15]=2160353368u;
uint32_t b_b[16];
b_b[0]=2756186129u;
b_b[1]=72u;
b_b[2]=218103808u;
b_b[3]=3007381504u;
b_b[4]=67126586u;
b_b[5]=895975424u;
b_b[6]=0u;
b_b[7]=269659399u;
b_b[8]=1477888000u;
b_b[9]=488751104u;
b_b[10]=100663296u;
b_b[11]=8394752u;
b_b[12]=1631601281u;
b_b[13]=56213504u;
b_b[14]=268480512u;
b_b[15]=1360753684u;
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
buggy(a_b,b_b,out_b);
unsigned witness_mismatch=(a_a[0]!=a_b[0] || a_a[1]!=a_b[1] || a_a[2]!=a_b[2] || a_a[3]!=a_b[3] || a_a[4]!=a_b[4] || a_a[5]!=a_b[5] || a_a[6]!=a_b[6] || a_a[7]!=a_b[7] || a_a[8]!=a_b[8] || a_a[9]!=a_b[9] || a_a[10]!=a_b[10] || a_a[11]!=a_b[11] || a_a[12]!=a_b[12] || a_a[13]!=a_b[13] || a_a[14]!=a_b[14] || a_a[15]!=a_b[15] || b_a[0]!=b_b[0] || b_a[1]!=b_b[1] || b_a[2]!=b_b[2] || b_a[3]!=b_b[3] || b_a[4]!=b_b[4] || b_a[5]!=b_b[5] || b_a[6]!=b_b[6] || b_a[7]!=b_b[7] || b_a[8]!=b_b[8] || b_a[9]!=b_b[9] || b_a[10]!=b_b[10] || b_a[11]!=b_b[11] || b_a[12]!=b_b[12] || b_a[13]!=b_b[13] || b_a[14]!=b_b[14] || b_a[15]!=b_b[15] || out_a[0]!=out_b[0] || out_a[1]!=out_b[1] || out_a[2]!=out_b[2] || out_a[3]!=out_b[3] || out_a[4]!=out_b[4] || out_a[5]!=out_b[5] || out_a[6]!=out_b[6] || out_a[7]!=out_b[7] || out_a[8]!=out_b[8] || out_a[9]!=out_b[9] || out_a[10]!=out_b[10] || out_a[11]!=out_b[11] || out_a[12]!=out_b[12] || out_a[13]!=out_b[13] || out_a[14]!=out_b[14] || out_a[15]!=out_b[15]);
unsigned witness_agrees=1;
witness_agrees &= (a_a[0]==3766616085u && a_b[0]==3766616085u);
witness_agrees &= (a_a[1]==2147483648u && a_b[1]==2147483648u);
witness_agrees &= (a_a[2]==67108864u && a_b[2]==67108864u);
witness_agrees &= (a_a[3]==134217728u && a_b[3]==134217728u);
witness_agrees &= (a_a[4]==2172658320u && a_b[4]==2172658320u);
witness_agrees &= (a_a[5]==1288241160u && a_b[5]==1288241160u);
witness_agrees &= (a_a[6]==3120562176u && a_b[6]==3120562176u);
witness_agrees &= (a_a[7]==1342525952u && a_b[7]==1342525952u);
witness_agrees &= (a_a[8]==2751463424u && a_b[8]==2751463424u);
witness_agrees &= (a_a[9]==1077936128u && a_b[9]==1077936128u);
witness_agrees &= (a_a[10]==1073741824u && a_b[10]==1073741824u);
witness_agrees &= (a_a[11]==1073776640u && a_b[11]==1073776640u);
witness_agrees &= (a_a[12]==1182894503u && a_b[12]==1182894503u);
witness_agrees &= (a_a[13]==1219717120u && a_b[13]==1219717120u);
witness_agrees &= (a_a[14]==1081888769u && a_b[14]==1081888769u);
witness_agrees &= (a_a[15]==2160353368u && a_b[15]==2160353368u);
witness_agrees &= (b_a[0]==2756186129u && b_b[0]==2756186129u);
witness_agrees &= (b_a[1]==72u && b_b[1]==72u);
witness_agrees &= (b_a[2]==218103808u && b_b[2]==218103808u);
witness_agrees &= (b_a[3]==3007381504u && b_b[3]==3007381504u);
witness_agrees &= (b_a[4]==67126586u && b_b[4]==67126586u);
witness_agrees &= (b_a[5]==895975424u && b_b[5]==895975424u);
witness_agrees &= (b_a[6]==0u && b_b[6]==0u);
witness_agrees &= (b_a[7]==269659399u && b_b[7]==269659399u);
witness_agrees &= (b_a[8]==1477888000u && b_b[8]==1477888000u);
witness_agrees &= (b_a[9]==488751104u && b_b[9]==488751104u);
witness_agrees &= (b_a[10]==100663296u && b_b[10]==100663296u);
witness_agrees &= (b_a[11]==8394752u && b_b[11]==8394752u);
witness_agrees &= (b_a[12]==1631601281u && b_b[12]==1631601281u);
witness_agrees &= (b_a[13]==56213504u && b_b[13]==56213504u);
witness_agrees &= (b_a[14]==268480512u && b_b[14]==268480512u);
witness_agrees &= (b_a[15]==1360753684u && b_b[15]==1360753684u);
witness_agrees &= (out_a[0]==1010429956u && out_b[0]==1010429957u);
witness_agrees &= (out_a[1]==2147483576u && out_b[1]==2147483576u);
witness_agrees &= (out_a[2]==150994944u && out_b[2]==150994944u);
witness_agrees &= (out_a[3]==2873163776u && out_b[3]==2873163776u);
witness_agrees &= (out_a[4]==2105531734u && out_b[4]==2105531734u);
witness_agrees &= (out_a[5]==392265736u && out_b[5]==392265736u);
witness_agrees &= (out_a[6]==3120562176u && out_b[6]==3120562176u);
witness_agrees &= (out_a[7]==1072866553u && out_b[7]==1072866553u);
witness_agrees &= (out_a[8]==1273575424u && out_b[8]==1273575424u);
witness_agrees &= (out_a[9]==589185024u && out_b[9]==589185024u);
witness_agrees &= (out_a[10]==973078528u && out_b[10]==973078528u);
witness_agrees &= (out_a[11]==1065381888u && out_b[11]==1065381888u);
witness_agrees &= (out_a[12]==448706778u && out_b[12]==448706778u);
witness_agrees &= (out_a[13]==1163503616u && out_b[13]==1163503616u);
witness_agrees &= (out_a[14]==813408257u && out_b[14]==813408257u);
witness_agrees &= (out_a[15]==799599684u && out_b[15]==799599684u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
