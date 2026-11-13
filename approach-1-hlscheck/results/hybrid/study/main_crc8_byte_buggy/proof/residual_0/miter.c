
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 8; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 4; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc ^ 1u;
}


int main(void) {
unsigned int __hlscheck_input_0=((unsigned int)0ULL);
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
