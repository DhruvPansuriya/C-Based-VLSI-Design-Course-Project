#include "common.h"
int main(void) {
  int a[8]; int n = nondet_int();
  __CPROVER_assume(1 <= n && n <= 7);
  for (int i = 0; i < 8; i++) a[i] = nondet_int();
  int r = p1_last(a, n); (void)r;
  return 0;
}
