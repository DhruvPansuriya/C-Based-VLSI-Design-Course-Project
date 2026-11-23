void kernel(unsigned int a[8], unsigned int b[8], unsigned int out[16])
{
  for (int i = 0; i < 8; i++)
  {
    out[2 * i] = a[i];
    out[(2 * i) + 1] = b[i];
  }

}


