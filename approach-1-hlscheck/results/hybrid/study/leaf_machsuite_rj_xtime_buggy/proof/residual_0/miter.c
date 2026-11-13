
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned char __hlscheck_nondet_0(void);
unsigned char __hlscheck_original(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


unsigned char __hlscheck_candidate(unsigned char x)
{
  return (x << 1) ^ ((x >> 7) * 0x1d);
}


int main(void) {
unsigned char __hlscheck_input_0=__hlscheck_nondet_0();
unsigned char __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned char __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
