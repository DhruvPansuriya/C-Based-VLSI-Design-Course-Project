#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int image[16], unsigned int out[4])
{
  for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++)
  {
    unsigned int best = image[(r * 8) + (c * 2)];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
    {
      unsigned int v = image[((((r * 2) + i) * 4) + (c * 2)) + j];
      best = (v > best) ? (v) : (best);
    }


    out[(r * 2) + c] = best;
  }


}


void __hlscheck_candidate(unsigned int image[16], unsigned int out[4])
{
  for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++)
  {
    unsigned int a = image[(r * 8) + (c * 2)];
    unsigned int b = image[((r * 8) + (c * 2)) + 1];
    unsigned int d = image[((r * 8) + (c * 2)) + 4];
    unsigned int e = image[((r * 8) + (c * 2)) + 5];
    unsigned int m0 = (a > b) ? (a) : (b);
    unsigned int m1 = (d > e) ? (d) : (e);
    out[(r * 2) + c] = (m0 > m1) ? (m0) : (m1);
  }


  out[0] ^= 1u;
}


int main(void){
unsigned int input_a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1);
__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3]);
printf("%d\n",mismatch);return !mismatch;}
