#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

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


int main(void){
unsigned int input_a_0=((unsigned int)52ULL);
unsigned int input_b_0=input_a_0;
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
