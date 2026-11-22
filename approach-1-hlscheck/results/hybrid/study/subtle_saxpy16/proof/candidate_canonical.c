void kernel(unsigned int a[16], unsigned int b[16], unsigned int k, unsigned int out[16])
{
  for (int i = 0; i < 16; i += 2)
  {
    out[i] = (a[i] * k) + b[i];
    out[i + 1] = (a[i + 1] * k) + b[i];
  }

}


