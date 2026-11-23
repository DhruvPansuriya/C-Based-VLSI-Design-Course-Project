#include <stdint.h>
#include <stdio.h>
/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void original(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
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

/* LLM-authored adaptation; see README.md and LICENSE. */
#include <stdint.h>

void optimized(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint32_t temp = 0u;
            for (int k1 = 0; k1 < 3; k1++) {
                int base = (r + k1) * 5 + c;
                temp += filter[k1 * 3] * orig[base];
                temp += filter[k1 * 3] * orig[base + 1];
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
unsigned failures=0, first=0;
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
if(orig_a[0]!=orig_b[0] || orig_a[1]!=orig_b[1] || orig_a[2]!=orig_b[2] || orig_a[3]!=orig_b[3] || orig_a[4]!=orig_b[4] || orig_a[5]!=orig_b[5] || orig_a[6]!=orig_b[6] || orig_a[7]!=orig_b[7] || orig_a[8]!=orig_b[8] || orig_a[9]!=orig_b[9] || orig_a[10]!=orig_b[10] || orig_a[11]!=orig_b[11] || orig_a[12]!=orig_b[12] || orig_a[13]!=orig_b[13] || orig_a[14]!=orig_b[14] || orig_a[15]!=orig_b[15] || orig_a[16]!=orig_b[16] || orig_a[17]!=orig_b[17] || orig_a[18]!=orig_b[18] || orig_a[19]!=orig_b[19] || orig_a[20]!=orig_b[20] || orig_a[21]!=orig_b[21] || orig_a[22]!=orig_b[22] || orig_a[23]!=orig_b[23] || orig_a[24]!=orig_b[24] || sol_a[0]!=sol_b[0] || sol_a[1]!=sol_b[1] || sol_a[2]!=sol_b[2] || sol_a[3]!=sol_b[3] || sol_a[4]!=sol_b[4] || sol_a[5]!=sol_b[5] || sol_a[6]!=sol_b[6] || sol_a[7]!=sol_b[7] || sol_a[8]!=sol_b[8] || sol_a[9]!=sol_b[9] || sol_a[10]!=sol_b[10] || sol_a[11]!=sol_b[11] || sol_a[12]!=sol_b[12] || sol_a[13]!=sol_b[13] || sol_a[14]!=sol_b[14] || sol_a[15]!=sol_b[15] || sol_a[16]!=sol_b[16] || sol_a[17]!=sol_b[17] || sol_a[18]!=sol_b[18] || sol_a[19]!=sol_b[19] || sol_a[20]!=sol_b[20] || sol_a[21]!=sol_b[21] || sol_a[22]!=sol_b[22] || sol_a[23]!=sol_b[23] || sol_a[24]!=sol_b[24] || filter_a[0]!=filter_b[0] || filter_a[1]!=filter_b[1] || filter_a[2]!=filter_b[2] || filter_a[3]!=filter_b[3] || filter_a[4]!=filter_b[4] || filter_a[5]!=filter_b[5] || filter_a[6]!=filter_b[6] || filter_a[7]!=filter_b[7] || filter_a[8]!=filter_b[8]){ if(!failures)first=t; ++failures; }
}
unsigned witness_mismatch=0, witness_agrees=0;
{
uint32_t orig_a[25];
orig_a[0]=0u;
orig_a[1]=2283919664u;
orig_a[2]=728543567u;
orig_a[3]=3406826599u;
orig_a[4]=0u;
orig_a[5]=0u;
orig_a[6]=359656704u;
orig_a[7]=2938774365u;
orig_a[8]=378334414u;
orig_a[9]=0u;
orig_a[10]=0u;
orig_a[11]=3375844466u;
orig_a[12]=2354514447u;
orig_a[13]=198368256u;
orig_a[14]=0u;
orig_a[15]=0u;
orig_a[16]=935160474u;
orig_a[17]=3295128464u;
orig_a[18]=2248373241u;
orig_a[19]=0u;
orig_a[20]=0u;
orig_a[21]=3949846451u;
orig_a[22]=3810956116u;
orig_a[23]=696056001u;
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
filter_a[0]=2696508894u;
filter_a[1]=14519775u;
filter_a[2]=0u;
filter_a[3]=1631895540u;
filter_a[4]=479682560u;
filter_a[5]=0u;
filter_a[6]=3810834366u;
filter_a[7]=2692151231u;
filter_a[8]=0u;
uint32_t orig_b[25];
orig_b[0]=0u;
orig_b[1]=2283919664u;
orig_b[2]=728543567u;
orig_b[3]=3406826599u;
orig_b[4]=0u;
orig_b[5]=0u;
orig_b[6]=359656704u;
orig_b[7]=2938774365u;
orig_b[8]=378334414u;
orig_b[9]=0u;
orig_b[10]=0u;
orig_b[11]=3375844466u;
orig_b[12]=2354514447u;
orig_b[13]=198368256u;
orig_b[14]=0u;
orig_b[15]=0u;
orig_b[16]=935160474u;
orig_b[17]=3295128464u;
orig_b[18]=2248373241u;
orig_b[19]=0u;
orig_b[20]=0u;
orig_b[21]=3949846451u;
orig_b[22]=3810956116u;
orig_b[23]=696056001u;
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
filter_b[0]=2696508894u;
filter_b[1]=14519775u;
filter_b[2]=0u;
filter_b[3]=1631895540u;
filter_b[4]=479682560u;
filter_b[5]=0u;
filter_b[6]=3810834366u;
filter_b[7]=2692151231u;
filter_b[8]=0u;
original(orig_a,sol_a,filter_a);
optimized(orig_b,sol_b,filter_b);
witness_mismatch=(orig_a[0]!=orig_b[0] || orig_a[1]!=orig_b[1] || orig_a[2]!=orig_b[2] || orig_a[3]!=orig_b[3] || orig_a[4]!=orig_b[4] || orig_a[5]!=orig_b[5] || orig_a[6]!=orig_b[6] || orig_a[7]!=orig_b[7] || orig_a[8]!=orig_b[8] || orig_a[9]!=orig_b[9] || orig_a[10]!=orig_b[10] || orig_a[11]!=orig_b[11] || orig_a[12]!=orig_b[12] || orig_a[13]!=orig_b[13] || orig_a[14]!=orig_b[14] || orig_a[15]!=orig_b[15] || orig_a[16]!=orig_b[16] || orig_a[17]!=orig_b[17] || orig_a[18]!=orig_b[18] || orig_a[19]!=orig_b[19] || orig_a[20]!=orig_b[20] || orig_a[21]!=orig_b[21] || orig_a[22]!=orig_b[22] || orig_a[23]!=orig_b[23] || orig_a[24]!=orig_b[24] || sol_a[0]!=sol_b[0] || sol_a[1]!=sol_b[1] || sol_a[2]!=sol_b[2] || sol_a[3]!=sol_b[3] || sol_a[4]!=sol_b[4] || sol_a[5]!=sol_b[5] || sol_a[6]!=sol_b[6] || sol_a[7]!=sol_b[7] || sol_a[8]!=sol_b[8] || sol_a[9]!=sol_b[9] || sol_a[10]!=sol_b[10] || sol_a[11]!=sol_b[11] || sol_a[12]!=sol_b[12] || sol_a[13]!=sol_b[13] || sol_a[14]!=sol_b[14] || sol_a[15]!=sol_b[15] || sol_a[16]!=sol_b[16] || sol_a[17]!=sol_b[17] || sol_a[18]!=sol_b[18] || sol_a[19]!=sol_b[19] || sol_a[20]!=sol_b[20] || sol_a[21]!=sol_b[21] || sol_a[22]!=sol_b[22] || sol_a[23]!=sol_b[23] || sol_a[24]!=sol_b[24] || filter_a[0]!=filter_b[0] || filter_a[1]!=filter_b[1] || filter_a[2]!=filter_b[2] || filter_a[3]!=filter_b[3] || filter_a[4]!=filter_b[4] || filter_a[5]!=filter_b[5] || filter_a[6]!=filter_b[6] || filter_a[7]!=filter_b[7] || filter_a[8]!=filter_b[8]);
witness_agrees=1;
witness_agrees &= (orig_a[0]==0u && orig_b[0]==0u);
witness_agrees &= (orig_a[1]==2283919664u && orig_b[1]==2283919664u);
witness_agrees &= (orig_a[2]==728543567u && orig_b[2]==728543567u);
witness_agrees &= (orig_a[3]==3406826599u && orig_b[3]==3406826599u);
witness_agrees &= (orig_a[4]==0u && orig_b[4]==0u);
witness_agrees &= (orig_a[5]==0u && orig_b[5]==0u);
witness_agrees &= (orig_a[6]==359656704u && orig_b[6]==359656704u);
witness_agrees &= (orig_a[7]==2938774365u && orig_b[7]==2938774365u);
witness_agrees &= (orig_a[8]==378334414u && orig_b[8]==378334414u);
witness_agrees &= (orig_a[9]==0u && orig_b[9]==0u);
witness_agrees &= (orig_a[10]==0u && orig_b[10]==0u);
witness_agrees &= (orig_a[11]==3375844466u && orig_b[11]==3375844466u);
witness_agrees &= (orig_a[12]==2354514447u && orig_b[12]==2354514447u);
witness_agrees &= (orig_a[13]==198368256u && orig_b[13]==198368256u);
witness_agrees &= (orig_a[14]==0u && orig_b[14]==0u);
witness_agrees &= (orig_a[15]==0u && orig_b[15]==0u);
witness_agrees &= (orig_a[16]==935160474u && orig_b[16]==935160474u);
witness_agrees &= (orig_a[17]==3295128464u && orig_b[17]==3295128464u);
witness_agrees &= (orig_a[18]==2248373241u && orig_b[18]==2248373241u);
witness_agrees &= (orig_a[19]==0u && orig_b[19]==0u);
witness_agrees &= (orig_a[20]==0u && orig_b[20]==0u);
witness_agrees &= (orig_a[21]==3949846451u && orig_b[21]==3949846451u);
witness_agrees &= (orig_a[22]==3810956116u && orig_b[22]==3810956116u);
witness_agrees &= (orig_a[23]==696056001u && orig_b[23]==696056001u);
witness_agrees &= (orig_a[24]==0u && orig_b[24]==0u);
witness_agrees &= (sol_a[0]==1945872350u && sol_b[0]==310797884u);
witness_agrees &= (sol_a[1]==1555904318u && sol_b[1]==135170948u);
witness_agrees &= (sol_a[2]==522719745u && sol_b[2]==3272058866u);
witness_agrees &= (sol_a[3]==0u && sol_b[3]==0u);
witness_agrees &= (sol_a[4]==0u && sol_b[4]==0u);
witness_agrees &= (sol_a[5]==4061811174u && sol_b[5]==3755451636u);
witness_agrees &= (sol_a[6]==221199463u && sol_b[6]==1980292294u);
witness_agrees &= (sol_a[7]==2213919499u && sol_b[7]==2098690628u);
witness_agrees &= (sol_a[8]==0u && sol_b[8]==0u);
witness_agrees &= (sol_a[9]==0u && sol_b[9]==0u);
witness_agrees &= (sol_a[10]==567393499u && sol_b[10]==3571573118u);
witness_agrees &= (sol_a[11]==2703023931u && sol_b[11]==10407704u);
witness_agrees &= (sol_a[12]==1210630297u && sol_b[12]==2077203500u);
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
witness_agrees &= (filter_a[0]==2696508894u && filter_b[0]==2696508894u);
witness_agrees &= (filter_a[1]==14519775u && filter_b[1]==14519775u);
witness_agrees &= (filter_a[2]==0u && filter_b[2]==0u);
witness_agrees &= (filter_a[3]==1631895540u && filter_b[3]==1631895540u);
witness_agrees &= (filter_a[4]==479682560u && filter_b[4]==479682560u);
witness_agrees &= (filter_a[5]==0u && filter_b[5]==0u);
witness_agrees &= (filter_a[6]==3810834366u && filter_b[6]==3810834366u);
witness_agrees &= (filter_a[7]==2692151231u && filter_b[7]==2692151231u);
witness_agrees &= (filter_a[8]==0u && filter_b[8]==0u);
}
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
