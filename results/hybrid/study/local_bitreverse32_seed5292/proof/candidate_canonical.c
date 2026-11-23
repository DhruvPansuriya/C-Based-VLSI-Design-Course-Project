unsigned int kernel(unsigned int x)
{
  unsigned int y = 0u;
  for (int i = 0; i < 32; i += 4)
  {
    y = (y << 16) | (x & 3u);
    y = (y << 16) | (x >> 2);
    y = (y << 16) | (x >> 4);
    x >>= 8;
  }

  return y;
}


