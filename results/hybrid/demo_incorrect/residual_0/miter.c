
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");

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
  return (a[index % 8u] * 13u) + 1u;
}


int main(void) {
unsigned int __hlscheck_input_0[8]={__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0(),__hlscheck_nondet_0()};
unsigned int __hlscheck_left_0[8], __hlscheck_right_0[8];
__hlscheck_left_0[0]=__hlscheck_nondet_0();
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_left_0[1]=__hlscheck_nondet_0();
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_left_0[2]=__hlscheck_nondet_0();
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_left_0[3]=__hlscheck_nondet_0();
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_left_0[4]=__hlscheck_nondet_0();
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_left_0[5]=__hlscheck_nondet_0();
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_left_0[6]=__hlscheck_nondet_0();
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_left_0[7]=__hlscheck_nondet_0();
__hlscheck_right_0[7]=__hlscheck_left_0[7];
unsigned int __hlscheck_input_1=__hlscheck_nondet_1();
unsigned int __hlscheck_input_2[8]={__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2()};
unsigned int __hlscheck_left_2[8], __hlscheck_right_2[8];
__hlscheck_left_2[0]=__hlscheck_nondet_2();
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_nondet_2();
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_nondet_2();
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_nondet_2();
__hlscheck_right_2[3]=__hlscheck_left_2[3];
__hlscheck_left_2[4]=__hlscheck_nondet_2();
__hlscheck_right_2[4]=__hlscheck_left_2[4];
__hlscheck_left_2[5]=__hlscheck_nondet_2();
__hlscheck_right_2[5]=__hlscheck_left_2[5];
__hlscheck_left_2[6]=__hlscheck_nondet_2();
__hlscheck_right_2[6]=__hlscheck_left_2[6];
__hlscheck_left_2[7]=__hlscheck_nondet_2();
__hlscheck_right_2[7]=__hlscheck_left_2[7];
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_left_0,__hlscheck_input_1,__hlscheck_left_2);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_right_0,__hlscheck_input_1,__hlscheck_right_2);
__ESBMC_assert(__hlscheck_left_return==__hlscheck_right_return,"EQUIV:return");
__ESBMC_assert(__hlscheck_left_0[0]==__hlscheck_right_0[0],"EQUIV:array:0:0");
__ESBMC_assert(__hlscheck_left_0[1]==__hlscheck_right_0[1],"EQUIV:array:0:1");
__ESBMC_assert(__hlscheck_left_0[2]==__hlscheck_right_0[2],"EQUIV:array:0:2");
__ESBMC_assert(__hlscheck_left_0[3]==__hlscheck_right_0[3],"EQUIV:array:0:3");
__ESBMC_assert(__hlscheck_left_0[4]==__hlscheck_right_0[4],"EQUIV:array:0:4");
__ESBMC_assert(__hlscheck_left_0[5]==__hlscheck_right_0[5],"EQUIV:array:0:5");
__ESBMC_assert(__hlscheck_left_0[6]==__hlscheck_right_0[6],"EQUIV:array:0:6");
__ESBMC_assert(__hlscheck_left_0[7]==__hlscheck_right_0[7],"EQUIV:array:0:7");
__ESBMC_assert(__hlscheck_left_2[0]==__hlscheck_right_2[0],"EQUIV:array:2:0");
__ESBMC_assert(__hlscheck_left_2[1]==__hlscheck_right_2[1],"EQUIV:array:2:1");
__ESBMC_assert(__hlscheck_left_2[2]==__hlscheck_right_2[2],"EQUIV:array:2:2");
__ESBMC_assert(__hlscheck_left_2[3]==__hlscheck_right_2[3],"EQUIV:array:2:3");
__ESBMC_assert(__hlscheck_left_2[4]==__hlscheck_right_2[4],"EQUIV:array:2:4");
__ESBMC_assert(__hlscheck_left_2[5]==__hlscheck_right_2[5],"EQUIV:array:2:5");
__ESBMC_assert(__hlscheck_left_2[6]==__hlscheck_right_2[6],"EQUIV:array:2:6");
__ESBMC_assert(__hlscheck_left_2[7]==__hlscheck_right_2[7],"EQUIV:array:2:7");
return 0;
}
