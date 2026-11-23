unsigned int kernel(unsigned int a[16])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 4; i++)
    sum += a[i * 5];

  return sum ^ 1u;
}


