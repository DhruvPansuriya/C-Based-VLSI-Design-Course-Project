unsigned int kernel(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 4; i++)
    y |= ((x >> (i * 8)) & 255u) << ((3 - i) * 8);

  return y;
}


