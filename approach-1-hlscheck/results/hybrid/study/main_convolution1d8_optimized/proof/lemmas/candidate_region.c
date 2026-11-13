void kernel(unsigned int a[8], unsigned int out[6])
{
  for (int i = 0; i < 6; i++)
    out[i] = (3u * (a[i] + a[i + 2])) + (5u * a[i + 1]);

}


