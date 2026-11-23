/* T01: a candidate that loops forever on "hard" inputs.
   Question: does CBMC silently drop those inputs (vacuous proof)? */
unsigned char nondet_uchar(void);
static unsigned char p1_add8(unsigned char a, unsigned char b) {
  unsigned s = (unsigned)a + (unsigned)b;
  if (s > 255u) { while (1) { } }          /* escapes the overflow inputs */
  return (unsigned char)s;
}
int main(void) {
  unsigned char a = nondet_uchar(), b = nondet_uchar();
  unsigned s = (unsigned)a + (unsigned)b;
  unsigned char r = p1_add8(a, b);
  __CPROVER_assert(r == (s > 255u ? 255u : s), "saturation requirement");
  return 0;
}
