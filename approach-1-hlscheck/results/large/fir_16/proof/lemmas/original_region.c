unsigned int kernel(unsigned int a[16])
{
  unsigned int s = 0u;
  for (int i = 0; i < 16; i++)
  {
    int tap = (i < 8) ? (i) : (15 - i);
    s += a[i] * (3u + (2u * ((unsigned int) tap)));
  }

  return s;
}


