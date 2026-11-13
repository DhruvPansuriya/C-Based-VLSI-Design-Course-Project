unsigned int kernel(unsigned int a[16], unsigned int k, unsigned int out[16])
{
  for (int i = 15; i >= 0; i--)
    out[i] = ((a[i] << 3) + (a[i] << 2)) + a[i];

  return a[k % 16u] * 13u;
}


