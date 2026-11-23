int float64_is_nan(unsigned long long int a)
{
  return 0xFFE0000000000000LL < ((unsigned long long int) (a << 1));
}


