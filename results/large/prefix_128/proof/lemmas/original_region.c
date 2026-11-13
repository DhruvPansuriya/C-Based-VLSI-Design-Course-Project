void kernel(unsigned int a[128], unsigned int out[128])
{
  for (int i = 0; i < 128; i++)
  {
    unsigned int s = 0u;
    for (int j = 0; j <= i; j++)
      s += a[j];

    out[i] = s;
  }

}


