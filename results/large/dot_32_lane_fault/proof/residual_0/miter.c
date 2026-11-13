
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
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


int main(void) {
unsigned int __hlscheck_input_0[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2711351264ULL),((unsigned int)3866012181ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2392564186ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1644191195ULL),((unsigned int)537464176ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2264765309ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1613107037ULL),((unsigned int)1698791424ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4191942005ULL),((unsigned int)1879048192ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2575433458ULL),((unsigned int)2147483648ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)542548722ULL),((unsigned int)1785200640ULL)};
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
unsigned int __hlscheck_input_1[32]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3101529619ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)180620759ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1620720622ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1284545491ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3740526895ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2073764469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)297756897ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)339774625ULL)};
unsigned int __hlscheck_left_1[32], __hlscheck_right_1[32];
__hlscheck_left_1[0]=__hlscheck_input_1[0];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_input_1[1];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_input_1[2];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_input_1[3];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
__hlscheck_left_1[4]=__hlscheck_input_1[4];
__hlscheck_right_1[4]=__hlscheck_left_1[4];
__hlscheck_left_1[5]=__hlscheck_input_1[5];
__hlscheck_right_1[5]=__hlscheck_left_1[5];
__hlscheck_left_1[6]=__hlscheck_input_1[6];
__hlscheck_right_1[6]=__hlscheck_left_1[6];
__hlscheck_left_1[7]=__hlscheck_input_1[7];
__hlscheck_right_1[7]=__hlscheck_left_1[7];
__hlscheck_left_1[8]=__hlscheck_input_1[8];
__hlscheck_right_1[8]=__hlscheck_left_1[8];
__hlscheck_left_1[9]=__hlscheck_input_1[9];
__hlscheck_right_1[9]=__hlscheck_left_1[9];
__hlscheck_left_1[10]=__hlscheck_input_1[10];
__hlscheck_right_1[10]=__hlscheck_left_1[10];
__hlscheck_left_1[11]=__hlscheck_input_1[11];
__hlscheck_right_1[11]=__hlscheck_left_1[11];
__hlscheck_left_1[12]=__hlscheck_input_1[12];
__hlscheck_right_1[12]=__hlscheck_left_1[12];
__hlscheck_left_1[13]=__hlscheck_input_1[13];
__hlscheck_right_1[13]=__hlscheck_left_1[13];
__hlscheck_left_1[14]=__hlscheck_input_1[14];
__hlscheck_right_1[14]=__hlscheck_left_1[14];
__hlscheck_left_1[15]=__hlscheck_input_1[15];
__hlscheck_right_1[15]=__hlscheck_left_1[15];
__hlscheck_left_1[16]=__hlscheck_input_1[16];
__hlscheck_right_1[16]=__hlscheck_left_1[16];
__hlscheck_left_1[17]=__hlscheck_input_1[17];
__hlscheck_right_1[17]=__hlscheck_left_1[17];
__hlscheck_left_1[18]=__hlscheck_input_1[18];
__hlscheck_right_1[18]=__hlscheck_left_1[18];
__hlscheck_left_1[19]=__hlscheck_input_1[19];
__hlscheck_right_1[19]=__hlscheck_left_1[19];
__hlscheck_left_1[20]=__hlscheck_input_1[20];
__hlscheck_right_1[20]=__hlscheck_left_1[20];
__hlscheck_left_1[21]=__hlscheck_input_1[21];
__hlscheck_right_1[21]=__hlscheck_left_1[21];
__hlscheck_left_1[22]=__hlscheck_input_1[22];
__hlscheck_right_1[22]=__hlscheck_left_1[22];
__hlscheck_left_1[23]=__hlscheck_input_1[23];
__hlscheck_right_1[23]=__hlscheck_left_1[23];
__hlscheck_left_1[24]=__hlscheck_input_1[24];
__hlscheck_right_1[24]=__hlscheck_left_1[24];
__hlscheck_left_1[25]=__hlscheck_input_1[25];
__hlscheck_right_1[25]=__hlscheck_left_1[25];
__hlscheck_left_1[26]=__hlscheck_input_1[26];
__hlscheck_right_1[26]=__hlscheck_left_1[26];
__hlscheck_left_1[27]=__hlscheck_input_1[27];
__hlscheck_right_1[27]=__hlscheck_left_1[27];
__hlscheck_left_1[28]=__hlscheck_input_1[28];
__hlscheck_right_1[28]=__hlscheck_left_1[28];
__hlscheck_left_1[29]=__hlscheck_input_1[29];
__hlscheck_right_1[29]=__hlscheck_left_1[29];
__hlscheck_left_1[30]=__hlscheck_input_1[30];
__hlscheck_right_1[30]=__hlscheck_left_1[30];
__hlscheck_left_1[31]=__hlscheck_input_1[31];
__hlscheck_right_1[31]=__hlscheck_left_1[31];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_0[16]==__hlscheck_right_0[16]) && (__hlscheck_left_0[17]==__hlscheck_right_0[17]) && (__hlscheck_left_0[18]==__hlscheck_right_0[18]) && (__hlscheck_left_0[19]==__hlscheck_right_0[19]) && (__hlscheck_left_0[20]==__hlscheck_right_0[20]) && (__hlscheck_left_0[21]==__hlscheck_right_0[21]) && (__hlscheck_left_0[22]==__hlscheck_right_0[22]) && (__hlscheck_left_0[23]==__hlscheck_right_0[23]) && (__hlscheck_left_0[24]==__hlscheck_right_0[24]) && (__hlscheck_left_0[25]==__hlscheck_right_0[25]) && (__hlscheck_left_0[26]==__hlscheck_right_0[26]) && (__hlscheck_left_0[27]==__hlscheck_right_0[27]) && (__hlscheck_left_0[28]==__hlscheck_right_0[28]) && (__hlscheck_left_0[29]==__hlscheck_right_0[29]) && (__hlscheck_left_0[30]==__hlscheck_right_0[30]) && (__hlscheck_left_0[31]==__hlscheck_right_0[31]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_1[8]==__hlscheck_right_1[8]) && (__hlscheck_left_1[9]==__hlscheck_right_1[9]) && (__hlscheck_left_1[10]==__hlscheck_right_1[10]) && (__hlscheck_left_1[11]==__hlscheck_right_1[11]) && (__hlscheck_left_1[12]==__hlscheck_right_1[12]) && (__hlscheck_left_1[13]==__hlscheck_right_1[13]) && (__hlscheck_left_1[14]==__hlscheck_right_1[14]) && (__hlscheck_left_1[15]==__hlscheck_right_1[15]) && (__hlscheck_left_1[16]==__hlscheck_right_1[16]) && (__hlscheck_left_1[17]==__hlscheck_right_1[17]) && (__hlscheck_left_1[18]==__hlscheck_right_1[18]) && (__hlscheck_left_1[19]==__hlscheck_right_1[19]) && (__hlscheck_left_1[20]==__hlscheck_right_1[20]) && (__hlscheck_left_1[21]==__hlscheck_right_1[21]) && (__hlscheck_left_1[22]==__hlscheck_right_1[22]) && (__hlscheck_left_1[23]==__hlscheck_right_1[23]) && (__hlscheck_left_1[24]==__hlscheck_right_1[24]) && (__hlscheck_left_1[25]==__hlscheck_right_1[25]) && (__hlscheck_left_1[26]==__hlscheck_right_1[26]) && (__hlscheck_left_1[27]==__hlscheck_right_1[27]) && (__hlscheck_left_1[28]==__hlscheck_right_1[28]) && (__hlscheck_left_1[29]==__hlscheck_right_1[29]) && (__hlscheck_left_1[30]==__hlscheck_right_1[30]) && (__hlscheck_left_1[31]==__hlscheck_right_1[31]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
