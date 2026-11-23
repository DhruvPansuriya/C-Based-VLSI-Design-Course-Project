
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern short int __hlscheck_nondet_0(void);
short int __hlscheck_original(short int a)
{
  return (a < 0) ? ((a == ((-32767) - 1)) ? (32767) : (-a)) : (a);
}


short int __hlscheck_candidate(short int a)
{
  unsigned short int bits = (unsigned short int) a;
  unsigned short int sign = (unsigned short int) (0u - (bits >> 15));
  unsigned short int magnitude = (unsigned short int) ((bits ^ sign) + (bits >> 15));
  return (short int) (magnitude - (magnitude >> 15));
}


int main(void) {
short int __hlscheck_input_0=__hlscheck_nondet_0();
short int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
short int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
