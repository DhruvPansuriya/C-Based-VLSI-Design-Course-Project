void kernel(unsigned int a[8], unsigned int out[8])
{
  for (int i = 0; i < 8; i++)
  {
    out[i] = (a[i] * 8u) + 3u;
  }

}


