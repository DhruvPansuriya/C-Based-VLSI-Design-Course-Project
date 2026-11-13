unsigned int kernel(unsigned int a[32], unsigned int b[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
    s += a[i] * b[i];

  return s;
}


