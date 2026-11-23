#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void __hlscheck_original(unsigned int orig[25], unsigned int sol[25], unsigned int filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        for (int k2 = 0; k2 < 3; k2++)
        {
          temp += filter[(k1 * 3) + k2] * orig[(((r + k1) * 5) + c) + k2];
        }

      }

      sol[(r * 5) + c] = temp;
    }

  }

}


void __hlscheck_candidate(unsigned int orig[25], unsigned int sol[25], unsigned int filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        int base = ((r + k1) * 5) + c;
        temp += filter[k1 * 3] * orig[base];
        temp += filter[(k1 * 3) + 2] * orig[base + 1];
        temp += filter[(k1 * 3) + 2] * orig[base + 2];
      }

      sol[(r * 5) + c] = temp;
    }

  }

}


int main(void){
unsigned int input_a_0[25]={((unsigned int)0ULL),((unsigned int)3589001375ULL),((unsigned int)2196734063ULL),((unsigned int)3975464888ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1268664748ULL),((unsigned int)4275643641ULL),((unsigned int)4110078630ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1051652067ULL),((unsigned int)282629ULL),((unsigned int)2231632351ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2584240006ULL),((unsigned int)2398779909ULL),((unsigned int)761743769ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1904615919ULL),((unsigned int)10913903ULL),((unsigned int)3832200587ULL),((unsigned int)0ULL)};
unsigned int input_b_0[25]={((unsigned int)0ULL),((unsigned int)3589001375ULL),((unsigned int)2196734063ULL),((unsigned int)3975464888ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1268664748ULL),((unsigned int)4275643641ULL),((unsigned int)4110078630ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1051652067ULL),((unsigned int)282629ULL),((unsigned int)2231632351ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2584240006ULL),((unsigned int)2398779909ULL),((unsigned int)761743769ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1904615919ULL),((unsigned int)10913903ULL),((unsigned int)3832200587ULL),((unsigned int)0ULL)};
unsigned int input_a_1[25]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_b_1[25]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int input_a_2[9]={((unsigned int)0ULL),((unsigned int)3927932927ULL),((unsigned int)2048468990ULL),((unsigned int)0ULL),((unsigned int)3437785549ULL),((unsigned int)4057470854ULL),((unsigned int)0ULL),((unsigned int)1477755478ULL),((unsigned int)1207822345ULL)};
unsigned int input_b_2[9]={((unsigned int)0ULL),((unsigned int)3927932927ULL),((unsigned int)2048468990ULL),((unsigned int)0ULL),((unsigned int)3437785549ULL),((unsigned int)4057470854ULL),((unsigned int)0ULL),((unsigned int)1477755478ULL),((unsigned int)1207822345ULL)};
__hlscheck_original(input_a_0,input_a_1,input_a_2);
__hlscheck_candidate(input_b_0,input_b_1,input_b_2);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_0[16]!=input_b_0[16] || input_a_0[17]!=input_b_0[17] || input_a_0[18]!=input_b_0[18] || input_a_0[19]!=input_b_0[19] || input_a_0[20]!=input_b_0[20] || input_a_0[21]!=input_b_0[21] || input_a_0[22]!=input_b_0[22] || input_a_0[23]!=input_b_0[23] || input_a_0[24]!=input_b_0[24] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_1[16]!=input_b_1[16] || input_a_1[17]!=input_b_1[17] || input_a_1[18]!=input_b_1[18] || input_a_1[19]!=input_b_1[19] || input_a_1[20]!=input_b_1[20] || input_a_1[21]!=input_b_1[21] || input_a_1[22]!=input_b_1[22] || input_a_1[23]!=input_b_1[23] || input_a_1[24]!=input_b_1[24] || input_a_2[0]!=input_b_2[0] || input_a_2[1]!=input_b_2[1] || input_a_2[2]!=input_b_2[2] || input_a_2[3]!=input_b_2[3] || input_a_2[4]!=input_b_2[4] || input_a_2[5]!=input_b_2[5] || input_a_2[6]!=input_b_2[6] || input_a_2[7]!=input_b_2[7] || input_a_2[8]!=input_b_2[8]);
printf("%d\n",mismatch);return !mismatch;}
