void kernel(unsigned int a[8], unsigned int out[8])
{
  unsigned int sum = 0u;
  for (int i = 0; i < 8; i++)
  {
    sum += a[i];
    out[i] = sum;
  }

}


