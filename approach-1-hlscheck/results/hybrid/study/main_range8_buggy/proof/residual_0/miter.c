
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int a[8])
{
  unsigned int low = a[0];
  unsigned int high = a[0];
  for (int i = 1; i < 8; i++)
    low = (a[i] < low) ? (a[i]) : (low);

  for (int j = 1; j < 8; j++)
    high = (a[j] > high) ? (a[j]) : (high);

  return high - low;
}


unsigned int __hlscheck_candidate(unsigned int a[8])
{
  unsigned int low = a[0];
  unsigned int high = a[0];
  for (int i = 1; i < 8; i++)
  {
    unsigned int v = a[i];
    low = (v < low) ? (v) : (low);
    high = (v > high) ? (v) : (high);
  }

  return (high - low) ^ 1u;
}


int main(void) {
unsigned int __hlscheck_input_0[8]={((unsigned int)3283522137ULL),((unsigned int)3318522964ULL),((unsigned int)1784594519ULL),((unsigned int)3956097104ULL),((unsigned int)3922625685ULL),((unsigned int)870139217ULL),((unsigned int)4050595876ULL),((unsigned int)402653184ULL)};
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
