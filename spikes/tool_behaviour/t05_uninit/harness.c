/* T05: P0 reads an uninitialised local (Chrysalis bug class INIT).
   Self-composition: two runs on the same input must agree. */
static int p0_count(int x) { int k; if (x > 0) k = 0; return k + x; }   /* k uninitialised when x <= 0 */
int nondet_int(void);
int main(void) {
  int x = nondet_int();
  __CPROVER_assume(-100 <= x && x <= 100);
  int r1 = p0_count(x), r2 = p0_count(x);
  __CPROVER_assert(r1 == r2, "P0 deterministic at x");
  return 0;
}
