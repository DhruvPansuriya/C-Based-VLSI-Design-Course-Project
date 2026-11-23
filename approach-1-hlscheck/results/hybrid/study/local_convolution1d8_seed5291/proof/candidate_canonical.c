void kernel(unsigned int a[8], unsigned int out[6])
{
  for (int i = 0; i < 6; i++)
  {
    unsigned int sum = ((3u * a[i]) + (5u * a[i + 1])) + (3u * a[i + 2]);
    out[i] = sum;
  }

}


