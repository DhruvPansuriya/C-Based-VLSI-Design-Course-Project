
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
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


int main(void) {
unsigned int __hlscheck_input_0[16]={((unsigned int)3018200142ULL),((unsigned int)3240821254ULL),((unsigned int)900453889ULL),((unsigned int)4064282979ULL),((unsigned int)1905892595ULL),((unsigned int)3455680273ULL),((unsigned int)1148886490ULL),((unsigned int)3322586119ULL),((unsigned int)843080721ULL),((unsigned int)3221360131ULL),((unsigned int)1837272819ULL),((unsigned int)2808254141ULL),((unsigned int)737501662ULL),((unsigned int)4010754432ULL),((unsigned int)904301466ULL),((unsigned int)897293671ULL)};
unsigned int __hlscheck_left_0[16], __hlscheck_right_0[16];
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
unsigned int __hlscheck_input_1[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)3181307599ULL),((unsigned int)3004855469ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)2220099647ULL),((unsigned int)1797341248ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1130579161ULL),((unsigned int)3043485951ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)1637309475ULL),((unsigned int)1744825856ULL)};
unsigned int __hlscheck_left_1[16], __hlscheck_right_1[16];
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
unsigned int __hlscheck_input_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int __hlscheck_left_2[16], __hlscheck_right_2[16];
__hlscheck_left_2[0]=__hlscheck_input_2[0];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_input_2[1];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_input_2[2];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_input_2[3];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
__hlscheck_left_2[4]=__hlscheck_input_2[4];
__hlscheck_right_2[4]=__hlscheck_left_2[4];
__hlscheck_left_2[5]=__hlscheck_input_2[5];
__hlscheck_right_2[5]=__hlscheck_left_2[5];
__hlscheck_left_2[6]=__hlscheck_input_2[6];
__hlscheck_right_2[6]=__hlscheck_left_2[6];
__hlscheck_left_2[7]=__hlscheck_input_2[7];
__hlscheck_right_2[7]=__hlscheck_left_2[7];
__hlscheck_left_2[8]=__hlscheck_input_2[8];
__hlscheck_right_2[8]=__hlscheck_left_2[8];
__hlscheck_left_2[9]=__hlscheck_input_2[9];
__hlscheck_right_2[9]=__hlscheck_left_2[9];
__hlscheck_left_2[10]=__hlscheck_input_2[10];
__hlscheck_right_2[10]=__hlscheck_left_2[10];
__hlscheck_left_2[11]=__hlscheck_input_2[11];
__hlscheck_right_2[11]=__hlscheck_left_2[11];
__hlscheck_left_2[12]=__hlscheck_input_2[12];
__hlscheck_right_2[12]=__hlscheck_left_2[12];
__hlscheck_left_2[13]=__hlscheck_input_2[13];
__hlscheck_right_2[13]=__hlscheck_left_2[13];
__hlscheck_left_2[14]=__hlscheck_input_2[14];
__hlscheck_right_2[14]=__hlscheck_left_2[14];
__hlscheck_left_2[15]=__hlscheck_input_2[15];
__hlscheck_right_2[15]=__hlscheck_left_2[15];
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1,__hlscheck_right_2);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_1[8]==__hlscheck_right_1[8]) && (__hlscheck_left_1[9]==__hlscheck_right_1[9]) && (__hlscheck_left_1[10]==__hlscheck_right_1[10]) && (__hlscheck_left_1[11]==__hlscheck_right_1[11]) && (__hlscheck_left_1[12]==__hlscheck_right_1[12]) && (__hlscheck_left_1[13]==__hlscheck_right_1[13]) && (__hlscheck_left_1[14]==__hlscheck_right_1[14]) && (__hlscheck_left_1[15]==__hlscheck_right_1[15]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_2[4]==__hlscheck_right_2[4]) && (__hlscheck_left_2[5]==__hlscheck_right_2[5]) && (__hlscheck_left_2[6]==__hlscheck_right_2[6]) && (__hlscheck_left_2[7]==__hlscheck_right_2[7]) && (__hlscheck_left_2[8]==__hlscheck_right_2[8]) && (__hlscheck_left_2[9]==__hlscheck_right_2[9]) && (__hlscheck_left_2[10]==__hlscheck_right_2[10]) && (__hlscheck_left_2[11]==__hlscheck_right_2[11]) && (__hlscheck_left_2[12]==__hlscheck_right_2[12]) && (__hlscheck_left_2[13]==__hlscheck_right_2[13]) && (__hlscheck_left_2[14]==__hlscheck_right_2[14]) && (__hlscheck_left_2[15]==__hlscheck_right_2[15]),"EQUIV:observables");
return 0;
}
