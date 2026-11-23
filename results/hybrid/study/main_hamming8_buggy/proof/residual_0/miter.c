
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
unsigned int __hlscheck_original(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] ^ b[i]) & 255u;
    for (int bit = 0; bit < 8; bit++)
      total += (v >> bit) & 1u;

  }

  return total;
}


unsigned int __hlscheck_candidate(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] ^ b[i]) & 255u;
    v -= (v >> 1) & 0x55u;
    v = (v & 0x33u) + ((v >> 2) & 0x33u);
    total += (v + (v >> 4)) & 15u;
  }

  return total ^ 1u;
}


int main(void) {
unsigned int __hlscheck_input_0[8]={((unsigned int)45ULL),((unsigned int)28ULL),((unsigned int)227ULL),((unsigned int)106ULL),((unsigned int)12ULL),((unsigned int)170ULL),((unsigned int)130ULL),((unsigned int)149ULL)};
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
unsigned int __hlscheck_input_1[8]={((unsigned int)194ULL),((unsigned int)73ULL),((unsigned int)12ULL),((unsigned int)149ULL),((unsigned int)208ULL),((unsigned int)5ULL),((unsigned int)73ULL),((unsigned int)106ULL)};
unsigned int __hlscheck_left_1[8], __hlscheck_right_1[8];
__hlscheck_left_1[0]=__hlscheck_input_1[0];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_input_1[1];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_input_1[2];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_input_1[3];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
__hlscheck_left_1[4]=__hlscheck_input_1[4];
__hlscheck_right_1[4]=__hlscheck_left_1[4];
__hlscheck_left_1[5]=__hlscheck_input_1[5];
__hlscheck_right_1[5]=__hlscheck_left_1[5];
__hlscheck_left_1[6]=__hlscheck_input_1[6];
__hlscheck_right_1[6]=__hlscheck_left_1[6];
__hlscheck_left_1[7]=__hlscheck_input_1[7];
__hlscheck_right_1[7]=__hlscheck_left_1[7];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
