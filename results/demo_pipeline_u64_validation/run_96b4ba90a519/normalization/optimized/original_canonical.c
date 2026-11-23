unsigned long long int sign(unsigned long long int x)
{
  return (x & 0x8000000000000000ULL) != 0;
}


