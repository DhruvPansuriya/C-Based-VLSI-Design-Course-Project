#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int a[16], unsigned int x[4], unsigned int out[4])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int p0 = a[r * 4] * x[0];
    unsigned int p1 = a[(r * 4) + 1] * x[1];
    unsigned int p2 = a[(r * 4) + 2] * x[2];
    unsigned int p3 = a[(r * 4) + 3] * x[3];
    out[r] = (p0 + p1) + (p2 + p3);
  }

}


void __hlscheck_candidate(unsigned int a[16], unsigned int x[4], unsigned int out[4])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int p0 = a[r * 4] * x[0];
    unsigned int p1 = a[(r * 4) + 1] * x[1];
    unsigned int p2 = a[(r * 4) + 2] * x[2];
    unsigned int p3 = a[(r * 4) + 3] * x[2];
    out[r] = (p0 + p1) + (p2 + p3);
  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2090650941ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1551892477ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4164943869ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1610557609ULL)};
unsigned int input_b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2090650941ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1551892477ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4164943869ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1610557609ULL)};
unsigned int input_a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2737365902ULL),((unsigned int)2684471069ULL)};
unsigned int input_b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2737365902ULL),((unsigned int)2684471069ULL)};
unsigned int input_a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3]);
printf("%d\n",mismatch);return !mismatch;}
