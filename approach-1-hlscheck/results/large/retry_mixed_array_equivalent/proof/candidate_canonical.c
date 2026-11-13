unsigned int transform(unsigned int a[8], unsigned int index, unsigned int out[8])
{
  for (int j = 7; j >= 0; --j)
  {
    unsigned int v = a[j];
    out[j] = ((v << 3) + (v << 2)) + v;
  }

  return a[index % 8u] * 13u;
}


