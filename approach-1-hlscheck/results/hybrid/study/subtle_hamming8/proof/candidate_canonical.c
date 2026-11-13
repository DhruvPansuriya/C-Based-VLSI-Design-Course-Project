unsigned int kernel(unsigned int a[8], unsigned int b[8])
{
  unsigned int total = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int v = (a[i] | b[i]) & 255u;
    v -= (v >> 1) & 0x55u;
    v = (v & 0x33u) + ((v >> 2) & 0x33u);
    total += (v + (v >> 4)) & 15u;
  }

  return total;
}


