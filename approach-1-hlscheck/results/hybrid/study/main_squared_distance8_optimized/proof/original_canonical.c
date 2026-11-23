unsigned int kernel(unsigned int a[8], unsigned int b[8])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int d = a[i] - b[i];
    sum += d * d;
  }

  return sum;
}


