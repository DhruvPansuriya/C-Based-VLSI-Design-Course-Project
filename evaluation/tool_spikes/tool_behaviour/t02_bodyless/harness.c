/* T02: candidate calls a function with no body. Real helper clobbers *p. */
void helper(int *p);                        /* declared, never defined */
static int p1(int x) { int y = x; helper(&y); return y; }
int nondet_int(void);
int main(void) {
  int x = nondet_int();
  __CPROVER_assert(p1(x) == x, "candidate preserves x");
  return 0;
}
