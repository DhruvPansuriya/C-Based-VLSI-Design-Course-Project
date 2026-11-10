int copy(const int *src, int *dst, int n, int cap) {
  dst[n] = src[n];
  for (int i = 0; i < n; ++i) dst[i] = src[i];
  (void)cap;
  return n + 1;
}
