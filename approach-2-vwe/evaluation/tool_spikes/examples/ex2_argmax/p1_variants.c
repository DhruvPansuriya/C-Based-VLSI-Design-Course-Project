#include <limits.h>
#ifndef VARIANT
#define VARIANT 1
#endif
int p1_argmax(const int *a, int n, int *idx) {
#if VARIANT == 1   /* correct fix */
  if (n == 0) { *idx = -1; return INT_MIN; }
  int m = a[0]; *idx = 0;
  for (int i = 1; i < n; i++) if (a[i] > m) { m = a[i]; *idx = i; }
  return m;
#elif VARIANT == 2 /* fixes n == 0 but picks the LAST tied index */
  if (n == 0) { *idx = -1; return INT_MIN; }
  int m = a[0]; *idx = 0;
  for (int i = 1; i < n; i++) if (a[i] >= m) { m = a[i]; *idx = i; }
  return m;
#elif VARIANT == 3 /* fixes n == 0 but reads a[n] as a sentinel (new out-of-bounds read) */
  if (n == 0) { *idx = -1; return INT_MIN; }
  int m = a[0]; *idx = 0;
  for (int i = 1; i <= n; i++) if (i < n && a[i] > m) { m = a[i]; *idx = i; } else if (i == n && a[i] > m) { m = a[i]; }
  return m;
#endif
}
