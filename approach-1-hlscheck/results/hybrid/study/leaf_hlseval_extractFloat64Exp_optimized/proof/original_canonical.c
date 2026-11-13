int extractFloat64Exp(unsigned long long int a)
{
  return (a >> 52) & 0x7FF;
}


