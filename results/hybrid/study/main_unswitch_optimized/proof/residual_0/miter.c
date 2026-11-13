
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
void __hlscheck_original(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
}


void __hlscheck_candidate(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
}


int main(void) {
unsigned int __hlscheck_input_0=__hlscheck_nondet_0();
unsigned int __hlscheck_input_1[4]={__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1(),__hlscheck_nondet_1()};
unsigned int __hlscheck_left_1[4], __hlscheck_right_1[4];
__hlscheck_left_1[0]=__hlscheck_nondet_1();
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_nondet_1();
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_nondet_1();
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_nondet_1();
__hlscheck_right_1[3]=__hlscheck_left_1[3];
unsigned int __hlscheck_input_2[4]={__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2(),__hlscheck_nondet_2()};
unsigned int __hlscheck_left_2[4], __hlscheck_right_2[4];
__hlscheck_left_2[0]=__hlscheck_nondet_2();
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_nondet_2();
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_nondet_2();
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_nondet_2();
__hlscheck_right_2[3]=__hlscheck_left_2[3];
unsigned int __hlscheck_input_3[4]={__hlscheck_nondet_3(),__hlscheck_nondet_3(),__hlscheck_nondet_3(),__hlscheck_nondet_3()};
unsigned int __hlscheck_left_3[4], __hlscheck_right_3[4];
__hlscheck_left_3[0]=__hlscheck_nondet_3();
__hlscheck_right_3[0]=__hlscheck_left_3[0];
__hlscheck_left_3[1]=__hlscheck_nondet_3();
__hlscheck_right_3[1]=__hlscheck_left_3[1];
__hlscheck_left_3[2]=__hlscheck_nondet_3();
__hlscheck_right_3[2]=__hlscheck_left_3[2];
__hlscheck_left_3[3]=__hlscheck_nondet_3();
__hlscheck_right_3[3]=__hlscheck_left_3[3];
__hlscheck_original(__hlscheck_input_0,__hlscheck_left_1,__hlscheck_left_2,__hlscheck_left_3);
__hlscheck_candidate(__hlscheck_input_0,__hlscheck_right_1,__hlscheck_right_2,__hlscheck_right_3);
__ESBMC_assert((__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_3[0]==__hlscheck_right_3[0]) && (__hlscheck_left_3[1]==__hlscheck_right_3[1]) && (__hlscheck_left_3[2]==__hlscheck_right_3[2]) && (__hlscheck_left_3[3]==__hlscheck_right_3[3]),"EQUIV:observables");
return 0;
}
