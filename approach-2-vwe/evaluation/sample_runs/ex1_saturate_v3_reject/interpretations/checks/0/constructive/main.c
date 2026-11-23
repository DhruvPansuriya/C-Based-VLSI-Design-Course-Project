#include <stdlib.h>
#include "frame.h"
void __vwe_a0_call(const struct __vwe_input *in, struct __vwe_output *out);
void __vwe_a1_call(const struct __vwe_input *in, struct __vwe_output *out);

unsigned char nondet___vwe_0(void);
unsigned char nondet___vwe_1(void);
unsigned char nondet___vwe_2(void);
unsigned char nondet___vwe_3(void);
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline long long vwe_observer_0(unsigned char ve_arg_0, unsigned char ve_arg_1) {
  long long ve_t_0 = ((((long long)ve_arg_0)) + (((long long)ve_arg_1)));
  long long ve_t_1 = (255LL);
  return (ve_t_0 < ve_t_1 ? ve_t_0 : ve_t_1);
}
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline int vwe_observer_1(unsigned char ve_arg_0, unsigned char ve_arg_1) {
  return ((((((long long)ve_arg_0)) + (((long long)ve_arg_1)))) > ((255LL)));
}
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline long long vwe_observer_2(unsigned char ve_arg_0, unsigned char ve_arg_1) {
  long long ve_t_0 = ((((long long)ve_arg_0)) + (((long long)ve_arg_1)));
  long long ve_t_1 = (255LL);
  return (ve_t_0 < ve_t_1 ? ve_t_0 : ve_t_1);
}
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline int vwe_observer_3(unsigned char ve_arg_0, unsigned char ve_arg_1) {
  return ((((((long long)ve_arg_0)) + (((long long)ve_arg_1)))) > ((255LL)));
}
/* VE-DSL-1 observer: V-G/old-definedness checks are still required. */
static inline int vwe_observer_4(unsigned char ve_arg_0, unsigned char ve_arg_1, unsigned char ve_arg_2) {
  long long ve_t_0 = ((((long long)ve_arg_0)) + (((long long)ve_arg_1)));
  long long ve_t_1 = (255LL);
  return ((((long long)ve_arg_2)) == ((ve_t_0 < ve_t_1 ? ve_t_0 : ve_t_1)));
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
  unsigned char __vwe_one_result_0=nondet___vwe_2();
  __vwe_one.r0=__vwe_one_result_0;
  unsigned char __vwe_zero_result_0=nondet___vwe_3();
  __vwe_zero.r0=__vwe_zero_result_0;
  if (vwe_observer_1(__vwe_in_scalar_0_0, __vwe_in_scalar_1_0)) {
  __vwe_one.r0=(unsigned char)(vwe_observer_2(__vwe_in_scalar_0_0, __vwe_in_scalar_1_0));
  }
  __CPROVER_assert(((!(vwe_observer_3(__vwe_in_scalar_0_0, __vwe_in_scalar_1_0)) || (vwe_observer_4(__vwe_in_scalar_0_0, __vwe_in_scalar_1_0, __vwe_one.r0)))), "VWE.validation_constructive.predicate");
  return 0;
}
