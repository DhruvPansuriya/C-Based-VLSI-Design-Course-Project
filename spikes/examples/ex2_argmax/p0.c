/* Example 2, original: reads a[0] even when n == 0. */
int p0_argmax(const int *a, int n, int *idx) {
  int m = a[0]; *idx = 0;
  for (int i = 1; i < n; i++) if (a[i] > m) { m = a[i]; *idx = i; }
  return m;
}
