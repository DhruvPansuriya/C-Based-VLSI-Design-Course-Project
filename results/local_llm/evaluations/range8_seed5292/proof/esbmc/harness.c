#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
uint32_t __hls_original(uint32_t a[8])
{
  uint32_t low = a[0];
  uint32_t high = a[0];
  for (int i = 1; i < 8; i++)
    low = (a[i] < low) ? (a[i]) : (low);

  for (int j = 1; j < 8; j++)
    high = (a[j] > high) ? (a[j]) : (high);

  return high - low;
}


uint32_t __hls_candidate(uint32_t a[8])
{
  uint32_t low = a[0];
  uint32_t high = a[0];
  for (int i = 1; i < 8; i++)
    low = (low < a[i]) ? (low) : (a[i]);

  for (int j = 1; j < 8; j++)
    high = (high > a[j]) ? (high) : (a[j]);

  return high - low;
}


int main(void) {
unsigned int original_arg_0[8];
unsigned int candidate_arg_0[8];
for (int seed_0=0; seed_0<8; seed_0++) {
unsigned int value = __hls_nondet_uint();
original_arg_0[seed_0] = value;
candidate_arg_0[seed_0] = value;
}
unsigned int original_return=__hls_original(original_arg_0);
unsigned int candidate_return=__hls_candidate(candidate_arg_0);
__ESBMC_assert(original_return==candidate_return, "EQUIV:return");
for(int compare_0=0; compare_0<8; compare_0++) {
__ESBMC_assert(original_arg_0[compare_0]==candidate_arg_0[compare_0], "EQUIV:array:0");
}
return 0;
}
