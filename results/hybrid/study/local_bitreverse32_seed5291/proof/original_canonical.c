unsigned int kernel(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 32; i++)
  {
    y = (y << 1) | (x & 1u);
    x = x >> 1;
  }

  return y;
}


