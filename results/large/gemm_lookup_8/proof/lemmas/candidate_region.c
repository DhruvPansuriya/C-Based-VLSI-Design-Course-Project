void kernel(unsigned int a[64], unsigned int b[64], unsigned int out[64], unsigned int index)
{
  for (int p = 0; p < 64; p++)
    out[p] = 0u;

  for (int i = 0; i < 8; i++)
    for (int k = 0; k < 8; k++)
  {
    unsigned int v = a[(i * 8) + k];
    for (int j = 0; j < 8; j++)
      out[(i * 8) + j] += v * b[(k * 8) + j];

  }


}


