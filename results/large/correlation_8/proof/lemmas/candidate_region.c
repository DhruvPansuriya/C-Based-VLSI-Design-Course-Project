void kernel(unsigned int a[8], unsigned int k, unsigned int out[8])
{
  for (int i = 7; i >= 0; i--)
    out[i] = ((a[i] << 3) + (a[i] << 2)) + a[i];

}


