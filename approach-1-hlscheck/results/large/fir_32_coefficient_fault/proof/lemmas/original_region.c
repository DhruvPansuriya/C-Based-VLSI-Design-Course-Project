unsigned int kernel(unsigned int a[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
  {
    int tap = (i < 16) ? (i) : (31 - i);
    s += a[i] * (3u + (2u * ((unsigned int) tap)));
  }

  return s;
}


