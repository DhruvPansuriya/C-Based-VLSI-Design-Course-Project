void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
    out[15 - i] = a[i];

}


