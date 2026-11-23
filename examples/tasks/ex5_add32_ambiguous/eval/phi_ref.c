/* Evaluation accepts both explicitly documented readings. */
int phi_ref(unsigned int a, unsigned int b, long long result) {
  unsigned long long s = (unsigned long long)a + b;
  return s <= 4294967295ULL ? result == (long long)s : (result == -1 || result == 4294967295LL);
}
