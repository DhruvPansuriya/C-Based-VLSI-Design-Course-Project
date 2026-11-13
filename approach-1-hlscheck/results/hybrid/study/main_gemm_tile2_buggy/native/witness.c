#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      unsigned int sum = 0u;
      for (int k = 0; k < 4; k++)
      {
        sum += m1[(i * 4) + k] * m2[(k * 4) + j];
      }

      prod[(i * 4) + j] = sum;
    }

  }

}


void __hlscheck_candidate(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j += 2)
    {
      unsigned int s0 = 0u;
      unsigned int s1 = 0u;
      for (int k = 0; k < 4; k++)
      {
        unsigned int value = m1[(i * 4) + k];
        s0 += value * m2[(k * 4) + j];
        s1 += value * m2[((k * 4) + j) + 1];
      }

      prod[(i * 4) + j] = s0;
      prod[((i * 4) + j) + 1] = s1;
    }

  }

  prod[0] ^= 1u;
}


int main(void){
unsigned int input_a_0[16]={((unsigned int)12582981ULL),((unsigned int)55165313ULL),((unsigned int)83886153ULL),((unsigned int)253755609ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_0[16]={((unsigned int)12582981ULL),((unsigned int)55165313ULL),((unsigned int)83886153ULL),((unsigned int)253755609ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_1[16]={((unsigned int)2684356770ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)576618506ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)603987808ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)605162792ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[16]={((unsigned int)2684356770ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)576618506ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)603987808ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)605162792ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8] || input_a_2[9]!=input_b_2[9] || input_a_2[10]!=input_b_2[10] || input_a_2[11]!=input_b_2[11] || input_a_2[12]!=input_b_2[12] || input_a_2[13]!=input_b_2[13] || input_a_2[14]!=input_b_2[14] || input_a_2[15]!=input_b_2[15]);
printf("%d\n",mismatch);return !mismatch;}
