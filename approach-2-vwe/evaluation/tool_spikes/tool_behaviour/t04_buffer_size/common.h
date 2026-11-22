/* T04: off-by-one read a[n]. Fixed-size buffer vs exact-size malloc. */
static int p1_last(const int *a, int n) { return a[n]; }   /* bug: should be a[n-1] */
int nondet_int(void);
