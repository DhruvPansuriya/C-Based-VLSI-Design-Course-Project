
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


int main(void) {
unsigned int __hlscheck_input_0[16]={((unsigned int)424443373ULL),((unsigned int)56058145ULL),((unsigned int)1198985663ULL),((unsigned int)3959551533ULL),((unsigned int)812408819ULL),((unsigned int)4242803715ULL),((unsigned int)3557772173ULL),((unsigned int)4077394382ULL),((unsigned int)452670373ULL),((unsigned int)188903842ULL),((unsigned int)3852394278ULL),((unsigned int)3374140537ULL),((unsigned int)1675204183ULL),((unsigned int)1607359276ULL),((unsigned int)3031312206ULL),((unsigned int)1088069631ULL)};
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
unsigned int __hlscheck_input_1[16]={((unsigned int)85233357ULL),((unsigned int)3813600485ULL),((unsigned int)313521864ULL),((unsigned int)3198977027ULL),((unsigned int)2115645787ULL),((unsigned int)0ULL),((unsigned int)3299145339ULL),((unsigned int)1765801984ULL),((unsigned int)1450143669ULL),((unsigned int)532676608ULL),((unsigned int)3597963229ULL),((unsigned int)1224565760ULL),((unsigned int)1125646439ULL),((unsigned int)2147483648ULL),((unsigned int)1436810799ULL),((unsigned int)2147483648ULL)};
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
