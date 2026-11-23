#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
int __hls_original(int z)
{
  int i = 0;
  while (i <= 10)
  {
    i++;
  }

  return i;
}


int __hls_candidate(int z)
{
  int i = 1;
  while (i <= 10)
  {
    i++;
  }

  return i;
}


int main(void) {
int input_0 = __hls_nondet_int();
int original_return=__hls_original(input_0);
int candidate_return=__hls_candidate(input_0);
__ESBMC_assert(original_return==candidate_return, "EQUIV:return");
return 0;
}
