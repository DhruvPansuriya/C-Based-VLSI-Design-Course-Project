void kernel(unsigned int a[64], unsigned int out[64])
{
  for (int i = 0; i < 64; i++)
  {
    unsigned int s = 0u;
    for (int j = 0; j <= i; j++)
      s += a[j];

    out[i] = s;
  }

}


