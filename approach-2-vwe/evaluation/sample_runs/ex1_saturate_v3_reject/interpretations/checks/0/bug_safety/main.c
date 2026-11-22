#include <stdlib.h>
#include "frame.h"
void __vwe_a0_call(const struct __vwe_input *in, struct __vwe_output *out);
void __vwe_a1_call(const struct __vwe_input *in, struct __vwe_output *out);

unsigned char nondet___vwe_0(void);
unsigned char nondet___vwe_1(void);
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline int vwe_observer_0(unsigned char ve_arg_0, unsigned char ve_arg_1) {
  return ((((((long long)ve_arg_0)) + (((long long)ve_arg_1)))) > ((255LL)));
}

int main(void) {
  struct __vwe_input __vwe_in={0};
  unsigned char __vwe_in_scalar_0_0=nondet___vwe_0();
  __CPROVER_assume(0LL <= __vwe_in_scalar_0_0 && __vwe_in_scalar_0_0 <= 255LL);
  __vwe_in.s0_0=__vwe_in_scalar_0_0;
  unsigned char __vwe_in_scalar_1_0=nondet___vwe_1();
  __CPROVER_assume(0LL <= __vwe_in_scalar_1_0 && __vwe_in_scalar_1_0 <= 255LL);
  __vwe_in.s1_0=__vwe_in_scalar_1_0;
  struct __vwe_output __vwe_one={0};
  struct __vwe_output __vwe_zero={0};
  __CPROVER_assume(vwe_observer_0(__vwe_in_scalar_0_0, __vwe_in_scalar_1_0));
  __vwe_a0_call(&__vwe_in, &__vwe_zero);
  __CPROVER_assert(1, "VWE.reference_safety.completed");
  return 0;
}
