/* Common core for Example 1 (E0 + E1 conditions).
   Interpretation set: every reading gives B = {a+b > 255}, Ext: y == min(a+b, 255).
   B_max = {a+b > 255}. Shapes trivial (no pointers). */
unsigned char p0_add8(unsigned char, unsigned char);
unsigned char p1_add8(unsigned char, unsigned char);
unsigned char nondet_uchar(void);
int main(void) {
  unsigned char a = nondet_uchar(), b = nondet_uchar();
  unsigned s = (unsigned)a + (unsigned)b;           /* contract arithmetic in a wider type */
  unsigned char y1 = p1_add8(a, b);                 /* E0: standard checks catch new UB in P1 */
  if (!(s > 255u)) {                                /* keep region: outside B_max */
    unsigned char y0 = p0_add8(a, b);
    /* E1 fires only if the output differs from P0 AND every known Ext rejects it */
    __CPROVER_assert(y1 == y0 || y1 == (s > 255u ? 255u : s), "E1: regression rejected by every Ext");
  }
  return 0;
}
