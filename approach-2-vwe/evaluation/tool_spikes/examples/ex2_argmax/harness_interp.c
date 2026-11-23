#include <stdlib.h>
#include <limits.h>
int p0_argmax(const int *, int, int *);
int p1_argmax(const int *, int, int *);
int nondet_int(void);
int main(void) {
  int n = nondet_int(); __CPROVER_assume(0 <= n && n <= 4);
  int *a0 = malloc((size_t)n * sizeof(int)), *a1 = malloc((size_t)n * sizeof(int));
  for (int i = 0; i < n; i++) { int v = nondet_int(); a0[i] = v; a1[i] = v; }
  int i1; int r1 = p1_argmax(a1, n, &i1);
  if (n == 0) __CPROVER_assert(r1 == INT_MIN && i1 == -1, "I1: clause on B");
  else { int i0; int r0 = p0_argmax(a0, n, &i0);
         __CPROVER_assert(r0 == r1 && i0 == i1, "I1: preservation outside B"); }
  return 0;
}
