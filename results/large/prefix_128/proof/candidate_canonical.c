void kernel(unsigned int a[128], unsigned int out[128])
{
  unsigned int s = 0u;
  for (int i = 0; i < 128; i++)
  {
    s += a[i];
    out[i] = s;
  }

}


