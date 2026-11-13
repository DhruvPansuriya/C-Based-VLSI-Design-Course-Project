int kernel(unsigned long long int a)
{
  return ((a & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL) & ((a & 0x000FFFFFFFFFFFFFULL) != 0);
}


