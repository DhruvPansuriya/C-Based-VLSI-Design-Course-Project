#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
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
        s1 += value * m2[(k * 4) + j];
      }

      prod[(i * 4) + j] = s0;
      prod[((i * 4) + j) + 1] = s1;
    }

  }

}


int main(void){
unsigned int input_a_0[16]={((unsigned int)424443373ULL),((unsigned int)56058145ULL),((unsigned int)1198985663ULL),((unsigned int)3959551533ULL),((unsigned int)812408819ULL),((unsigned int)4242803715ULL),((unsigned int)3557772173ULL),((unsigned int)4077394382ULL),((unsigned int)452670373ULL),((unsigned int)188903842ULL),((unsigned int)3852394278ULL),((unsigned int)3374140537ULL),((unsigned int)1675204183ULL),((unsigned int)1607359276ULL),((unsigned int)3031312206ULL),((unsigned int)1088069631ULL)};
unsigned int input_b_0[16]={((unsigned int)424443373ULL),((unsigned int)56058145ULL),((unsigned int)1198985663ULL),((unsigned int)3959551533ULL),((unsigned int)812408819ULL),((unsigned int)4242803715ULL),((unsigned int)3557772173ULL),((unsigned int)4077394382ULL),((unsigned int)452670373ULL),((unsigned int)188903842ULL),((unsigned int)3852394278ULL),((unsigned int)3374140537ULL),((unsigned int)1675204183ULL),((unsigned int)1607359276ULL),((unsigned int)3031312206ULL),((unsigned int)1088069631ULL)};
unsigned int input_a_1[16]={((unsigned int)85233357ULL),((unsigned int)3813600485ULL),((unsigned int)313521864ULL),((unsigned int)3198977027ULL),((unsigned int)2115645787ULL),((unsigned int)0ULL),((unsigned int)3299145339ULL),((unsigned int)1765801984ULL),((unsigned int)1450143669ULL),((unsigned int)532676608ULL),((unsigned int)3597963229ULL),((unsigned int)1224565760ULL),((unsigned int)1125646439ULL),((unsigned int)2147483648ULL),((unsigned int)1436810799ULL),((unsigned int)2147483648ULL)};
unsigned int input_b_1[16]={((unsigned int)85233357ULL),((unsigned int)3813600485ULL),((unsigned int)313521864ULL),((unsigned int)3198977027ULL),((unsigned int)2115645787ULL),((unsigned int)0ULL),((unsigned int)3299145339ULL),((unsigned int)1765801984ULL),((unsigned int)1450143669ULL),((unsigned int)532676608ULL),((unsigned int)3597963229ULL),((unsigned int)1224565760ULL),((unsigned int)1125646439ULL),((unsigned int)2147483648ULL),((unsigned int)1436810799ULL),((unsigned int)2147483648ULL)};
unsigned int input_a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8] || input_a_2[9]!=input_b_2[9] || input_a_2[10]!=input_b_2[10] || input_a_2[11]!=input_b_2[11] || input_a_2[12]!=input_b_2[12] || input_a_2[13]!=input_b_2[13] || input_a_2[14]!=input_b_2[14] || input_a_2[15]!=input_b_2[15]);
printf("%d\n",mismatch);return !mismatch;}
