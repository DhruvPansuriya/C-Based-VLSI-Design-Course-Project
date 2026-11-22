int extractFloat64Sign(unsigned long long int a)
{
  return (a & 0x8000000000000000ULL) != 0;
}


