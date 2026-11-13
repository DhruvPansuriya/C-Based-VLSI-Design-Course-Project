int extractFloat64Exp(unsigned long long int a)
{
  return (a & 0x7FF0000000000000ULL) >> 52;
}


