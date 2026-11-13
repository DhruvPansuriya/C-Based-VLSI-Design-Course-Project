
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int a[8])
{
  unsigned int lo = 0u;
  unsigned int hi = 0u;
  for (int i = 0; i < 4; i++)
  {
    lo |= ((a[i] > 128u) ? (1u) : (0u)) << i;
    hi |= ((a[i + 4] > 128u) ? (1u) : (0u)) << i;
  }

  return lo | (hi << 4);
}


unsigned int __hlscheck_candidate(unsigned int a[8])
{
  unsigned int lo = 0u;
  unsigned int hi = 0u;
  for (int i = 0; i < 4; i++)
  {
    lo |= ((a[i] >= 128u) ? (1u) : (0u)) << i;
    hi |= ((a[i + 4] > 128u) ? (1u) : (0u)) << i;
  }

  return lo | (hi << 4);
}


int main(void) {
unsigned int __hlscheck_input_0[8]={((unsigned int)128ULL),((unsigned int)128ULL),((unsigned int)128ULL),((unsigned int)1073741954ULL),((unsigned int)1ULL),((unsigned int)385ULL),((unsigned int)2ULL),((unsigned int)1ULL)};
unsigned int __hlscheck_left_0[8], __hlscheck_right_0[8];
__hlscheck_left_0[0]=__hlscheck_input_0[0];
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_left_0[1]=__hlscheck_input_0[1];
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_left_0[2]=__hlscheck_input_0[2];
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_left_0[3]=__hlscheck_input_0[3];
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_left_0[4]=__hlscheck_input_0[4];
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_left_0[5]=__hlscheck_input_0[5];
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_left_0[6]=__hlscheck_input_0[6];
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_left_0[7]=__hlscheck_input_0[7];
__hlscheck_right_0[7]=__hlscheck_left_0[7];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
