int p1_clamp(int x) {
#ifdef __SYNTHESIS__
  return x > 100 ? 100 : x;
#else
  return x > 99 ? 99 : x;
#endif
}
