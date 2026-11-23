void kernel(unsigned int a[144], unsigned int b[144], unsigned int out[144])
{
  for (int p = 0; p < 144; p++)
    out[p] = 0u;

  for (int i = 0; i < 12; i++)
    for (int k = 0; k < 12; k++)
  {
    unsigned int v = a[(i * 12) + k];
    for (int j = 0; j < 12; j++)
      out[(i * 12) + j] += v * b[(k * 12) + j];

  }


}


