#ifndef VARIANT
#define VARIANT 1
#endif
int p1_sum(const int *a, int n) {
  int s = 0;
#if VARIANT == 1
  for (int i = 0; i < n; i++) s += a[i];      /* correct */
#elif VARIANT == 2
  for (int i = 0; i <= n; i++) s += a[i];     /* reads a[n] */
#endif
  return s;
}
