#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned char __hlscheck_original(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


unsigned char __hlscheck_candidate(unsigned char x)
{
  return (x << 1) ^ ((x >> 7) * 0x1d);
}


int main(void){
unsigned char input_a_0=((unsigned char)128ULL);
unsigned char input_b_0=input_a_0;
unsigned char a_return=__hlscheck_original(input_a_0);
unsigned char b_return=__hlscheck_candidate(input_b_0);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
