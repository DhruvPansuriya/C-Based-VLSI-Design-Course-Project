void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 4; i++)
  {
    unsigned int sum1 = 0u;
    unsigned int sum2 = 0u;
    unsigned int sum3 = 0u;
    unsigned int sum4 = 0u;
    for (int j = 0; j < 4; j++)
    {
      sum1 += a[(i * 4) + j] * a[(j * 4) + 0];
      sum2 += a[(i * 4) + j] * a[(j * 4) + 1];
      sum3 += a[(i * 4) + j] * a[(j * 4) + 2];
      sum4 += a[(i * 4) + j] * a[(j * 4) + 3];
    }

    out[(i * 4) + 0] = sum1;
    out[(i * 4) + 1] = sum2;
    out[(i * 4) + 2] = sum3;
    out[(i * 4) + 3] = sum4;
  }

}


