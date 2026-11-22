int transform(int x) {
#ifdef __SYNTHESIS__
  return x + 2;
#else
  return x + 1;
#endif
}
