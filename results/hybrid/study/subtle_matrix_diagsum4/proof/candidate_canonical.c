unsigned int kernel(unsigned int a[16])
{
  unsigned int sum = 0u;
  for (int r = 0; r < 4; r++)
    sum += a[(r * 4) + r] + a[(r * 4) + r];

  return sum;
}


