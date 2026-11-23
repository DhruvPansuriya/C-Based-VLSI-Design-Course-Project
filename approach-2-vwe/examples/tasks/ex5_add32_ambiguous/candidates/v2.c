long long add32(unsigned int a, unsigned int b) { long long s = (long long)a + b; return s > 4294967295LL ? -1 : s; }
