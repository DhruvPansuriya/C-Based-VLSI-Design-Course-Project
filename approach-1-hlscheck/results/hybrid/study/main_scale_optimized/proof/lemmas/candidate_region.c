void kernel(unsigned int a[8], unsigned int out[8])
{
  for (int i = 0; i < 8; i += 2)
  {
    out[i] = (a[i] << 3) + 3u;
    out[i + 1] = (a[i + 1] << 3) + 3u;
  }

}


