/* Vacuity probes: both regions must be reachable. Each assertion is EXPECTED to FAIL. */
unsigned char p1_add8(unsigned char, unsigned char);
unsigned char nondet_uchar(void);
int main(void) {
  unsigned char a = nondet_uchar(), b = nondet_uchar();
  unsigned s = (unsigned)a + (unsigned)b;
  (void)p1_add8(a, b);
  if (s > 255u) __CPROVER_assert(0, "probe: B reachable after call");
  else          __CPROVER_assert(0, "probe: keep region reachable after call");
  return 0;
}
