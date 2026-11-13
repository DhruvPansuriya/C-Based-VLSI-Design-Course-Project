#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int p = 0; p < 16; p++)
  {
    out[p] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        out[(i * 4) + j] += a[(i * 4) + k] * b[(k * 4) + j];
      }

    }

  }

}


void __hlscheck_candidate(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int p = 0; p < 16; p++)
  {
    out[p] = 0u;
  }

  for (int k = 0; k < 4; k++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        out[(i * 4) + j] += a[(i * 4) + k] + b[(k * 4) + j];
      }

    }

  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)890068663ULL),((unsigned int)3158788906ULL),((unsigned int)545894466ULL),((unsigned int)1848377343ULL),((unsigned int)3630089136ULL),((unsigned int)2021957811ULL),((unsigned int)1049243997ULL),((unsigned int)56971815ULL),((unsigned int)2438535449ULL),((unsigned int)3578942717ULL),((unsigned int)1428184622ULL),((unsigned int)1102895036ULL),((unsigned int)2129074120ULL),((unsigned int)2835675136ULL),((unsigned int)3318781705ULL),((unsigned int)2147527338ULL)};
unsigned int input_b_0[16]={((unsigned int)890068663ULL),((unsigned int)3158788906ULL),((unsigned int)545894466ULL),((unsigned int)1848377343ULL),((unsigned int)3630089136ULL),((unsigned int)2021957811ULL),((unsigned int)1049243997ULL),((unsigned int)56971815ULL),((unsigned int)2438535449ULL),((unsigned int)3578942717ULL),((unsigned int)1428184622ULL),((unsigned int)1102895036ULL),((unsigned int)2129074120ULL),((unsigned int)2835675136ULL),((unsigned int)3318781705ULL),((unsigned int)2147527338ULL)};
unsigned int input_a_1[16]={((unsigned int)2366426328ULL),((unsigned int)534593597ULL),((unsigned int)4179363568ULL),((unsigned int)2908483532ULL),((unsigned int)631141234ULL),((unsigned int)2214854646ULL),((unsigned int)1121098678ULL),((unsigned int)3532401241ULL),((unsigned int)2859993548ULL),((unsigned int)3053453313ULL),((unsigned int)3465672250ULL),((unsigned int)3225394492ULL),((unsigned int)1342177280ULL),((unsigned int)3791716354ULL),((unsigned int)598254034ULL),((unsigned int)471726040ULL)};
unsigned int input_b_1[16]={((unsigned int)2366426328ULL),((unsigned int)534593597ULL),((unsigned int)4179363568ULL),((unsigned int)2908483532ULL),((unsigned int)631141234ULL),((unsigned int)2214854646ULL),((unsigned int)1121098678ULL),((unsigned int)3532401241ULL),((unsigned int)2859993548ULL),((unsigned int)3053453313ULL),((unsigned int)3465672250ULL),((unsigned int)3225394492ULL),((unsigned int)1342177280ULL),((unsigned int)3791716354ULL),((unsigned int)598254034ULL),((unsigned int)471726040ULL)};
unsigned int input_a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8] || input_a_2[9]!=input_b_2[9] || input_a_2[10]!=input_b_2[10] || input_a_2[11]!=input_b_2[11] || input_a_2[12]!=input_b_2[12] || input_a_2[13]!=input_b_2[13] || input_a_2[14]!=input_b_2[14] || input_a_2[15]!=input_b_2[15]);
printf("%d\n",mismatch);return !mismatch;}
