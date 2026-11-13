unsigned int kernel(unsigned int a[16])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 4; i++)
    sum += a[i * 4];

  return sum;
}


