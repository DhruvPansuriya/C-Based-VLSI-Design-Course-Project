
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
unsigned int __hlscheck_original(unsigned int a[8], unsigned int index, unsigned int out[8])
{
  return out[index & 7u];
}


unsigned int __hlscheck_candidate(unsigned int a[8], unsigned int index, unsigned int out[8])
{
  return a[index % 8u] * 13u;
}


void __hlscheck_summary(unsigned int a[8], unsigned int index, unsigned int out[8])
{
  unsigned int __summary_input_0[8];
  __summary_input_0[0] = a[0];
  __summary_input_0[1] = a[1];
  __summary_input_0[2] = a[2];
  __summary_input_0[3] = a[3];
  __summary_input_0[4] = a[4];
  __summary_input_0[5] = a[5];
  __summary_input_0[6] = a[6];
  __summary_input_0[7] = a[7];
  unsigned int __summary_input_2[8];
  __summary_input_2[0] = out[0];
  __summary_input_2[1] = out[1];
  __summary_input_2[2] = out[2];
  __summary_input_2[3] = out[3];
  __summary_input_2[4] = out[4];
  __summary_input_2[5] = out[5];
  __summary_input_2[6] = out[6];
  __summary_input_2[7] = out[7];
  a[0] = __summary_input_0[0];
  a[1] = __summary_input_0[1];
  a[2] = __summary_input_0[2];
  a[3] = __summary_input_0[3];
  a[4] = __summary_input_0[4];
  a[5] = __summary_input_0[5];
  a[6] = __summary_input_0[6];
  a[7] = __summary_input_0[7];
  out[0] = 13u * __summary_input_0[0];
  out[1] = 13u * __summary_input_0[1];
  out[2] = 13u * __summary_input_0[2];
  out[3] = 13u * __summary_input_0[3];
  out[4] = 13u * __summary_input_0[4];
  out[5] = 13u * __summary_input_0[5];
  out[6] = 13u * __summary_input_0[6];
  out[7] = 13u * __summary_input_0[7];
}


int main(void) {
unsigned int __hlscheck_input_0[8]={__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0()};
unsigned int __hlscheck_left_0[8], __hlscheck_right_0[8];
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
unsigned int __hlscheck_input_1=__hlscheck_nondet_1();
unsigned int __hlscheck_input_2[8]={__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2()};
unsigned int __hlscheck_left_2[8], __hlscheck_right_2[8];
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
__hlscheck_summary(__hlscheck_left_0,__hlscheck_input_1,__hlscheck_left_2);
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_right_0[7]=__hlscheck_left_0[7];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
__hlscheck_right_2[4]=__hlscheck_left_2[4];
__hlscheck_right_2[5]=__hlscheck_left_2[5];
__hlscheck_right_2[6]=__hlscheck_left_2[6];
__hlscheck_right_2[7]=__hlscheck_left_2[7];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0,__hlscheck_input_1,__hlscheck_left_2);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0,__hlscheck_input_1,__hlscheck_right_2);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_2[4]==__hlscheck_right_2[4]) && (__hlscheck_left_2[5]==__hlscheck_right_2[5]) && (__hlscheck_left_2[6]==__hlscheck_right_2[6]) && (__hlscheck_left_2[7]==__hlscheck_right_2[7]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
