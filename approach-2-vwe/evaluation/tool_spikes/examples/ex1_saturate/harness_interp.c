/* Per-interpretation check Sat(P1, I_k) for Example 1 (one equivalence class). */
unsigned char p0_add8(unsigned char, unsigned char);
unsigned char p1_add8(unsigned char, unsigned char);
unsigned char nondet_uchar(void);
int main(void) {
  unsigned char a = nondet_uchar(), b = nondet_uchar();
  unsigned s = (unsigned)a + (unsigned)b;
  unsigned char y1 = p1_add8(a, b);
  if (s > 255u) __CPROVER_assert(y1 == 255u, "I1: clause on B (y == 255)");
  else          __CPROVER_assert(y1 == p0_add8(a, b), "I1: preservation outside B");
  return 0;
}
