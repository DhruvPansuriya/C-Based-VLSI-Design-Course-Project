unsigned int transform(unsigned int a[4], unsigned int index, unsigned int out[4])
{
  for (int j = 3; j >= 0; --j)
    out[j] = ((a[j] << 3) + (a[j] << 2)) + a[j];

  return a[index % 4u] * 13u;
}


