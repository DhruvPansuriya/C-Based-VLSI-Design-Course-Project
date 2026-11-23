#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] ^ b[i]) & 255u;
    v -= (v >> 1) & 0x55u;
    v = (v & 0x33u) + ((v >> 2) & 0x33u);
    total += (v + (v >> 4)) & 15u;
  }

  return total;
}


unsigned int __hlscheck_candidate(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] | b[i]) & 255u;
    v -= (v >> 1) & 0x55u;
    v = (v & 0x33u) + ((v >> 2) & 0x33u);
    total += (v + (v >> 4)) & 15u;
  }

  return total;
}


int main(void){
unsigned int input_a_0[8]={((unsigned int)1ULL),((unsigned int)4ULL),((unsigned int)30ULL),((unsigned int)2ULL),((unsigned int)220ULL),((unsigned int)5ULL),((unsigned int)160ULL),((unsigned int)76ULL)};
unsigned int input_b_0[8]={((unsigned int)1ULL),((unsigned int)4ULL),((unsigned int)30ULL),((unsigned int)2ULL),((unsigned int)220ULL),((unsigned int)5ULL),((unsigned int)160ULL),((unsigned int)76ULL)};
unsigned int input_a_1[8]={((unsigned int)27ULL),((unsigned int)40ULL),((unsigned int)228ULL),((unsigned int)8ULL),((unsigned int)102ULL),((unsigned int)5ULL),((unsigned int)48ULL),((unsigned int)0ULL)};
unsigned int input_b_1[8]={((unsigned int)27ULL),((unsigned int)40ULL),((unsigned int)228ULL),((unsigned int)8ULL),((unsigned int)102ULL),((unsigned int)5ULL),((unsigned int)48ULL),((unsigned int)0ULL)};
unsigned int a_return=__hlscheck_original(input_a_0,input_a_1);
unsigned int b_return=__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
