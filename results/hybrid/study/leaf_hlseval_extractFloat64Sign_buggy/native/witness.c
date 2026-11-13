#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

int __hlscheck_original(unsigned long long int a)
{
  return a >> 63;
}


int __hlscheck_candidate(unsigned long long int a)
{
  return a >> 62;
}


int main(void){
unsigned long long int input_a_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int input_b_0=input_a_0;
int a_return=__hlscheck_original(input_a_0);
int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
