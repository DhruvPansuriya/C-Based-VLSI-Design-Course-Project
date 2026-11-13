void kernel(unsigned int a[8], unsigned int out[8])
{
  for (int i = 0; i < 8; i++)
  {
    unsigned int sum = 0u;
    for (int j = 0; j <= i; j++)
    {
      sum += a[j];
    }

    out[i] = sum;
  }

}


