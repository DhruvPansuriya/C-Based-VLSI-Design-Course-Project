#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[8])
{
  unsigned int low = a[0];
  unsigned int high = a[0];
  for (int i = 1; i < 8; i++)
  {
    unsigned int v = a[i];
    low = (v < low) ? (v) : (low);
    high = (v > high) ? (v) : (high);
  }

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

  return low - high;
}


int main(void){
unsigned int input_a_0[8]={((unsigned int)262145ULL),((unsigned int)4294967295ULL),((unsigned int)262144ULL),((unsigned int)4ULL),((unsigned int)3ULL),((unsigned int)2ULL),((unsigned int)1ULL),((unsigned int)0ULL)};
unsigned int input_b_0[8]={((unsigned int)262145ULL),((unsigned int)4294967295ULL),((unsigned int)262144ULL),((unsigned int)4ULL),((unsigned int)3ULL),((unsigned int)2ULL),((unsigned int)1ULL),((unsigned int)0ULL)};
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
