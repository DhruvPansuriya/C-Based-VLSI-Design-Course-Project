void kernel(unsigned int a[32], unsigned int out[32])
{
  for (int i = 0; i < 32; i++)
  {
    unsigned int s = 0u;
    for (int j = 0; j <= i; j++)
      s += a[j];

    out[i] = s;
  }

}


