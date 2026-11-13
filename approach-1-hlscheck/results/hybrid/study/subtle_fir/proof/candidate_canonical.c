unsigned int kernel(unsigned int a[8])
{
  return ((((a[0] + a[6]) * 3u) + ((a[1] + a[6]) * 5u)) + ((a[2] + a[5]) * 7u)) + ((a[3] + a[4]) * 11u);
}


