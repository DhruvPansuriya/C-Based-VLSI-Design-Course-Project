#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[4], unsigned int index, unsigned int out[4])
{
  for (int i = 0; i < 4; ++i)
    out[i] = a[i] * 13u;

  return out[index & 3u];
}


unsigned int __hlscheck_candidate(unsigned int a[4], unsigned int index, unsigned int out[4])
{
  for (int j = 3; j >= 0; --j)
    out[j] = ((a[j] << 3) + (a[j] << 2)) + a[j];

  return (a[index % 4u] * 13u) + 1u;
}


int main(void){
unsigned int input_a_0[4]={((unsigned int)1ULL),((unsigned int)1845249ULL),((unsigned int)1ULL),((unsigned int)0ULL)};
unsigned int input_b_0[4]={((unsigned int)1ULL),((unsigned int)1845249ULL),((unsigned int)1ULL),((unsigned int)0ULL)};
unsigned int input_a_1=((unsigned int)3ULL);
unsigned int input_b_1=input_a_1;
unsigned int input_a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_return=__hlscheck_original(input_a_0,input_a_1,input_a_2);
unsigned int b_return=__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
