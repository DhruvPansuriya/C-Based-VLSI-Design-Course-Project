unsigned int kernel(unsigned int a[16], unsigned int k, unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
    out[i] = a[i] * 13u;

  return out[k & 15u];
}


