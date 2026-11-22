/* Interpretation: shape SHAPE_ELEMS(n) elements; clause on all n >= 1: y == sum_{i<n} a[i].
   Values bounded to keep the sum free of signed overflow (contract must itself be UB-free). */
#include <stdlib.h>
#ifndef SHAPE_ELEMS
#define SHAPE_ELEMS(n) (n)
#endif
int p1_sum(const int *, int);
int nondet_int(void);
int main(void) {
  int n = nondet_int(); __CPROVER_assume(1 <= n && n <= 4);
  int *a = malloc((size_t)SHAPE_ELEMS(n) * sizeof(int));
  for (int i = 0; i < SHAPE_ELEMS(n); i++) { a[i] = nondet_int(); __CPROVER_assume(-1000 <= a[i] && a[i] <= 1000); }
  int expect = 0; for (int i = 0; i < n; i++) expect += a[i];     /* contract expression (reads a[n-1]) */
  __CPROVER_assert(p1_sum(a, n) == expect, "I: y == sum of all n elements");
  return 0;
}
