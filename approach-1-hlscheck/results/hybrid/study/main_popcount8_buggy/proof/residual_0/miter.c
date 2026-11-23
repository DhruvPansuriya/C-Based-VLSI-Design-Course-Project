
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int x)
{
  unsigned int count = 0u;
  for (int i = 0; i < 8; i++)
    count += (x >> i) & 1u;

  return count;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  unsigned int v = x & 255u;
  v = v - ((v >> 1) & 0x55u);
  v = (v & 0x33u) + ((v >> 2) & 0x33u);
  return ((v + (v >> 4)) & 15u) ^ 1u;
}


int main(void) {
unsigned int __hlscheck_input_0=((unsigned int)52ULL);
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
