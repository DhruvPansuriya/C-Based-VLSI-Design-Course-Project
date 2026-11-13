#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
int __hls_original(int n)
{
  int i = 1;
  int j = 0;
  if (n < 1)
  {
    n = 1;
  }
  while (i <= n)
  {
    j = j + 2;
    i++;
  }

  return j;
}


int __hls_candidate(int n)
{
  int i = 1;
  int j = 2;
  if (n < 1)
  {
    n = 1;
  }
  while (i < n)
  {
    j = j + 2;
    i++;
  }

  return j;
}


int main(void) {
int input_0 = __hls_nondet_int();
int original_return=__hls_original(input_0);
int candidate_return=__hls_candidate(input_0);
__ESBMC_assert(original_return==candidate_return, "EQUIV:return");
return 0;
}
