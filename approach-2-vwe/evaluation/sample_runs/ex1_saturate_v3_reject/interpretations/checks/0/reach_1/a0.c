#include "frame.h"
unsigned char p0_add8(unsigned char a, unsigned char b)
{
  return (unsigned char) (((unsigned) a) + ((unsigned) b));
}



void __vwe_a0_call(const struct __vwe_input *in, struct __vwe_output *out) {
  unsigned char __vwe_arg_0;
  __vwe_arg_0=in->s0_0;
  unsigned char __vwe_arg_1;
  __vwe_arg_1=in->s1_0;
  unsigned char __vwe_ret=p0_add8(__vwe_arg_0, __vwe_arg_1);
  out->r0=__vwe_ret;
}
