unsigned int kernel(unsigned int x)
{
  unsigned int parity = 0u;
  for (int i = 0; i < 32; i++)
    parity ^= (x >> i) & 1u;

  return parity;
}


