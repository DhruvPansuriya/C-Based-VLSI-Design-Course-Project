/* Common core for Example 2. B_max = {n == 0}. Every interpretation's Ext keeps P0 for n >= 1. */
#include <stdlib.h>
int p0_argmax(const int *, int, int *);
int p1_argmax(const int *, int, int *);
int nondet_int(void);
int main(void) {
  int n = nondet_int(); __CPROVER_assume(0 <= n && n <= 4);
  int *a0 = malloc((size_t)n * sizeof(int)), *a1 = malloc((size_t)n * sizeof(int));
  for (int i = 0; i < n; i++) { int v = nondet_int(); a0[i] = v; a1[i] = v; }
  int i1; int r1 = p1_argmax(a1, n, &i1);           /* E0: new UB in P1 under sigma_max (= n elements) */
  if (n != 0) {                                      /* keep region */
    int i0; int r0 = p0_argmax(a0, n, &i0);
    __CPROVER_assert(r0 == r1 && i0 == i1, "E1: preservation outside B_max (every Ext agrees)");
  }
  return 0;
}
