unsigned int kernel(unsigned int a[32], unsigned int b[32])
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  unsigned int s2 = 0u;
  unsigned int s3 = 0u;
  for (int i = 0; i < 32; i += 4)
  {
    s0 += a[i] * b[i];
    s1 += a[i + 1] * b[i + 1];
    s2 += a[i + 2] * b[i + 2];
    s3 += a[i + 3] * b[i + 3];
  }

  return (s0 + s1) + (s2 + s3);
}


