int avg(int a, int b) { int s = a + b; return s / 2 + (s % 2 == 0 ? 0 : (s > 0 ? 1 : -1)); }
