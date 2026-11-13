unsigned int kernel(unsigned int a[64])
{
  unsigned int s = 0u;
  for (int i = 0; i < 64; i++)
  {
    int tap = (i < 32) ? (i) : (63 - i);
    s += a[i] * (3u + (2u * ((unsigned int) tap)));
  }

  return s;
}


