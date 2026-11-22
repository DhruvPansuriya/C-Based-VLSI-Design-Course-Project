#include "frame.h"
unsigned char p1_add8(unsigned char a, unsigned char b)
{
  (void) a;
  (void) b;
  return 255u;
}



void __vwe_a1_call(const struct __vwe_input *in, struct __vwe_output *out) {
  unsigned char __vwe_arg_0;
  __vwe_arg_0=in->s0_0;
  unsigned char __vwe_arg_1;
  __vwe_arg_1=in->s1_0;
  unsigned char __vwe_ret=p1_add8(__vwe_arg_0, __vwe_arg_1);
  out->r0=__vwe_ret;
}
