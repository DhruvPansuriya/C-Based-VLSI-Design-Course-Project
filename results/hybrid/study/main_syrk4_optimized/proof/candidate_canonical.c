void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 4; i++)
    for (int j = i; j < 4; j++)
  {
    unsigned int sum = 0u;
    for (int k = 0; k < 4; k++)
      sum += a[(i * 4) + k] * a[(j * 4) + k];

    out[(i * 4) + j] = sum;
    if (i != j)
      out[(j * 4) + i] = sum;
  }


}


