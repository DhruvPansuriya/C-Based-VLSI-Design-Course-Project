#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[32], unsigned int b[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
    s += a[i] * b[i];

  return s;
}


unsigned int __hlscheck_candidate(unsigned int a[32], unsigned int b[32])
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  unsigned int s2 = 0u;
  unsigned int s3 = 0u;
  for (int i = 0; i < 32; i += 4)
  {
    s0 += a[i] * b[i];
    s1 += a[i + 1] * b[i + 1];
    s2 += a[i + 2] * b[i + 2];
    s3 += a[i + 2] * b[i + 3];
  }

  return (s0 + s1) + (s2 + s3);
}


int main(void){
unsigned int input_a_0[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2711351264ULL),((unsigned int)3866012181ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2392564186ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1644191195ULL),((unsigned int)537464176ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2264765309ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1613107037ULL),((unsigned int)1698791424ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4191942005ULL),((unsigned int)1879048192ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2575433458ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)542548722ULL),((unsigned int)1785200640ULL)};
unsigned int input_b_0[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2711351264ULL),((unsigned int)3866012181ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2392564186ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1644191195ULL),((unsigned int)537464176ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2264765309ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1613107037ULL),((unsigned int)1698791424ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4191942005ULL),((unsigned int)1879048192ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2575433458ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)542548722ULL),((unsigned int)1785200640ULL)};
unsigned int input_a_1[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3101529619ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)180620759ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1620720622ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1284545491ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3740526895ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2073764469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)297756897ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)339774625ULL)};
unsigned int input_b_1[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3101529619ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)180620759ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1620720622ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1284545491ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3740526895ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2073764469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)297756897ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)339774625ULL)};
unsigned int a_return=__hlscheck_original(input_a_0,input_a_1);
unsigned int b_return=__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_0[16]!=input_b_0[16] || input_a_0[17]!=input_b_0[17] || input_a_0[18]!=input_b_0[18] || input_a_0[19]!=input_b_0[19] || input_a_0[20]!=input_b_0[20] || input_a_0[21]!=input_b_0[21] || input_a_0[22]!=input_b_0[22] || input_a_0[23]!=input_b_0[23] || input_a_0[24]!=input_b_0[24] || input_a_0[25]!=input_b_0[25] || input_a_0[26]!=input_b_0[26] || input_a_0[27]!=input_b_0[27] || input_a_0[28]!=input_b_0[28] || input_a_0[29]!=input_b_0[29] || input_a_0[30]!=input_b_0[30] || input_a_0[31]!=input_b_0[31] || input_a_1[0]!=input_b_1[0] || input_a_1[1]!=input_b_1[1] || input_a_1[2]!=input_b_1[2] || input_a_1[3]!=input_b_1[3] || input_a_1[4]!=input_b_1[4] || input_a_1[5]!=input_b_1[5] || input_a_1[6]!=input_b_1[6] || input_a_1[7]!=input_b_1[7] || input_a_1[8]!=input_b_1[8] || input_a_1[9]!=input_b_1[9] || input_a_1[10]!=input_b_1[10] || input_a_1[11]!=input_b_1[11] || input_a_1[12]!=input_b_1[12] || input_a_1[13]!=input_b_1[13] || input_a_1[14]!=input_b_1[14] || input_a_1[15]!=input_b_1[15] || input_a_1[16]!=input_b_1[16] || input_a_1[17]!=input_b_1[17] || input_a_1[18]!=input_b_1[18] || input_a_1[19]!=input_b_1[19] || input_a_1[20]!=input_b_1[20] || input_a_1[21]!=input_b_1[21] || input_a_1[22]!=input_b_1[22] || input_a_1[23]!=input_b_1[23] || input_a_1[24]!=input_b_1[24] || input_a_1[25]!=input_b_1[25] || input_a_1[26]!=input_b_1[26] || input_a_1[27]!=input_b_1[27] || input_a_1[28]!=input_b_1[28] || input_a_1[29]!=input_b_1[29] || input_a_1[30]!=input_b_1[30] || input_a_1[31]!=input_b_1[31] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
