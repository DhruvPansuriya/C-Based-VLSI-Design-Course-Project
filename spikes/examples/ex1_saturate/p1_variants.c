/* Example 1, candidate fixes. Select one with -DVARIANT=<n>. */
#ifndef VARIANT
#define VARIANT 1
#endif
unsigned char p1_add8(unsigned char a, unsigned char b) {
#if VARIANT == 1   /* widen and saturate (correct) */
  unsigned s = (unsigned)a + (unsigned)b; return s > 255u ? (unsigned char)255u : (unsigned char)s;
#elif VARIANT == 2 /* carry test via wrap (correct alternative) */
  unsigned char s = (unsigned char)(a + b); return s < a ? (unsigned char)255u : s;
#elif VARIANT == 3 /* always 255 (regression) */
  (void)a; (void)b; return 255u;
#elif VARIANT == 4 /* unchanged (no fix) */
  return (unsigned char)((unsigned)a + (unsigned)b);
#elif VARIANT == 5 /* 254 on overflow (wrong constant) */
  unsigned s = (unsigned)a + (unsigned)b; return s > 255u ? (unsigned char)254u : (unsigned char)s;
#endif
}
