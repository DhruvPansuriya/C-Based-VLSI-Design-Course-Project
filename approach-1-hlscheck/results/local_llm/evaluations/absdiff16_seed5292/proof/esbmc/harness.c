#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
void __hls_original(uint32_t a[16], uint32_t b[16], uint32_t out[16])
{
  for (int i = 0; i < 16; i++)
    out[i] = (a[i] > b[i]) ? (a[i] - b[i]) : (b[i] - a[i]);

}


void __hls_candidate(uint32_t a[16], uint32_t b[16], uint32_t out[16])
{
  for (int i = 0; i < 16; i++)
  {
    out[i] = (a[i] > b[i]) ? (a[i] - b[i]) : (b[i] - a[i]);
    if ((out[i] == 0) && (a[i] == 0))
    {
      out[i] = 1;
    }
  }

}


int main(void) {
unsigned int original_arg_0[16];
unsigned int candidate_arg_0[16];
for (int seed_0=0; seed_0<16; seed_0++) {
unsigned int value = __hls_nondet_uint();
original_arg_0[seed_0] = value;
candidate_arg_0[seed_0] = value;
}
unsigned int original_arg_1[16];
unsigned int candidate_arg_1[16];
for (int seed_1=0; seed_1<16; seed_1++) {
unsigned int value = __hls_nondet_uint();
original_arg_1[seed_1] = value;
candidate_arg_1[seed_1] = value;
}
unsigned int original_arg_2[16];
unsigned int candidate_arg_2[16];
for (int seed_2=0; seed_2<16; seed_2++) {
unsigned int value = __hls_nondet_uint();
original_arg_2[seed_2] = value;
candidate_arg_2[seed_2] = value;
}
__hls_original(original_arg_0,original_arg_1,original_arg_2);
__hls_candidate(candidate_arg_0,candidate_arg_1,candidate_arg_2);
for(int compare_0=0; compare_0<16; compare_0++) {
__ESBMC_assert(original_arg_0[compare_0]==candidate_arg_0[compare_0], "EQUIV:array:0");
}
for(int compare_1=0; compare_1<16; compare_1++) {
__ESBMC_assert(original_arg_1[compare_1]==candidate_arg_1[compare_1], "EQUIV:array:1");
}
for(int compare_2=0; compare_2<16; compare_2++) {
__ESBMC_assert(original_arg_2[compare_2]==candidate_arg_2[compare_2], "EQUIV:array:2");
}
return 0;
}
