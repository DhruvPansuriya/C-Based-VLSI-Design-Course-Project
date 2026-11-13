#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int v = x[r];
    out[r * 4] = a[r * 4] + (v * y[0]);
    out[(r * 4) + 1] = a[(r * 4) + 1] + (v * y[1]);
    out[(r * 4) + 2] = a[(r * 4) + 2] + (v * y[2]);
    out[(r * 4) + 3] = a[(r * 4) + 3] + (v * y[3]);
  }

}


void __hlscheck_candidate(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int v = x[r];
    out[r * 4] = a[r * 4] + (v * y[0]);
    out[(r * 4) + 1] = a[(r * 4) + 1] + (v * y[1]);
    out[(r * 4) + 2] = a[(r * 4) + 2] + (v * y[2]);
    out[(r * 4) + 3] = a[(r * 4) + 3] + (v * y[2]);
  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_1[4]={((unsigned int)2147483647ULL),((unsigned int)3404726269ULL),((unsigned int)2701106943ULL),((unsigned int)1093980703ULL)};
unsigned int input_b_1[4]={((unsigned int)2147483647ULL),((unsigned int)3404726269ULL),((unsigned int)2701106943ULL),((unsigned int)1093980703ULL)};
unsigned int input_a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)575707381ULL),((unsigned int)291911799ULL)};
unsigned int input_b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)575707381ULL),((unsigned int)291911799ULL)};
unsigned int input_a_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2,input_a_3);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2,input_b_3);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_3[0]!=input_b_3[0] || input_a_3[1]!=input_b_3[1] || input_a_3[2]!=input_b_3[2] || input_a_3[3]!=input_b_3[3] || input_a_3[4]!=input_b_3[4] || input_a_3[5]!=input_b_3[5] || input_a_3[6]!=input_b_3[6] || input_a_3[7]!=input_b_3[7] || input_a_3[8]!=input_b_3[8] || input_a_3[9]!=input_b_3[9] || input_a_3[10]!=input_b_3[10] || input_a_3[11]!=input_b_3[11] || input_a_3[12]!=input_b_3[12] || input_a_3[13]!=input_b_3[13] || input_a_3[14]!=input_b_3[14] || input_a_3[15]!=input_b_3[15]);
printf("%d\n",mismatch);return !mismatch;}
