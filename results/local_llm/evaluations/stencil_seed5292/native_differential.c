#include <stdint.h>
#include <stdio.h>
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

#include <stdint.h>

void optimized(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9]) {
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
printf("%u %u %u %u\n", failures, first, witness_mismatch, witness_agrees);
return 0; }
