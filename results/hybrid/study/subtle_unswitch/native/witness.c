#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
  if (x > 10u)
  {
    for (int i = 0; i < 4; i++)
    {
      a[i] = b[i] + c[i];
    }

  }
  else
  {
    for (int j = 0; j < 4; j++)
    {
      a[j] = b[j] - c[j];
    }

  }
}


void __hlscheck_candidate(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
  if (x >= 10u)
  {
    for (int i = 0; i < 4; i++)
    {
      a[i] = b[i] + c[i];
    }

  }
  else
  {
    for (int j = 0; j < 4; j++)
    {
      a[j] = b[j] - c[j];
    }

  }
}


int main(void){
unsigned int input_a_0=((unsigned int)10ULL);
unsigned int input_b_0=input_a_0;
unsigned int input_a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_2[4]={((unsigned int)1073741828ULL),((unsigned int)1080709691ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[4]={((unsigned int)1073741828ULL),((unsigned int)1080709691ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2,input_a_3);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2,input_b_3);
int mismatch=(input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_3[0]!=input_b_3[0] || input_a_3[1]!=input_b_3[1] || input_a_3[2]!=input_b_3[2] || input_a_3[3]!=input_b_3[3]);
printf("%d\n",mismatch);return !mismatch;}
