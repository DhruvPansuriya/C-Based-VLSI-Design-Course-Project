void kernel(unsigned int a[32], unsigned int out[32])
{
  unsigned int s = 0u;
  for (int i = 0; i < 32; i++)
  {
    s += a[i];
    out[i] = s;
  }

}


