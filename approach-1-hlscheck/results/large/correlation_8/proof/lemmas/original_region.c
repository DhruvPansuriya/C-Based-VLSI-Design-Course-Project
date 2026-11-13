void kernel(unsigned int a[8], unsigned int k, unsigned int out[8])
{
  for (int i = 0; i < 8; i++)
    out[i] = a[i] * 13u;

}


