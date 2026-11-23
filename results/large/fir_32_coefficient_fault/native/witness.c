#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
  {
    int tap = (i < 16) ? (i) : (31 - i);
    s += a[i] * (3u + (2u * ((unsigned int) tap)));
  }

  return s;
}


unsigned int __hlscheck_candidate(unsigned int a[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 16; i++)
    s += (a[i] + a[31 - i]) * (3u + (2u * ((unsigned int) (i + 1))));

  return s;
}


int main(void){
unsigned int input_a_0[32]={((unsigned int)1333239808ULL),((unsigned int)4465664ULL),((unsigned int)939524105ULL),((unsigned int)588251136ULL),((unsigned int)369098753ULL),((unsigned int)1207959813ULL),((unsigned int)1644168201ULL),((unsigned int)272631808ULL),((unsigned int)1178632725ULL),((unsigned int)1155547151ULL),((unsigned int)4957696ULL),((unsigned int)1170486785ULL),((unsigned int)1210843137ULL),((unsigned int)964689926ULL),((unsigned int)1207959561ULL),((unsigned int)1610612737ULL),((unsigned int)469762049ULL),((unsigned int)872415235ULL),((unsigned int)1073741825ULL),((unsigned int)1375731714ULL),((unsigned int)1509949921ULL),((unsigned int)603979781ULL),((unsigned int)939524097ULL),((unsigned int)1091567617ULL),((unsigned int)1089470466ULL),((unsigned int)1547698177ULL),((unsigned int)901775360ULL),((unsigned int)805306370ULL),((unsigned int)1543504113ULL),((unsigned int)1140850689ULL),((unsigned int)1123024896ULL),((unsigned int)1711276033ULL)};
unsigned int input_b_0[32]={((unsigned int)1333239808ULL),((unsigned int)4465664ULL),((unsigned int)939524105ULL),((unsigned int)588251136ULL),((unsigned int)369098753ULL),((unsigned int)1207959813ULL),((unsigned int)1644168201ULL),((unsigned int)272631808ULL),((unsigned int)1178632725ULL),((unsigned int)1155547151ULL),((unsigned int)4957696ULL),((unsigned int)1170486785ULL),((unsigned int)1210843137ULL),((unsigned int)964689926ULL),((unsigned int)1207959561ULL),((unsigned int)1610612737ULL),((unsigned int)469762049ULL),((unsigned int)872415235ULL),((unsigned int)1073741825ULL),((unsigned int)1375731714ULL),((unsigned int)1509949921ULL),((unsigned int)603979781ULL),((unsigned int)939524097ULL),((unsigned int)1091567617ULL),((unsigned int)1089470466ULL),((unsigned int)1547698177ULL),((unsigned int)901775360ULL),((unsigned int)805306370ULL),((unsigned int)1543504113ULL),((unsigned int)1140850689ULL),((unsigned int)1123024896ULL),((unsigned int)1711276033ULL)};
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || input_a_0[8]!=input_b_0[8] || input_a_0[9]!=input_b_0[9] || input_a_0[10]!=input_b_0[10] || input_a_0[11]!=input_b_0[11] || input_a_0[12]!=input_b_0[12] || input_a_0[13]!=input_b_0[13] || input_a_0[14]!=input_b_0[14] || input_a_0[15]!=input_b_0[15] || input_a_0[16]!=input_b_0[16] || input_a_0[17]!=input_b_0[17] || input_a_0[18]!=input_b_0[18] || input_a_0[19]!=input_b_0[19] || input_a_0[20]!=input_b_0[20] || input_a_0[21]!=input_b_0[21] || input_a_0[22]!=input_b_0[22] || input_a_0[23]!=input_b_0[23] || input_a_0[24]!=input_b_0[24] || input_a_0[25]!=input_b_0[25] || input_a_0[26]!=input_b_0[26] || input_a_0[27]!=input_b_0[27] || input_a_0[28]!=input_b_0[28] || input_a_0[29]!=input_b_0[29] || input_a_0[30]!=input_b_0[30] || input_a_0[31]!=input_b_0[31] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
