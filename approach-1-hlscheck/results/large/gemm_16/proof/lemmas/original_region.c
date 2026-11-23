void kernel(unsigned int a[256], unsigned int b[256], unsigned int out[256])
{
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++)
  {
    unsigned int s = 0u;
    for (int k = 0; k < 16; k++)
      s += a[(i * 16) + k] * b[(k * 16) + j];

    out[(i * 16) + j] = s;
  }


}


