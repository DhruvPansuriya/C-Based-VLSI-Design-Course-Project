unsigned int kernel(unsigned int a[16], unsigned int n)
{
  unsigned int s = 0u;
  for (unsigned int i = 0u; i < n; i++)
    s += a[i];

  return s;
}


