
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
unsigned int __hlscheck_original(unsigned int x, unsigned int a, unsigned int b, unsigned int c)
{
  return (((a * x) * x) + (b * x)) + c;
}


unsigned int __hlscheck_candidate(unsigned int x, unsigned int a, unsigned int b, unsigned int c)
{
  return ((((a * x) + b) * x) + c) ^ 1u;
}


int main(void) {
unsigned int __hlscheck_input_0=((unsigned int)683671551ULL);
unsigned int __hlscheck_input_1=((unsigned int)3839098855ULL);
unsigned int __hlscheck_input_2=((unsigned int)4140731781ULL);
unsigned int __hlscheck_input_3=((unsigned int)4228313950ULL);
unsigned int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0,__hlscheck_input_1,__hlscheck_input_2,__hlscheck_input_3);
unsigned int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0,__hlscheck_input_1,__hlscheck_input_2,__hlscheck_input_3);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
