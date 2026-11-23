unsigned int kernel(unsigned int a[128], unsigned int b[128])
{
  unsigned int s = 0u;
  for (int i = 0; i < 128; i++)
    s += a[i] * b[i];

  return s;
}


