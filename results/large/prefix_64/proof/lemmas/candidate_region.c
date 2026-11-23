void kernel(unsigned int a[64], unsigned int out[64])
{
  unsigned int s = 0u;
  for (int i = 0; i < 64; i++)
  {
    s += a[i];
    out[i] = s;
  }

}


