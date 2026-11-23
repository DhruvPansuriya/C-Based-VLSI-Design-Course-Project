typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;
flag __original(float64 a) {
    return (0xFFE0000000000000LL < (bits64)(a << 1));
}

flag __candidate(float64 a){return ((a & 0x7FF0000000000000ULL)==0x7FF0000000000000ULL) && ((a & 0x000FFFFFFFFFFFFFULL)!=0);}

_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

extern void __ESBMC_assert(_Bool, const char*);
extern unsigned long long nondet_0(void);
int main(void){
unsigned long long input_0=nondet_0();
flag left=__original(input_0),right=__candidate(input_0);
__ESBMC_assert(left==right,"EQUIV:return");return 0;}
