#include <stdint.h>
#include <stdio.h>
_Static_assert(sizeof(unsigned)==4,"requires unsigned32");
/* MachSuite-derived; copyright/license and adaptations documented in README.md. */
#include <stdint.h>

void original(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    temp += filter[k1 * 3 + k2] * orig[(r + k1) * 5 + c + k2];
                }
            }
            sol[r * 5 + c] = temp;
        }
    }
}

/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void optimized(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                int base = (r + k1) * 5 + c;
                temp += filter[k1 * 3] * orig[base];
                temp += filter[k1 * 3 + 1] * orig[base + 1];
                temp += filter[k1 * 3 + 2] * orig[base + 2];
            }
            sol[r * 5 + c] = temp;
        }
    }
}

/* Deliberate negative control; see README.md and LICENSE. */
#include <stdint.h>

void buggy(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                int base = (r + k1) * 5 + c;
                temp += filter[k1 * 3] * orig[base];
                temp += filter[k1 * 3 + 2] * orig[base + 1];
                temp += filter[k1 * 3 + 2] * orig[base + 2];
            }
            sol[r * 5 + c] = temp;
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
unsigned failures=0;
for(unsigned t=0;t<264;++t){
uint32_t orig_a[25];
orig_a[0]=next_value(t);
orig_a[1]=next_value(t);
orig_a[2]=next_value(t);
orig_a[3]=next_value(t);
orig_a[4]=next_value(t);
orig_a[5]=next_value(t);
orig_a[6]=next_value(t);
orig_a[7]=next_value(t);
orig_a[8]=next_value(t);
orig_a[9]=next_value(t);
orig_a[10]=next_value(t);
orig_a[11]=next_value(t);
orig_a[12]=next_value(t);
orig_a[13]=next_value(t);
orig_a[14]=next_value(t);
orig_a[15]=next_value(t);
orig_a[16]=next_value(t);
orig_a[17]=next_value(t);
orig_a[18]=next_value(t);
orig_a[19]=next_value(t);
orig_a[20]=next_value(t);
orig_a[21]=next_value(t);
orig_a[22]=next_value(t);
orig_a[23]=next_value(t);
orig_a[24]=next_value(t);
uint32_t sol_a[25];
sol_a[0]=next_value(t);
sol_a[1]=next_value(t);
sol_a[2]=next_value(t);
sol_a[3]=next_value(t);
sol_a[4]=next_value(t);
sol_a[5]=next_value(t);
sol_a[6]=next_value(t);
sol_a[7]=next_value(t);
sol_a[8]=next_value(t);
sol_a[9]=next_value(t);
sol_a[10]=next_value(t);
sol_a[11]=next_value(t);
sol_a[12]=next_value(t);
sol_a[13]=next_value(t);
sol_a[14]=next_value(t);
sol_a[15]=next_value(t);
sol_a[16]=next_value(t);
sol_a[17]=next_value(t);
sol_a[18]=next_value(t);
sol_a[19]=next_value(t);
sol_a[20]=next_value(t);
sol_a[21]=next_value(t);
sol_a[22]=next_value(t);
sol_a[23]=next_value(t);
sol_a[24]=next_value(t);
uint32_t filter_a[9];
filter_a[0]=next_value(t);
filter_a[1]=next_value(t);
filter_a[2]=next_value(t);
filter_a[3]=next_value(t);
filter_a[4]=next_value(t);
filter_a[5]=next_value(t);
filter_a[6]=next_value(t);
filter_a[7]=next_value(t);
filter_a[8]=next_value(t);
uint32_t orig_b[25];
orig_b[0]=orig_a[0];
orig_b[1]=orig_a[1];
orig_b[2]=orig_a[2];
orig_b[3]=orig_a[3];
orig_b[4]=orig_a[4];
orig_b[5]=orig_a[5];
orig_b[6]=orig_a[6];
orig_b[7]=orig_a[7];
orig_b[8]=orig_a[8];
orig_b[9]=orig_a[9];
orig_b[10]=orig_a[10];
orig_b[11]=orig_a[11];
orig_b[12]=orig_a[12];
orig_b[13]=orig_a[13];
orig_b[14]=orig_a[14];
orig_b[15]=orig_a[15];
orig_b[16]=orig_a[16];
orig_b[17]=orig_a[17];
orig_b[18]=orig_a[18];
orig_b[19]=orig_a[19];
orig_b[20]=orig_a[20];
orig_b[21]=orig_a[21];
orig_b[22]=orig_a[22];
orig_b[23]=orig_a[23];
orig_b[24]=orig_a[24];
uint32_t sol_b[25];
sol_b[0]=sol_a[0];
sol_b[1]=sol_a[1];
sol_b[2]=sol_a[2];
sol_b[3]=sol_a[3];
sol_b[4]=sol_a[4];
sol_b[5]=sol_a[5];
sol_b[6]=sol_a[6];
sol_b[7]=sol_a[7];
sol_b[8]=sol_a[8];
sol_b[9]=sol_a[9];
sol_b[10]=sol_a[10];
sol_b[11]=sol_a[11];
sol_b[12]=sol_a[12];
sol_b[13]=sol_a[13];
sol_b[14]=sol_a[14];
sol_b[15]=sol_a[15];
sol_b[16]=sol_a[16];
sol_b[17]=sol_a[17];
sol_b[18]=sol_a[18];
sol_b[19]=sol_a[19];
sol_b[20]=sol_a[20];
sol_b[21]=sol_a[21];
sol_b[22]=sol_a[22];
sol_b[23]=sol_a[23];
sol_b[24]=sol_a[24];
uint32_t filter_b[9];
filter_b[0]=filter_a[0];
filter_b[1]=filter_a[1];
filter_b[2]=filter_a[2];
filter_b[3]=filter_a[3];
filter_b[4]=filter_a[4];
filter_b[5]=filter_a[5];
filter_b[6]=filter_a[6];
filter_b[7]=filter_a[7];
filter_b[8]=filter_a[8];
original(orig_a,sol_a,filter_a);
optimized(orig_b,sol_b,filter_b);
if(orig_a[0]!=orig_b[0] || orig_a[1]!=orig_b[1] || orig_a[2]!=orig_b[2] || orig_a[3]!=orig_b[3] || orig_a[4]!=orig_b[4] || orig_a[5]!=orig_b[5] || orig_a[6]!=orig_b[6] || orig_a[7]!=orig_b[7] || orig_a[8]!=orig_b[8] || orig_a[9]!=orig_b[9] || orig_a[10]!=orig_b[10] || orig_a[11]!=orig_b[11] || orig_a[12]!=orig_b[12] || orig_a[13]!=orig_b[13] || orig_a[14]!=orig_b[14] || orig_a[15]!=orig_b[15] || orig_a[16]!=orig_b[16] || orig_a[17]!=orig_b[17] || orig_a[18]!=orig_b[18] || orig_a[19]!=orig_b[19] || orig_a[20]!=orig_b[20] || orig_a[21]!=orig_b[21] || orig_a[22]!=orig_b[22] || orig_a[23]!=orig_b[23] || orig_a[24]!=orig_b[24] || sol_a[0]!=sol_b[0] || sol_a[1]!=sol_b[1] || sol_a[2]!=sol_b[2] || sol_a[3]!=sol_b[3] || sol_a[4]!=sol_b[4] || sol_a[5]!=sol_b[5] || sol_a[6]!=sol_b[6] || sol_a[7]!=sol_b[7] || sol_a[8]!=sol_b[8] || sol_a[9]!=sol_b[9] || sol_a[10]!=sol_b[10] || sol_a[11]!=sol_b[11] || sol_a[12]!=sol_b[12] || sol_a[13]!=sol_b[13] || sol_a[14]!=sol_b[14] || sol_a[15]!=sol_b[15] || sol_a[16]!=sol_b[16] || sol_a[17]!=sol_b[17] || sol_a[18]!=sol_b[18] || sol_a[19]!=sol_b[19] || sol_a[20]!=sol_b[20] || sol_a[21]!=sol_b[21] || sol_a[22]!=sol_b[22] || sol_a[23]!=sol_b[23] || sol_a[24]!=sol_b[24] || filter_a[0]!=filter_b[0] || filter_a[1]!=filter_b[1] || filter_a[2]!=filter_b[2] || filter_a[3]!=filter_b[3] || filter_a[4]!=filter_b[4] || filter_a[5]!=filter_b[5] || filter_a[6]!=filter_b[6] || filter_a[7]!=filter_b[7] || filter_a[8]!=filter_b[8]) ++failures;
}
{
uint32_t orig_a[25];
orig_a[0]=0u;
orig_a[1]=2614063989u;
orig_a[2]=841993090u;
orig_a[3]=3421799917u;
orig_a[4]=0u;
orig_a[5]=0u;
orig_a[6]=131023708u;
orig_a[7]=1165414319u;
orig_a[8]=1303686571u;
orig_a[9]=0u;
orig_a[10]=0u;
orig_a[11]=1736907631u;
orig_a[12]=1256503197u;
orig_a[13]=851229687u;
orig_a[14]=0u;
orig_a[15]=0u;
orig_a[16]=2741538719u;
orig_a[17]=2839396351u;
orig_a[18]=148481189u;
orig_a[19]=0u;
orig_a[20]=0u;
orig_a[21]=613679104u;
orig_a[22]=1348312814u;
orig_a[23]=452399146u;
orig_a[24]=0u;
uint32_t sol_a[25];
sol_a[0]=0u;
sol_a[1]=0u;
sol_a[2]=0u;
sol_a[3]=0u;
sol_a[4]=0u;
sol_a[5]=0u;
sol_a[6]=0u;
sol_a[7]=0u;
sol_a[8]=0u;
sol_a[9]=0u;
sol_a[10]=0u;
sol_a[11]=0u;
sol_a[12]=0u;
sol_a[13]=0u;
sol_a[14]=0u;
sol_a[15]=0u;
sol_a[16]=0u;
sol_a[17]=0u;
sol_a[18]=0u;
sol_a[19]=0u;
sol_a[20]=0u;
sol_a[21]=0u;
sol_a[22]=0u;
sol_a[23]=0u;
sol_a[24]=0u;
uint32_t filter_a[9];
filter_a[0]=0u;
filter_a[1]=4143817647u;
filter_a[2]=3220709630u;
filter_a[3]=0u;
filter_a[4]=1442304063u;
filter_a[5]=1417443947u;
filter_a[6]=0u;
filter_a[7]=3559586795u;
filter_a[8]=2256206826u;
uint32_t orig_b[25];
orig_b[0]=0u;
orig_b[1]=2614063989u;
orig_b[2]=841993090u;
orig_b[3]=3421799917u;
orig_b[4]=0u;
orig_b[5]=0u;
orig_b[6]=131023708u;
orig_b[7]=1165414319u;
orig_b[8]=1303686571u;
orig_b[9]=0u;
orig_b[10]=0u;
orig_b[11]=1736907631u;
orig_b[12]=1256503197u;
orig_b[13]=851229687u;
orig_b[14]=0u;
orig_b[15]=0u;
orig_b[16]=2741538719u;
orig_b[17]=2839396351u;
orig_b[18]=148481189u;
orig_b[19]=0u;
orig_b[20]=0u;
orig_b[21]=613679104u;
orig_b[22]=1348312814u;
orig_b[23]=452399146u;
orig_b[24]=0u;
uint32_t sol_b[25];
sol_b[0]=0u;
sol_b[1]=0u;
sol_b[2]=0u;
sol_b[3]=0u;
sol_b[4]=0u;
sol_b[5]=0u;
sol_b[6]=0u;
sol_b[7]=0u;
sol_b[8]=0u;
sol_b[9]=0u;
sol_b[10]=0u;
sol_b[11]=0u;
sol_b[12]=0u;
sol_b[13]=0u;
sol_b[14]=0u;
sol_b[15]=0u;
sol_b[16]=0u;
sol_b[17]=0u;
sol_b[18]=0u;
sol_b[19]=0u;
sol_b[20]=0u;
sol_b[21]=0u;
sol_b[22]=0u;
sol_b[23]=0u;
sol_b[24]=0u;
uint32_t filter_b[9];
filter_b[0]=0u;
filter_b[1]=4143817647u;
filter_b[2]=3220709630u;
filter_b[3]=0u;
filter_b[4]=1442304063u;
filter_b[5]=1417443947u;
filter_b[6]=0u;
filter_b[7]=3559586795u;
filter_b[8]=2256206826u;
original(orig_a,sol_a,filter_a);
buggy(orig_b,sol_b,filter_b);
unsigned witness_mismatch=(orig_a[0]!=orig_b[0] || orig_a[1]!=orig_b[1] || orig_a[2]!=orig_b[2] || orig_a[3]!=orig_b[3] || orig_a[4]!=orig_b[4] || orig_a[5]!=orig_b[5] || orig_a[6]!=orig_b[6] || orig_a[7]!=orig_b[7] || orig_a[8]!=orig_b[8] || orig_a[9]!=orig_b[9] || orig_a[10]!=orig_b[10] || orig_a[11]!=orig_b[11] || orig_a[12]!=orig_b[12] || orig_a[13]!=orig_b[13] || orig_a[14]!=orig_b[14] || orig_a[15]!=orig_b[15] || orig_a[16]!=orig_b[16] || orig_a[17]!=orig_b[17] || orig_a[18]!=orig_b[18] || orig_a[19]!=orig_b[19] || orig_a[20]!=orig_b[20] || orig_a[21]!=orig_b[21] || orig_a[22]!=orig_b[22] || orig_a[23]!=orig_b[23] || orig_a[24]!=orig_b[24] || sol_a[0]!=sol_b[0] || sol_a[1]!=sol_b[1] || sol_a[2]!=sol_b[2] || sol_a[3]!=sol_b[3] || sol_a[4]!=sol_b[4] || sol_a[5]!=sol_b[5] || sol_a[6]!=sol_b[6] || sol_a[7]!=sol_b[7] || sol_a[8]!=sol_b[8] || sol_a[9]!=sol_b[9] || sol_a[10]!=sol_b[10] || sol_a[11]!=sol_b[11] || sol_a[12]!=sol_b[12] || sol_a[13]!=sol_b[13] || sol_a[14]!=sol_b[14] || sol_a[15]!=sol_b[15] || sol_a[16]!=sol_b[16] || sol_a[17]!=sol_b[17] || sol_a[18]!=sol_b[18] || sol_a[19]!=sol_b[19] || sol_a[20]!=sol_b[20] || sol_a[21]!=sol_b[21] || sol_a[22]!=sol_b[22] || sol_a[23]!=sol_b[23] || sol_a[24]!=sol_b[24] || filter_a[0]!=filter_b[0] || filter_a[1]!=filter_b[1] || filter_a[2]!=filter_b[2] || filter_a[3]!=filter_b[3] || filter_a[4]!=filter_b[4] || filter_a[5]!=filter_b[5] || filter_a[6]!=filter_b[6] || filter_a[7]!=filter_b[7] || filter_a[8]!=filter_b[8]);
unsigned witness_agrees=1;
witness_agrees &= (orig_a[0]==0u && orig_b[0]==0u);
witness_agrees &= (orig_a[1]==2614063989u && orig_b[1]==2614063989u);
witness_agrees &= (orig_a[2]==841993090u && orig_b[2]==841993090u);
witness_agrees &= (orig_a[3]==3421799917u && orig_b[3]==3421799917u);
witness_agrees &= (orig_a[4]==0u && orig_b[4]==0u);
witness_agrees &= (orig_a[5]==0u && orig_b[5]==0u);
witness_agrees &= (orig_a[6]==131023708u && orig_b[6]==131023708u);
witness_agrees &= (orig_a[7]==1165414319u && orig_b[7]==1165414319u);
witness_agrees &= (orig_a[8]==1303686571u && orig_b[8]==1303686571u);
witness_agrees &= (orig_a[9]==0u && orig_b[9]==0u);
witness_agrees &= (orig_a[10]==0u && orig_b[10]==0u);
witness_agrees &= (orig_a[11]==1736907631u && orig_b[11]==1736907631u);
witness_agrees &= (orig_a[12]==1256503197u && orig_b[12]==1256503197u);
witness_agrees &= (orig_a[13]==851229687u && orig_b[13]==851229687u);
witness_agrees &= (orig_a[14]==0u && orig_b[14]==0u);
witness_agrees &= (orig_a[15]==0u && orig_b[15]==0u);
witness_agrees &= (orig_a[16]==2741538719u && orig_b[16]==2741538719u);
witness_agrees &= (orig_a[17]==2839396351u && orig_b[17]==2839396351u);
witness_agrees &= (orig_a[18]==148481189u && orig_b[18]==148481189u);
witness_agrees &= (orig_a[19]==0u && orig_b[19]==0u);
witness_agrees &= (orig_a[20]==0u && orig_b[20]==0u);
witness_agrees &= (orig_a[21]==613679104u && orig_b[21]==613679104u);
witness_agrees &= (orig_a[22]==1348312814u && orig_b[22]==1348312814u);
witness_agrees &= (orig_a[23]==452399146u && orig_b[23]==452399146u);
witness_agrees &= (orig_a[24]==0u && orig_b[24]==0u);
witness_agrees &= (sol_a[0]==3836864295u && sol_b[0]==3293329827u);
witness_agrees &= (sol_a[1]==2732539507u && sol_b[1]==2444146184u);
witness_agrees &= (sol_a[2]==2085018069u && sol_b[2]==2559808101u);
witness_agrees &= (sol_a[3]==0u && sol_b[3]==0u);
witness_agrees &= (sol_a[4]==0u && sol_b[4]==0u);
witness_agrees &= (sol_a[5]==515920001u && sol_b[5]==4200981338u);
witness_agrees &= (sol_a[6]==3151734034u && sol_b[6]==2423799824u);
witness_agrees &= (sol_a[7]==2077979941u && sol_b[7]==263994297u);
witness_agrees &= (sol_a[8]==0u && sol_b[8]==0u);
witness_agrees &= (sol_a[9]==0u && sol_b[9]==0u);
witness_agrees &= (sol_a[10]==467085545u && sol_b[10]==3121879166u);
witness_agrees &= (sol_a[11]==3498831867u && sol_b[11]==2176121172u);
witness_agrees &= (sol_a[12]==199187458u && sol_b[12]==823510637u);
witness_agrees &= (sol_a[13]==0u && sol_b[13]==0u);
witness_agrees &= (sol_a[14]==0u && sol_b[14]==0u);
witness_agrees &= (sol_a[15]==0u && sol_b[15]==0u);
witness_agrees &= (sol_a[16]==0u && sol_b[16]==0u);
witness_agrees &= (sol_a[17]==0u && sol_b[17]==0u);
witness_agrees &= (sol_a[18]==0u && sol_b[18]==0u);
witness_agrees &= (sol_a[19]==0u && sol_b[19]==0u);
witness_agrees &= (sol_a[20]==0u && sol_b[20]==0u);
witness_agrees &= (sol_a[21]==0u && sol_b[21]==0u);
witness_agrees &= (sol_a[22]==0u && sol_b[22]==0u);
witness_agrees &= (sol_a[23]==0u && sol_b[23]==0u);
witness_agrees &= (sol_a[24]==0u && sol_b[24]==0u);
witness_agrees &= (filter_a[0]==0u && filter_b[0]==0u);
witness_agrees &= (filter_a[1]==4143817647u && filter_b[1]==4143817647u);
witness_agrees &= (filter_a[2]==3220709630u && filter_b[2]==3220709630u);
witness_agrees &= (filter_a[3]==0u && filter_b[3]==0u);
witness_agrees &= (filter_a[4]==1442304063u && filter_b[4]==1442304063u);
witness_agrees &= (filter_a[5]==1417443947u && filter_b[5]==1417443947u);
witness_agrees &= (filter_a[6]==0u && filter_b[6]==0u);
witness_agrees &= (filter_a[7]==3559586795u && filter_b[7]==3559586795u);
witness_agrees &= (filter_a[8]==2256206826u && filter_b[8]==2256206826u);
printf("%u %u %u\n",failures,witness_mismatch,witness_agrees);
return failures || !witness_mismatch || !witness_agrees;
}
}
