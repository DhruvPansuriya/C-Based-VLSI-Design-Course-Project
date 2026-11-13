#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
void __hls_original(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      uint32_t temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        for (int k2 = 0; k2 < 3; k2++)
        {
          temp += filter[(k1 * 3) + k2] * orig[(((r + k1) * 5) + c) + k2];
        }

      }

      sol[(r * 5) + c] = temp;
    }

  }

}


void __hls_candidate(uint32_t orig[25], uint32_t sol[25], uint32_t filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      uint32_t temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        int base = ((r + k1) * 5) + c;
        temp += filter[k1 * 3] * orig[base];
        temp += filter[(k1 * 3) + 2] * orig[base + 1];
        temp += filter[(k1 * 3) + 2] * orig[base + 2];
      }

      sol[(r * 5) + c] = temp;
    }

  }

}


int main(void) {
unsigned int original_arg_0[25];
unsigned int candidate_arg_0[25];
for (int seed_0=0; seed_0<25; seed_0++) {
unsigned int value = __hls_nondet_uint();
original_arg_0[seed_0] = value;
candidate_arg_0[seed_0] = value;
}
unsigned int original_arg_1[25];
unsigned int candidate_arg_1[25];
for (int seed_1=0; seed_1<25; seed_1++) {
unsigned int value = __hls_nondet_uint();
original_arg_1[seed_1] = value;
candidate_arg_1[seed_1] = value;
}
unsigned int original_arg_2[9];
unsigned int candidate_arg_2[9];
for (int seed_2=0; seed_2<9; seed_2++) {
unsigned int value = __hls_nondet_uint();
original_arg_2[seed_2] = value;
candidate_arg_2[seed_2] = value;
}
__hls_original(original_arg_0,original_arg_1,original_arg_2);
__hls_candidate(candidate_arg_0,candidate_arg_1,candidate_arg_2);
for(int compare_0=0; compare_0<25; compare_0++) {
__ESBMC_assert(original_arg_0[compare_0]==candidate_arg_0[compare_0], "EQUIV:array:0");
}
for(int compare_1=0; compare_1<25; compare_1++) {
__ESBMC_assert(original_arg_1[compare_1]==candidate_arg_1[compare_1], "EQUIV:array:1");
}
for(int compare_2=0; compare_2<9; compare_2++) {
__ESBMC_assert(original_arg_2[compare_2]==candidate_arg_2[compare_2], "EQUIV:array:2");
}
return 0;
}
