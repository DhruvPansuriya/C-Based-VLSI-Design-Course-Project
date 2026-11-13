
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int x)
{
  return x * 13u;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  return x * 11u;
}


int main(void) {
unsigned int __hlscheck_input_0=((unsigned int)1073741824ULL);
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert(__hlscheck_left_return==__hlscheck_right_return,"EQUIV:return");
return 0;
}
