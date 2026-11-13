
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 32; i++)
  {
    y = (y << 1) | (x & 1u);
    x = x >> 1;
  }

  return y;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 32; i += 4)
  {
    y = (y << 16) | (x & 3u);
    y = (y << 16) | (x >> 2);
    y = (y << 16) | (x >> 4);
    x >>= 8;
  }

  return y;
}


int main(void) {
unsigned int __hlscheck_input_0=((unsigned int)2581227938ULL);
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
