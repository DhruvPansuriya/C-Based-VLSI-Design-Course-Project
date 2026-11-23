unsigned int kernel(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] ^ b[i]) & 255u;
    for (int bit = 0; bit < 8; bit++)
      total += (v >> bit) & 1u;

  }

  return total;
}


