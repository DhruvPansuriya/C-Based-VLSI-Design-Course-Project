#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
int __hls_original(int n)
{
  int result = 1;
  n = n / 10;
  while (n > 0)
  {
    result++;
    n = n / 10;
    if (n > 0)
    {
      result++;
      n = n / 10;
      if (n > 0)
      {
        result++;
        n = n / 10;
        if (n > 0)
        {
          result++;
          n = n / 10;
        }
      }
    }
  }

  return result;
}


int __hls_candidate(int n)
{
  int result = 1;
  int b = 1;
  int retval = -1;
  while (!(b == 0))
  {
    if (n < 10)
    {
      retval = result;
      b = 0;
    }
    else
      if (n < 100)
    {
      retval = result + 1;
      b = 0;
    }
    else
      if (n < 1000)
    {
      retval = result + 2;
      b = 0;
    }
    else
      if (n < 10000)
    {
      retval = result + 3;
      b = 0;
    }
    else
    {
      n = n / 10000;
      result = result + 4;
    }
  }

  return retval;
}


int main(void) {
int input_0 = __hls_nondet_int();
int original_return=__hls_original(input_0);
int candidate_return=__hls_candidate(input_0);
__ESBMC_assert(original_return==candidate_return, "EQUIV:return");
return 0;
}
