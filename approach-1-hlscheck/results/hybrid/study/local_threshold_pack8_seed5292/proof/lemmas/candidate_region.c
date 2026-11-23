unsigned int kernel(unsigned int a[8])
{
  unsigned int packed = 0u;
  for (int i = 0; i < 8; i++)
  {
    packed |= ((a[i] > 128u) ? (1u) : (0u)) << i;
  }

  return packed;
}


