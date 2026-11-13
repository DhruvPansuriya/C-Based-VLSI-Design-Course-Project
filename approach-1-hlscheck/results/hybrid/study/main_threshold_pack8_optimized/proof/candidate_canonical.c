unsigned int kernel(unsigned int a[8])
{
  unsigned int lo = 0u;
  unsigned int hi = 0u;
  for (int i = 0; i < 4; i++)
  {
    lo |= ((a[i] > 128u) ? (1u) : (0u)) << i;
    hi |= ((a[i + 4] > 128u) ? (1u) : (0u)) << i;
  }

  return lo | (hi << 4);
}


