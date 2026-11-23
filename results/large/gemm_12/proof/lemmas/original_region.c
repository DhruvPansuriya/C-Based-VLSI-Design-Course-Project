void kernel(unsigned int a[144], unsigned int b[144], unsigned int out[144])
{
  for (int i = 0; i < 12; i++)
    for (int j = 0; j < 12; j++)
  {
    unsigned int s = 0u;
    for (int k = 0; k < 12; k++)
      s += a[(i * 12) + k] * b[(k * 12) + j];

    out[(i * 12) + j] = s;
  }


}


