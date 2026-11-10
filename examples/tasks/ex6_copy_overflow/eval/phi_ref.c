int phi_ref(const int *src, const int *initial, const int *out, int n, int cap, int result) {
  int count = n + 1 < cap ? n + 1 : cap;
  if (result != count) return 0;
  for (int i=0; i<cap; ++i) if (out[i] != (i<count ? src[i] : initial[i])) return 0;
  return 1;
}
