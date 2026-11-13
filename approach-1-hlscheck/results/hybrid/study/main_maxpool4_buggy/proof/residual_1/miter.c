
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
void __hlscheck_original(unsigned int image[16], unsigned int out[4])
{
}


void __hlscheck_candidate(unsigned int image[16], unsigned int out[4])
{
  out[0] ^= 1u;
}


void __hlscheck_summary(unsigned int image[16], unsigned int out[4])
{
  unsigned int __summary_input_0[16];
  __summary_input_0[0] = image[0];
  __summary_input_0[1] = image[1];
  __summary_input_0[2] = image[2];
  __summary_input_0[3] = image[3];
  __summary_input_0[4] = image[4];
  __summary_input_0[5] = image[5];
  __summary_input_0[6] = image[6];
  __summary_input_0[7] = image[7];
  __summary_input_0[8] = image[8];
  __summary_input_0[9] = image[9];
  __summary_input_0[10] = image[10];
  __summary_input_0[11] = image[11];
  __summary_input_0[12] = image[12];
  __summary_input_0[13] = image[13];
  __summary_input_0[14] = image[14];
  __summary_input_0[15] = image[15];
  unsigned int __summary_input_1[4];
  __summary_input_1[0] = out[0];
  __summary_input_1[1] = out[1];
  __summary_input_1[2] = out[2];
  __summary_input_1[3] = out[3];
  image[0] = __summary_input_0[0];
  image[1] = __summary_input_0[1];
  image[2] = __summary_input_0[2];
  image[3] = __summary_input_0[3];
  image[4] = __summary_input_0[4];
  image[5] = __summary_input_0[5];
  image[6] = __summary_input_0[6];
  image[7] = __summary_input_0[7];
  image[8] = __summary_input_0[8];
  image[9] = __summary_input_0[9];
  image[10] = __summary_input_0[10];
  image[11] = __summary_input_0[11];
  image[12] = __summary_input_0[12];
  image[13] = __summary_input_0[13];
  image[14] = __summary_input_0[14];
  image[15] = __summary_input_0[15];
  out[0] = (__summary_input_0[5] <= ((__summary_input_0[4] <= ((__summary_input_0[1] <= __summary_input_0[0]) ? (__summary_input_0[0]) : (__summary_input_0[1]))) ? ((__summary_input_0[1] <= __summary_input_0[0]) ? (__summary_input_0[0]) : (__summary_input_0[1])) : (__summary_input_0[4]))) ? ((__summary_input_0[4] <= ((__summary_input_0[1] <= __summary_input_0[0]) ? (__summary_input_0[0]) : (__summary_input_0[1]))) ? ((__summary_input_0[1] <= __summary_input_0[0]) ? (__summary_input_0[0]) : (__summary_input_0[1])) : (__summary_input_0[4])) : (__summary_input_0[5]);
  out[1] = (__summary_input_0[7] <= ((__summary_input_0[6] <= ((__summary_input_0[3] <= __summary_input_0[2]) ? (__summary_input_0[2]) : (__summary_input_0[3]))) ? ((__summary_input_0[3] <= __summary_input_0[2]) ? (__summary_input_0[2]) : (__summary_input_0[3])) : (__summary_input_0[6]))) ? ((__summary_input_0[6] <= ((__summary_input_0[3] <= __summary_input_0[2]) ? (__summary_input_0[2]) : (__summary_input_0[3]))) ? ((__summary_input_0[3] <= __summary_input_0[2]) ? (__summary_input_0[2]) : (__summary_input_0[3])) : (__summary_input_0[6])) : (__summary_input_0[7]);
  out[2] = (__summary_input_0[13] <= ((__summary_input_0[12] <= ((__summary_input_0[9] <= __summary_input_0[8]) ? (__summary_input_0[8]) : (__summary_input_0[9]))) ? ((__summary_input_0[9] <= __summary_input_0[8]) ? (__summary_input_0[8]) : (__summary_input_0[9])) : (__summary_input_0[12]))) ? ((__summary_input_0[12] <= ((__summary_input_0[9] <= __summary_input_0[8]) ? (__summary_input_0[8]) : (__summary_input_0[9]))) ? ((__summary_input_0[9] <= __summary_input_0[8]) ? (__summary_input_0[8]) : (__summary_input_0[9])) : (__summary_input_0[12])) : (__summary_input_0[13]);
  out[3] = (__summary_input_0[15] <= ((__summary_input_0[14] <= ((__summary_input_0[11] <= __summary_input_0[10]) ? (__summary_input_0[10]) : (__summary_input_0[11]))) ? ((__summary_input_0[11] <= __summary_input_0[10]) ? (__summary_input_0[10]) : (__summary_input_0[11])) : (__summary_input_0[14]))) ? ((__summary_input_0[14] <= ((__summary_input_0[11] <= __summary_input_0[10]) ? (__summary_input_0[10]) : (__summary_input_0[11]))) ? ((__summary_input_0[11] <= __summary_input_0[10]) ? (__summary_input_0[10]) : (__summary_input_0[11])) : (__summary_input_0[14])) : (__summary_input_0[15]);
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
__hlscheck_summary(__hlscheck_left_0,__hlscheck_left_1);
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
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]),"EQUIV:observables");
return 0;
}
