#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "frame.h"
#define __CPROVER_assume(c) do { if (!(c)) exit(77); } while (0)
#define __CPROVER_assert(c,m) do { if (!(c)) exit(77); } while (0)
void __vwe_a0_call(const struct __vwe_input *in, struct __vwe_output *out);
void __vwe_a1_call(const struct __vwe_input *in, struct __vwe_output *out);

int main(int argc, char **argv) {
  if (argc != 3) return 77;
  char *__vwe_end;
  struct __vwe_input __vwe_in={0};
  errno=0;
  unsigned long long __vwe_native_value_1=strtoull(argv[1], &__vwe_end, 10);
  if (errno || __vwe_end==argv[1] || *__vwe_end || __vwe_native_value_1 < 0LL || __vwe_native_value_1 > 255LL) return 77;
  unsigned char __vwe_in_scalar_0_0=(unsigned char)__vwe_native_value_1;
  __vwe_in.s0_0=__vwe_in_scalar_0_0;
  errno=0;
  unsigned long long __vwe_native_value_2=strtoull(argv[2], &__vwe_end, 10);
  if (errno || __vwe_end==argv[2] || *__vwe_end || __vwe_native_value_2 < 0LL || __vwe_native_value_2 > 255LL) return 77;
  unsigned char __vwe_in_scalar_1_0=(unsigned char)__vwe_native_value_2;
  __vwe_in.s1_0=__vwe_in_scalar_1_0;
  struct __vwe_output __vwe_one={0};
  struct __vwe_output __vwe_zero={0};
  __vwe_a0_call(&__vwe_in, &__vwe_zero);
  printf("%s\t%llu\n", "ret", (unsigned long long)(__vwe_zero.r0));
  return 0;
}
