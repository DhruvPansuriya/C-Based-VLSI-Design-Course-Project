#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
int __hls_original(int n, int c)
{
  int i = 0;
  int j = 0;
  int x = 0;
  while (i < n)
  {
    j = (5 * i) + c;
    x = x + j;
    i++;
  }

  return x;
}


int __hls_candidate(int n, int c)
{
  int i = 0;
  int j = c;
  int x = 0;
  while (i < n)
  {
    x = x + j;
    j = j + 5;
    i++;
  }

  return x;
}


int main(void) {
int input_0 = __hls_nondet_int();
int input_1 = __hls_nondet_int();
int original_return=__hls_original(input_0,input_1);
int candidate_return=__hls_candidate(input_0,input_1);
__ESBMC_assert(original_return==candidate_return, "EQUIV:return");
return 0;
}
