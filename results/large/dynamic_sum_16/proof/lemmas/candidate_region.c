unsigned int kernel(unsigned int a[16], unsigned int n)
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  for (unsigned int i = 0u; (i + 1u) < n; i += 2u)
  {
    s0 += a[i];
    s1 += a[i + 1u];
  }

  if ((n & 1u) != 0u)
    s0 += a[n - 1u];
  return s0 + s1;
}


