typedef unsigned long long int bits64;
typedef unsigned long long float64;
bits64 __original(float64 a) { return a & 0x000FFFFFFFFFFFFFLL; }

bits64 __candidate(float64 a){return (a<<12)>>12;}

_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

extern void __ESBMC_assert(_Bool, const char*);
extern unsigned long long nondet_0(void);
int main(void){
unsigned long long input_0=nondet_0();
bits64 left=__original(input_0),right=__candidate(input_0);
__ESBMC_assert(left==right,"EQUIV:return");return 0;}
