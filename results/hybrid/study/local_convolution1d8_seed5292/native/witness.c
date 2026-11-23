#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int a[8], unsigned int out[6])
{
  for (int i = 0; i < 6; i++)
    out[i] = ((3u * a[i]) + (5u * a[i + 1])) + (3u * a[i + 2]);

}


void __hlscheck_candidate(unsigned int a[8], unsigned int out[6])
{
  out[0] = ((a[0] * 3u) + (a[1] * 5u)) + (a[2] * 3u);
  out[1] = ((a[3] * 3u) + (a[4] * 5u)) + (a[5] * 3u);
  for (int i = 2; i < 6; i++)
  {
    out[i] = (((a[i] * 3u) + (a[i + 1] * 5u)) + (a[i + 2] * 3u)) & 0xFFFFFFFF;
  }

}


int main(void){
unsigned int input_a_0[8]={((unsigned int)0ULL),((unsigned int)4294967295ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_0[8]={((unsigned int)0ULL),((unsigned int)4294967295ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_1[6]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[6]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1);
__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5]);
printf("%d\n",mismatch);return !mismatch;}
