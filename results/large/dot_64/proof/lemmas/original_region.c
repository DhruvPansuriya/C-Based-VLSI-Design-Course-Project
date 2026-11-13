unsigned int kernel(unsigned int a[64], unsigned int b[64])
{
  unsigned int s = 0u;
  for (int i = 0; i < 64; i++)
    s += a[i] * b[i];

  return s;
}


