void kernel(unsigned int a[16], unsigned int x[4], unsigned int out[4])
{
  unsigned int sum[4];
  for (int r = 0; r < 4; r++)
  {
    sum[r] = 0u;
    for (int c = 0; c <= r; c++)
    {
      sum[r] += a[(r * 4) + c] * x[c];
    }

    out[r] = sum[r];
  }

}


