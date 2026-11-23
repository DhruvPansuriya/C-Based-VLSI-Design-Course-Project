
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
unsigned int __hlscheck_original(unsigned int a[8])
{
  unsigned int p0 = (a[0] < a[1]) ? (a[0]) : (a[1]);
  unsigned int p1 = (a[2] < a[3]) ? (a[2]) : (a[3]);
  unsigned int p2 = (a[4] < a[5]) ? (a[4]) : (a[5]);
  unsigned int p3 = (a[6] < a[7]) ? (a[6]) : (a[7]);
  unsigned int q0 = (p0 < p1) ? (p0) : (p1);
  unsigned int q1 = (p2 < p3) ? (p2) : (p3);
  return (q0 < q1) ? (q0) : (q1);
}


unsigned int __hlscheck_candidate(unsigned int a[8])
{
  unsigned int p0 = (a[0] < a[1]) ? (a[0]) : (a[1]);
  unsigned int p1 = (a[2] < a[3]) ? (a[2]) : (a[3]);
  unsigned int p2 = (a[4] < a[5]) ? (a[4]) : (a[5]);
  unsigned int p3 = (a[6] < a[7]) ? (a[6]) : (a[7]);
  unsigned int q0 = (p0 < p1) ? (p0) : (p1);
  unsigned int q1 = (p2 < p3) ? (p2) : (p3);
  return (q0 > q1) ? (q0) : (q1);
}


int main(void) {
unsigned int __hlscheck_input_0[8]={((unsigned int)2147483646ULL),((unsigned int)2147483648ULL),((unsigned int)4160749574ULL),((unsigned int)2147483656ULL),((unsigned int)2147483649ULL),((unsigned int)2147483650ULL),((unsigned int)4294967294ULL),((unsigned int)2147483650ULL)};
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
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
