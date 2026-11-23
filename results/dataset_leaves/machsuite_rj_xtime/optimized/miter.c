#include <stdint.h>
uint8_t __original(uint8_t x)
{
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}

uint8_t __candidate(uint8_t x){return (x<<1)^((x>>7)*0x1b);}

_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

extern void __ESBMC_assert(_Bool, const char*);
extern unsigned char nondet_0(void);
int main(void){
unsigned char input_0=nondet_0();
uint8_t left=__original(input_0),right=__candidate(input_0);
__ESBMC_assert(left==right,"EQUIV:return");return 0;}
