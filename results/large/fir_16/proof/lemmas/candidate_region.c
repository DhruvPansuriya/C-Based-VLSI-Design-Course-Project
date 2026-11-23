unsigned int kernel(unsigned int a[16])
{
  unsigned int s = 0u;
  for (int i = 0; i < 8; i++)
    s += (a[i] + a[15 - i]) * (3u + (2u * ((unsigned int) i)));

  return s;
}


