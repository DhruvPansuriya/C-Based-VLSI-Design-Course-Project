/* Computed region B_ub for P0 (shape: a has n elements, idx separate, 0 <= n <= 4).
   Restricting to n == 0 shows P0's undefined behaviour is exactly there. */
#include <stdlib.h>
int p0_argmax(const int *, int, int *);
int nondet_int(void);
#ifndef NMIN
#define NMIN 0
#endif
int main(void) {
  int n = nondet_int(); __CPROVER_assume(NMIN <= n && n <= 4);
  int *a = malloc((size_t)n * sizeof(int));
  for (int i = 0; i < n; i++) a[i] = nondet_int();
  int idx; (void)p0_argmax(a, n, &idx);
  return 0;
}
