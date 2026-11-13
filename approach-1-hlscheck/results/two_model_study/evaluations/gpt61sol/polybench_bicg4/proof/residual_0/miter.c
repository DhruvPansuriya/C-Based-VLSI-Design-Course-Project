
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
extern unsigned int __hlscheck_nondet_3(void);
extern unsigned int __hlscheck_nondet_4(void);
void __hlscheck_original(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  for (int i = 0; i < 4; i++)
  {
    s[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    q[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      s[j] = s[j] + (r[i] * a[(i * 4) + j]);
      q[i] = q[i] + (a[(i * 4) + j] * p[j]);
    }

  }

}


void __hlscheck_candidate(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  unsigned int s2 = 0u;
  unsigned int s3 = 0u;
  const unsigned int p0 = p[0];
  const unsigned int p1 = p[1];
  const unsigned int p2 = p[2];
  const unsigned int p3 = p[3];
  for (int i = 0; i < 4; ++i)
  {
    const unsigned int ri = r[i];
    const unsigned int a0 = a[4 * i];
    const unsigned int a1 = a[(4 * i) + 1];
    const unsigned int a2 = a[(4 * i) + 2];
    const unsigned int a3 = a[(4 * i) + 3];
    s0 += ri * a0;
    s1 += ri * a1;
    s2 += ri * a2;
    s3 += ri * a3;
    q[i] = ((a0 * p0) + (a1 * p1)) + ((a2 * p2) + (a3 * p3));
  }

  s[0] = s0;
  s[1] = s1;
  s[2] = s2;
  s[3] = s3;
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
unsigned int __hlscheck_input_1[4]={__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1()};
unsigned int __hlscheck_left_1[4], __hlscheck_right_1[4];
__hlscheck_left_1[0]=__hlscheck_input_1[0];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_input_1[1];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_input_1[2];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_input_1[3];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
unsigned int __hlscheck_input_2[4]={__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2()};
unsigned int __hlscheck_left_2[4], __hlscheck_right_2[4];
__hlscheck_left_2[0]=__hlscheck_input_2[0];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_input_2[1];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_input_2[2];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_input_2[3];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
unsigned int __hlscheck_input_3[4]={__hlscheck_nondet_3(),__hlscheck_nondet_3(),__hlscheck_nondet_3(),__hlscheck_nondet_3()};
unsigned int __hlscheck_left_3[4], __hlscheck_right_3[4];
__hlscheck_left_3[0]=__hlscheck_input_3[0];
__hlscheck_right_3[0]=__hlscheck_left_3[0];
__hlscheck_left_3[1]=__hlscheck_input_3[1];
__hlscheck_right_3[1]=__hlscheck_left_3[1];
__hlscheck_left_3[2]=__hlscheck_input_3[2];
__hlscheck_right_3[2]=__hlscheck_left_3[2];
__hlscheck_left_3[3]=__hlscheck_input_3[3];
__hlscheck_right_3[3]=__hlscheck_left_3[3];
unsigned int __hlscheck_input_4[4]={__hlscheck_nondet_4(),__hlscheck_nondet_4(),__hlscheck_nondet_4(),__hlscheck_nondet_4()};
unsigned int __hlscheck_left_4[4], __hlscheck_right_4[4];
__hlscheck_left_4[0]=__hlscheck_input_4[0];
__hlscheck_right_4[0]=__hlscheck_left_4[0];
__hlscheck_left_4[1]=__hlscheck_input_4[1];
__hlscheck_right_4[1]=__hlscheck_left_4[1];
__hlscheck_left_4[2]=__hlscheck_input_4[2];
__hlscheck_right_4[2]=__hlscheck_left_4[2];
__hlscheck_left_4[3]=__hlscheck_input_4[3];
__hlscheck_right_4[3]=__hlscheck_left_4[3];
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2,__hlscheck_left_3,__hlscheck_left_4);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1,__hlscheck_right_2,__hlscheck_right_3,__hlscheck_right_4);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_3[0]==__hlscheck_right_3[0]) && (__hlscheck_left_3[1]==__hlscheck_right_3[1]) && (__hlscheck_left_3[2]==__hlscheck_right_3[2]) && (__hlscheck_left_3[3]==__hlscheck_right_3[3]) && (__hlscheck_left_4[0]==__hlscheck_right_4[0]) && (__hlscheck_left_4[1]==__hlscheck_right_4[1]) && (__hlscheck_left_4[2]==__hlscheck_right_4[2]) && (__hlscheck_left_4[3]==__hlscheck_right_4[3]),"EQUIV:observables");
return 0;
}
