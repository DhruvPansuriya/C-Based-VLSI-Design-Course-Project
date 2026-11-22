int p1_clamp(int x);
int nondet_int(void);
int main(void) {
  int x = nondet_int();
  int r = p1_clamp(x);
  __CPROVER_assert(r <= 99, "clamp to 99 (requirement)");
  return 0;
}
