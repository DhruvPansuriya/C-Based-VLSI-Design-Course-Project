unsigned int kernel(unsigned int a[4], unsigned int k, unsigned int out[4])
{
  for (int i = 3; i >= 0; i--)
    out[i] = ((a[i] << 3) + (a[i] << 2)) + a[i];

  return a[k % 4u] * 13u;
}


