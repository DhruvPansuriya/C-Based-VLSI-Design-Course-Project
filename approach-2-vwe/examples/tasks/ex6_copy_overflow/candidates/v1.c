int copy(const int *src, int *dst, int n, int cap) {
  int count = n + 1 < cap ? n + 1 : cap;
  for (int i = 0; i < count; ++i) dst[i] = src[i];
  return count;
}
