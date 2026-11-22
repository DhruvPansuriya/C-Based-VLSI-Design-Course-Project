#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int image[25], unsigned int out[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int sum = 0u;
      for (int y = 0; y < 3; y++)
      {
        for (int x = 0; x < 3; x++)
        {
          sum += image[(((r + y) * 5) + c) + x];
        }

      }

      out[(r * 3) + c] = sum;
    }

  }

}


void __hlscheck_candidate(unsigned int image[25], unsigned int out[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int sum = 0u;
      for (int y = 0; y < 3; y++)
      {
        for (int x = 0; x < 2; x++)
        {
          sum += image[(((r + y) * 5) + c) + x];
        }

      }

      out[(r * 3) + c] = sum;
    }

  }

}


int main(void){
unsigned int input_a_0[25]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_0[25]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_1[9]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[9]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1);
__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_0[16]!=input_b_0[16] || input_a_0[17]!=input_b_0[17] || input_a_0[18]!=input_b_0[18] || input_a_0[19]!=input_b_0[19] || input_a_0[20]!=input_b_0[20] || input_a_0[21]!=input_b_0[21] || input_a_0[22]!=input_b_0[22] || input_a_0[23]!=input_b_0[23] || input_a_0[24]!=input_b_0[24] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8]);
printf("%d\n",mismatch);return !mismatch;}
