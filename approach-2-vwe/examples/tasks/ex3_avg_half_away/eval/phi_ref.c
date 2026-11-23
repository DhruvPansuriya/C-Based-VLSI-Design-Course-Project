/* Evaluation only: round magnitude then restore sign. */
int phi_ref(int a, int b, int out_ret) {
  long s = (long)a + b;
  long magnitude = s < 0 ? -s : s;
  long rounded = (magnitude + 1) / 2;
  return out_ret == (s < 0 ? -rounded : rounded);
}
