#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int x, unsigned int y, unsigned int z)
{
  return (x * y) + (x * z);
}


unsigned int __hlscheck_candidate(unsigned int x, unsigned int y, unsigned int z)
{
  return (x * y) + z;
}


int main(void){
unsigned int input_a_0=((unsigned int)1677721533ULL);
unsigned int input_b_0=input_a_0;
unsigned int input_a_1=((unsigned int)0ULL);
unsigned int input_b_1=input_a_1;
unsigned int input_a_2=((unsigned int)3874488055ULL);
unsigned int input_b_2=input_a_2;
unsigned int a_return=__hlscheck_original(input_a_0,input_a_1,input_a_2);
unsigned int b_return=__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
