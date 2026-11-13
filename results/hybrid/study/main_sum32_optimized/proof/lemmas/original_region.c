unsigned int kernel(unsigned int a[32])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 32; i++)
    sum += a[i];

  return sum;
}


