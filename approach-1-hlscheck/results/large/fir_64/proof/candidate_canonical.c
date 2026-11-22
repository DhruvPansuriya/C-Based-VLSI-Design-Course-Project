unsigned int kernel(unsigned int a[64])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
    s += (a[i] + a[63 - i]) * (3u + (2u * ((unsigned int) i)));

  return s;
}


