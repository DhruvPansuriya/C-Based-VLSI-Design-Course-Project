unsigned int kernel(unsigned int a[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 16; i++)
    s += (a[i] + a[31 - i]) * (3u + (2u * ((unsigned int) (i + 1))));

  return s;
}


