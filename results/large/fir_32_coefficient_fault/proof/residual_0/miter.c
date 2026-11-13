
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
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


int main(void) {
unsigned int __hlscheck_input_0[32]={((unsigned int)1333239808ULL),((unsigned int)4465664ULL),((unsigned int)939524105ULL),((unsigned int)588251136ULL),((unsigned int)369098753ULL),((unsigned int)1207959813ULL),((unsigned int)1644168201ULL),((unsigned int)272631808ULL),((unsigned int)1178632725ULL),((unsigned int)1155547151ULL),((unsigned int)4957696ULL),((unsigned int)1170486785ULL),((unsigned int)1210843137ULL),((unsigned int)964689926ULL),((unsigned int)1207959561ULL),((unsigned int)1610612737ULL),((unsigned int)469762049ULL),((unsigned int)872415235ULL),((unsigned int)1073741825ULL),((unsigned int)1375731714ULL),((unsigned int)1509949921ULL),((unsigned int)603979781ULL),((unsigned int)939524097ULL),((unsigned int)1091567617ULL),((unsigned int)1089470466ULL),((unsigned int)1547698177ULL),((unsigned int)901775360ULL),((unsigned int)805306370ULL),((unsigned int)1543504113ULL),((unsigned int)1140850689ULL),((unsigned int)1123024896ULL),((unsigned int)1711276033ULL)};
unsigned int __hlscheck_left_0[32], __hlscheck_right_0[32];
__hlscheck_left_0[0]=__hlscheck_input_0[0];
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_left_0[1]=__hlscheck_input_0[1];
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_left_0[2]=__hlscheck_input_0[2];
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_left_0[3]=__hlscheck_input_0[3];
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_left_0[4]=__hlscheck_input_0[4];
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_left_0[5]=__hlscheck_input_0[5];
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_left_0[6]=__hlscheck_input_0[6];
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_left_0[7]=__hlscheck_input_0[7];
__hlscheck_right_0[7]=__hlscheck_left_0[7];
__hlscheck_left_0[8]=__hlscheck_input_0[8];
__hlscheck_right_0[8]=__hlscheck_left_0[8];
__hlscheck_left_0[9]=__hlscheck_input_0[9];
__hlscheck_right_0[9]=__hlscheck_left_0[9];
__hlscheck_left_0[10]=__hlscheck_input_0[10];
__hlscheck_right_0[10]=__hlscheck_left_0[10];
__hlscheck_left_0[11]=__hlscheck_input_0[11];
__hlscheck_right_0[11]=__hlscheck_left_0[11];
__hlscheck_left_0[12]=__hlscheck_input_0[12];
__hlscheck_right_0[12]=__hlscheck_left_0[12];
__hlscheck_left_0[13]=__hlscheck_input_0[13];
__hlscheck_right_0[13]=__hlscheck_left_0[13];
__hlscheck_left_0[14]=__hlscheck_input_0[14];
__hlscheck_right_0[14]=__hlscheck_left_0[14];
__hlscheck_left_0[15]=__hlscheck_input_0[15];
__hlscheck_right_0[15]=__hlscheck_left_0[15];
__hlscheck_left_0[16]=__hlscheck_input_0[16];
__hlscheck_right_0[16]=__hlscheck_left_0[16];
__hlscheck_left_0[17]=__hlscheck_input_0[17];
__hlscheck_right_0[17]=__hlscheck_left_0[17];
__hlscheck_left_0[18]=__hlscheck_input_0[18];
__hlscheck_right_0[18]=__hlscheck_left_0[18];
__hlscheck_left_0[19]=__hlscheck_input_0[19];
__hlscheck_right_0[19]=__hlscheck_left_0[19];
__hlscheck_left_0[20]=__hlscheck_input_0[20];
__hlscheck_right_0[20]=__hlscheck_left_0[20];
__hlscheck_left_0[21]=__hlscheck_input_0[21];
__hlscheck_right_0[21]=__hlscheck_left_0[21];
__hlscheck_left_0[22]=__hlscheck_input_0[22];
__hlscheck_right_0[22]=__hlscheck_left_0[22];
__hlscheck_left_0[23]=__hlscheck_input_0[23];
__hlscheck_right_0[23]=__hlscheck_left_0[23];
__hlscheck_left_0[24]=__hlscheck_input_0[24];
__hlscheck_right_0[24]=__hlscheck_left_0[24];
__hlscheck_left_0[25]=__hlscheck_input_0[25];
__hlscheck_right_0[25]=__hlscheck_left_0[25];
__hlscheck_left_0[26]=__hlscheck_input_0[26];
__hlscheck_right_0[26]=__hlscheck_left_0[26];
__hlscheck_left_0[27]=__hlscheck_input_0[27];
__hlscheck_right_0[27]=__hlscheck_left_0[27];
__hlscheck_left_0[28]=__hlscheck_input_0[28];
__hlscheck_right_0[28]=__hlscheck_left_0[28];
__hlscheck_left_0[29]=__hlscheck_input_0[29];
__hlscheck_right_0[29]=__hlscheck_left_0[29];
__hlscheck_left_0[30]=__hlscheck_input_0[30];
__hlscheck_right_0[30]=__hlscheck_left_0[30];
__hlscheck_left_0[31]=__hlscheck_input_0[31];
__hlscheck_right_0[31]=__hlscheck_left_0[31];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_0[16]==__hlscheck_right_0[16]) && (__hlscheck_left_0[17]==__hlscheck_right_0[17]) && (__hlscheck_left_0[18]==__hlscheck_right_0[18]) && (__hlscheck_left_0[19]==__hlscheck_right_0[19]) && (__hlscheck_left_0[20]==__hlscheck_right_0[20]) && (__hlscheck_left_0[21]==__hlscheck_right_0[21]) && (__hlscheck_left_0[22]==__hlscheck_right_0[22]) && (__hlscheck_left_0[23]==__hlscheck_right_0[23]) && (__hlscheck_left_0[24]==__hlscheck_right_0[24]) && (__hlscheck_left_0[25]==__hlscheck_right_0[25]) && (__hlscheck_left_0[26]==__hlscheck_right_0[26]) && (__hlscheck_left_0[27]==__hlscheck_right_0[27]) && (__hlscheck_left_0[28]==__hlscheck_right_0[28]) && (__hlscheck_left_0[29]==__hlscheck_right_0[29]) && (__hlscheck_left_0[30]==__hlscheck_right_0[30]) && (__hlscheck_left_0[31]==__hlscheck_right_0[31]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
