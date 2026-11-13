unsigned int kernel(unsigned int a[16], unsigned int b[16])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 16; i++)
    sum += a[i] * b[i];

  return sum;
}


