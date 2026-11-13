void kernel(unsigned int alpha, unsigned int beta, unsigned int c[16], unsigned int a[16])
{
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      unsigned int sum = 0;
      for (int k = 0; k < 4; ++k)
      {
        sum += a[(i * 4) + k] * a[(j * 4) + k];
      }

      c[(i * 4) + j] = (beta * c[(i * 4) + j]) + (alpha * sum);
    }

  }

}


