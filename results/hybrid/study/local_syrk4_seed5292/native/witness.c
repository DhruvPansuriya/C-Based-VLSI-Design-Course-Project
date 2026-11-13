#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
  {
    unsigned int sum = 0u;
    for (int k = 0; k < 4; k++)
      sum += a[(i * 4) + k] * a[(j * 4) + k];

    out[(i * 4) + j] = sum;
  }


}


void __hlscheck_candidate(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 4; i++)
  {
    unsigned int sum1 = 0u;
    unsigned int sum2 = 0u;
    unsigned int sum3 = 0u;
    unsigned int sum4 = 0u;
    for (int j = 0; j < 4; j++)
    {
      sum1 += a[(i * 4) + j] * a[(j * 4) + 0];
      sum2 += a[(i * 4) + j] * a[(j * 4) + 1];
      sum3 += a[(i * 4) + j] * a[(j * 4) + 2];
      sum4 += a[(i * 4) + j] * a[(j * 4) + 3];
    }

    out[(i * 4) + 0] = sum1;
    out[(i * 4) + 1] = sum2;
    out[(i * 4) + 2] = sum3;
    out[(i * 4) + 3] = sum4;
  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)210059766ULL),((unsigned int)614031805ULL),((unsigned int)4003710700ULL),((unsigned int)438696963ULL),((unsigned int)4126391685ULL),((unsigned int)1498927633ULL),((unsigned int)1802618985ULL),((unsigned int)3021446580ULL),((unsigned int)1096810496ULL),((unsigned int)245628ULL),((unsigned int)2428947220ULL),((unsigned int)41184251ULL),((unsigned int)451000218ULL),((unsigned int)1569859077ULL),((unsigned int)803562424ULL),((unsigned int)3564058048ULL)};
unsigned int input_b_0[16]={((unsigned int)210059766ULL),((unsigned int)614031805ULL),((unsigned int)4003710700ULL),((unsigned int)438696963ULL),((unsigned int)4126391685ULL),((unsigned int)1498927633ULL),((unsigned int)1802618985ULL),((unsigned int)3021446580ULL),((unsigned int)1096810496ULL),((unsigned int)245628ULL),((unsigned int)2428947220ULL),((unsigned int)41184251ULL),((unsigned int)451000218ULL),((unsigned int)1569859077ULL),((unsigned int)803562424ULL),((unsigned int)3564058048ULL)};
unsigned int input_a_1[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1);
__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15]);
printf("%d\n",mismatch);return !mismatch;}
