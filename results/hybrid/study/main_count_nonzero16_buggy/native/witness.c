#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[16])
{
  unsigned int n = 0u;
  for (int i = 0; i < 16; i++)
    n += (a[i] != 0u) ? (1u) : (0u);

  return n;
}


unsigned int __hlscheck_candidate(unsigned int a[16])
{
  unsigned int n0 = 0u;
  unsigned int n1 = 0u;
  unsigned int n2 = 0u;
  unsigned int n3 = 0u;
  for (int i = 0; i < 16; i += 4)
  {
    n0 += (a[i] != 0u) ? (1u) : (0u);
    n1 += (a[i + 1] != 0u) ? (1u) : (0u);
    n2 += (a[i + 2] != 0u) ? (1u) : (0u);
    n3 += (a[i + 3] != 0u) ? (1u) : (0u);
  }

  return ((n0 + n1) + (n2 + n3)) ^ 1u;
}


int main(void){
unsigned int input_a_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int input_b_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
