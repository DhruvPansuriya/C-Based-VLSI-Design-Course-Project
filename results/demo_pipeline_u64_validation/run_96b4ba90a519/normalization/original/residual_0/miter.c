
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned long long int __hlscheck_nondet_0(void);
unsigned long long int __hlscheck_original(unsigned long long int x)
{
  return x >> 63;
}


unsigned long long int __hlscheck_candidate(unsigned long long int x)
{
  return x >> 63;
}


int main(void) {
unsigned long long int __hlscheck_input_0=__hlscheck_nondet_0();
unsigned long long int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned long long int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
