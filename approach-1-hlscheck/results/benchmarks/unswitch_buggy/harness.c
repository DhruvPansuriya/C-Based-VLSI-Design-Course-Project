#include <stdint.h>
extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hls_nondet_uint(void);
extern int __hls_nondet_int(void);
_Static_assert(sizeof(int)==4 && sizeof(unsigned int)==4, "32-bit integers required");
void __hls_original(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4])
{
  for (int i = 0; i < 4; i++)
  {
    if (x > 10u)
    {
      a[i] = b[i] + c[i];
    }
    else
    {
      a[i] = b[i] - c[i];
    }
  }

}


void __hls_candidate(uint32_t x, uint32_t b[4], uint32_t c[4], uint32_t a[4])
{
  if (x >= 10u)
  {
    for (int i = 0; i < 4; i++)
    {
      a[i] = b[i] + c[i];
    }

  }
  else
  {
    for (int j = 0; j < 4; j++)
    {
      a[j] = b[j] - c[j];
    }

  }
}


int main(void) {
unsigned int input_0 = __hls_nondet_uint();
unsigned int original_arg_1[4];
unsigned int candidate_arg_1[4];
for (int seed_1=0; seed_1<4; seed_1++) {
unsigned int value = __hls_nondet_uint();
original_arg_1[seed_1] = value;
candidate_arg_1[seed_1] = value;
}
unsigned int original_arg_2[4];
unsigned int candidate_arg_2[4];
for (int seed_2=0; seed_2<4; seed_2++) {
unsigned int value = __hls_nondet_uint();
original_arg_2[seed_2] = value;
candidate_arg_2[seed_2] = value;
}
unsigned int original_arg_3[4];
unsigned int candidate_arg_3[4];
for (int seed_3=0; seed_3<4; seed_3++) {
unsigned int value = __hls_nondet_uint();
original_arg_3[seed_3] = value;
candidate_arg_3[seed_3] = value;
}
__hls_original(input_0,original_arg_1,original_arg_2,original_arg_3);
__hls_candidate(input_0,candidate_arg_1,candidate_arg_2,candidate_arg_3);
for(int compare_1=0; compare_1<4; compare_1++) {
__ESBMC_assert(original_arg_1[compare_1]==candidate_arg_1[compare_1], "EQUIV:array:1");
}
for(int compare_2=0; compare_2<4; compare_2++) {
__ESBMC_assert(original_arg_2[compare_2]==candidate_arg_2[compare_2], "EQUIV:array:2");
}
for(int compare_3=0; compare_3<4; compare_3++) {
__ESBMC_assert(original_arg_3[compare_3]==candidate_arg_3[compare_3], "EQUIV:array:3");
}
return 0;
}
