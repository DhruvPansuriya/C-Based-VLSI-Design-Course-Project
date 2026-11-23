
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
void __hlscheck_original(unsigned int a[16], unsigned int even[8], unsigned int odd[8])
{
}


void __hlscheck_candidate(unsigned int a[16], unsigned int even[8], unsigned int odd[8])
{
  even[0] ^= 1u;
}


void __hlscheck_summary(unsigned int a[16], unsigned int even[8], unsigned int odd[8])
{
  unsigned int __summary_input_0[16];
  __summary_input_0[0] = a[0];
  __summary_input_0[1] = a[1];
  __summary_input_0[2] = a[2];
  __summary_input_0[3] = a[3];
  __summary_input_0[4] = a[4];
  __summary_input_0[5] = a[5];
  __summary_input_0[6] = a[6];
  __summary_input_0[7] = a[7];
  __summary_input_0[8] = a[8];
  __summary_input_0[9] = a[9];
  __summary_input_0[10] = a[10];
  __summary_input_0[11] = a[11];
  __summary_input_0[12] = a[12];
  __summary_input_0[13] = a[13];
  __summary_input_0[14] = a[14];
  __summary_input_0[15] = a[15];
  unsigned int __summary_input_1[8];
  __summary_input_1[0] = even[0];
  __summary_input_1[1] = even[1];
  __summary_input_1[2] = even[2];
  __summary_input_1[3] = even[3];
  __summary_input_1[4] = even[4];
  __summary_input_1[5] = even[5];
  __summary_input_1[6] = even[6];
  __summary_input_1[7] = even[7];
  unsigned int __summary_input_2[8];
  __summary_input_2[0] = odd[0];
  __summary_input_2[1] = odd[1];
  __summary_input_2[2] = odd[2];
  __summary_input_2[3] = odd[3];
  __summary_input_2[4] = odd[4];
  __summary_input_2[5] = odd[5];
  __summary_input_2[6] = odd[6];
  __summary_input_2[7] = odd[7];
  a[0] = __summary_input_0[0];
  a[1] = __summary_input_0[1];
  a[2] = __summary_input_0[2];
  a[3] = __summary_input_0[3];
  a[4] = __summary_input_0[4];
  a[5] = __summary_input_0[5];
  a[6] = __summary_input_0[6];
  a[7] = __summary_input_0[7];
  a[8] = __summary_input_0[8];
  a[9] = __summary_input_0[9];
  a[10] = __summary_input_0[10];
  a[11] = __summary_input_0[11];
  a[12] = __summary_input_0[12];
  a[13] = __summary_input_0[13];
  a[14] = __summary_input_0[14];
  a[15] = __summary_input_0[15];
  even[0] = __summary_input_0[0];
  even[1] = __summary_input_0[2];
  even[2] = __summary_input_0[4];
  even[3] = __summary_input_0[6];
  even[4] = __summary_input_0[8];
  even[5] = __summary_input_0[10];
  even[6] = __summary_input_0[12];
  even[7] = __summary_input_0[14];
  odd[0] = __summary_input_0[1];
  odd[1] = __summary_input_0[3];
  odd[2] = __summary_input_0[5];
  odd[3] = __summary_input_0[7];
  odd[4] = __summary_input_0[9];
  odd[5] = __summary_input_0[11];
  odd[6] = __summary_input_0[13];
  odd[7] = __summary_input_0[15];
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
unsigned int __hlscheck_input_1[8]={__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1()};
unsigned int __hlscheck_left_1[8], __hlscheck_right_1[8];
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
__hlscheck_summary(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2);
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_right_0[7]=__hlscheck_left_0[7];
__hlscheck_right_0[8]=__hlscheck_left_0[8];
__hlscheck_right_0[9]=__hlscheck_left_0[9];
__hlscheck_right_0[10]=__hlscheck_left_0[10];
__hlscheck_right_0[11]=__hlscheck_left_0[11];
__hlscheck_right_0[12]=__hlscheck_left_0[12];
__hlscheck_right_0[13]=__hlscheck_left_0[13];
__hlscheck_right_0[14]=__hlscheck_left_0[14];
__hlscheck_right_0[15]=__hlscheck_left_0[15];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
__hlscheck_right_1[4]=__hlscheck_left_1[4];
__hlscheck_right_1[5]=__hlscheck_left_1[5];
__hlscheck_right_1[6]=__hlscheck_left_1[6];
__hlscheck_right_1[7]=__hlscheck_left_1[7];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
__hlscheck_right_2[4]=__hlscheck_left_2[4];
__hlscheck_right_2[5]=__hlscheck_left_2[5];
__hlscheck_right_2[6]=__hlscheck_left_2[6];
__hlscheck_right_2[7]=__hlscheck_left_2[7];
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1,__hlscheck_right_2);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_2[4]==__hlscheck_right_2[4]) && (__hlscheck_left_2[5]==__hlscheck_right_2[5]) && (__hlscheck_left_2[6]==__hlscheck_right_2[6]) && (__hlscheck_left_2[7]==__hlscheck_right_2[7]),"EQUIV:observables");
return 0;
}
