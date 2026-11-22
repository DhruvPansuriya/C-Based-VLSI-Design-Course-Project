unsigned long long int extractFloat64Frac(unsigned long long int a)
{
  return (a << 13) >> 13;
}


