void kernel(unsigned int a[8], unsigned int out[6])
{
  for (int i = 0; i < 6; i++)
    out[i] = ((3u * a[i]) + (5u * a[i + 1])) + (3u * a[i + 2]);

}


