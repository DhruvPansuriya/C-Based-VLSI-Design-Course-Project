int float64_is_nan(unsigned long long int a)
{
  return (a & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL;
}


