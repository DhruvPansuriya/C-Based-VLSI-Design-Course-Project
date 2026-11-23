void kernel(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int p = 0; p < 16; p++)
  {
    out[p] = 0u;
  }

  for (int k = 0; k < 4; k++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        out[(i * 4) + j] += a[(i * 4) + k] + b[(k * 4) + j];
      }

    }

  }

}


