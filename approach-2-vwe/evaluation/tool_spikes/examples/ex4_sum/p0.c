/* Example 4, original: misses the last element. */
int p0_sum(const int *a, int n) { int s = 0; for (int i = 0; i < n - 1; i++) s += a[i]; return s; }
