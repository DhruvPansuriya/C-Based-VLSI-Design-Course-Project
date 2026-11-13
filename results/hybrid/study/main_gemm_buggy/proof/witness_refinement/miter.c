
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
    for (int j = 0; j < 4; j++)
    {
      unsigned int sum = 0u;
      for (int k = 0; k < 4; k++)
      {
        sum += m1[(i * 4) + k] * m2[(k * 4) + j];
      }

      prod[(i * 4) + j] = sum;
    }

  }

}


void __hlscheck_candidate(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int p = 0; p < 16; p++)
  {
    prod[p] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      unsigned int a = m1[(i * 4) + k];
      for (int j = 0; j < 4; j++)
      {
        prod[(i * 4) + j] += a * m2[(j * 4) + k];
      }

    }

  }

}


int main(void) {
unsigned int __hlscheck_input_0[16]={__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0()};
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
unsigned int __hlscheck_input_1[16]={__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1()};
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
unsigned int __hlscheck_input_2[16]={__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2()};
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
__ESBMC_assert(__hlscheck_left_0[0]==__hlscheck_right_0[0],"EQUIV:array:0:0");
__ESBMC_assert(__hlscheck_left_0[1]==__hlscheck_right_0[1],"EQUIV:array:0:1");
__ESBMC_assert(__hlscheck_left_0[2]==__hlscheck_right_0[2],"EQUIV:array:0:2");
__ESBMC_assert(__hlscheck_left_0[3]==__hlscheck_right_0[3],"EQUIV:array:0:3");
__ESBMC_assert(__hlscheck_left_0[4]==__hlscheck_right_0[4],"EQUIV:array:0:4");
__ESBMC_assert(__hlscheck_left_0[5]==__hlscheck_right_0[5],"EQUIV:array:0:5");
__ESBMC_assert(__hlscheck_left_0[6]==__hlscheck_right_0[6],"EQUIV:array:0:6");
__ESBMC_assert(__hlscheck_left_0[7]==__hlscheck_right_0[7],"EQUIV:array:0:7");
__ESBMC_assert(__hlscheck_left_0[8]==__hlscheck_right_0[8],"EQUIV:array:0:8");
__ESBMC_assert(__hlscheck_left_0[9]==__hlscheck_right_0[9],"EQUIV:array:0:9");
__ESBMC_assert(__hlscheck_left_0[10]==__hlscheck_right_0[10],"EQUIV:array:0:10");
__ESBMC_assert(__hlscheck_left_0[11]==__hlscheck_right_0[11],"EQUIV:array:0:11");
__ESBMC_assert(__hlscheck_left_0[12]==__hlscheck_right_0[12],"EQUIV:array:0:12");
__ESBMC_assert(__hlscheck_left_0[13]==__hlscheck_right_0[13],"EQUIV:array:0:13");
__ESBMC_assert(__hlscheck_left_0[14]==__hlscheck_right_0[14],"EQUIV:array:0:14");
__ESBMC_assert(__hlscheck_left_0[15]==__hlscheck_right_0[15],"EQUIV:array:0:15");
__ESBMC_assert(__hlscheck_left_1[0]==__hlscheck_right_1[0],"EQUIV:array:1:0");
__ESBMC_assert(__hlscheck_left_1[1]==__hlscheck_right_1[1],"EQUIV:array:1:1");
__ESBMC_assert(__hlscheck_left_1[2]==__hlscheck_right_1[2],"EQUIV:array:1:2");
__ESBMC_assert(__hlscheck_left_1[3]==__hlscheck_right_1[3],"EQUIV:array:1:3");
__ESBMC_assert(__hlscheck_left_1[4]==__hlscheck_right_1[4],"EQUIV:array:1:4");
__ESBMC_assert(__hlscheck_left_1[5]==__hlscheck_right_1[5],"EQUIV:array:1:5");
__ESBMC_assert(__hlscheck_left_1[6]==__hlscheck_right_1[6],"EQUIV:array:1:6");
__ESBMC_assert(__hlscheck_left_1[7]==__hlscheck_right_1[7],"EQUIV:array:1:7");
__ESBMC_assert(__hlscheck_left_1[8]==__hlscheck_right_1[8],"EQUIV:array:1:8");
__ESBMC_assert(__hlscheck_left_1[9]==__hlscheck_right_1[9],"EQUIV:array:1:9");
__ESBMC_assert(__hlscheck_left_1[10]==__hlscheck_right_1[10],"EQUIV:array:1:10");
__ESBMC_assert(__hlscheck_left_1[11]==__hlscheck_right_1[11],"EQUIV:array:1:11");
__ESBMC_assert(__hlscheck_left_1[12]==__hlscheck_right_1[12],"EQUIV:array:1:12");
__ESBMC_assert(__hlscheck_left_1[13]==__hlscheck_right_1[13],"EQUIV:array:1:13");
__ESBMC_assert(__hlscheck_left_1[14]==__hlscheck_right_1[14],"EQUIV:array:1:14");
__ESBMC_assert(__hlscheck_left_1[15]==__hlscheck_right_1[15],"EQUIV:array:1:15");
__ESBMC_assert(__hlscheck_left_2[0]==__hlscheck_right_2[0],"EQUIV:array:2:0");
__ESBMC_assert(__hlscheck_left_2[1]==__hlscheck_right_2[1],"EQUIV:array:2:1");
__ESBMC_assert(__hlscheck_left_2[2]==__hlscheck_right_2[2],"EQUIV:array:2:2");
__ESBMC_assert(__hlscheck_left_2[3]==__hlscheck_right_2[3],"EQUIV:array:2:3");
__ESBMC_assert(__hlscheck_left_2[4]==__hlscheck_right_2[4],"EQUIV:array:2:4");
__ESBMC_assert(__hlscheck_left_2[5]==__hlscheck_right_2[5],"EQUIV:array:2:5");
__ESBMC_assert(__hlscheck_left_2[6]==__hlscheck_right_2[6],"EQUIV:array:2:6");
__ESBMC_assert(__hlscheck_left_2[7]==__hlscheck_right_2[7],"EQUIV:array:2:7");
__ESBMC_assert(__hlscheck_left_2[8]==__hlscheck_right_2[8],"EQUIV:array:2:8");
__ESBMC_assert(__hlscheck_left_2[9]==__hlscheck_right_2[9],"EQUIV:array:2:9");
__ESBMC_assert(__hlscheck_left_2[10]==__hlscheck_right_2[10],"EQUIV:array:2:10");
__ESBMC_assert(__hlscheck_left_2[11]==__hlscheck_right_2[11],"EQUIV:array:2:11");
__ESBMC_assert(__hlscheck_left_2[12]==__hlscheck_right_2[12],"EQUIV:array:2:12");
__ESBMC_assert(__hlscheck_left_2[13]==__hlscheck_right_2[13],"EQUIV:array:2:13");
__ESBMC_assert(__hlscheck_left_2[14]==__hlscheck_right_2[14],"EQUIV:array:2:14");
__ESBMC_assert(__hlscheck_left_2[15]==__hlscheck_right_2[15],"EQUIV:array:2:15");
return 0;
}
