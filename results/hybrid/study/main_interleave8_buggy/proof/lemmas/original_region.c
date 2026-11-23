void kernel(unsigned int a[8], unsigned int b[8], unsigned int out[16])
{
  for (int i = 0; i < 8; i++)
    out[2 * i] = a[i];

  for (int j = 0; j < 8; j++)
    out[(2 * j) + 1] = b[j];

}


