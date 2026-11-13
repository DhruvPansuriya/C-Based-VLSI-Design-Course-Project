unsigned int kernel(unsigned int a[256], unsigned int b[256], unsigned int out[256], unsigned int index)
{
  for (int p = 0; p < 256; p++)
    out[p] = 0u;

  for (int i = 0; i < 16; i++)
    for (int k = 0; k < 16; k++)
  {
    unsigned int v = a[(i * 16) + k];
    for (int j = 0; j < 16; j++)
      out[(i * 16) + j] += v * b[(k * 16) + j];

  }


  return out[index % 256u];
}


