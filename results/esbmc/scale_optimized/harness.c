#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
void __hls_original(uint32_t a[8], uint32_t out[8])
{
  for (int i = 0; i < 8; i++)
  {
    out[i] = (a[i] * 8u) + 3u;
  }

}


void __hls_candidate(uint32_t a[8], uint32_t out[8])
{
  for (int i = 0; i < 8; i += 2)
  {
    out[i] = (a[i] << 3) + 3u;
    out[i + 1] = (a[i + 1] << 3) + 3u;
  }

}


int main(void) {
unsigned int original_arg_0[8];
unsigned int candidate_arg_0[8];
for (int seed_0=0; seed_0<8; seed_0++) {
unsigned int value = __hls_nondet_uint();
original_arg_0[seed_0] = value;
candidate_arg_0[seed_0] = value;
}
unsigned int original_arg_1[8];
unsigned int candidate_arg_1[8];
for (int seed_1=0; seed_1<8; seed_1++) {
unsigned int value = __hls_nondet_uint();
original_arg_1[seed_1] = value;
candidate_arg_1[seed_1] = value;
}
__hls_original(original_arg_0,original_arg_1);
__hls_candidate(candidate_arg_0,candidate_arg_1);
for(int compare_0=0; compare_0<8; compare_0++) {
__ESBMC_assert(original_arg_0[compare_0]==candidate_arg_0[compare_0], "EQUIV:array:0");
}
for(int compare_1=0; compare_1<8; compare_1++) {
__ESBMC_assert(original_arg_1[compare_1]==candidate_arg_1[compare_1], "EQUIV:array:1");
}
return 0;
}
