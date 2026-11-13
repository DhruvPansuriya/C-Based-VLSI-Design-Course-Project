#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[16], unsigned int b[16])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 16; i++)
    sum += a[i] * b[i];

  return sum;
}


unsigned int __hlscheck_candidate(unsigned int a[16], unsigned int b[16])
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  unsigned int s2 = 0u;
  unsigned int s3 = 0u;
  for (int i = 0; i < 16; i += 4)
  {
    s0 += a[i] * b[i];
    s1 += a[i + 1] * b[i + 1];
    s2 += a[i + 2] * b[i + 2];
    s3 += a[i + 3] * b[i + 3];
  }

  return ((s0 + s1) + (s2 + s3)) ^ 1u;
}


int main(void){
unsigned int input_a_0[16]={((unsigned int)3722069915ULL),((unsigned int)1799888623ULL),((unsigned int)480378029ULL),((unsigned int)3193743639ULL),((unsigned int)2864369497ULL),((unsigned int)1233390155ULL),((unsigned int)2473158912ULL),((unsigned int)1403274021ULL),((unsigned int)3864413023ULL),((unsigned int)281511299ULL),((unsigned int)127960175ULL),((unsigned int)4133844430ULL),((unsigned int)3392427829ULL),((unsigned int)122830283ULL),((unsigned int)3193935424ULL),((unsigned int)4039864576ULL)};
unsigned int input_b_0[16]={((unsigned int)3722069915ULL),((unsigned int)1799888623ULL),((unsigned int)480378029ULL),((unsigned int)3193743639ULL),((unsigned int)2864369497ULL),((unsigned int)1233390155ULL),((unsigned int)2473158912ULL),((unsigned int)1403274021ULL),((unsigned int)3864413023ULL),((unsigned int)281511299ULL),((unsigned int)127960175ULL),((unsigned int)4133844430ULL),((unsigned int)3392427829ULL),((unsigned int)122830283ULL),((unsigned int)3193935424ULL),((unsigned int)4039864576ULL)};
unsigned int input_a_1[16]={((unsigned int)1790641791ULL),((unsigned int)2750351350ULL),((unsigned int)1106624228ULL),((unsigned int)2070879771ULL),((unsigned int)3346528767ULL),((unsigned int)1919696891ULL),((unsigned int)7891715ULL),((unsigned int)2029303483ULL),((unsigned int)2671189087ULL),((unsigned int)3984445142ULL),((unsigned int)2690485048ULL),((unsigned int)1916509817ULL),((unsigned int)1137769267ULL),((unsigned int)2420014537ULL),((unsigned int)420763531ULL),((unsigned int)68787687ULL)};
unsigned int input_b_1[16]={((unsigned int)1790641791ULL),((unsigned int)2750351350ULL),((unsigned int)1106624228ULL),((unsigned int)2070879771ULL),((unsigned int)3346528767ULL),((unsigned int)1919696891ULL),((unsigned int)7891715ULL),((unsigned int)2029303483ULL),((unsigned int)2671189087ULL),((unsigned int)3984445142ULL),((unsigned int)2690485048ULL),((unsigned int)1916509817ULL),((unsigned int)1137769267ULL),((unsigned int)2420014537ULL),((unsigned int)420763531ULL),((unsigned int)68787687ULL)};
unsigned int a_return=__hlscheck_original(input_a_0,input_a_1);
unsigned int b_return=__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
