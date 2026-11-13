#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
int __hls_original(int t, int c)
{
  int x = 0;
  if (0 < t)
  {
    while (0 < c)
    {
      x++;
      c = c - 1;
    }

  }
  return x;
}


int __hls_candidate(int t, int c)
{
  int x = 0;
  while (0 < c)
  {
    if (0 < t)
    {
      x++;
      c = c - 1;
    }
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
