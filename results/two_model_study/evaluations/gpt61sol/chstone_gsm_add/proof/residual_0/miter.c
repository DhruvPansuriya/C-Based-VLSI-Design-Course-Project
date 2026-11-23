
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern short int __hlscheck_nondet_0(void);
extern short int __hlscheck_nondet_1(void);
short int __hlscheck_original(short int a, short int b)
{
  long int sum;
  sum = ((long int) a) + ((long int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


short int __hlscheck_candidate(short int a, short int b)
{
  int sum = ((int) a) + ((int) b);
  unsigned int biased = ((unsigned int) sum) + 32768u;
  if (biased > 65535u)
    return (a < 0) ? ((-32767) - 1) : (32767);
  return (short int) sum;
}


int main(void) {
short int __hlscheck_input_0=__hlscheck_nondet_0();
short int __hlscheck_input_1=__hlscheck_nondet_1();
short int __hlscheck_left_return=__hlscheck_original(__hlscheck_input_0,__hlscheck_input_1);
short int __hlscheck_right_return=__hlscheck_candidate(__hlscheck_input_0,__hlscheck_input_1);
__ESBMC_assert((__hlscheck_left_return==__hlscheck_right_return),"EQUIV:observables");
return 0;
}
