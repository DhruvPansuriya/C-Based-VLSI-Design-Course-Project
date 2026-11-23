void kernel(unsigned int orig[25], unsigned int sol[25], unsigned int filter[9])
{
  for (int r = 0; r < 3; ++r)
  {
    for (int c = 0; c < 3; ++c)
    {
      unsigned int sum0 = 0u;
      unsigned int sum1 = 0u;
      unsigned int sum2 = 0u;
      for (int k = 0; k < 3; ++k)
      {
        int base = ((r + k) * 5) + c;
        sum0 += filter[k * 3] * orig[base];
        sum1 += filter[(k * 3) + 1] * orig[base + 1];
        sum2 += filter[(k * 3) + 2] * orig[base + 2];
      }

      sol[(r * 5) + c] = (sum0 + sum1) + sum2;
    }

  }

}


