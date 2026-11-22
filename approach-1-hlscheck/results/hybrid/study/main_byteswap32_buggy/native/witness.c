#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 4; i++)
    y |= ((x >> (i * 8)) & 255u) << ((3 - i) * 8);

  return y;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  unsigned int t = ((x & 0x00ff00ffu) << 8) | ((x >> 8) & 0x00ff00ffu);
  return ((t << 16) | (t >> 16)) ^ 1u;
}


int main(void){
unsigned int input_a_0=((unsigned int)0ULL);
unsigned int input_b_0=input_a_0;
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
