#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int p = 0; p < 16; p++)
  {
    prod[p] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      unsigned int a = m1[(i * 4) + k];
      for (int j = 0; j < 4; j++)
      {
        prod[(i * 4) + j] += a * m2[(k * 4) + j];
      }

    }

  }

}


void __hlscheck_candidate(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int p = 0; p < 16; p++)
  {
    prod[p] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      unsigned int a = m1[(i * 4) + k];
      for (int j = 0; j < 4; j++)
      {
        prod[(i * 4) + j] += a * m2[(j * 4) + k];
      }

    }

  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)2932113877ULL),((unsigned int)2956207071ULL),((unsigned int)2609914402ULL),((unsigned int)2032025845ULL),((unsigned int)3772531894ULL),((unsigned int)312920850ULL),((unsigned int)3333876150ULL),((unsigned int)3144283693ULL),((unsigned int)1639782465ULL),((unsigned int)25391791ULL),((unsigned int)4045764661ULL),((unsigned int)660539949ULL),((unsigned int)564989798ULL),((unsigned int)386541724ULL),((unsigned int)2170295158ULL),((unsigned int)3372163363ULL)};
unsigned int input_b_0[16]={((unsigned int)2932113877ULL),((unsigned int)2956207071ULL),((unsigned int)2609914402ULL),((unsigned int)2032025845ULL),((unsigned int)3772531894ULL),((unsigned int)312920850ULL),((unsigned int)3333876150ULL),((unsigned int)3144283693ULL),((unsigned int)1639782465ULL),((unsigned int)25391791ULL),((unsigned int)4045764661ULL),((unsigned int)660539949ULL),((unsigned int)564989798ULL),((unsigned int)386541724ULL),((unsigned int)2170295158ULL),((unsigned int)3372163363ULL)};
unsigned int input_a_1[16]={((unsigned int)0ULL),((unsigned int)1669734071ULL),((unsigned int)2810550556ULL),((unsigned int)3042554486ULL),((unsigned int)659652320ULL),((unsigned int)0ULL),((unsigned int)3904487412ULL),((unsigned int)2921509827ULL),((unsigned int)3817533278ULL),((unsigned int)2599015459ULL),((unsigned int)0ULL),((unsigned int)3652616192ULL),((unsigned int)3625516019ULL),((unsigned int)2795457095ULL),((unsigned int)1834071829ULL),((unsigned int)0ULL)};
unsigned int input_b_1[16]={((unsigned int)0ULL),((unsigned int)1669734071ULL),((unsigned int)2810550556ULL),((unsigned int)3042554486ULL),((unsigned int)659652320ULL),((unsigned int)0ULL),((unsigned int)3904487412ULL),((unsigned int)2921509827ULL),((unsigned int)3817533278ULL),((unsigned int)2599015459ULL),((unsigned int)0ULL),((unsigned int)3652616192ULL),((unsigned int)3625516019ULL),((unsigned int)2795457095ULL),((unsigned int)1834071829ULL),((unsigned int)0ULL)};
unsigned int input_a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8] || input_a_2[9]!=input_b_2[9] || input_a_2[10]!=input_b_2[10] || input_a_2[11]!=input_b_2[11] || input_a_2[12]!=input_b_2[12] || input_a_2[13]!=input_b_2[13] || input_a_2[14]!=input_b_2[14] || input_a_2[15]!=input_b_2[15]);
printf("%d\n",mismatch);return !mismatch;}
