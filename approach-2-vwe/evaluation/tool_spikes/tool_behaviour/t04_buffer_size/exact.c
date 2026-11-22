#include <stdlib.h>
#include "common.h"
int main(void) {
  int n = nondet_int();
  __CPROVER_assume(1 <= n && n <= 7);
  int *a = malloc((size_t)n * sizeof(int));
  for (int i = 0; i < n; i++) a[i] = nondet_int();
  int r = p1_last(a, n); (void)r;
  return 0;
}
