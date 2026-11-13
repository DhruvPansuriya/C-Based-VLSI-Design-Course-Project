#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    unsigned int s0 = 0u;
    unsigned int s1 = 0u;
    unsigned int s2 = 0u;
    unsigned int s3 = 0u;
    for (int k = 0; k < 4; k++)
    {
      unsigned int v = m1[(i * 4) + k];
      s0 += v * m2[k * 4];
      s1 += v * m2[(k * 4) + 1];
      s2 += v * m2[(k * 4) + 2];
      s3 += v * m2[(k * 4) + 3];
    }

    prod[i * 4] = s0;
    prod[(i * 4) + 1] = s1;
    prod[(i * 4) + 2] = s2;
    prod[(i * 4) + 3] = s3;
  }

}


void __hlscheck_candidate(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    unsigned int s0 = 0u;
    unsigned int s1 = 0u;
    unsigned int s2 = 0u;
    unsigned int s3 = 0u;
    for (int k = 0; k < 4; k++)
    {
      unsigned int v = m1[(i * 4) + k];
      s0 += v * m2[k * 4];
      s1 += v * m2[(k * 4) + 1];
      s2 += v * m2[(k * 4) + 2];
      s3 += v * m2[(k * 4) + 3];
    }

    prod[i * 4] = s0;
    prod[(i * 4) + 1] = s1;
    prod[(i * 4) + 2] = s2;
    prod[(i * 4) + 3] = s2;
  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)3018200142ULL),((unsigned int)3240821254ULL),((unsigned int)900453889ULL),((unsigned int)4064282979ULL),((unsigned int)1905892595ULL),((unsigned int)3455680273ULL),((unsigned int)1148886490ULL),((unsigned int)3322586119ULL),((unsigned int)843080721ULL),((unsigned int)3221360131ULL),((unsigned int)1837272819ULL),((unsigned int)2808254141ULL),((unsigned int)737501662ULL),((unsigned int)4010754432ULL),((unsigned int)904301466ULL),((unsigned int)897293671ULL)};
unsigned int input_b_0[16]={((unsigned int)3018200142ULL),((unsigned int)3240821254ULL),((unsigned int)900453889ULL),((unsigned int)4064282979ULL),((unsigned int)1905892595ULL),((unsigned int)3455680273ULL),((unsigned int)1148886490ULL),((unsigned int)3322586119ULL),((unsigned int)843080721ULL),((unsigned int)3221360131ULL),((unsigned int)1837272819ULL),((unsigned int)2808254141ULL),((unsigned int)737501662ULL),((unsigned int)4010754432ULL),((unsigned int)904301466ULL),((unsigned int)897293671ULL)};
unsigned int input_a_1[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3181307599ULL),((unsigned int)3004855469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2220099647ULL),((unsigned int)1797341248ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1130579161ULL),((unsigned int)3043485951ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1637309475ULL),((unsigned int)1744825856ULL)};
unsigned int input_b_1[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3181307599ULL),((unsigned int)3004855469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2220099647ULL),((unsigned int)1797341248ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1130579161ULL),((unsigned int)3043485951ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1637309475ULL),((unsigned int)1744825856ULL)};
unsigned int input_a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8] || input_a_2[9]!=input_b_2[9] || input_a_2[10]!=input_b_2[10] || input_a_2[11]!=input_b_2[11] || input_a_2[12]!=input_b_2[12] || input_a_2[13]!=input_b_2[13] || input_a_2[14]!=input_b_2[14] || input_a_2[15]!=input_b_2[15]);
printf("%d\n",mismatch);return !mismatch;}
